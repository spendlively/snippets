
//Create form dynamically, add params and submit
$('#pm-params-form').submit(function (event) {

    event.preventDefault();

    let ids = [1,2,3],
        action = '/action.php',
        form = $(`<form action="${action}" method="POST"></form>`).appendTo('body');

    ids.forEach(function (id) {
        let input = $('<input>')
            .attr('type', 'hidden')
            .attr('name', 'photos[]').val(id);
        form.append(input);
    });

    form.submit();
});