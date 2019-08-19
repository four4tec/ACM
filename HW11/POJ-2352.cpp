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
    }
}bin_index_tree;
int main(){
    int x[15005],y[15005],k[32005]={0};
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&x[i],&y[i]);
        ++x[i];
        ++y[i];
    }
    bin_index_tree tib;
    tib.s.clear();
    tib.s.resize(32005);
    tib.maxsize=32005;
    //
    for(int i=0;i<n;++i){
        int tmp=tib.sum(x[i]);
        ++k[tmp];
        tib.update(x[i],1);
    }
    //
    for(int i=0;i<n;++i){
        printf("%d\n",k[i]);
    }
    return 0;
}
