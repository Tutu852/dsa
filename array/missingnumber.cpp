#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums) {
    int sum = 0;
    int n = nums.size();

    // Calculating the sum of all elements in nums
    for (int index = 0; index < n; index++) {
        sum = sum + nums[index];
    }

    // Calculating the total sum of a sequence of numbers from 0 to n
    int totalSum = ((n) * (n + 1)) / 2;

    // The missing number is the difference between the total sum and the sum of elements in nums
    int ans = totalSum - sum;

    return ans;
}

int main() {
    std::vector<int> nums = {3, 0, 1};
    int missing = missingNumber(nums);
    std::cout << "The missing number is: " << missing << std::endl;
    return 0;
}
