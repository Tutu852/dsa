
function reverse(str,start,end){
    while(start<end){
        let temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}


function reverseEachWord(input){
    let str = input.split('');
    let start = 0;

    for(let i=0; i<=str.length;i++){
        if(i == str.length || str[i] == ' ' ){
            reverse(str,start,i-1);
            start = i + 1;
        }
    }
    return str.join('');
}





let input = "Hello world this is JavaScript";
console.log("Original String:", input);

let result = reverseEachWord(input);
console.log("Reversed String:", result);