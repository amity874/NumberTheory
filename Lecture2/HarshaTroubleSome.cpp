// https://www.codechef.com/problems/COWA19C
#include<bits/stdc++.h>
#define ll long long int
#define mod             1000000007

int main(int argc, char const *argv[])
{
    ll n=100005;
    std::vector<ll>result(n,1);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            result[j]=(result[j]*(i+1))%mod;
        }
    }
    ll t;
    std::cin>>t;
    while (t--){
        ll x;
        std::cin>>x;
        std::cout<<(result[x]+mod-1)%mod<<"\n";
    }
return 0;
}