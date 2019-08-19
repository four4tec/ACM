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
#define limit 100000001
int prime[8000000];
char all[limit];
int find(int left,int right,int key){
    int mid;
    while(left<right){
        mid=(left+right+1)/2;
        if(prime[mid]>key){right=mid-1;}
        else if(prime[mid]==key){return mid-1;}
        else{left=mid;}
    }
    return left;
}
int main(){
    int i,j,c=0;
    memset(all,0,sizeof(all));
    for(i=2;i<limit;++i){
        if(!all[i]){prime[c++]=i;}
        for(j=0;j<c && i*prime[j]<limit;++j){
            all[i*prime[j]]=1;
            if(i%prime[j]==0){break;}
        }
    }
    prime[c]=limit;
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n<5){printf("%d is not the sum of two primes!\n",n);}
        else if(n%2){
            if(prime[find(0,c,n-2)+1]==n-2){printf("%d is the sum of %d and %d.\n",n,2,n-2);}
            else{printf("%d is not the sum of two primes!\n",n);}
        }
        else{
            int f=1;
            for(i=find(0,c,n/2);i>=0;--i){
                if(prime[find(0,c,n-prime[i])+1]==(n-prime[i])){
                    f=0;
                    printf("%d is the sum of %d and %d.\n",n,prime[i],n-prime[i]);
                    break;
                }
            }
            if(f){printf("%d is not the sum of two primes!\n",n);}
        }
    }
    return 0;
}
