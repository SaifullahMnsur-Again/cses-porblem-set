/*****************************
File: Counting_Coprime_Pairs.cpp
Time & Date:
14:13 (GMT+06:00)
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
#define int ll

int N = 1e6+10;

int nc2(int n) {
    return (n * (n-1)) / 2;
}

void solve(int tt) {
    cerr << "Testcase: " << tt << "\n";
    int n;
    cin >> n;
    vector<int> freq(1e6+10);
    int inp;
    for(int i = 0; i < n; i++) {
        cin >> inp;
        freq[inp]++;
    }

    vector<int> baad(N);
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            baad[i] += freq[j];
        }
    }

    vector<int> mu(N, 0), primes;
    vector<bool> is_comp(N, false);
    mu[1] = 1;
    for(int i = 2; i < N; i++) {
        if(!is_comp[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }
        for(int prime : primes) {
            int mult = i * prime;
            if(mult >= N)
                break;
            is_comp[mult] = true;
            if(i % prime == 0) {
                mu[mult] = 0;
                break;
            } else {
                mu[mult] = -mu[i];
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < N; i++) {
        if(baad[i] >= 2 && mu[i] != 0) {
            ans += mu[i] * nc2(baad[i]);
        }
    }
    cout << ans << nl;
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