#include <bits/stdc++.h>
using namespace std;

int n;

string str;

int arr[27];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cin >> str;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<double> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != '*' && str[i] != '/' && str[i] != '+' && str[i] != '-')
        {
            s.push(arr[str[i] - '0' - 17]);
            //     cout
            // << arr[str[i] - '0' - 17] << " ";
        }
        else
        {

            double num2 = s.top();
            s.pop();
            double num1 = s.top();
            s.pop();

            if (str[i] == '+')
                s.push(num1 + num2);
            else if (str[i] == '-')
                s.push(num1 - num2);
            else if (str[i] == '*')
                s.push(num1 * num2);
            else if (str[i] == '/')
                s.push(num1 / num2);
        }
    }
    cout << fixed;
    cout.precision(2);
    double ans = s.top();
    cout << ans;
}