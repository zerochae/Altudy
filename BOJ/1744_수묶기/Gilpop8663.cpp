#include <bits/stdc++.h>
using namespace std;

int n;

int arr[55];
bool ch[55];

vector<int> postive;
vector<int> negative;

bool func(int a, int b)
{
    return a < b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int ans = 0;
    int zeroCnt = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num > 0 && num != 1)
        {
            postive.push_back(num);
        }
        else if (num < 0)
        {
            negative.push_back(num);
        }
        else if (num == 1)
        {
            ans++;
        }
        else if (num == 0)
        {
            zeroCnt++;
        }
    }

    sort(postive.begin(), postive.end(), greater<int>());
    sort(negative.begin(), negative.end(), less<int>());

    for (int i = 0; i < postive.size() - (postive.size() % 2); i += 2)
    {
        ans += postive[i] * postive[i + 1];
    }

    if (postive.size() % 2 == 1)
    {
        ans += postive.back();
    }

    for (int i = 0; i < negative.size() - (negative.size() % 2); i += 2)
    {
        ans += negative[i] * negative[i + 1];
    }

    if (negative.size() % 2 == 1)
    {
        if (zeroCnt == 0)
        {
            ans += negative.back();
        }
    }
    cout << ans;
}
