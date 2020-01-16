(function () {
    $('.pm-delete').click(function (e) {
        e.preventDefault();
        let btn = $(this);
        showModal('Do you really want to delete this user?', function () {
            window.location.href = btn.attr('href');
        });
    });
})();
