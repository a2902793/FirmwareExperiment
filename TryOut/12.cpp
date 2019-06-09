#define IN "P12IN.txt"
#define OUT "P12OUT.txt"
#include <iostream>
#include <vector>

void redir();
void dir();
using namespace std;

typedef struct Spreadsheet
{
    char cmd[5];    //存指令
    /* 交換用 */
    int r1,c1,r2,c2;
    /* 其他指令用 */
    int ins_del_cnt;        //計數
    int ins_del_array[10];  //存受影響之行列
}SS;
vector<SS> spreadsheet;
int r_init, c_init, operation_cnt;  //初始行、初始列、總運算數

int simulate(int *r_simu, int *c_simu);

int main()
{
    redir();
    int r_simu, c_simu, simu_cnt, _case = 0;    //模擬行、模擬列、第幾個case
    while(scanf("%d%d%d", &r_init, &c_init, &operation_cnt) == 3)   //當成功讀取後..
    {
        /* 記載所有運算 */
        for(int i = 0; i < operation_cnt; i++)
        {
            spreadsheet.resize(spreadsheet.size() + 1); //確保充足空間
            scanf("%s", spreadsheet[i].cmd);    //讀取指令

            /* 交換 */
            if(spreadsheet[i].cmd[0] == 'E')    //如果是交換 (EX)
            {
                scanf("%d%d%d%d",&spreadsheet[i].r1,&spreadsheet[i].c2,&spreadsheet[i].r2,&spreadsheet[i].c2);  //交換哪兩欄
            }
            /* 其他指令 */
            else                                //如果不是交換 (DR、DC、IR、IC)
            {
                scanf("%d", &spreadsheet[i].ins_del_cnt);   //計數受影響行列總數
                for(int j = 0; j < spreadsheet[i].ins_del_cnt; j++)
                {
                    scanf("%d",&spreadsheet[i].ins_del_array[j]);   //將受影像行列存入陣列
                }
            }
        }

        /* 印出標頭 */
        if(_case > 0)
        {
            printf("\n");
        }
        printf("Spreadsheet #%d\n",++_case);
        /* 查詢 */
        scanf("%d",&simu_cnt);  //計數查詢次數
        while(simu_cnt--)
        {
            scanf("%d%d",&r_simu,&c_simu);  //查看哪一行哪一列
            printf("Cell data in (%d,% d)", r_simu, c_simu);
            /* 模擬 */
            if(!simulate(&r_simu, &c_simu)) //如果結果為被移走則回傳0
            {
                printf("GONE\n");
            }
            else
            {
                printf("moved to (%d, %d)\n", r_simu, c_simu);
            }

        }

    }
    //dir();
    return 0;
}

int simulate(int *r_simu, int *c_simu)
{
    int dr, dc; //列變化量, 行變化量
    int ins_del_num;    //被插入或刪除之數
    for(int i = 0; i < operation_cnt; i++)
    {
        /* 交換 */
        if(spreadsheet[i].cmd[0] == 'E')
        {
            if(spreadsheet[i].r1 == *r_simu && spreadsheet[i].r2 == *c_simu)
            {
                *r_simu = spreadsheet[i].r2;
                *c_simu = spreadsheet[i].c2;
            }
            else if(spreadsheet[i].r2 == *r_simu && spreadsheet[i].c2 == *c_simu)
            {
                *r_simu = spreadsheet[i].r1;
                *c_simu = spreadsheet[i].c1;
            }
        }
        /* 其他指令 */
        else
        {
            dr = dc = 0;
            for(int j = 0; j < spreadsheet[j].ins_del_cnt; j++)
            {
                ins_del_num = spreadsheet[j].ins_del_array[j];
                /* 插入 */
                if(spreadsheet[i].cmd[0] == 'I')
                {
                    if(spreadsheet[i].cmd[1] == 'R' && *r_simu >= ins_del_num)  //有插入比查詢行更小的話，表示原查詢行已移至＋1行
                        dr++;
                    if(spreadsheet[i].cmd[1] == 'c' && *c_simu >= ins_del_num)  //有插入比查詢列更小的話，表示原查詢行已移至＋1列
                        dc++;
                }
                /* 刪除 */
                else
                {
                    if(spreadsheet[i].cmd[1] == 'R' && *r_simu == ins_del_num)  //若查詢行等於被刪除行，表示空(回傳0讓上面if判斷顯示GONE)
                        return 0;
                    if(spreadsheet[i].cmd[1] == 'C' && *c_simu == ins_del_num)  //若查詢列等於被刪除列，表示空(回傳0讓上面if判斷顯示GONE
                        return 0;
                    if(spreadsheet[i].cmd[1] == 'R' && *r_simu > ins_del_num)   //有插入比查詢行更小的話，表示原查詢行已移至-1行
                        dr--;
                    if(spreadsheet[i].cmd[1] == 'C' && *c_simu > ins_del_num)   //有插入比查詢列更小的話，表示原查詢行已移至-1列
                        dc--;

                }
            }
            *r_simu += dr;  //將變化加在查詢行上
            *c_simu += dc;  //將變化加在查詢列上
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