// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1;
        int hi = n;
        while(lo < hi) {
            int mid = (int)(((long)lo + (long)hi) / 2);
            if(isBadVersion(mid))
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        if(isBadVersion(lo))
            return lo;
        else
            return lo + 1;
    }
};