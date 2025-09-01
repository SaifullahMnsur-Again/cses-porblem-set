/*****************************
File: Mountain_Range.cpp
Time & Date:
01:00 (GMT+06:00)
Tue, 12-Aug-2025

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

/************* Constant Values *************/
const int MOD = 1e9+7;
const ll INF = 1e18+10;

void solve(int tt) {
    cerr << "Testcase: " << tt << "\n";
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> indices(n);
    iota(all(indices), 0);

    set<int> st;
    for(auto i : indices) {
        st.insert(i);
    }

    sort(all(indices), [&a](size_t x, size_t y) { return a[x] < a[y]; });

    unordered_map<int, int> dp;
    for(int i = 0; i < n; i++) {
        int idx = indices[i];
        auto stIdx = st.find(idx);

        if(*stIdx > *st.begin()) {
            int left = *(--stIdx);
            ++stIdx;
            if(a[left] == a[idx]) {
                dp[left] = max(dp[left], dp[idx]);
                dp[idx] = dp[left];
            }
            else
                dp[left] = max(dp[left], dp[idx] + 1);
        }
        
        if(*stIdx < *st.rbegin()) {
            int right = *(++stIdx);
            --stIdx;
            if(a[right] == a[idx]) {
                dp[right] = max(dp[right], dp[idx]);
                dp[idx] = dp[right];
            }
            else
                dp[right] = max(dp[right], dp[idx] + 1);
        }

        st.erase(stIdx);
    }


    int maxx = 0;
    for(auto &[f, s] : dp) {
        maxx = max(maxx, s);
    }
    cout << ++maxx << nl;

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