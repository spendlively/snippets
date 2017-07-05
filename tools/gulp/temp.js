
//Просмотр существующих задач
//gulp --tasks



//Завершение работы
//gulp.task должен вернуть
// - callback
// - Промис
// - Поток




//Поиск всех файлов по заданному пути
//Возвразает readable поток (объекты vinyl)
gulp.src('/source/*.*');
gulp.src('/source/**/*.js');
gulp.src('/source/**/*.{js,css}');
gulp.src('/{source1,source2}/**/*.*');
gulp.src(['/js/*.js', '/css/*.css']);
gulp.src(['**/*.*', '!node_modules/**']);
gulp.src('**/*.*', {read: false}); //не читать файлы в память (в contents будет null)



//Части пути 'public/source/**/*.*'
//base: public/source/
//relative: **/*.*
//в gulp.dest('path') файлы будут сохраняться в path + relative



//Возвращает writable поток
gulp.dest('/path/to/saving');
gulp.dest(function(){
    return '/path/to/saving';
});



//Свойства объекта Vinyl
//contents
//cwd
//path
//base



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



//Условия if
const gulpif = require('gulp-if');
const doConcat = true;
gulp.task('styles', function(){
    return gulp.src('styles/**/*.styl')
        .pipe(gulpif(doConcat, stylus()))
        .pipe(concat('all.css'))
        .pipe(gulp.dest('public'));
});



//Более сложный пример
const gulpif = require('gulp-if');
gulp.task('styles', function(){
    return gulp.src('styles/**/*.styl')
        .pipe(gulpif(function(file){
            return file.extname === '.js';
        }, stylus()))
        .pipe(concat('all.css'))
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