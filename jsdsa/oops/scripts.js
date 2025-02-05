// const user={
//     firstName : "Rajesh",
//     LastName : "Behera",
//     age :25,
//     getAgeYear(){
//         return new Date().getFullYear() - user.age
//     }
// }
// function getAgeYear(Age){
//     return new Date().getFullYear() - Age;
// }



// factory function
 
function createUser(firstName,LastName,age){
    const user = {
        //if the value and key both same then we dont need to pass both key and value
        firstName ,
        LastName ,
        age ,
        getAgeYear(){
            return new Date().getFullYear() - user.age
        }
         
    };

    return user
}

const user1 = createUser("Aman","Mishra",26);
const user2 = createUser("Ama","Mishr",26);
