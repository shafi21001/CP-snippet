#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5 + 5;
vector<ll> adj[N];
vector<bool> vis(N, 0);
vector<pair<ll, ll>> cnt(N);

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

        cnt[vx].first += cnt[x].first;
        cnt[vx].second += cnt[x].second;
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
        if (i & 1)
        {
            cnt[i] = {1, 0};
        }
        else
        {
            cnt[i] = {0, 1};
        }
    }
    dfs(1);
    for (ll i = 1; i <= n; i++)
    {
        cout << cnt[i].first << " " << cnt[i].second << endl;
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