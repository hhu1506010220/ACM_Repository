#include<bits/stdc++.h>
using namespace std;

char mp[51][51];
int vis[2][51][51];
int sx,sy,tx,ty;
int dir[4][2]={-1,0,1,0,0,1,0,-1};  
int r ,c ;
struct node{    
    int x,y;    
};    
bool OK(int x,int y){ 
    if(x>=0&&x<r&&y>=0&&y<c&&mp[x][y]!='#')    
        return true;    
    else    
        return false;    
}    
int bfs(int sx,int sy,int type){    
    queue<node>q;    
    node start,mid,next;    
    start.x=sx;    
    start.y=sy;       
    q.push(start);    
    while(!q.empty()){
        mid = q.front();    
        q.pop();      
		if(mp[mid.x][mid.y]=='+'||mp[mid.x][mid.y]=='S'||mp[mid.x][mid.y]=='T'){
			for(int i = 0; i<4; i++){
	            next.x = mid.x+dir[i][0];    
	            next.y = mid.y+dir[i][1];   
	            if (OK(next.x,next.y)&&!vis[type][next.x][next.y]){ 
	                vis[type][next.x][next.y]=true;
	                q.push(next);    
	            }    
	        }  	
		}
		if(mp[mid.x][mid.y]=='-'){
			for(int i = 2; i<4; i++){
	            next.x = mid.x+dir[i][0];    
	            next.y = mid.y+dir[i][1];        
	            if (OK(next.x,next.y)&&!vis[type][next.x][next.y]){        
	                vis[type][next.x][next.y]=true;
	                q.push(next);    
	            }    
	        }
		}
		if(mp[mid.x][mid.y]=='|'){
			for(int i = 0; i<2; i++){
	            next.x = mid.x+dir[i][0];    
	            next.y = mid.y+dir[i][1];        
	            if (OK(next.x,next.y)&&!vis[type][next.x][next.y]){        
	                vis[type][next.x][next.y]=true;
	                q.push(next);    
	            }    
	        }		
		}
		if(mp[mid.x][mid.y]=='.'){
			next.x = mid.x+1*pow(1.0,type);    
            next.y = mid.y;        
            if (OK(next.x,next.y)&&!vis[type][next.x][next.y]){        
                vis[type][next.x][next.y]=true;
                q.push(next);    
            } 
		}
    }    
    return 0;  
}


int main(){
	scanf("%d%d",&r,&c);
	for(int i=0;i<r;i++){
		scanf("%s",mp[i]);
		for(int j=0;j<c;j++){
			if(mp[i][j]=='S'){
				sx=i;
				sy=j;
			}
			if(mp[i][j]=='T'){
				tx=i;
				ty=j;
			}
		}
	}
	int sum = 0;
	bfs(sx,sy,0);//起点可达 
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(vis[0][i][j]){
				bfs(i,j,1);
			}
			if(vis[0][i][j]&&!vis[1][tx][ty]){
				sum++;
			}
			memset(vis[1],0,sizeof(vis[1]));		
		}
	}

	if(!vis[0][tx][ty])
		puts("I'm stuck!");
	else
		printf("%d\n",sum);
	return 0;	
}
