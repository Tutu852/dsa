// currying is a function that take one argument at a time and return a new function accepting the next argument


// function f(a){
//     //this is a anonnimos function because it doesnot have name on it
//     return function (b){
//         console.log(a,b);
//     }
// }


// console.log(f(5)(6));

function f(a){
    return function (b){
        return `${a} ${b}`;
    }
}

console.log(f(5)(6))

//solve this using curring sum(2)(6)(1);
//this is using normal function

// function sum(a,b,c){
//     return a+b+c;
// }
// console.log(sum(2,6,1));


//using currying
// function sum(a){
//     return function(b){
//         return function(c){
//             return a + b + c;
//         }
//     }
// }

// console.log(sum(2)(6)(1));


// Question 2-
// evaluate("sum")(4)(2) =>6
// evaluate("multiply")(4)(2) =>8
// evaluate("divide")(4)(2) =2
// evaluate("substract")(4)(2) =>2


// function evaluate (operation){
//     return function(a){
//         return  function(b){
//             if(operation === "sum") return a+b;
//             else if(operation === "multiply") return a*b;
//             else if(operation === "divide") return a/b;
//             else if(operation === "substract") return a-b;
//             else return " invalid  operation";
//         }
//     }
// }

// const sumAny=evaluate("sum");

// console.log(sumAny(4)(3))
// console.log(sumAny(5)(3))

// Question 3 - Infinite currying ->sumAny(1)(2)(3) ----(n);

// function add(a){
//     return function(b){
//         if(b) return add(a+b);
//         return a
//     }
// }
// this is wok like this 
// for 1st case a=5 and b=2 then it's sum is 7;
//then it will return 7 as a and then it will check if b is empty then  in that place it will take 4 and the sum of that return to a again 
//on 3rd case 11 + 8 =19
//on 4th case a =19 b is empty so it will written 19
// console.log(add(5)(2)(4)(8)());


//Question 4 - Currying vs Partial Application

// function sum(a){
//     return function (b,c){
//         return a+b+c;
//     }
// }
// const x = sum(10);
// console.log(x(5,6));
// console.log(x(3,6));


// // or 
// console.log(sum(20)(1,3));

//Question -5 where we can use currying
 // Manipulation DOM

//  function updateElementText(id){
//     return function (content){
//         document.querySelector("#" + id).textContent = content;
//     }
//  }
//  const updateHeader = updateElementText("heading");

//  updateHeader("love")

//Question 6 - curry() implementation
// Converts false(a,b,c) into false(a)(b)(c)

// function curry(fun){
//     //arg here is array of all argument
//     return function curriedFun (...args){
//         if(fun.length >= args.length){
//             return fun(...args);
//         }else{
//             return function(...next){
//                 return curriedFun(...args,...next);
//             }
//         }
//     }
// }

// const sum =(a,b,c) => a+b+c;

// const totalSum = curry(sum);
// console.log(totalSum(1)(2)(3));
