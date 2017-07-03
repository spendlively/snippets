
//PIPE (Вывалит: STARThello)
var server = require('http').createServer().listen(8989);
server.on('request', function(req, res){
    res.writeHead(200);
    res.write('START');
    req.pipe(res);
});
//curl -d 'hello' http://localhost:8989





//Запись из файла в файл с помощью потока pipe
var fs = require('fs');
var fileToRead = fs.createReadStream('fileFrom.txt');
var fileToWrite = fs.createWriteStream('fileTo.txt');
fileToRead.pipe(fileToWrite);





//Загрузка файла на сервер
var fs = require('fs');
var http = require('http').createServer().listen(8989);
http.on('request', function(req, res){
    res.writeHead(200);
    var fileTo = fs.createWriteStream('fileTo.txt');
    req.pipe(fileTo);
    req.on('end', function(){
        res.end('UPLOADED!');
    });
});
//curl --upload-file fileFrom.txt http://localhost:8989





//Запись файла с помощью file.write()
var fs = require('fs');
var http = require('http').createServer().listen(8989);
http.on('request', function(req, res){
    res.writeHead(200);
    var fileTo = fs.createWriteStream('fileTo.txt');
    req.on('data', function(data){
        data = "Data from client: \n" + data;
        fileTo.write(data);
    });
    req.on('end', function(){
        res.end("UPLOADED!\n");
    });
});





//Вывод файла на экран
var fs = require('fs');
var file = fs.createReadStream('index.html');
file.on('data', function(data){
    console.log(data.toString())
});





//Вывод файла на экран с помощью pipe
var fs = require('fs');
var file = fs.createReadStream('index.html');
file.pipe(process.stdout);





//Вывод картинки в браузере
var fs = require('fs');
var http = require('http');
http.createServer(function(req, res){

    res.writeHead(200, {'Content-Type': 'image/gif'});
    var file = fs.createReadStream('logo.jpg');
    file.pipe(res);

}).listen(8989);