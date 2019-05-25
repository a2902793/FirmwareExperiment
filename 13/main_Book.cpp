#define IN "P13IN.txt"
#define OUT "P13OUT.txt"
#include <cstdio>
#include <algorithm>
using namespace std;
void redir();
void dir();

const int maxn = 10000;

int main()
{
    redir();
    int n, q, x, a[maxn], kase = 0;
    while (scanf("%d%d", &n, &q) == 2 && n)
    {
        printf("CASE# %d:\n", ++kase);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n); // 排序
        while (q--)
        {
            scanf("%d", &x);
            int p = lower_bound(a, a + n, x) - a; // 在已排序数组a中寻找x
            if (p < n && a[p] == x)
                printf("%d found at %d\n", x, p + 1);
            else
                printf("%d not found\n", x);
        }
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