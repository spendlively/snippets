
//Создание объекта Даты
var d = new Date();
new Date(3600 * 24 * 1000); //01.01.1970 + 24 часа
new Date(2011, 0, 1, 0, 0, 0, 0);
new Date(2011, 0, 1);





//Получение компонентов даты
d.getFullYear();
d.getMonth(); //Месяц (0..11)
d.getDate();
d.getHours();
d.getMinutes();
d.getSeconds();
d.getMilliseconds();
d.getDay(); //День недели (0..6)
d.getUTCFullYear();
d.getUTCMonth();
d.getUTCDay();
d.getTimezoneOffset();





//Изменение даты
d.setFullYear(2017);
d.setMonth(0);
d.setDate(1);
d.setHours(0);
d.setMinutes(0);
d.setSeconds(0);
d.setMilliseconds(0);
d.setTime(3600 * 24 * 1000);





//Автоисправление даты
var d = new Date(2013, 0, 32);
d.setDate(0);
d.setDate(-1)





//Console.time
console.time("test");
console.timeEnd("test");





//Форматирование
var date = new Date(2014, 11, 31, 12, 30, 0);
var options = {
  era: 'long',
  year: 'numeric',
  month: 'long',
  day: 'numeric',
  weekday: 'long',
  timezone: 'UTC',
  hour: 'numeric',
  minute: 'numeric',
  second: 'numeric'
};
console.log(date.toLocaleString("ru", options));
console.log(date.toLocaleString("en-US", options));
//Без локации
console.log(date.toString());
console.log(date.toDateString());
console.log(date.toTimeString());
console.log(date.toISOString());





//Разбор строки
var d1 = Date.parse('2012-01-26T13:51:50.417Z');
var d2 = Date.parse('2012-01-26T13:51:50.417-07:00');
var d3 = Date.parse("January 26, 2011 13:51:50");
