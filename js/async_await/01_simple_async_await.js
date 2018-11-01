(() => {

    console.log("01 ===================================================");

    /**
     * async function определяет асинхронную функцию,
     * которая возвращает объект AsyncFunction
     *
     * После вызова функция async возвращает Promise.
     * Когда результат был получен, Promise завершается,
     * возвращая полученное значение.
     * Когда функция async выбрасывает исключение,
     * Promise ответит отказом с выброшенным (throws) значением.
     *
     * Функция async может содержать выражение await,
     * которое приостанавливает выполнение функции async
     * и ожидает ответа от переданного Promise,
     * затем возобновляя выполнение функции async
     * и возвращая полученное значение.
     *
     * Ключевое слово await допустимо только в асинхронных функциях.
     * В другом контексте вы получите ошибку SyntaxError.
     *
     */

    /**
     * Пример с промисом
     */

    function resolveAfterSecond(x){
        // return x;
        return new Promise(resolve => {
            setTimeout(() => {
                resolve(x);
            }, 1000);
        });
    }

    /**
     * async function возвращает Promise
     */
    async function sum(){

        /**
         * await
         * 1. приостанавливает async function
         * 2. ожидает ответа,
         * 3. возобновляет выполнение функции async
         * 4. возвращет полученное значение
         * 5. используется только в async функциях
         */
        const a = await resolveAfterSecond(10);
        const b = await resolveAfterSecond(20);

        /**
         * Функции resolveAfterSecond выполняются последовательно!
         * 2й таймер срабатывает только после срабатывания первого!
         */

        /**
         * Если не будет await функция "сложит" 2 промиса
         */

        return a + b;
    }

    //2 вариант объявления await
    // async function sum(){
    //     const a = resolveAfterSecond(1);
    //     const b = resolveAfterSecond(2);
    //     return await a + await b;
    // }

    /**
     * async function возвращает Promise
     */
    let promise = sum();
    promise.then(v => {
        console.log(v);
    });

    // sum().then(v => {
    //     console.log(v);
    // });
})();

/**
 * Результат: 30
 */