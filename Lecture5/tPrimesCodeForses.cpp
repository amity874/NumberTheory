#include<bits/stdc++.h>
#define ll long long int
#define max 100005
std::bitset<max>Prime;
std::bitset<max>IsPrime;
void getPrime(){
    Prime.set();
    Prime[0]=Prime[1]=false;
    for(int i=2;i*i<=max;i++){
        if(Prime[i]){
            for(int j=i;j*i<=max;j++){
                Prime[j*i]=false;
            }
        }
    }
    IsPrime[2]=true;
    for(int i=3;i<=max;i++){
        if(Prime[i]){
            IsPrime[i]=true;
        }
    }
}
float search(int n,int precision){
    int lo=0;
    int hi=n;
  float ans=0.0;
    while (lo<=hi){
        /* code */
        int mid=lo+(hi-lo)/2;
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid<n){
            lo=mid+1;
        }
        else{
            hi=mid-1;
            ans=hi;
        }
    }
   
    float incr=0.1;
    for(int i=0;i<=precision;i++){
        while((ans*ans)<=n){
            ans+=incr;
        }
        ans=ans-incr;
        incr=incr/10;
    }
    return ans;
}
int main(int argc, char const *argv[]){
    getPrime();
    ll t;
    std::cin>>t;
   while (t--){
       int n;
       std::cin>>n;
      float ans=search(n,0);
       if(std::sqrt(n)==ans&&IsPrime[ans]==true){
           std::cout<<"Yes"<<"\n";
       }
       else{
           std::cout<<"No"<<"\n";
       }
   }
return 0;
}