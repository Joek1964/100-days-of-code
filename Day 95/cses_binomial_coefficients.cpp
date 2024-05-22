#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxA = 1e6;
const ll MOD = 1e9+7;

int N, a, b;
ll fact[maxA+1], inv[maxA+1];

ll inverse(ll x, ll y, ll MOD){
    ll res = 1;
    while(y){
        if(y&1){
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

void init(){
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= maxA; i++){
        fact[i] = i * fact[i-1] % MOD;
        // this is called inverse mod
        inv[i] = inverse(fact[i],MOD-2,MOD);
    }
}

int main(){
    init();
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &a, &b);
        printf("%lld\n", fact[a] * inv[b] % MOD * inv[a-b] % MOD);
    }
}