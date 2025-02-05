//Synchronous and Asynchronous code



// console.log("start");

// function importantAction(username){
    
//     setTimeout(()=>{
//         return `my Name ${username}`;
//     },1000)
// }

// const message = importantAction("rajesh");

// console.log(message); //undefined

// console.log("Finish");


// callbacks 
// when we pass a function inside another function as argument that's called callback function

// console.log("start");

// function importantAction(username , cb){
    
//     setTimeout(()=>{
//        cb(  `my Name ${username}`);
//     },5000)
// }
// function likeTheVideo(video,cb){
    
//     setTimeout(()=>{
//        cb(  `Like the${video} video`);
//     },1000)
// }
// function ShareTheVideo(video,cb){
  
//         setTimeout(()=>{
//            cb(  `Share the${video} video`);
//         },1000)
// }



// //when we call this nested with in it that's called callback Hell

//  importantAction("rajesh",function (message){
//     console.log(message); //undefined
   
//     likeTheVideo("Javascript  interview Question ", (like) =>{
//         console.log(like);

//         ShareTheVideo("Javascript  interview Question ", (share) =>{
//             console.log(share);
    
//         });
//     });
// });



// resolve above code usign Promise
// console.log("start");

// function importantAction(username ){
//     return new Promise((resolve,reject)=>{

//         setTimeout(()=>{
//            resolve(  `my Name ${username}`);
//         },5000)
//     })
// } 
// function likeTheVideo(video,cb){
//     return new Promise((resolve,reject)=>{

//         setTimeout(()=>{
//            resolve(  `Like the${video} video`);
//         },1000)
//     })
// }
// function ShareTheVideo(video,cb){
    
//     return new Promise((resolve,reject)=>{

//         setTimeout(()=>{
//            resolve(  `sharethe${video} video`);
//         },1000)
//     })
// }

// //instade of doing this
//  importantAction("Roadside Coder")
//  .then((res)=>{
//     console.log(res);
//     return likeTheVideo("javascript interview Question");
//  }).then((res)=>{
//     console.log(res);
//     return ShareTheVideo("javascript Interview Question");
//  }).then((res)=>{
//     console.log(res);
//  })
//  .catch((err)=>console.log(err));

// //  promise combinator :- these means this will help me to execute more than one promise in it and result accordingly;

// // Promise.all // this can help me to get all resolved cd thing . Problem for this is if any one of them will reject then it show  error

// Promise.all([
//     importantAction("Roadside Coder"),
//         likeTheVideo("Javascript Interview Questuion"),
//         ShareTheVideo("Javascript Interview Question"),
// ]).then((res)=>{
//     console.log(res);
// }).catch((err)=>{
//     console.error("Error : Promises")
// })

// Promise.race = it return 1st promise that reject or resolve

//Promise.any = it will return only the 1st resolve one if 3 function are tehre and all 3are rejected then it will give reject

// Promise.allSettled([
//     importantAction("Roadside Coder"),
//     likeTheVideo("Javascript Interview Questuion"),
//     ShareTheVideo("Javascript Interview Question"),
// ]).then((res)=>{
//     console.log(res);
// }).catch((err)=>{
//     console.log("Error: Promise Failed" , err);
// })
 

//async await

// const result = async () =>{
//    try{
//     const message = await importantAction("Rodeside Coder");
//     const message1 = await likeTheVideo("Rodeside Coder");
//     const message2 = await ShareTheVideo("Rodeside Coder");

//     console.log({message,message1,message2});
//    }catch(error){
//     console.log("Promise Failed" , error);
//    }
// }


// result();

// console.log("Finish");


// to solve this callback hell promise came 

// Promise 

// console.log("Start");

// const sub = new Promise((resolve,reect)=>{
//     setTimeout(()=>{
//         const result = true;

//         if(result){
//             resolve("I am resolved");
//         }else{
//             reject(new Error("Why aren't you subscribed to readside coder"))
//         }
//     },2000)
// });

// console.log();


// //if ture
// sub.then(()=>{
//     console.log(res);
    
// }).catch((err)=>{
// //this is for false;
// console.log(err);

// })

// console.log("stop");



//Interview question

// console.log("Start");

// const Promise1 = new Promise((resolve,reject)=>{
//     console.log(1);
//     resolve(2);
// });

// Promise1.then((res)=>{
//     console.log(res);
// })

// console.log("end");

// answer should be start then 1 then end then 2
//because javascript always consider sync then async code so here resolve is coming in as async.


console.log("start"); //first
const fn = () =>{
    new Promise((resolve,reject)=>{
        console.log(1);//third because after middle fn()run so this will go after middle
        resolve("success");//fifth
    })

    console.log("middle");//second

    fn().then((res)=>{
        console.log(res); //fifth
    })
}
console.log("end");//fourth


// function job(){
//     return new Promise(function(resolve ,reject){
//         reject();
//     });
// }

// let promise = job();

// promise 
// .then(function(){
//     console.log("Success 1");
// })
// .then(function(){
//     console.log("Success 2");
// })
// .then(function(){
//     console.log("Success 3");
// })
// .error(function(){
//     console.log("error 1");
// })
// .then(function(){
//     console.log("Success 4");
// })

//Ans:- error 1 after Success 4 because we reject the promise so it directly come to error

function job(state){
    return new Promise(function(resolve,reject){
        if(state){
            resolve("success");
        }else{
            reject("error");
        }
    });
}

let promise =job(true);

promise
    .then(function(data){
        console.log(data);

        return job(false);
    })
    .catch(function(error){
        console.log(error);
        //when u return in catch it will resolve next then
        return "Error Caught";
    })
    .then(function(data){
        console.log(data);
        return job(true);
    })
    .catch(function(error){
        console.log(error);
    })

    // Ans:-  success
            //error
            //error caught

// // Q3  promise chaining
// const firstPromise = new Promise((resolve ,reject)=>{
//     resolve("First!")
// })

// const secondPromise = new Promise((resolve,reject)=>{
//     resolve("Second!");
// });

// secondPromise 
// .then((res)=>{
//     return res;
//     })
//     .then((res)=>console.log(res));

// Q:4 
// // write a examle using async/await instade of .then/catch 

// async function loadjson(url){
//     let response = await fetch(url);

//     if(response.status == 200){
//         let data = await response.json();
//         return data;
//     }
//     throw new Error(response.status );
// }

// loadjson("https://fakeurl.com/").catch((err)=>{
//     console.log(err);
// })

// console.log("start");
// function givemeName(username){
//     return new Promise((resolve,reject)=>{
//         setTimeout(()=>{
//             const result = true;
//             if(result) resolve("subscribt to roadside coder");
//             else reject("username is not valid");
//         },2000);
//     })
//     .then((res)=>{
//         console.log(res);
//     })
//     .catch((err)=>{
//         console.log(err);
//     })
// }

// givemeName(rajesh);
// console.log("end");