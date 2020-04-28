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

int compare(Interval a, Interval b) {
    return a.start < b.start;
}

std::vector<Interval> merge(std::vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    std::stack<Interval> s;
    int count = 0;
    std::sort(A.begin(), A.end(), compare);
    for(int i = 0; i < A.size(); i++) {
        if(!s.empty() && s.top().end >= A[i].start) {
            Interval in = s.top();
            s.pop();
            if(A[i].end > in.end)
                s.push(Interval(in.start, A[i].end));
            else
                s.push(Interval(in.start, in.end));
        }
        else {
            s.push(A[i]);
            count++;
        }
    }
    std::vector<Interval> ans(count);
    for(int i = count - 1; i > -1; i--) {
        ans[i] = s.top();
        s.pop();
    }
    return ans;
}
