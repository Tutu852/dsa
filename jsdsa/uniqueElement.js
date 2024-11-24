 


 function getUnique(arr, size){
    let ans = 0;

    for( let i=0; i<size; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

const arr = [2,10,11,10,2,13,15,13,15];
const size = arr.length;
const uniqueValue = getUnique(arr, size);
console.log("Unique value is:", uniqueValue); 
