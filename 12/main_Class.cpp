#define IN "P12IN.txt"
#define OUT "P12OUT.txt"
#include <iostream>
#include <vector>
using namespace std;
void redir();
void dir();

typedef struct command
{
    char c[3]; //"EX", "DC", "DR", "IC", "IR"
    int r1, c1, r2, c2;
    int a;
    int x[10]; //依題意
} CMD;
vector<CMD> cmd;
int r, c, n;
int simulate(int *r0, int *c0);

int main()
{
    redir();
    int i, j;
    int kase = 0;
    int q;
    int r0, c0;
    while (scanf("%d%d%d", &r, &c, &n) == 3)
    {
        for (i = 0; i < n; i++)
        {
            cmd.resize(cmd.size() + 1);
            scanf("%s", cmd[i].c);
            if (cmd[i].c[0] == 'E')
            {
                scanf("%d%d%d%d", &cmd[i].r1, &cmd[i].c1, &cmd[i].r2, &cmd[i].c2);
            }
            else
            {
                scanf("%d", &cmd[i].a);
                for (j = 0; j < cmd[i].a; j++)
                {
                    scanf("%d", &cmd[i].x[j]);
                }
            }
        }
        if (kase > 0)
        {
            printf("\n");
        }
        printf("Spreadsheet #%d\n", ++kase);
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d%d", &r0, &c0);
            printf("Cell data in (%d, %d) ", r0, c0);
            if (!simulate(&r0, &c0))
            {
                printf("GONE\n");
            }
            else
            {
                printf("moved to (%d, %d)\n", r0, c0);
            }
        }
    }
    //dir();
    return 0;
}

int simulate(int *r0, int *c0)
{
    int i;
    int j;
    int x;
    int dr, dc; //列變化量, 行變化量
    for (i = 0; i < n; i++)
    {
        if (cmd[i].c[0] == 'E')
        { //"EX"
            if (cmd[i].r1 == *r0 && cmd[i].c1 == *c0)
            {
                *r0 = cmd[i].r2;
                *c0 = cmd[i].c2;
            }
            else if (cmd[i].r2 == *r0 && cmd[i].c2 == *c0)
            {
                *r0 = cmd[i].r1;
                *c0 = cmd[i].c1;
            }
        }
        else
        { //計算列變化量, 行變化量
            dr = dc = 0;
            for (j = 0; j < cmd[i].a; j++)
            {
                x = cmd[i].x[j];
                if (cmd[i].c[0] == 'I')
                {
                    if (cmd[i].c[1] == 'R' && *r0 >= x)
                        dr++; //"IR"
                    if (cmd[i].c[1] == 'C' && *c0 >= x)
                        dc++; //"IC"
                }
                else
                { //cmd[i].c[0] == 'D'
                    if (cmd[i].c[1] == 'R' && *r0 == x)
                        return 0; //"DR" : 所在列被刪除
                    if (cmd[i].c[1] == 'C' && *c0 == x)
                        return 0; //"DC" : 所在欄被刪除
                    if (cmd[i].c[1] == 'R' && *r0 > x)
                        dr--; //"DR"
                    if (cmd[i].c[1] == 'C' && *c0 > x)
                        dc--; //"DC"
                }
            }
            *r0 += dr; //更新
            *c0 += dc;
        }
    }
    return 1;
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