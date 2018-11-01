(() => {

    console.log("02 ===================================================");

    /**
     * Выборс исключения
     */
    async function throwsValue() {
        throw new Error('Error!!!');
    }

    /**
     * Обработка в then
     */
    throwsValue()
        .then((resolve) => {
                console.log("resolve:" + resolve);
            },
            (reject) => {
                console.log("reject:" + reject);
            });

    /**
     * Обработка в catch
     */
    throwsValue()
        .then((resolve) => {
            console.log("resolve:" + resolve);
        })
        .catch((reject) => {
            console.log("reject:" + reject);
        });

})();

/**
 * Результат:
 * reject:Error: Error!!!
 */
