#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void soln()
{
    tuple<int, string> person(10, "shafi");
    cout << get<1>(person) << endl;

    tuple<int, char, bool, float> thing;
    cout << get<3>(thing) << endl;
    thing = make_tuple(5, 'd', 0, 2.45);
    cout << get<3>(thing) << endl;

    tuple<int, string> person1(11, "mahmud");
    person1.swap(person);
    cout << get<1>(person) << " " << get<1>(person1) << endl;

    int x;
    string name;
    tie(x, name) = person;
    cout << name << endl;

    tuple<int, char> t1(1, 'a');
    tuple<char, int> t2('c', 5);
    tuple<int, char, char, int> t3 = tuple_cat(t1, t2); // auto t3 = tuple_cat(t1, t2);
    cout << get<2>(t3) << endl;
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