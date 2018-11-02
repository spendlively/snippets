
(() => {

    console.log("02 =============================================================");

    /**
     * Генератор является итерируемым объектом
     */
    function* getGenerator(){
        yield 1;
        yield 2;
        return 3;
    }

    let generator = getGenerator();

    for(let value of generator) {
        console.log(value); //1, 2 (return 3 будет проигнорировано)
    }

})();

