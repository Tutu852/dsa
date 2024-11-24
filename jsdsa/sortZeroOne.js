 

// Javascript program to sort a binary array in one pass 

/*Function to put all 0s on left and all 1s on right*/
function segregate0and1(arr, size) 
{ 
	/* Initialize left and right indexes */
	let left = 0, right = size-1; 

	while (left < right) 
	{ 
		/* Increment left index while we see 0 at left */
		if (arr[left] == 0 ) 
			left++; 

		/* Decrement right index while we see 1 at right */
		if (arr[right] == 1 ) {

			right--; 
        }else{
            /* If left is smaller than right then there is a 1 at left 
            and a 0 at right. Exchange arr[left] and arr[right]*/
            arr[left] = 0; 
			arr[right] = 1; 
			left++; 
			right--; 
        }
        
		
	} 
} 

/* Driver code */
let arr = [0,1,0,1,0,1,1,1,1,0,0,0,0,0]; 
let   arr_size = arr.length; 

segregate0and1(arr, arr_size); 

console.log("Array after segregation "); 
for (i = 0; i < arr_size; i++) 
	console.log(arr[i] + " "); 

 

