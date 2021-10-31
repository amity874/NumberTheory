#include<bits/stdc++.h>
#define ll long long int
#define max 10000000
std::bitset<max> IsPrime;
std::vector<int>Prime;
void  GeneratePrime(){
    IsPrime.set();
    for(int i=2;i*i<=max;i++){
        if(IsPrime[i]){
            for(int j=i;j*i<=max;j++){
                IsPrime[j*i]=false;
            }
        }
    }
    for(int i=2;i<=max;i++){
        if(IsPrime[i]){
            Prime.push_back(i);
        }
    }
}
int main(int argc, char const *argv[]){
    GeneratePrime();
    for(int i=0;i<=100;i++){
        std::cout<<Prime[i]<<" ";
    }
return 0;
}