function countCharacters(str) {
    const counts = {}; // object to hold counts for each character
    for (const ch of str) {
      counts[ch] = (counts[ch] || 0) + 1;
    }
    return counts;
  }
  
  const str = "lovebabbar";
  const characterCounts = countCharacters(str);
  
  // Display the results:
  for (const ch in characterCounts) {
    console.log(`${ch} -> ${characterCounts[ch]}`);
  }
  