#include<iostream>
using namespace std;

int findNumber(int arr[],int size,int target){
    int start = 0;
    int end = size-1;
    int mid = start+(end-start)/2;

    while(start <= end){
        //found
        if(arr[mid] == target){
            return mid;
        }
        else if(target > arr[mid]){
            start = mid +1;
        }else if(target < arr[mid]){
            end = mid-1;
        }
        //here the cache we need to update the mid here
        mid = start+(end-start)/2; 
    }
    //aagr yaha tak pahonch gaye he to fir element nehni mila
    //then here we need to retrun -1;
    return -1;
}


int findfirstOccerance(int arr[],int size,int target){
    int s =0;
    int e = size-1;

    int mid = s +(e-s)/2;

    int ans = -1;

    while(s <=e){
        if(arr[mid] == target){
            //aagr hame target mil gaya then here is the 2 steps 
            // store the ans;
            ans = mid;
            //move left
            e = mid - 1;
        }else if(target  > arr[mid]){
            s = mid+1;
        }else if(target <  arr[mid]){
            e = mid-1;
        }
        //update mid
        mid = s+(e-s)/2;
    }
    return ans;
}
int findlastOccerance(int arr[],int size,int target){
    int s =0;
    int e  =size-1;
    int mid = s+(e-s)/2;

    int ans = -1;

    while(s <= e){
        if(arr[mid] == target){
            ans = mid;
            s = mid+1;
        }else if(target > arr[mid]){
            s =mid+1;
        }else if(target < arr[mid]){
            e = mid -1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
} 
int findtotaloccurance(int arr[],int size,int target){
    int firstOcc = findfirstOccerance(arr,size,target);
    int lastOcc = findlastOccerance(arr,size,target);

    int total  = lastOcc - firstOcc + 1;
    return total;
}

int findmissingnumber(int arr[],int size){
    int s = 0;
    int e= size-1;
    int mid = s +(e-s)/2;
    int ans = -1;
    while(s <= e){
        
        int diff = arr[mid] - mid;
        if(diff == 1){
            s =mid+1;
        }
        else{
            //store the ans
            ans = mid;
            //move left
            e = mid - 1;
        }
        mid =s+(e-s)/2;
    }
    if(ans + 1 == 0)
        return size+1;

    return ans+1;
}

int main(){
//     int arr[] = {10,20,30,40,50,60,70,80,90};
//     int target= 10;
//     int size = 9;

//    int ansIndex =    findNumber(arr,size,target);

//    if(ansIndex == -1){
//     cout<<"Element not found "<<endl;
//    }else{
//     cout<< "Element found at Index " << ansIndex <<endl;
//    }



//    int arr[] = {10,20,30,30,30,40,40,50};
//    int target =40 ;
//    int size = 8;


//    int ans = findtotaloccurance( arr, size, target);
//    cout<<"total occrance is "<<ans<<endl;
   


//    int ansIndex =    findfirstOccerance(arr,size,target);
//    int ansIndex =    findlastOccerance(arr,size,target);

//    if(ansIndex == -1){
//     cout<<"Element not found "<<endl;
//    }else{
//     cout<< "Element found at Index " << ansIndex <<endl;
//    }

int  arr[] = {1,3,4,5,6,7,8,9};
int size = 8;

cout<<findmissingnumber(arr,size)<<endl;
   

}