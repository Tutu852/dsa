// // The following variables are defined in the global scope
// const num1 = 20;
// const num2 = 3;
// const name = "Chamakh";

// // This function is defined in the global scope
// function multiply() {
//   return num1 * num2;
// }

// console.log(multiply()); // 60

// // A nested function example
// function getScore() {
//   const num1 = 2;
//   const num2 = 3;

//   function add() {
//     return `${name} scored ${num1 + num2}`;
//   }

//   return add();
// }

// console.log(getScore()); // "Chamakh scored 5"

// for(let i=0;i<5;i++){
//     setTimeout(function(){
//         console.log(i);
//     },i * 1000);
// }


// function a(){
//     for(var i=0;i<3;i++){
//        ( function(i){
//             setTimeout(function log(){
//                 console.log(i);
//             },i * 1000);
//         })(i);
        
//     }
// }
// a();

//     for(var i=0;i<3;i++){
//        function inner(i){
//             setTimeout(function log(){
//                 console.log(i);
//             },i * 1000);
//         }   
//         inner(i);
//     }


// Q what is function Expression


// const squre = function(num){
//     return num * num;
// }
// console.log(squre(5));

// what is 1st class function 
// function squre(num){
//     return num * num;
// }

// function displaySqure(fn){
//     console.log("square is "+ fn(5));
// }
// displaySqure(squre);


// Q IIFE -O/P Based Question 

// (function(x){
//     return (function(y){
//         const startTime = performance.now();
//         console.log(x); //1
//         const endTime = performance.now();
//         console.log(`Execution time: ${endTime - startTime} milliseconds`)
//     })(2);
// })(1);

// (function square(num){
//     console.log(num * num);
// })(5);


// Q Function Hoisting 

// functionName();
// console.log(x);


// function functionName(){
//     console.log("roadside coder");
// }

// var x =5;

// Q1 function hoisting 

// var x= 21;
// var fun = function(){
//     console.log(x); //undefined
//     var x= 20;
// }
// fun();


// Q:- Params vs Arguments   

// function square(num){ //params
//     console.log(num  * num);
// }
// square(5); //argumnents


// Q:-rest and spread operator

// function multiply(...nums){ // this is rest operator
//     console.log(nums[0] * nums[1]);
// }
// var arr = [5,6];

// multiply(...arr); //this is spread operator


// o/p based Question 

// const fn=(a,x,y,...numbers)=>{
//     console.log(a,y, numbers);
// }

// fn(1,2,3,4,5,6,7,8,9,);



// async function foo(){
//     return "hello world";
// }

// const result = foo();
// console.log(result); //promiese {"hello world"} //async always return promise

//if interviwer ask please reject this promise then

// async function foo(){
//     return "hello world";
    //these two way we can reject this promise

    // return  new Promise.reject("hello world");
    // throw new Error("hello world"); 

    //if i need to delay 
    // return new Promise(()=>{})
       
// }
//     // i need hello world in this result varable  
// (async function(){
//     const result = await foo();
//     console.log(result);
// })();

// Q.

// foo();

// var foo = 20;

// function foo(){
//     console.log("calling foo");
// }
// foo();


// Q:-
// async function foo(){
//     return "Hello world";
// }

// async function main() {
//     const result =await foo();
// console.log(result);
// }

// main(); //hello world

// function abc(){
//     console.log("hii");
// }
// const value = new abc();
// console.log(value); // abc {}


let count = 0;

(function printCount(){
    if(count === 0){
        let count = 1;
        console.log(count);//1
    }
    console.log(count);//0 because this shadowing will work on that block scope so on  1st console.log(1) as answer only for that second count it is now a fucntion scope so it will take count =0
})()