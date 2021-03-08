#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 11;
int N;
int People[MAX];
int index[MAX];
int main(int argc, char** argv) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>People[i];
	}
	
	for(int i=1;i<=N;i++)
	{
		
		int bigger = People[i];
		
		int j=1,cnt=0;
		while(1){
			
			if(index[j]){
				j++;
				continue;
			}
			
			if (bigger == cnt){
				index[j] = i;
				break;
			}
			
			j++,cnt++;
			
		}
		
		
		
	}
	
	for(int i=1;i<=N;i++)
	{
		printf("%d ",index[i]);
	}

	return 0;
}
