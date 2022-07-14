#include "SimpleAsyncWorker.h"
#include <chrono>
#include <thread>

SimpleAsyncWorker::SimpleAsyncWorker(Function& callback)
    : AsyncWorker(callback){};


void sampleSyncFunction() {
  std::this_thread::sleep_for(std::chrono::seconds(15)); // 15 second long task
}

void SimpleAsyncWorker::Execute() {
  // int runTime = 20;
  
  // call long sync process 
  sampleSyncFunction();

  // if (runTime == 4) SetError("Failed");
};

void SimpleAsyncWorker::OnOK() {
  std::string msg = "Success";
  Callback().Call({Env().Null(), String::New(Env(), msg)});
};