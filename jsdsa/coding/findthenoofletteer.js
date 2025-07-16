// function occ (str){
//     var occrance = {};
//     str.split("").forEach((elem)=>{
//         if(occrance.hasOwnProperty(elem)=== false){
//             occrance[elem] =1 ;

//         }else{
//             occrance[elem]++;
//         }
//     })
//     return occrance; 
// }
// console.log(occ("apple"))

function occ(str){
    const occrance =[];

    for(let char of str){
        occrance[char] = occrance[char] ? occrance[char]+1 :1;
    }
}

function occ(str) {
  const occurance = {};
  for (let char of str) {
    occurance[char] = occurance[char] ? occurance[char] + 1 : 1;
  }
  return occurance;
}
console.log(occ("apple"));