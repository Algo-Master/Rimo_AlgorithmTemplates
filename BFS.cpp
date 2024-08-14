#include <bits/stdc++.h>

#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define ll int64_t
#define bg() begin()
#define ed() end()
#define pb push_back
#define acc() accumulate()
#define mp make_pair
#define rrep(i,n,a) for(int i=n-1;i>=a;i--)
#define rep(i,a,n) for(int i=a;i<n;i++)
#define Faster ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

const ll inf = 1e18;
const ll N = 1e5;
vector<ll> adj[N];// Created an array of vectors with array size N.
// These three are optional actually depending upon the problem we adjust it
vector<ll> dis(N, inf);     // Initialized distance of all nodes to very large value
vector<bool> vis(N, false); //Created a visited array for enhancing the efficiency of code.
vector<ll> par(N, -1);     // Initialized for the parent of each node

void bfs(){
    ll n, m; cin>>n>>m;

    rep(i,0,m) {
        int u, v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<ll> q; q.push(0);
    dis[0] = 0;

    while(!q.empty()) {

        ll node = q.front();
        q.pop();

        for(auto child: adj[node]) {
            if(!vis[child]) {
                // Setting the visited array here optimized the code
                vis[child] = true;

                q.push(child);

                dis[child] = dis[node]++;
                par[child] = node;
            }
            // This is the optimal way, the approach written below just has been discussed in class
            else cout<<"cycle"<<"\n";
            /* (Discussed in class) We can add par[child] != node; too in the if condition 
            just that both can be considered in a different perspective*/
            if(par[node] != child) {
                cout<<"cycle"<<"\n";
            }
        }
    }
}

void init_code(){
    Faster;
    //#ifndef ONLINE_JUDGE
    //freopen('inputf.in','r',stdin);
    //freopen('outputf.in','w',stdout);
    //#endif
}

signed main()
{
    init_code();
    bfs();
    return 0;
}