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
int prim(int n,vector<float>g[]){
    int visit[n+5],parent[n+5];
    float dis[n+5];
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n+4;++i)
        dis[i]=999999999;
    dis[0]=0;
    parent[0]=0;
    for(int i=0;i<n;++i){
        int minn=-1;
        float mind=999999999;
        for (int j=0;j<n;++j){
            if(!visit[j]&&dis[j]<mind){
                minn=j;
                mind=dis[j];
            }
        }
        if(minn==-1)break;
        visit[minn]=true;
        for(int j=0;j<n;j++){
            if(!visit[j] && g[minn][j]<dis[j]){
                dis[j]=g[minn][j];
                parent[j]=minn;
            }
        }
    }
    float ans=0;
    for(int i=0;i<n;++i){
        if(parent[i]==i || g[parent[i]][i]==0)continue;
        //printf("%f\n",g[parent[i]][i]);
        ans+=g[parent[i]][i];
    }
    printf("%.2f\n",ans);
    return 1;
}
int main(){
    int cases;
        scanf("%d",&cases);
        while(cases--){
        int n;
        float x[105],y[105];
        vector<float>g[105];
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%f %f",&x[i],&y[i]);
        }
        for(int i=0;i<n;++i){
            g[i].clear();
            for(int j=0;j<n;++j){
                float tmp=  (x[i]-x[j])*(x[i]-x[j])+
                            (y[i]-y[j])*(y[i]-y[j]);
                g[i].push_back(sqrt(tmp));
            }
        }
        prim(n,g);
        if(cases)puts("");
    }
    return 0;
}
