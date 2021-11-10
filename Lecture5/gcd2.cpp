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
    ll t;
    std::cin>>t;
    while(t--){
        ll a;
        std::cin>>a;
        std::string s;
        std::cin>>s;
        if(a==0){
            std::cout<<s<<"\n";
            continue;
        }
        ll ans=0;
        for(int i=0;i<s.size();i++){
            ans=((ans%a*(10)%a)%a+s[i]-'0')%a;
        }
        std::cout<<gcd__(ans,a)<<"\n";
    }
return 0;
}