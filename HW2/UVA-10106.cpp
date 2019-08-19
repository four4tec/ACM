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
    char a[260],b[260];
    int x[260],y[260],ans[600],l;
    while(~scanf("%s%s",a,b)){
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<strlen(a);++i){x[strlen(a)-i-1]=a[i]-'0';}
        for(int i=0;i<strlen(b);++i){y[strlen(b)-i-1]=b[i]-'0';}
        l=bign_multi(x,strlen(a),y,strlen(b),ans);
        for(int i=l-1;i>=0;--i){printf("%d",ans[i]);}puts("");
    }
    return 0;
}
