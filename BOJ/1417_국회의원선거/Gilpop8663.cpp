#include <bits/stdc++.h>
using namespace std;

int n;

int arr[100];

bool comp(int a, int b)
{
    return a > b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n, comp);

    int cnt = 0;
    bool flag = 0;
    while (true)
    {

        bool isBig = 0;
        if (flag == 1)
        {
            break;
        }
        int max = 0;
        int maxI = -1;
        for (int i = 0; i < n; i++)
        {

            if (max <= arr[i])

            {
                max = arr[i];
                maxI = i;
            }
        }

        if (maxI == 0)
        {
            break;
        }
        else
        {
            arr[0]++;
            isBig = 1;
            arr[maxI]--;
            cnt++;
        }

        if (isBig == 0)
        {
            flag = 1;
        }
    }
    cout << cnt;
}
