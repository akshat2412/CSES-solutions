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

    char temp[2*s.length() + 3];
    temp[0] = '$';
    temp[1] = '#';
    temp[2*s.length() + 2] = '@';
    
    rep(i, 0, s.length()) {
        temp[2*i + 2] = s[i];
        temp[2*i + 3] = '#';
    }
    ll sz = 2*s.length() + 3;
    vll manacher(sz, 0);

    int r = 0, c = 0;

    ll max_len = 0;
    ll index = -1;
    rep(i, 1, sz) {
        int mirror = 2*c - i;

        if(i < r) {
            manacher[i] = min(manacher[mirror], r - i);
        }

        while(temp[i + manacher[i] + 1] == temp[i - (manacher[i] + 1)]) manacher[i]++;
        if(i + manacher[i] > r) {
            c = i;
            r = i + manacher[i];
        }
        if(manacher[i] > max_len) {
            max_len = manacher[i];
            index = i;
        }
        if(manacher[i] == s.length()) break;
    }

    // rep(i, 0, sz) {
    //     cout << temp[i] << " ";
    // }
    // cout << "\n";
    // rep(i, 0, sz) {
    //     cout << manacher[i] << " ";
    // }
    // cout << "\n";
    rep(i, 0, sz) {
        if(manacher[i] == max_len) {
            // ll start = manacher[index] % 2 == 0 ? index - (manacher[index] - 1) : index - (manacher[index] / 2) * 2;
            ll start = index - manacher[index];
            string ans = "";
            while(start != index + manacher[index]) {
                if(temp[start] != '#') ans += temp[start];
                start += 1;
            }
            cout << ans;
            break;
        }
    }
    return 0;
}