#include <bits/stdc++.h>
using namespace std;

string n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // cout << n;

    string ans;

    int cnt = 0;
    int flag = false;
    for (int i = 0; i < n.size(); i++)
    {
        if (flag == true)
        {
            break;
        }
        if (n[i] == '.')
        {

            while (cnt > 0)
            {
                if (cnt % 4 == 0 || cnt % 2 == 0)
                {

                    if (cnt - 4 >= 0)
                    {
                        ans += "AAAA";
                        cnt -= 4;
                    }
                    else if (cnt % 2 == 0)
                    {
                        ans += "BB";
                        cnt -= 2;
                    }
                }
                else
                {
                    cout << -1;
                    flag = true;
                    break;
                }
            }
            cnt = 0;
            ans += '.';
        }
        else if (n[i] == 'X')
        {
            cnt++;
        }
    }
    while (cnt > 0)
    {
        if (cnt % 4 == 0 || cnt % 2 == 0)
        {

            if (cnt - 4 >= 0)
            {
                ans += "AAAA";
                cnt -= 4;
            }
            else if (cnt % 2 == 0)
            {
                ans += "BB";
                cnt -= 2;
            }
        }
        else
        {
            cout << -1;
            flag = true;
            break;
        }
    }

    if (!flag)
    {

        cout << ans << "\n";
    }
}
