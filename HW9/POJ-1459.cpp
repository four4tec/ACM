#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
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
    int np,nc,u,v,z,m,n,s,t;
    vector<int>cap[1005];
    while(~scanf("%d%d%d%d",&n,&np,&nc,&m)){
        for(int i=0;i<n+5;++i){
            cap[i].clear();
            cap[i].resize(n+5);
        }
        s=n+1;
        t=n+2;
        for(int i=0;i<m;++i){
            scanf(" (%d,%d)%d",&u,&v,&z);
            cap[u][v]+=z;
        }
        for(int i=0;i<np;++i){
            scanf(" (%d)%d",&u,&z);
            cap[s][u]+=z;
        }
        for(int i=0;i<nc;++i){
            scanf(" (%d)%d",&u,&z);
            cap[u][t]+=z;
        }
        printf("%d\n",max_flow(n,cap,s,t));
    }
    return 0;
}
