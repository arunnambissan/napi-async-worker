#include "SimpleAsyncWorker.h"

Value runSimpleAsyncWorker(const CallbackInfo& info) {
  Function callback = info[0].As<Function>();
  SimpleAsyncWorker* asyncWorker = new SimpleAsyncWorker(callback);
  asyncWorker->Queue();
  std::string msg = "AsyncWorker task queued.";
  return String::New(info.Env(), msg.c_str());
};

Object Init(Env env, Object exports) {
  exports["runSimpleAsyncWorker"] = Function::New(
      env, runSimpleAsyncWorker, std::string("runSimpleAsyncWorker"));
  return exports;
}

NODE_API_MODULE(addon, Init)