#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
vector<ll> vc;
vector<vector<ll>> maxTable;
vector<vector<ll>> sumTable;
void build()
{
    for (ll i = 0; i < n; i++)
    {
        maxTable[i][0] = vc[i];
        sumTable[i][0] = vc[i];
    }

    for (ll j = 1; (1 << j) <= n; j++)
    {
        for (ll i = 0; i + (1 << j) <= n; i++)
        {
            sumTable[i][j] = sumTable[i][j - 1] + sumTable[i + (1 << (j - 1))][j - 1];
            maxTable[i][j] = max(maxTable[i][j - 1], maxTable[i + (1 << (j - 1))][j - 1]);
        }
    }
}
ll maxQuery(ll l, ll r)
{
    ll j = log2(r - l + 1);
    return max(maxTable[l][j], maxTable[r + 1 - (1 << j)][j]);
}
ll sumQuery(ll l, ll r)
{
    ll sm = 0;
    for (ll j = k; j >= 0; j--)
    {
        if (l + (1 << j) - 1 <= r)
        {
            sm += sumTable[l][j];
            l += (1 << j);
        }
    }
    return sm;
}

void soln()
{
    ll q;
    cin >> n >> q;
    vc.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }
    k = log2(n) + 1;
    maxTable.assign(n, vector<ll>());
    sumTable.assign(n, vector<ll>());
    for (int i = 0; i < n; i++)
    {
        maxTable[i].resize(k);
        sumTable[i].resize(k);
    }

    build();

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        // cout << maxQuery(l - 1, r - 1) << endl;
        cout << sumQuery(l - 1, r - 1) << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    soln();
    return 0;
}
