#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[1000000 + num]++;
    }

    for (int i = 0; i <= 2000000; i++)
    {
        if (arr[i] > 0)
        {
            while (arr[i]--)
            {
                cout << i - 1000000 << "\n";
            }
        }
    }
}
