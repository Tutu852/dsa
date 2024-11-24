
function sortZeroOneTwo(arr,size){
    let index= 0 ;
    let left = 0;
    let right = size-1;


    while(index  <= right){
        if(arr[index] == 0){
            [arr[index],arr[left]] = [arr[left],arr[index]];
            index++;
            left++
        }else if(arr[index] == 2){
            [arr[index],arr[right]] = [arr[right],arr[index]];
            right--;
        }else{
            index++;
        }
    }
}


const arr = [0,1,1,2,0,2,1];
const size = arr.length;

sortZeroOneTwo(arr,size);


console.log("Array after segregation "); 
for (i = 0; i < size; i++) 
	console.log(arr[i] + " "); 
