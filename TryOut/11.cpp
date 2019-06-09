#define IN "P11IN.txt"
#define OUT "P11OUT.txt"
#include <iostream>
#include <cstring>
void redir();
void dir();

int readcode();
int readint(int c);
int code[8][5]; //設 8 跟 5 是因為 (1)最長字元長度為7，1~7 加上原本code[0]所以一共8個
                //                (2)範例output沒有一個超出第5位，但這可能要更改因為有可能驗收會

int main()
{
    redir();
    while(readcode())   //會判斷是否讀到 EOF
    {
        for(;;) //無限for迴圈 - 直到遇到 00 (len = 0) 退出
        {
            int len = readint(3);   //將前三碼轉成十進位
            if(len == 0)
                break;
            for(;;)
            {
                int v = readint(len);   //將「前面轉成十進位後的len」碼轉成十進位
                if(v == (1 << len) - 1) //遇到全為1 (1,11,111...) 的時候斷開
                    break;
                putchar(code[len][v]);  //輸出 code[長度為len的字串][的第幾個]
            }
        }
        putchar('\n');
    }
    //dir();
    return 0;
}

int readcode()
{
    char ch;
    memset(code, 0, sizeof(code));  //開空間，可加可不加
    /* 讀取編碼頭 */
    while((ch = getchar()) == '\n') //
        ;
    if(ch == EOF)
        return 0;   //回傳0給上面main跳出while
    code[1][0] = ch;    //因為00只有一個元素所以直接指定就好 (用code[1]不用code[0]是為了直觀)
    for(int len = 2; len <=7; len++)    //從第二到第
    {
        for(int i = 0; i < (1 << len) - 1; i++)   // 1->4     2->8      3->16   ...
        {
            ch = getchar();
            if(ch == '\n')
                return 1;
            code[len][i] = ch;
        }
    }
}

int readint(int c)
{
    int v = 0;
    char ch;
    while(c--)
    {
        while((ch = getchar()) == '\n')
            ;
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