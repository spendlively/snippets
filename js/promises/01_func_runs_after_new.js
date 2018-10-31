(function() {

    console.log("01================================================");

    /**
     * 1. Функция переданная в new Promise вызывается срвзу же,
     */

    let promise1 = new Promise((resolve, reject) => {
        console.log('111');
        resolve('222');
    });

    promise1.then((data) => {
        console.log(data);
    });

    /**
     * Поэтому new Promise нужно возвращать из другой функции
     */

    function getPromise() {
        return new Promise((resolve, reject) => {
            console.log('111');
            resolve('222');
        });
    }

    let promise2 = getPromise();
    promise2.then((data) => {
        console.log(data);
    });

})();