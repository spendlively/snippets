
//Callback при загрузке класса
Ext.define('Test', {
    constructor: function(){
        console.log('CONSTRUCTOR')
    }
}, function(){
    console.log('CALLBACK')
});





//Сonfig, геттеры и сеттеры
Ext.define('My.own.Window', {
    extend: 'Ext.window.Window',
    isWindow: true,
    config: {
        title: 'Title Here'
    },
    applyTitle: function(title) {
        if (!this.title && title){
            this.title = title;
        }
    }
});
var myWindow = Ext.create('My.own.Window', {
    renderTo: Ext.getBody(),
    width: 200,
    height: 150,
    bodyPadding: 5,
    html: 'HTML'
});
myWindow.setTitle('TITLE');
myWindow.show();
console.log(myWindow.getTitle());





//Обновление layout вручную
var container = Ext.create('Ext.panel.Panel', {
    renderTo: Ext.getBody(),
    width: 400,
    height: 200,
    title: 'Parent',
    suspendLayout: true
});
container.add({
    xtype: 'panel',
    title: 'Child'
});
container.suspendLayout = false;
container.updateLayout();





//2 варианта добавления нескольких обработчиков на одно событие
//1: наследование
Ext.define('Child', {
    extend: 'Parent',
    constructor: function(config){
        var cfg = this.callParent(arguments);
        this.on({
            beforeshow: function(){
                console.log(222)
            }
        });
        return cfg;
    }
});
Ext.create('Child', {
    listeners: {
        beforeshow: function(){
            console.log(111)
        }
    }
});

//2: композиция
Ext.define('Child', {
    constructor: function(config){
        var tip = Ext.create('Parent', config);
        tip.on({
            beforeshow: function(ths){
                console.log(222)
            }
        });
        return tip;
    }
});
Ext.create('Child', {
    listeners: {
        beforeshow: function(){
            console.log(111)
        }
    }
});





//УСКОРЕНИЕ ГРАФИКОВ
//suspend store events
chartStore.suspendEvents(false);
chartStore.loadData(data);
chartStore.resumeEvents();

//turn off shadows in charts
var chart1 = Ext.create('Ext.chart.Chart',{
    xtype: 'chart',
    animate: false,
    shadow : false,
    //..
});

//turn off markers in each series
showMarkers: false

//use compress ext for testing (not debug version)
ext-all.js  // instead of ext-all-debug.js

//END УСКОРЕНИЕ ГРАФИКОВ

