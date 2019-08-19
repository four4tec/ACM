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
    int llink[105],rlink[105];
    bool used[105];
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
    int n,m,k;
    vector<int> edge[105];
    while(~scanf("%d",&n) &&n){
        for(int i=0;i<n;++i)
            edge[i].clear();
        scanf("%d %d",&m,&k);
        int x,y,z;
        for(int j=0;j<k;++j){
            scanf("%d %d %d",&z,&x,&y);
            if(!x || !y){continue;}
            edge[x].push_back(y);
        }
        printf("%d\n",bi_match(n,m,edge));
    }
    return 0;
}
