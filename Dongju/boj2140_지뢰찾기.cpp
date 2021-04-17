#include <iostream>
using namespace std;
int N;
char map[101][101];
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};


bool check(int x,int y)
{
	bool flag=true;
	for(int i=0;i<8;i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
			
		if( nx>=N || ny>=N || nx<0 || ny<0)
			continue;

		if(map[nx][ny]=='0')
		{
			flag=false;	
		}	
			

	}
	return flag;
	
}


void clear(int x,int y)
{
	
	for(int i=0;i<8;i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
			
		if( nx>=N || ny>=N || nx<0 || ny<0)
			continue;

		if(map[nx][ny]>'0' && map[nx][ny]<='9')
			map[nx][ny]--;

	}


}



int main(int argc, char** argv) {
	
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>map[i];
	}
	
	if(N<3){
		cout<<0;
		return 0;
	}

	
	int ans= (N-2)*(N-2);
	for(int i=1;i<N-1;i++)
	{
		
		for(int j=1;j<N-1;j++)
		{
			if ( check(i,j) )
			{
				clear(i,j);
				
			}else{
				
				ans--;
				
			}
	
		}
	}

	cout<<ans;

	
	return 0;
}
