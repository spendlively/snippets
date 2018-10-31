(() => {

    console.log("03================================================");

    /**
     * Кидать throw "new Error" в onResolve не надо,
     * исключение поймается только в следующем обработчике error/catch
     */

    let promise = new Promise((resolve, reject) => {
        console.log('new Promise');
        resolve('resolve');
    });

// promise
//     .then((data) => {
//         console.log('resolve 1');
//         console.log(data);
//         throw new Error('Error');
//     }, (error) => {
//         //Здесь НЕ отловится ошибка
//         console.log('reject 1');
//         console.log(error);
//     })
//     .then((data) => {
//         console.log('resolve 2');
//         console.log(data);
//     }, (error) => {
//         //Ошибка отловится здесь
//         console.log('reject 2');
//         console.log(error);
//     });
    /**
     * new Promise
     * resolve 1
     * resolve
     * reject 2
     * Error
     */

//Либо так
    promise
        .then((data) => {
            console.log('resolve 1');
            console.log(data);
            throw new Error('Error');
        })
        .catch((error) => {
            //Ошибка отловится здесь
            console.log('reject 1');
            console.log(error);
        });

})();