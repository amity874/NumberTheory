#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const long long mod = 1000000007;
const int maxl = 1e7 + 1;
int elimination1[maxl];
int elimination2[maxl];
int seive[maxl];
int main(){
    for(int i=1;i<maxl;i++){
        seive[i]=i;
        elimination1[i]=maxl;
    }
    for(int i=2;i<maxl;i++){
        if(seive[i]==i){
            for(int j=2*i;j<maxl;j+=i){
                seive[j]=i;
            }
        }
    }
    int n;
    ll res=1;
    std::cin>>n;
   for(int i=0;i<n;i++){
        std::map<int,int>mp;
        int ai;
        std::cin>>ai;
        for(int i=1;i<=ai;i++){
            int d;
            std::cin>>d;
            while(d>1){
                mp[seive[d]]++;
                d/=seive[d];
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            elimination2[(*it).first]++;
            elimination1[(*it).first]=std::min(elimination1[(*it).first],(*it).second);
        }
    }
    for(ll i=2;i<maxl;i++){
        if(elimination2[i]==n){
            while(elimination1[i]--){
                res*=i;
                res%=mod;
            }
        }
    }
    std::cout<<res;
	return 0;
}
