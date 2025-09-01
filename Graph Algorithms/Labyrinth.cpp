/*****************************
File: Labyrinth.cpp
Time & Date:
22:54 (GMT+06:00)
Wed, 13-Aug-2025

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


bool is_valid(int i, int j, int n, int m) {
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void BFS(vector<string>& vstr, int start_i, int start_j, int n, int m, vector<vector<pint>>& parent, vector<vector<int>> &dist) {
    queue<pint> q;
    q.push({start_i, start_j});
    dist[start_i][start_j] = 0;
    
    while(!q.empty()) {
        pint curr = q.front();
        q.pop();
        int i = curr.ff;
        int j = curr.ss;
        dbg(curr);
        
        if(!is_valid(i, j, n, m) || vstr[i][j] == '#')
            continue;
        // cerr << "From: " << i << "," << j << nl;
        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            // cerr << "At: " << ni << "," << nj << nl;

            if(is_valid(ni, nj, n, m) && (vstr[ni][nj] == '.' || vstr[ni][nj] == 'B') && dist[ni][nj] > dist[i][j]+1) {
                q.push({ni, nj});
                parent[ni][nj] = make_pair(i, j);
                dist[ni][nj] = dist[i][j] + 1;
                // cerr << "Update: " << ni << "," << nj << nl;
                // dbg(parent[ni][nj]);
                // dbg(dist[ni][nj]);
            }
        }
    }
    return;
}

char getDirection(int x1, int y1, int x2, int y2) {
    if(x2 < x1)
        return 'U';
    if(x2 > x1)
        return 'D';
    if(y2 < y1)
        return 'L';
    if(y2 > y1)
        return 'R';
}

void solve(int tt) {
    cerr << "Testcase: " << tt << "\n";
    int n, m;
    cin >> n >> m;
    vector<string> vstr(n);
    for(auto &str : vstr) {
        cin >> str;
    }

    vector<vector<int>> dist(n, vector<int>(m, MOD));
    vector<vector<pint>> parent(n, vector<pint>(m, make_pair(-1, -1)));
    pint locA, locB;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vstr[i][j] == 'A') {
                locA = {i,j};
            } else if(vstr[i][j] == 'B') {
                locB = {i, j};
            }
        }
    }
    dbg(locA);
    dbg(locB);

    BFS(vstr, locA.ff, locA.ss, n, m, parent, dist);
    int i = locB.ff;
    int j = locB.ss;

    if(dist[i][j] == MOD) {
        no;
        return;
    }
    yes;
    cout << dist[i][j] << nl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dist[i][j] == MOD)
                cerr << -1 << " ";
            else
                cerr << dist[i][j] << " ";
        } cerr << nl;
    }

    stack<char> path;
    cerr << "Parents: "; 
    while(is_valid(i, j, n, m)){
        pint par = parent[i][j];
        cerr<< "(" << par.ff << "," << par.ss << ") " ;
        if(is_valid(par.ff, par.ss, n, m))
            path.push(getDirection(par.ff, par.ss, i, j));
        i = par.ff, j = par.ss;
    }
    while(!path.empty()) {
        cout << path.top();
        path.pop();
    } cout << nl;
    
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