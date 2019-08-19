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
    char temp[10000],sign[2],div[10000];
    long long int in2,ans,t;
    int in1[10000],a=0;
    while(~scanf("%s %s %lld",temp,sign,&in2)){
        for(int i=strlen(temp)-1;i>=0;--i){in1[strlen(temp)-i-1]=temp[i]-'0';}
        switch(sign[0]){
            case '/':
                t=0;
                memset(div,0,sizeof(div));
                for(int i=strlen(temp)-1;i>=0;--i){
                    t*=10;
                    t+=in1[i];
                    div[strlen(temp)-1-i]=t/in2+'0';
                    t=t-t/in2*in2;
                }
                a=0;
                for(int i=0,f=1;i<strlen(temp) && f;i++){
                    if(div[i]=='0'){a++;}
                    else{f=0;}
                }
                if(a==strlen(div)){printf("0\n");}
                else printf("%s\n",&div[a]);
            break;
            case '%':
                ans=0;
                for(int i=strlen(temp)-1;i>=0;--i){
                    ans*=10;
                    ans+=in1[i];
                    ans%=in2;
                }
                printf("%d\n",ans);
            break;
        }
    }
    return 0;
}
