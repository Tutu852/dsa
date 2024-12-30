 
// const user ={
//     name : "rajesh",
//     age : 24
// }

// user.name = "gelli"
// delete user.age;

// console.log(user);


// const func = (function(a){
//     //delete keyword is only work on object not in function or in local variable 
//   delete a;
//   return a;
// })(5)

// console.log(func); //ans:-5

// // Question:-1 what's the Output

// const obj={
//   a:"one",
//   b:"two",
// //   a:"three",
// };

// console.log(obj); //ans is b:"two" and a:"three"


// // Question :-2 create a function multipyBytwo(obj) that
//             //    multiplies all numeric property valure of nums by 2
// let nums = {
//   a:100,
//   b:200,
//   tutle:"My nums",
// };
// multiplyByTwo(nums);

// function multiplyByTwo(obj){
//   //for accessing the key and vlaue 
//   for( key in obj){
//     if(typeof obj[key] === "number"){
//       obj[key]*=2;
//     }
//   }
// }

// console.log(nums);



// Question :-3 what's the Output of the following code?

// const a={};
// const b = {key:"b"};
// //this b object  is not converted key unless this is a string;
// const c = {key:"c"};


// a[b] = 123; //so this will give a["[object oject]"] = 123;
// a[c] = 456;//so this will also give a["[object oject]"] = 123;

// //1st this will assign as 123 then this will assign 456 that's why the ans is 456

// console.log(a[b]); //ans is 456


// Question what is JSON.stringify and JSON.parse
// this will use this in storing data in localstorage
// const user={
//   name:"Piyush",
//   age:24,
// }

// const strObj= JSON.stringify(user);
// // when we try to do object to string forcefully then it will give [object object] 
// // localStorage.setItem("data" ,user)
// localStorage.setItem("data" ,strObj)
// console.log(JSON.parse(localStorage.getItem("data")))
// // console.group(JSON.parse(strObj))


// Question:- what's the Output


// const settings ={
//   userName:"Piyush",
//   level:19,
//   health:90,

// };

// const data = JSON.stringify(settings,["level","health"] );
// console.log(data) //output is ["level":19 "health" :90]

// Question :- what's the output

// const shape = {
//   radius: 10,
//   diameter() {
//     return this.radius * 2;
//   },
//   perimeter:() =>{
//     return 2 * Math.PI * this.radius;
//   },
//   perimeter1() {
//     return 2 * Math.PI * this.radius;
//   },
// };

// console.log(shape.diameter());   // 20
// console.log(shape.perimeter()); //NAN 
//  console.log(shape.perimeter1());//62.83185307179586 (approximately)


// Question : what is the output

// function getItem(fruitList,favoriteFruit, ...args){
//   return [...fruitList,...args ,favoriteFruit];
// }

// console.log(getItem(["bananna","apple"] , "pear" , "orange"));


// Question in  javascript
// what is destructuring in obj

// let user={
//   name:"Piyush",
//   age:25,
//   fullName:{
//     first:"rajesh",
//     last:"Behera",
//   }
// }

// const name = "rajesh";

// // const {name:myname}  = user;

// const{
//   fullName :{first},
// }=user;
// console.log(first);


// Q 

const user1 = {
    name: "Piyush",
    age: 25,
    address: {
        street: "street1",
        city: "city1",
        }
}

const user2 = user1;

user2.name = "Ramesh";
user2.address.city = "pune";
console.log(user1);
console.log(user2);

// In JavaScript, when you assign an object to another variable, such as const user2 = user1;, both variables (user1 and user2) point to the same memory reference. They do not create separate copies of the object. thats why the ans is
// {
//     name: 'Ramesh',
//     age: 25,
//     address: { street: 'street1', city: 'pune' }
//   }
//   {
//     name: 'Ramesh',
//     age: 25,
//     address: { street: 'street1', city: 'pune' }
//   }