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
int fail(char in[],int pi[]){
    int len=strlen(in);
    pi[0]=-1;
    for(int i=1;i<len;++i){
        if(in[i]==in[pi[i-1]+1])pi[i]=pi[i-1]+1;
        else if(in[i]==in[0])pi[i]=0;
        else pi[i]=-1;
    }
    return 1;
}
int KMP(char guest[],char master[]){
    int len1=strlen(guest),len2=strlen(master),pi[max(len1,len2)+5];
    int match=0,cur_pos=-1;
    fail(master,pi);
    for(int i=0;i<len2;++i){
        while(cur_pos>=0 && master[i]!=guest[cur_pos+1])
            cur_pos=pi[cur_pos];
        if(master[i]==guest[cur_pos+1])cur_pos++;
        if(cur_pos+1==len1){
            cur_pos=pi[cur_pos];
            match++;
        }
    }
    return match;
}
int main(){
    int cases,i,j,k,pi;
    char w[10005],t[1000005];
    scanf("%d",&cases);
    while(cases--){
        scanf("%s%s",w,t);
        printf("%d\n",KMP(w,t));
	}
    return 0;
}
