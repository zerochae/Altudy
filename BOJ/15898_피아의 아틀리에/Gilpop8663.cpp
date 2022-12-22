#include <bits/stdc++.h>
using namespace std;

int n;

int answer = 0;

int arr[11][5][5][4];

char sArr[11][5][5][4];

bool state[11] = {0};

int bucket[6][6];
char sBucket[6][6];

int reBucket[6][6];
char reSBucket[6][6];

int tmpMatter[5][5];
char tmpSMatter[5][5];

int tmpRot[5][5];
char tmpSRot[5][5];

const char S_WHITE = 'W';
const char S_RED = 'R';
const char S_BLUE = 'B';
const char S_GREEN = 'G';
const char S_YELLOW = 'Y';

void initBucket()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            bucket[i][j] = 0;
            sBucket[i][j] = S_WHITE;
        }
    }
}

void printBucket()
{
    cout << "\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << bucket[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << sBucket[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void initTmpMatter(int order, int dir)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tmpMatter[i][j] = arr[order][i][j][dir];
            tmpSMatter[i][j] = sArr[order][i][j][dir];
        }
    }
}

int calculate()
{
    int red = 0, blue = 0, green = 0, yellow = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sBucket[i][j] == S_RED)
            {
                red += bucket[i][j];
            }
            else if (sBucket[i][j] == S_BLUE)
            {
                blue += bucket[i][j];
            }
            else if (sBucket[i][j] == S_GREEN)
            {
                green += bucket[i][j];
            }
            else if (sBucket[i][j] == S_YELLOW)
            {
                yellow += bucket[i][j];
            }
        }
    }

    int bomb = 7 * red + 5 * blue + 3 * green + 2 * yellow;

    return bomb;
}

void pushMatter(int x, int y)
{
    for (int i = x; i < x + 4; i++)
    {
        for (int j = y; j < y + 4; j++)
        {
            int num = bucket[i][j] + tmpMatter[i - x][j - y];

            if (num < 0)
            {
                num = 0;
            }
            else if (num > 9)
            {
                num = 9;
            }

            bucket[i][j] = num;
            char color = tmpSMatter[i - x][j - y];
            if (color == S_WHITE)
                continue;
            sBucket[i][j] = color;
        }
    }
}

void rotateArr(int num, int dir)
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[num][i][j][dir] = arr[num][3 - j][i][dir - 1];
            sArr[num][i][j][dir] = sArr[num][3 - j][i][dir - 1];
        }
    }

    return;
}

void initRecoverBucket(vector<vector<int>> &buc, vector<vector<char>> &sBuc)
{
    for (int i = 0; i < 5; i++)
    {
        vector<int> tmp;
        vector<char> sTmp;
        for (int j = 0; j < 5; j++)
        {
            tmp.push_back(0);
            sTmp.push_back(S_WHITE);
        }
        buc.push_back(tmp);
        sBuc.push_back(sTmp);
    }
}

void copyBucket(vector<vector<int>> &buc, vector<vector<char>> &sBuc)
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            buc[i][j] = bucket[i][j];
            sBuc[i][j] = sBucket[i][j];
        }
    }
}

void recoverBucket(vector<vector<int>> &buc, vector<vector<char>> &sBuc)
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            bucket[i][j] = buc[i][j];
            sBucket[i][j] = sBuc[i][j];
        }
    }
}

void toMix(int k, vector<int> &order)
{
    if (k == 3)
    {
        int number = calculate();
        if (answer < number)
        {
            answer = number;
        }

        return;
    }

    int num = order[k];

    vector<vector<int>> reBuc;
    vector<vector<char>> reSBuc;

    initRecoverBucket(reBuc, reSBuc);

    copyBucket(reBuc, reSBuc);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int count = 0; count < 4; count++)
            {
                initTmpMatter(num, count);
                pushMatter(i, j);
                toMix(k + 1, order);
                recoverBucket(reBuc, reSBuc);
            }
        }
    }
}

void initTest()
{
    initBucket();
    initTmpMatter(1, 3);
    pushMatter(0, 0);

    printBucket();

    initTmpMatter(2, 0);
    pushMatter(1, 1);
    printBucket();
    initTmpMatter(0, 0);

    pushMatter(1, 0);
    printBucket();

    cout << calculate();
}

void initRotateArr()
{
    for (int i = 0; i < n; i++)
    {
        for (int dir = 1; dir < 4; dir++)
        {
            rotateArr(i, dir);
        }
    }
}

void printRotateArr(int num)
{
    cout << "\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[num][i][j][0] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[num][i][j][1] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[num][i][j][2] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[num][i][j][3] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cin >> arr[i][j][k][0];
            }
        }

        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cin >> sArr[i][j][k][0];
            }
        }
    }

    initRotateArr();

    for (int i = 0; i < 3; i++)
    {
        state[i] = 1;
    }

    do
    {

        vector<int> order;
        for (int i = 0; i < n; i++)
        {
            if (state[i] == 1)
            {
                order.push_back(i);
            }
        }

        do
        {

            initBucket();
            toMix(0, order);

        } while (next_permutation(order.begin(), order.end()));

    } while (prev_permutation(state, state + n));

    cout << answer;
}