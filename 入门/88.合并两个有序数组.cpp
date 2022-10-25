#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> r;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                r.push_back(nums1[i]);
                i++;
            }
            else
            {
                r.push_back(nums2[j]);
                j++;
            }
        }
        if (i == m)
        {
            for (; j < n; j++)
            {
                r.push_back(nums2[j]);
            }
        }
        else
        {
            for (; i < m; i++)
            {
                r.push_back(nums1[i]);
            }
        }

        nums1 = r;
    }
};
