#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        vector<int> re;
        for (auto i : nums1)
        {
            if (mp.find(i) == mp.end()) mp[i] = 1;
            else mp[i]++;
        }
        for (auto i : nums2)
        {
            if (mp.find(i) != mp.end() && mp.find(i)->second != 0)
            {
                mp[i]--;
                re.push_back(i);
            }
        }
        return re;
    }
};