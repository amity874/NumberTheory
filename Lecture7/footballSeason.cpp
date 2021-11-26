#include<bits/stdc++.h>
// https://codeforces.com/problemset/problem/1244/C
#define ll long long int
struct Pair{
    ll gcd;
    ll x;
    ll y;
};
Pair extendedEuclid(ll a,ll b){
    if(b==0){
        Pair res;
        res.gcd=a;
        res.x=1;
        res.y=0;
        return res;
    }
    Pair result=extendedEuclid(b,a%b);
    Pair res;
    res.gcd=result.gcd;
    res.x=result.y;
    res.y=(result.x-((a/b)*result.y));
    return res;
}
ll Modinv(ll a,ll b){
    ll ans=extendedEuclid(a,b).x;
    return (ans%b+b)%b;
}
int main(int argc, char const *argv[])
{
    ll n;
    int p;
    int w;
    int d;
    std::cin>>n>>p>>w>>d;
    ll g=extendedEuclid(w,d).gcd;
    if((p%g)!=0){
        std::cout<<"ui";
        return -1;
    }
    w/=g;
    d/=g;
    ll y=((p%w)*Modinv(d,w));
    ll x=(p-(d*(y)))/w;
    if(x<0){
        return -1;
    }
    if((x+y)>n){
        return -1;
    }
    else{
        ll z=(n-x-y);
        std::cout<<x<<" "<<y<<" "<<z; 
    }
return 0;
}