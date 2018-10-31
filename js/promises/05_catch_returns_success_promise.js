/**
 * Обработчик reject тоже возвращает успешно завершенное обещание
 */

(() => {

    console.log("05==========================================================");

    let promise = new Promise(function (resolve, reject) {
        reject('error');
    });

    promise
        .catch(function (error) {
            return 'catch ' + error;
        })
        .then(
            function (data) {
                console.log('resolve ' + data); //resolve catch error
            },
            function (error) {
                console.error('reject' + error); //DID NOT RUN
            }
        );

    /**
     Результат:
     resolve catch error
     */


})();
