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
    int chk[len+10],tmp[len+10];
    tmp[0]=in[0];
    chk[0]=1;
    for(int i=1;i<len;++i){
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
int tran_LCS(int in1[],int len1,int in2[],int len2){
    int num[max(len1,len2)+10],all[max(len1,len2)],out[max(len1,len2)],n=0;
    for(int i=0;i<len1;++i)num[in1[i]]=i+1;
    for(int i=0;i<len2;++i)
        if(num[in2[i]])all[n++]=num[in2[i]]-1;
    return exLIS(all,n,out);
}
int main(){
	int in1[63000]={0},in2[63000]={0},n=0,c,p,q,i,j;
	scanf("%d",&c);
   for(j=0;j<c;j++){
        scanf("%d%d%d",&n,&p,&q);
        for(i=0;i<p+1;i++){scanf("%d",&in1[i]);}
        for(i=0;i<q+1;i++){scanf("%d",&in2[i]);}
        printf("Case %d: %d\n",j+1,tran_LCS(in1,p+1,in2,q+1));
	}
    return 0;
}
