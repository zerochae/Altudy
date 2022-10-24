#include <bits/stdc++.h>
using namespace std;

int t, n;

int arr[100005];
int state[100005];

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x)
{
    int cur = x;
    while (true)
    {
        state[cur] = x;
        cur = arr[cur];
        // 이번 방문에서 지나간 학생에 도달했을 경우

        if (state[cur] == x)
        {
            while (state[cur] != CYCLE_IN)
            {
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
        //이전 방문에서 지나간 학생에 도달했을 경우
        else if (state[cur] != 0)
            return;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        fill(state + 1, state + n + 1, 0);
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            if (state[i] == NOT_VISITED)
            {
                run(i);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (state[i] != CYCLE_IN)
                ans++;
        }

        cout << ans << "\n";
    }
}
