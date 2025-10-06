/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let newarr=[]
    arr.forEach((value,index)=>{
        newarr.push(fn(value,index));
    })
    return newarr
};