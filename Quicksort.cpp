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

int partition(vector<int> &arr, int low, int high)
{

    int i = low, j = high;

    while (i < j)
    {
        while (arr[i] <= arr[low] && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > arr[low] && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high)
{

    if (low < high)
    {
        int pivot_Index = partition(arr, low, high);
        qs(arr, low, pivot_Index - 1);
        qs(arr, pivot_Index + 1, high);
    }
}

// By Hoare's partition
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    rep(i, 0, n)
    {
        cin >> arr[i];
    }

    qs(arr, 0, arr.size());
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