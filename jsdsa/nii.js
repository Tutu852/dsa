// let count = 0;
// const nums = [0,1,2,3];
// nums.forEach(num => {
//     if (num ) {
//         count = count +1;
        
//     }
// })

// console.log(count);

// // Breakdown:
// // nums array: [0, 1, 2, 3]
// // forEach loop: Iterates over each element in the nums array.
// // Condition if (num): Checks if each element is truthy.
// // Truthy vs Falsy in JavaScript:
// // In JavaScript, values are either truthy or falsy:

// // Falsy values: false, 0, "" (empty string), null, undefined, and NaN.
// // Truthy values: All other values, including positive and negative numbers, non-empty strings, objects, and arrays.
// // Iteration Steps:
// // First iteration (num = 0):
// // if (0) is evaluated. Since 0 is falsy, the condition is not met, and count remains 0.
// // Second iteration (num = 1):
// // if (1) is evaluated. 1 is truthy, so count is incremented to 1.
// // Third iteration (num = 2):
// // if (2) is evaluated. 2 is truthy, so count is incremented to 2.
// // Fourth iteration (num = 3):
// // if (3) is evaluated. 3 is truthy, so count is incremented to 3.
// // Why not 6?
// // Only three numbers (1, 2, and 3) are truthy. The number 0 is falsy, so it doesn't contribute to the count.
// // Hence, the final value of count is 3.


// let colors = ["red", "blue", "green", "yellow"];
// let removed = colors.splice(1, 2); // Remove 2 elements starting from index 1
// console.log(colors); // Output: ["red", "yellow"]
// console.log(removed); // Output: ["blue", "green"]

// let colors = ["red", "yellow"];
// colors.splice(1, 0, "blue", "green"); // Add elements at index 1, remove 0 elements
// console.log(colors); // Output: ["red", "blue", "green", "yellow"]


// let numbers = [10, 20, 30, 40];
// numbers.splice(2, 1, 25); // Replace 1 element at index 2
// console.log(numbers); // Output: [10, 20, 25, 40]

// console.log(!"hello"); //false

// console.log(+false); //0


// console.log("" == false);
// console.log("" === false);

// console.log(NaN == NaN);
// console.log(NaN === NaN);

// // example of above 
// console.log(1 + undefined);


// console.log(typeof typeof 1000); //string because when i did typeof1000 there i get this "number" then type of "number" is string ;

// const arr= [3,4,5,6];
// arr[10] = 100;
// console.log(arr.length); // Output: 11
// console.log(arr); // Output: [ 3, 4, 5, 6, <6 empty items>, 100 ]

// function myFun(){
    
//      xyz =100;
//     console.log(xyz);//100
        // return 4;
// }
// console.log(myFun()); //4 if i not return any thing it will give//undefined 

// here xyz automatically take this as var so the ans should be 100 and undefined

// function myFun(xyz) {
//     console.log(xyz); // Print the parameter value
//     return 4;         // Return 4 after printing
// }

// console.log(myFun(100)); // Pass 100 as an argument

// var xyz = 1 + abc 
//  abc =100;//withut any variable i ll get error abc is not defined 
//  //with var abc = 100 ;i will get  NaN
// console.log(xyz);


const data ={
    name:"john",
}

const abc = [1,2,3,4];
console.log(delete data);
console.log(delete abc);
 console.log(delete 1); // Output: true