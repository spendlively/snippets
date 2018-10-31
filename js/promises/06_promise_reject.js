/**
 * Promise.reject(value) возвращает неуспешное обещание с переданным значением
 */

(() => {

    console.log("06==========================================================");

    Promise.reject('reject')
        .catch((value) => {
            console.log(value); //reject
        });

    /**
     * Прием, возвращающий отклоненное обещание с заданным значением.
     */

    let getPromise = () => Promise.reject('error');

    getPromise()
        .catch((error) => {
            console.log('catch', error);
        });

    /**
     Результат: catch error
     */


})();
