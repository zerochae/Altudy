#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[55][55];
int n, m;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            cin >> board[i][j];
            if (board[i][j] == 1)
                house.push_back({i, j});
            if (board[i][j] == 2)
                chicken.push_back({i, j});
        }
    }

    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin() + chicken.size() - m, 0); // 앞의 chicken.size() - m 칸은 0, 뒤의 m칸은 1

    // for (int i = 0; i < brute.size(); i++)
    // {
    //     cout << brute[i];
    // }

    int mn = 0x7f7f7f7f;
    int ap = 1;
    do
    {
        int dist = 0; // 도시의 치킨 거리를 저장할 변수
        for (auto h : house)
        {
            int tmp = 0x7f7f7f7f; // 집의 치킨 거리를 저장할 변수
            for (int i = 0; i < chicken.size(); i++)
            {
                if (brute[i] == 0)
                    continue;
                // cout << h.X << " " << h.Y << "\n";
                tmp = min(tmp, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y));
            }
            dist += tmp;
        }
        mn = min(mn, dist);
    } while (next_permutation(brute.begin(), brute.end()));
    cout << mn;
}
