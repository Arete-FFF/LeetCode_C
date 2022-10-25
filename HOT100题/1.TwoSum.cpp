#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); i++){
//             for (int j = i ; j < nums.size(); j++){
//                 if(nums[i] + nums[j] == target){
//                     cout << "[" << i << "," << j << "]" << endl;
//                 }
//             }
//         }
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> result;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = result.find(target - nums[i]);
            if (it != result.end()) {
                return {it->second, i};
            }
            result[nums[i]] = i;
        }
        return {};
    }
};


int main(){
    Solution t;
    vector<int> nums ;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    t.twoSum(nums, 9);
}