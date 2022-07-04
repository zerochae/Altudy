#include <bits/stdc++.h>
using namespace std;

int n;

int arr[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int plus, minus, multiply, divide;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> plus >> minus >> multiply >> divide;

    vector<int> sign;

    for (int i = 0; i < plus; i++)
    {
        sign.push_back(1);
    }
    for (int i = 0; i < minus; i++)
    {
        sign.push_back(2);
    }
    for (int i = 0; i < multiply; i++)
    {
        sign.push_back(3);
    }
    for (int i = 0; i < divide; i++)
    {
        sign.push_back(4);
    }

    int maxNum = -1e9;
    int minNum = 1e9;

    do
    {

        int cur = arr[0];

        // cout << cur << "\n";

        for (int i = 1; i < n; i++)
        {
            int num = arr[i];

            if (sign[i - 1] == 1)
            {
                cur += num;
            }
            else if (sign[i - 1] == 2)
            {
                cur -= num;
            }
            else if (sign[i - 1] == 3)
            {
                cur *= num;
            }
            else
            {
                cur /= num;
            }
        }

        // cout << cur << "\n";

        maxNum = max(maxNum, cur);
        minNum = min(minNum, cur);
    } while (next_permutation(sign.begin(), sign.end()));

    cout << maxNum << "\n";
    cout << minNum << "\n";
}
