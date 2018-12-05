
onmessage = function(e) {
    postMessage('Worker ' + e.data + ' has started');

    var i = 0;
    while(true){
        i++;
    }
};
