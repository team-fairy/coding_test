#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<vector<int> > dp;
    vector<int> tmp;
    tmp.push_back(arr[0]);
    dp.push_back(tmp);

    for (int i=1; i<n; i++) {
        int start = 0, end = dp.size(), mid = 0;
        if (dp[end-1][dp[end-1].size()-1] < arr[i]) {
            vector<int> tmp = dp[end-1];
            tmp.push_back(arr[i]);
            dp.push_back(tmp);
            continue;
        }
        while(start < end) {
            mid = (start + end) / 2;
            if (dp[mid][dp[mid].size()-1] >= arr[i]) {
                end = mid;
            }
            else {
                start = mid+1;
            }
        }
        mid = (start + end) / 2;
        dp[mid][dp[mid].size()-1] = arr[i];
    }
    printf("%ld\n", n-dp[dp.size()-1].size());

}