#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void soln()
{
    vector<ll> vc = {7, 7, 7, 5, 9, 9, 5, 7};
    cout << "before:" << endl;
    for (int i = 0; i < vc.size(); i++)
    {
        cout << vc[i] << " ";
    }

    ll new_sz = unique(vc.begin(), vc.end()) - vc.begin();

    cout << "\nafter:" << endl;
    for (int i = 0; i < new_sz; i++)
    {
        cout << vc[i] << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    {
        soln();
    }
    return 0;
}