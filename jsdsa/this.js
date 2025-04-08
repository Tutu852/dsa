// // Question

//  this.a =5;
//  function getParam(){
//     console.log(this.a);
//  }
//  getParam();//5


//  this.a =5;
//  const getParam1=()=>{
//     console.log(this.a);
//  }

//  getParam1();//5

//  let user ={
//     name:"Rajesh",
//     age:24,
//     getDetails(){
//         console.log(this.name )
//     }
//  }

//  user.getDetails();//rajesh




//  let user1 ={
//     name:"Rajesh",
//     age:24,
//     childObj:{
//         newName : "gelli",
//         getDetails1(){
//             console.log(this.newName ,"and" ,this.name );
//         }
//     }
//  }

//  user1.childObj.getDetails1(); //gelli and undefined

//fix this using bind

// const bindfix = user1.childObj.getDetails1.bind({
//   name : user1.name,
//   newName : user1.childObj.newName,
// })
// console.log(bindfix());

//arrow function will refere to window if it is nested function then it refer to the its parent function 

// let user = {
//    name:"Rajesh",
//    age:24,
//    getDetails(){
//       const nestedArrow = () =>console.log(this.name);
//       nestedArrow();
// }

// }
// user.getDetails();//rajesh

// let user ={
//     name:"rajesh",
//     age:24,
//     getDetails:()=>{
//         console.log(this.name);
//     }
// }
// user.getDetails();//this will give undefined because it is a  arrowfuncion is will pointed to the imediate parent function so it will give nothing 


//  class user{
//     constructor(n){
//       this.name = n;
//     }
//     getName(){
//       console.log(this.name);
//     }
//     setName(newName){
//         this.name =newName
//     }
//  }
//  //this new keyword create a new object
//  const User = new user("Rajesh");
//  User.getName();//rajesh

//  User.setName("gelli");
//  User.getName();


// Question

//  const user={
//  firstName :"Rajesh !",
//     getName(){
//       const firstName = "Rajesh behera";
//       return this.firstName;
//     //   return firstName;
//     }
//  }
//  console.log(user.getName());//Rajesh !

// Question

//  function makeUser(){
//    return {
//       name : "rajesh",
//       ref :this,
//    }
//  }
//  let user = makeUser();//we will not going to get any ans because  this ref is pointing to window object so in widow object is not pointing to any name
//  console.log(user.ref.name)

//  //fix this problem

//  function makeuser(){
//    return {
//       name:"rojalin",
//       ref(){
//          return this.name;
//       }
//    }
//  }
//  let user1 = makeuser();

//  console.log(user1.ref().name);



//Question

// const user ={
//    name :"Rajesh kumar",
//    logMessage(){
//       console.log(this.name);
//    }
// }
// setTimeout(user.logMessage,1000);//this code will give nothing of undefined because settimeout take as callback function this is indicate to window object



//fix this

// const user1 = {
//    name:"rajesh kumar",
//    logMessage(){
//       console.log(this.name);
//    }
// }
// //we convert this callback function to invoked function
// setTimeout(function(){
//    user.logMessage();
// },1000);
 

// Question

// const user ={
//    name : "rajesh",
//    greet(){
//       return `hello,${this.name}`
//    },
//    farewall: ()=>{
//       return `goodbye ,${this.name}`
//    }
// }


// console.log(user.greet())

//ans is hello rajesh becz this normal function is pointed to the user object 
// console.log(user.farewall());
//this will  give  goodbye undefined  ans because this a arrow function this will not indicate to user object this will pointed to the window object so.

// Question

// var length = 4;
// function callback(){
//     console.log(this.length);
// }
// // Calling object.method(callback): When object.method(callback) is executed, fn is assigned the callback function. Inside method, fn() is called. However, fn (which is callback) is called in the global context, not as a method of object. Therefore, the value of this inside callback will not be object.

// const object  = {
//    length :5,
//    method(fn){
//       fn();
//    }
// }
// object.method(callback);//4


// var length = 4;
// function callback(){
//     console.log(this.length);
// }


// const object  = {
//    length :5,
//    method(){
//       console.log(arguments)
//       arguments[0]();
//    }
// }
// object.method(callback,2,3);//4

// create an object calculator 

// let calculator ={
//     read(){
//         this.a = prompt("a= " ,0 );
//         this.b=  prompt ("b= " ,0 );
//     },
//     sum(){
//       return thia.a+this.b;
//     },
//     mul(){
//       return thia.a*this.b;
//     }
// }
// calculator.read();
// console.log(calculator.sum())
// console.log(calculator.mul());



