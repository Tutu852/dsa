
// console.log(getScore()); // "Chamakh scored 5"




function a(){
    for(let i=0;i<5;i++){
    setTimeout(function(){
        console.log(i);
    },i * 1000);
    }
}

a();


function a(){
    for(var i=0;i<3;i++){
       ( function(i){
            setTimeout(function log(){
                console.log(i);
            },i * 1000);
        })(i);
        
    }
}
a();

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


//create a private counter

// function counter(){
//     var _counter = 0;

//     function add(increment){
//         _counter += increment;
//     }
//     function retrive(){
//         return "Counter = " + _counter;
//     }

//     return {
//         add,
//         retrive,
//     };
// }

// const c = counter();
// console.log(c.add(5));

// c.add(10);


// console.log(c.retrive());




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