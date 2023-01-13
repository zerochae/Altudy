#include <bits/stdc++.h>
using namespace std;

int m, s;

int sharkX, sharkY;

int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int sharkDx[5] = {0, -1, 0, 1, 0};
int sharkDy[5] = {0, 0, -1, 0, 1};

bool ch[6][6] = {0};
int fishSmell[6][6];

vector<int> fishes[6][6];

vector<int> copy_fishes[6][6];

vector<int> tmp_fishes[6][6];

int tmpNumber = 0;

void copySpellCasting()
{

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            copy_fishes[i][j] = fishes[i][j];
        }
    }
}

int rotateDir(int dir)
{
    if (dir == 1)
        return 8;

    return dir - 1;
}

void fishMove()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            tmp_fishes[i][j].clear();
        }
    }

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            for (int k = 0; k < fishes[i][j].size(); k++)
            {
                int dir = fishes[i][j][k];
                int firstDir = fishes[i][j][k];
                int count = 0;

                bool isMove = 0;
                while (true)
                {
                    if (isMove == 1 || count == 8)
                    {

                        tmp_fishes[i][j].push_back(dir);
                        break;
                    }

                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    count += 1;

                    if (nx < 1 || ny < 1 || ny > 4 || nx > 4)
                    {
                        dir = rotateDir(dir);
                        continue;
                    }
                    if (nx == sharkX && ny == sharkY)
                    {
                        dir = rotateDir(dir);
                        continue;
                    }
                    if (fishSmell[nx][ny] > 0)
                    {
                        dir = rotateDir(dir);
                        continue;
                    }
                    isMove = 1;
                    tmp_fishes[nx][ny].push_back(dir);
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            fishes[i][j] = tmp_fishes[i][j];
        }
    }
}

int sharkDFS(int k, int x, int y, int sum)
{
    if (k == 3)
    {
        if (tmpNumber < sum)
        {
            tmpNumber = sum;

            // cout << k << " " << x << " " << y << " " << sum << "\n";
        }
        return 0;
    }

    for (int i = 1; i <= 4; i++)
    {
        int nx = x + sharkDx[i];
        int ny = y + sharkDy[i];

        if (nx < 1 || ny < 1 || nx > 4 || ny > 4)
            continue;
        int fishSize = fishes[nx][ny].size();
        if (ch[nx][ny] == 1)
        {
            fishSize = 0;
            continue;
        }
        ch[nx][ny] = 1;
        sharkDFS(k + 1, nx, ny, sum + fishSize);
        ch[nx][ny] = 0;
    }

    return 0;
}

int calculateMaxFish()
{
    fill(&ch[0][0], &ch[5][6], 0);
    tmpNumber = 0;
    int count = 0;
    sharkDFS(0, sharkX, sharkY, 0);
    count = max(count, tmpNumber);

    return count;
}

int calculateSharkMove(int first, int second, int third)
{
    int count = 0;
    fill(&ch[0][0], &ch[5][6], 0);

    int movement[3] = {first, second, third};

    int nx = sharkX;
    int ny = sharkY;

    for (int i = 0; i < 3; i++)
    {
        nx += sharkDx[movement[i]];
        ny += sharkDy[movement[i]];

        if (nx < 1 || ny < 1 || nx > 4 || ny > 4)
            return -11;
        int fishSize = fishes[nx][ny].size();
        if (ch[nx][ny] == 1)
        {
            continue;
        }
        ch[nx][ny] = 1;

        count += fishSize;
    }

    return count;
}

tuple<int, int, int> findSharkMovement(int fishCount)
{

    vector<int> numbers;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            for (int k = 1; k <= 4; k++)
            {
                if (fishCount == calculateSharkMove(i, j, k))
                {
                    int sum = i * 100 + j * 10 + k;
                    numbers.push_back(sum);
                }
            }
        }
    }
    sort(numbers.begin(), numbers.end());

    int number = numbers[0];
    int f = number / 100;
    number = number - f * 100;
    int s = number / 10;
    number -= s * 10;
    int t = number;

    return {f, s, t};
}

void sharkMove(tuple<int, int, int> movement)
{
    int first = get<0>(movement);
    int second = get<1>(movement);
    int third = get<2>(movement);

    // cout << "상어 이동경로 :" << first << " " << second << " " << third << "\n";

    int moves[3] = {first, second, third};

    int nx = sharkX;
    int ny = sharkY;

    for (int i = 0; i < 3; i++)
    {
        nx += sharkDx[moves[i]];
        ny += sharkDy[moves[i]];

        if (fishes[nx][ny].size() > 0)
        {
            fishes[nx][ny].clear();
            fishSmell[nx][ny] = 3;
        }
    }

    sharkX = nx;
    sharkY = ny;
}

void decreaseSmell()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (fishSmell[i][j] > 0)
            {
                fishSmell[i][j] -= 1;
            }
        }
    }
}

void copySpellDone()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            for (int k = 0; k < copy_fishes[i][j].size(); k++)
            {
                int dir = copy_fishes[i][j][k];
                fishes[i][j].push_back(dir);
            }
            copy_fishes[i][j].clear();
        }
    }
}

int calculateAnswer()
{
    int ans = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            ans += fishes[i][j].size();
        }
    }
    return ans;
}

void printFish()
{
    cout << "\n";
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cout << fishes[i][j].size() << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void printFishDetail()
{
    cout << "\n";
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cout << "\n";
            cout << "좌표 : " << i << " " << j << "\n";
            cout << "\n";
            for (int k = 0; k < fishes[i][j].size(); k++)
            {
                cout << fishes[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printSmell()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cout << fishSmell[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> s;

    for (int i = 0; i < m; i++)
    {
        int x, y, dir;
        cin >> x >> y >> dir;
        fishes[x][y].push_back(dir);
    }

    cin >> sharkX >> sharkY;

    while (s--)
    {
        copySpellCasting();

        fishMove();

        int maxFishCount = calculateMaxFish();
        tuple<int, int, int> sharkMovement = findSharkMovement(maxFishCount);

        sharkMove(sharkMovement);

        decreaseSmell();
        copySpellDone();
    }

    cout << calculateAnswer();
}
