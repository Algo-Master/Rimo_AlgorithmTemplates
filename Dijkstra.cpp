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
vector<pair<ll, ll>> adj[N];// Created an array of vectors with array size N.
vector<ll> dis(N, inf);     // Initialized distance of all nodes to very large value
vector<bool> vis(N, false); //Created a visited array for enhancing the efficiency of code.

void dijkstra(){
    ll n, m; cin>>n>>m;

    // Order of entry made: Node, Weight
    rep(i,0,m) {
        ll u, v, w; cin>>u>>v>>w;
        // Considering u and v inputs as 0 based indexing
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    // Min Heap implemented using priority queue, for understanding imp reffer -> https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
    // Order to be followed: Weight, Node, (state: optional for remodelling)
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    // Enter the Source Nodes in the specified format
    pq.push({0, 0});
    dis[0] = 0;

    while (!pq.empty()) {

        ll node = pq.top().second;
        pq.pop();

        /* This is a very important optimization which reduces the looping over of the outgoing edges from the same 
        node multiple times, this particularly helps us in a star type of pattern. Hence ensuring each node is 
        visited once only; this takes place only for the edges which were added to the pq before the node was visited 
        (Optimized visiting of nodes) */
        if(vis[node]) continue;
        else vis[node] = true;

        for(auto child: adj[node]) {
            // State Handling logic to be handled here

            /* As we can't exactly control the order in which the incoming nodes will be visiting hence what we did 
            here is not adding the nodes which already has a shorter way to reach or if it has already been visited 
            (Optimized adding of nodes in pq) */
            if(dis[child.first] > dis[node] + child.second) {
                dis[child.first] = dis[node] + child.second;
                pq.push({dis[node] + child.second, child.first});
            }
            /* Actually we can even replace the above if condition with if(!vis[child.first]) and it should run fine 
            as it doesn't allow the back traversal also stops adding more edges for the same node which is already 
            visited like the above statement, but the storage of pq will be more and also there might be some more 
            loops being executed.   This should not increase or decrease the Execution time by a huge margin.*/
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
    dijkstra();
    return 0;
}