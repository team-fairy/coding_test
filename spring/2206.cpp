#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n][m];
    bool visited[n][m][2];
    for (int i=0; i<n; i++) {
        char s[m];
        scanf("%s", s);

        for (int j=0; j<m; j++) {
            if (s[j] == '0')
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
            visited[i][j][0] = false;
            visited[i][j][1] = false;
        }
    }

    queue<pair<int, int> > unbroken;
    queue<pair<int, int> > broken;

    int x_move[4] = {0, 0, 1, -1};
    int y_move[4] = {1, -1, 0, 0};

    int depth = 1;
    unbroken.push(pair<int, int>(0, 0));
    visited[0][0][0] = true;
    while (!broken.empty() or !unbroken.empty()) {
        int broke_len = broken.size();
        int unbroke_len = unbroken.size();

        for (int i=0; i<unbroke_len; i++) {
            pair<int, int> curr = unbroken.front();
            //printf("(%d, %d)\t", curr.first, curr.second);
            unbroken.pop();

            // if curr is destination: print & terminate
            if (curr.first == n-1 && curr.second == m-1) {
                printf("%d\n", depth);
                return 0;
            }
            for (int i=0; i<4; i++) {
                int n_x = curr.first + x_move[i], n_y = curr.second + y_move[i];
                if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < m && !visited[n_x][n_y][0]) {
                    if (arr[n_x][n_y] == 0)
                        unbroken.push(pair<int, int>(n_x, n_y));
                    else
                        broken.push(pair<int, int>(n_x, n_y));
                    visited[n_x][n_y][arr[n_x][n_y]] = true;
                }
            }
        }

        for (int i=0; i<broke_len; i++) {
            pair<int, int> curr = broken.front();
            broken.pop();
            //printf("(%d, %d)\t", curr.first, curr.second);
            // if curr is destination: print & terminate
            if (curr.first == n-1 && curr.second == m-1) {
                printf("%d\n", depth);
                return 0;
            }
            for (int i=0; i<4; i++) {
                int n_x = curr.first + x_move[i], n_y = curr.second + y_move[i];
                if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < m && arr[n_x][n_y] == 0 && !visited[n_x][n_y][1]) {
                    broken.push(pair<int, int>(n_x, n_y));
                    visited[n_x][n_y][1] = true;
                }
            }
        }
        depth += 1;
        //printf("\n");
    }
    printf("-1\n");
    return 0;
}