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

// 5 8
// ########
// #.A#...#
// #.##.#B#
// #......#
// ########

// For these types of problems take the Order as: {y, x} this will make the code consitent and better management

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<string> grid(n);
    ll srcx, srcy, desx, desy;

    vector<vector<ll>> dis(n, vector<ll>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<ll, ll>>> par(n, vector<pair<ll, ll>>(m, {-1, -1}));

    rep(i, 0, n)
    {
        cin >> grid[i];
        rep(j, 0, m)
        {
            if (grid[i][j] == 'A')
                srcy = i, srcx = j;
            else if (grid[i][j] == 'B')
                desy = i, desx = j;
        }
    }

    ll dy[4] = {-1, 0, 1, 0};
    ll dx[4] = {0, 1, 0, -1};

    queue<pair<ll, ll>> q;
    q.push({srcy, srcx});
    vis[srcy][srcx] = true;
    par[srcy][srcx] = {srcy, srcx};

    while (!q.empty())
    {

        auto node = q.front();
        // cerr<<node.first<<" "<<node.second<<"\n";
        q.pop();

        rep(i, 0, 4)
        {

            ll y = node.first + dy[i], x = node.second + dx[i];

            if (0 <= y && y < n && 0 <= x && x < m)
            {
                if (grid[y][x] != '#' && !vis[y][x])
                {

                    vis[y][x] = true;
                    dis[y][x] = dis[node.first][node.second] + 1;
                    par[y][x] = {node.first, node.second};

                    q.push({y, x});
                    if (y == desy && x == desx)
                        break;
                }
            }
        }
    }

    if (vis[desy][desx])
    {
        string s;
        cout << "YES" << "\n"
             << dis[desy][desx] << "\n";

        while (desy ^ srcy || desx ^ srcx)
        {
            auto node = par[desy][desx];
            ll y = node.first, x = node.second;

            if (y < desy)
                s += 'D';
            else if (desy < y)
                s += 'U';
            else if (x < desx)
                s += 'R';
            else
                s += 'L';

            desy = y, desx = x;
        }
        reverse(s.bg(), s.ed());
        cout << s << "\n";
        return;
    }
    cout << "NO" << "\n";
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