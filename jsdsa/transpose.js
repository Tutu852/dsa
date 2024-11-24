let array = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
];


function tranpose (){
let row  = array.length;
let col = array[0].length;

for(let i = 0;i<row;i++){
    for(let j=i;j<col;j++){
        [array[i][j] , array[j][i] ] = [array[j][i],array[i][j]]
    }
}

}
console.log("Original matrix:");
console.table(array);

tranpose(array);

console.log("Transposed matrix:");
console.table(array);

