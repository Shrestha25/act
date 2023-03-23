#include<bits/stdc++.h>
using namespace std;
#define fainou ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define mod 1000000007

ll gcd(ll a,ll b) { if(b==0) return a; return gcd(b,a%b); }
ll lcm(ll a,ll b) { return (a*b)/gcd(a,b); }

bool sortbypref(vector<ll> a, vector<ll> b){
    
}

ll powe(ll x,ll n){
    ll result=1;
    while(n>0){
        if(n%2==1) result=result*x;
        x=x*x;
        n=n/2;
    }
    return result;
}
ll powem(ll x,ll n,ll M){
    int result=1;
    while(n>0){
        if(n%2==1) result=(result*x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}
const ll N=1e5+5;
ll isprime[N];
void sieve(){
    memset(isprime,0,sizeof(isprime));
    isprime[1]=1;
    for(ll i=2;i*i<N;i++){
        if(isprime[i]==0){
            for(ll j=i*i;j<N;j+=i) isprime[j]=1;
        }
    }
}

int main(){
	fainou;
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif
    //sieve();
    ll test;
    cin>>test;
    for(ll t=1;t<=test;t++){
        
    }
	return 0;
}