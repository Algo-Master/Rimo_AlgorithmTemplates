#include <bits/stdc++.h>
#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define ll int64_t
#define bg() begin()
#define ed() end()
#define pb push_back
#define acc() accumulate()
#define mp make_pair
#define rrep(i, n, a) for (int i = n - 1; i >= a; i--)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define Faster ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

const int ALPHABETS = 26;
vector<vector<int>> Trie(1, vector<int>(ALPHABETS, -1));
int node_count = 0;
// hotnode[i] is the no of strings ending at node i
vector<int> hotnode(1, 0);

void insert(string &s)
{
    int cur = 0;
    rep(i, 0, s.length())
    {
        if (Trie[cur][s[i] - 'a'] == -1)
        {
            Trie[cur][s[i] - 'a'] = ++node_count;
            vector<int> vt(ALPHABETS, -1);
            Trie.pb(vt);
            hotnode.pb(0);
        }
        cur = Trie[cur][s[i] - 'a'];
    }
    hotnode[cur]++;
}

// Search whether a string is present in the trie
bool exact_search(const string &s)
{
    int cur = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (Trie[cur][s[i] - 'a'] == -1)
            return false;
        cur = Trie[cur][s[i] - 'a'];
    }
    if (hotnode[cur])
        return true;
    return false;
}

// search whether a prefix is present in the trie
bool prefix_search(const string s)
{
    int cur = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (Trie[cur][s[i] - 'a'] == -1)
            return false;
        cur = Trie[cur][s[i] - 'a'];
    }
    return true;
}

int max_depth = 0;

int max_prefix_dfs(int cur, int depth)
{
    int total_hotnodes = hotnode[cur];
    rep(i, 0, ALPHABETS)
    {
        if (Trie[cur][i] != -1)
        {
            total_hotnodes += max_prefix_dfs(Trie[cur][i], depth + 1);
        }
        if (total_hotnodes > 1)
            max_depth = max(max_depth, depth);
    }
    return total_hotnodes;
}

void solve() {
    
}

void init_code()
{
    Faster;
    // #ifndef ONLINE_JUDGE
    // freopen('inputf.in','r',stdin);
    // freopen('outputf.in','w',stdout);
    // #endif
}

signed main()
{
    init_code();
    solve();
    return 0;
}