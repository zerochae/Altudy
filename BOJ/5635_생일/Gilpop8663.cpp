#include <bits/stdc++.h>
using namespace std;

int n;

int d[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int minYear = 1989, maxYear = 2011;
    int minMon = 0, maxMon = 13;
    int minDay = 0, maxDay = 31;

    string minName, maxName;

    for (int i = 0; i < n; i++)
    {
        string name;
        int day, mon, year;

        cin >> name >> day >> mon >> year;

        if (minYear < year)
        {

            minYear = year;
            minMon = mon;
            minDay = day;
            minName = name;
        }
        else if (minYear == year)
        {

            if (minMon < mon)
            {
                minYear = year;
                minMon = mon;
                minDay = day;
                minName = name;
            }

            if (minMon == mon)
            {

                if (minDay < day)
                {
                    minYear = year;
                    minMon = mon;
                    minDay = day;
                    minName = name;
                }
            }
        }

        if (maxYear > year)
        {
            maxYear = year;
            maxMon = mon;
            maxDay = day;
            maxName = name;
        }
        else if (maxYear == year)
        {

            if (maxMon > mon)
            {
                maxYear = year;
                maxMon = mon;
                maxDay = day;
                maxName = name;
            }
            else if (maxMon == mon)
            {
                if (maxDay > day)
                {
                    maxYear = year;
                    maxMon = mon;
                    maxDay = day;
                    maxName = name;
                }
            }
        }
    }

    cout << minName << "\n"
         << maxName;
}
