
//Поиск плагинов для gulpjs
http://gulpjs.com/plugins/



//Установка
//gulp нужно ставить и локально и глобально
//чтобы подключать через require
//и для доступа к команде gulp
sudo npm install gulp-cli -g
npm install gulp -D
touch gulpfile.js
gulp --help



//Использование локального gulp
export PATH=./node_modules/.bin:$PATH
export PATH=../node_modules/.bin:$PATH
export PATH=../../node_modules/.bin:$PATH
gulp



//Просмотр существующих задач
//gulp --tasks



//Завершение работы
//gulp.task должен вернуть
// - callback
// - Промис
// - Поток

