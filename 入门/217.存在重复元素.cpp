#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }
        return false;

        // 哈希表  时间空间复杂度均为O(n)
        // unordered_set<int> s;
        // for (int x : nums)
        // {
        //     if (s.find(x) != s.end())
        //     {
        //         return true;
        //     }
        //     s.insert(x);
        // }
        // return false;
    }
};

int main()
{
    Solution t;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    printf("%s", t.containsDuplicate(nums) ? "true" : "false");

    return 0;
}
