

function missingNumber(arr, n) {
    let sum = 0;

    for (let i = 0; i < n; i++) {
        sum += arr[i];
    }

    
    let totalSum = ((n) * (n + 1)) / 2;
    let ans = totalSum - sum;
    return ans;
}


const arr = [3 ,0 ,2 , 5,1,7,4];
const n = arr.length;

const missing = missingNumber(arr, n);
console.log("missing number is:  " + missing);

function missingNumber(arr1,n1){
    const totalsum = ((n)* (n+1))/2;
    const currentSum = arr1.reduce((acc,curr)=>acc +curr,0)

    return totalsum - currentSum;
}

const arr1=[2,4,5,1,7,8];
const n1 = arr1.length;

const miss = missingNumber(arr,n);
console.log("missing number is: "+miss);
