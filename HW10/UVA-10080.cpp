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
bool bi_dfs(int now,vector<int>g[],int llink[],int rlink[],bool used[]){
    for(int i=0;i<g[now].size();++i){
        int nxt=g[now][i];
        if(used[nxt])continue;
        used[nxt]=true;
        if(rlink[nxt]==-1 || bi_dfs(rlink[nxt],g,llink,rlink,used)){
            llink[now]=nxt;
            rlink[nxt]=now;
            return true;
        }
    }
    return false;
}
int bi_match(int n,int m,vector<int>g[]){
    int ans=0;
    int llink[n+5],rlink[m+5];
    bool used[m+5];
    fill(llink,llink+n,-1);
    fill(rlink,rlink+m,-1);
    for(int i=0;i<n;++i){
        fill(used,used+m,false);
        if(bi_dfs(i,g,llink,rlink,used))
            ans++;
    }
    return ans;
}
int main(){
    int n,m,s,v;
    while(scanf("%d %d %d %d",&n,&m,&s,&v)==4){
        double x1[105],y1[105];
        double x2[105],y2[105];
        for(int i=0;i<n;++i){
            scanf("%lf %lf",&x1[i],&y1[i]);
        }
        for(int i=0;i<m;++i){
            scanf("%lf %lf",&x2[i],&y2[i]);
        }
        vector<int>g[105];
        for(int i=0;i<n;++i){
            g[i].clear();
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(sqrt(pow(x1[i]-x2[j],2)+pow(y1[i]-y2[j],2))/v<=s){
                    g[i].push_back(j);
                }
            }
        }
        printf("%d\n",n-bi_match(n,m,g));
    }
    return 0;
}
