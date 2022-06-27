#include <bits/stdc++.h>
using namespace std;

int n;

int arr[12];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    vector<int> tmp;
    for (int i = 1; i <= n; i++)
    {
        tmp.push_back(i);
    }

    do
    {

        int isFind = 0;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < i; j++)
            {
                if (tmp[i] < tmp[j])
                {
                    cnt++;
                }
            }
            // for (int i = 0; i < n; i++)
            // {
            //     cout << tmp[i] << " ";
            // }
            // cout << "\n";

            // cout << tmp[i] << " " << cnt << "\n";
            if (cnt == arr[tmp[i]])
            {
                isFind++;
            }
            else
            {
                isFind = 0;
            }
        }

        // cout << isFind << "\n";
        if (isFind == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << tmp[i] << " ";
            }
        }
    } while (next_permutation(tmp.begin(), tmp.end()));
}