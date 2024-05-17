/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    let n=0, m=0;

    await promise1.then((result1) => {
        n = result1;
    })

    await promise2.then((result1) => {
        m = result1;
    })

    return new Promise(resolve => {
        resolve(n+m);
    })
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */