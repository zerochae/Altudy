#include <bits/stdc++.h>
using namespace std;

int n;

priority_queue<int, vector<int>, greater<int>> q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n * n; i++)
    {
        int num;
        cin >> num;
        if (q.size() < n)
        {
            q.push(num);
        }
        else if (q.size() >= n)
        {
            q.push(num);
            q.pop();
        }
    }
    // while (!q.empty())
    // {
    //     cout << q.top() << "\n";
    //     q.pop();
    // }
    cout << q.top();
    return 0;
}

/*


2
1 10
2 11


4

1 5 9  100
2 6 10 101
3 7 11 102
4 8 12 103

6

1 5 9  100
2 6 10 101
3 7 11 102
4 8 12 103
15 17 19 111
16 18 20 112
*/