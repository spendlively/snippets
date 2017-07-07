
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



//Сборка разных файлов
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
