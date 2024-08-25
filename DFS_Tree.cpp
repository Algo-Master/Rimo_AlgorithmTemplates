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

const ll N = 2e5;
vector<ll> adj[N + 1];

void dfs_tree(int curr, int par)
{

    // write entry logic here
    cout << curr << "\n";
    // IT is advised not to change logic here in the loop instead change the logic in the entry and exit regions
    for (auto child : adj[curr])
    {
        if (child != par)
        {
            dfs_tree(child, curr);
        }
    }
    // write exit logic here
    cout << "Exit" << "\n";
}

void solve()
{
    dfs_tree(0, -1);
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
    int t, i = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}