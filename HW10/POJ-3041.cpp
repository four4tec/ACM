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
    int llink[1005],rlink[1005];
    bool used[1005];
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
    int n,m;
    vector<int>g[1005];
    scanf("%d %d",&n,&m);
    for(int i=0;i<1004;++i){
        g[i].clear();
    }
    for(int i=0;i<m;++i){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        --t1;
        --t2;
        g[t1].push_back(n+t2);
        g[n+t2].push_back(t1);
    }
    printf("%d\n",bi_match(2*n,2*n,g)/2);
    return 0;
}
