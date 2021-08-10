#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
#include<string>
#include<iostream>
#include<queue>

//初始化结构体，root为节点
struct point{
	int x,y,root;
};
point ans[100000];
vector<int> wayx;
vector<int> wayy;
int arr1[] = {-1,1,0,0};
int arr2[] = {0,0,-1,1};

std:: vector<int> directionx (arr1,arr1+4);
std:: vector<int> directiony (arr2,arr2+4); 


void print(point p);
void bfs(vector<vector<int> >&maze,int a,int b);
int main()
{
//输入迷宫大小n*m
int n,m;
scanf("%d %d",&n,&m);
string t;
vector<vector<int> >maze(n,vector<int>(m));
//定义搜索方向向上后下，先左后右

getchar();//防止第一行被吞，某些编译器用不了fflush(stdin);

//用字符串读入

for(int i=0;i<n;i++){
getline(cin,t);
    for(int j=0;j<m;j++){//初始化迷宫
        maze[i][j]=t[j]-'0';
    }
}
vector<string>character;
character.push_back("UDLR");
//标记起点0，0
maze[0][0]=2;
wayx.push_back(0);
wayy.push_back(0);
bfs(maze,0,0);
//输出最小步数
printf("%d\n",wayx.size()-1);
for(int i=0;i<wayx.size();i++){
    for(int j=0;j<4;j++){
        //寻找下一步的方向
        if((wayx[i]+directionx[j])==wayx[i+1]&&(wayy[i]+directiony[j])==wayy[i+1])
        cout<< character[0][j];
    }
}

    return 0;
}

void bfs(vector<vector<int> >&maze,int a,int b ){ 
int cnt=0,k=0;
point p;
p.x=a;
p.y=b;
p.root=-1;
queue<point> q;
q.push(p);
ans[0]=p;
cnt++;
 while(!q.empty()){
     point m=q.front();//指向队列的第一个 
     q.pop();//将首元素取出队列 
     if(p.x==maze.size()-1&&p.y==maze[0].size()-1){
         //如果走到出口则打印路径
         print(p);return ;
         }
     for(int i=0;i<4;i++){
         int _x=m.x+directionx[i];
         int _y=m.y+directiony[i];
         //符合条件的进队列
        if(_x>=0&&_x<maze.size()&&_y>=0&&_y<maze[0].size()&&maze[_x][_y]!=1&&maze[_x][_y]!=2){
            //记录走过的路为2
            maze[_x][_y]=2;
            p.x=_x;
            p.y=_y;
            p.root=k;
            //将p压入队列 
            q.push(p);
            //先++再赋值 将p点给ans数组便于最后输出
            ans [ cnt++ ]=p;
        }

     }
     k++;
 }

}
void print(point p){//递归打印路径
	while(p.root!=-1){
        
		print(ans[p.root]);
        //把路径传入way
        wayx.push_back(p.x);
        wayy.push_back(p.y);

		return;
	} 

}

