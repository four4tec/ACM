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
typedef struct ns{
    double x,y;
    struct ns operator-(struct ns in){
        struct ns out;
        out.x=this->x-in.x;
        out.y=this->y-in.y;
        return out;
    }
    struct ns operator=(struct ns in){
        this->x=in.x;
        this->y=in.y;
        return in;
    }
}point;
double det(point in1,point in2){
    return in1.x*in2.y-in2.x*in1.y;
}
int cross(point s1,point e1,point s2,point e2){
    int re=0;
    if(((det(s1-s2,e2-s2)*det(e1-s2,e2-s2))<0) &&
       ((det(s2-s1,e1-s1)*det(e2-s1,e1-s1))<0)){
        re=1;
    }
    if(s2.x==e2.x){
        if(s1.x==s2.x&&
           ((s1.y<=s2.y&&s1.y>=e2.y)||(s1.y>=s2.y&&s1.y<=e2.y))){
           re=1;
        }
        if(s1.x==e1.x&&
           !((s2.y>=s1.y&&e2.y>=s1.y&&s2.y>=e1.y&&e2.y>=e1.y)||(s2.y<=s1.y&&e2.y<=s1.y&&s2.y<=e1.y&&e2.y<=e1.y))){
            re=1;
        }
    }
    else if(s2.y==e2.y){
        if(s1.y==s2.y&&((s1.x<=s2.x&&s1.x>=e2.x)||(s1.x>=s2.x&&s1.x<=e2.x))){re=1;}
        if(s1.y==e1.y&&!((s2.x>=s1.x&&e2.x>=s1.x&&s2.x>=e1.x&&e2.x>=e1.x)||(s2.x<=s1.x&&e2.x<=s1.x&&s2.x<=e1.x&&e2.x<=e1.x))){re=1;}
    }
    return re;
}
//
int main(){
    int cases,i,j;
    scanf("%d",&cases);
    while(cases--){
        point p[6];
        for(i=0;i<4;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
             if(p[2].x<p[3].x && p[2].y<p[3].y){p[5]=p[2];          p[2].x=p[5].x;p[2].y=p[3].y;p[4].x=p[3].x;p[4].y=p[5].y;}
        else if(p[2].x>p[3].x && p[2].y<p[3].y){p[4]=p[2];p[2]=p[3];p[3].x=p[4].x;p[3].y=p[2].y;p[5].x=p[2].x;p[5].y=p[4].y;}
        else if(p[2].x<p[3].x && p[2].y>p[3].y){p[4]=p[3];          p[3].x=p[4].x;p[3].y=p[2].y;p[5].x=p[2].x;p[5].y=p[4].y;}
        else if(p[2].x>p[3].x && p[2].y>p[3].y){p[5]=p[3];p[3]=p[2];p[2].x=p[5].x;p[2].y=p[3].y;p[4].x=p[3].x;p[4].y=p[5].y;}
        int ans=0;
        if(cross(p[0],p[1],p[2],p[3])||
           cross(p[0],p[1],p[3],p[4])||
           cross(p[0],p[1],p[4],p[5])||
           cross(p[0],p[1],p[5],p[2])){
            ans=1;
        }
        if(p[0].x<p[3].x&&
           p[0].x>p[2].x&&
           p[0].y<p[2].y&&
           p[0].y>p[4].y){
           ans=1;
        }
        printf("%c\n",(ans)?'T':'F');
    }
    return 0;
}
