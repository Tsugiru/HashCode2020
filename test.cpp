#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

struct int_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct pair_hash {
    size_t operator()(pii x) const {
        return int_hash{}(x.first) ^ (int_hash{}(x.second) << 16);
    }
};

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<cd> vcd;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef vector<vvi> vvvi;
typedef unordered_map<int, int, int_hash> umii;
typedef unordered_map<ll, ll, int_hash> umll;
typedef unordered_set<int, int_hash> usi;
typedef unordered_set<ll, int_hash> usll;
typedef unordered_set<pii, pair_hash> uspii;
typedef queue<int> qi;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int inf = numeric_limits<int>::max();
const int MX = 100001; //check the limits, dummy



vector<int> sf(int n) {
    map<int, int> p;
    int count = 0;
    for(int i = 2; i * i < n; i++) {
        while(n % i == 0) {
            count++;
            n /= i;
            p[i]++;
        }
    }
    if(n > 1) {
        p[n]++;
        count++;
    }
    if(count < 3) {
        return {-1, -1, -1};
    }

    int a = begin(p)->first;
    if(--p[a] == 0) p.erase(a);
    int b = begin(p)->first;
    if(--p[b] == 0) p.erase(b);

    if(b == a) {
        b *= begin(p)->first;
        --(begin(p)->second);
    }

    int c = 1;
    for(auto &elem : p) {
        for(int i = 0; i < elem.second; i++) c *= elem.first;
    }

    if(c == 1 || c == a || c == b) {
        return {-1, -1, -1};
    }

    return {a, b, c};
}

vector<int> ss(int n) {
    for(int i = 2; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; i * j * k <= n; k++) {
                if(i * j * k == n) {
                    return {i, j, k};
                }
            }
        }
    }
    return {-1, -1, -1};
}

class BigObject {
private:
    BigObject(int a) {
        cout << a << endl;
        cout << "constructor. " << endl;
}
    ~BigObject() {
        cout << "destructor."<< endl;
    }
    BigObject(const BigObject&) {
        cout << "copy constructor." << endl;
 }
    BigObject(const BigObject&&) {
        cout << "move constructor." << endl;
 }
};

//counts occurences of t in s
int count_occurences(const std::string& t, const std::string &s) {
    if(t.size() > s.size()) return 0;
    int result = 0;
    for(int i = 0; i + t.size() <= s.size(); i++) {
        result += s.substr(i, t.size()) == t;
    }
    return result;
}

enum Sign
		{
			negative = -1,
			positive = 1
		};
 
int main() {
    Sign m_sign = negative;
    cout << m_sign << endl;
}