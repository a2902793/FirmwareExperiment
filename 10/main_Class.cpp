#define IN "P10IN.txt"
#define OUT "P10OUT.txt"
#include <iostream>
using namespace std;
void redir();
void dir();

int a[20];
int n;
int go(int p, int d, int t);
int main()
{
    redir();
        int i;
    int left;
    int pA, pB;
    int k, m;
    while (scanf("%d%d%d", &n, &k, &m) == 3 && n)
    {
        for (i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        left = n;
        pA = n;
        pB = 1;
        while (left)
        {
            pA = go(pA, 1, k);
            pB = go(pB, -1, m);
            printf("%3d", pA);
            left--;
            if (pB != pA)
            {
                printf("%3d", pB);
                left--;
            }
            a[pA] = a[pB] = 0;
            if (left)
                printf(",");
        }
        printf("\n");
    }
    //dir();
    return 0;
}

int go(int p, int d, int t)
{
    while (t--)
    {
        do
        {
            p = p + d;
            if (p == (n + 1))
                p = 1;
            if (p == 0)
                p = n;
        } while (a[p] == 0);
    }
    return p;
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