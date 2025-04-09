#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = 1e5 + 5;
vector<ll> adj[N];
vector<bool> vis(N, false);
vector<ll> level(N, 0);

void bfs(ll v) {
    queue<ll> qq;
    qq.push(v);
    vis[v] = true;

    while (!qq.empty()) {
        ll k = qq.front();
        qq.pop();

        for (ll a : adj[k]) {
            if (!vis[a]) {
                qq.push(a);
                vis[a] = true;
                level[a] = level[k] + 1;
            }
        }
    }
}

int main() {
    ll nodes, edges;
    cin >> nodes >> edges;

    for (ll i = 0; i < edges; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll start_node;
    cin >> start_node; 
    bfs(start_node);

    cout << "Levels of nodes from source:\n";
    for (ll i = 1; i <= nodes; i++) {
        cout << "Node " << i << ": Level " << level[i] << endl;
    }

    return 0;
}
