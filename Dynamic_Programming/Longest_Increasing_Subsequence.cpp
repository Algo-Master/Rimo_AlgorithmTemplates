#include <bits/stdc++.h>

#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define ll int64_t
#define yesno(check) cout<<(check ? "Yes" : "No")
#define bg() begin()
#define ed() end()
#define pb push_back
#define acc() accumulate()
#define mp make_pair
#define rrep(i,n,a) for(int i=n-1;i>=a;i--)
#define rep(i,a,n) for(int i=a;i<n;i++)
#define Faster ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;

int longest_seq(int i, int prev, vector<int> &arr, vector<vector<int>> &dp) {

    if(i<0) return 0;

    if(dp[i][prev] != -1) return -1;

    int tk = 0;
    if(arr[i] < arr[prev]) tk = 1 + longest_seq(i-1, i, arr, dp);

    int nt_tk = longest_seq(i-1, prev, arr, dp);

    return dp[i][prev] = max(tk, nt_tk);
}

void solve(){

    int n; cin>>n;
    vector<int> arr(n + 1);
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    for(int i = 0; i<n ; i++) {
        cin>>arr[i];
    }
    arr[n] = 1e9;

    cout<<longest_seq(n-1, n, arr, dp);
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