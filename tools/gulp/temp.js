
//Сборка styl в css в папку public/
//npm i -D gulp-stylus
//npm i -D stylus
gulp.task('styles', function(){
    return gulp.src('/path/to/styles/**/*.styl')
        .pipe(stylus())
        .pipe(gulp.dest('public'));
});

//Сборка styl в css в папку public/styles/
gulp.task('styles', function(){
    return gulp.src('/path/to/styles/**/*.styl', {base: 'frontend'})
        .pipe(stylus())
        .pipe(gulp.dest('public'));
});



//Объединение css в один файл //concat('all.css')
const concat = require('gulp-concat');
gulp.task('styles', function(){
    return gulp.src('styles/**/*.styl')
        .pipe(stylus())
        .pipe(concat('all.css'))
        .pipe(gulp.dest('public'));
});



//Сборка с sourcemaps
const sourcemaps = require('gulp-sourcemaps');
gulp.task('styles', function(){
    return gulp.src('styles/**/*.styl')
        .pipe(sourcemaps.init()) //file.sourceMap
        .pipe(stylus())
        .pipe(sourcemaps.write()) //Запись sourcemaps в сами файлы
        //.pipe(sourcemaps.write('.')) //Запись sourcemaps в файл all.css.map
        .pipe(gulp.dest('public'));
});



//Отладка
const concat = require('gulp-debug');
gulp.task('styles', function(){
    return gulp.src('styles/**/*.styl')
        .pipe(debug({title: 'src'}))
        .pipe(stylus())
        .pipe(debug({title: 'stylus'}))
        .pipe(concat('all.css'))
        .pipe(debug({title: 'concat'}))
        .pipe(gulp.dest('public'));
});



//Группировка задач
const del = require('del');
gulp.task('clean', function(){
    return del('public');
});

gulp.task('build1', gulp.series('clean', 'styles'));

gulp.task('build2', gulp.series('clean', gulp.parallel('styles', 'other')));



//Автоматическая пересборка
//1. gulp.series - обязательно
//2. gulp не завершает выполнение, т.к. стоит gulp.watch
gulp.watch('styles/**/*.*', gulp.series('styles'));