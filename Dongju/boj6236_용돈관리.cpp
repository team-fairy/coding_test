#include <iostream>
#include <algorithm>
using namespace std;

int N,M,s,e,mid,ans=0;
int arr[100001];



bool calc(int m,int k){
	
	int cnt = 1, cur = k;
	
	for(int i = 0; i < N ;i++){
		if( k < arr[i])
			return false;
		if(cur < arr[i]){
			cnt += 1;
			cur = k;
		}
		cur -= arr[i];
	}
	
	return cnt<=m;
}

int main(int argc, char** argv) {
	cin>>N>>M;
	
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	
	
	s = 1;
	e = 10000*100000;
	
	while(s<=e){
		
		mid= (s+e)/2;	
		
		
		
//		printf("s:%d e:%d  mid:%d ans:%d\n",s,e,mid,ans);
		
		if(calc(M,mid)){
			ans=mid;
			e=mid-1;
		}else{
			s=mid+1;
		}
		
		
		
	}
//	printf("s:%d e:%d  mid:%d ans:%d\n",s,e,mid,ans);
		
	cout<<ans;
	
	
	
	return 0;
}
