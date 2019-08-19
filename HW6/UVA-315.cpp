#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include <set>
using namespace std;
int ARTIrec(int cur,int parent,int n,vector<int>g[],int ans[],int &atop,int &depth,int dfn[],int low[]){
    int child=0,nxt,f1=0,f2=0;
    ++depth;
    low[cur]=depth;
    dfn[cur]=low[cur];
    for(int i=0;i<g[cur].size();++i){
        nxt=g[cur][i];
        f2=0;
        if(!dfn[nxt]){
            ++child;
            ARTIrec(nxt,cur,n,g,ans,atop,depth,dfn,low);
            low[cur]=min(low[cur],low[nxt]);
            if(low[nxt]>=dfn[cur]){
                f1=1;f2=1;
            }
            /*if((child>1 || parent!=-1) && f2){
                ++cut[cur];
            }*/
        }
        else if(nxt!=parent){
            low[cur]=min(low[cur],dfn[nxt]);
        }
    }
    if((child>1 || parent!=-1) && f1){
        ans[atop++]=cur;
    }
    return 0;
}
int ARTI(int n,vector<int>g[],int ans[]){
    int depth=0,dfn[n+5],low[n+5],atop=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    for(int i=0;i<n;++i){
        if(!dfn[i]){
            //++graph_cnt;
            ARTIrec(i,-1,n,g,ans,atop,depth,dfn,low);
        }
    }
    return atop;
}
int main() {
    int x,y,n;
    int ans[1005];
    char c;
    vector<int>g[1005];
    while(scanf("%d",&n)==1&&n){
        for(int i=0;i<=n;++i)
            g[i].clear();
        while(scanf("%d",&x)==1&&x){
            while(scanf("%d%c",&y,&c)==2){
                g[x].push_back(y);
                g[y].push_back(x);
                if(c=='\n'){break;}
            }
        }
        printf("%d\n",ARTI(n,g,ans));
    }
    return 0;
}
