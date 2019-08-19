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
int main(){
    char a[10000];
    int b,c,d[5000],e,l,i,m=0,ans,out[5000];
    scanf("%d\n",&b);
    for(l=0;l<b;l++){
        memset(d,0,sizeof(d));
        memset(a,'0',10000);
        memset(out,0,sizeof(out));
        for(i=0;1;i++){a[i]=getchar();if((a[i]=='\n'&&a[i-1]=='\n')||(a[i]==EOF)){c=i;break;}}
        d[0]=atoi(&a[0]);
        m=0;
        for(i=0;i<c;i++){if(a[i]=='\n'){m++;d[m]=atoi(&a[i+1]);}}
        e=m;
        ans=exLIS(d,e,out);
        printf("Max hits: %d\n",ans);
        for(i=0;i<ans;++i){printf("%d\n",out[i]);}
        if(l!=b-1){printf("\n");}
    }
    return 0;
}
