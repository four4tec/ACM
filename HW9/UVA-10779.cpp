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
#include<set>
using namespace std;
int max_flow(int n,vector<int>cap[],int s,int t){
    int ans=0,flow[n+10][n+10],p[n+10],a[n+10];
    queue<int>q;
    memset(flow,0,sizeof(flow));
    while(1){
        memset(a,0,sizeof(a));
        int v,u;
        a[s]=1<<30;
        q.push(s);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(v=0;v<=n+2;v++)
            if(!a[v]&&cap[u][v]-flow[u][v]>0){
                p[v]=u;
                q.push(v);
                a[v]=min(a[u],cap[u][v]-flow[u][v]);
            }
        }
        if(a[t]==0){break;}
        for(u=t;u!=s;u=p[u]){
            flow[p[u]][u]+=a[t];
            flow[u][p[u]]-=a[t];
        }
        ans+=a[t];
    }
    return ans;
}
int main(){
    int cases,cases_cnt=0;
    int n,m;
    vector<int>g[40];
    scanf("%d",&cases);
    while(cases_cnt!=cases){
        ++cases_cnt;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n+m+3;++i){
            g[i].clear();
            g[i].resize(40);
        }
        for(int i=1;i<=n;++i){
            int t1,t2;
            scanf("%d",&t1);
            for(int j=1;j<=t1;++j){
                scanf("%d",&t2);
                ++g[i][n+t2];
            }
        }
        //parse
        for(int i=2;i<=n;++i){
            for(int j=n+1;j<n+m+1;++j){
                if(g[i][j]>=1){
                    --g[i][j];
                }
                else if(g[i][j]==0){
                    g[j][i]=1;
                }
            }
        }
        for(int i=n+1;i<n+m+1;++i){
            g[i][n+m+1]=1;
        }
        //for(int i=0;i<n+m+2;++i){for(int j=0;j<n+m+2;++j){printf("%3d",g[i][j]);}puts("");}
        printf("Case #%d: %d\n",cases_cnt,max_flow(n+m+2,g,1,n+m+1));
        //
    }
    return 0;
}
