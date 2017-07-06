
//Анимация прозрачности до 0.30 и margin-left до 150px
$(function () {
    $("div").animate(
        {
            opacity: 0.30,
            marginLeft: '150px'
        }, 1000);
});



//Несколько анимаций последовательно
$("div")
    .animate(
        {
            opacity: 0.25,
            marginLeft: '550px'
        }, 5000)
    .animate(
        {
            opacity: 1.0,
            marginLeft: '0px'
        }, 5000);




//Продолжительность анимации в миллисекундах, 'fast' или 'slow' (200 и 600)
$("div").animate(
    {
        opacity: 0.25,
        marginLeft: '550px'
    },
    "slow");



//Несколько анимаций параллельно
$(function () {

    var anim = {
        marginLeft: '150px',
        marginTop: '150px',
    };

    var options = {
        queue: false,
        duration: 5000
    };

    $("div")
        .animate(anim, options)
        .animate(
            {
                width: '50px',
                height: '50px'
            }, 5000);
});

