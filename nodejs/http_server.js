
//http сервер app.js
var http = require('http');
http.createServer(function (request, response){
    response.writeHead(200, {
        'Content-Type': 'text/html; charset=utf-8'
    });
    response.write('Hello, world');
    response.end();
}).listen(8080);
console.log('Listening on 8080...');
//node app.js





//События сервера
var http = require('http');
var server = http.createServer();
server.listen(8989);
server.on('request', function (request, response){
    response.writeHead(200);
    response.write('Hello!');
    response.end(' The end!');
});
server.on('listening', function (request, response){
    console.log('Listen: 8989...');
});
server.on('request', function (request, response){
    console.log('Request:', request.method, request.url, request.statusCode);
});
server.on('connection', function (request, response){
    console.log('Connection');
});
server.on('close', function (request, response){
    console.log('Close');
});





//Модуль URL
console.log(require('url').parse(request.url));
console.log(require('url').parse(request.url, true)); //С разбором параметров





//Пользовательские события
var events = require('events');
var EventEmitter = events.EventEmitter;
var test = new EventEmitter();
test.on('myEvent', function(param){
    console.log(param);
});
test.emit('myEvent', 'Test 1');





//Получение данных методом POST
var server = require('http').createServer().listen(8989);
server.on('request', function(req, res){

    res.writeHead(200);
    res.write('START');

    req.on('data', function(msg){
        console.log(msg.toString());
        //process.stdout.write() / console.log()
    });

    req.on('end', function(){
        res.end();
    });

});
//curl -d 'hello' http://localhost:8989