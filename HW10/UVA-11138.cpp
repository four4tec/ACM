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
    int cases;
    int now_cases=0;
    scanf("%d",&cases);
    while(cases--){
        int n,m;
        scanf("%d %d",&n,&m);
        vector<int>g[1005];
        for(int i=0;i<n;++i){
            g[i].clear();
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int t;
                scanf("%d",&t);
                if(t){
                    g[i].push_back(j);
                }
            }
        }
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",++now_cases,bi_match(n,m,g));
    }
    return 0;
}
