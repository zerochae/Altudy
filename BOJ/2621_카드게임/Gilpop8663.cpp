#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[6];

char str[6];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        cin >> str[i] >> arr[i];

        // cout << str[i] << " " << arr[i] << "\n";
    }

    sort(arr, arr + 5);
    sort(str, str + 5);

    int ans = 0;

    // 1번째 방법
    int number = 0;
    int strCnt = 1;
    int numCnt = 1;
    for (int i = 0; i < 4; i++)
    {
        if (str[i] == str[i + 1])
        {
            strCnt++;
        }
        if (arr[i] == arr[i + 1] - 1)
        {
            numCnt++;
        }
    }

    // cout << strCnt << " " << numCnt << "\n";

    if (strCnt == 5 && numCnt == 5)
    {
        ans = 900 + arr[4];
        cout << ans;
        return 0;
    }

    // 2번째 방법
    strCnt = 1;
    numCnt = 1;
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            numCnt++;
        }
        else
        {
            numCnt = 1;
        }
        if (numCnt == 4)
        {
            number = arr[i];
            break;
        }
    }

    if (number != 0)
    {
        ans = 800 + number;
        cout << ans;
        return 0;
    }

    // 3번째 방법
    int newCnt = 0;
    int newNumber = 1;
    number = 0;
    numCnt = 0;
    for (int i = 0; i < 5; i++)
    {
        if (arr[0] == arr[i])
        {
            numCnt++;
        }
        else if (arr[4] == arr[i])
        {
            newCnt++;
        }
    }

    if (numCnt == 3 && newCnt == 2)
    {

        number = arr[0];
        newNumber = arr[4];
    }
    else if (newCnt == 3 && numCnt == 2)
    {
        number = arr[4];
        newNumber = arr[0];
    }

    if (number != 0 && newNumber != 0)
    {
        ans = 700 + (number * 10) + newNumber;
        cout << ans;
        return 0;
    }

    // 4,5번째 방법
    strCnt = 1;
    numCnt = 1;
    for (int i = 0; i < 4; i++)
    {
        if (str[i] == str[i + 1])
        {
            strCnt++;
        }

        if (arr[i] == arr[i + 1] - 1)
        {
            numCnt++;
        }
    }

    // 4번째
    if (strCnt == 5)
    {
        ans = 600 + arr[4];

        cout << ans;
        return 0;
    }

    // 5번째
    if (numCnt == 5)
    {
        ans = 500 + arr[4];
        cout << ans;
        return 0;
    }

    // 6번째 방법
    numCnt = 1;
    number = 0;
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            numCnt++;
        }
        else
        {
            numCnt = 1;
        }

        if (numCnt == 3)
        {
            number = arr[i];
        }
    }

    if (number != 0)
    {
        ans = 400 + number;
        cout << ans;
        return 0;
    }

    // 7번째 방법

    numCnt = 1;
    vector<int> isAns;
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            numCnt++;
        }

        if (numCnt == 2)
        {
            numCnt = 1;
            isAns.push_back(arr[i]);
        }
    }

    if (isAns.size() == 2)
    {
        ans = 300 + (max(isAns[0], isAns[1]) * 10) + min(isAns[0], isAns[1]);
        cout << ans;

        return 0;
    }

    // 8번재 방법
    numCnt = 1;
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            numCnt++;
            number = arr[i];
        }
    }

    if (numCnt == 2)
    {
        ans = 200 + number;
        cout << ans;
        return 0;
    }

    // 9번째 방법
    ans = 100 + arr[4];
    cout << ans;
    return 0;
}

/*

1.

Y 4
Y 3
Y 2
Y 5
Y 6
답 : 906

2.

B 3
R 3
B 7
Y 3
G 3

답:803

3.

R 5
Y 5
G 7
B 5
Y 7

답: 757

4.

Y 3
Y 4
Y 8
Y 6
Y 7

답:608

5.

R 7
R 8
G 9
Y 6
B 5

답:509

6.

R 7
Y 7
R 2
G 7
R 5

답:407

7.

R 5
Y 5
Y 4
G 9
B 4

답:354

8.

R 5
Y 2
B 5
B 3
G 4

답:205

9.

R 1
R 2
B 4
B 8
Y 5

답:108


//추가 케이스

1.

R 5
R 2
R 3
R 4
R 1

답 : 905

2.

B 3
G 3
R 4
Y 3
R 3

답 : 803

3.

R 6
R 2
G 6
G 2
A 6

답 : 762

4.

Y 7
Y 2
Y 6
Y 9
Y 1

답 : 609



*/