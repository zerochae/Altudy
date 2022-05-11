#include <bits/stdc++.h>
using namespace std;

// solution 1

/*

int n;
int d[505][505];

int arr[505];

int nums[125255];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    // 1 3 6 10 15
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + i;
    }
    // cout << arr[n];
    for (int i = 1; i <= arr[n]; i++)
    {
        cin >> nums[i];
    }


d[1][1] = nums[1];

for (int i = 2; i <= n; i++)
{
    for (int j = 1; j <= arr[i] - arr[i - 1]; j++)
    {
        d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + nums[arr[i - 1] + j];
        // cout << d[i][j] << " " << i << " " << j << "\n";
    }
    // cout << d[i] << "\n";
}

int ans = 0;
for (int i = 1; i <= arr[n] - arr[n - 1]; i++)
{
    ans = max(ans, d[n][i]);
}
cout << ans;
}
*/

// solution 2

int n;
int a[505][505], d[505][505];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            cin >> a[i][j];
    d[1][1] = a[1][1];
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
    cout << *max_element(d[n] + 1, d[n] + n + 1);
}

/*
      d[1] =                        nums[1];

      d[2] = d[1] +           nums[2]      , nums[3]

      d[3] = d[2] +      nums [4] , nums[5] ,      nums[6]

      d[4] = d[3]+  nums[7] , nums[8],   nums[9],       nums[10]


      d[1][1]
      d[2][1] d[2][2]
      d[3][1] d[3][2] d[3][3]
      d[4][1] d[4][2] d[4][3] d[4][4]
      ...
      d[i][j] = max(d[i-1][j-1] , d[i-1][j]) + nums[arr[i-1] + j];



      d[1][1] = nums[1];
      d[2][1] = d[1][1] +nums[2]
      d[2][2] = d[1][1] + nums[3];
      d[3][1] = d[2][1] + nums[4];
      d[3][2] = max(d[2][1],d[2][2])+ nums[5];
      d[3][3] = d[2][2] + nums[6];
      d[4][1] = d[3][4] +nums[7];
      d[4][2] = d[4]
      d[4][3] = d[4]
      d[4][4] = d[4]


      d[i][j] = d[i-1][j-1] ,



  */