#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr1[1000000];
int arr2[1000000];
int arr3[2000000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    int idx1 = 0;
    int idx2 = 0;

    for (int i = 0; i < n + m; i++)
    {
        if (idx1 >= n)
        {
            arr3[i] = arr2[idx2++];
        }
        else if (idx2 >= m)
        {
            arr3[i] = arr1[idx1++];
        }
        else if (arr1[idx1] <= arr2[idx2])
        {
            arr3[i] = arr1[idx1++];
        }
        else
        {
            arr3[i] = arr2[idx2++];
        }
        // cout << idx1 << " " << idx2 << "\n";
    }
    for (int i = 0; i < n + m; i++)
        cout << arr3[i] << " ";
}