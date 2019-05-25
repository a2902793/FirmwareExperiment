#define IN "P20IN.txt"
#define OUT "P20OUT.txt"
#include <iostream>
using namespace std;
void redir();
void dir();

#include <string>
#include <cmath>
#include <algorithm>
void print(string s, int len, char extra);

int main()
{
    redir();
    int n;
    int M;
    string filename[100];
    int i;
    int cols, rows;
    int r, c;
    int id;
    while (scanf("%d", &n) == 1)
    {
        M = 0;
        for (i = 0; i < n; i++)
        {
            cin >> filename[i];
            M = max(M, (int)filename[i].length()); //注意轉型: (int)filename[i].length()
        }
        cols = (60 - M) / (M + 2) + 1;      //常數60來自題目: 每列60個字元
        rows = (int)ceil(double(n) / cols); //注意轉型
        print("", 60, '-');
        cout << endl;
        sort(filename, filename + n);
        for (r = 0; r < rows; r++)
        {
            for (c = 0; c < cols; c++)
            {
                id = c * rows + r; //column-major
                if (id < n)
                {
                    print(filename[id], c == cols - 1 ? M : M + 2, ' ');
                }
            }
            cout << endl;
        }
    }
    //dir();
    return 0;
}

//輸出字串s, 長度不足len時補字元extra
void print(string s, int len, char extra)
{
    int i;
    cout << s;
    for (i = 0; i < len - s.length(); i++)
    {
        cout << extra;
    }
}

void redir()
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}

void dir()
{
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
}