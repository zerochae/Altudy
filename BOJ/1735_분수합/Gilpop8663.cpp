#include <bits/stdc++.h>
using namespace std;

long long A, B;
long long C, D;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    cin >> C >> D;

    long long num = lcm(B, D);

    long long sum = num / B * A + num / D * C;

    int ansA, ansB;

    ansA = sum / gcd(sum, num);
    ansB = num / gcd(sum, num);

    cout << ansA << " " << ansB;
}
