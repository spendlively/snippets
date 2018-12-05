
let workers = [];
for(let i = 1; i <= 4; i++){

    workers[i] = new Worker("worker.js");
    workers[i].postMessage(i);
    workers[i].onmessage = function(e) { console.log(e.data); };
}
