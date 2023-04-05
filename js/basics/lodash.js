
//Библиотека LoDash
//<script src="https://cdnjs.cloudflare.com/ajax/libs/lodash.js/4.3.0/lodash.js"></script>





//Шаблоны
//1. Код
// <% code %>
//2. Вставка HTML, <%=2+2%> вставит 4.
// <%= expr %>
//3. Вставка текста, <br> вставит &lt;br&gt;
// <%- expr %>





//Обработка шаблона из строки
var tmpl = _.template('<h1><%=title%></h1>');
document.write(tmpl({
  title: "Заголовок"
}));





//Обработка шаблона из документа
// <script type="text/template" id="my-ul">
// <ul>
//   <% for (var i=1; i<=count; i++) { %>
//   <li><%=i%></li>
//   <% } %>
// </ul>
// </script>
var tmpl = _.template(document.getElementById('my-ul').innerHTML);
var result = tmpl({count: 5});
document.write( result );





//Обход массива forEach и вставка в body
// <script type="text/template" id="my-ul">
// 	<ul>
// 			<% items.forEach(function(item) { %>
//   			<li><%-item%></li>
//   		<% }); %>
// 	</ul>
// </script>
var tpl = _.template(document.getElementById('my-ul').innerHTML);
document.body.insertAdjacentHTML('afterBegin', tpl({
	items: [1,2,3,4,5]
}));
