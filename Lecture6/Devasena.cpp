#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define N 100005
ll freq[N];
ll COUNT[N];
ll arr[N];
ll pow__(ll a,ll b,ll md){
    ll res=1;
    a%=md;
    while(b>0){
        if(b%2!=0){
            res=(res%md*a%md)%md;
        }
        a=(a%md*a%md)%md;
        b>>=1;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int t;
    std::cin>>t;
    while(t--){
        memset(freq,0,sizeof(freq));
        memset(COUNT,0,sizeof(COUNT));
        int  n;
        std::cin>>n;
        ll  max_ele=-1;
        for(int i=0;i<n;i++){
            std::cin>>arr[i];
            freq[arr[i]]++;
            max_ele=std::max(arr[i],max_ele);
        }
        ll ans=1;
       for(int i=max_ele;i>1;i--){
           ll f=freq[i];
           for(int j=i*2;j<=max_ele;j+=i){
              f+=freq[j];
           }
           ll cnt=pow__(2,f,(MOD-1))%MOD;
           cnt--;
           COUNT[i]=cnt;
           for(int j=i*2;j<=max_ele;j+=i){
               COUNT[i]-=COUNT[j];
               COUNT[i]=(COUNT[i]+(MOD-1))%(MOD-1);
           }
           if(cnt>0){
               ans=((ans%MOD)*pow__(i,COUNT[i],MOD))%MOD;
           }
       }
       std::cout<<ans<<"\n";
    }
return 0;
}
