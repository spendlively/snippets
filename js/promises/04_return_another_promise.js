/**
 * 1. promise.then() всегда возвращает promise.
 *
 * 2. Однако в promise.then() можно вернуть
 * и другой promise с помощью return new Promise()
 *
 * Таким образом можно делать последовательные асинхронные вызовы.
 */

(() => {

    console.log("04==========================================================");

    let firstPromise = () => {
        return new Promise((resolve, reject) => {
            console.log('new firstPromise');
            resolve('first promise');
        });
    };

    let secondPromise = () => {
        return new Promise((resolve, reject) => {
            console.log('new secondPromise');
            resolve('second promise');
        });
    };

    firstPromise() //new firstPromise
        .then((data) => {
            console.log('then 1', data); //then 1 first promise
            return 'test';
        })
        .then((data) => {
            console.log('then 2', data); //then 2 test
            return secondPromise(); //new secondPromise
        })
        .then((data) => {
            console.log('then 3', data); //then 3 second promise
        });

    /**
     Результат:
     new firstPromise
     then 1 first promise
     then 2 test (undefined - если не указан return)
     new secondPromise
     then 3 second promise
     */

})();


