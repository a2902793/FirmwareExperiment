#define IN "P06IN.txt"
#define OUT "P06OUT.txt"
#include <stdio.h>
#include <cstring>
void redir();
void dir();
#define maxn 100005
int ans[maxn];

int main()
{
    redir();
    int T, n;
    memset(ans, 0, sizeof(ans));
    for (int m = 1; m < maxn; m++)
    {
        int x = m, y = m;
        while (x > 0)
        {
            y += x % 10;
            x /= 10;
        }
        if (ans[y] == 0 || m < ans[y])
            ans[y] = m;
    }
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    //dir();
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