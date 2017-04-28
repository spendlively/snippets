
//Assert
describe("pow (возведение в степень)", function() {

	it("2 ^ 3 = 8", function() {
		chai.assert.equal(pow(2, 3), 8);
	});

	it("3 ^ 4 = 81", function() {
		chai.assert.equal(pow(3, 4), 81);
	});
});



//Вложенный describe
describe("возведение в степень", function() {

	describe("pow", function() {

		it("3 ^ 4 = 81", function() {
			chai.assert.equal(pow(3, 4), 81);
		});
	});
});



//Функции до и после
describe("pow", function() {

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



//Другие assert
// assert(value) – проверяет что value является true в логическом контексте.
// assert.equal(value1, value2) – проверяет равенство value1 == value2.
// assert.strictEqual(value1, value2) – проверяет строгое равенство value1 === value2.
// assert.notEqual, assert.notStrictEqual – проверки, обратные двум предыдущим.
// assert.isTrue(value) – проверяет, что value === true
// assert.isFalse(value) – проверяет, что value === false
