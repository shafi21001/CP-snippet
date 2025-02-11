#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5 + 5;
vector<ll> adj[N];
vector<bool> vis(N, 0);
vector<ll> depth(N, 0);
vector<ll> height(N, 0);

void dfs(ll vx)
{
    vis[vx] = true;
    // cout << vx << endl;

    for (ll x : adj[vx])
    {
        // cout << x <<" ";
        if (vis[x])
        {
            continue;
        }
        depth[x] = depth[vx] + 1;
        dfs(x);
        height[vx] = max(height[vx], height[x] + 1);
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

    for (ll i = 1; i <= n; i++)
    {
        cout << depth[i] << " ";
    }
    cout << endl;
    for (ll i = 1; i <= n; i++)
    {
        cout << height[i] << " ";
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