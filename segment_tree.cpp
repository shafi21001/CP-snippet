#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7;

void build(ll ind, ll lo, ll hi, vector<ll> &v, vector<ll> &seg)
{
    if (lo == hi)
    {
        seg[ind] = v[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(2 * ind + 1, lo, mid, v, seg);
    build(2 * ind + 2, mid + 1, hi, v, seg);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}

ll query(ll ind, ll lo, ll hi, ll l, ll r, vector<ll> &seg)
{
    if (r < lo || l > hi)
    {
        return LLONG_MAX;
    }
    if (lo >= l && hi <= r)
    {
        return seg[ind];
    }
    ll mid = (lo + hi) / 2;
    ll left = query(2 * ind + 1, lo, mid, l, r, seg);
    ll right = query(2 * ind + 2, mid + 1, hi, l, r, seg);
    return min(left, right);
}

void update(ll ind, ll lo, ll hi, ll i, ll val, vector<ll> &seg)
{
    if (lo == hi)
    {
        seg[ind] = val;
        return;
    }
    int mid = (lo + hi) / 2;
    if (i <= mid)
    {
        update(2 * ind + 1, lo, mid, i, val, seg);
    }
    else
    {
        update(2 * ind + 2, mid + 1, hi, i, val, seg);
    }
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}

void soln()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }

    vector<ll> seg(n * 4);
    build(0, 0, n - 1, vc, seg);

   while (q--)
    {
        ll typ;
        cin >> typ;
        if (typ == 1)
        {
            ll l, r;
            cin >> l >> r;
            cout << query(0, 0, n - 1, l - 1, r - 1, seg) << endl;
        }
        else
        {
            ll i, val;
            cin >> i >> val;
            update(0, 0, n - 1, i - 1, val, seg);
            vc[i - 1] = val;
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
