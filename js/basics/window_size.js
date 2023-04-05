
function getWindowSize(){
    var e = document.documentElement,
        g = document.getElementsByTagName('body')[0],
        x = window.innerWidth || e.clientWidth || g.clientWidth,
        y = window.innerHeight|| e.clientHeight|| g.clientHeight;

    return [x, y];
}
