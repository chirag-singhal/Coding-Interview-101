#include <stdio.h>
#include <math.h>
int f[7] = {0, 1, 1, 2, 3, 5, 8};

int fib(unsigned long long int n)
{
    if (n == 0)
    {
        return 0; // F(0) = 0.
    }
    else if (n <= 2)
    {
        return 1;
    }
    else if (n <= 6)
        return f[n];
    else
    {
        if (n % 2)
        { // n is odd: F(n) = F(((n-1) / 2) + 1)^2 + F((n-1) / 2)^2
            unsigned int k = (n - 1) / 2;
            unsigned long long int a = fib(k) % 10;
            unsigned long long int b = fib(k + 1) % 10;
            return (a * a + b * b) % 10;
        }
        else
        { // n is even: F(n) = F(n/2) * [ 2 * F(n/2 + 1) - F(n/2) ]
            unsigned int k = n / 2;
            unsigned int a = fib(k) % 10;
            return (a * (2 * fib(k + 1) - a)) % 10;
        }
    }
}
int main(void)
{
    unsigned long long int t;
    unsigned long long int n;
    scanf("%llu", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%llu", &n);
        int smallestPower = 0;
        unsigned long long int pow = 1; 
        for (int j = 0;; j++)
        {
            pow *= 2;
            if (pow <= n)
                smallestPower = j + 1;
            else
                break;
        }
        printf("%d\n", fib((pow / 2) % 60 - 1));
    }
}