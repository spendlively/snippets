
//Модуль request
//npm install request



//Создание http-клиента
var request = require('request');
request(url, function(err, res, body){

});



//С использование модуля url
var url = require('url');
var options = {
    protocol: 'http',
    pathname: '/',
    query: {user: 'name'}
};
var needUrl = url.format(options)
request(url, function(err, res, body){

});