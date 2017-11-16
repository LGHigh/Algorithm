#include <cstdio>  
#include <iostream>  
#include <cmath>  
#include <string>  
#include <algorithm>  
using namespace std;  
const int maxn = 101;  
int n;  
  
int main() {  
    string file[maxn];  
    int cmax;  
    while (scanf("%d", &n) != EOF) {  
        printf("------------------------------------------------------------\n");  
        cmax = 0;  
        for (int i = 0; i < n; i++) {  
            cin >> file[i];  
            cmax = max(cmax, (int)file[i].size());  
        }  
        int col = 62 / (cmax + 2);  
        int row = ceil(1.0 * n / col);  
        sort (file, file + n);  
        for (int i = 0; i < row; i++) {  
            for (int j = 0; j < col; j++) {  
                //  printf("%s", file[i * row + j]);  
                int t = j * row + i;  
                if (t >= n)  
                    continue;  
                cout << file[t];  
                int k = cmax - file[t].size();  
                while (k--)  
                    printf(" ");  
                if (j != col - 1)  
                    printf("  ");  
            }  
            if (i <= row - 1)  
                printf("\n");  
        }  
    }  
    return 0;  
}  

/*Time Limit Exceeded*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxcol = 60;
const int maxn = 105;
string filenames[maxn];

void print(const string& s, int len, char extra) {
	cout << s;
	for (int i = 0; i < len - s.length(); i++) {
		cout << extra;
	}
}

int main() {
	int n;
	while (cin >> n) {
		int M = 0;
		for (int i = 0; i < n; i++) {
			cin >> filenames[i];
			M = max(M, (int)filenames->length());
		}
		int cols = (maxcol - M) / (M + 2) + 1;
		int rows = (n - 1) / cols + 1;
		printf("", 60, '-');
		cout << "\n";
		sort(filenames, filenames + n);
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				int idx = c*rows + r;
				if (idx < n)print(filenames[idx], c == cols - 1 ? M : M + 2, ' ');
			}
			cout << "\n";
		}
	}
	
}