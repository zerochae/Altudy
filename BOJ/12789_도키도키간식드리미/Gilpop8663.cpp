#include <bits/stdc++.h>
using namespace std;

int n;

int arr[1005];
int arr2[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> arr[i];
    }
    int cnt = 1;
    int fIndex = 0;
    int sIndex = 0;
    for (int i = 0; i < 2 * n; i++)
    {

        if (arr[fIndex] == cnt)
        {
            // cout << arr[fIndex] << " " << cnt << "\n";
            cnt++;
            fIndex++;
        }
        else if (arr2[sIndex - 1] == cnt)
        {
            // cout << arr2[sIndex - 1] << " " << cnt << "\n";
            cnt++;
            sIndex--;
        }
        else
        {
            arr2[sIndex++] = arr[fIndex++];
        }

        // cout << arr[fIndex] << " " << fIndex << " " << arr2[sIndex - 1] << " " << sIndex << " " << cnt << "\n";
    }

    bool isNice = cnt == n + 1;

    // cout
    //     << cnt;

    if (isNice == 1)
    {
        cout << "Nice";
    }
    else
    {
        cout << "Sad";
    }
}
