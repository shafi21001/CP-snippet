#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void build(ll ind, ll lo, ll hi, vector<ll> &v, vector<ll> &seg)
{
    if (lo == hi)
    {
        seg[ind] = v[lo];
        return;
    }
    ll mid = (lo + hi) / 2;
    build(2 * ind + 1, lo, mid, v, seg);
    build(2 * ind + 2, mid + 1, hi, v, seg);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

void propagate(ll ind, ll lo, ll hi, vector<ll> &seg, vector<ll> &lazy)
{
    if (lazy[ind] != 0)
    {
        seg[ind] += (hi - lo + 1) * lazy[ind];
        if (lo != hi)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
}

ll query(ll ind, ll lo, ll hi, ll l, ll r, vector<ll> &seg, vector<ll> &lazy)
{
    propagate(ind, lo, hi, seg, lazy);

    if (r < lo || l > hi)
        return 0;
    if (lo >= l && hi <= r)
        return seg[ind];

    ll mid = (lo + hi) / 2;
    ll left = query(2 * ind + 1, lo, mid, l, r, seg, lazy);
    ll right = query(2 * ind + 2, mid + 1, hi, l, r, seg, lazy);
    return left + right;
}

void lazyUpdate(ll ind, ll lo, ll hi, ll l, ll r, ll val, vector<ll> &seg, vector<ll> &lazy)
{
    propagate(ind, lo, hi, seg, lazy);

    if (r < lo || l > hi)
        return;

    if (lo >= l && hi <= r)
    {
        seg[ind] += (hi - lo + 1) * val;
        if (lo != hi)
        {
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }
        return;
    }

    ll mid = (lo + hi) / 2;
    lazyUpdate(2 * ind + 1, lo, mid, l, r, val, seg, lazy);
    lazyUpdate(2 * ind + 2, mid + 1, hi, l, r, val, seg, lazy);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

void soln()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> vc(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> vc[i];
    }

    vector<ll> seg(n * 4, 0);
    vector<ll> lazy(n * 4, 0);
    build(0, 0, n - 1, vc, seg);

    while (q--)
    {
        ll typ;
        cin >> typ;
        if (typ == 1)
        {
            ll l, r;
            cin >> l >> r;
            cout << query(0, 0, n - 1, l - 1, r - 1, seg, lazy) << endl;
        }
        else
        {
            ll l, r, val;
            cin >> l >> r >> val;
            lazyUpdate(0, 0, n - 1, l - 1, r - 1, val, seg, lazy);
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
