#include <bits/stdc++.h>
using namespace std;

// solution 1

// 2차원 배열을 이용해서 1번쨰 계단을 밟았을 때 , 2번째 계단을 밟았을 때로 계산하여 구함

// int n;

// int d[305][3];
// int s[305];

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> s[i];
//     }
//     d[1][1] = s[1];
//     d[1][2] = 0;
//     d[2][1] = s[2];        //
//     d[2][2] = s[1] + s[2]; //
//     // d[i-2][1] 혹은  d[i-1][2]에서 왔음. S[k] 는 k번째 계단에 써있는 점수
//     // d[i][1] = max(d[i-2][1] , d[i-2][2]) + S[k]

//     //연속으로 3번의 계단은 오르지 못하므로 전번째 계단 + 현재 k번째에 써있는 점수임
//     // d[i][2] = d[i-1] + S[k]

//     if (n == 1)
//     {
//         cout << s[1];
//         return 0;
//     }

//     for (int i = 3; i <= n; i++)
//     {
//         d[i][1] = max(d[i - 2][1], d[i - 2][2]) + s[i];
//         d[i][2] = d[i - 1][1] + s[i];
//     }
//     cout << max(d[n][1], d[n][2]);
// }

// solution 2

// 1차원 배열을 이용해서 밟지 않을 계단의 합의 최솟값을 구함,  단 i 번쨰 계단은 무조건 밟지 않음.

int n;
int s[305];
int d[305];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        tot += s[i];
    }
    if (n <= 2)
    {
        cout << tot;
        return 0;
    }

    d[1] = s[1]; // 첫번째 계단을 밟지 않는 것.
    d[2] = s[2]; // 두번째 계단을 밟지 않는것.
    d[3] = s[3]; // 세번째 계단을 밟지 않는것.

    // d[4] 는 연속으로 4번째 계단을 오르지 못하므로 d[1] 혹은 d[2] 중 큰 계단을 밟는 것이 밟지 않은것의 최솟값으므로 작은 것을 골라야함.
    //  min(d[1],d[2]) + s[4] k번쨰는 무조건 밟지 않아야 하므로.

    for (int i = 4; i <= n; i++)
    {
        d[i] = min(d[i - 2], d[i - 3]) + s[i];
    }

    //최솟값을 구했다면 이게 연속 3번쨰는 안되므로 n-1 혹은 n-2를 빼야 함.
    cout << tot - min(d[n - 1], d[n - 2]);
    // d[i] = min(s[i-2],s[i-1])
}