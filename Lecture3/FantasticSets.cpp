#include<bits/stdc++.h>
#define ll long long int
const ll max=1000005;
#define mod 1000000007
std::unordered_map<ll,bool>mp;
int main(int argc, char const *argv[])
{
    int t;
    std::cin>>t;
    while (t--){
        ll n;
        std::cin>>n;
        std::vector<int>freq(max,0);
        std::vector<int>arr(n);
        for(int i=0;i<n;i++){
            std::cin>>arr[i];
            freq[arr[i]]=1;
            mp[arr[i]]=true;
        }
        for(int i=1;i<=1000000;i++){
            if(mp.count(i)){
                for(int j=2*i;j<=1000000;j+=i){
                    freq[j]=(freq[j]%mod+freq[i]%mod)%mod;
                }
            }
        }
        ll result=0;
        for(int i=1;i<=1000000;i++){
            if(mp.count(i)){
                result=(result%mod+freq[i]%mod)%mod;
            }
        }
        if(mp.count(0)){
            result*=2;
            result++;
        }
        std::cout<<result;
    }
return 0;
}