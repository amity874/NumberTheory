// Problem Link - https://www.spoj.com/problems/PRIME1/cstart=10
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
#define ll              long long int
#define ld              long double
#define mod             1000000007
#define inf             1e18
#define nl              "\n"
#define pb              push_back
#define eb              emplace_back
#define vi              std::vector<ll>
#define vs              std::vector<std::string>
#define pii             std::pair<ll,ll>
#define ump             std::unordered_map
#define mp              std::make_pair
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n)          n.begin(),n.end()
#define ff              first
#define ss              second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n)         __builtin_popcount(n)
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }

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

#define MAX 1000005
std::bitset<MAX> isCube;
std::vector<ll> Cube;
std::unordered_map<ll,ll>mp1;
// void cube_Free(ll n){
//  isCube.set();
//     for(ll div = 2; div*div*div <= n;div++) {
//         if(isCube[div]){
//             for(ll multiple = 1;div*div*div*multiple<=MAX;multiple++) {
//                 isCube[div*div*div*multiple]=false;
//             }
//         }
//     }
//     ll c=1;
//     mp[1]=c;
//     for(ll i=2;i<1000000;i++){
//         if(isCube[i]){
//             mp[i]=++c;
//         }
//     }
// }
void cube_Free(ll n){
    isCube.set();
    for(ll div=2;div*div*div<=MAX;div++){
        if(isCube[div]){
            for(ll multiple=1;multiple*div*div*div<=MAX;multiple++){
                isCube[multiple*div*div*div]=false;
            }
        }
    }
    ll c=1;
    mp1[1]=c;
    for(int i=2;i<=1000000;i++){
        if(isCube[i]){
            mp1[i]=++c;
        }
    }
}
int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    ll c=1;
    ll t;
    std::cin>>t;
    cube_Free(1000000);
    while(t--) {
       ll n;
       std::cin>>n;
       if(mp1.count(n)){
           std::cout<<"Case "<<c++<<": "<<mp1[n]<<"\n";
       }
       else{
             std::cout<<"Case "<<c++<<": "<<"Not Cube Free "<<"\n";
       }
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}