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

ll query(ll ind, ll lo, ll hi, ll l, ll r, vector<ll> &seg, vector<ll> &lzy)
{
    if (lzy[ind] != 0)
    {
        seg[ind] += ((hi - lo + 1) * lzy[ind]);
        if (hi != lo)
        {
            lzy[2 * ind + 1] += lzy[ind];
            lzy[2 * ind + 2] += lzy[ind];
        }
        lzy[ind] = 0;
    }
    if (r < lo || l > hi)
    {
        return 0;
    }
    if (lo >= l && hi <= r)
    {
        return seg[ind];
    }
    ll mid = (lo + hi) / 2;
    ll left = query(2 * ind + 1, lo, mid, l, r, seg, lzy);
    ll right = query(2 * ind + 2, mid + 1, hi, l, r, seg, lzy);
    return left + right;
}

void lazyUpdate(ll ind, ll lo, ll hi, ll l, ll r, ll val, vector<ll> &seg, vector<ll> &lzy)
{
    if (lzy[ind] != 0)
    {
        seg[ind] += ((hi - lo + 1) * lzy[ind]);
        if (hi != lo)
        {
            lzy[2 * ind + 1] += lzy[ind];
            lzy[2 * ind + 2] += lzy[ind];
        }
        lzy[ind] = 0;
    }

    if (r < lo || l > hi)
    {
        return;
    }

    if (lo >= l && hi <= r)
    {
        seg[ind] += ((hi - lo + 1) * val);
        if (hi != lo)
        {
            lzy[2 * ind + 1] += val;
            lzy[2 * ind + 2] += val;
        }
        return;
    }
    ll mid = (lo + hi) / 2;
    lazyUpdate(2 * ind + 1, lo, mid, l, r, val, seg, lzy);
    lazyUpdate(2 * ind + 2, mid + 1, hi, l, r, val, seg, lzy);
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

    vector<ll> seg(n * 4);
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
