////////////////////////////////////////////////////////////
///////////////Создание своего модуля///////////////////////
////////////////////////////////////////////////////////////
//one.js
var one = function(){
    console.log('one');
}
module.exports = one;

//two.js
exports.two = function(){
    console.log('two');
}

//three.js
function Three(){
    this.test = function(){
        console.log('three');
    }
}
exports.Three = Three;

//four.js
function Four(){
    this.test = function(){
        console.log('four');
    }
}
module.exports = Four;

//five.json
{
    "f": "five"
}

//all.js
var one = require('./one');
var two = require('./two');
var three = require('./three');
var obj3 = new three.Three();
var Four = require('./four');
var obj4 = new Four();
var five = require('./five');

one(); //one \n
two.two(); //two \n
require('./two').two(); //two \n
obj3.test(); //three
obj4.test(); //four
console.log(five.f); //five
