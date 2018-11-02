
(() => {

    console.log("05 =============================================================");

    /**
     * Передача исключения
     */
    function* gen() {
        try {
            // в этой строке возникнет ошибка
            let result = yield "Сколько будет 2 + 2?"; // (**)

            alert("выше будет исключение ^^^");
        } catch(e) {
            alert(e); // выведет ошибку
        }
    }

    let generator = gen();

    let question = generator.next().value;

    generator.throw(new Error("ответ не найден в моей базе данных")); // (*)

})();

