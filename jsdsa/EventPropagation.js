//event bubbling

// const div = document.querySelector("div");

// const form = document.querySelector("form");
// const button = document.querySelector("button");

// div.addEventListener("click" , function(){
//     alert("div");
// })
// form.addEventListener("click" , function(){
//     alert("form");
// })
// button.addEventListener("click" , function(){
//     alert("button");
// })

// Q :- event.target vs this.target vs event.currentTarget

// const div = document.querySelector("div");
// const form = document.querySelector("form");
// const button = document.querySelector("button");

// div.addEventListener("click" ,func)
// form.addEventListener("click",func )
// button.addEventListener("click",func )

// function func(event){
//     alert("currentTarget = " +
//         event.currentTarget.tagName +
//         ", target = " +
//         event.target.tagName

//     );
// }


// Q what is the event Capturing /trickling 


// const div = document.querySelector("div");
// const form = document.querySelector("form");
// const button = document.querySelector("button");

// div.addEventListener("click" , function(){
//     alert("div");
// },
//  {
//     capture:true,
//  }
// )
// form.addEventListener("click" , function(){
//     alert("form");
// },

// )
// button.addEventListener("click" , function(){
//     alert("button");
// })


// Q - how to stop bubbling or capturing

// const div = document.querySelector("div");
// const form = document.querySelector("form");
// const button = document.querySelector("button");

// div.addEventListener("click" , function(e){
    
//     alert("div");
// });
// form.addEventListener("click" , function(e){
//     e.stopPropagation();
//     alert("form");
// });
// button.addEventListener("click" , function(e){
   
//     alert("button");
// });


// Q:- what is Event Delegation
//this is creating the routes

document.querySelector(".products").
addEventListener("click",(event)=> {
    console.log(event.target.closest("SPAN"));
    if(event.target.tagName === "SPAN"){
        window.location.href += "/" + event.target.className;
    }
});