
(() => {

    console.log("04 =============================================================");

    /**
     * Передача значений
     */
    function* gen() {
        let ask1 = yield "2 + 2?";

        alert(ask1); //2) 4

        let ask2 = yield "3 * 3?"

        alert(ask2); //4) 9
    }

    let generator = gen();

    alert( generator.next().value ); //1) "2 + 2?"

    alert( generator.next(4).value ); //3) "3 * 3?"

    alert( generator.next(9).done ); //5) true

})();

