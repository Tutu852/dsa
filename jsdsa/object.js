// const user = {
//     name:"Roadside Coder",
//     age:24,
//     isToatllyAwesome:true,
// };
// //for access the value
// // for(key in user){
// //     console.log(user[key])
// // }
// //this is for the key
// // for(key in user){
// //     console.log(key)
// // }

// for(let x of Object.keys(user)){
//     console.log(x,user[x])
// }



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
// //    multiplies all numeric property valure of nums by 2

// let nums = {
//   a:100,
//   b:200,
//   tutle:"My nums",
// };
// multiplyByTwo(nums);
// function multiplyByTwo(x){
//     for(let key in x){
//         if(typeof x[key] === "number"){
//             x[key] *=2 ;
            
//         }
//     }
// }

// console.log(nums);

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
// //this b object  is not converted to  key unless this is a string;
// const c = {key:"c"};


// a[b] = 123; //so this will give a["[object oject]"] = 123;
// a[c] = 456;//so this will also give a["[object oject]"] = 123;

// //1st this will assign as 123 then this will assign 456 that's why the ans is 456

// console.log(a[b]); //ans is 456

//if i need to a[b] is 123 we should use Map

// const a = new Map();
// const b = {key : "b"};
// const c = {key : "c"};

// a.set(b,123);
// a.set(c,456);

// console.log(a.get(b));
// console.log(a.get(c));


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

// let user= {
//     name: "rajesh",
//     age:26
// }
// const {name} = user;
// console.log(name); //rajesh


// Question in javascript

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

// //here one think to notice for the nested destructuring  i use fullName :{first} the {};for the  above name change of use i just did const {name:myName} = user; 
// const{fullName :{first}}=user;
// console.log(first);


// Q 

// const user1 = {
//     name: "Piyush",
//     age: 25,
//     address: {
//         street: "street1",
//         city: "city1",
//         }
// }

// const user2 = user1;

//this will change only  the value of 
// const user2 = JSON.parse(JSON.stringify(user1));

// user2.name = "Ramesh";
// user2.address.city = "pune";
// console.log(user1);
// console.log(user2);

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

// Destructuring 
// let Details ={
//     name: "Ramesh",
//     age: 25,
// }
//to access this name i will get this using notation bracket
// Details[name];

// let {name ,age} = Details;
//using spread operator

// let {name ,...data} = Details;

//change the name in to userName

// let {name:userName ,...data} = Details
// console.log(name); //ramesh
// console.log(age); //25
//spread operator

// console.log(data); //{age:25};

//after chnageing the name
// console.log(userName); //Ramesh
// console.log(data); //{age: 25}


//object refrencing
//these both are false because these are different object so it refrence to the different object so it never same
// console.log({a:1}== {a:2});
// console.log({b:5} === {b:3});


// output base question 

const value = {number:10};

const multiplies = (x={...value})=>{
    console.log((x.number *= 2));
}
//this multiplies never change the original value of this because it will clone the value above multiplies function
multiplies();//20
multiplies();//20
//but here it direactly pointed to the value of the about number:10 so it will change the original value
multiplies(value); //20
multiplies(value); //40

