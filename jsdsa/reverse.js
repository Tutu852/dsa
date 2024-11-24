const myArray = [1, 2, 3, 4, 5, 6];

function reverseArray() {
    let left = 0;
    let right = myArray.length-1;

    while (left <= right) { // Change to "<" since there's no need to swap if they meet
        // Swap using array destructuring
        [myArray[left], myArray[right]] = [myArray[right], myArray[left]];

        // Move the pointers
        left++;
        right--;
    }


}

// Test the reverseArray function

console.log("Original array:", myArray);

reverseArray(myArray);
console.log("Reversed array:", myArray);
