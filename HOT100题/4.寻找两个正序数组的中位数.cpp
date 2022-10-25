#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//  1 
//  1 2 3 4 5 6
// index
// int findK(vector<int> &arr, int begin, int end, int k) {
//     int p = arr[begin];
//     int l=begin, r=end;
//     while (l<r) {
//         while (l<r && arr[r]>=p) {
//             r--;
//         }
//         while (l<r && arr[l]<=p) {
//             l++;
//         }
//         swap(arr[l], arr[r]);
//     }
//     swap(arr[begin], arr[l]);
//     int n = l-begin+1;
//     // findK(arr, begin, l-1, 0);
//     // findK(arr, l+1, end, 0);
//     if (n==k) {
//         return arr[l];
//     } else (if n>k) {
//         return findK(arr, begin, l-1, k);
//     } else {
//         return findK(arr, l+1, end, k-n)
//     }
// }
// val
    int findkk(vector<int>& arr1, vector<int>& arr2, int begin1, int begin2, int k) {
        if (begin1>=arr1.size()) {
            return arr2[begin2+k-1];
        }
        if (begin2>=arr2.size()) {
            return arr1[begin1+k-1];
        }

        if (k==1) {
            return min(arr1[begin1], arr2[begin2]);
        }    



        int mid = k/2;
        int idx1 = min(begin1+mid-1, int(arr1.size()-1)), idx2 = min(begin2+mid-1, int(arr2.size()-1));

        if (arr1[idx1] < arr2[idx2]) {
            return findkk(arr1, arr2, idx1+1, begin2, k-(idx1-begin1+1));
        } else {
            return findkk(arr1, arr2, begin1, idx2+1, k-(idx2-begin2+1));
        }

    } 

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if (size&1) {
            int k = size/2+1;
            return findkk(nums1, nums2, 0, 0, k);

        } else {
            int k1=size/2, k2 = k1+1;
            double v1 = findkk(nums1, nums2, 0, 0, k1), v2 = findkk(nums1, nums2, 0, 0, k2);
            return (v1+v2)/2;
        }
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if (nums1[i] < nums2[j]){
                merge.push_back(nums1[i]);
                i++;
            }
            else{
                merge.push_back(nums2[j]);
                j++;
            }
        }
        if (i == nums1.size()){
            while(j<nums2.size()){
                merge.push_back(nums2[j]);
                j++;
            }
        }
        else{
            while(i<nums1.size()){
                merge.push_back(nums1[i]);
                i++;
            }
        }
        return merge.size() % 2 ? merge[merge.size()/2] : float(merge[merge.size()/2] + merge[merge.size()/2 -1])/2;
    }
};


int main(){
    Solution t;
    vector<int> a = {1,2,3};
    vector<int> b = {4,5};
    cout << t.findMedianSortedArrays(a, b) << endl;
}