#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5 + 5;
vector<ll> adj[N];
vector<bool> vis(N, 0);
stack<ll> st;
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
    }
    st.push(vx);
}

void soln()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    while (!st.empty())
    {
        ll x = st.top();
        st.pop();
        cout << x << " ";
    }
    cout << endl;
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