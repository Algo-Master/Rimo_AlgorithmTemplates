// Problem for 
// https://codeforces.com/contest/1092/problem/F

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

const ll N = 2e5;
vector<ll> adj[N +1];
ll cost[N+1], sum[N+1], a[N+1];

ll ans = 0;

void preCalc(ll node, ll prev) {

    sum[node] = a[node];
    cost[node] = 0;
    for(auto child: adj[node]) {
        if(child!=prev) {
            preCalc(child, node);
            sum[node] += sum[child];
            cost[node] += (cost[child] + sum[child]);
        }
    }
}

void reroot(ll node, ll prev) {

    ans = max(ans, cost[node]);
    for(auto child: adj[node]) {
        if(child!=prev) {
            // Calculating the cost of tree rooted at node without the subtree starting from child.
            ll newCost = cost[node] - (cost[child] + sum[child]);
            // Now finally getting the cost of tree rooted at child.
            cost[child]+=newCost + (sum[node] - sum[child]);
            sum[child] = sum[node];
            reroot(child, node);
        }
    }
}

void solve(){

    ll n; cin>>n;

    rep(i,1,n+1) {
        cin>>a[i];
    }
    rep(i,0,n-1) {
        ll u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    preCalc(1, -1);
    reroot(1, -1);
    cout<<ans<<"\n";
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
    solve();
    return 0;
}