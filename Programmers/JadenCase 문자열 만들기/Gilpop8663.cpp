#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";

    bool isFind = 1;

    for (int i = 0; i < s.size(); i++)
    {
        if (isFind == 1)
        {
            s[i] = toupper(s[i]);
        }
        else
        {
            s[i] = tolower(s[i]);
        }
        if (s[i] == ' ')
        {
            isFind = 1;
        }
        else
        {
            isFind = 0;
        }

        answer += s[i];
    }
    return answer;
}
