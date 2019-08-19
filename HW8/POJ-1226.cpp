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
    int len=strlen(in),cur_pos=-1;
	pi[0]=-1;
	for(int i=1;i<=len;i++){
		while(cur_pos>-1 && in[cur_pos+1]!=in[i])
            cur_pos=pi[cur_pos];
		if(in[cur_pos+1]==in[i])cur_pos++;
		pi[i]=cur_pos;
	}
	return 1;
}
int KMP(char guest[],char master[]){
    int len1=strlen(guest),len2=strlen(master),pi[max(len1,len2)+5];
    int cur_pos=-1;
    fail(guest,pi);
    for(int i=0;i<len2;++i){
        while(cur_pos>=0 && master[i]!=guest[cur_pos+1])
            cur_pos=pi[cur_pos];
        if(master[i]==guest[cur_pos+1])cur_pos++;
        if(cur_pos+1==len1){
            cur_pos=pi[cur_pos];
            return 1;
        }
    }
    return 0;
}
int main(){
    int cases,n,minl,flag=1,bf=0;
    int len[105];
    char in[105][105],t0[105],t1[105];
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);
        if(n==0){puts("0");continue;}
        minl=0;
        for(int i=0;i<n;++i){
            scanf("%s",in[i]);
            len[i]=strlen(in[i]);
            minl= len[minl]>len[i] ? i : minl;
        }
        bf=0;
        for(int i=len[minl];i>=1;--i){
            flag=1;
            for(int j=0;j < len[minl]-i+1 ;++j){
                strncpy(t0,&in[minl][j],i);
                t0[i]='\0';
                for(int k=0;k<i;++k)
                    t1[i-k-1]=t0[k];
                t1[i]='\0';
                flag=1;
                for(int k=0;k<n;++k){//printf("%s %s %s\n",t0,t1,in[k]);
                    if(k==minl)continue;
                    if(KMP(t0,in[k]) || KMP(t1,in[k]));
                    else{flag=0;break;}
                }
                if(flag){
                    printf("%d\n",i);
                    bf=1;
                    break;
                }
            }
            if(bf)break;
        }
        if(!bf)puts("0");
    }
    return 0;
}
