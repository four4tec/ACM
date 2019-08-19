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
//node define
typedef struct ns{
    int maxval;
    int minval;
    ns *l,*r;
    //
    int update(int new_val){
        maxval=new_val;
        minval=new_val;
        return 1;
    }
    int pull(){
        maxval=max(l->maxval,r->maxval);
        minval=min(l->minval,r->minval);
        return 1;
    }
}node;
node all[150000];
int cnt=0;
//build
node* build(int l,int r,int s[]){
    node *now=&all[cnt++];//new node();
    if(l==r){
        now->maxval=s[l];
        now->minval=s[l];
        return now;
    }
    //
    int mid=(l+r)/2;
    now->l=build(l,mid,s);
    now->r=build(mid+1,r,s);
    now->pull();
    return now;
}
//find - find max in [x,y]
int findmax(node* now,int l,int r,int x,int y){
    if(x>r || y<l){
        return -1*(0x3f3f3f3f);
    }
    if(x<=l && y>=r){
        return (now->maxval);
    }
    //
    int mid=(l+r)/2;
    return max(findmax(now->l,l,mid,x,y),findmax(now->r,mid+1,r,x,y));
}
int findmin(node* now,int l,int r,int x,int y){
    if(x>r || y<l){
        return 1*(0x3f3f3f3f);
    }
    if(x<=l && y>=r){
        return (now->minval);
    }
    //
    int mid=(l+r)/2;
    return min(findmin(now->l,l,mid,x,y),findmin(now->r,mid+1,r,x,y));
}
//---------------------------------------------------//
int main(){
    int n,m;
    int s[50005];
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&s[i]);
    }
    //
    node* root=build(1,n,s);
    int x,y;
    for(int i=0;i<m;++i){
        scanf("%d %d",&x,&y);
        printf("%d\n",findmax(root,1,n,x,y)-findmin(root,1,n,x,y));
    }
    return 0;
}
