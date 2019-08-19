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
int main(){
    int len,pi[1000005];
    char in[1000005];
    while(~scanf("%s",in) && in[0]!='.'){
        fail(in,pi);
        len=strlen(in);
        if(len%(len-pi[len-1]-1)==0)printf("%d\n",len/(len-pi[len-1]-1));
        else printf("%d\n",1);
    }
    return 0;
}
