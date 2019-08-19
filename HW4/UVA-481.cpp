#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cmath>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int exLIS(int in[],int len,int out[]){
    int ans=1,t,top;
    int chk[len+10],pos[len+10],tmp[len+10];
    for(int i=0;i<len;++i){
        t=lower_bound(tmp,tmp+ans,in[i])-tmp;
        tmp[t]=in[i];
        chk[i]=t+1;
        ans=t+1>ans?t+1:ans;
    }
    top=ans;
    for(int i=len-1;i>=0;--i){
        if(chk[i]==top){
            out[--top]=in[i];
        }
    }
    return ans;
}
int main(){
	int all[100000],n=0,i,out[100000],ans;
	while(scanf("%d",&all[n])!=EOF){n++;}
	ans=exLIS(all,n,out);
	printf("%d\n-\n",ans);
	for(i=0;i<ans;++i){printf("%d\n",out[i]);}
    return 0;
}
