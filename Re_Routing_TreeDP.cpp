// Problem for 
// https://codeforces.com/contest/1092/problem/F

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> T_set; // PBDS_set
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> T_multiset; // PBDS_multiset
void myerase(T_multiset &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    T_multiset::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
int gcd(int a,int b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}
int lcm(int &a, int &b) { return a * b / __gcd(a, b); }

const int MAX = (int) 1000;
int spf[MAX];
bool vis[MAX];
const ll inf=1e18;

void spf_Sieve(){
    spf[1]=1;
    memset(vis,false,MAX);
    for(int i=2;i<MAX;i+=2) {
        vis[i]=true;
        spf[i]=2;
    }

    for(ll i=3;i<MAX;i+=2){
        if(!vis[i]){
            spf[i]=i;
            for(ll j=i; (i*j)<MAX; j+=2){
                if(!vis[i*j]){
                    vis[i*j]=true;
                    spf[i*j] = i;
                }
            }
        }
    }
}

vector<int> prime_factors(int dvd){

    vector<int> pf;
    while(dvd!=1){
        int x = spf[dvd], c=0;
        while(spf[dvd]==x){
            c++;
            dvd = dvd/x;
        }
        pf.push_back(c);
    }
    return pf;
}

long long binexp(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

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