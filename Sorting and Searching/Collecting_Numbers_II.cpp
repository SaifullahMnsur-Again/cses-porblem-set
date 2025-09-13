/*****************************
File: Collecting_Numbers_II.cpp
Time & Date:
15:11 (GMT+06:00)
Wed, 10-Sep-2025

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

void update(vector<int> &val, int x, int v, int &sum) {
    sum += v - val[x];
    val[x] = v;
}

void validate(vector<int> &loc, vector<int> &val, int &sum, int x, int i) {
    update(val, x, loc[x-1] >= i, sum);
    update(val, x+1, loc[x+1] <= i, sum);
    loc[x] = i;
}

void solve(int tt) {
    cerr << "Testcase: " << tt << "\n";
    int n, m;
    cin >> n >> m;
    vector<int> key(n+1), loc(n+2), val(n+2);
    key[n+1] = n+1; loc[n+1] = n+1;
    
    for(int i = 1; i <= n; i++) {
        cin >> key[i];
        loc[key[i]] = i;
    }
    
    int sum = 1;
    for(int i = 1; i <= n; i++) {
        if(loc[i-1] > loc[i])
            val[i] = 1;
        sum += val[i];
    }

    int a, b;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        validate(loc, val, sum, key[a], b);
        validate(loc, val, sum, key[b], a);
        swap(key[a], key[b]);
        cout << sum << nl;
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