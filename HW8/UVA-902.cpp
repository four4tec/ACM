#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<map>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    string in,t;
    int n,len,ans;
    map<string,int>::iterator mi;
    while(cin>>n>>in){
        map<string,int>all;
        len=in.length();
        for(int i=0;i<len-n+1;++i){
            t.assign(in,i,n);
            all[t]++;
        }
        ans=0;
        for(mi=all.begin();mi!=all.end();mi++){
            if(mi->second >ans){
                ans=mi->second;
                t=mi->first;
            }
        }
        cout<<t<<"\n";
    }
    return 0;
}
