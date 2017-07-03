//Загрузка модуля для работы с файлами
var fs = require('fs');



//Синхронное чтение файла
var cont = fs.readFileSync('file.txt');
console.log(decodeURIComponent(cont));



//Асинхронное чтение файла
fs.readFile('file.txt', function(err, cont){
    console.log(decodeURIComponent(cont));
});



//Удаление
fs.unlink('/tmp/hello', (err) => {
    if (err) throw err;
console.log('successfully deleted /tmp/hello');
});
fs.unlinkSync('/tmp/hello');



//Переименовывание
fs.rename('/tmp/hello', '/tmp/world', (err) => {
    if (err) throw err;
console.log('renamed complete');
});



//Вывод файла
fs.readFile('/');



//Проверки
fs.isFile('tmp/test');
fs.stat('tmp/test');
fs.access('/etc/passwd', fs.R_OK | fs.W_OK, (err) => {
    console.log(err ? 'no access!' : 'can read/write');
});
fs.accessSync(path, mode);
fs.exists(path, callback);
fs.existsSync(path);



//Добавление данных в файл
fs.appendFile('message.txt', 'data to append', 'utf8', callback);
fs.appendFileSync(file, data[, options])



//Права и владельцы
fs.chmod(path, mode, callback)#
fs.chmodSync(path, mode)#
fs.chown(path, uid, gid, callback)#
fs.chownSync(path, uid, gid)



//Открытие/закрытие
fs.open(path, flags[, mode], callback)
fs.openSync(path, flags[, mode])#
//r, r+, rs, rs+, w, wx, w+, wx+, a, ax, a+, ax+
fs.close(fd, callback)



//Чтение
fs.read(fd, buffer, offset, length, position, callback)
fs.readFile(file[, options], callback)
fs.readFile('/etc/passwd', (err, data) => {
    if (err) throw err;
console.log(data);
});
fs.readFile('/etc/passwd', 'utf8', callback);
fs.readFileSync(file[, options])



//Запись
fs.write(fd, data[, position[, encoding]], callback)
fs.writeFile(file, data[, options], callback)
fs.writeFile('message.txt', 'Hello Node.js', (err) => {
    if (err) throw err;
console.log('It\'s saved!');
});
fs.writeFile('message.txt', 'Hello Node.js', 'utf8', callback);
fs.writeFileSync(file, data[, options])#
fs.writeSync(fd, buffer, offset, length[, position])



//Каталоги
fs.readdir(path, callback)
fs.readdirSync(path)
fs.realpath(path[, cache], callback)
fs.realpath('/etc/passwd', {'/etc':'/private/etc'}, (err, resolvedPath) => {
    if (err) throw err;
console.log(resolvedPath);
});
fs.rmdir(path, callback)#
fs.rmdirSync(path)



//Следить за файлом
fs.watch(filename[, options][, listener])
fs.watch('somedir', (event, filename) => {
    console.log(`event is: ${event}`);
if (filename) {
    console.log(`filename provided: ${filename}`);
} else {
    console.log('filename not provided');
}
});
fs.watchFile(filename[, options], listener)
fs.watchFile('message.text', (curr, prev) => {
    console.log(`the current mtime is: ${curr.mtime}`);
console.log(`the previous mtime was: ${prev.mtime}`);
});
