
(() => {

    console.log("01 =============================================================");

    /**
     * 0. function* при вызове возвращает генератор
     * 1. При создании генератора код находится в начале своего выполнения.
     * 2. При вызове next() генератор возобновляет выполнение до ближайшего yield.
     * 3. В yield выполнение приостанавливается, а значение – возвращается во внешний код.
     */
    //function *getGenerator() - другой вариант записи
    function* getGenerator(){
        //getGenerator()
        yield 1; //one
        yield 2; //two
        return 3; //three
    }

    let generator = getGenerator();

    let one = generator.next();
    let two = generator.next();
    let three = generator.next();

    console.log(one); //{value: 1, done: false}
    console.log(two); //{value: 2, done: false}
    console.log(three); //{value: 1, done: true}
    console.log(generator.next()); //{value: undefined, done: true}

})();

