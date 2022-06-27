#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int answer, maxVal;

int d[1001][3];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        d[a][0] = b;
    }

    for (int i = 0; i <= 1000; i++) //왼편에서 빛을 쏘았다고 가정하고  x좌표를 0부터 1000까지 순회하면서 더 긴 기둥이 나온다면 max 값을 갱신해주면서 그 값을 해당 x 좌표의 높이로 저장합니다.
    {
        maxVal = max(d[i][0], maxVal);
        d[i][1] = maxVal; // 가장 큰 수 현재 가장 높은 숫자 .
    }

    maxVal = 0;

    //현재 왼편에서 봤을 때는 가장 긴 기둥의 x좌표를 기준으로 오른쪽에 큰 값들이 저장되어 있으며 , 오른편에서 빛을 쐇을 때는 왼편에 큰 값들이 저장되어 있습니다.

    //다시 x 좌표 0~1000까지 순회하며 저장된 각자의 값중 최솟값이 최소 창고 다각형을 구성하는 한 기둥의 높이가 됩니다.

    for (int i = 1000; i >= 0; i--)
    {

        maxVal = max(d[i][0], maxVal);
        d[i][2] = maxVal;
    }

    for (int i = 0; i <= 1000; i++)
    {
        answer += min(d[i][1], d[i][2]);
    }

    cout << answer;
}
