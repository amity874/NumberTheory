#include<bits/stdc++.h>
// https://www.hackerearth.com/problem/algorithm/can-you-handle-the-weights/
#define ll long long int
struct Pair{
    ll gcd;
    ll x;
    ll y;
};
Pair extendedEuclid(ll a,ll b){
    if(b==0){
        Pair ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }
    Pair result=extendedEuclid(b,a%b);
    Pair ans;
    ans.gcd=result.gcd;
    ans.x=result.y;
    ans.y=(result.x-((a/b)*result.y));
    return ans;
}
ll Modinv(ll a,ll b){
    ll ans=extendedEuclid(a,b).x;
    return (ans%b+b)%b;
}
int main(int argc, char const *argv[]){
    ll t;
    std::cin>>t;
    while(t--){
        ll a,b,d;
        std::cin>>a>>b>>d;
        ll g=extendedEuclid(a,b).gcd;
        if(d%g!=0){
            std::cout<<0<<"\n";
            continue;
        }
        if(d==0){
            std::cout<<1<<"\n";
            continue;
        }
        ll y=(d%a*(Modinv(b,a)));
        if(d<y*b){
            std::cout<<0<<"\n";
            continue;
        }
        else{
            ll ans=d/b;
            ll res=(ans-y)/a;
            std::cout<<(res+1)<<"\n";
        }
    }
return 0;
}