#include <bits/stdc++.h>
using namespace std;

int n;

int tmp[100005];
vector<int> arr[100005];
bool ch[100005];

queue<int> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // cout << "\n";
    for (int i = 0; i < n - 1; i++)
    {
        int num1, num2;

        cin >> num1 >> num2;
        arr[num2].push_back(num1);
        arr[num1].push_back(num2);
    }

    q.push(1);
    ch[1] = 1;

    while (!q.empty())
    {
        int num = q.front();

        q.pop();

        // cout << num << " " << arr[num][0] << "\n";
        for (int i = 0; i < arr[num].size(); i++)
        {
            int number = arr[num][i];
            if (ch[number] == 1)
                continue;
            q.push(number);
            ch[number] = 1;
            tmp[number] = num;
            // cout << num << " " << arr[num][i] << "\n";
        }
    }
    // cout << "\n";
    for (int i = 2; i <= n; i++)
    {
        cout << tmp[i] << "\n";
    }
}
