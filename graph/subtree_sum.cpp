#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5 + 5;
vector<ll> adj[N];
vector<bool> vis(N, 0);
vector<ll> sum(N, 0);
void dfs(ll vx)
{
    vis[vx] = true;
    for (ll x : adj[vx])
    {
        if (vis[x])
        {
            continue;
        }
        dfs(x);
        sum[vx] += sum[x];
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
    for (ll i = 1; i <= n; i++)
    {
        sum[i] = i;
    }
    dfs(1);
    for (ll i = 1; i <= n; i++)
    {
        cout << sum[i] << " ";
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