#include<bits/stdc++.h>
#define ll long long int
struct Pair{
    ll gcd;
    ll x;
    ll y;
};
ll gcd__(ll a,ll b){
    if(b==0){
        return a;
    }
     if(b>a){
        gcd__(b,a);
    }
    return gcd__(b,a%b);
}
Pair extendedEuclid(ll a,ll b){
    if(b==0){
        Pair ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
    }
    Pair result=extendedEuclid(b,a%b);
    Pair ans;
    ans.gcd=result.gcd;
    ans.x=result.y;
    ans.y=result.x-(a/b)*result.y;
    return ans;
}
ll ModuloInverse(ll a,ll m){
    Pair ans=extendedEuclid(a,m);
    if(ans.gcd!=1){
        std::cout<<"Mod inverse not exist";
        return INT_MAX;
    }
    else{
        return ans.x;
    }
}
int main(int argc, char const *argv[])
{

return 0;
}