#include <bits/stdc++.h>
using namespace std;

int n, m, p;

int step[10];
int area[10];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int canExtend[1002][1002];

queue<tuple<int, int, int>> q[10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p;

    //각 플레이어의 이동횟수 입력
    for (int i = 1; i <= p; i++)
    {
        cin >> step[i];
    }

    //맵 입력
    char ch;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ch;

            if (ch == '.')
            {
                canExtend[i][j] = 1;
            }
            else if (ch == '#')
            {
                canExtend[i][j] = 0;
            }
            else
            {
                canExtend[i][j] = 0;
                q[ch - '0'].push({i, j, 0}); // 각 플레이어의 초기 영토 기록
                area[ch - '0'] += 1;
            }
        }
    }

    //게임 시작

    while (1)
    {
        bool isExtend = 0;

        // 1 ~ P까지 순차적인 영토 확장

        for (int i = 1; i <= p; i++) // 각 플레이어 마다 진행
        {

            queue<tuple<int, int, int>> nextq; // 다음턴에 확장을 고려할 영토 기록
            while (!q[i].empty())
            {
                int curx, cury, curstep;
                tie(curx, cury, curstep) = q[i].front(); // 순차적으로 뽑음;
                q[i].pop();
                if (curstep >= step[i])
                { // 현재 내가 이동할 수 있는 거리보다 크거나 같다면 멈추고  0 으로 초기화 하는 동시에 다음 턴에 넣어주어야 한다
                    nextq.push({curx, cury, 0});
                    continue;
                }
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = curx + dx[dir], ny = cury + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (canExtend[nx][ny] == 0)
                        continue;
                    q[i].push({nx, ny, curstep + 1});
                    canExtend[nx][ny] = 0;
                    area[i]++;
                    isExtend = 1; // 확장했다는 의미
                }
            }
            q[i] = nextq; // 플레리어의 큐를 다음턴으로 교체함
        }

        if (!isExtend)
            break; // 아무도 영토를 확장하지 못하고 게임이 끝날수도 있으니 체크
    }
    //각 플레이어의 영토 출력

    for (int i = 1; i <= p; i++)
    {
        cout << area[i] << " ";
    }
}
