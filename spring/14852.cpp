#include <iostream>

int main(void) {
    int n;
    scanf("%d", &n);

    long long int arr[n];

    if (n == 1)
        printf("2\n");
    else if (n==2)
        printf("7\n");
    else {
        arr[0] = 2, arr[1] = 7;
        long long int tmp = 1;
        for (int i=2; i<n; i++) {
            arr[i] = (arr[i-1] * 2 + arr[i-2] * 3 + 2 * tmp) % 1000000007;
            tmp += arr[i-2];
        }
        printf("%lld\n", arr[n-1]);
    }
}