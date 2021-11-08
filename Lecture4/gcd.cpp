#include<bits/stdc++.h>
#define ll long long int
ll gcd__(ll a,ll b){
    if(b==0){
        return a;
    }
     if(b>a){
        gcd__(b,a);
    }
    return gcd__(b,a%b);
}
int main(int argc, char const *argv[])
{
    ll a,b;
    std::cin>>a>>b;
    std::cout<<(a,b);
return 0;
}