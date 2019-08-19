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
int fail(char in[],int len,int pi[]){
    pi[0]=-1;
    for(int i=1;i<len;++i){
        if(in[i]==in[pi[i-1]+1])pi[i]=pi[i-1]+1;
        else if(in[i]==in[0])pi[i]=0;
        else pi[i]=-1;
    }
    return 1;
}
int main(){
    int k,len;
    char in[1000005];
    int pi[1000005];
    while(~scanf("%s",in) && in[0]!='.'){
        len=strlen(in);
        fail(in,len,pi);
        k=len-1-pi[len-1];
        if(len%k==0)printf("%d\n",len/k);
        else puts("1");
    }
    return 0;
}
