#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;
int main(){
    //ios::sync_with_stdio(false);
    string country;
    string tmp;
    int n;
    map<string,int>all;
    all.clear();
    scanf("%d",&n);
    while(n--){
        cin>>country;
        getline(cin,tmp);
        all[country]++;
    }
    for(map<string,int>::iterator i=all.begin();i!=all.end();++i){
        cout<< i->first <<" "<< i->second <<endl;
    }
    return 0;
}
