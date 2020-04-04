#include <iostream>

bool checkYear(int year)
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;

    if (year % 4 == 0)
        return true;
    return false;
}

int findDay(int day, int month, int year)
{
    if (month == 1)
    {
        month = 13;
        year--;
    }
    if (month == 2)
    {
        month = 14;
        year--;
    }
    int q = day;
    int m = month;
    int k = year % 100;
    int j = year / 100;
    int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;
    return h;
}

int getLastDay(int m, int y)
{
    int leap = checkYear(y);
    if (m == 2 && leap)
        return 29;
    if (m == 2)
        return 28;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    else
        return 30;
}

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int m1, m2;
        long int y1, y2;
        std::cin >> m1 >> y1 >> m2 >> y2;
        long long int count = 0;
        if(m2 < 2) {
            m2 = 2;
            y2--;
        }
        else {
            m2 = 2;
        }
        if(m1 > 2) {
            m1 = 2;
            y1++;
        }
        else {
            m1 = 2;
        }
        while (y1 % 2800 != 0)
        {
            if (y1 == y2 + 1)
            {
                break;
            }
            int d1 = findDay(1, m1, y1);
            d1 = 7 - d1;
            int lastday = getLastDay(m1, y1);
            int d2 = findDay(lastday, m1, y1);
            if (d2 == 0)
                lastday -= 6 + 7;
            else if (d1 == 1)
                lastday -= 7;
            else
                lastday -= d2 - 1 + 7;
            // std::cout << y1<<"  "<< m1 << "    "<< d1 << "    "<<lastday <<std::endl;
            if (d1 + 10 > lastday)
                count++;
            y1++;
        }
        int fourcen = (y2 - y1) / 2800;
        // std::cout<<count<<std::endl;
        if (fourcen > 0)
        {
            long long int remcount = 616;
            // for (int j = 0; j < 2800; j++)
            // {
            //     int d1 = findDay(1, m1, y1 + j);
            //     d1 = 7 - d1;
            //     int lastday = getLastDay(m1, y1 + j);
            //     int d2 = findDay(lastday, m1, y1 + j);
            //     if (d2 == 0)
            //         lastday -= 6 + 7;
            //     else if (d1 == 1)
            //         lastday -= 7;
            //     else
            //         lastday -= d2 - 1 + 7;
            //     if (d1 + 10 > lastday)
            //         remcount++;
            //     y1++;
            // }
            count += remcount * (fourcen - 1);
            y1 += (fourcen - 1) * 2800;
            // std::cout<<fourcen<<remcount<<std::endl;
        }
            // std::cout<<y1<<std::endl;
        while (y1 < y2 + 1) {
            int d1 = findDay(1, m1, y1);
            d1 = 7 - d1;
            int lastday = getLastDay(m1, y1);
            int d2 = findDay(lastday, m1, y1);
            if (d2 == 0)
                lastday -= 6 + 7;
            else if (d1 == 1)
                lastday -= 7;
            else
                lastday -= d2 - 1 + 7;
            // std::cout << d1 << "    "<<lastday <<std::endl;
            if (d1 + 10 > lastday)
                count++;
           y1++;
        }
        std::cout << count << std::endl;
    }
    return 0;
}