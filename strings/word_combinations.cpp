#include<bits/stdc++.h>
#define f first
#define s second
#define rep(i, a, b) for(long long i = a; i < b; i++)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;

ll mod = 1e9 + 7;

// ONLY WORKS FOR SMALL CASE ENGLISH CHARS

class TrieNode {
    public:
    vector<TrieNode*> chars;
    bool is_end;
    TrieNode(): is_end(false) {
        chars.resize(26, NULL);
    }
};

class Trie {
    TrieNode* root;

    public:
    Trie(): root(NULL){}
    void insert(string s) {
        if(!root) root = new TrieNode();
        TrieNode* temp = root;
        int index = 0;
        while(index != s.length()) {
            if(!(temp -> chars[s[index] - 'a'])) {
                temp -> chars[s[index] - 'a'] = new TrieNode();
            }
            temp = temp -> chars[s[index] - 'a'];
            index++;
            if(index == s.length()) temp -> is_end = true;
        }
    }


    bool exists(string s) {
        if(!root) return false;
        TrieNode* temp = root;
        int index = 0;
        while(index != s.length()) {
            if(!(temp -> chars[s[index] - 'a'])) {
                return false;
            }
            temp = temp -> chars[s[index] - 'a'];
            index++;
        }

        return temp -> is_end;
    }

    ll get_ways(vll &dp, string &s, int index) {
        if(index == s.length()) return 1;
        if(dp[index] >= 0) return dp[index];
        dp[index] = 0;
        TrieNode* temp = root;
        int ind = index;
        temp = temp -> chars[s[ind] - 'a'];
        while(temp and ind != s.length()) {
            if(temp -> is_end) {
                ll ans = (get_ways(dp, s, ind + 1)) % mod;
                dp[index] += ans;
                dp[index] %= mod;
            }
            ind++;
            temp = temp -> chars[s[ind] - 'a'];
        }
        return dp[index];
    } 

};

int main() {
    cin.sync_with_stdio(0);
    Trie t;

    string s;
    cin >> s;

    int k;
    cin >> k;

    rep(i, 0, k) {
        string dict;
        cin >> dict;
        t.insert(dict);
    }

    vll dp(s.size() + 1, -1);
    ll ans = t.get_ways(dp, s, 0);
    cout << ans;
    return 0;
}