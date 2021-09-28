#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9 + 7;

int findUniqueSubstrings(string s, string goodBad, int k) {
    set<pair<int, int>> st;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int hash1 = 0, hash2 = 0;
        int pr1 = 1;
        int pr2 = 1;
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (goodBad[s[j] - 'a'] == '0') cnt++;
            if (cnt > k) break;

            hash1 = (hash1 + ((s[j] - 'a' + 1) * pr1) % mod) % mod;
            hash2 = (hash2 + ((s[j] - 'a' + 1) * pr2) % mod) % mod;
            st.insert({hash1, hash2});
            pr1 = (pr1 * 31) % mod;
            pr2 = (pr2 * 37) % mod;
        }
    }
    return st.size();
}

signed main() {
    string s;
    cin >> s;
    string goodBad;
    cin >> goodBad;
    int k;
    cin >> k;
    int ans = findUniqueSubstrings(s, goodBad, k);
    cout << ans << endl;
    return 0;
}