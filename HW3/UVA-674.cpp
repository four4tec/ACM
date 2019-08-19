#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

int main(){
    int n,i,j;
	int ch[5]={50,25,10,5,1},all[10000]={1};
	for(j=0;j<5;j++){
		for(i=ch[j];i<10000;i++){
			if(all[i-ch[j]]){all[i]+=all[i-ch[j]];}
		}
	}
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",all[n]);
	}
    return 0;
}
