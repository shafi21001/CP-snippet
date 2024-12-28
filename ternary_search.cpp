#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void soln()
{
    ll n, v;
    cin >> n >> v;
    vector<ll> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }

    ll lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        ll m1 = lo + (hi - lo) / 3;
        ll m2 = hi - (hi - lo) / 3;
        if (vc[m1] == v || vc[m2] == v)
        {
            cout << "Found" << endl;
            return;
        }
        else if (v < vc[m1])
        {
            hi = m1 - 1;
        }
        else if (v > vc[m2])
        {
            lo = m2 + 1;
        }
        else
        {
            lo = m1 + 1;
            hi = m2 - 1;
        }
    }
    cout << "Not found" << endl;
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