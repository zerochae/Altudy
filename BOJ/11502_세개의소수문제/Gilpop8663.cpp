#include <bits/stdc++.h>
using namespace std;

int t, n;

vector<int> arr;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for (int j = 2; j <= 1500; j++)
    {
        bool isPrime = 1;
        for (int i = 2; i * i <= j; i++)
        {
            if (j % i == 0)
            {
                isPrime = 0;
                continue;
            }
        }
        if (isPrime == 1)
        {
            arr.push_back(j);
            // cout << j << " ";
        }
    }

    while (t--)
    {
        cin >> n;

        bool isFind = 0;
        vector<int> ans;
        for (int i = 0; arr[i] < n; i++)
        {
            if (isFind == 1)
                break;
            for (int j = 0; arr[j] < n; j++)
            {
                if (isFind == 1)
                    break;
                for (int k = 0; arr[k] < n; k++)
                {
                    int num = arr[i] + arr[j] + arr[k];
                    // cout << num << "\n";

                    if (num == n)
                    {
                        // cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
                        isFind = 1;
                        ans.push_back(arr[i]);
                        ans.push_back(arr[j]);
                        ans.push_back(arr[k]);
                        sort(ans.begin(), ans.end());
                        for (int z = 0; z < 3; z++)
                        {
                            cout << ans[z] << " ";
                        }
                        cout << "\n";
                        break;
                    }
                }
            }
        }
    }
}
