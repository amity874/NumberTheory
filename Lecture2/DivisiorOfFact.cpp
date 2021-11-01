#include<bits/stdc++.h>
#define ll long long int
#define MAX 50005
#define mod             1000000007
std::bitset<MAX> isPrime;
std::vector<int>Prime;
void GeneratePrime() {
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i*i <= MAX; i++) {
        if(isPrime[i]) {
            for(ll j = i; j*i <= MAX; j++) {
                isPrime[j*i] = false;
            }
        }
    }
    Prime.push_back(2);
    for(int i = 3; i <= MAX; i+= 2) {
        if(isPrime[i]) Prime.push_back(i);
    }
}
ll calcDivFact(ll n){
    ll ans=1;
    for(int i=0;Prime[i]<=n;i++){
        ll j=Prime[i];
        ll count=0;
        while ((n/j)!=0){
            count=(count+(n/j))%mod;
            j=j*Prime[i];
        }
        ans=((ans*(count+1))%mod)%mod;
    }
    return ans;
}
int main(int argc, char const *argv[]){
    GeneratePrime();
    ll t;
    std::cin>>t;
    while(t--){
        ll x;
        std::cin>>x;
        std::cout<<calcDivFact(x)<<"\n";
    }  
return 0;
}