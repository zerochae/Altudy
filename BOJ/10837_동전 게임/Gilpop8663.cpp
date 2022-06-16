#include <bits/stdc++.h>
using namespace std;

int k, n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;

    for (int i = 0; i < n; i++)
    {
        int YH, DS;
        cin >> YH >> DS;

        if (YH == DS) // 둘의 점수가 같을 때
        {
            cout << 1 << "\n";
            continue;
        }
        else if (YH < DS)
        {                     // 영희가 동수보다 작을 때
            int pos = k - DS; // 2
            // 0+2 >= 2

            // cout << pos << " " << YH << " " << DS << "\n";
            if (YH + pos >= DS - 1)
            {
                cout << 1 << "\n";
                continue;
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if (YH > DS)
        {
            int pos = k - YH;

            if (DS + pos >= YH - 2)
            {
                cout << 1 << "\n";
                continue;
            }
            else
            {

                cout << 0 << "\n";
            }
        }
    }
}
