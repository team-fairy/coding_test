#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007, MAX = 1000001;
int N; 
long dp[MAX][2];
 
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>N;
	
	
	
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 2;
	dp[1][1] = 1;
	
	
	for(int i=2;i<=N;i++)
	{
		
		dp[i][1] = dp[i-1][0] + dp[i-2][0] + dp[i-2][1];
		dp[i][1] %= MOD;;
		
		dp[i][0] = 2*dp[i][1] + dp[i-2][0];
		dp[i][0] %= MOD; 
	
	}
	

	cout<<dp[N][0];
	
	return 0;
}
