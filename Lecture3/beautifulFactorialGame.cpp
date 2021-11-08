#include<bits/stdc++.h>
#define ll long long int
int main(int argc, char const *argv[])
{
    ll t;
    std::cin>>t;
    ll cnt=0;
    while (t--){
        ll n,k;
        std::cin>>n>>k;
        ll ans=INT_MAX;
        for(int i=2;i*i<=k;i++){
            ll a1=0;
            while (k%i==0){
                a1++;
                k/=i;
            }
            if(a1==0)continue;
            ll prime=i;
            ll b1=0;
            while(prime<=n){
                b1+=(n/prime);
                prime*=i;
            }
            ans=std::min(ans,b1/a1);
        }
        if(k>1){
            ll b1=0;
            ll prime=k;
            while (prime<=n){
                b1+=(n/prime);
                prime*=k;
            
           }
         ans=std::min(ans,b1);
    }
    if(ans==INT_MAX){
        ans=0;
    }
    std::cout<<"Case "<<++cnt<<": "<<ans<<"\n";
    }
return 0;
}