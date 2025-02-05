function factorial(n){

    if(n==0 || n ==1){
        return 1;

    }

    for(let i= n-1; i>=1 ; i--){
        n = n*i;
    }
    return n;
}    

console.log(factorial(5));


function summation(num){
    let sum =0;
     for(let i=1;i<=num;i++){
        sum = sum+i;
     }
     return sum;
}

console.log(summation(4))