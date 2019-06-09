#define IN "P11IN.txt"
#define OUT "P11OUT.txt"
#include <iostream>
#include <cstring>
void redir();
void dir();

int readcodes(void);
int readint(int c);
int code[8][128];

int main()
{
    redir();
    int len;
    int v;
    char ch;
    while (readcodes())
    {
        for (;;)
        {
            len = readint(3);
            if (len == 0)
                break;
            for (;;)
            {
                v = readint(len);
                if (v == (1 << len) - 1)
                    break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    //dir();
    return 0;
}

int readcodes(void)
{
    int len, i;
    char ch;
    memset(code, 0, sizeof(code)); //清空陣列
    while ((ch = getchar()) == '\n')
        ; //跳過分行符號
    if (ch == EOF)
        return 0;
    code[1][0] = ch;
    for (len = 2; len <= 7; len++)
    {
        for (i = 0; i < (1 << len) - 1; i++)
        {
            ch = getchar();
            if (ch == '\n')
                return 1;
            code[len][i] = ch;
        }
    }
}

//讀取長度為c的01字串(二進位整數), 並將其轉換為十進位整數
int readint(int c)
{
    int v = 0;
    int ch;
    while (c--)
    {
        while ((ch = getchar()) == '\n')
            ; //跳過分行符號, 因為編碼文字可能由多行組成
        v = v * 2 + ch - '0';
    }
    return v;
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