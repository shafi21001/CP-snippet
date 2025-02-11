#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5 + 5;
vector<ll> parent(N);
vector<ll> sz(N);
void make(ll v)
{
    parent[v] = v;
    sz[v] = 1;
}

ll find_p(ll v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return parent[v] = find_p(parent[v]);
}

void unite(ll a, ll b)
{
    a = find_p(a);
    b = find_p(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void soln()
{
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    vector<pair<ll, pair<ll, ll>>> edges(k);
    for (int i = 0; i < k; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }
    sort(edges.begin(), edges.end());
    ll wt = 0;
    for (ll i = 0; i < k; i++)
    {
        ll u = edges[i].second.first;
        ll v = edges[i].second.second;
        if (find_p(u) != find_p(v))
        {
            unite(u, v);
            wt += edges[i].first;
            // cout << u << " " << v << endl;
        }
    }
    cout << wt << endl;
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