## [Valid Mountain Array](https://leetcode.com/problems/valid-mountain-array/)

### Problem Link - https://leetcode.com/problems/valid-mountain-array/

---

### Solution

```cpp

    class Solution {
    public:
        bool validMountainArray(vector<int>& arr) {
            if(arr.size() < 3)
                return false;
            int i = 0;
            while(i < arr.size() - 1 && arr[i] < arr[i + 1])
                i++;
            if(i == arr.size() - 1 || i == 0)
                return false;
            while(i < arr.size() - 1 && arr[i] > arr[i + 1])
                i++;
            if(i == arr.size() - 1)
                return true;
            return false;
        }
    };

```