#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define vii vector<pair<int, int>>
#define vvi vector<vector<int>>
#define ll int64_t
#define yesno(check) cout << (check ? "Yes" : "No")
#define bg() begin()
#define ed() end()
#define pb push_back
#define acc() accumulate()
#define mp make_pair
#define rrep(i, n, a) for (int i = n - 1; i >= a; i--)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define Faster ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

bool predicate(int check) {
    // write logic here
    return true;
}

void solve()
{

    int n;
    cin >> n;
    vector<int> sba(n); // This is a sorted array

    rep(i, 0, n)
    {
        cin >> sba[i];
    }

    int l, r;         // Define the ranges well according to the situation
    while (l + 1 < r) // Replace 1 by the degree of accuracy u require
    {
        int mid = l + (r - l) / 2;

        if (predicate(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    // Conditions come here
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