#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5 + 5;
vector<pair<ll, ll>> adj[N];
vector<ll> dist(N, INT_MAX);
vector<bool> vis(N, 0);
void dijkstra(ll v)
{
    set<pair<ll, ll>> st;
    st.insert({0, v});
    dist[v] = 0;
    while (!st.empty())
    {
        pair<ll, ll> k = *st.begin();
        st.erase(st.begin());
        ll u = k.second;
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;
        for (auto &a : adj[u])
        {
            ll wt = a.second;
            ll to = a.first;
            if (dist[u] + wt < dist[to])
            {
                st.erase({dist[to], to});
                dist[to] = dist[u] + wt;
                st.insert({dist[to], to});
            }
        }
    }
}

void soln()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
    dijkstra(1);
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i]);
    }
    if (ans == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
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
