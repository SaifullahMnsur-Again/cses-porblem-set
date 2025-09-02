/*****************************
File: Range_Update_Queries.cpp
Time & Date:
16:31 (GMT+06:00)
Tue, 02-Sep-2025

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

class LazySegmentTree {
public:
    int n;
    vector<ll> tree, lazy, arr;

    LazySegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
        lazy.resize(4 * n);
        arr.resize(n);
    }

    void propagate(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += (r - l + 1) * lazy[node];
            if (l != r) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void build(int node = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int i, int j, ll val, int node = 1, int l = 0, int r = -1) {
        if (r == -1)
            r = n - 1;
        propagate(node, l, r);
        if (r < i || l > j) 
            return;
        if (i <= l && r <= j) {
            lazy[node] += val;
            propagate(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(i, j, val, node * 2, l, mid);
        update(i, j, val, node * 2 + 1, mid + 1, r);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    ll query(int i, int j, int node = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        propagate(node, l, r);
        if (r < i || l > j) 
            return 0;
        if (i <= l && r <= j) 
            return tree[node];
        int mid = (l + r) / 2;
        ll left = query(i, j, node * 2, l, mid);
        ll right = query(i, j, node * 2 + 1, mid + 1, r);
        return left + right;
    }
};

void solve(int tt) {
    cerr << "Testcase: " << tt << "\n";
    int n, q;
    cin >> n >> q;
    LazySegmentTree lst(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> lst.arr[i];
    }
    lst.build(1, 1, n);

    int c, a, b, d;
    while(q--) {
        cin >> c >> a;
        if(c == 1) {
            cin >> b >> d;
            lst.update(a, b, d, 1, 1, n);
        } else {
            cout << lst.query(a, a, 1, 1, n) << nl;
        }
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