#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=1001;
int N,L,H,Ans=0;
int map[MAX];

int main(int argc, char** argv) {
	
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	
	cin>>N;
	
	int start=987987,end=-1,maxH = -1,maxIdx=-1;
	
	
	for(int i=0;i<N;i++){
		cin >> L >> H;
		map[L] = H;
		
		if (maxH < map[L]){
			maxH = map[L];
			maxIdx = L;	
		}
		
		start = min(start,L);
		end = max(end,L);
	}
	
	int cur = 0;
	for(int i=start; i<maxIdx;i++)
	{
		if(map[i] > cur )
			cur = map[i];
		Ans += cur;
	}
	
	cur = 0;
	for(int i=end;i>=maxIdx;i--){
		if(map[i] > cur )
			cur = map[i];
		Ans += cur;
	}
	
	cout << Ans;
	
	
	
	
	return 0;
}
