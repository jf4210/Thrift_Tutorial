#include <iostream>
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
#include <thrift/async/TAsyncProtocolProcessor.h>
#include <thrift/async/TEvhttpServer.h>
#include "../Interface-Asyn/gen-cpp/Twitter.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using std::string;
using namespace boost;
using namespace  ::example;
using namespace apache::thrift::async;


class TwitterAsyncHandler : public TwitterCobSvIf {
public:
	TwitterAsyncHandler() {
		// Your initialization goes here  
	}


	void sendString(std::function<void(std::string const& _return)> cob, const std::string& data) {
		printf("sendString rec:%s\n", data.c_str());  // 输出收到的数据  
		std::string _return = "world";   // 返回world字符串给客户端  
		return cob(_return);
	}


};

int main(int argc, char **argv) {
	stdcxx::shared_ptr<TAsyncProcessor> underlying_pro(new TwitterAsyncProcessor(stdcxx::shared_ptr<TwitterCobSvIf>(new TwitterAsyncHandler())));
	stdcxx::shared_ptr<TAsyncBufferProcessor> processor(new TAsyncProtocolProcessor(underlying_pro, stdcxx::shared_ptr<TProtocolFactory>(new TBinaryProtocolFactory())));

	WORD version(MAKEWORD(2, 2));
	WSAData data = { 0 };

	int error(WSAStartup(version, &data));
	if (error != 0) {
		BOOST_ASSERT(false);
		throw std::runtime_error("Failed to initialise Winsock.");
	}

	try
	{
		TEvhttpServer server(processor, 14488);
		server.serve();
	}
	catch (TException& exc)
	{
		std::cout << exc.what();
	}
	WSACleanup();
	system("pause");
	return 0;
}