const arr = ['one' ,'two' ,'three'];
const str = "Hello";

const res = arr.includes('one');
const anotherView = arr.includes('one two');

const  newview = str.includes('ll');//this is 'true' because it will go to the string and check there is ll is present in Hello..thats why it is true;

console.log(res);
console.log(anotherView);
console.log(newview);
