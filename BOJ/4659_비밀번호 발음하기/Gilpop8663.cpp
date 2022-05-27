#include <bits/stdc++.h>
using namespace std;

int n;

int arr[100];

bool comp(int a, int b)
{
    return a > b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    while (true)
    {
        string str;
        cin >> str;
        t = str.size();

        if (str == "end")
        {
            break;
        }

        bool flag = 0;
        int cnt = 0;
        if (str.find('a') < 30 || str.find('e') < 30 || str.find('i') < 30 || str.find('o') < 30 || str.find('u') < 30)
        {

            cnt = 1;
            for (int i = 1; i < t; i++)
            {

                if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
                {
                    if (str[i - 1] == 'a' || str[i - 1] == 'e' || str[i - 1] == 'i' || str[i - 1] == 'o' || str[i - 1] == 'u')
                    {
                        cnt++;
                    }
                    else
                    {

                        cnt = 1;
                    }
                }
                else
                {
                    if (str[i - 1] == 'a' || str[i - 1] == 'e' || str[i - 1] == 'i' || str[i - 1] == 'o' || str[i - 1] == 'u')
                    {
                        cnt = 1;
                    }
                    else
                    {

                        cnt++;
                    }
                }

                if (cnt >= 3)
                {
                    flag = 1;
                    break;
                }
            }
        }
        else
        {
            flag = 1;
        }

        cnt = 1;
        for (int i = 0; i < t - 1; i++)
        {
            // cout << cnt << "\n";
            if (str[i] == str[i + 1])
            {
                cnt++;

                if (cnt >= 2)
                {
                    if (str[i] == 'e' && str[i + 1] == 'e')
                    {
                        if (cnt >= 3)
                        {
                            flag = 1;
                        }
                        continue;
                    }
                    else if (str[i] == 'o' && str[i + 1] == 'o')
                    {
                        if (cnt >= 3)
                        {
                            flag = 1;
                        }
                        continue;
                    }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            else
            {
                cnt = 1;
            }
        }

        if (flag == 1)
        {

            cout << "<" << str << "> is not acceptable.";
        }
        else
        {
            cout << "<" << str << "> is acceptable.";
        }
        cout << "\n";
        // cout << str << "\n";
    }
}
