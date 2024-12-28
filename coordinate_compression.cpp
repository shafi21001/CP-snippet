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

    vector<ll> cp = vc;
    sort(cp.begin(), cp.end());
    unordered_map<ll, ll> mp;
    unordered_map<ll, ll> back;
    ll ind = 1;
    for (ll i = 0; i < n; i++)
    {
        if (!mp[cp[i]])
        {
            mp[cp[i]] = ind;
            back[ind] = cp[i];
            ind++;
        }
    }

    for (ll i = 0; i < n; i++)
    {
        vc[i] = mp[vc[i]];
        cout << vc[i] << " ";
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