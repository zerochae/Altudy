#include <bits/stdc++.h>
using namespace std;

int r, c, k;

int arr[105][105];

int row = 3;
int col = 3;

vector<int> nums;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

vector<int> getNewArr(map<int, int> a)
{
    vector<pair<int, int>> vec(a.begin(), a.end());

    vector<int> newNum;
    sort(vec.begin(), vec.end(), comp);

    for (auto x : vec)
    {

        if (newNum.size() >= 100)
            break;
        if (x.first == 0)
            continue;
        newNum.push_back(x.first);
        if (newNum.size() >= 100)
            break;
        newNum.push_back(x.second);
    }

    return newNum;
}

void sortRow(int len, int nums)
{
    map<int, int> cntNum;
    for (int i = 1; i <= len; i++)
    {
        int number = arr[i][nums];

        if (number == 0)
            continue;

        if (cntNum.find(number) != cntNum.end())
        {
            cntNum.find(number)->second++;
        }
        else
        {
            cntNum.insert({number, 1});
        }
    }

    vector<int> numbers = getNewArr(cntNum);

    if (numbers.size() > row)
    {
        row = numbers.size();
    }

    for (int i = 1; i <= row; i++)
    {
        if (i <= numbers.size())
        {
            arr[i][nums] = numbers[i - 1];
            continue;
        }

        arr[i][nums] = 0;
    }

    return;
}

void sortCol(int len, int nums)
{
    map<int, int> cntNum;
    for (int i = 1; i <= len; i++)
    {
        int number = arr[nums][i];

        if (number == 0)
            continue;

        if (cntNum.find(number) != cntNum.end())
        {
            cntNum.find(number)->second++;
        }
        else
        {
            cntNum.insert({number, 1});
        }
    }

    vector<int> numbers = getNewArr(cntNum);

    if (numbers.size() > col)
    {
        col = numbers.size();
    }

    for (int i = 1; i <= col; i++)
    {
        if (i <= numbers.size())
        {
            arr[nums][i] = numbers[i - 1];
            continue;
        }

        arr[nums][i] = 0;
    }

    return;
}

void print()
{
    cout << "\n";
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

/*
크기가 3×3인 배열 A가 있다. 배열의 인덱스는 1부터 시작한다. 1초가 지날때마다 배열에 연산이 적용된다.

R 연산: 배열 A의 모든 행에 대해서 정렬을 수행한다. 행의 개수 ≥ 열의 개수인 경우에 적용된다.
C 연산: 배열 A의 모든 열에 대해서 정렬을 수행한다. 행의 개수 < 열의 개수인 경우에 적용된다.
한 행 또는 열에 있는 수를 정렬하려면, 각각의 수가 몇 번 나왔는지 알아야 한다. 그 다음,
수의 등장 횟수가 커지는 순으로,
 그러한 것이 여러가지면 수가 커지는 순으로 정렬한다.
 그 다음에는 배열 A에 정렬된 결과를 다시 넣어야 한다. 정렬된 결과를 배열에 넣을 때는,
 수와 등장 횟수를 모두 넣으며, 순서는 수가 먼저이다.

예를 들어, [3, 1, 1]에는 3이 1번, 1가 2번 등장한다. 따라서, 정렬된 결과는 [3, 1, 1, 2]가 된다.
다시 이 배열에는 3이 1번, 1이 2번, 2가 1번 등장한다. 다시 정렬하면 [2, 1, 3, 1, 1, 2]가 된다.

정렬된 결과를 배열에 다시 넣으면 행 또는 열의 크기가 달라질 수 있다.
 R 연산이 적용된 경우에는 가장 큰 행을 기준으로 모든 행의 크기가 변하고, C 연산이 적용된 경우에는 가장 큰 열을 기준으로 모든 열의 크기가 변한다.
  행 또는 열의 크기가 커진 곳에는 0이 채워진다. 수를 정렬할 때 0은 무시해야 한다. 예를 들어, [3, 2, 0, 0]을 정렬한 결과는 [3, 2]를 정렬한 결과와 같다.

행 또는 열의 크기가 100을 넘어가는 경우에는 처음 100개를 제외한 나머지는 버린다.

배열 A에 들어있는 수와 r, c, k가 주어졌을 때, A[r][c]에 들어있는 값이 k가 되기 위한 최소 시간을 구해보자.
*/

void rowFn()
{
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    // print();

    int timer = 101;
    while (timer--)
    {
        if (arr[r][c] == k)
        {
            cout << 100 - timer;
            return 0;
        }

        if (row < col)
        {
            for (int i = 1; i <= col; i++)
            {
                sortRow(row, i);
            }
        }
        else
        {
            for (int i = 1; i <= row; i++)
            {
                sortCol(col, i);
            }
        }

        // cout << 100 - timer << "초 "
        //      << "\n";
        // print();
    }

    cout << -1;
}
