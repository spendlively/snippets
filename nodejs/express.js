
//Установка express
//npm install express



//Первое приложение (app.js)
var express = require('express');
var app = express();
app.listen(8989);

app.get('/', function(request, response){
    response.sendfile(__dirname + '/test.html');
});

app.get('/user/:name', function(request, response){
    response.write(request.params.name);
    response.end();
});