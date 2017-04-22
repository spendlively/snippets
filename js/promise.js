
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
