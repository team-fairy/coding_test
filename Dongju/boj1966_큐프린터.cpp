#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int M,N,Idx;
int main(int argc, char** argv) {
	
	cin>>N;
	
	for(int i=0;i<N;i++){
		
		cin>>M>>Idx;
				
		priority_queue<int> pq;
		queue<pair<int,int> > q;

		for(int j=0;j<M;j++){
			int pri;
			cin>>pri;
			q.push({j,pri});
			pq.push(pri);
		} 	
		
		int ans=0;
		while(!pq.empty()){
			
			int cur_idx=q.front().first;
			int cur_pri=q.front().second;
			q.pop();
			if(pq.top() == cur_pri){
				pq.pop();
				ans++;
				if(cur_idx==Idx){
					printf("%d\n",ans);
				}
			}else{
				q.push({cur_idx,cur_pri});
			}
			
			
		}
		
		
		
	}
	
	
	return 0;
}
