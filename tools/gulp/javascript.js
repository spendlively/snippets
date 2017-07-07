
//Простая сборка javascript
//npm install gulp-concat
var gulp = require('gulp');
var concat = require('gulp-concat');

gulp.task('default', function () {
    return gulp.src('js/**/*.js')
        .pipe(concat("all.js"))
        .pipe(gulp.dest('out/'));
});



//Минификация
//npm install gulp-uglify
//npm install gulp-uglyfly
var gulp = require('gulp');
var concat = require('gulp-concat');
var uglyfly = require('gulp-uglyfly');

gulp.task('default', function () {
    return gulp.src('js/**/*.js')
        .pipe(concat("all.js"))
        .pipe(uglyfly())
        .pipe(gulp.dest('out/'));
});



//Проверка кода в соответствии с различными стайл гайдами
//npm install gulp-jscs



//Веб-сервер
//npm install gulp-express



//Поддор необходимых полифиллов для javascript
//npm install gulp-autopolyfiller



//babel
//npm install gulp-babel



//Линтер
//npm install gulp-jshint
