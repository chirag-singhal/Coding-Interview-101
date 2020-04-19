#include <bits/stdc++.h>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int pivot = 0;
        int lo = 0, hi = nums.size() - 1;
        
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            int num = nums[mid];
            int l1 = nums[lo];
            int l2 = nums[hi];
            if(num == target) return mid;
            else if(l1 <= num) {
                if(target >= l1 && target < num)
                    hi = mid - 1;
                else 
                    lo = mid + 1;
            }
            else {
                if(l2 >= target && target > num)
                    lo = mid + 1;
                else
                    hi = mid - 1;    
            }
        }
        return -1;
    }
};