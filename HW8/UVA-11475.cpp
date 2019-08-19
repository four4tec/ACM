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
    int len,pi[200010];
    char in1[100010],in2[100010],in3[200010];
    while(~scanf("%s",in1)){
        memset(in2,0,sizeof(in2));
        memset(in3,0,sizeof(in3));
        len=strlen(in1);
        for(int i=0;i<len;++i){
            in2[len-1-i]=in1[i];
        }
        strcpy(in3,in2);
        strcat(in3,in1);
        fail(in3,pi);
        printf("%s%s\n",in1,in2+pi[len*2-1]+1);
    }
    return 0;
}
