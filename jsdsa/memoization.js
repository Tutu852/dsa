// console.time("Total Execution Time");
// function fibonacci(n) {
//     if (n <= 1) return n;
//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// console.log(fibonacci(10)); // Takes time
// console.timeEnd("Total Execution Time");


function fibonaccii(){
    const cache={}
    return function fib(n){

        if(n in cache){
            return cache[n]
        }
    
        if(n<=1) return n;
        cache[n]=fib(n-1)+fib(n-2);
        return cache[n];
    }
}

const fibonacc = fibonaccii();
console.log(fibonacc(10))



