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
    int s,t,n,c,cases=0;
    vector<int>g[105];
    while(scanf("%d",&n)!=EOF && n>0){
        ++cases;
        scanf("%d %d %d",&s,&t,&c);
        for(int i=0;i<n+4;++i){
            g[i].clear();
            g[i].resize(n+4);
        }
        for(int i=0;i<c;++i){
            int t1,t2,t3;
            scanf("%d %d %d",&t1,&t2,&t3);
            g[t1][t2]+=t3;
            g[t2][t1]+=t3;
        }
        printf("Network %d\n",cases);
        printf("The bandwidth is %d.\n\n",max_flow(n,g,s,t));
    }
    return 0;
}
