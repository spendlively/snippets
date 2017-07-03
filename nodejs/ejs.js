
//Установка embedded js
npm install ejs



//user.ejs
<!-- Строка -->
<h3>Пользователь <%= name %> </h3>

    <!-- Цикл -->
    <ul>
    <% users.forEach(function(name)){ %>
<li>User name: <% name %> </li>
    <% }); %>
</ul>
//end user.ejs



//app.js
var express = require('express');
var app = express();
app.listen(8989);

app.set('views', __dirname);
app.set('view engine', 'ejs');



//localhost:8989/John
app.get('/:name', function(request, response){
    response.render('user', {name: request.params.name});
    response.end();
});