/*****************************
File: Sum_of_Four_Values.cpp
Time & Date:
23:46 (GMT+06:00)
Mon, 01-Sep-2025

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

void solve(int tt) {
    cerr << "Testcase: " << tt << "\n";
    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<ll, vector<pll>> sums;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            ll sum = a[i] + a[j];
            sums[sum].push_back({i+1, j+1});
        }
    }

    for(auto &[sum1, indices1] : sums) {
        if(sums.find(x - sum1) != sums.end()) {
            auto &indices2 = sums[x - sum1];
            
            for(auto &p1 : indices1 ) {
                for(auto &p2 : indices2) {
                    set<ll> st;
                    st.insert(p1.ff);
                    st.insert(p1.ss);
                    st.insert(p2.ff);
                    st.insert(p2.ss);
                    
                    if(st.size() == 4) {
                        for(auto idx : st) {
                            cout << idx << " ";
                        } cout << nl;
                        return;
                    }
                }
            }
        } 
    }
    cout << "IMPOSSIBLE\n";    

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