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
        dis[i]=0x3f3f3f3f;
    dis[0]=0;
    parent[0]=0;
    for(int i=0;i<n;++i){
        int minn=-1,mind=0x3f3f3f3f;
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
    return 1;
}
int main(){
    int n,m,t1,t2,t3;
    ans=0;
    vector<int>g[2002];
    for(int i=0;i<2002;++i){
        g[i].clear();
    }
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            g[i].push_back(0x3f3f3f3f);
        }
    }
    for(int i=0;i<m;++i){
        scanf("%d %d %d",&t1,&t2,&t3);
        g[t1-1][t2-1]=min(t3,g[t1-1][t2-1]);
        g[t2-1][t1-1]=min(t3,g[t2-1][t1-1]);
    }
    prim(n,g);
    printf("%d\n",ans);
    return 0;
}
