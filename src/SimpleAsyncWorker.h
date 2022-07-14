#pragma once
#include <napi.h>
using namespace Napi;

class SimpleAsyncWorker : public AsyncWorker {
 public:
  SimpleAsyncWorker(Function& callback);
  virtual ~SimpleAsyncWorker(){};

  void Execute();
  void OnOK();
};