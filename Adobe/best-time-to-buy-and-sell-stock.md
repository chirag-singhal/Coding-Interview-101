## [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

### Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

---

### Solution

```cpp

    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int maxProfit = 0;
            int maxPrice = prices[prices.size() - 1];
            for(int i = prices.size() - 2; i >= 0; i--) {
                maxProfit = max(maxProfit, maxPrice - prices[i]);
                maxPrice = max(maxPrice, prices[i]);
            }
            return maxProfit;
        }
    };
    

```