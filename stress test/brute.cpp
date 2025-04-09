#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define int long long 
#define   mod             1000000007
#define test int t; cin>>t; while(t--)

void solve(){
    test{
    int l,r;
    cin>>l>>r;
    int cnt=0;
    for(int i=l;i<=r;i++){
        string s=to_string(i);
        int n=s.size();
        int flag=0;
        for(int j=0;j<n;j++){
            if(s[j]!='6' && s[j]!='9'){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    }

}
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
solve();

}