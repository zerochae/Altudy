#include <bits/stdc++.h>
using namespace std;

int L, P, V;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 1;
    while (true)
    {
        cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0)
            break;

        int day = L * (V / P);
        if (V % P <= L)
            day += V % P;
        else
            day += L;
        cout << "Case " << cnt++ << ": " << day << "\n";
    }
}
