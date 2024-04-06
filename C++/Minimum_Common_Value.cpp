/*
2540. Minimum Common Value

Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.
Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
 
Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[j] <= 109
Both nums1 and nums2 are sorted in non-decreasing order.
*/

#include<bits/stdc++.h>
#include <vector>
using std::vector;

class Solution {
public:
    int binarySearch(vector<int>& nums, int l,int r,int x){
        if(l<=r){
            int m = (l+r)/2;
            if(nums[m] == x)
                return m;
            else if(nums[m] < x)
                return binarySearch(nums,m+1,r,x);
            else
                return binarySearch(nums,l,m-1,x);
        }
        return -1;
    }

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n;
        bool v1 = false;
        bool v2 = false;
        if(nums1.size()<nums2.size()){
            n = nums1.size();
            v1 = true;
        }
        else{
            n = nums2.size();
            v2 = true;
        }
        for(int i=0;i<n;i++){
            if(v1){
                int l = 0;
                int r = nums2.size()-1;
                int c = binarySearch(nums2,l,r,nums1[i]);
                if(c != -1)
                    return nums2[c];
            }
            if(v2){
                int l = 0;
                int r = nums1.size()-1;
                int c = binarySearch(nums1,l,r,nums2[i]);
                if(c != -1)
                    return nums1[c];
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2,4};
    Solution ans ;
    std :: cout << ans.getCommon(nums1,nums2) << std::endl;
    nums1 = {1,2,3,6};
    nums2 = {2,3,4,5};
    std :: cout << ans.getCommon(nums1,nums2) << std::endl;
}