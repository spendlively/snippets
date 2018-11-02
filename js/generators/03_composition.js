
(() => {

    console.log("03 =============================================================");

    /**
     * Композиция генераторов
     */
    function* generateSequence(start, end) {
        for (let i = start; i <= end; i++) yield i;
    }

    function* generateAlphaNum() {

        // 0..9
        yield* generateSequence(48, 57);

        // A..Z
        yield* generateSequence(65, 90);

        // a..z
        yield* generateSequence(97, 122);

    }

    let str = '';

    for(let code of generateAlphaNum()) {
        str += String.fromCharCode(code);
    }

    console.log(str); // 0..9A..Za..z
})();

