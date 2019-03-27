import {text} from './test';

let div = document.createElement('div');
div.innerHTML = "<h1>" + text + "</h1>";
document.body.appendChild(div);
