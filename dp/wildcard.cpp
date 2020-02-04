#include <iostream>

int main() {
    int n, m;
    std::cout<<"Enter length of string : ";
    std::cin>>n;

    char str[n + 1];
    std::cout<<"Enter string : ";
    std::cin>>str;

    std::cout<<"Enter length of pattern : ";
    std::cin>>m;

    char pat[m + 1];
    std::cout<<"Enter pattern : ";
    std::cin>>pat;

    bool arr[n + 1][m + 1];
    
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <=m; j++)
            arr[i][j] = false;

    arr[0][0] = true;

    for(int i = 1; i <= m; i++)
        if(pat[i - 1] == '*')
            arr[0][i] = arr[0][i - 1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <=m; j++) {
            if(pat[j - 1] == '*')
                arr[i][j] = arr[i - 1][j] || arr[i][j - 1];
            else if(pat[j - 1] == '?' || pat[j - 1] == str[i - 1])
                arr[i][j] = arr[i - 1][j - 1];
            else arr[i][j] = false;
        }
    }

    if(arr[n][m])
        std::cout<<"TRUE"<<std::endl;
    else 
        std::cout<<"FALSE"<<std::endl;
    
    return 0;
}