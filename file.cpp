#include <bits/stdc++.h>


using namespace std;

#define pb push_back
#define ll long long int
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vs vector<string>
#define vp vector<pair<ll,ll>>
#define endl '\n'
#define f(i,a,b) for( ll i=a;i<b;i++)
#define fa(v) for (auto &it : (v))
#define all(a) (a).begin(),(a).end()
#define ff first
#define ss second
#define sp " "
#define say(name) cout << #name << endl
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define vi(a,n) vll a(n); for(auto &i:a) cin>>i
#define fr(i,a,b) for( ll i=a;i>=b;i--)
#define mp(a,b) make_pair(a,b)
#define pll pair<ll,ll>
#define accu(a) accumulate(all(a),0ll)
#define mini(a) *min_element(all(a))
#define maxi(a) *max_element(all(a))
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define um unordered_map
#define unsetbitll(x) __builtin_clzll(x)
#define print(v) for(auto &x:v) {cout<<x<<sp;} cout<<endl

const ll m=1e9+7;

int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(ans*1LL*a)%m;
        a=(a*1LL*a)%m;
        b>>=1;
    }
    return ans;
}

vector<bool> sieve(ll n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}

ll __gcd(ll a, ll b) {
    if (b == 0) return a;
    return __gcd(b, a % b);
}

ll lcm(ll a,ll b){
return (a*b)/(__gcd(a,b));
}

ll getMSBPosition(ll n) {
    if (n == 0) return -1;
    return (ll)log2(n);
}

int unsetBitsBeforeMSB(int n) {
    if (n == 0) return -1;
    int msb = 31 - __builtin_clz(n);
    return msb - __builtin_popcount(n) + 1;
}

int digitToIndex(char ch){
    if(ch=='0') return 9;
    return (ch-'1');
}

vll divisors(long long n) {
    vector<long long> divs;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i) divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

// --- Efficient Prime Check ---
bool isPrime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    if (n % 3 == 0) return n == 3;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

bool cmp(pair<ll,ll> &a, pair<ll,ll> &b){
    return a.second<b.second;
}

// --- Modular Arithmetic ---
ll mod_add(ll a, ll b, ll mod = m) { a %= mod; b %= mod; return (((a + b) % mod) + mod) % mod; }
ll mod_mul(ll a, ll b, ll mod = m) { a %= mod; b %= mod; return (((a * b) % mod) + mod) % mod; }
ll mod_sub(ll a, ll b, ll mod = m) { a %= mod; b %= mod; return (((a - b) % mod) + mod) % mod; }

ll mod_pow(ll a, ll b, ll mod = m) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll mod_inv(ll a, ll mod = m) {
    return mod_pow(a, mod - 2, mod);
}

ll mod_div(ll a, ll b, ll mod = m) {
    return mod_mul(a, mod_inv(b, mod), mod);
}

// --- Combinatorics ---
vll fact;
void precompute_factorials(int n) {
    fact.resize(n + 1); fact[0] = 1;
    f(i, 1, n + 1) fact[i] = mod_mul(fact[i - 1], i);
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return mod_div(fact[n], mod_mul(fact[r], fact[n - r]));
}

// --- Disjoint Set Union (DSU) ---
vll parent, set_size;

void dsu_make(int n) {
    parent.resize(n + 1);
    iota(all(parent), 0);
    set_size.assign(n + 1, 1);
}

ll find_set(ll i) {
    if (parent[i] == i) return i;
    return parent[i] = find_set(parent[i]);
}

void unite_sets(ll i, ll j) {
    ll root_i = find_set(i);
    ll root_j = find_set(j);
    if (root_i != root_j) {
        if (set_size[root_i] < set_size[root_j]) swap(root_i, root_j);
        parent[root_j] = root_i;
        set_size[root_i] += set_size[root_j];
    }
}

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}