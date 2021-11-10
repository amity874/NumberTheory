#include<bits/stdc++.h>
// https://www.codechef.com/problems/GCDDIV
#define mod 1000000009
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
int main(int argc, char const *argv[]){
ll t;
std::cin>>t;
while(t--){
    ll n,k;
    std::cin>>n>>k;
    std::vector<ll>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    ll g=arr[0];
    for(int i=1;i<n;i++){
        g=gcd__(g,arr[i]);
    }
    if((n==1 && g<=k)|| g==1){
        std::cout<<"yes"<<"\n";
    }
    else{
        std::map<ll,ll>mp;
        for(int i=2;i*i<=g;i++){
            if(g%i==0){
                while(g%i==0){
                mp[i]++;
                g/=i;
            }
            }
        }
        if(g>1){
            mp[g]++;
        }
        auto it=mp.rbegin();
        if(it->first<=k){
            std::cout<<"YES"<<"\n";
        }
        else{
            std::cout<<"NO"<<"\n";
        }
    }
}
return 0;
}