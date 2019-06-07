#define IN "P14IN.txt"
#define OUT "P14OUT.txt"
#include <iostream>
void redir();
void dir();

#include <string>
#include <vector>
using namespace std;

void find_block(int a, int &pa, int &ha);
void clear_above(int p, int h);
void pipe_over(int p, int h, int p2);
void show(void);
int n;
vector<int> pipe[25]; //二維陣列(第一維大小根據題意, 第二維大小不固定)

int main()
{
    redir();
    int i;
    string s1, s2;
    int a, b;
    int pa, pb; //pa, pb: position of a and b
    int ha, hb; //ha, hb: height of a and b
    cin >> n;
    for (i = 0; i < n; i++)
    {
        pipe[i].push_back(i);
    }
    while (1)
    {
        cin >> s1;  // Pile/Move
        if (s1 == "quit")
        { // '==' is overloaded for type string
            break;
        }
        else
        {
            cin >> a >> s2 >> b; // a over/onto b
            find_block(a, pa, ha);  // 更動pa,ha值
            find_block(b, pb, hb);  // 更動pb,hb值
            if (pa == pb)
            {
                continue; //非法指令
            }
            if (s1 == "move")
            {
                clear_above(pa, ha);
            }
            if (s2 == "onto")
            {
                clear_above(pb, hb);
            }
            pipe_over(pa, ha, pb);
        }
    }
    show();
    //dir();
    return 0;
}

//發現木塊a的位置p和高度h(皆從0算起)
void find_block(int a, int &p, int &h)
{
    for (p = 0; p < n; p++)
    {
        for (h = 0; h < pipe[p].size(); h++)
        {
            if (pipe[p][h] == a)
            {
                return;
            }
        }
    }
}
//把第p堆高度為h的木塊"上方的"所有木塊歸位
void clear_above(int p, int h)
{
    int i;
    int b;
    for (i = pipe[p].size() - 1; i > h; i--)
    {
        b = pipe[p][i];
        pipe[b].push_back(b);
    }
    pipe[p].resize(h + 1);
}
//把第p堆高度h"及其上方"的木塊整體移動到第p2堆的頂部
void pipe_over(int p, int h, int p2)
{
    int i;
    for (i = h; i < pipe[p].size(); i++)
    {
        pipe[p2].push_back(pipe[p][i]);
    }
    pipe[p].resize(h);
}

//[木塊問題/The Blocks Problem](3/3)
//輸出結果
void show(void)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("%d: ", i);
        for (j = 0; j < pipe[i].size(); j++)
        {
            printf("%d ", pipe[i][j]);
        }
        printf("\n");
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