#include <bits/stdc++.h>
using namespace std;

int n;

int arr[1000005];

int arr2[1000005];
int ans[1000005];

stack<int> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr2[arr[i]] += 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int num = arr[i];
        int height = arr2[num];

        while (!s.empty())
        {
            int topNum = arr[s.top()];
            int topHeight = arr2[topNum];

            if (height >= topHeight)
            {
                s.pop();
            }
            else
            {
                break;
            }
        }

        ans[i] = -1;

        if (!s.empty())
        {
            ans[i] = arr[s.top()];
        }

        s.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
