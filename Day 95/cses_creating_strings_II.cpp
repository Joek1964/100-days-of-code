#include<iostream>
#include<bits/stdc++.h>
#define pll = pair<ll, ll>
#define tlll = tuple<ll, ll, ll>
#define _test   int _TEST; cin>>_TEST; while(_TEST--)
#define ll long long
#define dis(x) cout<<x<<endl
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ff first
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define ASST(x,y,z) assert(x >= y && x <= z)
#define ss second
#define rep(i,a,n) for(int i = (a); i <= (n); ++i)
#define sz(a) (int)(a.size())
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
const int N = 100100;
const ll M = 1e9+7;
const int maxA = 1e6;
using namespace std;
ll exp(ll a,ll b,ll c){
        ll res =1;
        while(b){
            if(b&1){
                res =(res*a)%M;
            }
            a = (a*a)%M;
            b=b>>1;
            // res=res%M;
        }
        return res;
    }
void solve(){
    string s;
    cin>>s;
    unordered_map<char,ll>mp;
    for(auto it:s){
        mp[it]++;
    }
    // ####### static keyword is important
//     Stack Overflow: If your arrays f and inv are too large, declaring them without static might
//      cause a stack overflow because the stack has a limited size. By making them static, you 
//      move them to a different memory segment that is typically larger and can accommodate 
//      larger arrays without causing stack overflow.

// Uninitialized Memory: If you declare f and inv without static, their elements might contain 
// garbage values initially. This could lead to undefined behavior when you try to access these elements. 
// By using static, the arrays are initialized to zero, which could prevent such issues.
    static ll f[maxA + 1];  
     static ll inv[maxA + 1];
    f[0]=1;
    inv[0]=1;
    for(int i =1;i<=maxA;i++){
        f[i] = (i*f[i-1])%M;
        inv[i] = exp(f[i],M-2,M);
    }
    int x = s.size();
    int ans = (f[x]%M);
    int k = ans*inv[3];
    for(auto it:mp){
        ans = (ans* inv[it.second])%M;
    }

    cout<<ans<<endl;
}
int main(){
int t;
cin>>t;
while(t--){
    solve();
}	
    return 0;
}