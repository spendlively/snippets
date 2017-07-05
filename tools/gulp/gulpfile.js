'use strict';

const gulp = require('gulp');



//Запуск дефолтной задачи
//gulp
gulp.task('default', function(callback){
    console.log('default');
    callback();
});



//Запуск задачи hello
//gulp hello
gulp.task('test', function(callback){
    console.log('test');
    callback();
});



//Запуск серии задач
// gulp.series
// gulp.parallel



// gulp.task('default', function(callback){
//     return gulp.src('/tmp/*.*')
//         .on('data', function(file){
//             console.log(file);
//         })
//         .pipe(gulp.dest('dest'));
// });



//** - любой путь включая вложенный
gulp.task('default', function(callback){
    return gulp.src('/tmp/**/*.*')
        .on('data', function(file){
            console.log(file);
        })
        .pipe(gulp.dest(function(file){
            return  file.extname == '.js' ? 'js':
                    file.extname == '.css' ? 'css' : 'dest';
        }));
});