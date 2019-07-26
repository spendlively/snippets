
// 1
// свойство data у компонентов должно быть функцией
// чтобы каждый экземпляр компонента управлял собственной
// независимой копией возвращаемого объекта данных:


Vue.component('button-counter', {
    data: function () {
        return {
            count: 0
        }
    },
    template: '<button v-on:click="count++">Счётчик кликов — {{ count }}</button>'
})
new Vue({ el: '#components-demo' })
// Есть два типа регистрации компонентов: глобальная и локальная
// Этот пример глобальной регистрации




// 2
Vue.component('blog-post', {
    props: ['title'],
    template: '<h4>{{ title }}</h4>'
})
new Vue({ el: '#e2' })



// 3
new Vue({
    el: '#e3',
    data: {
        posts: [
            { id: 1, title: 'My journey with Vue' },
            { id: 2, title: 'Blogging with Vue' },
            { id: 3, title: 'Why Vue is so fun' }
        ]
    }
})



// 4
Vue.component('blog-post2', {
    props: ['post'],
    template: `
    <div class="blog-post2">
      <h5>{{ post.title }}</h5>
      <div v-html="post.content"></div>
    </div>
  `
})
new Vue({
    el: '#e4',
    data: {
        posts: [
            { id: 1, title: '111' },
            { id: 2, title: '222' },
            { id: 3, title: '333' }
        ]
    }
})


//5

Vue.component('blog-post3', {
    props: ['post'],
    template: `
    <div class="blog-post">
        <h3>{{ post.title }}</h3>
        <button v-on:click="$emit('enlarge-text', 0.1)">
          Увеличить размер текста
        </button>
        <div v-html="post.content"></div>
    </div>
  `
})
new Vue({
    el: '#blog-posts-events-demo',
    data: {
        posts: [
            {id: 1, content: 'qwerty'},
            {id: 2, content: 'asdfgh'},
            {id: 3, content: 'zxcvbn'}
        ],
        postFontSize: 1
    },
    methods: {
        onEnlargeText: function (enlargeAmount) {
            this.postFontSize += enlargeAmount
        }
    }
})



// 6
// добавляем слот там, куда хотим подставлять контент
Vue.component('alert-box', {
    template: `
    <div class="demo-alert-box">
      <strong>Ошибка!</strong>
      <slot></slot>
    </div>
  `
})
new Vue({
    el: '#alert-box',
})
