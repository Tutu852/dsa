// Function to find duplicates in a string without using Set or built-in functions
// const findDuplicatesInString = (str) => {
//     let duplicates = [];
    
//     // Outer loop to go through each character in the string
//     for (let i = 0; i < str.length; i++) {
//       // Inner loop to compare the current character with the remaining characters
//       for (let j = i + 1; j < str.length; j++) {
//         if (str[i] === str[j] && !duplicates.includes(str[i])) {
//           duplicates.push(str[i]); // Add the character to duplicates if found
//         }
//       }
//     }
  
//     return duplicates;
//   };


// another way

// const findDuplicatesInString = (str) => {
//     let duplicates = [];
//     let seen = {};  // Using an object to track occurrences
//     let added ={};
    
//     // Loop through the string
//     for (let i = 0; i < str.length; i++) {
//       if (seen[str[i]] ) {
//         if (!added[str[i]]) {
//             duplicates.push(str[i]);
//             added[str[i]] = true;  // Mark as added
//           }
//         } else {
//           // Otherwise, mark the character as seen
//           seen[str[i]] = true;
//         }
//     }
  
//     return duplicates;
//   };




  const findDuplicate=(str)=>{
    let duplicate = [];
    let seen={};
    let alreadyThere={};

    for(let i=0;i<=str.length;i++){
      if(seen[str[i]]){
        if(!alreadyThere[str[i]]){
          duplicate.push(str[i]);
          alreadyThere[str[i]]=true;
        }
      }else{
        seen[str[i]] = true;
      }
    }
    return duplicate;
  }
  
  // Example usage
  let str = "hello world";
  console.log(findDuplicate(str)); 
  