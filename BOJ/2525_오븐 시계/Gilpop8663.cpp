#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int curH, curM;

    cin >> curH >> curM;

    int cookM;

    cin >> cookM;

    while (cookM--)
    {
        curM++;

        if (curM == 60)
        {
            curM = 0;
            curH++;
        }

        if (curH == 24)
        {
            curH = 0;
        }
    }

    cout << curH << " " << curM;
}
