#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[12][12];
int state[12][12];
bool ch[12][12];
int minBridge[12][12];
int d[120][120];

bool sel[12][12] = {0};

int parent[7];
vector<int> graph[7];
vector<tuple<int, int, int>> vec; // {거리 , 섬1 ,섬2}

bool bridgeCh[12][12][4];

int island_visit[7];

queue<tuple<int, int, int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int createIsland()
{
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == 1 && ch[i][j] == 0)
            {
                ch[i][j] = 1;
                idx++;
                q.push({i, j, idx});

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    int x = get<0>(cur);
                    int y = get<1>(cur);
                    int index = get<2>(cur);

                    state[x][y] = index;

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                            continue;
                        if (ch[nx][ny] == 1 || arr[nx][ny] == 0)
                            continue;
                        ch[nx][ny] = 1;
                        q.push({nx, ny, index});
                    }
                }
            }
        }
    }
    return idx;
}

void calculateMinBrdige(int number)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (state[i][j] == number)
            {
                for (int k = 0; k < 4; k++)
                {

                    int nx = i;
                    int ny = j;
                    int dist = 0;

                    while (true)
                    {
                        nx += dx[k];
                        ny += dy[k];

                        // 범위 이탈 또는 현재 섬일 경우 탈출

                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                            break;
                        if (state[nx][ny] == number)
                            break;

                        if (state[nx][ny] != 0)
                        {
                            vec.push_back({dist, number, state[nx][ny]});
                            break;
                        }
                        dist++;
                    }
                }
            }
        }
    }
}

int find(int u)
{
    if (u == parent[u])
        return u;
    else
        return find(parent[u]);
}

bool union_island(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u != v)
    {
        // 노드 결합
        parent[u] = v;

        // 섬 간의 연결관계 기록
        graph[u].push_back(v);
        graph[v].push_back(u);
        return true;
    }
    else
        return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // 초기 세팅
    for (int i = 1; i <= 6; i++)
        parent[i] = i; // 자기 자신을 부모로 지정

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int index = createIsland();

    fill(&minBridge[0][0], &minBridge[11][12], 100);

    for (int i = 1; i <= index; i++)
    {
        calculateMinBrdige(i);
    }

    int ans = 0;

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++)
    {
        int dist = get<0>(vec[i]);
        int isLand1 = get<1>(vec[i]);
        int isLand2 = get<2>(vec[i]);
    }

    // MST 구하기
    for (int i = 0; i < vec.size(); i++)
    {
        int dist = get<0>(vec[i]);
        int island_1 = get<1>(vec[i]);
        int island_2 = get<2>(vec[i]);

        // 다리길이가 2미만이면 패스!
        if (dist < 2)
            continue;

        // 두 섬간의 다리 건설 시
        if (union_island(island_1, island_2))
            ans += dist;
    }

    // 섬이 모두 연결되어 있는지 확인
    int cnt = 1;

    queue<int> isLandQ;
    isLandQ.push(1);

    while (!isLandQ.empty())
    {
        int now_island = isLandQ.front();
        isLandQ.pop();
        island_visit[now_island] = true;

        for (int i = 0; i < graph[now_island].size(); i++)
        {
            int next_island = graph[now_island][i];
            if (!island_visit[next_island])
            {
                isLandQ.push(next_island);
                cnt++;
            }
        }
    }

    if (cnt != index)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}