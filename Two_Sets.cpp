/*****************************
File: Two_Sets.cpp
Time & Date:
15:03 (GMT+06:00)
Wed, 23-Jul-2025

Author:
SAYFULLAH MONSUR SUJAN SARKAR
3rd year B.Sc. Engineering Student
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
#define int ll

void solve(int tt) {
    cerr << "Testcase: " << tt << "\n";
    int n;
    cin >> n;
    
    int sum = (n * (n + 1)) / 2;
    
    if(sum%2) {
        no;
    } else {
        yes;
        queue<int> q;
        for(int i = n; i >= 1; i--) {
            q.push(i);
        }
        set<int> st1, st2;
        sum /= 2;
        while(sum > 0) {
            if(sum >= q.front()) {
                st1.insert(q.front());
                sum -= q.front();
            } else {
                st2.insert(q.front());
            }
            q.pop();
        }
        while(!q.empty()) {
            st2.insert(q.front());
            q.pop();
        }

        cout << st1.size() << nl;
        for(auto i : st1) {
            cout << i << " ";
        } cout << nl;

        cout << st2.size() << nl;
        for(auto i : st2) {
            cout << i << " ";
        } cout << nl;

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