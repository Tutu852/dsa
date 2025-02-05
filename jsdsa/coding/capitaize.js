// const capitalize = (str)=>{
//    var allwords =  str.split(" ").map((word)=>{
//        return word.charAt(0).toUpperCase()+ word.substring(1)
//     })
//    return allwords.join(" ");
// }

// console.log(capitalize("rajesh vicky subha akhi"));




const  capitalize = (str)=>{
    var data = str.split(" ").map((word)=>{
        return word.charAt(0).toUpperCase() + word.substring(1)
    })
    return data.join(" ");
}
console.log(capitalize("my name is rajesh"))


const capital = (str) =>{
    var letter = str.split(" ").map((data)=>{
        return data.charAt(0).toUpperCase() + data.substring(1)
    })
    return letter.join(" ");

}
console.log(capital("rajesh kumar behera"))