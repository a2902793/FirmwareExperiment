#define IN "P10IN.txt"
#define OUT "P10OUT.txt"
#include <stdio.h>
void redir();
void dir();

#define maxn 25
int n, k, m, a[maxn];
int go(int p, int d, int t);

int main()
{
  redir();
  while (scanf("%d%d%d", &n, &k, &m) == 3 && n)
  {
    for (int i = 1; i <= n; i++)
      a[i] = i;
    int left = n; // 还剩下的人数
    int p1 = n, p2 = 1;
    while (left)
    {
      p1 = go(p1, 1, k);
      p2 = go(p2, -1, m);
      printf("%3d", p1);
      left--;
      if (p2 != p1)
      {
        printf("%3d", p2);
        left--;
      }
      a[p1] = a[p2] = 0;
      if (left)
        printf(",");
    }
    printf("\n");
  }
  dir();
  return 0;
}

int go(int p, int d, int t)
{
  while (t--)
  {
    do
    {
      p = (p + d + n - 1) % n + 1;
    } while (a[p] == 0); // 走到下一个非0数字
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