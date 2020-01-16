function showModal(message = '', callback = function(){}) {

    let modal = $('#message-modal');

    modal.find('.modal-title').html(message);
    modal.find('.ok-btn').unbind().on('click', function (e) {
        callback();
    });

    modal.modal('show');
}
