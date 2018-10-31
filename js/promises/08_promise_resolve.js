/**
 * Promise.resolve возвращает обещание, которое успешно завершено с переданным значением
 */

(() => {

    console.log("08==========================================================");

    Promise.resolve('resolve')
        .then((data) => {
            console.log(data);
        });

    /**
     Результат: resolve
     */

})();
