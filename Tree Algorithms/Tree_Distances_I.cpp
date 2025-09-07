/*****************************
File: Tree_Distances_I.cpp
Time & Date:
00:07 (GMT+06:00)
Sun, 07-Sep-2025

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
const ll INF = 1e18+10;

int DFS(vector<vector<int>>& adj, vector<int> &depthHist, int root, int parent, int depth) {
    int maxxDepth = depth;
    for(auto child : adj[root]) {
        if(child != parent) {
            maxxDepth = max(maxxDepth, DFS(adj, depthHist, child, root, depth+1));
        }
    }
    depthHist[root] = depth;
    return maxxDepth;
}

void solve(int tt) {
    cerr << "Testcase: " << tt << "\n";
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    int u, v;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> fromRandom(n+1, 0);
    int maxxDepth = DFS(adj, fromRandom, 1, 0, 0);
    
    int leaf = 0;
    while(fromRandom[leaf] != maxxDepth)
        leaf++;
    
    vector<int> fromLeft(n+1, 0);
    maxxDepth = DFS(adj, fromLeft, leaf, 0, 0);

    leaf = 0;
    while(fromLeft[leaf] != maxxDepth)
        leaf++;

    vector<int> fromRight(n+1, 0);
    maxxDepth = DFS(adj, fromRight, leaf, 0, 0);

    for(int i = 1; i <= n; i++) {
        cout << max(fromLeft[i], fromRight[i]) << " ";
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