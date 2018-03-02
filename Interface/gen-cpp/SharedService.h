/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef SharedService_H
#define SharedService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "shared_types.h"

namespace shared {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class SharedServiceIf {
 public:
  virtual ~SharedServiceIf() {}
  virtual void getStruct(SharedStruct& _return, const int32_t key) = 0;
};

class SharedServiceIfFactory {
 public:
  typedef SharedServiceIf Handler;

  virtual ~SharedServiceIfFactory() {}

  virtual SharedServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(SharedServiceIf* /* handler */) = 0;
};

class SharedServiceIfSingletonFactory : virtual public SharedServiceIfFactory {
 public:
  SharedServiceIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<SharedServiceIf>& iface) : iface_(iface) {}
  virtual ~SharedServiceIfSingletonFactory() {}

  virtual SharedServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(SharedServiceIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<SharedServiceIf> iface_;
};

class SharedServiceNull : virtual public SharedServiceIf {
 public:
  virtual ~SharedServiceNull() {}
  void getStruct(SharedStruct& /* _return */, const int32_t /* key */) {
    return;
  }
};

typedef struct _SharedService_getStruct_args__isset {
  _SharedService_getStruct_args__isset() : key(false) {}
  bool key :1;
} _SharedService_getStruct_args__isset;

class SharedService_getStruct_args {
 public:

  SharedService_getStruct_args(const SharedService_getStruct_args&);
  SharedService_getStruct_args& operator=(const SharedService_getStruct_args&);
  SharedService_getStruct_args() : key(0) {
  }

  virtual ~SharedService_getStruct_args() throw();
  int32_t key;

  _SharedService_getStruct_args__isset __isset;

  void __set_key(const int32_t val);

  bool operator == (const SharedService_getStruct_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const SharedService_getStruct_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SharedService_getStruct_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SharedService_getStruct_pargs {
 public:


  virtual ~SharedService_getStruct_pargs() throw();
  const int32_t* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SharedService_getStruct_result__isset {
  _SharedService_getStruct_result__isset() : success(false) {}
  bool success :1;
} _SharedService_getStruct_result__isset;

class SharedService_getStruct_result {
 public:

  SharedService_getStruct_result(const SharedService_getStruct_result&);
  SharedService_getStruct_result& operator=(const SharedService_getStruct_result&);
  SharedService_getStruct_result() {
  }

  virtual ~SharedService_getStruct_result() throw();
  SharedStruct success;

  _SharedService_getStruct_result__isset __isset;

  void __set_success(const SharedStruct& val);

  bool operator == (const SharedService_getStruct_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SharedService_getStruct_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SharedService_getStruct_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SharedService_getStruct_presult__isset {
  _SharedService_getStruct_presult__isset() : success(false) {}
  bool success :1;
} _SharedService_getStruct_presult__isset;

class SharedService_getStruct_presult {
 public:


  virtual ~SharedService_getStruct_presult() throw();
  SharedStruct* success;

  _SharedService_getStruct_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class SharedServiceClient : virtual public SharedServiceIf {
 public:
  SharedServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  SharedServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getStruct(SharedStruct& _return, const int32_t key);
  void send_getStruct(const int32_t key);
  void recv_getStruct(SharedStruct& _return);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class SharedServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<SharedServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (SharedServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getStruct(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  SharedServiceProcessor(::apache::thrift::stdcxx::shared_ptr<SharedServiceIf> iface) :
    iface_(iface) {
    processMap_["getStruct"] = &SharedServiceProcessor::process_getStruct;
  }

  virtual ~SharedServiceProcessor() {}
};

class SharedServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  SharedServiceProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< SharedServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< SharedServiceIfFactory > handlerFactory_;
};

class SharedServiceMultiface : virtual public SharedServiceIf {
 public:
  SharedServiceMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<SharedServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~SharedServiceMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<SharedServiceIf> > ifaces_;
  SharedServiceMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<SharedServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getStruct(SharedStruct& _return, const int32_t key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getStruct(_return, key);
    }
    ifaces_[i]->getStruct(_return, key);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class SharedServiceConcurrentClient : virtual public SharedServiceIf {
 public:
  SharedServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  SharedServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getStruct(SharedStruct& _return, const int32_t key);
  int32_t send_getStruct(const int32_t key);
  void recv_getStruct(SharedStruct& _return, const int32_t seqid);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif
