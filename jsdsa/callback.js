// function fetchUserData(UserId,callback){
//     setTimeout(() => {
//         console.log("fetch user data");
//         callback(UserId)
//     }, 1000);
// }

// function fetchPosts(UserId,callback){
//     setTimeout(() => {
//         console.log("Fetch posts for user ",UserId);
//         callback();
//     }, 1000);
// }

// function fetchComments(callback){
//     setTimeout(()=>{
//         console.log("fetch comments");
//         callback();
//     },1000)
// }

// console.time("Total Execution Time");

// fetchUserData(1,(UserId)=>{
//     fetchPosts(UserId,()=>{
//         fetchComments(() => {
//             console.log("All data fetched");
//             // Stop timer with matching label
//              console.timeEnd("Total Execution Time");
//         });
//     })
// })

// optimise the code 
// function fetchUserData(UserId){
//     return new Promise((resolve)=>{

//         setTimeout(() => {
//             console.log("fetch user data");
//             resolve(UserId)
//         }, 1000);
//     })
// }

// function fetchPosts(UserId){
//     return new Promise((resolve)=>{
//         setTimeout(() => {
//             console.log("Fetch posts for user ",UserId);
//             resolve();
//         }, 1000);
//     })
// }

// function fetchComments(){
//     return new Promise((resolve)=>{
//         setTimeout(()=>{
//             console.log("fetch comments");
//             resolve();
//         },1000)
//     })
// }
// async function fetchAllData() {

//     console.time("Total Execution Time");

//     try {
//         const UserId = await fetchUserData(1);
//         await fetchPosts(UserId);
//         await fetchComments();
//         console.log("All tasks done!");
//     } catch (error) {
//         console.error("An error occurred:", error); 
//     }
//     console.timeEnd("Total Execution Time");

// }

// // Call the async function
// fetchAllData();

// console.time("Total Execution time");
// fetchUserData(1)
//     .then(fetchPosts)
//     .then(fetchComments)
//     .then(() => console.log("All tasks done!"))
//     .catch((error) => console.error(error));
// console.timeEnd("Total Execution time");



// imp 



