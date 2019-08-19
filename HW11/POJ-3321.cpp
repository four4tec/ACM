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
#define max_n 100005
using namespace std;
typedef struct b_i_t{
    //
    vector<int>s;
    int maxsize;
    //
    int lowbit(int in){
        return in&(-in);
    }
    long long int sum(int index){
        long long int ans=0;
        while(index>0){
            ans+=s[index];
            index-=lowbit(index);
        }
        return ans;
    }
    int update(int index,int delta){
        for(int i=index;(i!=0 && i<=maxsize);i+=lowbit(i)){
            s[i]+=delta;
        }
        return 1;
    }
}bin_index_tree;
//
vector<vector<int> >g;
int l[max_n],r[max_n];
bool used[max_n];
int dfn=1;
int dfs(int u,int p){
    l[u]=dfn;
    ++dfn;
    int len=g[u].size();
    for(int i=0;i<len;++i){
        int v=g[u][i];
        if(v==p)continue;
        else{
            dfs(v,u);
        }
    }
    r[u]=dfn;
    return 1;
}
//
int main(){
    int n;
    g.resize(max_n);
    scanf("%d",&n);
    for(int i=0;i<(n-1);++i){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    //
    dfs(0,-1);
    bin_index_tree tib;
    tib.s.clear();
    tib.s.resize(max_n);
    tib.maxsize=max_n;
    for(int i=0;i<n;++i){
        tib.update(l[i],1);
    }
    memset(used,0,sizeof(used));
    int m;
    char op[10];
    int u;
    scanf("%d",&m);
    while(m--){
        scanf("%s %d",op,&u);
        --u;
        switch(op[0]){
            case 'C':
                if(used[u])tib.update(l[u],1);
                else tib.update(l[u],-1);
                used[u]=(!used[u]);
                break;
            case 'Q':
                printf("%d\n",(tib.sum(r[u]-1)-tib.sum(l[u]-1)));
                break;
        }
    }
    return 0;
}
