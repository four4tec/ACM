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
int i_to_bign(long long int in,int out[]){
    int c=0;
    if(in==0){c=1;}
    while(in!=0){
        out[c++]=in%10;
        in/=10;
    }
    return c;
}
int bign_multi(int in1[],int l1,int in2[],int l2,int out[]){
    for(int i=0;i<l1;++i){
        for(int j=0;j<l2;++j){
            out[i+j]+=in1[i]*in2[j];
        }
    }
    for(int i=0;i<l1+l2+3;++i){
        if(out[i]>9){
            out[i+1]+=out[i]/10;
            out[i]%=10;
        }
    }
    int c=0;
    for(int i=l1+l2+3,f=1;i>=0 && f;--i){
        if(out[i]!=0){f=0;c=i+1;}
    }
    if(c==0){c=1;}
    return c;
}
int main(){
    long long int in1,in2;
    int n1[20],n2[20],l1,l2,ans[40],la;
    while(scanf("%llu %llu",&in1,&in2)==2){
        memset(n1,0,sizeof(n1));
        memset(n2,0,sizeof(n2));
        memset(ans,0,sizeof(ans));
        l1=i_to_bign(in1,n1);
        l2=i_to_bign(in2,n2);
        la=bign_multi(n1,l1,n2,l2,ans);
        //for(int i=lo-1;i>=0;--i){printf("%d",out[i]);}printf("\n");
        for(int i=0;i<max(l1,max(l2,la))-l1;++i){putchar(' ');}
        for(int i=l1-1;i>=0;--i){printf("%d",n1[i]);}puts("");
        for(int i=0;i<max(l1,max(l2,la))-l2;++i){putchar(' ');}
        for(int i=l2-1;i>=0;--i){printf("%d",n2[i]);}puts("");
        for(int i=0;i<max(l1,max(l2,la))-max(l1,l2);++i){putchar(' ');}
        for(int i=0;i<max(l1,l2);++i){putchar('-');}puts("");
        //
        int suc=0,out[l2+3][20],lo[l2+3],bs[l2+3],temp[20];
        memset(out,0,sizeof(out));
        memset(temp,0,sizeof(temp));
        for(int i=0;i<l2;++i){
            if(n2[i]!=0){
                temp[i]=n2[i];
                lo[suc]=bign_multi(n1,l1,temp,i+1,&out[suc][0]);
                bs[suc]=i;
                temp[i]=0;
                if(lo[suc]!=1 || out[suc][0]!=0)suc++;
            }
        }
        if(suc>1){
            for(int i=0;i<suc;++i){
                for(int j=0;j<la-lo[i];++j){putchar(' ');}
                for(int j=lo[i]-1;j>=bs[i];--j){printf("%d",out[i][j]);}puts("");
            }
            for(int i=0;i<la;++i){putchar('-');}puts("");
        }
        //
        for(int i=max(l1,max(l2,la))-la;i>=la;--i){putchar(' ');}
        for(int i=la-1;i>=0;--i){printf("%d",ans[i]);}puts("\n");
    }
    return 0;
}
