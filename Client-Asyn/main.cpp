#include <string>  
#include "boost/shared_ptr.hpp"  
#include <thrift/Thrift.h>  
#include <thrift/protocol/TProtocol.h>  
#include <thrift/transport/TSocket.h>  
#include <thrift/transport/TTransportUtils.h>  
#include <thrift/concurrency/ThreadManager.h>  
#include <thrift/transport/TBufferTransports.h>  
#include <thrift/server/TServer.h>  
#include <thrift/async/TAsyncChannel.h>  
#include <thrift/async/TEvhttpClientChannel.h>  
#include "../Interface-Asyn/gen-cpp/Twitter.h"  
#include "boost/function.hpp"  
#include "boost/bind.hpp"  
#include <event.h>  
#include <stdio.h>  
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using std::string;
using boost::shared_ptr;
using namespace example;
using namespace apache::thrift::async;

class testClient : public TwitterCobClient
{
public:
	testClient(stdcxx::shared_ptr< ::apache::thrift::async::TAsyncChannel> channel, TProtocolFactory* protocolFactory)
		: TwitterCobClient(channel, protocolFactory)
	{ };


	virtual void completed__(bool success)
	{
		if (success)
		{
			printf("respone : %s \n", res.c_str());   // 输出返回结果  
		}
		else
		{
			printf("failed to respone\n");
		}
		fflush(0);
	};


	string res;
};


//callback function  
static void my_recv_sendString(TwitterCobClient *client) {
	client->recv_sendString(dynamic_cast<testClient*>(client)->res);
}


static void sendString(testClient & client) {
	printf("snedstring start\n");
	std::function<void(TwitterCobClient*client)>cob = bind(&my_recv_sendString, _1);
	try
	{
		client.sendString(cob, "Hello");
	}
	catch (TException& exc)
	{
		printf("%s\n", exc.what());
	}
	printf("sendstring end\n");
}

static void DoSimpleTest(const std::string & host, int port) {
	printf("running SimpleTset(%s, %d)..\n", host.c_str(), port);
	event_base* base = event_base_new();
	stdcxx::shared_ptr< ::apache::thrift::async::TAsyncChannel>  channel1(new TEvhttpClientChannel(host, "/", host.c_str(), port, base));
	testClient client1(channel1, new TBinaryProtocolFactory());

	sendString(client1);   // 发送第一个请求  

	stdcxx::shared_ptr< ::apache::thrift::async::TAsyncChannel>  channel2(new TEvhttpClientChannel(host, "/", host.c_str(), port, base));
	testClient client2(channel2, new TBinaryProtocolFactory());

	sendString(client2);  // 发送第二个请求  


	event_base_dispatch(base);


	event_base_free(base);


	printf("done DoSimpleTest().\n");
}


int main(int argc, char* argv[])
{
 	WORD version(MAKEWORD(2, 2));
 	WSAData data = { 0 };
 	int error(WSAStartup(version, &data));
 	if (error != 0) {
 		BOOST_ASSERT(false);
		throw std::runtime_error("Failed to initialise Winsock.");
 	}
	//try {
	//	event_base* evbase = event_base_new();
	//	stdcxx::shared_ptr<TAsyncChannel> channel(new TEvhttpClientChannel("127.0.0.1", "/", "127.0.0.1", 14488, evbase));	//"127.0.0.1", "/", "127.0.0.1", 14488, evbase
	//	testClient client(channel, new TBinaryProtocolFactory());
	//	std::function<void(TwitterCobClient* client)> cob = bind(&my_recv_sendString, _1);

	//	client.sendString(cob, "ping");
	//	printf("[%d] ping\n", (int)time(NULL));

	//	for (int i = 0; i < 5; i++)
	//	{
	//		printf("[%d] running...\n", (int)time(NULL));
	//		Sleep(1);
	//	}

	//	event_base_dispatch(evbase);
	//	event_base_free(evbase);
	//}
	//catch (TException& exc)
	//{
	//	printf("%s\n", exc.what());
	//}
	//catch (...)
	//{
	//	printf("exception");
	//	return 1;
	//}



 	DoSimpleTest("127.0.0.1", 14488);	//"localhost", 14488	使用localhost会有异常
 	WSACleanup();
	return 0;


}