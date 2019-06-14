
// 1
var e1 = new Vue({
    el: '#e1',
    data: {
        items: [
            { message: 'Foo' },
            { message: 'Bar' }
        ]
    }
})

//Методы внесения изменений
// push()
// pop()
// shift()
// unshift()
// splice()
// sort()
// reverse()
var period = 0
setTimeout(() => {e1.items.push({ message: '111'})}, ++period*1000)
setTimeout(() => {e1.items.push({ message: '222'})}, ++period*1000)
setTimeout(() => {e1.items.push({ message: '333'})}, ++period*1000)
setTimeout(() => {e1.items.push({ message: '444'})}, ++period*1000)
setTimeout(() => {e1.items.push({ message: '555'})}, ++period*1000)
setTimeout(() => {e1.items.push({ message: '666'})}, ++period*1000)

//Методы замены
// filter()
// concat()
// slice()
setTimeout(() => {
    e1.items = e1.items.filter(function (item, ind) {
        return ind%2
    })
}, ++period*1000)




// 2
var e2 = new Vue({
    el: '#e2',
    data: {
        parentMessage: 'Родитель',
        items: [
            { message: 'Foo' },
            { message: 'Bar' }
        ]
    }
})



// 3
var e3 = new Vue({
    el: '#e3',
    data: {
        items: [
            { message: 'Foo' },
            { message: 'Bar' }
        ]
    }
})



// 4
new Vue({
    el: '#v-for-object',
    data: {
        object: {
            title: 'How to do lists in Vue',
            author: 'Jane Doe',
            publishedAt: '2016-04-10'
        }
    }
})



// 5
new Vue({
    el: '#v-for-object2',
    data: {
        object: {
            title: 'How to do lists in Vue',
            author: 'Jane Doe',
            publishedAt: '2016-04-10'
        }
    }
})



// 6
new Vue({
    el: '#v-for-object3',
    data: {
        object: {
            title: 'How to do lists in Vue',
            author: 'Jane Doe',
            publishedAt: '2016-04-10'
        }
    }
})



// 7
new Vue({
    el: '#e7',
    data: {
        items: [
            { message: 'Foo' },
            { message: 'Bar' }
        ]
    }
})




// Из-за ограничений JavaScript, Vue не способен отследить следующие изменения в массиве:
// 1) Прямую установку элемента по индексу: vm.items[indexOfItem] = newValue
// 2) Явное изменение длины массива: vm.items.length = newLength

// Решение установки нового значения по индексу
// 1) Использовать Vue.set:
// Vue.set(vm.items, indexOfItem, newValue)

// 2) Использовать Array.prototype.splice:
// vm.items.splice(indexOfItem, 1, newValue)


// 8
var el8 = new Vue({
    el: '#el8',
    data: {
        items: [
            {message: 111},
            {message: 222},
            {message: 333},
            {message: 444},
            {message: 555},
        ]
    }
})
setTimeout(() => {
    el8.$set(el8.items, 0, {message: '000'})
}, 1000)



// 9
new Vue({
    el: '#el9',
    data: {

    }
})



// 10
Vue.component('todo-item', {
    template: '\
    <li>\
      {{ title }}\
      <button v-on:click="$emit(\'remove\')">Удалить</button>\
    </li>\
  ',
    props: ['title']
})

new Vue({
    el: '#todo-list-example',
    data: {
        newTodoText: '',
        todos: [
            {
                id: 1,
                title: 'Помыть посуду'
            },
            {
                id: 2,
                title: 'Вынести мусор'
            },
            {
                id: 3,
                title: 'Подстричь газон'
            }
        ],
        nextTodoId: 4
    },
    methods: {
        addNewTodo: function () {
            this.todos.push({
                id: this.nextTodoId++,
                title: this.newTodoText
            })
            this.newTodoText = ''
        }
    }
})
