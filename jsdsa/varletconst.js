// console.log(count)
// let count= 1;
// var count2 =2;
// // const count3 = 3;


//scope

// var a = 5;

// console.log(a);

// //blcok scope

// {
//     const b =5;
//     console.log(b);
// }

//function scope

// function test() {
//     let c = 5;
//     if(true){
//         let d = "hi";
//         console.log(d);
//     }
//     console.log(c);

// }
// test();//hii //hello


 //illegal shadowing

// function test() {
//     // let c = 5;  
//     var e = 5;
//     if(true){
//         let d = "hi";
//         var c ="good bye"; //this will give error because it present in  out side of this scope as let but when pass throw var then it accessible in this scope
//         let e = 6;
//         console.log(d);
//         console.log(e);
//     }
//     console.log(c);

// }
// test();



//Hoisting
console.log(count);//ans is undefined because when we do this it already present in creation phase there it is undefined
var count = 1;
// Q1

// function abc(){
//     console.log(a);

//     var a = 10;
// }
// abc();

// function bcd(){
//     console.log(a,b,c);

//     const c = 30;
//     let b = 20;
//     var a= 10;
// }
// bcd();
