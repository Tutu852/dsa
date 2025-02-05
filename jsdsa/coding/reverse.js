var str = "my name is rajesh kumar behera"
// var savestr  = str.split(" ").map(function(word){
//    return  word.split("").reverse().join("")
// })
// console.log(savestr.join(" "))

const reverseString =(str)=>{
    const arr = str.split('');
    let start = 0;
    let end = str.length -1;

    while(start <= end){
        [arr[start],arr[end]] = [arr[end],arr[start]];
        start++;
        end--;
    }
    return arr.join('');

}

console.log(reverseString(str));



// when we split it will converted in to an array then we 
// took map to get every element in a function(word)
//  then every word of our string store on the function(word)
//  separately then we spilt that word and reverse that and join 
//  that it will reverse that one word "my"


// const st = "kuchh bhi bolo";
// var data = st.split(" ").map(function(word){
//     return word.split("").reverse().join("")
// })

// console.log(data.join(" "));

// const string = "rajesh is a bad boy";
// var pra =string.split(" ").map(function(data){
//     return data.split("").reverse().join("")
// })

// console.log(pra.join(" "));

// const real  = "no current is there";

// var current = real.split(" ").map(function(funy){
//     return funy.split("").reverse().join("")
// })

// console.log(current.join(" "));


// function reverseString(str){
//    return str.split('').reverse().join('');
// }
// console.log(reverseString("my name is rajesh kumar behera"));

 
