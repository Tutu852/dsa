
const arr = [10,20,30,40,50,60,70];

let size = arr.length;

function extreamArray(){
    let left = 0;

    let right = size-1;

    while(left <= right){
        if(left == right){
            console.log(arr[left]);
        }else{
            console.log(arr[left]+ " ");
            console.log(arr[right] + " ");
        }
        left++;
        right--;
    }

}
extreamArray();

