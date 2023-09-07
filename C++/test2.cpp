#include<bits/stdc++.h>
using namespace std;

map<pair<string,char>,int> mp;
stack<string> ans;
bool poss(string s){
    int m_z=0,m_o=0;
    for(int i=0;i<6;i+=2){
        if(s[i]=='0') m_z++;
        else m_o++;
    }
    for(int i=1;i<6;i+=2){
        if(s[i]=='0'){
            if(s[i-1]=='1' && m_z!=0) return 0;
        }
        else{
            if(s[i-1]=='0' && m_o!=0) return 0;
        }
    }
    return 1;
}

bool dfs(string s,char l){
    if(s=="111111"){
        return true;
    };
    mp[{s,l}]++;
    for(int i=0;i<6;i++){
        if(s[i]==l){
            s[i]= l=='0'?'1':'0';
            if(poss(s)){
                if(l=='0'){
                    if(mp.find({s,'1'})==mp.end()){
                        if(dfs(s,'1')){
                            ans.push(s);
                            return true;
                        }
                    }
                }
                else{
                    if(mp.find({s,'0'})==mp.end()){
                        if(dfs(s,'0')){
                            ans.push(s);
                            return true;
                        }
                    }
                }
            }
            for(int j=i+1;j<6;j++){
                if(s[j]==l){
                    s[j]= l=='0'?'1':'0';
                    if(poss(s)){
                        if(l=='0'){
                            if(mp.find({s,'1'})==mp.end()){
                                if(dfs(s,'1')){
                                    ans.push(s);
                                    return true;
                                }
                            }
                        }
                        else{
                            if(mp.find({s,'0'})==mp.end()){
                                if(dfs(s,'0')){
                                    ans.push(s);
                                    return true;
                                }
                            }
                        }
                    }
                    s[j]=l;
                }
            }
            s[i]=l;
        }
    }
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif
    string s="000000";
    dfs(s,'0');
    ans.push(s);
    while(!ans.empty()){
        cout<<ans.top()<<"\n";
        ans.pop();
    }
    return 0;
}