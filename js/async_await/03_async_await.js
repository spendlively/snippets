(() => {

    console.log("03 ===================================================");

    function getPromise(){
        return new Promise((resolve, reject) => {
            setTimeout(() => {
                resolve(111);
            }, 1000);
        });
    }

    async function getData(){
        return await getPromise();
    }

    getData().then((data) => {
        console.log(data);
    });



    // let getPromise2 = () => {
    //     return new Promise((resolve, reject) => {
    //         setTimeout(() => {
    //             resolve(222);
    //         }, 1000);
    //     });
    // };
    //
    // let getData2 = async () => {
    //     return await getPromise2();
    // };
    //
    // getData2().then((data) => {
    //     console.log(data);
    // });
})();