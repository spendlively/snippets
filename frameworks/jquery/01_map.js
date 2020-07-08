
$(":checkbox")
    .map(function() {
        return this.id;
    })
    .get() //[1,2,3]
    .join(); //1,2,3