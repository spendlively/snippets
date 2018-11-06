//https://github.com/github/fetch
//https://learn.javascript.ru/fetch

(() => {


    //html
    fetch('/data.html')
        .then(function(response) {
            return response.text()
        }).then(function(body) {
        document.body.innerHTML = body
    });



    //json
    fetch('/data.json')
        .then(function(response) {
            return response.json()
        }).then(function(json) {
        console.log('parsed json', json)
    }).catch(function(ex) {
        console.log('parsing failed', ex)
    });



    //response meta-data
    fetch('/data.json').then(function(response) {
        console.log(response.headers.get('Content-Type'));
        console.log(response.headers.get('Date'));
        console.log(response.status);
        console.log(response.statusText);
    });



    //post
    // var form = document.querySelector('form');
    // fetch('/users', {
    //     method: 'POST',
    //     body: new FormData(form)
    // })



    //post json
    fetch('/users.php', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({
            name: 'Hubot',
            login: 'hubot',
        })
    })



    //File upload
    // var input = document.querySelector('input[type="file"]')
    //
    // var data = new FormData()
    // data.append('file', input.files[0])
    // data.append('user', 'hubot')
    //
    // fetch('/avatars', {
    //     method: 'POST',
    //     body: data
    // })

})();
