#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int sumofminmaxfallwindowofsizek(vector<int>nums, int k) {
        deque<int>dq,dq2;
        int ans = 0;
        
        //first window of k size
        for(int i=0;i<k;i++){
            //chote element remove kardo
            //back se isiliye ki agar me front se karunga to phir mujhe usse aage baade element hi  milegi 
            //aagr me back se karu mujhe us ke left me use se chote element hi miliga
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            //bada element remove kardo
            while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
                dq2.pop_back();
            }
            //inserting index,so that we can checkout of window element
            dq.push_back(i);
            dq2.push_back(i);
        }
        ans += nums[dq.front()] + nums[dq2.front()];
        //remaining window ko process
        for(int i=k ; i<nums.size() ;i++){
        //store ans for window
            //out of windwo element remove kardo
            // removal
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            if(!dq2.empty() && i - dq2.front() >= k){
                dq2.pop_front();
            }
            //ab ferse current element k liyue chotte element ko remove kardo
             while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
             while(!dq2.empty() && nums[i] >= nums[dq2.back()]){
                dq2.pop_back();
            }
            //inserting index,so that we can chackout of window element
            dq.push_back(i);
            dq2.push_back(i);

            ans += nums[dq.front()] + nums[dq2.front()];
        }
            //current window ka ans store karna he
           
        return ans;
    };

int main(){
    vector<int>v{2,5,-1,7,-1,-1,-2};
    int k =4;

    cout<<sumofminmaxfallwindowofsizek(v,k)<<endl;
    return 0;
}