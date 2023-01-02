#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[104];

int tmp[105][105];

int rotateArr[105][105];
int copyRotateArr[105][105];
int fish[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void leftStack()
{
    tmp[1][0] = arr[0];
    for (int i = 0; i < n; i++)
    {
        tmp[0][i] = arr[i + 1];
    }
}

void recoverTmp()
{
    int minY, maxY;

    for (int i = 0; i < n; i++)
    {
        if (tmp[0][i] > 0)
        {
            minY = i;
            break;
        }
    }

    for (int i = 0; i < n - minY; i++)
    {
        tmp[0][i] = tmp[0][minY + i];
    }

    for (int i = n - minY; i < n; i++)
    {
        tmp[0][i] = 0;
    }
}

tuple<int, int, int, int> rotate(int x, int y)
{
    int maxNum = max(x, y);

    int minX = 100, minY = 100, maxX = 0, maxY = 0;

    for (int i = 0; i <= maxNum; i++)
    {
        for (int j = 0; j <= maxNum; j++)
        {
            copyRotateArr[i][j] = rotateArr[j][maxNum - i];
        }
    }

    for (int i = 0; i <= maxNum; i++)
    {
        for (int j = 0; j <= maxNum; j++)
        {
            rotateArr[i][j] = copyRotateArr[i][j];
            if (rotateArr[i][j] > 0)
            {
                minX = min(minX, i);
                minY = min(minY, j);
                maxX = max(maxX, i);
                maxY = max(maxY, j);
            }
        }
    }

    return {minX, minY, maxX, maxY};
}

pair<int, int> checkMaxColAndRow()
{
    int maxX = 0, maxY = 0;

    for (int i = 0; i < n / 2; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (tmp[i][j] > 0 && i > 0)
            {
                maxX = max(maxX, i);
                maxY = max(maxY, j);
            }
        }
    }

    return {maxX, maxY};
}

pair<int, int> calculateTmpXAndY()
{
    int maxX = 0, maxY = 0;

    for (int i = 0; i < n / 2; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (tmp[i][j] > 0)
            {
                maxX = max(maxX, i);
                maxY = max(maxY, j);
            }
        }
    }

    return {maxX, maxY};
}

bool checkLevitation()
{
    int maxX = 0, maxY = 0;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (tmp[0][i] > 0)
        {
            count += 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tmp[i][j] > 0 && i > 0)
            {
                maxX = max(maxX, i);
                maxY = max(maxY, j);
            }
        }
    }

    int firstFloorCount = count - maxY - 1;

    int floorHeight = maxX + 1;

    if (count - 1 == maxY)
        return false;

    if (firstFloorCount < floorHeight)
        return false;

    return true;
}

void saveRotateArr(int x, int y)
{
    fill(&rotateArr[0][0], &rotateArr[104][105], 0);
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            rotateArr[i][j] = tmp[i][j];
            tmp[i][j] = 0;
        }
    }
}

void plusFish()
{
    int minNum = *min_element(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == minNum)
        {
            arr[i] += 1;
        }
    }
}

void combineTmp(int minX, int minY, int maxX, int maxY)
{

    int stX = 1;
    for (int i = minX; i <= maxX; i++)
    {
        for (int j = 0; j <= maxY; j++)
        {
            tmp[stX][j] = rotateArr[i][j];
        }
        stX += 1;
    }
}

void printRotateArr(int x, int y)
{
    cout << "\n";
    for (int i = 0; i <= x; i++)
    {

        for (int j = 0; j <= y; j++)
        {
            cout << rotateArr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void printTmp(int floor)
{
    cout << "\n";
    for (int i = 0; i <= floor; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << tmp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void printArr()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void decreaseFish(int x, int y)
{
    fill(&fish[0][0], &fish[104][105], 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fish[i][j] = tmp[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tmp[i][j] == 0)
                continue;
            int fishNum = tmp[i][j];
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if (tmp[nx][ny] == 0)
                    continue;
                if (tmp[nx][ny] > fishNum)
                    continue;

                int score = (fishNum - tmp[nx][ny]) / 5;

                fish[i][j] -= score;
                fish[nx][ny] += score;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = fish[i][j];
        }
    }
}

void lineUp()
{
    int idx = 0;

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (tmp[i][j] > 0)
            {
                arr[idx] = tmp[i][j];
                idx += 1;
            }
        }
    }

    fill(&tmp[0][0], &tmp[104][105], 0);
}

void calculateHalf()
{
    int index = 0;
    fill(&tmp[0][0], &tmp[104][105], 0);
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        tmp[1][i] = arr[index];
        index += 1;
    }

    for (int i = 0; i < n / 2; i++)
    {
        tmp[0][i] = arr[index];
        index += 1;
    }
}

void calculateTmpHalf()
{
    int halfNumber = n / 4;

    for (int i = 0; i < halfNumber; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            tmp[2 + j][i + halfNumber] = tmp[1 - j][halfNumber - 1 - i];
            tmp[1 - j][halfNumber - 1 - i] = 0;
        }
    }
}

void levitation()
{

    auto cur = checkMaxColAndRow();

    int x = cur.first;
    int y = cur.second;

    saveRotateArr(x, y);

    auto rotateCur = rotate(x, y);
    int minX = get<0>(rotateCur);
    int minY = get<1>(rotateCur);
    int maxX = get<2>(rotateCur);
    int maxY = get<3>(rotateCur);

    recoverTmp();

    combineTmp(minX, minY, maxX, maxY);
}

bool isOrganize()
{
    int maxNum = *max_element(arr, arr + n);
    int minNum = *min_element(arr, arr + n);

    if (maxNum - minNum <= k)
        return false;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int answer = 0;

    int count = 10;
    while (isOrganize())
    {
        answer += 1;
        plusFish();
        leftStack();

        while (checkLevitation())
        {
            levitation();
        }

        auto cur = calculateTmpXAndY();

        decreaseFish(cur.first, cur.second);

        lineUp();

        calculateHalf();

        calculateTmpHalf();
        decreaseFish(n / 2, n / 2);
        lineUp();
    }

    cout << answer;
}
