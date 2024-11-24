// Q:-1 Create a button UI and add debounce as follows =>
    // --> Show "Button Pressed<X> Times " every time button is pressed 
//Increase "Trigered <Y> Times" count after 800ms of debounce


// const btn = document.querySelector(".increment_btn");
// const btnPress = document.querySelector(".increment_pressed");
// const count = document.querySelector(".increment_count");


// var pressedCount = 0;
// var triggerCount = 0;

// const debouncedCount = _.debounce(()=>{
//     count.innerHTML = ++triggerCount;
// },800)

// btn.addEventListener('click',()=>{
//     btnPress.innerHTML = ++pressedCount;
//     debouncedCount();
// })

//loadash is create a custom implementation of debouncing


//throttling

// const btn1 = document.querySelector(".increment_btn");
// const btnPress1 = document.querySelector(".increment_pressed");
// const count1 = document.querySelector(".increment_count");


// var pressedCount = 0;
// var triggerCount = 0;

// const start = new Date().getTime();

// const throttlingCount = _.throttle(()=>{
//     const now = new Date().getTime();
//     console.log(now - start);
    
//     count1.innerHTML = ++triggerCount;
// },800)

// btn1.addEventListener('click',()=>{
//     btnPress1.innerHTML = ++pressedCount;
//     throttlingCount();
// })



// create debounce() Polyfill Implementation

// const btn = document.querySelector(".increment_btn");
// const btnPress = document.querySelector(".increment_pressed");
// const count = document.querySelector(".increment_count");


// var pressedCount = 0;
// var triggerCount = 0;

// const myDebounce = (cb,d) =>{
//     let timer;
    
//     return function(...args){
//         if(timer) clearTimeout(timer);
//         timer = setTimeout(()=>{
//             cb(...args);
//         },d)
//     }
// }

// const debouncedCount = myDebounce(()=>{
//     count.innerHTML = ++triggerCount;
// },800)

// btn.addEventListener('click',()=>{
//     btnPress.innerHTML = ++pressedCount;
//     debouncedCount();
// })


//pollyfill of throttling 



const btn1 = document.querySelector(".increment_btn");
const btnPress1 = document.querySelector(".increment_pressed");
const count1 = document.querySelector(".increment_count");


var pressedCount = 0;
var triggerCount = 0;

const myThrottle=((cb,d)=>{
    let lastCallTime = 0;

    return (...args)=>{
        let now =  new Date().getTime();
        if(now - lastCallTime < d) return;
        lastCallTime=now;
        return cb(...args);
    }
})

const start = new Date().getTime();

const throttlingCount = myThrottle(()=>{
    const now = new Date().getTime();
    console.log(now - start);
    
    count1.innerHTML = ++triggerCount;
},1000)

btn1.addEventListener('click',()=>{
    btnPress1.innerHTML = ++pressedCount;
    throttlingCount();
})