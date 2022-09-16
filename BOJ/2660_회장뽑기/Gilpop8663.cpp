#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> arr[55];

bool ch[55] = {0};

int score[55];

int func(int start)
{
    int cnt = 0;
    fill(ch, ch + 51, 0);
    queue<pair<int, int>> q;
    ch[start] = 1;
    q.push({start, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int num = cur.first;
        int curCnt = cur.second;

        cnt = max(cnt, curCnt);

        for (int i = 0; i < arr[num].size(); i++)
        {
            int next = arr[num][i];

            if (ch[next] == 1)
                continue;
            ch[next] = 1;
            q.push({next, curCnt + 1});
        }
    }

    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int num1, num2;

    while (cin >> num1 >> num2)
    {
        if (num1 == -1 && num2 == -1)
            break;

        arr[num1].push_back(num2);
        arr[num2].push_back(num1);
    }

    int minScore = 1e9;
    vector<int> president;

    for (int i = 1; i <= n; i++)
    {

        score[i] = func(i);

        if (score[i] < minScore)
        {
            minScore = score[i];
            president.clear();
            president.push_back(i);
        }
        else if (score[i] == minScore)
        {
            president.push_back(i);
        }
    }

    cout << minScore << " " << president.size() << "\n";
    for (int i = 0; i < president.size(); i++)
    {
        cout << president[i] << " ";
    }
}
