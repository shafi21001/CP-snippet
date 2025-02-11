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

ll find(ll v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return parent[v] = find(parent[v]);
}

void unite(ll a, ll b)
{
    a = find(a);
    b = find(b);
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

    while (k--)
    {
        ll u, v;
        cin >> u >> v;
        unite(u, v);
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