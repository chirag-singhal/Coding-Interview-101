## [Next Permutation](https://leetcode.com/problems/next-permutation/description/)

### Problem Link - https://leetcode.com/problems/next-permutation/description/

---

### Solution

```cpp

    class Solution {
    public:
        int binarySearch(vector<int>& nums, int x, int idx) {
            int lo = idx;
            int hi = nums.size() - 1;
            while(lo <= hi) {
                int mid = (lo + hi) / 2;
                if(nums[mid] <= x)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            return hi;
        }
        void reverse(vector<int>& nums, int idx) {
            for(int i = idx; i < idx + (nums.size() - idx) / 2; i++) {
                int temp = nums[i];
                nums[i] = nums[nums.size() + idx - i - 1];
                nums[nums.size() + idx - i - 1] = temp;
            }
        }
        void nextPermutation(vector<int>& nums) {
            if(nums.size() == 1)
                return;
            for(int i = nums.size() - 2; i >= 0; i--) {
                if(nums[i] < nums[i + 1]) {
                    int idx = binarySearch(nums, nums[i], i + 1);
                    int temp = nums[i];
                    nums[i] = nums[idx];
                    nums[idx] = temp;
                    reverse(nums, i + 1);
                    return;
                }
            }
            reverse(nums, 0);
        }
    };


```