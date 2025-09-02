/*****************************
File: Next_Prime.cpp
Time & Date:
13:48 (GMT+06:00)
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
vector<int> primes;

void sieve(ll n) {
    vector<bool> check(n + 1, true);
    check[0] = check[1] = false;

    for (ll i = 2; i * i <= n; ++i) {
        if (check[i]) {
            for (ll j = i * i; j <= n; j += i)
                check[j] = false;
        }
    }

    primes.push_back(2);
    for(ll i = 3; i <= n; i+=2) {
        if(check[i]) {
            primes.push_back(i);
        }
    }
}

void solve(int tt) {
    cerr << "Testcase: " << tt << "\n";
    ll n;
    cin >> n;
    while(true) {
        n++;
        bool isPrime = true;
        for(int i = 0; i < primes.size() && primes[i]*primes[i] <= n; i++) {
            if(n%primes[i] == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            break;
    }
    cout << n << nl;

    return;
}

int32_t main(int32_t /*argc*/, char* /*argv*/[]) {
    #ifdef SAIFULLAH
        START_TIMER();
    #else
        fastIO;
    #endif

    int t = 1;
    cin >> t;

    sieve(1e6+10);
    for( int i = 1 ; i <= t ; i++ )
        solve(i);

    #ifdef SAIFULLAH
        STOP_TIMER();
    #endif

    return 0;
}