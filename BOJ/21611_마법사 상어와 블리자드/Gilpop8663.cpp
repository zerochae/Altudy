#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[52][52];

int sharkX, sharkY;

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

int one = 0, two = 0, three = 0;

bool check[2552] = {0};

int changeDir(int dir)
{
    if (dir == 4)
    {
        return 1;
    }
    if (dir == 3)
    {
        return 2;
    }
    if (dir == 2)
    {
        return 4;
    }
    if (dir == 1)
    {
        return 3;
    }
    return 0;
}

void copyArr(vector<int> copy_arr)
{
    int step = 1;
    int stX = sharkX, stY = sharkY;

    int dir = 3;
    int index = 0;
    int count = copy_arr.size();

    while (step != n)
    {

        for (int i = 0; i < step; i++)
        {
            if (stX == sharkX && stY == sharkY)
            {

                stX += dx[dir];
                stY += dy[dir];
                continue;
            }

            if (index == count)
                return;

            arr[stX][stY] = copy_arr[index];
            index += 1;
            stX += dx[dir];
            stY += dy[dir];
        }

        dir = changeDir(dir);

        for (int i = 0; i < step; i++)
        {
            if (index == count)
                return;
            arr[stX][stY] = copy_arr[index];
            index += 1;
            stX += dx[dir];
            stY += dy[dir];
        }

        dir = changeDir(dir);
        step += 1;
    }

    // 맨 마지막 줄
    for (int i = 0; i < step - 1; i++)
    {
        if (index == count)
            return;
        arr[stX][stY] = copy_arr[index];
        index += 1;
        stX += dx[dir];
        stY += dy[dir];
    }
}

void printArr()
{
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void destroy(int dir, int power)
{
    int nx = sharkX, ny = sharkY;
    while (power--)
    {

        nx += dx[dir];
        ny += dy[dir];

        if (nx < 1 || ny < 1 || nx > n || ny > n)
            break;
        arr[nx][ny] = 0;
    }

    return;
}

vector<int> calculateNotZero(vector<int> numbers)
{
    vector<int> newArr;

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 0)
            continue;
        newArr.push_back(numbers[i]);
    }
    return newArr;
}

vector<int> seriesArr()
{
    vector<int> numbers;

    int step = 1;
    int stX = sharkX, stY = sharkY;

    int dir = 3;
    bool isFind = 0;

    while (step != n)
    {

        for (int i = 0; i < step; i++)
        {
            numbers.push_back(arr[stX][stY]);
            stX += dx[dir];
            stY += dy[dir];
        }

        dir = changeDir(dir);

        for (int i = 0; i < step; i++)
        {
            numbers.push_back(arr[stX][stY]);
            stX += dx[dir];
            stY += dy[dir];
        }

        dir = changeDir(dir);
        step += 1;
    }

    // 맨 마지막 줄
    for (int i = 0; i < step - 1; i++)
    {
        numbers.push_back(arr[stX][stY]);
        stX += dx[dir];
        stY += dy[dir];
    }

    return numbers;
}

bool calculateBomb(vector<int> &numbers)
{
    vector<int> tmp;
    int count = 1;
    bool isBomb = 0;
    int num = 9;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == num)
        {
            count += 1;
            tmp.push_back(i);
        }
        else
        {
            if (count >= 4)
            {
                isBomb = 1;
                for (int j = 0; j < tmp.size(); j++)
                {
                    numbers[tmp[j]] = 0;
                }

                if (num == 3)
                {
                    three += tmp.size();
                }
                else if (num == 2)
                {
                    two += tmp.size();
                }
                else if (num == 1)
                {
                    one += tmp.size();
                }
            }
            tmp.clear();
            count = 1;
            num = numbers[i];
            tmp.push_back(i);
        }
    }

    if (count >= 4)
    {
        isBomb = 1;
        for (int j = 0; j < tmp.size(); j++)
        {
            numbers[tmp[j]] = 0;
        }

        if (num == 3)
        {
            three += tmp.size();
        }
        else if (num == 2)
        {
            two += tmp.size();
        }
        else if (num == 1)
        {
            one += tmp.size();
        }
    }

    return isBomb;
}

vector<int> calculateDivideArr(vector<int> numbers)
{

    vector<int> divideArr;
    fill(check, check + 2505, 0);

    for (int i = 1; i < numbers.size(); i++)
    {
        int count = 0;
        if (check[i] == 1)
            continue;
        for (int j = i; j < numbers.size(); j++)
        {
            if (numbers[i] == numbers[j])
            {
                check[j] = 1;
                count += 1;
            }
            else
            {
                break;
            }
        }
        divideArr.push_back(count);
        divideArr.push_back(numbers[i]);
    }

    return divideArr;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    sharkX = n / 2 + 1, sharkY = n / 2 + 1;
    arr[sharkX][sharkY] = 9;

    for (int i = 0; i < m; i++)
    {
        int dir, power;
        cin >> dir >> power;
        destroy(dir, power);

        auto cur = seriesArr();

        auto newArr = calculateNotZero(cur);

        while (calculateBomb(newArr) == 1)
        {
            newArr = calculateNotZero(newArr);
        }

        auto divideArr = calculateDivideArr(newArr);

        fill(&arr[0][0], &arr[51][52], 0);
        arr[sharkX][sharkY] = 9;
        copyArr(divideArr);
    }

    int answer = 1 * one + 2 * two + 3 * three;

    cout << answer;
}
