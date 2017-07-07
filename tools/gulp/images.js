
//Сжатие всех изображение на 30-40%
//npm install gulp-imagemin
const gulp = require('gulp');
const imagemin = require('gulp-imagemin');

gulp.task('default', function() {
    gulp.src('images/*')
        .pipe(imagemin())
        .pipe(gulp.dest('dist/images'))
});



//Изменение размеров изображений
//npm install gulp-image-resize
//npm install gulp-img-retina



//Генерация изображениев для различных устройств
//npm install gulp-responsive



//Преобразование картинок в data uri
//npm install gulp-imacss
