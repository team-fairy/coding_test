#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    // n의 값을 입력
    int size;
    cin >> size;

    // n개의 arr element를 저장할 공간 & stk
    int arr[size];
    int stk[size];

    // n개의 element를 입력
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }

    // stk_point: push/pop
    int curr = 1;
    int stk_point = 0;
    bool output[size * 2]; // true: +, false: -
    int output_ind = 0;

    // algorithm
    for (int i=0; i<size; i++) { // arr element를 순회
        while (stk_point == 0 || stk[stk_point-1] < arr[i]) {
            stk[stk_point++] = curr++;
            output[output_ind++] = true;
        }
        if (stk[stk_point-1] != arr[i]) {
            cout <<"NO\n";
            return 0;
        }
        output[output_ind++] = false;
        stk_point--;
    }

    for (int i=0; i<output_ind; i++) {
        if (output[i])
            cout << "+\n";
        else
            cout << "-\n";
    }
    return 0;
}