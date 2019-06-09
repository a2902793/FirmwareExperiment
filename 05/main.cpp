#define IN "P05IN.txt"
#define OUT "P05OUT.txt"
#include <stdio.h>
#include <algorithm>
void redir();
void dir();
#define maxn 1000 + 10

int main()
{
    redir();
    int n, a[maxn], b[maxn];
    int count = 0;
    while (scanf("%d", &n) == 1 && n)
    {
        printf("Game %d:\n", ++count);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (;;)
        {
            int A = 0, B = 0;
            /* 猜幾A */
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &b[i]);
                if (a[i] == b[i])
                    A++;
            }

            /* 猜幾B */
            if (b[0] == 0)
                break;
            for (int d = 1; d <= 9; d++)
            {
                int c1 = 0, c2 = 0;
                for (int i = 0; i < n; i++)
                {
                    if (a[i] == d)
                        c1++;
                    if (b[i] == d)
                        c2++;
                }
                B += std::min(c1,c2);
            }
            printf("    (%d,%d)\n", A, B - A);
        }
    }
    dir();
    return 0;
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