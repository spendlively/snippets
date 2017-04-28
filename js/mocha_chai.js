
//Assert
describe("Pow (возведение в степень)", function() {

	it("2 ^ 3 = 8", function() {
		chai.assert.equal(pow(2, 3), 8);
	});

	it("3 ^ 4 = 81", function() {
		chai.assert.equal(pow(3, 4), 81);
	});
});



//Вложенный describe
describe("Возведение в степень", function() {

	describe("pow()", function() {

		it("3 ^ 4 = 81", function() {
			chai.assert.equal(pow(3, 4), 81);
		});
	});
});



//Функции до и после
describe("Pow", function() {

	before(function() { console.log("before"); });
	after(function() { console.log("after"); });

	beforeEach(function() { console.log("beforeEach"); });
	afterEach(function() { console.log("afterEach"); });

	it("2 ^ 3 = 8", function() {
		chai.assert.equal(pow(2, 3), 8);
	});

	it("3 ^ 4 = 81", function() {
		chai.assert.equal(pow(3, 4), 81);
	});
});



//Тестирование асинхронного кода
describe("Async", function() {

    it("3 ^ 4 = 81 (Success)", function(done) {

        setTimeout(function(){
            if(pow(3, 4) === 81){
                done();
            }
            else{
                done('Error!')
            }
        }, 1000);
    });

    it("3 ^ 4 = 82 (Failure)", function(done) {

        setTimeout(function(){
            // throw new Error('Error!');
            if(pow(3, 4) === 82){
                done();
            }
            else{
                done('Error!')
            }
        }, 1000);
    });
});



//Другие assert
// assert(value) – проверяет что value является true в логическом контексте.
// assert.equal(value1, value2) – проверяет равенство value1 == value2.
// assert.strictEqual(value1, value2) – проверяет строгое равенство value1 === value2.
// assert.notEqual, assert.notStrictEqual – проверки, обратные двум предыдущим.
// assert.isTrue(value) – проверяет, что value === true
// assert.isFalse(value) – проверяет, что value === false
