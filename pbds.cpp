#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void soln()
{
    pbds A;
    A.insert(1);
    A.insert(4);
    A.insert(2);
    A.insert(6);

    for (auto x : A)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "2nd element: " << *A.find_by_order(1) << endl;
    cout << "no. element lower than 5: " << A.order_of_key(5) << endl;
    cout << "lower bound of 5: " << *A.lower_bound(5) << endl;
    cout << "upper bound of 5: " << *A.upper_bound(5) << endl;

    A.erase(1); // removes 1
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