/*****************************
File: Shortest_Routes_II.cpp
Time & Date:
00:04 (GMT+06:00)
Wed, 03-Sep-2025

Author:
SAYFULLAH MONSUR SUJAN SARKAR
4th year B.Sc. Engineering Student
Department of Information and Communication Engineering
University of Rajshahi, Bangladesh
******************************/

#include <bits/stdc++.h>
using namespace std;

/************ Selfmade Debugger ************/
#ifdef SAIFULLAH
    #include <smss/debug>
#else
    #define dbg(...)   991
    #define line()     992
    #define cendl()    993
    #define cerr       if(false)cerr
#endif

time_t ms() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
}

/******* Policy Based Data Structure *******/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/***************** Typedefs ****************/
typedef  long long                   ll;
typedef  pair<int, int>              pint;
typedef  pair<long long, long long>  pll;
typedef  vector<int>                 vi;
typedef  vector<long long>           vll;

/******* Defines for long statements *******/
#define  pb        push_back
#define  ff        first
#define  ss        second
#define  yes       cout << "YES\n"
#define  no        cout << "NO\n"
#define  nai       cout << "-1\n"
#define  nl        "\n"
#define  all(x)    x.begin(), x.end()
#define  allr(x)   x.rbegin(), x.rend()

/**** Disable Synchronization between C++ and C Standard Streams ****/
#define  fastIO    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*** Graph Movement ***/
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

/************* Constant Values *************/
const int MOD = 1e9+7;
const ll INF = LLONG_MAX;

void floyd_warshall(int n, vector<vector<pair<ll,ll>>> &adj, vector<vector<ll>> &dist) {
    for (int i = 1; i <= n; i++) {
        for (auto &j : adj[i]) {
            ll v = j.ff;
            ll w = j.ss;
            if (w < dist[i][v]) 
                dist[i][v] = w;
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (dist[i][k] == INF) 
                continue;
            for (int j = 1; j <= n; ++j) {
                if (dist[k][j] == INF) 
                    continue;
                ll nd = dist[i][k] + dist[k][j];
                if (nd < dist[i][j])
                    dist[i][j] = nd;
            }
        }
    }

    return;
}

void solve(int tt) {
    cerr << "Testcase: " << tt << "\n";
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<ll, ll>>> adj(n+1);
    ll u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    floyd_warshall(n, adj, dist);
    
    while(q--) {
        cin >> u >> v;
        cout << (dist[u][v] == INF ? -1 : dist[u][v]) << nl;
    }
    return;
}

int32_t main(int32_t /*argc*/, char* /*argv*/[]) {
    #ifdef SAIFULLAH
        START_TIMER();
    #else
        fastIO;
    #endif

    int t = 1;
    // cin >> t;
    for( int i = 1 ; i <= t ; i++ )
        solve(i);

    #ifdef SAIFULLAH
        STOP_TIMER();
    #endif

    return 0;
}