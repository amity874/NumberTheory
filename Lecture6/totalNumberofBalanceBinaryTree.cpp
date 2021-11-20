#include<bits/stdc++.h>
#define mod 1000000007
int main(int argc, char const *argv[])
{
    int h;
    std::cin>>h;
    int ans=0;
    if(h==1){
        ans=1;
    }
    if(h==2){
        ans=3;
    }
    else{
        ans=(((h-1)*(h-1))%mod+(2*((h-1)*(h-2)))%mod)%mod;
    }
    std::cout<<ans;
return 0;
}