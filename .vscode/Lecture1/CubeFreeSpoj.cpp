// Problem Link - https://www.spoj.com/problems/PRIME1/cstart=10
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define nl				"\n"
#define pb 				push_back
#define eb				emplace_back
#define vi              std::vector<ll>
#define vs				std::vector<std::string>
#define pii             std::pair<ll,ll>
#define ump				std::unordered_map
#define mp 				std::make_pair
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }

void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<std::string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

#define MAX 100000
std::bitset<MAX> isPrime;
std::vector<int> primes;

void gen_primes() {
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i*i <= MAX; i++) {
        if(isPrime[i]) {
            for(ll j = i; j*i <= MAX; j++) {
                isPrime[j*i] = false;
            }
        }
    }
    primes.pb(2);
    for(int i = 3; i <= MAX; i+= 2) {
        if(isPrime[i]) primes.pb(i);
    }
}

void segmented_sieve(ll a, ll b) {
    std::vector<bool> seg(b-a+1, true);
    if(a == 1) a++;
    for(int i = 0; primes[i]*primes[i] <= b; i++) {
        ll p = primes[i];
        ll j = (a/p)*p;
        if(j < a) j+= p;
        for(; j <= b; j+= p) {
            if(j != p) {
                seg[j-a] = false;
            }
        }
    }
    for(ll i = a; i <= b; i++) {
        if(seg[i-a] or i == 2) {
            std::cout<<i<<"\n";
        }
    }
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int t;
    std::cin>>t;
    gen_primes();
    while(t--) {
        ll a, b;
        std::cin>>a>>b;
        segmented_sieve(a, b);
        std::cout<<"\n";
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}