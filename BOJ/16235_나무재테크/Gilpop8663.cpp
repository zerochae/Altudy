#include <bits/stdc++.h>
using namespace std;

int n;

int m, k;

int nutrient[11][11];

int farm[11][11];

int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

vector<int> tree[11][11];

void springAndSummmer()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (tree[i][j].size() == 0)
                continue;
            sort(tree[i][j].begin(), tree[i][j].end());
            vector<int> newTree;

            int die = 0;
            for (auto plant : tree[i][j])
            {

                if (farm[i][j] >= plant)
                {
                    newTree.push_back(plant + 1);
                    farm[i][j] -= plant;
                }
                else
                {
                    die += plant / 2;
                }
            }
            tree[i][j].clear();
            for (auto updateTree : newTree)
            {
                tree[i][j].push_back(updateTree);
            }

            farm[i][j] += die; // 여름
        }
    }
    return;
}

bool OOP(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > n)
        return true;
    return false;
}

void fall()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (tree[i][j].size() == 0)
                continue;
            for (auto plant : tree[i][j])
            {
                if (plant % 5 == 0)
                {

                    for (int k = 0; k < 8; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (OOP(nx, ny))
                            continue;
                        tree[nx][ny].push_back(1);
                    }
                }
            }
        }
    }
    return;
}

void winter()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            farm[i][j] += nutrient[i][j];
        }
    }
    return;
}

void initFarm()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            farm[i][j] = 5;
        }
    }
}

void print()
{
    cout << "현재 땅의 양분"
         << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << farm[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
    cout << "겨울에 추가되는 땅의 양분"
         << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << nutrient[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
    cout << "나무 나이"
         << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (tree[i][j].size() > 0)
            {
                for (auto x : tree[i][j])
                {
                    cout << i << " " << j << " " << x << "\n";
                }
            }
    }
    cout << "\n";
}

int treeSize()
{

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (tree[i][j].size() > 0)
            {
                for (auto x : tree[i][j])
                {
                    cnt++;
                }
            }
    }

    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> nutrient[i][j];

    for (int i = 0; i < m; i++)
    {
        int x, y, age;
        cin >> x >> y >> age;
        tree[x][y].push_back(age);
    }

    initFarm();

    while (k--)
    {
        springAndSummmer();
        fall();
        winter();
    }

    // print();
    cout << treeSize();
}
