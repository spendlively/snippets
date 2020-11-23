(function () {
    let data = {
        email: 'qwerty@mail.ru',
        password: 'asdfgh'
    };

    // 0. Отправка через форму
    // Form Data
    // email: qwerty@mail.ru
    // password: asdfgh
    //
    // Request Content-Type: application/x-www-form-urlencoded
    // Response Content-type: text/html; charset=UTF-8
    //
    // php: print_r($_POST);
    // [
    //   [email] => qwerty@mail.ru
    //   [password] => asdfgh
    // ]


    /////////////////////////////////////////////////////////////
    /////////////////////////jQuery AJAX/////////////////////////
    /////////////////////////////////////////////////////////////

    //contentType по умолчанию = application/x-www-form-urlencoded
    //contentType доступные значения:

    //application/x-www-form-urlencoded
    // - Вместо пробелов ставится +
    // - символы вроде русских букв кодируются их шестнадцатеричными значениями
    // - (например, %D0%90%D0%BD%D1%8F вместо Аня)

    //multipart/form-data
    // - Данные не кодируются
    // - Это значение применяется при отправке файлов

    //text/plain
    // - Пробелы заменяются знаком +
    // - буквы и другие символы не кодируются


    // 1. Отправка ajax get
    $('.btn.get').click(function (e) {
        $.ajax({
            url: 'index.php',
            method: 'get',
            data: data,
            success: function (response) {
                console.log(response);
            }
        });
    });
    // Query String Parameters
    // email: qwerty@mail.ru
    // password: pass
    //
    // Request Content-Type: отсутствует так как нет тела то есть контента
    // Response Content-type: text/html; charset=UTF-8
    //
    // php: print_r($_GET);
    // [
    //   [email] => qwerty@mail.ru
    //   [password] => asdfgh
    // ]


    // 2. Отправка ajax post
    $('.btn.post').click(function (e) {
        $.ajax({
            url: 'index.php',
            method: 'post',
            data: data,
            success: function (response) {
                console.log(response);
            }
        });
    });
    // Form Data
    // email: qwerty@mail.ru
    // password: pass
    //
    // Request Content-Type: application/x-www-form-urlencoded; charset=UTF-8
    // Response Content-type: text/html; charset=UTF-8
    //
    // php: print_r($_POST);
    // [
    //   [email] => qwerty@mail.ru
    //   [password] => asdfgh
    // ]


    // 3. Отправка ajax json
    $('.btn.json').click(function (e) {
        $.ajax({
            url: 'index.php',
            method: 'post',
            data: JSON.stringify(data),
            dataType: 'json',
            contentType: 'application/json; charset=utf-8',
            success: function (response) {
                console.log(response);
            }
        });
    });
    // Request Payload
    // {email: "qwerty@mail.ru", password: "asdfgh"}
    //
    // Request Content-Type: application/json; charset=UTF-8
    // Response Content-type: text/html; charset=UTF-8
    //
    // php: print_r(json_decode(file_get_contents('php://input'), true));
    // [
    //   [email] => qwerty@mail.ru
    //   [password] => asdfgh
    // ]


    // 4. Отправка ajax FormData
    $('.btn.form').click(function (e) {
        let formData = new FormData();
        formData.append('email', 'qwerty@mail.ru');
        formData.append('password', 'asdfgh');

        $.ajax({
            url: 'index.php',
            method: 'POST',
            data: formData,
            processData: false,
            contentType: false,
            success: function (response) {
                console.log(response);
            }
        });
    });
    // Form Data
    // email: qwerty@mail.ru
    // password: pass
    //
    // Если contentType: false
    // Request Content-Type: multipart/form-data; boundary=----WebKitFormBoundaryPZsHwHKx8Yky3BjV
    // Response Content-type: text/html; charset=UTF-8
    //
    // php: print_r($_POST);
    // [
    //   [email] => qwerty@mail.ru
    //   [password] => asdfgh
    // ]
    //
    // Если не указать contentType: false
    // Content-Type будет application/x-www-form-urlencoded;
    // и внутри $_POST будет:
    //     [------WebKitFormBoundaryK4qxQkgEShoTePwU
    // Content-Disposition:_form-data;_name] => "email"
    //
    // qwerty@mail.ru
    // ------WebKitFormBoundaryK4qxQkgEShoTePwU
    // Content-Disposition: form-data; name="password"
    //
    // asdfgh
    // ------WebKitFormBoundaryK4qxQkgEShoTePwU--
})()
