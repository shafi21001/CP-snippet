#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 5e2 + 5;
ll dist[N][N];

void soln()
{
    for (ll i = 0; i < N; ++i)
    {
        for (ll j = 0; j < N; ++j)
        {
            if (i == j)
            {
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = INT_MAX;
        }
    }
    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    for (ll k = 1; k <= n; ++k)
    {
        for (ll i = 1; i <= n; ++i)
        {
            for (ll j = 1; j <= n; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        cout << (dist[u][v] == INT_MAX ? -1 : dist[u][v]) << '\n';
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