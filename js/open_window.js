
//Open simple window
var win1 = window.open("http://ya.ru");





//Open window with simple text
var win2 = window.open("javascript:'win2'", "win2", "width=200,height=200");





//Open blank window and document.write
var win3 = window.open("about:blank", "win3", "width=200,height=200");
win3.document.write("win3");





// Open blank window and append html
var win4 = window.open('/', 'win4', 'width=200,height=200');
win4.onload = function() {

	var div = win4.document.createElement('div'),
		body = win4.document.body;

	div.innerHTML = 'win4'

	body.append(div);
}





//Ссылка на родителя в открытом окне 
window.opener;
window.opener.document;
window.opener.document.body;





//Доступ к iframe
// <iframe src="javascript:'тест'" style="height:60px"></iframe>
var iframe = document.getElementsByTagName('iframe')[0];
var iframeDoc = iframe.contentWindow.document;





//События
// onresize – событие изменения размера окна.
// onscroll – событие при прокрутке окна.
// onload – полностью загрузилась страница со всеми ресурсами.
// onfocus/onblur





//Методы
// window.closed
// window.close()
// win.moveBy(x,y)
// win.moveTo(x,y)
// win.resizeBy(width,height)
// win.resizeTo(width,height)
