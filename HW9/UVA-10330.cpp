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
    int n,m;
    int a,b;
    int s[105],t[105];
    int node[105];
    int pre_g[105][105];
    while(scanf("%d",&n)!=EOF){
        //read input
        for(int i=0;i<n;++i){
            scanf("%d",&node[i]);
        }
        scanf("%d",&m);
        memset(pre_g,0,sizeof(pre_g));
        for(int i=0;i<m;++i){
            int t1,t2,t3;
            scanf("%d %d %d",&t1,&t2,&t3);
            pre_g[t1][t2]+=t3;
        }
        scanf("%d %d",&a,&b);
        for(int i=0;i<a;++i){
            scanf("%d",&s[i]);
        }
        for(int i=0;i<b;++i){
            scanf("%d",&t[i]);
        }
        //parse
        vector<int>g[410];
        for(int i=0;i<(4*n);++i){
            g[i].clear();
            g[i].resize(4*n+5);
        }
        for(int i=0;i<a;++i){
            g[0][s[i]*2-1]=0x3f3f3f3f;
        }
        for(int i=0;i<b;++i){
            g[t[i]*2][2*n+1]=0x3f3f3f3f;
        }
        for(int i=0;i<n;++i){
            g[i*2+1][i*2+2]+=node[i];
        }
        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j){
                g[i*2][j*2-1]+=pre_g[i][j];
            }
        }
        //for(int i=0;i<4*n;++i){for(int j=0;j<4*n;++j){printf("%3d",g[i][j]);}puts("");}
        printf("%d\n",max_flow(2*n,g,0,2*n+1));
    }
    return 0;
}
