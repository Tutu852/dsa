function shiftingNegativeInteger(arr , size){
    let j =0 

    for(let i = 0;i<size;i++){
        if(arr[i] < 0){
            [arr[i],arr[j] ]=  [arr[j],arr[i]];
            j++;
        }
    }
}

const arr= [23,-7,12,-10,-1,40,60];
const size = 7;

shiftingNegativeInteger(arr,size);

//print
for(let i=0;i<size;i++){
    console.log(arr[i] + " ");
}