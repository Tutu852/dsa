// shallow copy

// const original = { name: "John", address: { city: "NYC" } };
// const shallowCopy = { ...original };
// shallowCopy.address.city = "LA";
// shallowCopy.name ="rajesh";

// console.log(original.address.city); // "LA" (same inner box)

// console.log(original);

// DeepCopy

// const original = { name: "John", address: { city: "NYC" } };
// const deepCopy = JSON.parse(JSON.stringify(original));
// deepCopy.address.city = "LA";
// deepCopy.name ="rajesh";

// console.log(original.address.city); // "NYC" (different inner box)
// console.log(original);


// function myName(){
//     let name = 'rajesh';
//     function myFullName(){
//         console.log(`Hello${name}`);
//     }
//     return myFullName;
// }
// let myNam = myName();
// myNam();




