//what is closure?

// console.log(getScore()); // "Chamakh scored 5"


// function a(){
//     for(let i=0;i<5;i++){
//     setTimeout(function(){
//         console.log(i);
//     },i * 1000);
//     }
// }
// a();

// for(var i=1;i<=3;i++){
//     setTimeout(()=>{
//         console.log(i); //4 will come 3 times
//     },1000);
// }


// function a(){
//     for(var i=1;i<=3;i++){
//        ( function(i){
//             setTimeout(function log(){
//                 console.log(i);
//             },i * 1000);
//         })(i);
        
//     }
// }
// a();

//  for(var i =0;i<5;i++){
//    function innerHeight(i){
//     setTimeout(function log(){
//         console.log(i)
//     },i *1000);
//    }
//    innerHeight(i);
// }




// function salutation() {
//     let name = 'Aayush';

//     function greet() {
//         console.log(`Hello ${name}!`);
//     }
//     return greet;
// }

// let wish = salutation();
// wish();

// create a clouser 
// function salution(){
//     let name = "Gelli";
//     function greeat(){
//         console.log(`Hello ${name}!`);
//     }
//     return greeat;
// }
// let wish = salution();
// wish();

//in closer we can access n every scope 
// chaning 

// var e = 10;
// function sum(a){
//     return function (b){
//         return function (c){
//             return function (d){
//                 return a + b + c + d + e;
//             }
//         }   
//     }
// }
// console.log(sum(1)(2)(3)(4)); //20



// Q3. var addSix = createaBase(6);
// addSix(10); // return 16
// addSix(15); //return 21

// function createaBase(num){
//     return function(innernum){
//         console.log(innernum + num);
//     }
// }

// var addSix = createaBase(6);
// addSix(10);
// addSix(15);

// function find(index){
    //     let a = [];
    //     for(let i=0;i<100000;i++){
        //         a[i] = i*i;
        //     }
        // }
        // const cls = find();
        // console.time("6");
        // cls(6);
        // console.timeEnd(6)
        
// time optimization using closure 
// //solution
// function find(){
//     let a = [];
//     for(let i = 0;i<100000;i++){
//         a[i] = i*i;
//     }
//     return function(index){ 
//         console.log(a[index])
//     }
// }
// const clouser = find();
// console.time("6");
// clouser(6);
// console.timeEnd("6");
// console.time("6");
// clouser(6);
// console.timeEnd("6");



//create a private counter


function counter(){
    //_counter _ this is privatex
    var _counter = 0;

    function add(increment){
        _counter += increment;
    }
    function retrive(){
        return "Counter = " + _counter;
    }

    return {
        add,
        retrive,
    };
}

const c = counter();
console.log(c.add(5));

c.add(10);


console.log(c.retrive());


//what is Module Pattern
// var module = (function(){
//     function privateMethod(){
//         console.log("Private Method");
//     }
//     return {
//         publicMethod: function(){
//             console.log("Public Method");
            
//         }
//     }
// })();

// module.publicMethod();
// module.privateMethod();

// let view;
// function likeTheVideo(){
//     let called = 0;
//     return function(){

//         if(called > 0){
//             console.log("Already like the Video");
//         }else{
//             view = "Like the video";
//             console.log("Please ",view);
//             called++;
//         }
//     }
// }
// let like = likeTheVideo();
// like();
// like();
// like();
// like();




//Courser in javascript
//Q.7 Make this run ans

// let view;

// function likeTheVideo(){
//     let called = 0;
//     return function(){
//         if(called > 0){
//             console.log("You have already liked this video");
//         }else{
//             view = "rajesh";
//             console.log("Love to", view);
//             called++;
//         }
//     }
// }
// let isSubscribe = likeTheVideo();
// isSubscribe();
// isSubscribe();
// isSubscribe();
// isSubscribe();




// function subscribe(){
//     var name = "Rajesh";
//     function displayName(){
//         console.log(name);
//     }
//     displayName();
// }
// subscribe();


// clouser Scope Chain 

// var userName ="Behera"
// function makeFun(){
//     var name = "Rajesh";
//     function displayName(num){
//         console.log(name,num,userName);
//     }
//     return displayName;
// }
// makeFun()(5);

