(() => {

    console.log("02================================================");

    /**
     * Исключение в "new Promise" вызовет reject,
     * как если бы весь код функции был обрамлен try/catch.
     *
     * Если promise.catch() (promise.then(null, foo))
     * не описан, ошибка быдет выброшена наружу.
     */
    let promise1 = new Promise(() => {
        console.log('new Promise');
        throw new Error('Ошибка');
    });

// promise1.then(null, (error) => {
//     console.log(error);
// });

    promise1.catch((error) => {
        console.log(error);
        console.log(error.message);
    });

})();
