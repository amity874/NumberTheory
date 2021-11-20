// https://codeforces.com/contest/1350/problem/C
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define MAX 200005
std::vector<ll>Prime;
void genPrime(){
    std::bitset<MAX> isPrime;
    isPrime.set();
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=MAX;i++){
        if(isPrime[i]){
            for(int j=i;j*i<=MAX;j++){
                isPrime[j*i]=false;
            }
        }
    }
    Prime.push_back(2);
    for(int i=3;i<=MAX;i++){
        if(isPrime[i]){
            Prime.push_back(i);
        }
    }
}
ll pow__(ll a,ll b){
    ll res=1;
    a%=mod;
    while(b>0){
        if(b%2!=0){
            res=(res%mod*a%mod)%mod;
        }
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    genPrime();
    int n;
    std::cin>>n;
    std::vector<ll>arr(n+1,0);
    std::map<ll,std::vector<ll>>mp;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
		ll x = arr[i];
		for(ll j=2;j*j<=x;j++){
		if(x % j == 0)
		{
			int cnt = 0;
			while(x % j == 0){
			x /= j , cnt++;
            }
			mp[j].push_back(cnt);
		}
		if(x > 1)
		mp[x].push_back(1);
        }
    }
    ll res=1;
    for(ll p:Prime){
   if(mp.find(p) == mp.end() || (mp[p].size() + 1 < n))
		continue;
		sort(mp[p].begin() , mp[p].end());
		
		if(mp[p].size() + 1 == n)
		res *= pow__(p , mp[p][0]);
		else
		res *= pow__(p , mp[p][1]);
    }
    std::cout<<res;
return 0;
}