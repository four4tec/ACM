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
int h[16000010],c[260];
char in[16000010];
int main(){
    int n,nc,t,len,ans;
    while(~scanf("%d%d",&n,&nc)){
        scanf("%s",in);
        len=strlen(in);
        memset(c,0,sizeof(c));
        memset(h,0,sizeof(h));
        t=0;
        for(int i=0;i<len;++i){
            if(!c[in[i]]){c[in[i]]=t;t++;}
            if(t==nc)break;
        }
        ans=0;
        for(int i=0;i<len-n+1;++i){
            t=0;
            for(int j=0;j<n;++j){
                t*=nc;
                t+=c[in[i+j]];
            }
            if(!h[t]){h[t]=1;ans++;}
        }
        printf("%d\n",ans);
    }
    return 0;
}
