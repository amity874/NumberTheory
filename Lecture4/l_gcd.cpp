#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
int main(int argc, char const *argv[])
{
    int t;
    std::cin>>t;
    while (t--){
        ll n;
        std::cin>>n;
        std::unordered_map<ll,ll>mp;
        for(int i=0;i<n;i++){
            ll x;
            std::cin>>x;
           if(mp.count(x)){
               mp[x]=mp[x]+1;
           }
           else{
               mp[x]=1;
           }

        }
        ll ans=0;
        for(auto i:mp){
            int y=i.first;
            if(mp.count(2&y)){
                ans+=mp[y]*mp[2*y];
            }
        }
        std::cout<<ans<<"\n";
    }    
return 0;
}