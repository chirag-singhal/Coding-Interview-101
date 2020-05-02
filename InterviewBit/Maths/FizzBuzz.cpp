#include <bits/stdc++.h>

std::vector<std::string> fizzBuzz(int A) {
    std::vector<std::string> ans;
    for(int i = 1; i <= A; i++) {
        if(i % 3 == 0 && i % 5 == 0)
            ans.push_back("FizzBuzz");
        else if(i % 3 == 0)
            ans.push_back("Fizz");
        else if(i % 5 == 0)
            ans.push_back("Buzz");
        else
            ans.push_back(std::to_string(i));
    }
    return ans;
}
