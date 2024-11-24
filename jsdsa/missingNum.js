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
