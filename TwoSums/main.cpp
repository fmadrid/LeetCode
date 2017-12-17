#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
		  vector<int> idx(nums.size());
		  for(int i = 0; i < nums.size(); i++)
			  idx[i] = i;
		  
		  sort(idx.begin(), idx.end(), [&nums](size_t i1, size_t i2) {return nums[i1] < nums[i2];});
        
		  vector<int> sol;
		  
        std::sort(nums.begin(), nums.end());
        
        auto front = nums.begin();
        auto back = nums.end() - 1;
        
        while(true) {
            int sum = *front + *back;
				
            if(sum == target)	return {idx[front - nums.begin()],idx[back - nums.begin()]};
            if(sum > target)  back--;
            if (sum < target) front++;

        }
        
    }
    
};

int main() {
	
	Solution s;
	vector<int> vec = {3,2,4};
	for(int n : s.twoSum(vec, 6))
		cout << n << " ";
	
	return 0;
	
}