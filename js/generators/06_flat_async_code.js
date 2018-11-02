
(() => {

    console.log("06 =============================================================");

    /**
     * Плоский асинхронный код
     */
    // генератор для получения и показа аватара
    // он yield'ит промисы
    function* showUserAvatar() {

        let userFetch = yield fetch('user.json');
        let userInfo = yield userFetch.json();

        let githubFetch = yield fetch(`https://api.github.com/users/${userInfo.name}`);
        let githubUserInfo = yield githubFetch.json();

        let img = new Image();
        img.src = githubUserInfo.avatar_url;
        img.className = "promise-avatar-example";
        document.body.appendChild(img);

        yield new Promise(resolve => setTimeout(resolve, 3000));

        img.remove();

        return img.src;
    }

    // вспомогательная функция-чернорабочий
    // для выполнения промисов из generator
    function execute(generator, yieldValue) {

        let next = generator.next(yieldValue);

        if (!next.done) {
            next.value.then(
                result => execute(generator, result),
                err => generator.throw(err)
            );
        } else {
            // обработаем результат return из генератора
            // обычно здесь вызов callback или что-то в этом духе
            alert(next.value);
        }

    }

    execute( showUserAvatar() );

})();

