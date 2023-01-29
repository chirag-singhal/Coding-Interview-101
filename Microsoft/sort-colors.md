## [Sort Colors](https://leetcode.com/problems/sort-colors/description/)

### Problem Link - https://leetcode.com/problems/sort-colors/description/

---

### Solution

```cpp

    class Solution {
    public:
        void swap(vector<int>& nums, int i, int j ) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        void sortColors(vector<int>& nums) {
            int lo = 0, hi = nums.size() - 1;
            int mid = 0;
            while(mid <= hi) {
                if(nums[mid] == 0) {
                    swap(nums, lo, mid);
                    lo++;
                    mid++;
                }
                else if(nums[mid] == 2) {
                    swap(nums, hi, mid);
                    hi--;
                }
                else {
                    mid++;
                }
            }
        }
    };
    

```