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
int ans;
int prim(int n,vector<int>g[]){
    int visit[n+5],parent[n+5],dis[n+5];
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n+4;++i)
        dis[i]=1<<30;
    dis[0]=0;
    parent[0]=0;
    for(int i=0;i<n;++i){
        int minn=-1,mind=1<<30;
        for (int j=0;j<n;++j){
            if(!visit[j]&&dis[j]<mind){
                minn=j;
                mind=dis[j];
            }
        }
        if(minn==-1)break;
        if(mind>ans)ans=mind;
        visit[minn]=true;
        for(int j=0;j<n;j++){
            if(!visit[j] && g[minn][j]<dis[j]){
                dis[j]=g[minn][j];
                parent[j]=minn;
            }
        }
    }
    printf("%d\n%d\n",ans,n-1);
    for(int i=0;i<n;++i){
        if(parent[i]==i)continue;
        printf("%d %d\n",parent[i]+1,i+1);
    }
    return 1;
}
int main(){
    int n,m,t1,t2,t3;
    ans=0;
    vector<int>g[1002];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        g[i].clear();
        for(int j=0;j<n;++j){
            g[i].push_back(0x3f3f3f3f);
        }
    }
    for(int i=0;i<m;++i){
        scanf("%d %d %d",&t1,&t2,&t3);
        g[t1-1][t2-1]=t3;
        g[t2-1][t1-1]=t3;
    }
    prim(n,g);
    return 0;
}
