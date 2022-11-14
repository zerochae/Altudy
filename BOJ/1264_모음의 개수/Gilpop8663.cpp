#include <bits/stdc++.h>
#include <cmath>
using namespace std;

char lower[5] = {'a', 'e', 'o', 'u', 'i'};
char upper[5] = {'A', 'E', 'O', 'U', 'I'};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    while (getline(cin, str))
    {
        if (str == "#")
        {
            break;
        }

        int count = 0;
        for (int i = 0; i < str.size(); i++)
        {

            for (int j = 0; j < 5; j++)
            {

                if (str[i] == lower[j])
                    count++;
                if (str[i] == upper[j])
                    count++;
            }
        }

        cout << count << "\n";
    }
}
