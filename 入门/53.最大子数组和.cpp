#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 动态规划算法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

// 分治法
// class Solution {
// public:
//     struct Status {
//         int lSum, rSum, mSum, iSum;
//     };

//     Status pushUp(Status l, Status r) {
//         int iSum = l.iSum + r.iSum;
//         int lSum = max(l.lSum, l.iSum + r.lSum);
//         int rSum = max(r.rSum, r.iSum + l.rSum);
//         int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
//         return (Status) {lSum, rSum, mSum, iSum};
//     };

//     Status get(vector<int> &a, int l, int r) {
//         if (l == r) {
//             return (Status) {a[l], a[l], a[l], a[l]};
//         }
//         int m = (l + r) >> 1;
//         Status lSub = get(a, l, m);
//         Status rSub = get(a, m + 1, r);
//         return pushUp(lSub, rSub);
//     }

//     int maxSubArray(vector<int>& nums) {
//         return get(nums, 0, nums.size() - 1).mSum;
//     }
// };


int main(){
    Solution t;
    vector<int> nums ;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-3);
    nums.push_back(1);
    printf("%d", t.maxSubArray(nums));

    return 0;
}
