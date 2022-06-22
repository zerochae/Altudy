#include <bits/stdc++.h>
using namespace std;

int n;

int arr[100005];
int d[100005];

queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    fill(d, d + n, 999);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    d[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int num = arr[i - 1];
        for (int j = i; j >= 0; j--)

        {
            // cout << i - j << " " << arr[i - j] << " " << j << "\n";
            if (arr[i - j] >= j)
            {
                d[i] = min(d[i], d[i - j] + 1);
            }
            // cout << j << " " << num << " " << i
            //      << "\n";
        }
        // cout << d[i] << "\n";
    }
    if (d[n - 1] == 999)
    {
        cout << -1;
    }
    else
    {

        cout << d[n - 1];
    }
}

/*

5
1 2 5 1 1

d[0]=0;  arr[0]=1;
d[1]=1; arr[1]=2;
d[2]=2; arr[2]=5;

i에 0부터 i-1까지 올수 있는지 확인해

없으면 d[i]=-1;
있으면 d[i]= d[j]+1;


d[3]=2;
d[4]=2;
d[5]=2;

*/