#include <bits/stdc++.h>
using namespace std;

int n, l;

int arr[105][105];

bool check(vector<int> &line)
{
    int idx = 0;
    int cnt = 1; // 현재 보고 있는 ,높이가 같은 구간의 길이

    while (idx < n - 1)
    {
        if (abs(line[idx + 1] - line[idx]) > 1) // 높이 차이가 1 이상 날 경우 설치 불가
            return 0;
        if (line[idx] == line[idx + 1]) // 같다면 다음 칸 체크
        {
            idx++;
            cnt++;
        }
        else if (line[idx] < line[idx + 1]) //다음 경사로보다 높이가 낮다면
        {
            if (cnt < l)
                return 0;
            idx++;
            cnt = 1;
        }
        else //다음 칸이 더 낮다면
        {
            if (idx + l >= n) // l 길이 만큼 길이 없다면 경사로 설치 불가
                return 0;
            for (int i = idx + 1; i < idx + l; i++)
            {
                if (line[i] != line[i + 1]) // 경사로 높이가 같지 않다면 설치 불가
                    return 0;
            }

            idx = idx + l; // 경사로를 설치했다면 , 설치한 칸부터 다음 칸과 비교
            cnt = 0;
        }
    }

    return 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    //가로
    for (int i = 0; i < n; i++)
    {
        vector<int> line;
        for (int j = 0; j < n; j++)
        {
            line.push_back(arr[i][j]);
        }
        ans += check(line);
    }

    //세로
    for (int i = 0; i < n; i++)
    {
        vector<int> line;
        for (int j = 0; j < n; j++)
        {
            line.push_back(arr[j][i]);
        }
        ans += check(line);
    }

    cout << ans;
}
