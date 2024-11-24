





// //REDUCE 

// // REDUCE METHOD IS REDUCES ALL ARRAY VALUE AND DOWN TO ONE VALUE 
// //acc is the result of previous computation
// const sum = nums.reduce((acc,curr)=>{
//     return acc+curr;
// },0)
// console.log(sum);



//pollyfil of map ,filter and reduce

//Array.map((num,i,arr)=>{})
Array.prototype.myMap =function(cb){
    //map is create a new array
    let temp = [];
    //here this is for arr
    for(let i=0;i<this.length;i++){
        temp.push(cb(this[i],i,this));
    }
    return temp;
}

Array.prototype.myMao = function(cb){
    let data = [];
    for(let i=0;i<this.length;i++){
        data.push(cb(this[i],i,this));
    }
    return data;
}

// filter pollyfil
// Array.filter((num,i,arr)=>{})
Array.prototype.myfilter =function(cb){
    //map is create a new array
    let temp = [];
    
    for(let i=0;i<this.length;i++){
        if(cb(this[i],i,this)) temp.push(this[i]);
    }
    return temp;
}


Array.prototype.myfil=function(cb){
    let data=[];
    for(let i=0;i<this.length;i++){
        if(cb(this[i],i,this))temp.push(this[i]);
    }
    return data;
}

const nums = [1,2,3,4];

const mutiplyThree = nums.myMap((ele,i,arr)=>{
    return ele *3 + i; 
    // 1*3+0;
    // 2*3+1;
    // 3*3+2;
})
console.log(mutiplyThree);


//FILTER
const findMoreThenTwo= nums.myfilter((ele,i,arr)=>{
    return ele > 2;
})
console.log(findMoreThenTwo);


//pollyfil of reduce

//arr.reduce((acc,curr,i,arr)=>{},initialValue)
//in our case the initial value is "0". but if we miss to give the initialvalue accumulator will take 1st value of the array as initialvalue
//this cb has acc,curr,i arr
Array.prototype.myReduce = function(cb,initialValue){
    
    var accumulator = initialValue
    for(let i =0;i<this.length;i++){
        accumulator = accumulator?cb(accumulator,this[i],i,this) : this[i];
    }
    return accumulator;
}
