/**
 * Promise.all запускает несколько паралельно
 */

(() => {

    console.log("07==========================================================");

    let promiseOne = () => {
        return new Promise((resolve, reject) => {
            setTimeout(() => {
                console.log('promiseOne');
                resolve('promiseOne');
            }, 200);
        });
    };

    let promiseTwo = () => {
        return new Promise((resolve, reject) => {
            setTimeout(() => {
                console.log('promiseTwo');
                resolve('promiseTwo');
            }, 100);
        });
    };

    let promiseThree = () => {
        return new Promise((resolve, reject) => {
            console.log('promiseThree');
            resolve('promiseThree');
        });
    };

    /**
     * Запустить третий промис, когда первые 2 успешно отработают
     */
    Promise.all([
        promiseOne(),
        promiseTwo()
    ]).then(() => {
        promiseThree();
    });

    /**
     Результат:
        promiseTwo
        promiseOne
        promiseThree
     */

})();
