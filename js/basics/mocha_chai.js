
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
//Успех - done()
//Неудача - done("Error) или throw new Error("Error")
describe("test", function() {

    it("2 ^ 3 = 8 (success)", function(done) {

        setTimeout(function(){
            done(chai.assert.equal(pow(2, 3), 8));
        }, 1000);
    });

    it("2 ^ 3 = 9 (failure)", function(done) {

        setTimeout(function(){
            done(chai.assert.equal(pow(2, 3), 9));
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

