#include <bits/stdc++.h>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> q;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    for (int i = 0; i < scoville.size(); i++)
    {
        q.push(scoville[i]);
    }

    while (q.top() < K)
    {

        if (q.size() < 2)
            break;

        long long num = q.top();
        q.pop();
        long long num2 = q.top();
        q.pop();

        long long shake = num + num2 * 2;

        q.push(shake);

        answer++;
    }

    if (q.top() < K)
    {
        answer = -1;
    }
    return answer;
}