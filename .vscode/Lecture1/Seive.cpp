#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
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


int main(int argc, char const *argv[]){
    GeneratePrime();
    for(int i=0;i<=100;i++){
        std::cout<<Prime[i]<<" ";
    }
return 0;
}