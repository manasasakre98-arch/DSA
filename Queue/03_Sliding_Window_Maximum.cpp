#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution{
public: 
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        deque<int> dq;
        vector<int> result;

        for(int i = 0;i < nums.size(); i++){
            if(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = { 1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Input: [";
    for(size_t i=0;i<nums.size();i++){
        cout << nums[i] << (i+1 < nums.size() ? ", ": "");
    }
    cout << "], k = " << k << endl;

    cout << "Output: [";
    for(size_t i =0; i<result.size();i++){
        cout << result[i] << (i + 1 < result.size() ? ", ": "");
    }
    cout << "]" << endl;

    return 0;
}