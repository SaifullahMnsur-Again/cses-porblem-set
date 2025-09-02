/*****************************
File: Dynamic_Range_Sum_Queries.cpp
Time & Date:
16:04 (GMT+06:00)
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

class SegmentTree {
public:
    vector<ll> tree, arr;
    SegmentTree(ll n) {
        tree.resize(4 * n);
        arr.resize(n);
    }

    void build(ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            ll mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    ll query(ll node, ll start, ll end, ll l, ll r) {
        if (r < start || end < l) 
            return 0;
        if (l <= start && end <= r) 
            return tree[node];
        ll mid = (start + end) / 2;
        ll left = query(2 * node, start, mid, l, r);
        ll right = query(2 * node + 1, mid + 1, end, l, r);
        return left + right;
    }

    void update(ll node, ll start, ll end, ll idx, ll val) {
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
        } else {
            ll mid = (start + end) / 2;
            if (start <= idx && idx <= mid)
                update(2 * node, start, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
};

void solve(int tt) {
    cerr << "Testcase: " << tt << "\n";
    ll n, q;
    cin >> n >> q;
    SegmentTree st(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> st.arr[i];
    }
    st.build(1, 1, n);

    ll c, a, b;
    while(q--) {
        cin >> c >> a >> b;
        if(c == 1) {
            st.update(1, 1, n, a, b);
        } else {
            cout << st.query(1, 1, n, a, b) << nl;
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