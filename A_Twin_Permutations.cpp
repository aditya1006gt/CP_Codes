#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long int
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vs vector<string>
#define vp vector<pair<ll,ll>>
#define endl '\n'
#define f(i,a,b) for(ll i=a; i<b; i++)
#define fr(i,a,b) for(ll i=a; i>=b; i--)
#define fa(v) for(auto &it : (v))
#define all(a) (a).begin(), (a).end()
#define ff first
#define ss second
#define sp " "
#define mp(a,b) make_pair(a,b)
#define pll pair<ll,ll>
#define um unordered_map
#define accu(a) accumulate(all(a),0ll)
#define mini(a) *min_element(all(a))
#define maxi(a) *max_element(all(a))
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define print(v) for(auto &x:v){ cout<<x<<sp; } cout<<endl

const ll m = 1e9+7;

int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans = (ans*1LL*a)%m;
        a = (a*1LL*a)%m;
        b >>= 1;
    }
    return ans;
}

vector<bool> sieve(ll n){
    vector<bool> isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;
    for(ll i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(ll j=i*i;j<=n;j+=i) isPrime[j]=false;
        }
    }
    return isPrime;
}

ll __gcdll(ll a,ll b){ return b?__gcdll(b,a%b):a; }

ll lcm(ll a,ll b){ return (a/ __gcdll(a,b))*b; }

vll divisors(ll n){
    vll d;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            d.pb(i);
            if(i!=n/i) d.pb(n/i);
        }
    }
    sort(all(d));
    return d;
}

bool isPrimeFast(ll n){
    if(n<2) return false;
    if(n%2==0) return n==2;
    if(n%3==0) return n==3;
    for(ll i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}

ll mod_add(ll a,ll b,ll mod=m){ a%=mod; b%=mod; return (a+b+mod)%mod; }
ll mod_sub(ll a,ll b,ll mod=m){ a%=mod; b%=mod; return (a-b+mod)%mod; }
ll mod_mul(ll a,ll b,ll mod=m){ a%=mod; b%=mod; return (a*b)%mod; }

ll mod_pow(ll a,ll b,ll mod=m){
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

ll mod_inv(ll a,ll mod=m){ return mod_pow(a,mod-2,mod); }
ll mod_div(ll a,ll b,ll mod=m){ return mod_mul(a, mod_inv(b,mod), mod); }

vll fact;
void precompute_factorials(int n){
    fact.resize(n+1); fact[0]=1;
    f(i,1,n+1) fact[i] = mod_mul(fact[i-1], i);
}

ll nCr(int n,int r){
    if(r<0||r>n) return 0;
    return mod_div(fact[n], mod_mul(fact[r], fact[n-r]));
}

vll parent,set_size;

void dsu_make(int n){ parent.resize(n+1); iota(all(parent),0); set_size.assign(n+1,1);} 

ll find_set(ll a){ return (a==parent[a])?a:parent[a]=find_set(parent[a]); }

void unite_sets(ll a,ll b){
    a=find_set(a); b=find_set(b);
    if(a!=b){
        if(set_size[a]<set_size[b]) swap(a,b);
        parent[b]=a;
        set_size[a]+=set_size[b];
    }
}

void solve(){
    ll n;cin >>n;
    vll a(n);
    ll mx=0;
    f(i,0,n)
    {
        cin>>a[i];
        mx=max(a[i],mx);
    }
    f(i,0,n)
    cout<<(mx+1-a[i])<<" ";
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}