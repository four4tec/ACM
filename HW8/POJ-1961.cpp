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
int len;
int fail(char in[],int pi[]){
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
    int cases=0,k,pi[1000005];
    char in[1000005];
    while(~scanf("%d",&len) && len!=0){
        scanf("%s",in);
        fail(in,pi);
        printf("Test case #%d\n",++cases);
        for(int i=2;i<=len;++i){
            k=i-1-pi[i-1];
            if(i%k==0 && i!=k)printf("%d %d\n",i,i/k);
        }
        printf("\n");
    }
    return 0;
}
