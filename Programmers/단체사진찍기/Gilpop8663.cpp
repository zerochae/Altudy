#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool ch(char c, int diff, int num)
{
    if (c == '=')
    {
        return diff == num;
    }
    else if (c == '>')
    {
        return diff > num;
    }
    else if (c == '<')
    {
        return diff < num;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    int answer = 0;

    string friends = "ACFJMNRT";

    sort(friends.begin(), friends.end());

    do
    {

        bool flag = 1;

        for (string text : data)
        {

            int firstIdx = friends.find(text[0]);
            int secondIdx = friends.find(text[2]);

            int dis = abs(firstIdx - secondIdx) - 1;

            char sign = text[3];

            int num = text[4] - '0';

            if (ch(sign, dis, num))
                continue;
            flag = 0;
            break;
        }

        if (flag == 1)
            answer++;
    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}