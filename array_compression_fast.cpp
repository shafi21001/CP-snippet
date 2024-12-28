#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void soln()
{
    ll n;
    cin >> n;
    vector<ll> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }

    vector<pair<ll, ll>> cp(n);
    for (ll i = 0; i < n; i++)
    {
        cp[i] = {vc[i], i};
    }

    sort(cp.begin(), cp.end());
    ll ind = 0;
    for (ll i = 0; i < n; i++)
    {
        if (i > 0 && cp[i - 1].first != cp[i].first)
        {
            ind++;
        }
        vc[cp[i].second] = ind;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        soln();
    }
    return 0;
}