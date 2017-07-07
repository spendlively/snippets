
//Сборка css в out/styles/bundle.css
//npm install gulp-concat-css
var gulp = require('gulp');
var concatCss = require('gulp-concat-css');

gulp.task('default', function () {
    return gulp.src('css/**/*.css')
        .pipe(concatCss("styles/bundle.css"))
        .pipe(gulp.dest('out/'));
});



//Минификация
//npm install gulp-clean-css
var gulp = require('gulp');
var concatCss = require('gulp-concat-css');
var cleanCSS = require('gulp-clean-css');

gulp.task('default', function () {
    return gulp.src('css/**/*.css')
        .pipe(concatCss("styles/bundle.css"))
        .pipe(cleanCSS({compatibility: 'ie8'}))
        .pipe(gulp.dest('out/'));
});



//Переименовывание в bundle.min.css
//npm install gulp-rename
var gulp = require('gulp');
var concatCss = require('gulp-concat-css');
var cleanCSS = require('gulp-clean-css');
var rename = require("gulp-rename");

gulp.task('default', function () {
    return gulp.src('css/**/*.css')
        .pipe(concatCss("styles/bundle.css"))
        .pipe(cleanCSS({compatibility: 'ie8'}))
        .pipe(rename("bundle.min.css"))
        .pipe(gulp.dest('out/'));
});



//Удаление из сборки селекторов css, которых нет в index.html
//npm install gulp-uncss
var gulp = require('gulp');
var concatCss = require('gulp-concat-css');
var cleanCSS = require('gulp-clean-css');
var rename = require("gulp-rename");
var uncss = require('gulp-uncss');


gulp.task('default', function () {
    return gulp.src('css/**/*.css')
        .pipe(concatCss("styles/bundle.css"))
        .pipe(cleanCSS({compatibility: 'ie8'}))
        .pipe(uncss({
            html: ['index.html']
        }))
        .pipe(rename("bundle.min.css"))
        .pipe(gulp.dest('out/'));
});
