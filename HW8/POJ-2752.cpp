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
    int cur_pos=-1;
	pi[0]=-1;
	for(int i=1;i<=len;i++){
		while(cur_pos>-1 && in[cur_pos+1]!=in[i])
            cur_pos=pi[cur_pos];
		if(in[cur_pos+1]==in[i])cur_pos++;
		pi[i]=cur_pos;
	}
	return 1;
}
int main(){
    int len,now,t,pi[400010],ans[400010];
    char in[400010];
    while(~scanf("%s",in)){
        len=strlen(in);
        memset(ans,0,sizeof(ans));
        fail(in,len,pi);
        now=len-1;
        t=0;
        while(now!=-1){
            ans[t++]=now+1;
            now=pi[now];
        }
        for(int i=t-1,f=0;i>=0;--i){
            printf("%d",ans[i]);
            if(i)putchar(' ');
        }
        puts("");
    }
    return 0;
}
