//what is call


var obj ={name:"rajesh"};
function sayHello(age){
    return "Hello "+ this.name + " is "+age;
}
// console.log(sayHello.call(obj,25));
//apply is same as call but here what ever argumet we need to pass that pass in a array 
// console.log(sayHello.apply(obj,[24]))

//bin will create a function on this
// const bindfunc = sayHello.bind(obj);
// console.log(bindfunc(24))


// var obj ={name:"rajesh"};

// function sayHello(age){
//   return "Hello " + this.name + " is " + age;
// }
// console.log(sayHello()); //Hello undefined is undefined
// after fixing 

// var obj = {name:"rajesh"};

// function sayHello(age){
//     return "hello " + this.name + " is " + age;
// }

// console.log(sayHello.call(obj,24));


//what is apply

// var obj = {name : "rajesh"};
// function sayHello(age,profession){
//     return "Hello " + this.name + " is "+age +" is an a " + profession ;
// }
// console.log(sayHello.apply(obj,[24,"Software engineer"]));

//what is bind


// var obj = {name : "rajesh"};
// function sayHello(age,profession){
//     return "Hello " + this.name + " is "+age +" is an a " + profession ;
// }
// const bindfunc =sayHello.bind(obj)

// console.log(bindfunc(24, " software Engineer ")); 
// console.log(bindfunc(23, " software Engineer ")); 


//output base question

// Question:-1
// const person = { name: "Rajesh"};


// function sayHi(age){
//     return `${this.name} is ${age}`;
// }
// console.log(sayHi.call(person,24)); //rajesh is 24
// console.log(sayHi.bind(person,24)); //this will give a function




// question:2

// const age = 20;

// var perosn = {
//     name :"Rajesh",
//     age:25,
//     getAge:function(){
//         return this.age; //this is pointed to the person object age
//     }
// }
// var person2 = {age:24};
// person2.getAge.call(person2); //24


// Question:-2

// var status ="😎"

// setTimeout(()=>{
//     const status = "😍";

//     const data = {
//         status:"🥑",
//         getStatus(){
//             return this.status;
//         }
//     }
//     console.log(data.getStatus());//🥑
//     console.log(data.getStatus.call(this));//😎
//     //this keyword never pointed to the function 
//     //this will pointed to the context of the function
// },0);

// Question :- call printAnimals such that it prints all animals 

// const animals =[
//     { species:"Lion" , name: "King"},
//     { species:"Whale" , name: "Queen"}
// ];

// function printAnimals(i){
//     this.print = function(){
//         console.log("#" + i + " " + this.species + ":" + this.name);
//     };
//     this.print();
// }
// for(let i =0; i<animals.length;i++){
//     printAnimals.call(animals[i],i)
// }



//Question  Append an array to another array



const array = ["a" , "b"];
const elements = [0,1,2];
// concate will give new array instade of that array so i use apply here

// console.log(array.concat(elements));

array.push.apply(array,elements);

console.log(array);


// question:- find min/max number is an array 
// const numbers = [5,6,2,3,7];

//using loop
// max = -Infinity ,min = +Infinity;


// for(let i=0; i <numbers.length;i++){
//     if(numbers[i] > max){
//         max = numbers[i];
//     }
//     if(numbers[i] < min){
//         min= numbers[i]
//     }
// }

// using call,apply,bind 

// console.log(Math.max.apply(null,numbers)); //7
// console.log(Math.min.apply(null,numbers)); //2
// console.log(Math.max(...numbers));


//bind Chaining

// function f(){
//     console.log(this.name);
// }
// f = f.bind({name : "john"}).bind({name:"Ann"});

// f();
//there is no such concept of bind chaing ans is john

// question :-fix the line 165  to make code work properly 

// function checkPassword(success,failed){
//     let password = prompt ("password" ,"");
//     if(password == "rajesh123") success();
//     else failed();
// }

// let user ={
//     name :"Rajesh",

//     loginSuccessful(){
//         console.log(`${this.name} logged in`);
//     },
//     loginFailed(){
//         console.log(`${this.name} faild to log`)
//     }
// }
// //use bind here to get the name bind(user)
// checkPassword(user.loginSuccessful.bind(user),user.loginFailed.bind(user));



// Question :- Partial application for login function
//i need a function ineed bind here  


// function checkPassword(ok,fail){
//     let password = prompt("password?" , "");
//     if(password == "rajesh123") ok();
//     else fail();
// }
// let user = {
//     name:"Rajesh Behera",

//     login(result){
//         console.log(this.name + (result ? " login successful" : " login failed"));
//     }
// }
// checkPassword(user.login.bind(user,true), user.login.bind(user,false));


// Question:- Explict binding with Arrow function 

// const age = 20;

// var person = {
//     name :"Piyush",
//     age : 20,
//     getAgeArrow : ()=> console.log(this.age),
//     getAge : function() {
//         console.log(this.age);
//     }
// }
// var person2 = {age : 25};
// person.getAgeArrow.call (person2);
// //undefind because arrow function will always indicate to the window object
// person.getAge.call(person2);//24




// pollyfil of call 

// let car = {
//     color:"Red",
//     companey:"Farrari",
// };

// function purchaseCar(currency,price){
//   console.log(
//     `I have purchased ${this.color} - ${this.companey} car for  ${currency} ${price}`
//   )  
// }

// call takes one is context and other is ...arg of object    
// Function.prototype.myCall = function(context = {} , ...args){
//     if(typeof this !== 'function'){
//         throw new Error(this + "Its not callable");
//     }
//     context.fn = this; //this indicate  to   parchaseCar
//     context.fn(...args);
// }

// purchaseCar.myCall(car,"$", 1000 );


//pollyfill for apply
// let car1 = {
//     color:"Red",
//     companey:"Farrari",
// };

// function purchaseCar(currency,price){
//   console.log(
//     `I have purchased ${this.color} - ${this.companey} car for  ${currency} ${price}`
//   )  
// }

// Function.prototype.myApply = function(context = {} , args = []){
//     if(typeof this !== 'function'){
//         throw new Error(this + "Its not callable");
//     }

//     if(!Array.isArray(args)){
//         throw new TypeError("createListFromArray like called on non")
//     }
//     context.fn = this;
//     context.fn(...args);
// }

// purchaseCar.myApply(car1,["$", 1000] );

// const person ={

//   name : "rajesh",
  
//     sayHello:function(){
//       return "hello "+ this.name;
//     }
// }
// console.log(person.sayHello());

// var obj = {name:"rajesh"}

// function sayHello(age){
//   return "hello "+ this.name + "is" +age;
// }
// console.log(sayHello.call(obj,24));

