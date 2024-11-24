// var myObj = {};

// Object.assign(myObj,{a:1,b:2,c:3},{d:4,e:5,f:6});
// console.log(myObj)

// function sumOne(a,b) {
//     return a+b;
// }
// var myA = [5,4]
// console.log(sumOne(...myA))


function nums(...num){
    //this rest operator wil collect all the values in nums and bunch them in to in an array
    console.log(num);
}
nums(3,2,3,4,5); // [3,2,3,4,5]

function sumTwo(...args){
    console.log(args);
    let sum = 0;
    for (const arg of args) {
        sum+=arg;
    }
    return sum ; 
}
console.log(sumTwo(2,3,2,1,4))