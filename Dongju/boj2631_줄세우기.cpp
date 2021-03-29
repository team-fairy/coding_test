#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=201;
int N;
int arr[MAX];
int dp[MAX];
int MAXLEN=-1;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	
	for(int i=0;i<N;i++)	
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<N;i++)
	{
		
		dp[i] = 1;
		for(int j=0; j<i; j++)
		{
			if(arr[j]<arr[i]){
				
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		MAXLEN = max(MAXLEN,dp[i]);
	}
	
	cout<<N-MAXLEN;
	
	
	return 0;
}
