
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
