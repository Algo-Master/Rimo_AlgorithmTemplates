#include <bits/stdc++.h>

#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define ll int64_t
#define bg() begin()
#define ed() end()
#define pb push_back
#define yesno(check) check ? "Yes" : "No";
#define acc() accumulate()
#define mp make_pair
#define rrep(i, n, a) for (int i = n - 1; i >= a; i--)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define Faster ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

const ll N = 2e5;
vector<ll> adj[N];
vector<ll> color(N, 0);

vector<int> time_in, time_out;
int dfs_timer = 0;

void dfs(int cur)
{
    time_in[cur] = dfs_timer++;
    color[cur] = 1;
    for (auto child : adj[cur])
    {
        if (color[child] == 0)
            dfs(child);
    }
    color[cur] = 2;
    time_out[cur] = dfs_timer++;
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