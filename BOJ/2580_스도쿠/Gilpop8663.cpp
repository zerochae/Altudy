#include <bits/stdc++.h>
using namespace std;

int arr[10][10];

vector<pair<int, int>> point;

bool numbers[10] = {0};

vector<int> ans;

bool isFind = 0;

void print()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

// 1~9 체크
bool isCheck(int a, int b)
{
    //한줄 체크

    for (int i = 0; i < 9; i++)
    {
        if (arr[a][i] == arr[a][b] && i != b)
            return false;
        if (arr[i][b] == arr[a][b] && i != a)
            return false;
    }

    // 3*3 체크

    int sa = (a / 3) * 3;
    int sb = (b / 3) * 3;

    for (int i = sa; i < sa + 3; i++)
    {
        for (int j = sb; j < sb + 3; j++)
        {
            if (i == a && j == b)
                continue;
            if (arr[i][j] == arr[a][b])
                return false; // 겹치는 것이 존재함
        }
    }

    //겹치는 것이 없다면 true 반환
    return true;
}

void sdoku(int k)
{
    if (k == point.size())
    {
        print();
        isFind = 1;
        return;
    }

    // k번째 빈칸 좌표
    int a = point[k].first;
    int b = point[k].second;

    for (int i = 1; i <= 9; i++)
    {
        arr[a][b] = i;
        if (isCheck(a, b))
        {
            sdoku(k + 1);
        }
        if (isFind == 1)
            return; //스도쿠 완성
    }

    arr[a][b] = 0; // 못채우면 되돌리기
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 9;
    int m = 9;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 0)
            {
                point.push_back({i, j});
            }
        }
    }

    /*
    스도쿠를 푸는 방법

    1. 3*3 칸 중 123456789 중 하나만 없는 칸을 찾아 채운다. 반복한다
    2. 가로 1*9 칸 중 123456789 중 하나만 없는 칸을 찾아 채운다. 반복한다.
    3. 세로 1*9 칸 중 123456789 중 하나만 없는 칸을 찾아 채운다. 반복한다.

    */
    sdoku(0);
}