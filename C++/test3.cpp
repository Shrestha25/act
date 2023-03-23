#include<bits/stdc++.h>
using namespace std;
#define fainou ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define mod 1000000007

void dfs(ll i,ll p,vector<vector<ll>> &v,vector<ll> &lv,vector<vector<ll>> &tab,ll level){
    lv[i]=level;
    tab[i][0]=p;
    for(ll j=1;j<32;j++){
        if(tab[i][j-1]!=-1) tab[i][j]=tab[tab[i][j-1]][j-1];
        else break;
    }
    for(auto x:v[i]){
        if(lv[x]==-1){
            dfs(x,i,v,lv,tab,level+1);
        }
    }
}
ll lca(ll a,ll b,vector<ll> &lv,vector<vector<ll>> &tab){
    if(a>b) swap(a,b);
    ll d=lv[b]-lv[a];
    for(ll i=31;i>=0;i--){
        if(d&(1<<i)) b=tab[b][i];
    }
    if(a==b) return a;
    for(ll i=31;i>=0;i--){
        if(tab[a][i]!=-1 && tab[a][i]!=tab[b][i]){
            a=tab[a][i];
            b=tab[b][i];
        }
    }
    return tab[a][0];
}
int main(){
	fainou;
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> v(n);
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(auto x:v){
        for(auto y:x) cout<<y<<" ";
        cout<<"\n";
    }
    vector<ll> lv(n,-1);
    vector<vector<ll>> tab(n,vector<ll> (32,-1));
    dfs(0,-1,v,lv,tab,0);
    for(ll i=0;i<n;i++) cout<<i+1<<" "<<lv[i]<<"\n";
    for(auto x:tab){
        for(auto y:x) cout<<y<<" ";
        cout<<"\n";
    }
    ll q;
    cin>>q;
    while(q--){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        cout<<lca(x,y,lv,tab)+1<<"\n";
    }
	return 0;
}