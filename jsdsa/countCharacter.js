function countChar(Str){
    const count = {};
    for(const ch of Str){
        count[ch] = (count[ch] || 0) +1;
    }
    return count;
}

const str1 = "my name is rajesh"
const characterCount = countChar(str1);

for(const ch in characterCount){
    console.log(`${ch} -> ${characterCount[ch]}`);
}



// function countCharacters(str) {
//     const counts = {}; // object to hold counts for each character
//     for (const ch of str) {
//       if (ch === "@" || ch === ".") continue;
//       counts[ch] = (counts[ch] || 0) + 1;
//     }
//     return counts;
//   }
  
//   const str = "852tutkumar@gmail.com";
//   const characterCounts = countCharacters(str);
  
//   // Display the results:
//   for (const ch in characterCounts) {
//     console.log(`${ch} -> ${characterCounts[ch]}`);
//   }




//time complexity: O(n)
//space complexity: O(n)

