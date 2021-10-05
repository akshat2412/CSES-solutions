#include<bits/stdc++.h>
#define f first
#define s second
#define rep(i, a, b) for(long long i = a; i < b; i++)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;

void build_lps(vector<int> &lps, string &pattern) {

    int j = 0;
    for(int i = 1; i < pattern.length();) {
        if(pattern[i] == pattern[j]) {
            lps[i] = j + 1;
            j++;
            i++;
        }
        else if(j > 0) {
            j = lps[j - 1];
        }
        else {
            lps[i] = 0;
            j = 0;
            i++;
        }
    }
}

ll count_occurances(string &text, string &pattern, vector<int> &lps) {
    int i = 0, j = 0;
    ll count = 0;
    while(i < text.length()) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
            if(j == pattern.length()) {
                count++;
                j = lps[j - 1];
            }
        }
        else if(j > 0) {
            j = lps[j - 1];
        }
        else {
            j = 0;
            i++;
        }
    }

    return count;
}

int main() {
    cin.sync_with_stdio(0);

    string text;
    cin >> text;

    string pattern;
    cin >> pattern;
    
    vector<int> lps(pattern.size(), 0);
    build_lps(lps, pattern);

    ll count = count_occurances(text, pattern, lps);
    cout << count;
    return 0;
}