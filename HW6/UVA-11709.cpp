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
#define maxn 1005
using namespace std;
int ans;
int TARrec(int in,int n,vector<int>g[],int visit[],int low[],int &t,int stk[],int &top,int instk[],int con[]){
    t++;
    visit[in]=t;
    low[in]=t;
    stk[top++]=in;
    instk[in]=1;
    for(vector<int>::iterator i=g[in].begin();i!=g[in].end();i++){
        if(!visit[*i]){
            TARrec(*i,n,g,visit,low,t,stk,top,instk,con);
        }
        if(instk[*i]){
            low[in]=min(low[in],low[*i]);
        }
    }
    if(visit[in]==low[in]){
        int j;
        do{
            j=stk[--top];
            instk[j]=0;
            con[j]=in;
        }while(j!=in);
        ans++;
    }
    return 0;
}
int TARJAN(int n,vector<int> g[]){
    int visit[n+5],low[n+5],t=0;
    int stk[n+5],top=0;
    int instk[n+5];
    int con[n+5];
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n;++i){
        if(!visit[i]){
            TARrec(i,n,g,visit,low,t,stk,top,instk,con);
        }
    }
    return 1;
}
int main(){
    int n,m,x,y,i;
    char name[50],a[50],b[50];
    map<string,int>mapped;
    vector<int>g[maxn];
    while(scanf("%d %d",&n,&m)==2){
        if(!n&&!m)break;
        mapped.clear();
        getchar();
        for(i=0;i<n;i++){
            gets(name);
            mapped[name]=i;
            g[i].clear();
        }
        for(i=0;i<m;i++){
            gets(a);
            gets(b);
            x=mapped[a];
            y=mapped[b];
            g[x].push_back(y);
        }
        ans=0;
        TARJAN(n,g);
        printf("%d\n",ans);
    }
    return 0;
}
