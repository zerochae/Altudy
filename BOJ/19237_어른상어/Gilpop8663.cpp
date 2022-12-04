#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int arr[25][25];
int tmp[25][25];

struct shark
{
    int dir;
    int priority[5][5];
};

struct smellInfo
{
    int timer;
    int num;
};

shark v[405];
smellInfo s[25][25];
smellInfo c_s[25][25];

int ans = 0;

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

int detailMove(vector<int> &pos, int sNum)
{

    int sDir = v[sNum].dir;
    for (int j = 0; j < 4; j++)
        for (int i = 0; i < pos.size(); i++)
        {
            int pDir = pos[i];

            {
                if (v[sNum].priority[sDir][j] == pDir)
                {
                    return pDir;
                }
            }
        }

    return 0;
}

bool isOneShark()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > 1)
                return true;
        }
    }
    return false;
}

void move()
{
    //임시 배열 초기화
    fill(&tmp[0][0], &tmp[24][25], 0);

    ans++;

    //현재 냄새 배열 저장

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            c_s[i][j].num = s[i][j].num;
            c_s[i][j].timer = s[i][j].timer;
        }
    }

    // 상어 냄새 배열 1씩 감소

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i][j].num == 0)
                continue;

            if (s[i][j].timer > 0)
            {
                s[i][j].timer--;
            }

            if (s[i][j].timer == 0)
            {
                s[i][j].num = 0;
            }
        }
    }

    // 상어 이동

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
                continue;

            int sharkNum = arr[i][j];

            vector<int> emptyPos;
            vector<int> myPos;

            for (int k = 1; k <= 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if (c_s[nx][ny].num == 0 && c_s[nx][ny].timer == 0)
                {
                    emptyPos.push_back(k);
                }
                if (c_s[nx][ny].num == sharkNum)
                {
                    myPos.push_back(k);
                }
            }

            int newDir;
            if (!emptyPos.empty())
            {
                newDir = detailMove(emptyPos, sharkNum);
            }
            else
            {
                newDir = detailMove(myPos, sharkNum);
            }

            int nx = i + dx[newDir];
            int ny = j + dy[newDir];

            arr[i][j] = 0;

            if (s[nx][ny].num >= sharkNum || s[nx][ny].num == 0)
            {
                tmp[nx][ny] = sharkNum;
                v[sharkNum].dir = newDir;
                s[nx][ny].num = sharkNum;
                s[nx][ny].timer = k;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = tmp[i][j];
        }
    }
}

void print()
{
    cout << "상어 번호 배열"
         << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void smellPrint()
{
    cout << "상어 번호 냄새  배열"
         << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << s[i][j].num << " ";
        }
        cout << "\n";
    }
}

void timerPrint()
{
    cout << "상어 번호 시간 배열"
         << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << s[i][j].timer << " ";
        }
        cout << "\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] > 0)
            {
                s[i][j].num = arr[i][j];
                s[i][j].timer = k;
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int sharkDir;
        cin >> sharkDir;
        v[i].dir = sharkDir;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= 4; j++)
        {

            for (int k = 0; k < 4; k++)
            {
                int dir;
                cin >> dir;
                v[i].priority[j][k] = dir;
            }
        }
    }

    while (isOneShark())
    {
        if (ans > 1000)
            break;
        move();
    }

    if (ans > 1000)
    {
        ans = -1;
    }

    cout << ans;
}