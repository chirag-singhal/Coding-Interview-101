
#include <iostream>

int main() {
    int t;
    char d; int dig, prev;
    long long N;
    std::cin >> t; 
    std::cin.get(c);
    while(t) {
        bool removed = false;
        N = 0;
        std::cin.get(d);
        prev = d - '0';
        while(std::cin.get(d)) {
            if (d == '\n') {
                if (removed) {
                    N = N*10 + prev;
                }
                break;
            }
            else {
                dig = c - '0';

                if (prev <= dig || removed) {

                    N = N*10 + prev;
                }
                else {
                    removed = true;
                }
                prev = dig;
            }
        }

        std::cout << N << "\n";

        --t;
    }
    return 0;

}