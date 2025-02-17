#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void soln()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> indegree(n + 1, 0);
    vector<ll> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<ll> qq;
    for (ll i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            qq.push(i);
        }
    }
    vector<ll> topo;
    while (!qq.empty())
    {
        ll u = qq.front();
        qq.pop();
        topo.push_back(u);
        for (auto &v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                qq.push(v);
            }
        }
    }
    if (topo.size() != n)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (ll i = 0; i < topo.size(); i++)
        {
            cout << topo[i] << " ";
        }
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