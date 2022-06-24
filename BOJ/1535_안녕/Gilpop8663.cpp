#include <bits/stdc++.h>
using namespace std;

int n;

int answer = 0;

int arr1[22];
int arr2[22];

tuple<int, int, int> arr[22];

void func(int idx, int sum, int vital)
{

    if (idx >= n || vital <= 0)
    {

        if (vital > 0)
        {
            answer = max(answer, sum);
        }
        return;
    }

    func(idx + 1, sum + arr2[idx], vital - arr1[idx]);
    func(idx + 1, sum, vital);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    func(0, 0, 100);

    cout << answer;
}
