
var vm1 = new Vue({
    el: '#ex1',
    data: {
        isActive: true,
        hasError: false
    }
})



var vm2 = new Vue({
    el: '#ex2',
    data: {
        classObject: {
            active: true,
            'text-danger': false
        }
    }
})



var vm3 = new Vue({
    el: '#ex3',
    data: {
        isActive: true,
        error: null
    },
    computed: {
        classObject: function () {
            return {
                active: this.isActive && !this.error,
                'text-danger': this.error && this.error.type === 'fatal'
            }
        }
    }
})



var vm4 = new Vue({
    el: '#ex4',
    data: {
        activeClass: 'active',
        errorClass: 'text-danger'
    }
})



var vm5 = new Vue({
    el: '#ex5',
    data: {
        isActive: true,
        activeClass: 'active',
        errorClass: 'text-danger'
    }
})



var vm6 = new Vue({
    el: '#ex6',
    data: {
        isActive: true,
        activeClass: 'active',
        errorClass: 'text-danger'
    }
})



Vue.component('my-component', {
    template: '<p class="foo bar">COMPONENY</p>'
})
var vm7 = new Vue({
    el: '#ex7',
    data: {
        isActive: true,
        activeClass: 'active'
    }
})



var ex8 = new Vue({
    el: '#ex8',
    data: {
        activeColor: 'red',
        fontSize: 30
    }
})



var ex9 = new Vue({
    el: '#ex9',
    data: {
        styleObject: {
            color: 'red',
            fontSize: '13px'
        }
    }
})



var ex10 = new Vue({
    el: '#ex10',
    data: {
        baseStyles: {color: 'red'},
        overridingStyles: {fontSize: '13px'}
    }
})
