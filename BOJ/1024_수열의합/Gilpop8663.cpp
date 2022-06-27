#include <bits/stdc++.h>
using namespace std;

int n, l;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l;

    int high = n;
    int low = l;

    while (true)
    {
        int mid = high / low;

        if (low > 100)
        {
            cout << -1;
            break;
        }

        if (low % 2 == 1)
        {
            if (mid - low / 2 < 0)
            {
                low++;
                continue;
            }
            if (n % low == 0)
            {
                for (int i = mid - low / 2; i < mid + (low + 1) / 2; i++)
                {
                    cout << i << " ";
                }
                break;
            }
        }
        else if (low % 2 == 0)
        {
            int num = n % low;
            if (mid - (low - 1) / 2 < 0)
            {

                low++;
                continue;
            }
            if (num == low / 2)
            {
                for (int i = mid - (low - 1) / 2; i < mid + (low) / 2 + 1; i++)
                {
                    cout << i << " ";
                }
                break;
            }
        }

        // cout << low << "\n";
        low++;
    }
}

/*

l이 홀수 일 때  18 3 처럼 나누어 떨어진다면 3의 수열이 나옴 5 6 7 처럼

l이 짝수 일 때 18  4 처럼  18%4 = 2  l /2와 같을 때 같은 결과값이 나온다



*/