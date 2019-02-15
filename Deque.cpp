#include <bits/stdc++.h>

using namespace std;

int main() {
        int n, top = 1;
        cin >> n;
        vector<int> D(n + 1), L(n + 1), R(n + 1), cur(n + 1);
        for(int i = 1; i <= n; i++) cin >> cur[i];
        for(int i = 1; i <= n; i++) {
                while(top > 0 && cur[D[top]] >= cur[i]) top--;
                L[i] = D[top] + 1;
                D[++top] = i;
        }
        D[1] = n;
        D[0] = n + 1;
        top = 1;
        for(int i = n; i >= 0; i--) {
                while(top > 0 && cur[D[top]] >= cur[i]) top--;
                R[i] = D[top] - 1;
                D[++top] = i;
        }
        for(int i = 1; i <= n; i++) cout << L[i] << " ";
        cout << endl;
        for(int i = 1; i <= n; i++) cout << R[i] << " ";
        return 0;
}
