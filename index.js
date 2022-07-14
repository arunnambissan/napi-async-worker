const runWorker = require('./build/Release/napi-asyncworker-example-native');


const task = runWorker.runSimpleAsyncWorker((err, result) => {
    if (err) {
        console.log("SimpleAsyncWorker returned an error: ", err);
    } else {
        console.log("SimpleAsyncWorker returned '"+result+"'.");
    }
});

console.log(task)