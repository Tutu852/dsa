function occ (str){
    var occrance = {};
    str.split("").forEach((elem)=>{
        if(occrance.hasOwnProperty(elem)=== false){
            occrance[elem] =1 ;

        }else{
            occrance[elem]++;
        }
    })
    return occrance; 
}
console.log(occ("apple"))