// how to check if an object is an array or not

function checkArray(element){
    return Array.isArray(element)
}
console.log(checkArray([]));
console.log(checkArray({}));

function check(data){
    return Array.isArray(data)
}

console.log(check([]))
console.log(check({}))




function check(data){
    return Array.isArray(data);
}
console.log(check([]))
console.log(check({}))