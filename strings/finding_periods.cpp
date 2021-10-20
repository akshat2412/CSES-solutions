#include<bits/stdc++.h>
#define f first
#define s second
#define rep(i, a, b) for(long long i = a; i < b; i++)
#define rep_rev(i, a, b) for(long long i = a; i >= b; i--)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;

int main() {
    cin.sync_with_stdio(0);


    string s;
    cin >> s;
    vll z(s.length(), 0);
    multiset<ll> ms;

    int c = 0, r = 0;
    rep(i, 1, s.length()) {
        if(i > r) {
            c = i;
        }
        int mirror = i - c;

        if(i <= r) {
            z[i] = min(z[mirror], r - i + 1);
        }

        while(i + z[i]< s.length() and s[i + z[i]] == s[z[i]]) z[i]++;
        if(i + z[i] - 1> r) {
            r = i + z[i] - 1;
            c = i;
        }
        ms.insert(z[i]);
    }

    rep(i, 0, s.length()) {
        if(i + z[i] == s.length()) {
            cout << i << " ";
        }
    }
    cout << s.length();
    return 0;
}