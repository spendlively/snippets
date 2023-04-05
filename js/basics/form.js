
//Поиск в DOM
// <form name="my" action="#">
// 	<fieldset name="set">
// 		<input name="one" value="1" autofocus>
// 		<input name="two" value="2">
// 	</fieldset>
// 	<select name="mySelect" multiple>
//     	<option value="myOption1" selected>Option 1</option>
//     	<option value="myOption2">Option 2</option>
// 	</select>	
// </form>
var form1 = document.forms.my;
var form2 = document.forms[0];
var input1 = form1.elements.one;
var input2 = form1.elements.set.elements.two;
var select = form1.elements.mySelect;
for (var i = 0; i < select.options.length; i++) {
	var option = select.options[i];
	if(option.selected){
    	console.log(option.value);
	}
}





//Добавить option в select
select.appendChild(new Option("Option 3", "myOption3"));





//События
input1.onblur = function(){
	console.log('blur');
};
input1.onfocus = function(){
	console.log('focus');
};
input1.onchange = function(){
	console.log('change');
};
input1.oninput = function(){
	//не ждет потери фокуса
	console.log('input');
};
input1.oncut = function(){
	console.log('cut');
};
input1.oncopy = function(){
	console.log('copy');
};
input1.onpaste = function(){
	console.log('paste');
};





//Отправка формы
form1.onsubmit = function(){
	alert('Форма не отправится');
	return false;
};
// form1.submit();
