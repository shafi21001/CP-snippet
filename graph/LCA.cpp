#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
vector<ll> adj[N];
vector<bool> vis(N, 0);
vector<ll> parent(N, 0);

void dfs(ll vx, ll p = 0)
{
    vis[vx] = true;
    parent[vx] = p;
    for (ll x : adj[vx])
    {
        if (vis[x])
        {
            continue;
        }
        dfs(x, vx);
    }
}

void soln()
{
    ll n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    ll q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        vector<ll> pathx;
        vector<ll> pathy;
        pathx.push_back(x);
        while (parent[x] != 0)
        {
            pathx.push_back(parent[x]);
            x = parent[x];
        }
        pathy.push_back(y);
        while (parent[y] != 0)
        {
            pathy.push_back(parent[y]);
            y = parent[y];
        }
        reverse(pathx.begin(), pathx.end());
        reverse(pathy.begin(), pathy.end());
        ll ind = 0;
        ll sz = min(pathx.size(), pathy.size());
        while (ind < sz && pathx[ind] == pathy[ind])
        {
            ind++;
        }
        cout << pathx[ind - 1] << "\n";
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