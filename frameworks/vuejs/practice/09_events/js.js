
// 1
new Vue({
    el: '#example-1',
    data: {
        counter: 0
    }
})



// 2
var example2 = new Vue({
    el: '#example-2',
    data: {
        name: 'Vue.js'
    },
    // определяйте методы в объекте `methods`
    methods: {
        greet: function (event) {
            // `this` внутри методов указывает на экземпляр Vue
            alert('Привет, ' + this.name + '!')
            // `event` — нативное событие DOM
            if (event) {
                alert(event.target.tagName)
            }
        }
    }
})

setTimeout(() => {
    // вызывать методы можно и императивно
    // example2.greet() // => 'Привет, Vue.js!'
}, 3000)



// 3
new Vue({
    el: '#example-3',
    methods: {
        say: function (message) {
            alert(message)
        }
    }
})



// 4
new Vue({
    el: '#ex4',
    methods: {
        warn: function (message, event) {
            // теперь у нас есть доступ к нативному событию
            if (event) event.preventDefault()
            alert(message)
        }
    }
})



// 5
new Vue({
    el: '#ex5',
    methods: {
        submit: function(){
            alert('SUBMIT')
        }
    }
})



// 6
new Vue({
    el: '#ex6',
    methods: {
        onClick: function(){
            alert('onClick')
        },
        onCtrlClick: function(){
            alert('onCtrlClick')
        },
    }
})

















