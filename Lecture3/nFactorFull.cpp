#include<bits/stdc++.h>
#define ll long long int 
#define max 1000005
std::vector<std::vector<ll>>count(11,std::vector<ll>(1000005,0));
std::vector<ll>Prime(1000005,0);
void gen(){
    //calculating distinct divisior for i th element but dont consider the prime number
    for(int i=2;i<=1000000;i++){   
        if(not Prime[i]){
            for(int j=i;j<=1000000;j+=i){
            Prime[j]++;
        }
        }
    }
    for(int i=0;i<=10;i++){
        for(int j=1;j<=1000000;j++){
            count[i][j]=count[i][j-1]+(Prime[j]==i);
        }
    }
}
int main(int argc, char const *argv[])
{
    gen();
    ll t;
    std::cin>>t;
    while (t--){
        ll a,b,n;
        std::cin>>a>>b>>n;
        std::cout<<(count[n][b]-count[n][a-1])<<"\n";
    }
    
return 0;
}