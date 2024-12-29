#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 2;
vector<ll> divisors[N];

void primeDivisors()
{
    for (ll i = 2; i < N; i++)
    {
        if (divisors[i].size() == 0)
        {
            for (ll j = i; j < N; j += i)
            {
                divisors[j].push_back(i);
            }
        }
    }
}

void soln()
{
    primeDivisors();
    ll n;
    cin >> n;
    for (int i = 0; i < divisors[n].size(); i++)
    {
        cout << divisors[n][i] << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // for (int c = 1; c <= t; c++)
    {
        soln();
    }
    return 0;
}