
function isTargetVisible(el){
    var rect = el.getBoundingClientRect();
    if(
        rect &&
        rect.top >= 0 &&
        rect.left >= 0 &&
        rect.bottom <= (window.innerHeight || document.documentElement.clientHeight) &&
        rect.right <= (window.innerWidth || document.documentElement.clientWidth)
    ){
        return false;
    }
    return true;
}
