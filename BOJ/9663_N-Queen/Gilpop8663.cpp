#include <bits/stdc++.h>
using namespace std;

int n;

bool isused1[40]; //    y 열
bool isused2[40]; // \  x+y 오른쪽 위 ~ 왼쪽 아래로 대각선
bool isused3[40]; //  / x-y+n-1 왼쪽 위~오른쪽 아래로 대각선

int cnt = 0;

void func(int cur)
{
    if (cur == n)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    { // (cur , i) 에 말을 놓을 예정

        if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1]) // column 이나 대각선에 말이 있다면
        {
            continue;
        }
        isused1[i] = true;
        isused2[i + cur] = true;
        isused3[cur - i + n - 1] = true;
        func(cur + 1);
        isused1[i] = false;
        isused2[i + cur] = false;
        isused3[cur - i + n - 1] = false;
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);
    cout << cnt;
}
