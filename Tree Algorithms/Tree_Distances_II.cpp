/*****************************
File: Tree_Distances_II.cpp
Time & Date:
00:15 (GMT+06:00)
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

void DFS1(vector<vector<ll>>& adj, vector<ll> &subTrees, vector<ll> &distSums, int root, int parent) {
    for(int child : adj[root]) {
        if(child != parent) {
            DFS1(adj, subTrees, distSums, child, root);
            subTrees[root] += subTrees[child];
            distSums[root] += distSums[child] + subTrees[child];
        }
    }
    return;
}

void DFS2(vector<vector<ll>>& adj, vector<ll> &subTree, vector<ll> &total, int root, int parent) {
    for(int child : adj[root]) {
        if(child != parent) {
            total[child] = total[root] - subTree[child] + subTree.size() - 1 - subTree[child];
            DFS2(adj, subTree, total, child, root);
        }
    }
    return;
}

void solve(int tt) {
    cerr << "Testcase: " << tt << "\n";
    int n;
    cin >> n;

    vector<vector<ll>> adj(n+1);
    ll u, v;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<ll> subTrees(n+1, 1), distSums(n+1, 0);
    DFS1(adj, subTrees, distSums, 1, 0);
    
    vector<ll> total(n+1, 0);
    total[1] = distSums[1];
    DFS2(adj, subTrees, total, 1, 0);
    
    for(int i = 1; i <= n; i++) {
        cout << total[i] << " ";
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