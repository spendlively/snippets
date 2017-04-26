
//Промис выполняющий XMHttpRequest
var promise = new Promise(function(resolve, reject){

	var xhr = new XMLHttpRequest();
	xhr.open('GET', 'test.json', true);
	xhr.onreadystatechange = function(){
		if(xhr.readyState != 4) return;
		if(xhr.status != 200){
			reject(new Error("Fuck you!"))
	  	}
	  	else{
			resolve(xhr.responseText);
		}
	}
	xhr.send();
});

promise.then(function(success){
	console.log(success);
}, function(error){
	console.log(error);
});





//Промисификация
function getData(){
	return new Promise(function(resolve, reject){

		var xhr = new XMLHttpRequest();
		xhr.open('GET', 'test.json', true);
		xhr.onreadystatechange = function(){
			if(xhr.readyState != 4) return;
			if(xhr.status != 200){
				reject(new Error("Fuck you!"))
		  	}
		  	else{
				resolve(xhr.responseText);
			}
		}
		xhr.send();
	});
}

getData()
	.then(function(success){
		console.log(success);
		return getData();
	})
	.then(function(success){
		console.log(success);
		return getData();
	});





//Чейнинг с обраьботкой ошибок и передачей значений в следующие then	
function getData2(){
	return new Promise(function(resolve, reject){

		setTimeout(function(){
			resolve("Ok");
		}, 500);
	});
}

getData2()
	.then(function(data){
		console.log(1, data);
		return getData2();
	})
	.then(function(data){
		console.log(2, data);
		return getData2();
	})
	.then(function(data){
		console.log(3, data);
		return data; //Просто передать значение в следующий then
	})
	.then(function(data){
		console.log(4, data);
		throw new Error("Error 1");
	})
	.then(null, function(data){
		console.log(5, data);
		throw new Error("Error 2");
	})
	.catch(function(data){
		console.log(6, data);
	});





//Параллельное выполнение массива промисов
//Результат - массив ответов
Promise.all([
	getData(),
	getData(),
	getData()
]).then(function(results){
	console.log(results);
}, function(errors){
	console.log(errors);
});





//Результат - ответ первого промиса
Promise.race([
	getData(),
	getData(),
	getData()
]).then(function(results){
	console.log(results);
}, function(errors){
	console.log(errors);
});





//Создание промиса со значением value для resolve
Promise.resolve('value')
	.then(function(value){
		console.log(value);
	});




//Создание промиса со значением value для reject	
Promise.reject(new Error('error'))
	.catch(function(value){
		console.log(value);
	});