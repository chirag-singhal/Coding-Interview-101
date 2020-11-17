#include <bits/stdc++.h>

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
std::vector<Interval> insert(std::vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = intervals.size();
    bool done = false;
    std::vector<Interval> ans; 
    
    for(int i = 0; i < n; i++) {
        if(!done && newInterval.start <= intervals[i].end) {
            int j = i;
            int start, end;
            while(j < intervals.size() && intervals[j].start < newInterval.end)
                j++;
            if(intervals[i].start <= newInterval.start)
                start = intervals[i].start;
            else
                start = newInterval.start;
            if(j == 0)
                end = newInterval.end;
            else if(intervals[j - 1].end >= newInterval.end)
                end = intervals[j - 1].end;
            else
                end = newInterval.end;
            ans.push_back(Interval(start, end));
            done = true;
            i = j - 1;
        }
        else 
            ans.push_back(intervals[i]);
    }
    if(!done)
        ans.push_back(newInterval);
    return ans;
}
