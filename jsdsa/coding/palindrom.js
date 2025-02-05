function palindrom(str){
    var reversed = str.split("").reverse().join("");
    return reversed ===str ? true:false;
    // if(reversed === str){
    //     return true;

    // }else return false

}
console.log(palindrom("pope"))


function pali (str){
    var reverse = str.split("").reverse().join("");
    return reverse === str ? true : false
}
console.log(pali("pop"))