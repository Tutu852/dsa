

function countVowels(str){
    let count = 0;
    let vowels ="aeiouAEIOU";

    for(const  char of str){
        if(vowels.includes(char)){
            count++;
        }
    }
    return count;
}




const input = "my name is rajesh";
const vowelCount = countVowels(input);
console.log("Total vowels: ", vowelCount )