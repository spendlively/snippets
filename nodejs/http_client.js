
//client.js
var http = require('http');
var request = http.request({
        host: 'localhost',
        port: '8989',
        path: '/',
        method: 'POST'
    },
    function(response){
        response.on('data', function(data){
            console.log(data.toString());
        });
    });
request.write('Hello, world!');
request.end();





//server.js
var http = require('http');
http.createServer(function(request, response){
    response.writeHead(200);
    request.on('data', function(data){
        console.log('Request: ',  data.toString());
        response.write('Write: ' + data.toString());
    });
    request.on('end', function(){
        console.log('The end');
    });
}).listen(8989);