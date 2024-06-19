#include<iostream>
#include<bits/stdc++.h>
#define pll pair<long long, long long>
#define tlll tuple<long long, long long, long long>
#define int long long
const int N = 100100;
using namespace std;

int32_t main() {
    // int _TEST;
    // cin >> _TEST;
    // while (_TEST--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int> > a(k, vector<int>(n));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        int ans = n;
        unordered_map<int, int> mp;
        for (int j = 0; j < n; j++) {
            mp[a[0][j]] = j;
        }
        for (int i = 0; i < k; i++) {
            int decreaseCount = 0;
            for (int j = 0; j < n - 1; j++) {
                if (mp[a[i][j]] > mp[a[i][j + 1]]) {
                    decreaseCount++;
                }
            }
            ans -= decreaseCount;
        }
        cout << ans << endl;
    return 0;
}
