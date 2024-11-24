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



