#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define test int t; cin>>t; while(t--)
int dp[20][2][2];
vector<int>v{6,9};
int cal(string& R,int n, bool leading_zero,bool tight){
    if(n==0) return 1;
    if(dp[n][leading_zero][tight]!=-1) 
        return dp[n][leading_zero][tight];

    int temp= R[R.size()-n]-'0';
    int ub=0;
    if(tight){
        for(auto i:v){
            if(i<=temp){
                ub=i;
            }
        }
    }
    else{
        ub=9;
    }
    int res=0;
    if(leading_zero==1){
            res+=cal(R,n-1,1,0);
    }
    for(auto i:v){
           if(i>ub) break;
           res+= cal(R,n-1,0,tight&(i==ub));
    }
    
    return dp[n][leading_zero][tight]= res;
}
void solve(){
    test{
    int l,r;
    cin>>l>>r;
    l--;
    string L=to_string(l);
    string R=to_string(r);
    
    memset(dp,-1,sizeof(dp));
    int ans1 = cal(L,L.size(),1,1);
    memset(dp,-1,sizeof(dp));
    int ans2 = cal(R,R.size(),1,1);
    cout<<ans2-ans1<<endl;
    }
}
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
solve();

}