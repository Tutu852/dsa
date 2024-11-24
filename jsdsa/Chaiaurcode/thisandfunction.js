

const user= {
    userName: "Rajesh",
    price : 999,
    welcomeMessage : function(){
        console.log(`${this.userName},welcome to website`);
        console.log(this);
        
    }
}
// user.welcomeMessage();
// user.userName="gelli";
// user.welcomeMessage();

// console.log(this);


// function chai(){
//     let userName = "hitesh"
//     console.log(this.userName);
// }
// chai()

// const chai =function (){
//     let userName = "hitesh"
//     console.log(this.userName);
// }
// chai()

const chai = ()=>{
    let userName = "hitesh"
    console.log(this.userName);
}
chai()
