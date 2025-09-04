/*****************************
File: Divisor_Analysis.cpp
Time & Date:
14:59 (GMT+06:00)
Wed, 03-Sep-2025

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
#define  fastIO    cin.tie(0)->sync_with_stdio(0);

/*** Graph Movement ***/
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

/************* Constant Values *************/
const ll MOD = 1e9+7;
const ll INF = 1e18+10;

ll mod_pow(ll base, ll power, ll mod = MOD) {
    base %= mod;
    ll res = 1;
    while (power > 0) {
        if (power%2) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        power /= 2;
    }
    return res;
}

ll NOD(vector<pll> &pairs) {
    ll divs = 1LL;
    for(auto &[base, power] : pairs) {
        divs = (divs * (power+1LL))%MOD;
    }
    return divs;
}

ll POD(vector<pll> &pairs) {
    int k = pairs.size();

    vector<ll> pref(k+1, 1), suff(k+1, 1);
    ll i = 0, j = k-1;
    
    for(int i = 0, j = k-1; i < k; i++, j--) {
        pref[i+1] = pref[i] * (pairs[i].ss + 1) % (MOD - 1);
        suff[j] = suff[j+1] * (pairs[j].ss + 1) % (MOD - 1);
    }

    ll prod = 1;
    for (int i = 0; i < k; i++) {
        __int128 new_power = (__int128)pairs[i].ss * (pairs[i].ss + 1) / 2;
        new_power = new_power * pref[i] % (MOD-1);
        new_power = new_power * suff[i+1] % (MOD-1);

        prod = (prod * mod_pow(pairs[i].ff, (ll)new_power)) % MOD;
    }

    return prod;
}


ll SOD(vector<pll> &pairs) {
    ll sum = 1LL;
    for(auto &[base, power] : pairs) {
        ll num = (mod_pow(base, power + 1LL) - 1LL + MOD) % MOD;
        ll den = mod_pow(base - 1LL, MOD - 2);
        sum = sum * (num * den % MOD) % MOD;
        sum %= MOD;
    }
    return sum;
}

void solve(int tt) {
    cerr << "Testcase: " << tt << "\n";
    int n;
    cin >> n;

    vector<pll> pairs(n);
    for(auto &[base, power] : pairs) {
        cin >> base >> power;
    }

    ll nod = NOD(pairs);
    ll sod = SOD(pairs);
    ll pod = POD(pairs);

    cout << nod << " " << sod << " " << pod << nl;

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