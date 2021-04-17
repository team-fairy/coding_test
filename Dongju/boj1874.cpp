#include <iostream>
#include <stack>
#include <vector>
using  namespace std;


int main(int argc, char** argv) {
	
	int n,x;
	cin>>n;
	stack<int> stck;
	int idx=1,t=0;
	vector<char> ans(2*n);
	
	for(int i=0;i<n;i++){
		
		cin>>x;
		
		while(stck.empty() || stck.top()!=x)
		{
			if(idx>n)	
			{
				printf("NO");
				return 0;
			}
		
			stck.push(idx++);
			ans[t++] = '+';
		}
		
		stck.pop();
		ans[t++]='-';
		
		
	}
	
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<"\n";
	}
	return 0;
}
