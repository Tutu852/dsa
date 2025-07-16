







//pollyfil of map ,filter and reduce




Array.prototype.myMap=function(cb){
    let temp =[];
    for(let i =0;i<this.length;i++){
        temp.push(cb(this[i],i,this));
    }
    return temp;
}

Array.prototype.myFilter =function(cb){
    let temp =[];
    for(let i =0;i<this.length;i++){
        if(cb(this[i],i,this)) temp.push(this[i])
    }
    return temp
}

Array.prototype.myReduce = function(cb,initialValue){
    var acc = initialValue;
    for(let i=0;i<this.length;i++){
        //if anything present inside the acc tehn cb(this[i],i,this )otherthan that the firstvalue of the array
        acc = acc ? cb(this[i],i,this):this[i];
    }
    return acc;
}

// Array.map((num,i,arr)=>{})


// Array.prototype.myMap=function(cb){
//     let temp = [];
//     for(let i=0;i<this.length;i++){
//         temp.push(cb(this[i],i,this));
//     }
//     return temp;
// }
// const nums = [1,2,3,4];

// const mutiplyThree = nums.myMap((ele,i,arr)=>{
//     return ele *3 + i; 
//     // 1*3+0;
//     // 2*3+1;
//     // 3*3+2;
// })
// console.log(mutiplyThree);

// // filter pollyfil

// // Array.filter((num,i,arr)=>{})

// Array.prototype.myfilter= function(cb){
//     let temp = [];
//     for(let i =0;i<this.length;i++){
//         if(cb(this[i],i,this)) {
//             temp.push(this[i]);
//         }
//     }
//     return temp;
// }


// //FILTER
// const moreThanTwo = nums.filter((num)=>{
//     return num > 2
// })
// console.log(moreThanTwo);


//pollyfil of reduce

//arr.reduce((acc,curr,i,arr)=>{},initialValue)
//in our case the initial value is "0". but if we miss to give the initialvalue accumulator will take 1st value of the array as initialvalue
// //this cb has acc,curr,i arr
// Array.prototype.myReduce = function(cb,initialValue){
//     var accumulator = initialValue
//     for(let i =0;i<this.length;i++){
//             accumulator = accumulator?cb(accumulator,this[i],i,this) : this[i];
//         }
//         return accumulator;
//     }

    // Array.prototype.myReduce =function(cb,initialValue){
    //     var accumulator = initialValue;
    //     for(let i=0;i<this.length; i++){
    //         accumulator = accumulator? cb(
    //             accumulator,this[i],i,this
    //         ):this[i];
    //     }
    //     return accumulator;
    // }
    
    //REDUCE 
    
    // // REDUCE METHOD IS REDUCES ALL ARRAY VALUE AND DOWN TO ONE VALUE 
    // //acc is the result of previous computation

    // const sum = nums.myReduce((acc,curr,i,arr)=>{
    //     return acc+curr;
    // },1)
    // console.log(sum);

    // Question:-1 

    // const arr = [2,5,3,4,7];

    // const mapResult = arr.map((arr)=>{
    //     return arr *2;
    // })
    // console.log(mapResult);

    // const forEachResult = arr.forEach((arr,i)=>{
    //     arr[i]= arr *2;
    // })
    // console.log(forEachResult,arr);


    // Question:-2 

    let students =[
        {name:"rajesh",rollNumber:31,marks:80},
        {name:"vicky",rollNumber:15,marks:90},
        {name:"jaga",rollNumber:21,marks:50},
        {name:"baya",rollNumber:7,marks:30},
    ]

    // Question u have to print the mark above 60 with name 
    // ans 
    // const names = students.filter((stu)=>stu.marks > 60).map((stu)=>stu.name);
    // console.log(names);

    //return total marks for students with marks greater then 60 after 20 marks have been added to these who scores less than 60
    // ans 
    const totalMarks = students.map((stu)=>{
        if(stu.marks < 60){
            stu.marks +=20;
        }
        return stu;
    }).filter((stu)=>stu.marks > 60).reduce((acc,curr)=>acc + curr.marks , 0);
    console.log(totalMarks);
    



    