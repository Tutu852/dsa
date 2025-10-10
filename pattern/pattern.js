// function squre(){
//     for(let row=0;row<4;row++){
//         let line="";
//         for(let col=0;col<4;col++){
//             line += "* " 
//         }
//         console.log(line)
//     }
// }
// squre();



// function HollowSquare(n){
//     for(let row =0;row<n;row++){
//         let line="";
//         for(let col=0;col<n;col++){
//             //i did a mistake here col <n-1 it is col == n-1
//             if(row == 0 || row == n-1 ||col ==0 ||col== n-1){
//                 line += "* ";
//             }
//             else{
//                 line += "  ";
//             }
//         }
//         console.log(line);
//     }
// }
// HollowSquare(5);



// function hollowInverted(n){
//     for(let i=0;i<n;i++){
//         let line ="";
//         for(let j=0;j<n;j++){
//             if(i==0 || j==0 || j == n-i-1){
//                 line += "*"
//             }else{
//                 line += " ";
//             }
//         }
//         console.log(line);
        
//     }
// }
// hollowInverted(5);

// function invertedTriangle(n){
//     for(let row=0;row<n;row++){
//         let line="";
//         for(let col=0;col<n-row;col++){
//             line += "*";
//         }
//         console.log(line);
//     }
// }
// invertedTriangle(5);



// function mirrorTriangle(n) {
//   for (let row = 0; row <= n; row++) {
//     let line = ""; 

//     // then stars
//     for (let col = 0; col < row+1; col++) {
//       line += "*";
//     }
//     console.log(line);
//   }
// }

// mirrorTriangle(5);

// function hollowrightangletriangle(n){
//     for(let row=0;row<n;row++){
//         let line="";
//         for(let col=0;col<=row;col++){
//             if(col==0 || row == n-1 || col == row){
//                 line += "*";
//             }else{
//                 line += " ";
//             }
//         }
//         console.log(line);
//     }
// }
// hollowrightangletriangle(5);

// function mirrorTrianglechar(n) {
//   for (let row = 0; row <= n; row++) {
//     let line = ""; 

//     // then stars
//     for (let col = 0; col < row; col++) {
//       line += String.fromCharCode(col +97);
//     }
//     console.log(line);
//   }
// }

// mirrorTrianglechar(5);

// function mirrorTriangleNumber(n){
//     for(let row =0;row<=n;row++){
//         let line ="";
//         for(let col=0;col<row;col++){
//             line += col+1;
//         }
//         console.log(line);
//     }
// }
// mirrorTriangleNumber(5);



// function triangle(n){
//     for(let row=0;row<n;row++){
//         let line="";
//         //space
//         for(let col=0;col<n-row-1;col++){
//             line += " ";
//         }
//         //star
//         for(let col=0;col<row+1;col++){
//             line += "* ";
//         }
//         console.log(line);
        
//     }
// }

// triangle(5);

// function reverseTriangle(n){
//     for(let row=0;row<n;row++){
//         let line ="";
//         //space
//         for(let col=0;col<row;col++){
//             line +=" ";
//         }

//         //star
//         for(let col=0;col<n-row;col++){
//             line += "* ";
//         }
//         console.log(line);
//     }
// }
// reverseTriangle(5);

