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

const ll inf = 1e18;
const ll N = 1e5;
vector<ll> adj[N]; // Created an array of vectors with array size N.
// These three are optional actually depending upon the problem we adjust it
vector<bool> vis(N, false); // Created a visited array for enhancing the efficiency of code.

void toposort()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> indegree(n, 0);
    vector<ll> order;

    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        indegree[v]++;
    }

    queue<ll> q;
    rep(i,0,n) {
        if(indegree[i]==0) q.push(i);
    }

    while (!q.empty())
    {

        ll node = q.front();
        order.pb(node);
        q.pop();

        for (auto child : adj[node])
        {
            if (!vis[child])
            {

                indegree[child]--;

                if(indegree[child] == 0) {
                    vis[child] = true;
                    q.push(child);
                }
            }
        }
    }
    for(auto e: order) {
        cout<<e<<" ";
    } cout<<"\n";
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
    toposort();
    return 0;
}