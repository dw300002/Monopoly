#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#define red SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED); //將字體設為紅色
#define wht SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)//將字體設為白色
#define pur SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE) //將字體設為紫色
#define grn SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE) //將字體設為青色
#define yew SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN)  //將字體設為黃色
#define bgblue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);  //將字體設為藍綠色
#define slp0 500
#define slp1 1000
#define slp2 1500
#define slp3 2000
#define slp4 4000
#define n 13
void world(int s); //玩家們的回合                                                  (范雲漢)
void world_set(); //將土地設定為0.1.2的形式                                        (范雲漢)
void world_print(); //根據world_set的0.1.2印出相對應的符號及格式                   (范雲漢)
void move_player(int s); //根據骰子數把玩家移動                                    (范雲漢)
int dice(); //骰子點數設定                                                         (范雲漢)
void start();  //開始畫面                                                          (范雲漢)
void rules();  //規則                                                              (吳宥萱)
void player_choose(); //選擇角色畫面                                               (王博弘)
void print_detail(int a); //印出選擇角色後的屬性                                   (王博弘)
void player1();//玩家1的main                                                       (王博弘)
void player2();//玩家2的AI                                                         (王博弘)
void player3();//玩家3的AI                                                         (王博弘)
void player4();//玩家4的AI                                                         (王博弘)
void print_situation();//印出角色目前兵力金錢CD等資訊                              (王博弘)
void player_rule(int pr); //放在玩家們的資訊欄裡面，讓其了解目前是什麼腳色         (王博弘)
void gotoxy(int xpos, int ypos);//移動游標座標                                     (范雲漢)
void player_xy_switch(int a); //控制玩家能在五格內，不會走超出邊界                 (范雲漢)
void player_set();//設定初始站位1.5.9.13                                           (范雲漢)
void player_print(int p);//印出角色                                                (范雲漢)
void land_set();//看1~16格哪個玩家佔領哪格                                         (王博弘)
void land_xy_switch(int ls); //佔領格子的玩家是誰並依據玩家印出土地相對應的        (王博弘)
void chance_or_destiny(int cod,int man);//機會命運                                 (共同一起)
void player_now_print();//看1~16格哪個玩家佔領哪格                                 (范雲漢)
void superpower(int people,int people2, int ch_i);//使用絕招                       (共同一起)
void attack_land(int al,int alp); //攻城                                           (范雲漢)
void attack_door(int ad); //闖關                                                   (范雲漢)
void you_win(); //獲勝時畫面                                                       (吳宥萱)
void you_lose(); //破產時畫面                                                      (吳宥萱)
void you_win1(); //獲勝介面                                                        (吳宥萱)
void you_win2(); //獲勝介面                                                        (吳宥萱)
void you_lose1(); // 破產介面                                                      (吳宥萱)
void you_lose2(); // 破產介面                                                      (吳宥萱)
void pk(int pk1,int pk2);//pk                                                      (王博弘)
void pk_view();//pk介面                                                            (吳宥萱)
void p();//pk介面                                                                  (吳宥萱)
void p_k();//pk介面                                                                (吳宥萱)
void fight1();//pk介面                                                             (吳宥萱)
void fight2();//pk介面                                                             (吳宥萱)
void fight3();//pk介面                                                             (吳宥萱)
int i,j,x,y,z,w,a,cod;
int withdraw1=0,savemoney1=0; //存款提款金額
int lightning=0;//皮卡丘麻痺的倒數
char y_n; //yes no
int world1[n][n]= {0}; //土地矩陣
int player_situation[6][4]= {0}; //玩家的編號、位置、金額、存款、兵力、CD
int land_situationl[4][16]= {0};//土地的編號、所有者、過路費、城內兵力
int force_quanity;//兵力(扣或增)
int player[4];//player[0]代表玩家，player[1]代表電腦1，以此類推到電腦3
int money_cosume=0;//選擇佔領之後的花費
int army_lose1=0,army_lose2=0,money_lose=0,money_gap=0; //pk時損失兵力
int CD[10]= {0,8,10,8,10,9,5,4,7,6}; //絕招的CD
int main()                                                                       //(王博弘)
{
    start();
    rules();
    int l,u;
    int pl2l=0,pl3l=0,pl4l=0;

    char yn;//讓玩家選擇(Y/N)
    player_choose();
    do
    {
f1:
        printf("\n請選擇角色:");
        scanf("%d",&player[0]);
        if(player[0]>9 || player[0]<1)
        {
            printf("請輸入1~9!!\n");
        }
        else
        {
            printf("確認選擇角色 %d? (Y/N):",player[i]);
            scanf(" %c",&yn);
            yn=toupper(yn);       //把輸入轉換成大寫
            if(yn=='Y')
            {
                printf("\n你的角色:");
                print_detail(player[i]);
                break;
            }
            else if(yn=='N')
            {
                goto f1;
            }
        }
    }
    while(1);
    printf("輪到電腦選角色了!\n");
    system("PAUSE");
    srand((unsigned)time(NULL));
    for(j=1; j<=3; j++) //給3位電腦
    {
        int x;
f2:
        i++;
        player[i]=rand()%8+1;

        for(x=0; x<i; x++) //檢查player[i]有沒有和前面所選的角色重複
        {
            if(player[i]==player[x])
            {
                i--;
                goto f2;
            }
        }
        printf("\n電腦%d的角色:",j);
        print_detail(player[i]);
    }
    red;
    printf("\n準備開始遊戲!!\n\n");
    wht;
    system("PAUSE");
    system("cls");
    /***************************以下為正式進入遊戲數值初始化****************************/
    for(l=0; l<=3; l++) //CD值設定
    {
        player_situation[5][l]=CD[player[l]];
    }
    for(l=0; l<=3; l++) //玩家金錢兵力初始化
    {
        player_situation[2][l]=10000;
        player_situation[4][l]=10000;
    }
    for(i=0; i<=15; i++)
    {
        land_situationl[0][i]=i+1;
    }
    for(i=0; i<=15; i++)
    {
        land_situationl[1][i]=0;
    }
    for(i=0; i<16; i++)
    {
        land_situationl[2][i]=(rand()%5+3)*100;
    }
    for(i=0; i<16; i++) //城內駐軍
    {
        land_situationl[3][i]=1000;
    }
    /**************開始遊戲***************/
g1:
    world_set();
    world_print();
    print_situation();
    player_set();
    do
    {

        if(player_situation[2][0]<=0 && player_situation[3][0]<=0)  //玩家1破產
        {

            printf("您已經沒有金錢了...\n");
            Sleep(slp3);
            do
            {
                you_lose1();
                Sleep(slp1);
                system("cls");
                you_lose2();
                Sleep(slp1);
                system("cls");
            }
            while(1);
        }
        else if((player_situation[2][1]<=0 && player_situation[3][1]<=0) && (player_situation[2][2]<=0 && player_situation[3][2]<=0) && (player_situation[2][3]<=0 && player_situation[3][3]<=0)) //其他玩家皆破產，玩家1獲勝
        {
            printf("其他玩家皆破產了!!!!!!\n");
            Sleep(slp3);
            system("PAUSE");
            do
            {
                you_win1();
                Sleep(slp1);
                system("cls");
                you_win2();
                Sleep(slp1);
                system("cls");
            }
            while(1);
        }
        else if((player_situation[2][1]<=0 && player_situation[3][1]<=0) && (player_situation[2][2]<=0 && player_situation[3][2]<=0)) //玩家2.3破產
        {
            if(pl2l==0)
            {
                grn;
                printf("玩家2已經破產...\n玩家2土地將被清空\n");
                player_situation[1][1]=-102;
                Sleep(slp3);
                wht;
                pl2l++;
            }
            if(pl3l==0)
            {
                pur;
                printf("玩家3已經破產...\n玩家3土地將被清空\n");
                player_situation[1][2]=-103;
                Sleep(slp3);
                wht;
                pl3l++;
            }
            for(u=0; u<=15; u++) //將玩家2.3的土地清空
            {
                if(land_situationl[1][u]==102 ||land_situationl[1][u]==103)
                {
                    land_situationl[1][u]=0;
                }
            }
            for(u=0; u<=15; u++) //將土地兵力+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==104)
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("您的回合結束，輪到玩家4\n");
            player4();
            printf("玩家4的回合結束，輪到玩家1\n");
        }
        else if((player_situation[2][2]<=0 && player_situation[3][2]<=0) && (player_situation[2][3]<=0 && player_situation[3][3]<=0)) //玩家3.4破產
        {
            if(pl3l==0)
            {
                pur;
                printf("玩家3已經破產...\n玩家3土地將被清空\n");
                player_situation[1][2]=-103;
                Sleep(slp3);
                wht;
                pl3l++;
            }
            if(pl4l==0)
            {
                yew;
                printf("玩家4已經破產...\n玩家4土地將被清空\n");
                player_situation[1][3]=-104;
                Sleep(slp3);
                wht;
                pl4l++;
            }
            for(u=0; u<=15; u++) //將玩家4.3的土地清空
            {
                if(land_situationl[1][u]==103 ||land_situationl[1][u]==104)
                {
                    land_situationl[1][u]=0;
                }
            }
            for(u=0; u<=15; u++) //將土地兵力+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==102)
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("您的回合結束，輪到玩家2\n");
            player2();
            printf("玩家2的回合結束，輪到玩家1\n");
        }
        else if((player_situation[2][1]<=0 && player_situation[3][1]<=0) && (player_situation[2][3]<=0 && player_situation[3][3]<=0))//玩家2.4破產
        {
            if(pl2l==0)
            {
                grn;
                printf("玩家2已經破產...\n玩家土地將被清空\n");
                player_situation[1][1]=-102;
                Sleep(slp3);
                wht;
                pl2l++;
            }
            if(pl4l==0)
            {
                yew;
                printf("玩家4已經破產...\n玩家4土地將被清空\n");
                player_situation[1][3]=-104;
                Sleep(slp3);
                wht;
                pl4l++;
            }
            for(u=0; u<=15; u++) //將玩家2.4的土地清空
            {
                if(land_situationl[1][u]==102 ||land_situationl[1][u]==104)
                {
                    land_situationl[1][u]=0;
                }
            }
            for(u=0; u<=15; u++) //將土地兵力+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==103)
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("您的回合結束，輪到玩家3\n");
            player3();
            printf("玩家3的回合結束，輪到玩家1\n");
        }
        else if(player_situation[2][1]<=0 && player_situation[3][1]<=0) //玩家2破產
        {
            if(pl2l==0)
            {
                grn;
                printf("玩家2已經破產...\n玩家2土地將被清空\n");
                player_situation[1][1]=-102;
                Sleep(slp3);
                wht;
                pl2l++;
            }
            for(u=0; u<=15; u++) //將玩家2的土地清空
            {
                if(land_situationl[1][u]==102)
                {
                    land_situationl[1][u]=0;
                }
            }
            for(u=0; u<=15; u++) //將土地兵力+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==103 || land_situationl[1][u]==104 )
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("您的回合結束，輪到玩家3\n");
            player3();
            printf("玩家3的回合結束，輪到玩家4\n");
            player4();
            printf("玩家4的回合結束，輪到玩家1\n");
        }
        else if(player_situation[2][2]<=0 && player_situation[3][2]<=0) //玩家3破產
        {
            if(pl3l==0)
            {
                pur;
                printf("玩家3已經破產...\n玩家3土地將被清空\n");
                player_situation[1][2]=-103;
                Sleep(slp3);
                wht;
                pl3l++;
            }
            for(u=0; u<=15; u++) //將玩家3的土地清空
            {
                if(land_situationl[1][u]==103)
                {
                    land_situationl[1][u]=0;
                }
            }
            for(u=0; u<=15; u++) //將土地兵力+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==102 || land_situationl[1][u]==104 )
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("您的回合結束，輪到玩家2\n");
            player2();
            printf("玩家2的回合結束，輪到玩家4\n");
            player4();
            printf("玩家4的回合結束，輪到玩家1\n");
        }
        else if(player_situation[2][3]<=0 && player_situation[3][3]<=0) //玩家4破產
        {
            if(pl4l==0)
            {
                yew;
                printf("玩家4已經破產...\n玩家4土地將被清空\n");
                player_situation[1][3]=-104;
                Sleep(slp3);
                wht;
                pl4l++;
            }
            for(u=0; u<=15; u++) //將玩家4的土地清空
            {
                if(land_situationl[1][u]==104)
                {
                    land_situationl[1][u]=0;
                }
            }
            for(u=0; u<=15; u++) //將土地兵力+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==102 || land_situationl[1][u]==103 )
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("您的回合結束，輪到玩家2\n");
            player2();
            printf("玩家2的回合結束，輪到玩家3\n");
            player3();
            printf("玩家3的回合結束，輪到玩家1\n");
        }
        else
        {
            for(u=0; u<=15; u++) //將土地兵力+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==103 || land_situationl[1][u]==104 || land_situationl[1][u]==102 )
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("您的回合結束，輪到玩家2\n");
            player2();
            printf("玩家2的回合結束，輪到玩家3\n");
            player3();
            printf("玩家3的回合結束，輪到玩家4\n");
            player4();
            printf("玩家4的回合結束，輪到玩家1\n");
        }
    }
    while(1);
    return 0;
}
void player_choose()
{
    wht;
    printf("\t\t\t     ======角色選擇=====\t\t\t\n\n");
    printf(" －－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－\n│");
    red;
    printf("1.宇智波佐助\t\t");
    wht;
    printf(" ｜");
    pur;
    printf("2.馬英丸\t\t");
    wht;
    printf("  ｜");
    grn;
    printf("3.來來哥\t\t ");
    wht;
    printf("   ｜\n│");
    red;
    printf("-宇智波一族僅存的最後一");
    wht;
    printf("｜");
    pur;
    printf("-中華銘國為人詬病之總統");
    wht;
    printf("｜");
    grn;
    printf("-對社會運動頗為熱情的男 ");
    wht;
    printf("｜\n｜");
    red;
    printf(" 人，俊酷的外表下隱藏強");
    wht;
    printf("｜");
    pur;
    printf(",右手隱藏著極大的能量  ");
    wht;
    printf("｜");
    grn;
    printf(" 子,其口頭禪曾經風行一時");
    wht;
    printf("｜\n｜");
    bgblue;
    printf("絕招:萬花筒寫輪眼");
    wht;
    printf("      ｜");
    bgblue;
    printf("絕招:死亡之握");
    wht;
    printf("          ｜");
    bgblue;
    printf("絕招:哩尬挖來!");
    wht;
    printf("          ｜\n｜");
    bgblue;
    printf("闖關時不耗損兵力,且可以");
    wht;
    printf("｜");
    bgblue;
    printf("pk時發動，對手兵力減半");
    wht;
    printf(" ｜");
    bgblue;
    printf("強制將在自己後面5格內的");
    wht;
    printf(" ｜\n｜");
    bgblue;
    printf("招降10％敵方城內士兵");
    wht;
    printf("\t ｜\t\t\t  ｜");
    bgblue;
    printf("對手移動到自己的格位");
    wht;
    printf("    ｜\n｜");
    bgblue;
    printf("CD:8");
    wht;
    printf("\t\t\t ｜");
    bgblue;
    printf("CD:10");
    wht;
    printf("\t\t  ｜");
    bgblue;
    printf("CD:8");
    wht;
    printf("\t\t    ｜\n｜\t\t\t ｜\t\t\t  ｜\t\t\t    ｜\n －－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－\n｜");
    grn;
    printf("4.冰雪女王艾莎\t");
    wht;
    printf(" ｜");
    red;
    printf("5.蟹老闆\t\t");
    wht;
    printf("  ｜");
    yew;
    printf("6.魯夫\t\t");
    wht;
    printf("    ｜\n｜");
    grn;
    printf("-皇家背景,自幼便擁有冰");
    wht;
    printf(" ｜");
    red;
    printf("-蟹堡王董事長,\"嗜錢如命");
    wht;
    printf("｜");
    yew;
    printf("-立誓成為海賊王的男人,誤");
    wht;
    printf("｜\n｜");
    grn;
    printf(" 雪魔法，同時擁有一副好");
    wht;
    printf("｜");
    red;
    printf("，壓榨勞工\"指的就是他");
    wht;
    printf("  ｜");
    yew;
    printf(" 食橡膠果實讓其身體富有 ");
    wht;
    printf("｜\n｜");
    grn;
    printf(" 歌喉\t\t\t ");
    wht;
    printf("｜\t\t\t  ｜");
    yew;
    printf(" 彈性\t\t    ");
    wht;
    printf("｜\n｜");
    bgblue;
    printf("絕招:LET IT GO");
    wht;
    printf("\t ｜");
    bgblue;
    printf("絕招:美味蟹堡");
    wht;
    printf("\t  ｜");
    bgblue;
    printf("絕招:伸縮自如的橡膠手槍");
    wht;
    printf(" ｜\n｜");
    bgblue;
    printf("可攻下一次別人的土地");
    wht;
    printf("   ｜");
    bgblue;
    printf("丟一次骰子，將現金乘上");
    wht;
    printf(" ｜");
    bgblue;
    printf("若自己領地在前或後一格,");
    wht;
    printf(" ｜\n｜\t\t\t ｜");
    bgblue;
    printf("\"1+(0.1*該點數)\"");
    wht;
    printf("\t  ｜");
    bgblue;
    printf("可補充兵力");
    wht;
    printf("\t\t    ｜\n｜");
    bgblue;
    printf("CD:10");
    wht;
    printf("\t\t\t ｜");
    bgblue;
    printf("CD:9");
    wht;
    printf("\t\t\t  ｜");
    bgblue;
    printf("CD:5");
    wht;
    printf("\t\t    ｜\n｜\t\t\t ｜\t\t\t  ｜\t\t\t    ｜\n －－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－\n｜");
    pur;
    printf("7.洛基\t\t");
    wht;
    printf(" ｜");
    yew;
    printf("8.皮卡丘\t\t");
    wht;
    printf("  ｜");
    red;
    printf("9.孫悟空\t\t");
    wht;
    printf("    ｜\n｜");
    pur;
    printf("-雷神索爾的弟弟，變化 ");
    wht;
    printf(" ｜");
    yew;
    printf("-隱沒在草叢的電氣老鼠, ");
    wht;
    printf("｜");
    red;
    printf("-賽亞人的驕傲,總在世界危");
    wht;
    printf("｜\n｜");
    pur;
    printf(" 無窮，可化身成任何人");
    wht;
    printf("  ｜");
    yew;
    printf(" 兩頰的腮紅可產生高壓電");
    wht;
    printf("｜");
    red;
    printf(" 機時解救地球\t");
    wht;
    printf("    ｜\n｜");
    bgblue;
    printf("絕招:幻影");
    wht;
    printf("\t\t ｜");
    bgblue;
    printf("絕招:十萬伏特");
    wht;
    printf("\t  ｜");
    bgblue;
    printf("絕招:元氣彈");
    wht;
    printf("\t\t    ｜\n｜");
    bgblue;
    printf("可指定移動到某一格,範圍");
    wht;
    printf("｜");
    bgblue;
    printf("全場麻痺一回合");
    wht;
    printf("\t  ｜");
    bgblue;
    printf("可以轟掉一塊土地");
    wht;
    printf("\t    ｜\n｜");
    bgblue;
    printf("為自身位置前後三格");
    wht;
    printf("\t ｜\t\t\t  ｜\t\t\t    ｜\n｜");
    bgblue;
    printf("CD:4");
    wht;
    printf("\t\t\t ｜");
    bgblue;
    printf("CD:7");
    wht;
    printf("\t\t\t  ｜");
    bgblue;
    printf("CD:6");
    wht;
    printf("\t\t    ｜\n｜\t\t\t ｜\t\t\t  ｜\t\t\t    ｜\n －－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－");
}
void print_detail(int a)
{
    switch(a)
    {
    case 1:
        printf("宇智波佐助\n");
        printf("絕招：萬花筒寫輪眼(闖關時不耗損兵力，且可以招降10％敵方城內士兵)\n");
        printf("CD值：8\n");
        break;
    case 2:
        printf("馬英丸\n");
        printf("絕招：死亡之握(pk時發動，對手兵力減半)\n");
        printf("CD值：10\n");
        break;
    case 3:
        printf("來來哥\n");
        printf("絕招：哩尬挖來!(強制將在自己後面5格內的對手移動到自己的格位)\n");
        printf("CD值：8\n");
        break;
    case 4:
        printf("冰雪女王艾莎\n");
        printf("絕招：LET IT GO(可攻下一次別人的土地)\n");
        printf("CD值：10\n");
        break;
    case 5:
        printf("蟹老闆\n");
        printf("絕招：美味蟹堡(身上的現金乘以(1+0.1*骰子點數))\n");
        printf("CD值：9\n");
        break;
    case 6:
        printf("魯夫\n");
        printf("絕招：伸縮自如的橡膠手槍(若自己領地在前或後一格，可補充兵力)\n");
        printf("CD值：5\n");
        break;
    case 7:
        printf("洛基\n");
        printf("絕招：幻影(可指定移動到某一格，範圍為自身位置前後三格)\n");
        printf("CD值：4\n");
        break;
    case 8:
        printf("皮卡丘\n");
        printf("絕招：十萬伏特(全場麻痺一回合)\n");
        printf("CD值：7\n");
        break;
    case 9:
        printf("孫悟空\n");
        printf("絕招：元氣彈(可以轟掉一塊土地)\n");
        printf("CD值：6\n");
        break;
    }
}
void start()
{
    printf("                               \n");
    printf("                   歡迎來到亂鬥大富翁                    \n");
    printf("    \n");
    printf("    在這裡你需要                  --------------------        \n");
    printf("                                /                    / |      \n");
    printf("                              /     ability        /   |      \n");
    printf("                            /                    /     |      \n");
    printf("                          /       能力         /       |      \n");
    printf("                        /                    /         |      \n");
    printf("                        --------------------    force  |      \n");
    printf("                       |                    |          |      \n");
    printf("                       |                    |    暴力  |      \n");
    printf("                       |                    |          |      \n");
    printf("                       |       fortune      |          |      \n");
    printf("                       |                    |         /       \n");
    printf("                       |                    |       /         \n");
    printf("                       |        財力        |     /           \n");
    printf("                       |                    |   /             \n");
    printf("                       |                    | /               \n");
    printf("                        --------------------                  \n");
    printf("\n");
    printf("\n");
    printf("                                          吳宥萱、王博弘、范雲瀚聯合製作\n");
    printf("\n");
    system("pause");
    system("cls");
}
void rules()
{
    printf("###################遊戲規則###################\n\n");
    printf("1. 每個玩家的起始現金、兵力皆相同。\n\n");
    printf("2. 走到銀行可存款。\n\n");
    printf("3. 佔領空土地可用現金或兵力。\n\n");
    printf("4. 走到別人土地須付過路費，\n");
    printf("   或以兵力強行通過。\n\n");
    printf("5. 兩個玩家同時在同一土地會進行PK，\n");
    printf("   輸家會被搶劫現金。\n\n");
    printf("6. 走到自己領地可以提領兵力。\n\n");
    printf("7. 其餘規則如一般大富翁遊戲。\n");
    system("PAUSE");
    system("cls");
}
void world(int s)
{
    srand((unsigned) time(NULL));

    a=dice();
    printf("骰子點數:%d\n",a);
    Sleep(slp2);
    do
    {
        Sleep(slp0);
        system("cls");
        world_print();
        print_situation();
        move_player(s);
        land_set();
        a--;
    }
    while(a>0);

    gotoxy(0,21);
}
int dice()
{
    a=rand()%6+1;
    return a;
}
void move_player(int s)
{
    player_situation[1][s]++;//站位+1
    if(player_situation[1][s]>16)//如果站位超過16回到一重新計算
    {
        player_situation[1][s]=1;
    }
    player_xy_switch(player_situation[1][0]);//當時的角色
    player_print(1);
    player_xy_switch(player_situation[1][1]);//別的角色
    player_print(2);
    player_xy_switch(player_situation[1][2]);//別的角色
    player_print(3);
    player_xy_switch(player_situation[1][3]);//別的角色
    player_print(4);
}
void player_xy_switch(int s)//坐標轉換，這個方法的核心
{
     if(s==-102)
        gotoxy(40,0);
    else if(s==-103)
        gotoxy(45,0);
    else if(s==-104)
        gotoxy(50,0);
    else if(s<=5)
        gotoxy(s*4,2);
    else if(s>5&&s<=9)
        gotoxy(20,(s-4)*2);
    else if(s>9&&s<=13)
        gotoxy(20-(s-9)*4,10);
    else if(s>13&&s<=16)
        gotoxy(4,10-(s-13)*2);
}
void player_set()
{
    player_situation[1][0]=1;
    player_situation[1][1]=5;
    player_situation[1][2]=9;
    player_situation[1][3]=13;
    player_xy_switch(player_situation[1][0]);
    player_print(1);
    player_xy_switch(player_situation[1][1]);
    player_print(2);
    player_xy_switch(player_situation[1][2]);
    player_print(3);
    player_xy_switch(player_situation[1][3]);
    player_print(4);
    gotoxy(0,21);
}
void player_now_print()
{
    player_xy_switch(player_situation[1][0]);
    player_print(1);
    player_xy_switch(player_situation[1][1]);
    player_print(2);
    player_xy_switch(player_situation[1][2]);
    player_print(3);
    player_xy_switch(player_situation[1][3]);
    player_print(4);
    gotoxy(0,21);
}
void player_print(int p)
{
    switch(p)
    {
    case 1:
        red;
        printf("●");
        wht;
        break;
    case 2:
        grn;
        printf("●");
        wht;
        break;
    case 3:
        pur;
        printf("●");
        wht;
        break;
    case 4:
        yew;
        printf("●");
        wht;
        break;
    }
}
void land_set()
{
    for(i=0; i<=15; i++)
    {
        land_xy_switch(land_situationl[0][i]);
    }
    gotoxy(0,21);
}
void land_xy_switch(int ls)
{
    if(ls==1)
    {
        gotoxy(4,0);
        if(land_situationl[1][0]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][0]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][0]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][0]==104)
        {
            yew;
            printf("●");
            wht;
        }
        else printf("○");
    }
    else if(ls==2)
    {
        gotoxy(8,0);
        if(land_situationl[1][1]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][1]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][1]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][1]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==3)
    {
        gotoxy(12,0);
        if(land_situationl[1][2]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][2]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][2]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][2]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==4)
    {
        gotoxy(16,0);
        if(land_situationl[1][3]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][3]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][3]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][3]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==5)
    {
        gotoxy(24,2);
        if(land_situationl[1][4]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][4]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][4]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][4]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==6)
    {
        gotoxy(24,4);
        if(land_situationl[1][5]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][5]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][5]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][5]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==7)
    {
        gotoxy(24,6);
        if(land_situationl[1][6]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][6]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][6]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][6]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==8)
    {
        gotoxy(24,8);
        if(land_situationl[1][7]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][7]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][7]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][7]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==9)
    {
        gotoxy(20,12);
        if(land_situationl[1][8]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][8]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][8]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][8]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==10)
    {
        gotoxy(16,12);
        if(land_situationl[1][9]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][9]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][9]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][9]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==11)
    {
        gotoxy(12,12);
        if(land_situationl[1][10]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][10]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][10]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][10]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==12)
    {
        gotoxy(8,12);
        if(land_situationl[1][11]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][11]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][11]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][11]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==13)
    {
        gotoxy(0,10);
        if(land_situationl[1][12]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][12]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][12]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][12]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==14)
    {
        gotoxy(0,8);
        if(land_situationl[1][13]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][13]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][13]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][13]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==15)
    {
        gotoxy(0,6);
        if(land_situationl[1][14]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][14]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][14]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][14]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
    else if(ls==16)
    {
        gotoxy(0,4);
        if(land_situationl[1][15]==101)
        {
            red;
            printf("●");
            wht;
        }
        else if(land_situationl[1][15]==102)
        {
            grn;
            printf("●");
            wht;
        }
        else if(land_situationl[1][15]==103)
        {
            pur;
            printf("●");
            wht;
        }
        else if(land_situationl[1][15]==104)
        {
            yew;
            printf("●");
            wht;
        }
    }
}
void world_set()
{
    for(i=1; i<4; i++) //part1
    {
        for(j=1; j<n-4; j++)
        {
            world1[i][j]=1;//將選取範圍數值變為1
        }

    }
    for(j=1; j<n-3; j++)
    {
        if(j%2==0)//偶數格裡面挖空變成0  外面加上2
        {
            world1[0][j]=2;
            world1[2][j]=0;
        }
    }
    for(i=n-4; i<n-1; i++) //part2
    {
        for(j=4; j<n-1; j++)
        {
            world1[i][j]=1;
        }

    }
    for(j=4; j<n-1; j++)
    {
        if(j%2==0)
        {
            world1[n-1][j]=2;
            world1[n-3][j]=0;
        }
    }
    for(j=1; j<4; j++) //part3
    {
        for(i=4; i<n-1; i++)
        {
            world1[i][j]=1;
        }

    }
    for(i=4; i<n-1; i++)
    {
        if(i%2==0)
        {
            world1[i][0]=2;
            world1[i][2]=0;
        }
    }
    for(j=n-4; j<n-1; j++) //part4
    {
        for(i=1; i<n-4; i++)
        {
            world1[i][j]=1;
        }

    }
    for(i=1; i<n-4; i++)
    {
        if(i%2==0)
        {
            world1[i][n-1]=2;
            world1[i][n-3]=0;
        }
    }
    world1[0][6]=-1000;
    world1[6][12]=-1001;
    world1[6][0]=-1001;
}
void world_print()
{

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            x=world1[i-1][j];//定位上下左右
            y=world1[i+1][j];
            z=world1[i][j-1];
            w=world1[i][j+1];
            if(world1[i][j]==0)//坐標為0印出空格
            {
                printf("  ");
            }
            else if(world1[i][j]==1)//坐標為一判斷上下左右
            {
                if(x==1&&y==1&&z==1&&w==1)
                {
                    printf("┼");
                }
                else if(x!=1&&y!=1&&z==1&&w==1)
                {
                    printf("─");
                }
                else if(x==1&&y==1&&z!=1&&w!=1)
                {
                    printf("│");
                }
                else if(x!=1&&y==1&&z==1&&w==1)
                {
                    printf("┬");
                }
                else if(x==1&&y!=1&&z==1&&w==1)
                {
                    printf("┴");
                }
                else if(x==1&&y==1&&z!=1&&w==1)
                {
                    printf("├");
                }
                else if(x==1&&y==1&&z==1&&w!=1)
                {
                    printf("┤");
                }
                else if(x==1&&y==1&&z!=1&&w!=1)
                {
                    printf("│");
                }
                else if(x==1&&y!=1&&z==1&&w!=1)
                {
                    printf("┘");
                }
                else if(x==1&&y!=1&&z!=1&&w==1)
                {
                    printf("└");
                }
                else if(x!=1&&y==1&&z==1&&w!=1)
                {
                    printf("┐");
                }
                else
                {
                    printf("┌");
                }
            }
            else if(world1[i][j]==-1000)
            {
                yew;
                printf(" $");
                wht;
            }
            else if(world1[i][j]==-1001)
            {
                red;
                printf("？");
                wht;
            }
            else//不是零或是一即為土地
            {
                printf("○");
            }
        }
        printf("\n");
    }
}
void print_situation()
{

    printf("-------------------------------------------------------------------------------\n");
    red;
    printf("玩家1 ");
    player_rule(player[0]);
    wht;
    printf("|");
    grn;
    printf("玩家2 ");
    player_rule(player[1]);
    wht;
    printf("|");
    pur;
    printf("玩家3 ");
    player_rule(player[2]);
    wht;
    printf("|");
    yew;
    printf("玩家4 ");
    player_rule(player[3]);
    wht;
    printf("                    |                   |                   |                   \n");
    printf("    現金:%5d     |    現金:%5d     |    現金:%5d     |    現金:%5d\n",player_situation[2][0],player_situation[2][1],player_situation[2][2],player_situation[2][3]);
    printf("    存款:%5d     |    存款:%5d     |    存款:%5d     |    存款:%5d\n",player_situation[3][0],player_situation[3][1],player_situation[3][2],player_situation[3][3]);
    printf("    兵力:%5d     |    兵力:%5d     |    兵力:%5d     |    兵力:%5d\n",player_situation[4][0],player_situation[4][1],player_situation[4][2],player_situation[4][3]);
    printf("      CD:%5d     |      CD:%5d     |      CD:%5d     |      CD:%5d\n",player_situation[5][0],player_situation[5][1],player_situation[5][2],player_situation[5][3]);
}
void player_rule(int pr)
{
    switch(pr)
    {
    case 1:
        printf("宇智波佐助   ");
        break;
    case 2:
        printf("馬英丸       ");
        break;
    case 3:
        printf("來來哥       ");
        break;
    case 4:
        printf("冰雪女王艾莎 ");
        break;
    case 5:
        printf("蟹老闆       ");
        break;
    case 6:
        printf("魯夫         ");
        break;
    case 7:
        printf("洛基         ");
        break;
    case 8:
        printf("皮卡丘       ");
        break;
    case 9:
        printf("孫悟空       ");
        break;
    }
}
void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X=xpos;
    scrn.Y=ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}
int money_change(int h)
{
    int world_price;
    switch(h)
    {
    case 1: //占領花費
        srand((unsigned)time(NULL));
        world_price=rand()%201+300;
        break;
    }
    return world_price;
}
void chance_or_destiny(int cod,int man)
{
    if(cod>=1 && cod<=5)
    {
        printf("恭喜您中了樂透大獎!\n");
        int lottery=rand()%10+1;
        if(lottery>=1 && lottery<=4)
        {
            printf("獎金為現金100元\n");
            player_situation[2][man]+=100;
        }
        else if(lottery>=5 && lottery<=7)
        {
            printf("獎金為現金500元\n");
            player_situation[2][man]+=500;
        }
        else if(lottery>=8 && lottery<=9)
        {
            printf("獎金為現金1000元\n");
            player_situation[2][man]+=1000;
        }
        else if(lottery==10)
        {
            printf("獎金為現金5000元\n");
            player_situation[2][man]+=5000;
        }
    }

    else if(cod>=6 && cod<=20)
    {
        printf("組織扁平化，裁員&財源A___A(兵力減少2成，金錢增加5趴)\n");
        player_situation[4][man]*=0.8;
        player_situation[2][man]*=1.05;

    }
    else if(cod>=21&&cod<=25)
    {
        printf("金融風暴，雷曼兄弟倒閉，銀行大受影響(所有人存款減半)\n");
        for(i=0; i<4; i++)
        {
            player_situation[3][i]=player_situation[3][i]/2;
        }
    }
    else if(cod>=26&&cod<=40)
    {
        printf("你累了嗎?讓曼秀雷敦小護士來消除您的疲勞!(兵力增加)\n");
        int med=rand()%10+1;
        if(med>=1 && med<=4)
        {
            printf("兵力增加100\n");
            player_situation[4][man]+=100;
        }
        else if(med>=5 && med<=7)
        {
            printf("兵力增加500\n");
            player_situation[4][man]+=500;
        }
        else if(med>=8 && med<=9)
        {
            printf("兵力增加1000\n");
            player_situation[4][man]+=1000;
        }
        else if(med==10)
        {
            printf("兵力增加5000\n");
            player_situation[4][man]+=5000;
        }
    }

    else if(cod>=41&&cod<=45)
    {
        printf("次級房貸，房價大跌(所有土地過路費減半)\n");
        for(i=0; i<16; i++)
        {
            land_situationl[2][i]=land_situationl[2][i]/2;
        }
    }
    else if(cod>=46 && cod<=50)
    {
        printf("屏氣凝神，氣灌丹田，這招叫做，我開大絕(絕招CD歸0，可使用絕招了!)\n");
        player_situation[5][man]=0;
    }
    else if(cod>=51 && cod<=60)
    {
        printf("賭性堅強，恭喜您獲得十八拉機會一次!(可再擲一次骰子)\n");
        world(man);
    }

    else if(cod>=61&&cod<=65)
    {
        printf("微服出巡，總統近距離與民眾接觸，大家跟總統握個手(全部人兵力減半)\n");
        for(i=0; i<4; i++)
        {
            player_situation[4][i]=player_situation[4][i]/2;
        }
    }
}
void attack_land(int al,int alp)//攻城
{
    int force_prob=(player_situation[4][al]-land_situationl[3][player_situation[1][al]-1])/200+50;//這為成功機率，如果相等的話機率是50%，差距每隔200加1%
    int force_decrease = (rand()%5+4)*land_situationl[3][player_situation[1][al]-1]/10;//隨機耗損30%~70%的城內兵力

    if(force_prob>rand()%100+1)
    {
        printf("攻佔囉~\n");
        if(player_situation[4][al]<force_decrease)
        {
            player_situation[4][al]=0;
        }
        else
        {
            player_situation[4][al]-=force_decrease;
        }
        land_situationl[3][player_situation[1][al]-1]=500;//攻占完後起始兵力為500
        land_situationl[1][player_situation[1][al]-1]=alp;
    }
    else
    {
        printf("攻占失敗，請上繳過路費\n");
        if(player_situation[4][al]<force_decrease)
        {
            player_situation[4][al]=0;
        }
        else
        {
            player_situation[4][al]-=force_decrease;
        }
        if(land_situationl[1][player_situation[1][al]-1] == 101 || land_situationl[1][player_situation[1][al]-1] == 102 || land_situationl[1][player_situation[1][al]-1] == 103 || land_situationl[1][player_situation[1][al]-1] == 104)//有人的土地
        {
            if(land_situationl[2][player_situation[1][al]-1]>player_situation[2][al]) //手上現金不足，從銀行扣
            {
                int gap1=land_situationl[2][player_situation[1][al]-1]-player_situation[2][al];
                player_situation[2][al]=0;
                player_situation[3][al]-=gap1;
                player_situation[3][land_situationl[1][player_situation[1][al]-1]-101]+=land_situationl[2][player_situation[1][al]-1];//錢過戶給地主存款
            }
            else //從手中現金扣款
            {
                player_situation[2][al]-=land_situationl[2][player_situation[1][al]-1];
                player_situation[3][land_situationl[1][player_situation[1][al]-1]-101]+=land_situationl[2][player_situation[1][al]-1];//錢過戶給地主存款
            }
        }
        else if(land_situationl[1][player_situation[1][al]-1] == 0) //空土地
        {
            if(land_situationl[2][player_situation[1][al]-1]>player_situation[2][al]) //手上現金不足，從銀行扣
            {
                int gap2=land_situationl[2][player_situation[1][al]-1]-player_situation[2][al];
                player_situation[2][al]=0;
                player_situation[3][al]-=gap2;
            }
            else //從手中現金扣款
            {
                player_situation[2][al]-=land_situationl[2][player_situation[1][al]-1];//錢過戶給地主存款
            }
        }
        Sleep(slp2);
    }
}
void attack_door(int ad)//闖關
{
    int force_prob=(player_situation[4][ad]-land_situationl[3][player_situation[1][ad]-1])/600+50;// 1/3的城內兵力
    int force_decrease = (rand()%5+4)*land_situationl[3][player_situation[1][ad]-1]/30;// 耗損也變為1/3
    if(force_prob>rand()%100+1)
    {
        printf("闖關達成，免收過路費\n");
        if(player_situation[4][ad]<force_decrease)
        {
            player_situation[4][ad]=0;
        }
        else
        {
            player_situation[4][ad]-=force_decrease;
        }
    }
    else
    {
        printf("闖關失敗，加收過路費\n");
        if(player_situation[4][ad]<force_decrease)
        {
            player_situation[4][ad]=0;
        }
        else
        {
            player_situation[4][ad]-=force_decrease;
        }
        if(land_situationl[2][player_situation[1][ad]-1]+300>player_situation[2][ad])
        {
            int gap3=land_situationl[2][player_situation[1][ad]-1]-player_situation[2][ad]+300;//闖關失敗加收300元
            player_situation[2][ad]=0;
            player_situation[3][ad]-=gap3;
            player_situation[3][land_situationl[1][player_situation[1][ad]-1]-101]+=(land_situationl[2][player_situation[1][ad]-1]+300);//錢過戶給地主存款
        }
        else
        {
            player_situation[2][ad]-=(land_situationl[2][player_situation[1][ad]-1]+300);//闖關失敗加收300元
            player_situation[3][land_situationl[1][player_situation[1][ad]-1]-101]+=(land_situationl[2][player_situation[1][ad]-1]+300);//錢過戶給地主存款
        }
    }
    Sleep(slp2);
}
void pk(pk1,pk2)
{
    if((player_situation[4][pk2]*0.15)>player_situation[4][pk1]) //player[pk]損失大於自身兵力，則損失變為自身兵力
    {
        army_lose1=player_situation[4][pk1];
    }
    else if((player_situation[4][pk2]*0.15)<=player_situation[4][pk1])//player[pk]損失小於等於自身兵力，則損失正常
    {
        army_lose1=(player_situation[4][pk2]*0.15);
    }
    if((player_situation[4][pk1]*0.15)>player_situation[4][pk2]) //player[pk]損失大於自身兵力，則損失變為自身兵力
    {
        army_lose2=player_situation[4][pk2];
    }
    else if((player_situation[4][pk1]*0.15)<=player_situation[4][pk2])//player[pk]損失小於等於自身兵力，則損失正常
    {
        army_lose2=(player_situation[4][pk1]*0.15);
    }
    player_situation[4][pk1]-=army_lose1;
    player_situation[4][pk2]-=army_lose2;
}
void superpower(int people,int people2, int ch_i)
{
    int force_quanity,Loki,you_come,you_come_count,distance,super_dice,army_6;
    switch(ch_i)
    {
    case 1: //宇智波佐助絕招
        printf("玩家%d發動絕招\n",people+1);
        Sleep(slp3);
        printf("萬花筒寫輪眼!順利闖關並招降城內士兵1成\n");
        Sleep(slp4);
        force_quanity=(land_situationl[3][player_situation[1][people]-1]*0.1);//
        land_situationl[3][player_situation[1][people]-1]-=force_quanity;
        player_situation[4][people]+=force_quanity;
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        Sleep(slp2);
        player_situation[5][people]=CD[player[people]];
        break;
    case 2:
        Sleep(slp3);
        printf("馬英丸使用死亡之握，對手兵力減半...\n");
        player_situation[4][people2]/=2;
        Sleep(slp4);
        gotoxy(0,21);
        player_situation[5][people]=CD[player[people]];
        break;
    case 3:
        if(people==0)//玩家是來來哥
        {you_come_count=0;
f11:
        if(you_come_count<=3)
        {
            printf("要將哪個玩家拉過來?(自己前面五格內的玩家):");
            scanf("%d", &you_come);
            if(you_come<=0 || you_come>4)
            {
                printf("請輸入玩家2~4\n");
                goto f11;
            }
            else
            {
                distance = player_situation[1][people]-player_situation[1][(you_come)-1];
                if((distance<=-1 && distance>=-5) || (distance>=11 && distance <=15))
                {
                    red;
                    printf("哩");
                    Sleep(slp1);
                    printf("嘎");
                    Sleep(slp1);
                    printf("挖");
                    Sleep(slp1);
                    printf("來\n");
                    Sleep(slp1);
                    wht;
                    player_situation[1][(you_come)-1]=player_situation[1][people];
                    system("cls");
                    world_print();
                    print_situation();
                    player_now_print();
                    land_set();
                    Sleep(slp1);
                    printf("玩家%d被你吸引過來，準備pk!",you_come);
                    Sleep(slp4);
                    system("cls");
                pk_view();
                pk(0,(you_come-1));
                printf("您損失%d兵力，",army_lose1);
                if(you_come==2)
                {
                    grn;
                    printf("玩家2");
                }
                else if(you_come==3)
                {
                    pur;
                    printf("玩家3");
                }
                else if(you_come==4)
                {
                    yew;
                    printf("玩家4");
                }
                wht;
                printf("損失%d兵力\n",army_lose2);
                Sleep(slp2);
                money_lose=rand()%501+500;
                if(army_lose1>army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("您損失較慘重，被玩家%d劫走%d元\n",you_come,player_situation[2][0]);
                        player_situation[2][0]=0;
                        player_situation[2][(you_come)-1]+=player_situation[2][0];
                    }
                    else
                    {
                        printf("您損失較慘重，被玩家%d劫走%d元\n",you_come,money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][(you_come)-1]+=money_lose;
                    }
                }
                else if(army_lose1<army_lose2)
                {
                    if(player_situation[2][(you_come)-1]<money_lose)
                    {
                        printf("玩家%d損失較慘重，您火上加油打劫走%d元\n",you_come,player_situation[2][(you_come)-1]);
                        player_situation[2][(you_come)-1]=0;
                        player_situation[2][0]+=player_situation[2][(you_come)-1];
                    }
                    else
                    {
                        printf("玩家%d損失較慘重，您火上加油打劫走%d元\n",you_come,money_lose);
                        player_situation[2][(you_come)-1]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }
                }
                else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
                Sleep(slp4);
                gotoxy(0,13);
                print_situation();
                Sleep(slp3);
                }
                else
                {
                    printf("您指定的玩家不在五格範圍內喔!\n");
                    you_come_count++;
                    goto f11;
                }
            }
        }
        else
        {
            printf("來來哥輸入錯誤3次了，聲嘶力竭...!\n");
            Sleep(slp3);
        }
        }
        else //電腦是來來哥 ，判斷在player各自的function時
        {
            printf("玩家%d發動絕招\n",people+1);
            Sleep(slp3);
            player_situation[1][people2]=player_situation[1][people];
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
            Sleep(slp1);
            printf("玩家%d被玩家%d吸引到自己位置進入pk!\n",people2+1,people+1);
            Sleep(slp4);
            system("cls");
            pk_view();
            pk(people,people2);
            printf("玩家%d損失%d兵力，",people+1,army_lose1);
            printf("玩家%d損失%d兵力\n",people2+1,army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1>army_lose2)
            {

                if(player_situation[2][people]<money_lose)
                {
                    printf("玩家%d損失較慘重，被玩家%劫走%d元\n",people,people2, player_situation[2][people]);
                    player_situation[2][people2]+=player_situation[2][people];
                    player_situation[2][people]=0;
                }
                else
                {
                    printf("玩家%d損失較慘重，被玩家%劫走%d元\n",people,people2,money_lose);
                    player_situation[2][people]-=money_lose;
                    player_situation[2][people2]+=money_lose;
                }
            }
            else if(army_lose1<army_lose2)
            {

                if(player_situation[2][people2]<money_lose)
                {
                    printf("玩家%d損失較慘重，被玩家%d劫走%d元\n",people2,people,player_situation[2][people2]);
                    player_situation[2][people]+=player_situation[2][people2];
                    player_situation[2][people2]=0;
                }
                else
                {
                    printf("玩家%d損失較慘重，被玩家%d劫走%d元\n",people2,people,money_lose);
                    player_situation[2][people2]-=money_lose;
                    player_situation[2][people]+=money_lose;
                }
            }
            else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        Sleep(slp2);
        player_situation[5][people]=CD[player[people]];
        break;
    case 4: //判斷在main
        printf("\n玩家%d發動絕招\n",people+1);
        Sleep(slp3);
        printf("艾莎獨倚欄杆，高唱let it go~~");
        Sleep(slp2);
        printf("let it go，讓土地歸玩家%d所有\n",people+1);
        switch(people)
        {
        case 0:
            land_situationl[1][(player_situation[1][people])-1]=101;
            break;
        case 1:
            land_situationl[1][(player_situation[1][people])-1]=102;
            break;
        case 2:
            land_situationl[1][(player_situation[1][people])-1]=103;
            break;
        case 3:
            land_situationl[1][(player_situation[1][people])-1]=104;
            break;
        }
        Sleep(slp4);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        Sleep(slp2);
        player_situation[5][people]=CD[player[people]];
        break;
    case 5:
        printf("玩家%d發動絕招\n",people+1);
        Sleep(slp3);
        gotoxy(0,21);
        printf("蟹老闆對金錢的執著超乎想像...\n使用美味蟹堡，丟一次骰子並將身上現金乘上(1+0.1*骰子點數)!\n");
        super_dice=dice();
        Sleep(slp3);
        printf("骰子點數:%d\n",super_dice);
        Sleep(slp3);
        player_situation[2][people]*=(1+(0.1*super_dice));
        printf("玩家%d金錢變成%d",people+1,player_situation[2][people]);
        Sleep(slp3);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        Sleep(slp2);
        player_situation[5][people]=CD[player[people]];
        break;
    case 6: //判斷前方後方是否為自己城池是在main
        if(people==0)//玩家
        {
f12:
            printf("要抓前面還是後面城池的兵?  1.前面 2.後面: ");
            scanf("%d",&army_6);
            if(army_6!=1 && army_6!=2)
            {
                printf("請輸入1.前面 或是 2.後面\n");
                goto f12;
            }
            else if(army_6==1)
            {
                if(player_situation[1][people]==16 && land_situationl[1][0]==101)
                {
                    printf("城內士兵目前有%d，要抓多少? :",land_situationl[3][0]);
                    scanf("%d",&force_quanity);
                    if(force_quanity>land_situationl[3][0] || force_quanity<=0)
                    {
                        printf("輸入數字錯誤!\n");
                        goto f12;
                    }
                    else
                    {
                        printf("魯夫伸長雙手，把自己領地的兵抓過來補充了!\n");
                        player_situation[4][people]+=force_quanity;
                        land_situationl[3][0]-=force_quanity;
                    }
                }
                else if(land_situationl[1][player_situation[1][people]]==101)
                {
                    printf("城內士兵目前有%d，要抓多少? :",land_situationl[3][player_situation[1][people]]);
                    scanf("%d",&force_quanity);
                    if(force_quanity>land_situationl[3][player_situation[1][people]] || force_quanity<=0)
                    {
                        printf("輸入數字錯誤!\n");
                        goto f12;
                    }
                    else
                    {
                        printf("魯夫伸長雙手，把自己領地的兵抓過來補充了!\n");
                        player_situation[4][people]+=force_quanity;
                        land_situationl[3][player_situation[1][people]]-=force_quanity;
                    }
                }
            else
            {
                printf("前面的土地不是您的!\n");
                goto f12;
            }
            }
            else if(army_6==2)
            {
                if(player_situation[1][people]==1 && land_situationl[1][15]==101)
                {
                    printf("城內士兵目前有%d，要抓多少? :",land_situationl[3][15]);
                    scanf("%d",&force_quanity);
                    if(force_quanity>land_situationl[3][15] || force_quanity<=0)
                    {
                        printf("輸入數字錯誤!\n");
                        goto f12;
                    }
                    else
                    {
                        printf("魯夫伸長雙手，把自己領地的兵抓過來補充了!\n");
                        player_situation[4][people]+=force_quanity;
                        land_situationl[3][15]-=force_quanity;
                    }
                }
                else if(land_situationl[1][player_situation[1][people]-2]==101)
                {
                    printf("城內士兵目前有%d，要抓多少? :",land_situationl[3][player_situation[1][people]-2]);
                    scanf("%d",&force_quanity);
                    if(force_quanity>land_situationl[3][player_situation[1][people]-2] || force_quanity<=0)
                    {
                        printf("輸入數字錯誤!\n");
                        goto f12;
                    }
                    else
                    {
                        printf("魯夫伸長雙手，把自己領地的兵抓過來補充了!\n");
                        player_situation[4][people]+=force_quanity;
                        land_situationl[3][player_situation[1][people]-2]-=force_quanity;
                    }
                }
                else
                {
                    printf("後面的土地不是您的!\n");
                    goto f12;
                }
            }
        }
        else //電腦
        {
            if(player_situation[1][people]==16)//電腦站16
            {
                army_6=rand()%1+1;
                if(army_6==1 && (land_situationl[1][0]-101)==people)
                    {
                        printf("魯夫伸長雙手，把自己領地的兵抓過來補充了!\n");
                        force_quanity=land_situationl[3][0]*0.5;
                        player_situation[4][people]+=force_quanity;
                        land_situationl[3][0]-=force_quanity;
                    }
                else if((land_situationl[1][player_situation[1][people]]-101)==people)
                {
                     force_quanity=land_situationl[3][player_situation[1][people]]*0.5;
                     printf("魯夫伸長雙手，把自己領地的兵抓過來補充了!\n");
                     player_situation[4][people]+=force_quanity;
                     land_situationl[3][player_situation[1][people]]-=force_quanity;
                }
            }
            else if(player_situation[1][people]==1)//電腦站1
            {
                army_6=rand()%1+1;
                if(army_6==2 && (land_situationl[1][15]-101)==people)
                 {
                        force_quanity=land_situationl[3][15]*0.5;
                        printf("魯夫伸長雙手，把自己領地的兵抓過來補充了!\n");
                        player_situation[4][people]+=force_quanity;
                        land_situationl[3][15]-=force_quanity;
                }
                else if((land_situationl[1][player_situation[1][people]-2]-101)==people)
                {
                    force_quanity=land_situationl[3][player_situation[1][people]-2]*0.5;
                     printf("魯夫伸長雙手，把自己領地的兵抓過來補充了!\n");
                     player_situation[4][people]+=force_quanity;
                     land_situationl[3][player_situation[1][people]-2]-=force_quanity;
                }
            }
            else
            {
                army_6=rand()%1+1;
                if(army_6==1 && (land_situationl[1][player_situation[1][people]]-101)==people)
                {
                    force_quanity=land_situationl[3][player_situation[1][people]]*0.5;
                     printf("魯夫伸長雙手，把自己領地的兵抓過來補充了!\n");
                     player_situation[4][people]+=force_quanity;
                     land_situationl[3][player_situation[1][people]]-=force_quanity;
                }
                else if((land_situationl[1][player_situation[1][people]-2]-101)==people)
                {
                    force_quanity=land_situationl[3][player_situation[1][people]-2]*0.5;
                     printf("魯夫伸長雙手，把自己領地的兵抓過來補充了!\n");
                     player_situation[4][people]+=force_quanity;
                     land_situationl[3][player_situation[1][people]-2]-=force_quanity;
                }
            }
        }
        Sleep(slp4);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        Sleep(slp2);
        player_situation[5][people]=CD[player[people]];
        break;
    case 7:
f13:
        if(people==0)//玩家
        {
            printf("請輸入想移動的距離(-3~+3):");
            scanf("%d",&Loki);
            if(Loki>3 || Loki<-3)
            {
                printf("輸入錯誤!\n");
                goto f13;
            }
            else
            {
                player_situation[1][people]+=Loki;
                if(player_situation[1][people]>16)
                {
                    player_situation[1][people]-=16;
                }
                else if(player_situation[1][people]<0)
                {
                    player_situation[1][people]+=16;
                }
            }
        }
        else//電腦
        {
            Loki=rand()%7-3;
            player_situation[1][people]+=Loki;
            if(player_situation[1][people]>16)
            {
                player_situation[1][people]-=16;
            }
            else if(player_situation[1][people]<0)
            {
                player_situation[1][people]+=16;
            }
        }
         printf("\n玩家%d發動絕招\n",people+1);
        Sleep(slp3);
       printf("洛基將自己融入景色當中，並且出現在另一個區域");
       Sleep(slp3);
       system("cls");
       world_print();
        print_situation();
        player_now_print();
        land_set();
        Sleep(slp2);
        printf("洛基移動%d格\n",Loki);
        Sleep(slp4);
        system("cls");
       world_print();
        print_situation();
        player_now_print();
        land_set();
        player_situation[5][people]=CD[player[people]];
        break;
    case 8:
        printf("\n玩家%d發動絕招\n",people+1);
        Sleep(slp3);
        printf("皮~");
        Sleep(slp1);
        printf("卡~");
        Sleep(slp1);
        printf("啾~~~~~~~~~~~~~~~~\n");
        Sleep(slp1);
        printf("其他玩家受到強烈的電擊而無法動彈，麻痺一回合\n");
        lightning=4;
        Sleep(slp4);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        Sleep(slp2);
        player_situation[5][people]=CD[player[people]];
        break;
    case 9:
        printf("玩家%d發動絕招\n",people+1);
        Sleep(slp3);
        printf("匯集了全身的力量，悟空朝他的所在地使出元氣彈，將該地區夷為平地");
        land_situationl[1][player_situation[1][people]-1]=0;
        Sleep(slp4);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        printf("土地已經變成空地\n");
        Sleep(slp3);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        player_situation[5][people]=CD[player[people]];
        break;
    }
}
void you_win1()
{
    red;
    printf("                          __________                     \n");
    printf("    \\           /        |          |     |        |    ");
    yew;
    printf("○    ○    ○\n");
    red;
    printf("      \\       /          |          |     |        |    ");
    yew;
    printf("|\\    /\\    /|\n");
    wht;
    printf("        \\   /            |          |     |        |    ");
    yew;
    printf("|  \\/    \\/  |\n");
    wht;
    printf("          |              |          |     |        |    ");
    yew;
    printf("|____________|\n");
    red;
    printf("          |              |          |     |        |    \n");
    printf("          |              |__________|     |________|    \n");
    wht;
    printf("                         ____________                       \n");
    printf("\\                  /          |        |\\          |   !!!\n");
    printf(" \\                /           |        |  \\        |   !!!\n");
    red;
    printf("  \\      /\\      /            |        |    \\      |   !!!\n");
    printf("   \\    /  \\    /             |        |      \\    |   !!!\n");
    wht;
    printf("    \\  /    \\  /              |        |        \\  |      \n");
    printf("     \\/      \\/         ______|______  |          \\|   !!!\n");
    printf("\n");
    pur;
    printf("                                                     $$  \n");
    grn;
    printf("Congraduation for becoming a MONOPOLY!!!              ");
    pur;
    printf("$$$\n");
    wht;
    printf("Congraduation for becoming a MONOPOLY!!!          ");
    pur;
    printf("$$$$$$$\n");
    grn;
    printf("Congraduation for becoming a MONOPOLY!!!          ");
    pur;
    printf("$$$$$$$\n");
    wht;
    printf("Congraduation for becoming a MONOPOLY!!!          ");
    pur;
    printf("$$$$$$$\n");
    grn;
    printf("Congraduation for becoming a MONOPOLY!!!          ");
    pur;
    printf("$$$$$$$\n");
    yew;
    int i;
    for(i=0; i<=39; i++)
    {
        yew;
        printf("%c ",(char)2);
        red;
        printf("%c ",(char)2);
    }


}
void you_win2()
{
    bgblue;
    printf("                          __________                     \n");
    printf("    \\           /        |          |     |        |    ");
    yew;
    printf("○    ○    ○\n");
    bgblue;
    printf("      \\       /          |          |     |        |    ");
    yew;
    printf("|\\    /\\    /|\n");
    red;
    printf("        \\   /            |          |     |        |    ");
    yew;
    printf("|  \\/    \\/  |\n");
    red;
    printf("          |              |          |     |        |    ");
    yew;
    printf("|____________|\n");
    bgblue;
    printf("          |              |          |     |        |    \n");
    printf("          |              |__________|     |________|    \n");
    red;
    printf("                         ____________                       \n");
    printf("\\                  /          |        |\\          |   !!!\n");
    printf(" \\                /           |        |  \\        |   !!!\n");
    bgblue;
    printf("  \\      /\\      /            |        |    \\      |   !!!\n");
    printf("   \\    /  \\    /             |        |      \\    |   !!!\n");
    red;
    printf("    \\  /    \\  /              |        |        \\  |      \n");
    printf("     \\/      \\/         ______|______  |          \\|   !!!\n");
    printf("\n");
    pur;
    printf("                                                     $$  \n");
    grn;
    printf("Congraduation for becoming a MONOPOLY!!!              ");
    pur;
    printf("$$$\n");
    wht;
    printf("Congraduation for becoming a MONOPOLY!!!          ");
    pur;
    printf("$$$$$$$\n");
    grn;
    printf("Congraduation for becoming a MONOPOLY!!!          ");
    pur;
    printf("$$$$$$$\n");
    wht;
    printf("Congraduation for becoming a MONOPOLY!!!          ");
    pur;
    printf("$$$$$$$\n");
    grn;
    printf("Congraduation for becoming a MONOPOLY!!!          ");
    pur;
    printf("$$$$$$$\n");
    int i;
    for(i=0; i<=39; i++)
    {
        red;
        printf("%c ",(char)2);
        yew;
        printf("%c ",(char)2);
    }


}
void you_lose1()
{
    grn;
    printf("                          __________                     \n");
    printf("    \\           /        |          |     |        |    \n");
    printf("      \\       /          |          |     |        |    \n");
    wht;
    printf("        \\   /            |          |     |        |    \n");
    printf("          |              |          |     |        |     \n");
    grn;
    printf("          |              |          |     |        |    \n");
    printf("          |              |__________|     |________|    \n");
    wht;
    printf("                      __________      __________       __________\n");
    printf("    |                |          |     |               |          \n");
    printf("    |                |          |     |               |          \n");
    grn;
    printf("    |                |          |     |_________      |          \n");
    printf("    |                |          |               |     |----------\n");
    wht;
    printf("    |                |          |               |     |          \n");
    printf("    |                |          |               |     |          \n");
    grn;
    printf("    |___________     |__________|     __________|     |__________\n");
    printf("\n\n");
    bgblue;
    printf("You are BANKRUPT!!!\n");
    printf("You are BANKRUPT!!!\n");
    printf("You are BANKRUPT!!!\n");
    wht;
    printf("                           ______________ \n");
    printf("                          |              |\n");
    printf("                          |   ●    ●   |\n");
    printf("                          |              |\n");
    printf("                          |      __      |\n");
    printf("                          |______________|\n");
}
void you_lose2()
{
    wht;
    printf("                          __________                     \n");
    printf("    \\           /        |          |     |        |    \n");
    printf("      \\       /          |          |     |        |    \n");
    grn;
    printf("        \\   /            |          |     |        |    \n");
    printf("          |              |          |     |        |     \n");
    wht;
    printf("          |              |          |     |        |    \n");
    printf("          |              |__________|     |________|    \n");
    grn;
    printf("                      __________      __________       __________\n");
    printf("    |                |          |     |               |          \n");
    printf("    |                |          |     |               |          \n");
    wht;
    printf("    |                |          |     |_________      |          \n");
    printf("    |                |          |               |     |----------\n");
    grn;
    printf("    |                |          |               |     |          \n");
    printf("    |                |          |               |     |          \n");
    wht;
    printf("    |___________     |__________|     __________|     |__________\n");
    printf("\n\n");
    bgblue;
    printf("You are BANKRUPT!!!\n");
    printf("You are BANKRUPT!!!\n");
    printf("You are BANKRUPT!!!\n");
    wht;
    printf("                           ______________ \n");
    printf("                          |              |\n");
    printf("                          |   ○    ○   |\n");
    printf("                          |  *        *  |  \n");
    printf("                          | *    /\\    * |  \n");
    printf("                          |______________|  \n");
}
void pk_view()
{
     gotoxy(0,13);
    print_situation();
    Sleep(slp1);
    system("cls");
    p();
    gotoxy(0,13);
    print_situation();
    Sleep(slp1);
    system("cls");
    p_k();
    gotoxy(0,13);
    print_situation();
    Sleep(slp1);
    system("cls");
    fight1();
    gotoxy(0,13);
    print_situation();
    Sleep(slp1);
    system("cls");
    fight2();
    gotoxy(0,13);
    print_situation();
    Sleep(slp1);
    system("cls");
    fight1();
    gotoxy(0,13);
    print_situation();
    Sleep(slp1);
    system("cls");
    fight2();
    gotoxy(0,13);
    print_situation();
    printf("\n");
}
void p()
{
    red;
    printf("\n");
    printf("\n");
    printf("                 ______ \n");
    printf("                |      |\n");
    printf("                |      |\n");
    printf("                |______|\n");
    printf("                |       \n");
    printf("                |       \n");
    printf("                |       \n");
    wht;
}
void p_k()
{
   red;
    printf("\n");
    printf("\n");
    printf("                 ______ ");
    grn;
    printf("                         \n");
    red;
    printf("                |      |");
    grn;
    printf("                |     /  \n");
    red;
    printf("                |      |");
    grn;
    printf("                |   /    \n");
    red;
    printf("                |______|");
    grn;
    printf("                | /      \n");
    red;
    printf("                |       ");
    grn;
    printf("                | \\     \n");
    red;
    printf("                |       ");
    grn;
    printf("                |   \\   \n");
    red;
    printf("                |       ");
    grn;
    printf("                |     \\ \n");
    wht;
}
void fight1()
{
    yew;
    printf("                                                                \n");
    printf("                              |         |                       \n");
    printf("                            |_|_|     |_|_|                     \n");
    printf("             _____________    |         |    _____________      \n");
    printf("            |   \\     /   |   |         |   |   \\     /   |    \n");
    printf("            |  ○ ___ ○  |   |         |   |  >  ___  <  |       \n");
    printf("        0---|    |   |    |---0         0---|    |   |    |---0 \n");
    printf("            |    |___|    |   |         |   |    |___|    |     \n");
    printf("            |_____________|   |   v.s.  |   |_____________|     \n");
    printf("               U       U                       U       U        \n");
    printf("                                                                \n");
    wht;
}
void fight2()
{
    pur;
    printf("                                                                \n");
    printf("                              \\   \\ /   /                     \n");
    printf("                                \\/   \\/                       \n");
    printf("             _____________    \\/  \\ /  \\/    _____________   \n");
    printf("            |   \\     /   |       / \\       |   \\     /   |  \n");
    printf("            |  >       <  |     /     \\     |  ● ___ ●  |      \n");
    printf("        0---|   ┌┬┬┐  |---0         0---|   ┌┬┬┐  |---0         \n");
    printf("            |   └┴┴┘  | /             \\ |   └┴┴┘  |            \n");
    printf("            |_____________|       v.s.      |_____________|     \n");
    printf("               U       U                       U       U        \n");
    printf("                                                                \n");
    wht;
}
void player1()
{
    int choose,land_choose,land_choose2,land_choose3;
    if(lightning>0&&lightning<4)
    {
        printf("被皮卡丘電擊，全身麻痺無法動彈\n");
        lightning--;
        goto p1;
    }
    else if(lightning==0||lightning==4)
    {
        if(lightning==4)//4代表是放絕招的人
        {
            lightning--;
        }
    }
    printf("player1選擇: 1.丟骰子 2.絕招 :");
    scanf("%d",&choose);
    if(choose==1)
    {
        world(0);
f21:
        if(player_situation[1][0]==player_situation[1][1] || player_situation[1][0]==player_situation[1][2] || player_situation[1][0]==player_situation[1][3])//pk
        {
            printf("遇到對手了，進行pk一決勝負!\n");
            Sleep(2000);
            system("cls");
            gotoxy(0,13);
            print_situation();
            printf("\n");
f7:
            if(player_situation[1][0]==player_situation[1][1])
            {
                if(player[0]==2 && player_situation[5][0]==0)
                {
                    printf("是否使用\"死亡之握\"?(Y/N) :");
                    scanf(" %c",&y_n);
                    y_n=toupper(y_n);
                    if(y_n=='Y')
                    {
                        superpower(0,1,2);
                    }
                    else if(y_n=='N')
                    {
                        printf("不使用...!\n");
                    }
                    else goto f7;
                }
                if(player[1]==2 && player_situation[5][1]==0)
                {
                    superpower(1,0,2);
                }
                gotoxy(0,0);
                pk_view();
                pk(0,1);
                printf("您損失%d兵力，",army_lose1);
                grn;
                printf("玩家2");
                wht;
                printf("損失%d兵力\n",army_lose2);
                money_lose=rand()%501+500;
                if(army_lose1>army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("您損失較慘重，被玩家2劫走%d元\n",player_situation[2][0]);
                        player_situation[2][1]+=player_situation[2][0];
                        player_situation[2][0]=0;

                    }
                    else
                    {
                        printf("您損失較慘重，被玩家2劫走%d元\n",money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][1]+=money_lose;
                    }

                }
                else if(army_lose1<army_lose2)
                {

                    if(player_situation[2][1]<money_lose)
                    {
                        printf("玩家2損失較慘重，您火上加油打劫走%d元\n",player_situation[2][1]);
                        player_situation[2][0]+=player_situation[2][1];
                        player_situation[2][1]=0;
                    }
                    else
                    {
                        printf("玩家2損失較慘重，您火上加油打劫走%d元\n",money_lose);
                        player_situation[2][1]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }

                }
                else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
                Sleep(slp4);
                gotoxy(0,13);
                print_situation();
                Sleep(slp3);
            }
            else if(player_situation[1][0]==player_situation[1][2])
            {
                if(player[0]==2 && player_situation[5][0]==0)
                {
                    printf("是否使用\"死亡之握\"?(Y/N) :");
                    scanf(" %c",&y_n);
                    y_n=toupper(y_n);
                    if(y_n=='Y')
                    {
                        superpower(0,2,2);
                    }
                    else if(y_n=='N')
                    {
                        printf("直接進入戰鬥!\n");
                    }
                    else goto f7;
                }
                if(player[2]==2 && player_situation[5][2]==0)
                {
                    superpower(2,0,2);
                }
                gotoxy(0,0);
                pk_view();
                pk(0,2);
                printf("您損失%d兵力，",army_lose1);
                pur;
                printf("玩家3");
                wht;
                printf("損失%d兵力\n",army_lose2);
                money_lose=rand()%501+500;
               if(army_lose1>army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("您損失較慘重，被玩家3劫走%d元\n",player_situation[2][0]);
                        player_situation[2][2]+=player_situation[2][0];
                        player_situation[2][0]=0;

                    }
                    else
                    {
                        printf("您損失較慘重，被玩家3劫走%d元\n",money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][2]+=money_lose;
                    }

                }
                else if(army_lose1<army_lose2)
                {

                    if(player_situation[2][2]<money_lose)
                    {
                        printf("玩家3損失較慘重，您火上加油打劫走%d元\n",player_situation[2][2]);
                        player_situation[2][0]+=player_situation[2][2];
                        player_situation[2][2]=0;
                    }
                    else
                    {
                        printf("玩家3損失較慘重，您火上加油打劫走%d元\n",money_lose);
                        player_situation[2][2]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }

                }
                else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
                Sleep(slp4);
                gotoxy(0,13);
                print_situation();
                Sleep(slp3);
            }
            else if(player_situation[1][0]==player_situation[1][3])
            {
                if(player[0]==2 && player_situation[5][0]==0)
                {
                    printf("是否使用\"死亡之握\"?(Y/N) :");
                    scanf(" %c",&y_n);
                    y_n=toupper(y_n);
                    if(y_n=='Y')
                    {
                        superpower(0,3,2);
                    }
                    else if(y_n=='N')
                    {
                        printf("直接進入戰鬥!\n");
                    }
                    else goto f7;
                }
                if(player[3]==2 && player_situation[5][3]==0)
                {
                    superpower(3,0,2);
                }
                gotoxy(0,0);
                pk_view();
                pk(0,3);
                printf("您損失%d兵力，",army_lose1);
                yew;
                printf("玩家4");
                wht;
                printf("損失%d兵力\n",army_lose2);
                money_lose=rand()%501+500;
                if(army_lose1>army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("您損失較慘重，被玩家4劫走%d元\n",player_situation[2][0]);
                        player_situation[2][3]+=player_situation[2][0];
                        player_situation[2][0]=0;

                    }
                    else
                    {
                        printf("您損失較慘重，被玩家4劫走%d元\n",money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][3]+=money_lose;
                    }

                }
                else if(army_lose1<army_lose2)
                {

                    if(player_situation[2][3]<money_lose)
                    {
                        printf("玩家4損失較慘重，您火上加油打劫走%d元\n",player_situation[2][3]);
                        player_situation[2][0]+=player_situation[2][3];
                        player_situation[2][3]=0;
                    }
                    else
                    {
                        printf("玩家4損失較慘重，您火上加油打劫走%d元\n",money_lose);
                        player_situation[2][3]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }

                }
                else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
                Sleep(slp4);
                gotoxy(0,13);
                print_situation();
                Sleep(slp3);
            }
            Sleep(slp4);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
        }
        else if(player_situation[5][0]==0 && player[0]==3)
        {
            printf("您要使用來來哥絕招嗎? (Y/N):");
            scanf(" %c",&y_n);
            y_n=toupper(y_n);
            if(y_n=='Y')
            {
                superpower(0,1000,3);
            }
        }
        if (land_situationl[1][player_situation[1][0]-1]==0 && player_situation[1][0]!=3 && player_situation[1][0]!=7 && player_situation[1][0]!=15) //走道空城
        {
            money_cosume=money_change(1);
f3:
            printf("此土地地價為%d元，城內駐軍%d人，你要1.購買? 2.攻占? 3.離開 :",money_cosume,land_situationl[3][player_situation[1][0]-1]);
            scanf("%d",&land_choose);
            switch(land_choose)
            {
            case 1:
                if(player_situation[2][0]<money_cosume)
                {
                    printf("您手頭現金不足唷...\n");
                    goto f3;
                }
                else
                {
                    land_situationl[1][player_situation[1][0]-1]=101;
                    player_situation[2][0]-=money_cosume;
                    printf("花費%d元占領土地...\n",money_cosume);
                    Sleep(slp2);
                    system("cls");
                    world_print();
                    print_situation();
                    player_now_print();
                    land_set();
                }
                break;
            case 2:
                attack_land(0,101);
                break;
            case 3:
                break;
            default:
                printf("輸入錯誤\n");
                goto f3;
            }
        }
        else if(player_situation[1][0]==3) //走到銀行
        {
f4:
            printf("請問你要1.領錢? 2.存錢? 3.離開\n");
            int while_bank_choose;
            scanf("%d",&while_bank_choose);
            switch(while_bank_choose)
            {
            case 1:
            {
                printf("請輸入提款金額:");
                scanf("%d",&withdraw1);
                if(withdraw1>player_situation[3][0] || withdraw1<=0)
                {
                    printf("提款金額有誤!\n");
                    goto f4;
                }
                else
                {
                    player_situation[2][0]+=withdraw1;//現金增加
                    player_situation[3][0]-=withdraw1;//存款減少
                    Sleep(slp1);
                    system("cls");
                    world_print();
                    print_situation();
                    player_now_print();
                    land_set();
                }
                break;
            }
            case 2:
            {
                printf("請輸入存款金額:");
                scanf("%d",&savemoney1);
                if(savemoney1>player_situation[2][0] || savemoney1<=0)
                {
                    printf("存款金額錯誤!\n");
                    goto f4;
                }
                else
                {
                    player_situation[2][0]-=savemoney1;//現金減少
                    player_situation[3][0]+=savemoney1;//存款增加
                    Sleep(slp1);
                    system("cls");
                    world_print();
                    print_situation();
                    player_now_print();
                    land_set();
                }
                break;
            }
            case 3:
            {
                printf("謝謝惠顧歡迎下次再來~\n");
                break;
            }
            default:
            {
                printf("請輸入正確選項!\n");
                goto f4;
                break;
            }
            }
        }
        else if(player_situation[1][0]==7 || player_situation[1][0]==15) //走到機會命運
        {
            int cod;
            printf("機會命運關!\n");
            cod=rand()%65+1;
            chance_or_destiny(cod,0);
            Sleep(slp4);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
            if(cod>=51 && cod<=60)
            {
                goto f21;
            }
            Sleep(slp1);
        }
        else if(land_situationl[1][player_situation[1][0]-1]!=101 && player_situation[1][0]!=3 && player_situation[1][0]!=7 && player_situation[1][0]!=15) //過路費
        {
f5:
            if(player_situation[5][0]==0 && player[0]==4)
            {
                printf("是否使用冰雪女王艾莎絕招? (Y/N) :");
                scanf(" %c",&y_n);
                y_n=toupper(y_n);
                if(y_n=='Y')
                {
                    superpower(0,1000,4);
                }
            }
            else if(player_situation[5][0]==0 && player[0]==9)
            {
                printf("是否使用孫悟空絕招? (Y/N) :");
                scanf(" %c",&y_n);
                y_n=toupper(y_n);
                if(y_n=='Y')
                {
                    superpower(0,1000,9);
                }
            }
            else
            {
                printf("此土地過路費為%d，城內駐軍為%d，你要1.付過路費? 2.闖關? 3.攻城?\n",land_situationl[2][player_situation[1][0]-1],land_situationl[3][player_situation[1][0]-1]);
            scanf("%d",&land_choose2);
            switch(land_choose2)
            {
            case 1:
                if(land_situationl[2][player_situation[1][0]-1]>player_situation[2][0])
                {
                    int gap=land_situationl[2][player_situation[1][0]-1]-player_situation[2][0];
                    player_situation[2][0]=0;
                    player_situation[3][0]-=gap;
                    player_situation[3][land_situationl[1][player_situation[1][0]-1]-101]+=land_situationl[2][player_situation[1][0]-1];//地主收到過路費，存款增加
                }
                else
                {
                    player_situation[2][0]-=land_situationl[2][player_situation[1][0]-1];
                    player_situation[3][land_situationl[1][player_situation[1][0]-1]-101]+=land_situationl[2][player_situation[1][0]-1];//地主收到過路費，存款增加
                }
                break;
            case 2:
                if(player[0]==1 && player_situation[5][0]==0)
                {
                    printf("是否使用宇智波絕招--萬花筒寫輪眼?:\n");
                    scanf(" %c",&y_n);
                    y_n=toupper(y_n);
                    if(y_n=='Y')
                    {
                        superpower(0,1000,1);
                    }
                }
                attack_door(0);
                break;
            case 3:
                attack_land(0,101);
                break;
            default:
                printf("輸入錯誤");
                goto f5;
            }

            Sleep(slp1);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
            }
        }
        else if(land_situationl[1][player_situation[1][0]-1]==101 && player_situation[1][0]!=3 && player_situation[1][0]!=7 && player_situation[1][0]!=15) //走到自己土地
        {
f6:
            printf("目前城內駐軍%d人，1.領取兵力 2.存放兵力 3.離開 :\n",land_situationl[3][player_situation[1][0]-1]);
            scanf("%d",&land_choose3);
            if(land_choose3==1)
            {
                printf("請輸入領取兵力數量：");
                scanf("%d",&force_quanity);
                if(force_quanity>0 && force_quanity <= land_situationl[3][player_situation[1][0]-1])
                {
                    player_situation[4][0]+=force_quanity;
                    land_situationl[3][player_situation[1][0]-1]-=force_quanity;
                }
                else
                {
                    printf("輸入兵力數字有誤\n");
                    goto f6;
                }
            }
            else if(land_choose3==2)
            {
                printf("請輸入存放兵力數量：");
                scanf("%d",&force_quanity);
                if(force_quanity<=player_situation[4][0] && force_quanity>0)
                {
                    player_situation[4][0]-=force_quanity;
                    land_situationl[3][player_situation[1][0]-1]+=force_quanity;
                }
                else
                {
                    printf("輸入兵力數字有誤\n");
                    goto f6;
                }
            }
            else if(land_choose3!=1 && land_choose3 !=2 && land_choose3 !=3)
            {
                printf("輸入錯誤!");
                goto f6;
            }
        }
    }
    else if(choose==2)
       {
            if(player_situation[5][0]==0) //絕招已經準備好
            {
                if(player[0]==3)
                {
                    superpower(0,1000,3);
                }
                else if(player[0]==5)
                {
                    superpower(0,1000,5);
                }
                else if(player[0]==6)
                {
                    if(player_situation[1][0]==1) //站在第一格
                    {
                        if(land_situationl[1][15]==101 || land_situationl[1][1]==101)
                        {
                            superpower(0,1000,6);
                        }
                        else printf("前後兩格沒有您的領地\n");
                        Sleep(slp2);
                        system("cls");
                        world_print();
                        print_situation();
                        player_now_print();
                        land_set();
                        player1();
                    }
                    else if(player_situation[1][0]==16) //站在第16格
                    {
                        if(land_situationl[1][0]==101 || land_situationl[1][14]==101)
                        {
                            superpower(0,1000,6);
                        }
                        else printf("前後兩格沒有您的領地\n");
                        Sleep(slp2);
                        system("cls");
                        world_print();
                        print_situation();
                        player_now_print();
                        land_set();
                        player1();
                    }
                    else if(land_situationl[1][player_situation[1][0]]==101 || land_situationl[1][player_situation[1][0]-2]==101) //站在2~15格
                    {
                        superpower(0,1000,6);
                    }
                    else if(land_situationl[1][player_situation[1][0]]!=101 || land_situationl[1][player_situation[1][0]-2]!=101)
                    {
                        printf("前後兩格沒有您的領地\n");
                        Sleep(slp2);
                        system("cls");
                        player1();
                    }
                }
                else if(player[0]==7)
                {
                    superpower(0,1000,7);
                    goto f21;
                }
                else if(player[0]==8)
                {
                    superpower(0,1000,8);
                }
                else if(player[0]==9)
                {
                    superpower(0,1000,9);
                }
                system("cls");
                world_print();
                print_situation();
                player_now_print();
                land_set();
                player1();
            }
            else if(player_situation[5][0]>0) //絕招尚未準備好ˋ
            {
                printf("絕招還沒準備好");
                Sleep(slp2);
                system("cls");
                world_print();
                print_situation();
                player_now_print();
                land_set();
                player1();
            }
       }
p1:
    Sleep(slp3);
    if(player_situation[5][0]>0)  //CD-1
    {
        player_situation[5][0]-=1;
    }
    Sleep(slp1);
    system("cls");
    world_print();
    print_situation();
    player_now_print();
    land_set();
}
void player2()
{
    printf("玩家2");
l2:
    if(lightning>0&&lightning<4)
        {
            printf("被皮卡丘電擊，全身麻痺無法動彈\n");
            lightning--;
            goto p2;
        }
        else if(lightning==0||lightning==4)
        {
            if(lightning==4)
            {
                lightning--;
            }
            if(player[1]==3 && player_situation[5][1]==0)
            {
                if(((player_situation[1][1]-player_situation[1][2])<=-1 && (player_situation[1][1]-player_situation[1][2])>=-5) ||((player_situation[1][1]-player_situation[1][2])<=5 && (player_situation[1][1]-player_situation[1][2])>=1) ||((player_situation[1][1]-player_situation[1][2])<=15 && (player_situation[1][1]-player_situation[1][2])>=11))
                {
                    superpower(1,2,3);
                }
                else if(((player_situation[1][1]-player_situation[1][3])<=-1 && (player_situation[1][1]-player_situation[1][3])>=-5) ||((player_situation[1][1]-player_situation[1][3])<=5 && (player_situation[1][1]-player_situation[1][3])>=1) ||((player_situation[1][1]-player_situation[1][3])<=15 && (player_situation[1][1]-player_situation[1][3])>=11))
                {
                    superpower(1,3,3);
                }
                else if(((player_situation[1][1]-player_situation[1][0])<=-1 && (player_situation[1][1]-player_situation[1][0])>=-5) ||((player_situation[1][1]-player_situation[1][0])<=5 && (player_situation[1][1]-player_situation[1][0])>=1) ||((player_situation[1][1]-player_situation[1][0])<=15 && (player_situation[1][1]-player_situation[1][0])>=11))
                {
                    superpower(1,0,3);
                }
            }
            else if(player[1]==5 && player_situation[5][1]==0)
            {
                superpower(1,1000,5);
            }
            else if(player[1]==6 && player_situation[5][1]==0)
            {
                if(player_situation[1][1]==1) //站在第一格
                    {
                        if(land_situationl[1][15]==102 || land_situationl[1][1]==102)
                        {
                            superpower(1,1000,6);
                        }
                        else world(1);
                    }
                    else if(player_situation[1][1]==16) //站在第16格
                    {
                        if(land_situationl[1][0]==102 || land_situationl[1][14]==102)
                        {
                            superpower(1,1000,6);
                        }
                        else world(1);
                    }
                    else if(land_situationl[1][player_situation[1][1]]==102 || land_situationl[1][player_situation[1][1]-2]==102) //站在2~15格
                    {
                        superpower(1,1000,6);
                    }
                    else if(land_situationl[1][player_situation[1][1]]!=102 || land_situationl[1][player_situation[1][1]-2]!=102)
                    {
                        world(1);
                    }
            }
            else if(player[1]==7 && player_situation[5][1]==0)
            {
                superpower(1,1000,7);
                goto f22;
            }
            else if(player[1]==8 && player_situation[5][1]==0)
            {
                superpower(1,1000,8);
                goto l2;
            }
            else world(1);
        }
f22:
    Sleep(slp3);
    if(player_situation[1][1]==player_situation[1][0] || player_situation[1][1]==player_situation[1][2] || player_situation[1][1]==player_situation[1][3])//pk
    {
        printf("玩家2遇到對手了，進行pk\n");
        Sleep(slp3);
        if(player_situation[1][1]==player_situation[1][0])
        {
f8:
            if(player[0]==2 && player_situation[5][0]==0)
            {
                printf("是否使用\"死亡之握\"?(Y/N) :");
                scanf(" %c",&y_n);
                y_n=toupper(y_n);
                if(y_n=='Y')
                {
                    superpower(0,1,2);
                }
                else if(y_n=='N')
                {
                    printf("直接進入戰鬥!\n");
                }
                else goto f8;
            }
            gotoxy(0,0);
            pk_view();
            pk(1,0);
            printf("您損失%d兵力，",army_lose1);
            grn;
            printf("玩家2");
            wht;
            printf("損失%d兵力\n",army_lose2);
            money_lose=rand()%501+500;
           if(army_lose1<army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("您損失較慘重，被玩家2劫走%d元\n",player_situation[2][0]);
                        player_situation[2][1]+=player_situation[2][0];
                        player_situation[2][0]=0;

                    }
                    else
                    {
                        printf("您損失較慘重，被玩家2劫走%d元\n",money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][1]+=money_lose;
                    }

                }
                else if(army_lose1>army_lose2)
                {

                    if(player_situation[2][1]<money_lose)
                    {
                        printf("玩家2損失較慘重，您火上加油打劫走%d元\n",player_situation[2][1]);
                        player_situation[2][0]+=player_situation[2][1];
                        player_situation[2][1]=0;
                    }
                    else
                    {
                        printf("玩家2損失較慘重，您火上加油打劫走%d元\n",money_lose);
                        player_situation[2][1]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }
                }
            else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        else if(player_situation[1][1]==player_situation[1][2])
        {
            if(player[1]==2 && player_situation[5][1]==0)
            {
                printf("玩家2使用死亡之握\n");
                superpower(1,2,2);

            }
            else if(player[2]==2 && player_situation[5][2]==0)
            {
                printf("玩家3使用死亡之握\n");
                superpower(2,1,2);
            }
            gotoxy(0,0);
            pk_view();
            pk(1,2);
            grn;
            printf("玩家2");
            wht;
            printf("損失%d兵力，",army_lose1);
            pur;
            printf("玩家3");
            wht;
            printf("損失%d兵力\n",army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1>army_lose2)
                {
                    if(player_situation[2][1]<money_lose)
                    {
                        printf("玩家2損失較慘重，被玩家3劫走%d元\n",player_situation[2][0]);
                        player_situation[2][2]+=player_situation[2][1];
                        player_situation[2][1]=0;

                    }
                    else
                    {
                        printf("玩家2損失較慘重，被玩家3劫走%d元\n",money_lose);
                        player_situation[2][1]-=money_lose;
                        player_situation[2][2]+=money_lose;
                    }

                }
                else if(army_lose1<army_lose2)
                {

                    if(player_situation[2][2]<money_lose)
                    {
                        printf("玩家3損失較慘重，被玩家2劫走%d元\n",player_situation[2][2]);
                        player_situation[2][1]+=player_situation[2][2];
                        player_situation[2][2]=0;
                    }
                    else
                    {
                        printf("玩家3損失較慘重，被玩家2劫走%d元\n",money_lose);
                        player_situation[2][2]-=money_lose;
                        player_situation[2][1]+=money_lose;
                    }
                }
            else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        else if(player_situation[1][1]==player_situation[1][3])
        {
            if(player[1]==2 && player_situation[5][1]==0)
            {
                printf("玩家2使用死亡之握\n");
                superpower(1,3,2);

            }
            else if(player[2]==2 && player_situation[5][2]==0)
            {
                printf("玩家4使用死亡之握\n");
                superpower(3,1,2);
            }
            gotoxy(0,0);
            pk_view();
            pk(1,3);
            grn;
            printf("玩家2");
            wht;
            printf("損失%d兵力，",army_lose1);
            yew;
            printf("玩家4");
            wht;
            printf("損失%d兵力\n",army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1>army_lose2)
                {
                    if(player_situation[2][1]<money_lose)
                    {
                        printf("玩家2損失較慘重，被玩家4劫走%d元\n",player_situation[2][1]);
                        player_situation[2][3]+=player_situation[2][1];
                        player_situation[2][1]=0;

                    }
                    else
                    {
                        printf("玩家2損失較慘重，被玩家4劫走%d元\n",money_lose);
                        player_situation[2][1]-=money_lose;
                        player_situation[2][3]+=money_lose;
                    }
                }
                else if(army_lose1<army_lose2)
                {
                    if(player_situation[2][3]<money_lose)
                    {
                        printf("玩家4損失較慘重，被玩家2劫走%d元\n",player_situation[2][3]);
                        player_situation[2][1]+=player_situation[2][3];
                        player_situation[2][3]=0;
                    }
                    else
                    {
                        printf("玩家4損失較慘重，被玩家2劫走%d元\n",money_lose);
                        player_situation[2][3]-=money_lose;
                        player_situation[2][1]+=money_lose;
                    }
                }
            else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
    }
    if(land_situationl[1][player_situation[1][1]-1]==0 && player_situation[1][1]!=3 && player_situation[1][1]!=7 && player_situation[1][1]!=15)
    {
        if(player_situation[2][1]>1500 ||
                (player_situation[1][1]==14 && player_situation[2][1]<1500 && player_situation[2][1]>500) ||
                (player_situation[1][1]==15 && player_situation[2][1]<1500 && player_situation[2][1]>500) ||
                (player_situation[1][1]==16 && player_situation[2][1]<1500 && player_situation[2][1]>500) ||
                (player_situation[1][1]==1 && player_situation[2][1]<1500 && player_situation[2][1]>500) ||
                (player_situation[1][1]==2 && player_situation[2][1]<1500 && player_situation[2][1]>500) ) //電腦如果金錢大於1500或雖然小於1500但預期將能在下個回合走到銀行，便會選擇佔領
        {
            printf("玩家2選擇購買土地\n");
            Sleep(slp1);
            money_cosume=money_change(1);
            if(money_cosume>player_situation[2][1])
            {
                printf("但玩家2發現手頭沒有足夠金錢因此作罷...\n");
                Sleep(slp3);
                system("cls");
                world_print();
                print_situation();
                player_now_print();
                land_set();
            }
            else
            {
                player_situation[2][1]-=money_cosume;
                printf("玩家2花費%d元佔領土地...",money_cosume);
                land_situationl[1][player_situation[1][1]-1]=102;
                Sleep(slp3);
                system("cls");
                world_print();
                print_situation();
                player_now_print();
                land_set();
            }
        }
        else if(player_situation[4][1]>1000 && player_situation[4][1]>=player_situation[4][0]*0.6 && player_situation[4][1]>=player_situation[4][2]*0.6 && player_situation[4][1]>=player_situation[4][3]*0.6) //如果兵力充足且相信跟其他玩家pk不致損失太多，就會攻佔
        {
            printf("玩家2選擇攻佔土地...\n");
            Sleep(slp2);
            attack_land(1,102);
        }
        else
        {
            printf("玩家2沒做任何動作...\n");
        }
    }
    else if(player_situation[1][1]==3) //走到銀行
    {
        if(player_situation[2][1]>2000)
        {
            printf("玩家2選擇存款\n");
            int save_prob=rand()%401+300;
            savemoney1=(player_situation[2][1]-2000)*save_prob/1000;
            Sleep(slp2);
            printf("玩家2存了%d元...\n",savemoney1);
            player_situation[2][1]-=savemoney1;//現金減少
            player_situation[3][1]+=savemoney1;//存款增加
            Sleep(slp1);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
        }
        else if(player_situation[2][1]<1000 && player_situation[4][1]<=player_situation[4][0]*0.3 && player_situation[4][1]<=player_situation[4][2]*0.3 && player_situation[4][1]<=player_situation[4][3]*0.3 && player_situation[3][1] >0)
        {
            printf("玩家2選擇提款\n");
            withdraw1=rand()%(player_situation[3][1]);
            Sleep(slp2);
            printf("玩家2領了%d元...\n",withdraw1);
            player_situation[2][1]+=withdraw1;//現金增加
            player_situation[3][1]-=withdraw1;//存款減少
            Sleep(slp1);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
        }
        else
        {
            printf("玩家2對銀行視而不見...\n");
        }
    }
    else if(player_situation[1][1]==7 || player_situation[1][1]==15) //走到機會命運
    {
        printf("玩家2走到機會命運關\n");
        cod=rand()%65+1;
        chance_or_destiny(cod,1);
        Sleep(slp4);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        if(cod>=51 && cod<=60)
        {
            goto f22;
        }
        Sleep(slp1);
    }
    else if(land_situationl[1][player_situation[1][1]-1]!=102 && player_situation[1][1]!=3 && player_situation[1][1]!=7 && player_situation[1][1]!=15) //過路費
    {
        printf("玩家2走到其他人土地\n");
        if(player_situation[5][1]==0 && player[1]==4)
        {
            superpower(1,1000,4);
        }
        else if(player_situation[5][1]==0 && player[1]==9)
        {
            superpower(1,1000,9);
        }
        else
        {
            if(player_situation[2][1]>2500 && player_situation[4][1]>=player_situation[4][0]*0.6 && player_situation[4][1]>=player_situation[4][2]*0.6 && player_situation[4][1]>=player_situation[4][3]*0.6 )
        {
            printf("玩家2繳交過路費%d元\n",land_situationl[2][player_situation[1][1]-1]);
            if(land_situationl[2][player_situation[1][1]-1]>player_situation[2][1])
            {
                int gap=land_situationl[2][player_situation[1][1]-1]-player_situation[2][1];
                player_situation[2][1]=0;
                player_situation[3][1]-=gap;
                player_situation[3][land_situationl[1][player_situation[1][1]-1]-101]+=land_situationl[2][player_situation[1][1]-1];//地主收到過路費，存款增加
            }
            else
            {
                player_situation[2][1]-=land_situationl[2][player_situation[1][1]-1];
                player_situation[3][land_situationl[1][player_situation[1][1]-1]-101]+=land_situationl[2][player_situation[1][1]-1];//地主收到過路費，存款增加
            }
        }
        else if(player_situation[2][1]<=2500 && player_situation[4][1]>=player_situation[4][0]*0.6 && player_situation[4][1]>=player_situation[4][2]*0.6 && player_situation[4][1]>=player_situation[4][3]*0.6 )
        {
            printf("玩家2選擇闖關...");
            if(player[1]==1 && player_situation[5][1]==0)
            {
                printf("玩家2使用萬花筒寫輪眼!\n");
                superpower(1,1000,1);
            }
            attack_door(1);
        }
        else if(player_situation[2][1]<=2500 && player_situation[4][1]>=player_situation[4][0]*0.8 && player_situation[4][1]>=player_situation[4][2]*0.8 && player_situation[4][1]>=player_situation[4][3]*0.8 )
        {
            printf("玩家2選擇攻城...");
            attack_land(1,102);
        }
        else
        {
            printf("玩家2繳交過路費%d元\n",land_situationl[2][player_situation[1][1]-1]);
            if(land_situationl[2][player_situation[1][1]-1]>player_situation[2][1])
            {
                int gap=land_situationl[2][player_situation[1][1]-1]-player_situation[2][1];
                player_situation[2][1]=0;
                player_situation[3][1]-=gap;
                player_situation[3][land_situationl[1][player_situation[1][1]-1]-101]+=land_situationl[2][player_situation[1][1]-1];//地主收到過路費，存款增加
            }
            else
            {
                player_situation[2][1]-=land_situationl[2][player_situation[1][1]-1];
                player_situation[3][land_situationl[1][player_situation[1][1]-1]-101]+=land_situationl[2][player_situation[1][1]-1];//地主收到過路費，存款增加
            }
        }
        Sleep(slp1);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        }
    }
    else if(land_situationl[1][player_situation[1][1]-1]==102 && player_situation[1][1]!=3 && player_situation[1][1]!=7 && player_situation[1][1]!=15) //走到自己土地
    {
        if(player_situation[4][1]<= player_situation[4][0]*0.8 && player_situation[4][1]<= player_situation[4][2]*0.8 && player_situation[4][1]<= player_situation[4][3]*0.8) //電腦領取兵力
        {
            force_quanity=land_situationl[3][player_situation[1][1]-1]-500;
            if(force_quanity>0)
            {
                printf("玩家2選擇領取 %d 兵力\n",force_quanity);
                player_situation[4][1]+=force_quanity;
                land_situationl[3][player_situation[1][1]-1]-=force_quanity;
            }
        }
        else if(player_situation[4][1]>= player_situation[4][0]*1.2 && player_situation[4][1]>= player_situation[4][2]*1.2 && player_situation[4][1]>= player_situation[4][3]*1.2) //電腦存放兵力
        {
            int p1s=player_situation[4][0],p2s=player_situation[4][2],p3s=player_situation[4][3],maxs;
            maxs=p1s;
            if(p2s>maxs)        //比較其他三個玩家的兵力，取最大的出來，然後電腦存放與[最大的兵力]的差距的0.8
            {
                maxs=p2s;
                if(p3s>maxs)
                {
                    maxs=p3s;
                }
            }
            else if(p2s<=maxs)
            {
                if(p3s>maxs)
                {
                    maxs=p3s;
                }
            }
            force_quanity=(player_situation[4][1]-maxs)*0.8;
            printf("玩家2選擇存放 %d 兵力\n",force_quanity);
            player_situation[4][1]-=force_quanity;
            land_situationl[3][player_situation[1][1]-1]+=force_quanity;
        }
        else
        {
            printf("玩家2按兵不動...\n");
        }
    }
p2:
    Sleep(slp3);
    if(player_situation[5][1]>0)
    {
        player_situation[5][1]-=1;
    }
    Sleep(slp1);
    system("cls");
    world_print();
    print_situation();
    player_now_print();
    land_set();
}
void player3()
{
    printf("玩家3");
l3:
    if(lightning>0&&lightning<4)
    {
        printf("被皮卡丘電擊，全身麻痺無法動彈\n");
        lightning--;
        goto p3;
    }
    else if(lightning==0||lightning==4)
        {
            if(lightning==4)
            {
                lightning--;
            }
            if(player[2]==3 && player_situation[5][2]==0)
            {
                if(((player_situation[1][2]-player_situation[1][3])<=-1 && (player_situation[1][2]-player_situation[1][3])>=-5) ||((player_situation[1][2]-player_situation[1][3])<=5 && (player_situation[1][2]-player_situation[1][3])>=1) ||((player_situation[1][2]-player_situation[1][3])<=15 && (player_situation[1][2]-player_situation[1][3])>=11))
                {
                    superpower(2,3,3);
                }
                else if(((player_situation[1][2]-player_situation[1][1])<=-1 && (player_situation[1][2]-player_situation[1][1])>=-5) ||((player_situation[1][2]-player_situation[1][1])<=5 && (player_situation[1][2]-player_situation[1][1])>=1) ||((player_situation[1][2]-player_situation[1][1])<=15 && (player_situation[1][2]-player_situation[1][1])>=11))
                {
                    superpower(2,1,3);
                }
                else if(((player_situation[1][2]-player_situation[1][0])<=-1 && (player_situation[1][2]-player_situation[1][0])>=-5) ||((player_situation[1][2]-player_situation[1][0])<=5 && (player_situation[1][2]-player_situation[1][0])>=1) ||((player_situation[1][2]-player_situation[1][0])<=15 && (player_situation[1][2]-player_situation[1][0])>=11))
                {
                    superpower(2,0,3);
                }
            }
            else if(player[2]==5 && player_situation[5][2]==0)
            {
                superpower(2,1000,5);
            }
            else if(player[2]==6 && player_situation[5][2]==0)
            {
                if(player_situation[1][2]==1) //站在第一格
                    {
                        if(land_situationl[1][15]==103 || land_situationl[1][1]==103)
                        {
                            superpower(2,1000,6);
                        }
                        else world(2);
                    }
                    else if(player_situation[1][2]==16) //站在第16格
                    {
                        if(land_situationl[1][0]==103 || land_situationl[1][14]==103)
                        {
                            superpower(2,1000,6);
                        }
                        else world(2);
                    }
                    else if(land_situationl[1][player_situation[1][2]]==103 || land_situationl[1][player_situation[1][2]-2]==103) //站在2~15格
                    {
                        superpower(2,1000,6);
                    }
                    else if(land_situationl[1][player_situation[1][2]]!=103 || land_situationl[1][player_situation[1][2]-2]!=103)
                    {
                        world(2);
                    }
            }
            else if(player[2]==7 && player_situation[5][2]==0)
            {
                superpower(2,1000,7);
                goto f23;
            }
            else if(player[2]==8 && player_situation[5][2]==0)
            {
                superpower(2,1000,8);
                goto l3;
            }
            else world(2);
        }
f23:
    Sleep(slp3);
    if(player_situation[1][2]==player_situation[1][0] || player_situation[1][2]==player_situation[1][1] || player_situation[1][2]==player_situation[1][3])//pk
    {
        printf("玩家3遇到對手了，進行pk\n");
        Sleep(slp3);
        if(player_situation[1][2]==player_situation[1][0])
        {
f9:
            if(player[0]==2 && player_situation[5][0]==0)
            {
                printf("是否使用\"死亡之握\"?(Y/N) :");
                scanf(" %c",&y_n);
                y_n=toupper(y_n);
                if(y_n=='Y')
                {
                    superpower(0,2,2);
                }
                else if(y_n=='N')
                {
                    printf("直接進入戰鬥!\n");
                }
                else goto f9;
            }
            gotoxy(0,0);
            pk_view();
            pk(2,0);
            printf("您損失%d兵力，",army_lose1);
            grn;
            printf("玩家3");
            wht;
            printf("損失%d兵力\n",army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1<army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("您損失較慘重，被玩家3劫走%d元\n",player_situation[2][0]);
                        player_situation[2][2]+=player_situation[2][0];
                        player_situation[2][0]=0;
                    }
                    else
                    {
                        printf("您損失較慘重，被玩家3劫走%d元\n",money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][2]+=money_lose;
                    }
                }
                else if(army_lose1>army_lose2)
                {
                    if(player_situation[2][2]<money_lose)
                    {
                        printf("玩家3損失較慘重，您火上加油打劫走%d元\n",player_situation[2][2]);
                        player_situation[2][0]+=player_situation[2][2];
                        player_situation[2][2]=0;
                    }
                    else
                    {
                        printf("玩家3損失較慘重，您火上加油打劫走%d元\n",money_lose);
                        player_situation[2][2]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }
                }
            else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        else if(player_situation[1][2]==player_situation[1][1])
        {
            if(player[2]==2 && player_situation[5][2]==0)
            {
                printf("玩家3使用死亡之握\n");
                superpower(2,1,2);

            }
            else if(player[1]==2 && player_situation[5][1]==0)
            {
                printf("玩家2使用死亡之握\n");
                superpower(1,2,2);
            }
            gotoxy(0,0);
            pk_view();
            pk(2,1);
            pur;
            printf("玩家3");
            wht;
            printf("損失%d兵力，",army_lose1);
            grn;
            printf("玩家2");
            wht;
            printf("損失%d兵力\n",army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1>army_lose2)
                {
                    if(player_situation[2][2]<money_lose)
                    {
                        printf("玩家3損失較慘重，被玩家2劫走%d元\n",player_situation[2][2]);
                        player_situation[2][1]+=player_situation[2][2];
                        player_situation[2][2]=0;
                    }
                    else
                    {
                        printf("玩家3損失較慘重，被玩家2劫走%d元\n",money_lose);
                        player_situation[2][2]-=money_lose;
                        player_situation[2][1]+=money_lose;
                    }
                }
                else if(army_lose1<army_lose2)
                {
                    if(player_situation[2][1]<money_lose)
                    {
                        printf("玩家2損失較慘重，被玩家3劫走%d元\n",player_situation[2][1]);
                        player_situation[2][2]+=player_situation[2][1];
                        player_situation[2][1]=0;
                    }
                    else
                    {
                        printf("玩家2損失較慘重，被玩家3劫走%d元\n",money_lose);
                        player_situation[2][1]-=money_lose;
                        player_situation[2][2]+=money_lose;
                    }
                }
            else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        else if(player_situation[1][2]==player_situation[1][3])
        {
            if(player[2]==2 && player_situation[5][2]==0)
            {
                printf("玩家3使用死亡之握\n");
                superpower(2,3,2);

            }
            else if(player[3]==2 && player_situation[5][3]==0)
            {
                printf("玩家4使用死亡之握\n");
                superpower(3,2,2);
            }
            gotoxy(0,0);
            pk_view();
            pk(2,3);
            pur;
            printf("玩家3");
            wht;
            printf("損失%d兵力，",army_lose1);
            yew;
            printf("玩家4");
            wht;
            printf("損失%d兵力\n",army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1>army_lose2)
                {
                    if(player_situation[2][2]<money_lose)
                    {
                        printf("玩家3損失較慘重，被玩家4劫走%d元\n",player_situation[2][2]);
                        player_situation[2][3]+=player_situation[2][2];
                        player_situation[2][2]=0;
                    }
                    else
                    {
                        printf("玩家3損失較慘重，被玩家4劫走%d元\n",money_lose);
                        player_situation[2][2]-=money_lose;
                        player_situation[2][3]+=money_lose;
                    }
                }
                else if(army_lose1<army_lose2)
                {
                    if(player_situation[2][3]<money_lose)
                    {
                        printf("玩家4損失較慘重，被玩家3劫走%d元\n",player_situation[2][3]);
                        player_situation[2][2]+=player_situation[2][3];
                        player_situation[2][3]=0;
                    }
                    else
                    {
                        printf("玩家4損失較慘重，被玩家3劫走%d元\n",money_lose);
                        player_situation[2][3]-=money_lose;
                        player_situation[2][2]+=money_lose;
                    }
                }
            else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
    }
    if(land_situationl[1][player_situation[1][2]-1]==0 && player_situation[1][2]!=3 && player_situation[1][2]!=7 && player_situation[1][2]!=15)
    {
        if(player_situation[2][2]>1500 ||
                (player_situation[1][2]==14 && player_situation[2][2]<1500 && player_situation[2][2]>500) ||
                (player_situation[1][2]==15 && player_situation[2][2]<1500 && player_situation[2][2]>500) ||
                (player_situation[1][2]==16 && player_situation[2][2]<1500 && player_situation[2][2]>500) ||
                (player_situation[1][2]==1 && player_situation[2][2]<1500 && player_situation[2][2]>500) ||
                (player_situation[1][2]==2 && player_situation[2][2]<1500 && player_situation[2][2]>500) ) //電腦如果金錢大於1500或雖然小於1500但預期將能在下個回合走到銀行，便會選擇佔領
        {
            printf("玩家3選擇購買土地\n");
            Sleep(slp1);
            money_cosume=money_change(1);
            if(money_cosume>player_situation[2][2])
            {
                printf("但玩家2發現手頭沒有足夠金錢因此作罷...\n");
                Sleep(slp3);
                system("cls");
                world_print();
                print_situation();
                player_now_print();
                land_set();
            }
            else
            {
                player_situation[2][2]-=money_cosume;
                printf("玩家3花費%d元佔領土地...",money_cosume);
                land_situationl[1][player_situation[1][2]-1]=103;
                Sleep(slp3);
                system("cls");
                world_print();
                print_situation();
                player_now_print();
                land_set();
            }
        }
        else if(player_situation[4][2]>1000 && player_situation[4][2]>=player_situation[4][0]*0.6 && player_situation[4][2]>=player_situation[4][1]*0.6 && player_situation[4][2]>=player_situation[4][3]*0.6) //如果兵力充足且相信跟其他玩家pk不致損失太多，就會攻佔
        {
            printf("玩家3選擇攻佔土地...\n");
            Sleep(slp2);
            attack_land(2,103);
        }
        else
        {
            printf("玩家3沒做任何動作...\n");
        }
    }
    else if(player_situation[1][2]==3) //走到銀行
    {
        if(player_situation[2][2]>2000)
        {
            printf("玩家3選擇存款\n");
            int save_prob=rand()%401+300;
            savemoney1=(player_situation[2][2]-2000)*save_prob/1000;
            Sleep(slp2);
            printf("玩家2存了%d元...\n",savemoney1);
            player_situation[2][2]-=savemoney1;//現金減少
            player_situation[3][2]+=savemoney1;//存款增加
            Sleep(slp1);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
        }
        else if(player_situation[2][2]<1000 && player_situation[4][2]<=player_situation[4][0]*0.3 && player_situation[4][2]<=player_situation[4][1]*0.3 && player_situation[4][2]<=player_situation[4][2]*0.3 && player_situation[3][1] >0)
        {
            printf("玩家3選擇提款\n");
            withdraw1=rand()%(player_situation[3][2]);
            Sleep(slp2);
            printf("玩家3領了%d元...\n",withdraw1);
            player_situation[2][2]+=withdraw1;//現金增加
            player_situation[3][2]-=withdraw1;//存款減少
            Sleep(slp1);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
        }
        else
        {
            printf("玩家3對銀行視而不見...\n");
        }
    }
    else if(player_situation[1][2]==7 || player_situation[1][2]==15) //走到機會命運
    {
        printf("玩家3走到機會命運關\n");
        cod=rand()%65+1;
        chance_or_destiny(cod,2);
        Sleep(slp4);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        if(cod>=51 && cod<=60)
        {
            goto f23;
        }
        Sleep(slp1);
    }
    else if(land_situationl[1][player_situation[1][2]-1]!=103 && player_situation[1][2]!=3 && player_situation[1][2]!=7 && player_situation[1][2]!=15) //過路費
    {
        printf("玩家3走到其他人土地\n");
        if(player_situation[5][2]==0 && player[2]==4)
        {
            superpower(2,1000,4);
        }
        else if(player_situation[5][2]==0 && player[2]==9)
        {
            superpower(2,1000,9);
        }
        else
        {
            if(player_situation[2][2]>2500 && player_situation[4][2]>=player_situation[4][0]*0.6 && player_situation[4][2]>=player_situation[4][1]*0.6 && player_situation[4][2]>=player_situation[4][3]*0.6 )
        {
            printf("玩家3繳交過路費%d元\n",land_situationl[2][player_situation[1][2]-1]);
            if(land_situationl[2][player_situation[1][2]-1]>player_situation[2][2])
            {
                int gap=land_situationl[2][player_situation[1][2]-1]-player_situation[2][2];
                player_situation[2][2]=0;
                player_situation[3][2]-=gap;
                player_situation[3][land_situationl[1][player_situation[1][2]-1]-101]+=land_situationl[2][player_situation[1][2]-1];//地主收到過路費，存款增加
            }
            else
            {
                player_situation[2][2]-=land_situationl[2][player_situation[1][2]-1];
                player_situation[3][land_situationl[1][player_situation[1][2]-1]-101]+=land_situationl[2][player_situation[1][2]-1];//地主收到過路費，存款增加
            }
        }
        else if(player_situation[2][2]<=2500 && player_situation[4][2]>=player_situation[4][0]*0.6 && player_situation[4][2]>=player_situation[4][1]*0.6 && player_situation[4][2]>=player_situation[4][3]*0.6 )
        {
            printf("玩家3選擇闖關...");
            if(player[2]==1 && player_situation[5][2]==0)
            {
                printf("玩家3使用萬花筒寫輪眼!\n");
                superpower(2,1000,1);
            }
            attack_door(2);
        }
        else if(player_situation[2][2]<=2500 && player_situation[4][2]>=player_situation[4][0]*0.8 && player_situation[4][2]>=player_situation[4][1]*0.8 && player_situation[4][2]>=player_situation[4][3]*0.8 )
        {
            printf("玩家3選擇攻城...");
            attack_land(2,103);
        }
        else
        {
            printf("玩家3繳交過路費%d元\n",land_situationl[2][player_situation[1][2]-1]);
            if(land_situationl[2][player_situation[1][2]-1]>player_situation[2][2])
            {
                int gap=land_situationl[2][player_situation[1][2]-1]-player_situation[2][2];
                player_situation[2][2]=0;
                player_situation[3][2]-=gap;
                player_situation[3][land_situationl[1][player_situation[1][2]-1]-101]+=land_situationl[2][player_situation[1][2]-1];//地主收到過路費，存款增加
            }
            else
            {
                player_situation[2][2]-=land_situationl[2][player_situation[1][2]-1];
                player_situation[3][land_situationl[1][player_situation[1][2]-1]-101]+=land_situationl[2][player_situation[1][2]-1];//地主收到過路費，存款增加
            }
        }
        Sleep(slp1);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        }
    }
    else if(land_situationl[1][player_situation[1][2]-1]==103 && player_situation[1][2]!=3 && player_situation[1][2]!=7 && player_situation[1][2]!=15) //走到自己土地
    {
        if(player_situation[4][2]<= player_situation[4][0]*0.8 && player_situation[4][2]<= player_situation[4][1]*0.8 && player_situation[4][2]<= player_situation[4][3]*0.8) //電腦領取兵力
        {
            force_quanity=land_situationl[3][player_situation[1][2]-1]-500;
            if(force_quanity>0)
            {
                printf("玩家3選擇領取 %d 兵力\n",force_quanity);
                player_situation[4][2]+=force_quanity;
                land_situationl[3][player_situation[1][2]-1]-=force_quanity;
            }
        }
        else if(player_situation[4][2]>= player_situation[4][0]*1.2 && player_situation[4][2]>= player_situation[4][1]*1.2 && player_situation[4][2]>= player_situation[4][3]*1.2) //電腦存放兵力
        {
            int p1s=player_situation[4][0],p2s=player_situation[4][1],p3s=player_situation[4][3],maxs;
            maxs=p1s;
            if(p2s>maxs)        //比較其他三個玩家的兵力，取最大的出來，然後電腦存放與[最大的兵力]的差距的0.8
            {
                maxs=p2s;
                if(p3s>maxs)
                {
                    maxs=p3s;
                }
            }
            else if(p2s<=maxs)
            {
                if(p3s>maxs)
                {
                    maxs=p3s;
                }
            }
            force_quanity=(player_situation[4][2]-maxs)*0.8;
            printf("玩家3選擇存放 %d 兵力\n",force_quanity);
            player_situation[4][2]-=force_quanity;
            land_situationl[3][player_situation[1][2]-1]+=force_quanity;
        }
        else
        {
            printf("玩家3按兵不動...\n");
        }
    }
p3:
    Sleep(slp3);
    if(player_situation[5][2]>0)
    {
        player_situation[5][2]-=1;
    }
    Sleep(slp1);
    system("cls");
    world_print();
    print_situation();
    player_now_print();
    land_set();
}
void player4()
{
    printf("玩家4");
l4:
    if(lightning>0&&lightning<4)
    {
        printf("被皮卡丘電擊，全身麻痺無法動彈\n");
        lightning--;
        goto p4;
    }
    else if(lightning==0||lightning==4)
        {
            if(lightning==4)
            {
                lightning--;
            }
            if(player[3]==3 && player_situation[5][3]==0)//來來哥
            {
                if(((player_situation[1][3]-player_situation[1][1])<=-1 && (player_situation[1][3]-player_situation[1][1])>=-5) ||((player_situation[1][3]-player_situation[1][1])<=5 && (player_situation[1][3]-player_situation[1][1])>=1) ||((player_situation[1][3]-player_situation[1][1])<=15 && (player_situation[1][3]-player_situation[1][1])>=11))
                {
                    superpower(3,1,3);
                }
                else if(((player_situation[1][3]-player_situation[1][2])<=-1 && (player_situation[1][3]-player_situation[1][2])>=-5) ||((player_situation[1][3]-player_situation[1][2])<=5 && (player_situation[1][3]-player_situation[1][2])>=1) ||((player_situation[1][3]-player_situation[1][2])<=15 && (player_situation[1][3]-player_situation[1][2])>=11))
                {
                    superpower(3,2,3);
                }
                else if(((player_situation[1][3]-player_situation[1][0])<=-1 && (player_situation[1][3]-player_situation[1][0])>=-5) ||((player_situation[1][3]-player_situation[1][0])<=5 && (player_situation[1][3]-player_situation[1][0])>=1) ||((player_situation[1][3]-player_situation[1][0])<=15 && (player_situation[1][3]-player_situation[1][0])>=11))
                {
                    superpower(3,0,3);
                }
            }
            else if(player[3]==5 && player_situation[5][3]==0)
            {
                superpower(3,1000,5);
            }
            else if(player[3]==6 && player_situation[5][3]==0)
            {
                if(player_situation[1][3]==1) //站在第一格
                    {
                        if(land_situationl[1][15]==104 || land_situationl[1][1]==104)
                        {
                            superpower(3,1000,6);
                        }
                        else world(3);
                    }
                    else if(player_situation[1][3]==16) //站在第16格
                    {
                        if(land_situationl[1][0]==103 || land_situationl[1][14]==104)
                        {
                            superpower(3,1000,6);
                        }
                        else world(3);
                    }
                    else if(land_situationl[1][player_situation[1][3]]==104 || land_situationl[1][player_situation[1][3]-2]==104) //站在2~15格
                    {
                        superpower(3,1000,6);
                    }
                    else if(land_situationl[1][player_situation[1][3]]!=104 || land_situationl[1][player_situation[1][3]-2]!=104)
                    {
                        world(3);
                    }
            }
            else if(player[3]==7 && player_situation[5][3]==0)
            {
                superpower(3,1000,7);
                goto f24;
            }
            else if(player[3]==8 && player_situation[5][3]==0)
            {
                superpower(3,1000,8);
                goto l4;
            }
            else world(3);
        }
f24:
    Sleep(slp3);
    if(player_situation[1][3]==player_situation[1][0] || player_situation[1][3]==player_situation[1][1] || player_situation[1][3]==player_situation[1][2])//pk
    {
        printf("玩家4遇到對手了，進行pk\n");
        Sleep(slp3);
        if(player_situation[1][3]==player_situation[1][0])
        {
f10:
            if(player[0]==2 && player_situation[5][0]==0)
            {
                printf("是否使用\"死亡之握\"?(Y/N) :");
                scanf(" %c",&y_n);
                y_n=toupper(y_n);
                if(y_n=='Y')
                {
                    superpower(0,3,2);
                }
                else if(y_n=='N')
                {
                    printf("直接進入戰鬥!\n");
                }
                else goto f10;
            }
            gotoxy(0,0);
            pk_view();
            pk(3,0);
            printf("您損失%d兵力，",army_lose1);
            yew;
            printf("玩家4");
            wht;
            printf("損失%d兵力\n",army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1<army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("您損失較慘重，被玩家4劫走%d元\n",player_situation[2][0]);
                        player_situation[2][3]+=player_situation[2][0];
                        player_situation[2][0]=0;
                    }
                    else
                    {
                        printf("您損失較慘重，被玩家4劫走%d元\n",money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][3]+=money_lose;
                    }
                }
                else if(army_lose1>army_lose2)
                {
                    if(player_situation[2][3]<money_lose)
                    {
                        printf("玩家4損失較慘重，您火上加油打劫走%d元\n",player_situation[2][3]);
                        player_situation[2][0]+=player_situation[2][3];
                        player_situation[2][3]=0;
                    }
                    else
                    {
                        printf("玩家3損失較慘重，您火上加油打劫走%d元\n",money_lose);
                        player_situation[2][3]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }
                }
            else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        else if(player_situation[1][3]==player_situation[1][1])
        {
            if(player[3]==2 && player_situation[5][3]==0)
            {
                printf("玩家4使用死亡之握\n");
                superpower(3,1,2);

            }
            else if(player[1]==2 && player_situation[5][1]==0)
            {
                printf("玩家2使用死亡之握\n");
                superpower(1,3,2);
            }
            gotoxy(0,0);
            pk_view();
            pk(3,1);
            yew;
            printf("玩家4");
            wht;
            printf("損失%d兵力，",army_lose1);
            grn;
            printf("玩家2");
            wht;
            printf("損失%d兵力\n",army_lose2);
            money_lose=rand()%501+500;
              if(army_lose1>army_lose2)
                {
                    if(player_situation[2][3]<money_lose)
                    {
                        printf("玩家4損失較慘重，被玩家2劫走%d元\n",player_situation[2][3]);
                        player_situation[2][1]+=player_situation[2][3];
                        player_situation[2][3]=0;
                    }
                    else
                    {
                        printf("玩家4損失較慘重，被玩家2劫走%d元\n",money_lose);
                        player_situation[2][3]-=money_lose;
                        player_situation[2][1]+=money_lose;
                    }
                }
                else if(army_lose1<army_lose2)
                {
                    if(player_situation[2][1]<money_lose)
                    {
                        printf("玩家2損失較慘重，被玩家4劫走%d元\n",player_situation[2][1]);
                        player_situation[2][3]+=player_situation[2][1];
                        player_situation[2][1]=0;
                    }
                    else
                    {
                        printf("玩家2損失較慘重，被玩家4劫走%d元\n",money_lose);
                        player_situation[2][1]-=money_lose;
                        player_situation[2][3]+=money_lose;
                    }
                }
            else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        else if(player_situation[1][2]==player_situation[1][3])
        {
            if(player[2]==2 && player_situation[5][2]==0)
            {
                printf("玩家3使用死亡之握\n");
                superpower(2,3,2);

            }
            else if(player[3]==2 && player_situation[5][3]==0)
            {
                printf("玩家4使用死亡之握\n");
                superpower(3,2,2);
            }
            gotoxy(0,0);
            pk_view();
            pk(3,2);
            yew;
            printf("玩家4");
            wht;
            printf("損失%d兵力，",army_lose1);
            pur;
            printf("玩家3");
            wht;
            printf("損失%d兵力\n",army_lose2);
            money_lose=rand()%501+500;
              if(army_lose1>army_lose2)
                {
                    if(player_situation[2][3]<money_lose)
                    {
                        printf("玩家4損失較慘重，被玩家3劫走%d元\n",player_situation[2][3]);
                        player_situation[2][2]+=player_situation[2][3];
                        player_situation[2][3]=0;
                    }
                    else
                    {
                        printf("玩家4損失較慘重，被玩家3劫走%d元\n",money_lose);
                        player_situation[2][3]-=money_lose;
                        player_situation[2][2]+=money_lose;
                    }
                }
                else if(army_lose1<army_lose2)
                {
                    if(player_situation[2][2]<money_lose)
                    {
                        printf("玩家3損失較慘重，被玩家4劫走%d元\n",player_situation[2][2]);
                        player_situation[2][3]+=player_situation[2][2];
                        player_situation[2][2]=0;
                    }
                    else
                    {
                        printf("玩家3損失較慘重，被玩家4劫走%d元\n",money_lose);
                        player_situation[2][2]-=money_lose;
                        player_situation[2][3]+=money_lose;
                    }
                }
            else printf("損失兵力一樣，沒氣力去打劫另外一人...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
    }
    if(land_situationl[1][player_situation[1][3]-1]==0 && player_situation[1][3]!=3 && player_situation[1][3]!=7 && player_situation[1][3]!=15)
    {
        if(player_situation[2][3]>1500 ||
                (player_situation[1][3]==14 && player_situation[2][3]<1500 && player_situation[2][3]>500) ||
                (player_situation[1][3]==15 && player_situation[2][3]<1500 && player_situation[2][3]>500) ||
                (player_situation[1][3]==16 && player_situation[2][3]<1500 && player_situation[2][3]>500) ||
                (player_situation[1][3]==1 && player_situation[2][3]<1500 && player_situation[2][3]>500) ||
                (player_situation[1][3]==2 && player_situation[2][3]<1500 && player_situation[2][3]>500) ) //電腦如果金錢大於1500或雖然小於1500但預期將能在下個回合走到銀行，便會選擇佔領
        {
            printf("玩家4選擇購買土地\n");
            Sleep(slp1);
            money_cosume=money_change(1);
            if(money_cosume>player_situation[2][3])
            {
                printf("但玩家4發現手頭沒有足夠金錢因此作罷...\n");
                Sleep(slp3);
                system("cls");
                world_print();
                print_situation();
                player_now_print();
                land_set();
            }
            else
            {
                player_situation[2][3]-=money_cosume;
                printf("玩家4花費%d元佔領土地...",money_cosume);
                land_situationl[1][player_situation[1][3]-1]=104;
                Sleep(slp3);
                system("cls");
                world_print();
                print_situation();
                player_now_print();
                land_set();
            }
        }
        else if(player_situation[4][3]>1000 && player_situation[4][3]>=player_situation[4][0]*0.6 && player_situation[4][3]>=player_situation[4][1]*0.6 && player_situation[4][3]>=player_situation[4][2]*0.6) //如果兵力充足且相信跟其他玩家pk不致損失太多，就會攻佔
        {
            printf("玩家4選擇攻佔土地...\n");
            Sleep(slp2);
            attack_land(3,104);
        }
        else
        {
            printf("玩家4沒做任何動作...\n");
        }
    }
    else if(player_situation[1][3]==3) //走到銀行
    {
        if(player_situation[2][3]>2000)
        {
            printf("玩家4選擇存款\n");
            int save_prob=rand()%401+300;
            savemoney1=(player_situation[2][3]-2000)*save_prob/1000;
            Sleep(slp2);
            printf("玩家4存了%d元...\n",savemoney1);
            player_situation[2][3]-=savemoney1;//現金減少
            player_situation[3][3]+=savemoney1;//存款增加
            Sleep(slp1);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
        }
        else if(player_situation[2][3]<1000 && player_situation[4][3]<=player_situation[4][0]*0.3 && player_situation[4][3]<=player_situation[4][1]*0.3 && player_situation[4][3]<=player_situation[4][2]*0.3 && player_situation[3][1] >0)
        {
            printf("玩家4選擇提款\n");
            withdraw1=rand()%(player_situation[3][3]);
            Sleep(slp2);
            printf("玩家4領了%d元...\n",withdraw1);
            player_situation[2][3]+=withdraw1;//現金增加
            player_situation[3][3]-=withdraw1;//存款減少
            Sleep(slp1);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
        }
        else
        {
            printf("玩家4對銀行視而不見...\n");
        }
    }
    else if(player_situation[1][3]==7 || player_situation[1][3]==15) //走到機會命運
    {
        printf("玩家4走到機會命運關\n");
        cod=rand()%65+1;
        chance_or_destiny(cod,3);
        Sleep(slp4);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        if(cod>=51 && cod<=60)
        {
            goto f24;
        }
        Sleep(slp1);
    }
    else if(land_situationl[1][player_situation[1][3]-1]!=104 && player_situation[1][3]!=3 && player_situation[1][3]!=7 && player_situation[1][3]!=15) //過路費
    {
        printf("玩家4走到其他人土地\n");
        if(player_situation[5][3]==0 && player[3]==4)
        {
            superpower(3,1000,4);
        }
        else if(player_situation[5][3]==0 && player[3]==9)
        {
            superpower(3,1000,9);
        }
        else
        {
            if(player_situation[2][3]>2500 && player_situation[4][3]>=player_situation[4][0]*0.6 && player_situation[4][3]>=player_situation[4][1]*0.6 && player_situation[4][3]>=player_situation[4][2]*0.6 )
        {
            printf("玩家4繳交過路費%d元\n",land_situationl[2][player_situation[1][3]-1]);
            if(land_situationl[2][player_situation[1][3]-1]>player_situation[2][3])
            {
                int gap=land_situationl[2][player_situation[1][3]-1]-player_situation[2][3];
                player_situation[2][3]=0;
                player_situation[3][3]-=gap;
                player_situation[3][land_situationl[1][player_situation[1][3]-1]-101]+=land_situationl[2][player_situation[1][3]-1];//地主收到過路費，存款增加
            }
            else
            {
                player_situation[2][3]-=land_situationl[2][player_situation[1][3]-1];
                player_situation[3][land_situationl[1][player_situation[1][3]-1]-101]+=land_situationl[2][player_situation[1][3]-1];//地主收到過路費，存款增加
            }
        }
        else if(player_situation[2][3]<=2500 && player_situation[4][3]>=player_situation[4][0]*0.6 && player_situation[4][3]>=player_situation[4][1]*0.6 && player_situation[4][3]>=player_situation[4][2]*0.6 )
        {
            printf("玩家4選擇闖關...");
            if(player[3]==1 && player_situation[5][3]==0)
            {
                printf("玩家4使用萬花筒寫輪眼!\n");
                superpower(3,1000,1);
            }
            attack_door(3);
        }
        else if(player_situation[2][3]<=2500 && player_situation[4][3]>=player_situation[4][0]*0.8 && player_situation[4][3]>=player_situation[4][2]*0.8 && player_situation[4][3]>=player_situation[4][1]*0.8 )
        {
            printf("玩家4選擇攻城...");
            attack_land(3,104);
        }
        else
        {
            printf("玩家4繳交過路費%d元\n",land_situationl[2][player_situation[1][3]-1]);
            if(land_situationl[2][player_situation[1][3]-1]>player_situation[2][3])
            {
                int gap=land_situationl[2][player_situation[1][3]-1]-player_situation[2][3];
                player_situation[2][3]=0;
                player_situation[3][3]-=gap;
                player_situation[3][land_situationl[1][player_situation[1][3]-1]-101]+=land_situationl[2][player_situation[1][3]-1];//地主收到過路費，存款增加
            }
            else
            {
                player_situation[2][3]-=land_situationl[2][player_situation[1][3]-1];
                player_situation[3][land_situationl[1][player_situation[1][3]-1]-101]+=land_situationl[2][player_situation[1][3]-1];//地主收到過路費，存款增加
            }
        }
        Sleep(slp1);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        }
    }
    else if(land_situationl[1][player_situation[1][3]-1]==104 && player_situation[1][3]!=3 && player_situation[1][3]!=7 && player_situation[1][3]!=15) //走到自己土地
    {
        if(player_situation[4][3]<= player_situation[4][0]*0.8 && player_situation[4][3]<= player_situation[4][2]*0.8 && player_situation[4][3]<= player_situation[4][1]*0.8) //電腦領取兵力
        {
            force_quanity=land_situationl[3][player_situation[1][3]-1]-500;
            if(force_quanity>0)
            {
                printf("玩家4選擇領取 %d 兵力\n",force_quanity);
                player_situation[4][3]+=force_quanity;
                land_situationl[3][player_situation[1][3]-1]-=force_quanity;
            }
        }
        else if(player_situation[4][3]>= player_situation[4][0]*1.2 && player_situation[4][3]>= player_situation[4][2]*1.2 && player_situation[4][3]>= player_situation[4][1]*1.2) //電腦存放兵力
        {
            int p1s=player_situation[4][0],p2s=player_situation[4][1],p3s=player_situation[4][2],maxs;
            maxs=p1s;
            if(p2s>maxs)        //比較其他三個玩家的兵力，取最大的出來，然後電腦存放與[最大的兵力]的差距的0.8
            {
                maxs=p2s;
                if(p3s>maxs)
                {
                    maxs=p3s;
                }
            }
            else if(p2s<=maxs)
            {
                if(p3s>maxs)
                {
                    maxs=p3s;
                }
            }
            force_quanity=(player_situation[4][3]-maxs)*0.8;
            printf("玩家4選擇存放 %d 兵力\n",force_quanity);
            player_situation[4][3]-=force_quanity;
            land_situationl[3][player_situation[1][3]-1]+=force_quanity;
        }
        else
        {
            printf("玩家4按兵不動...\n");
        }
    }
    p4:
    Sleep(slp3);
    if(player_situation[5][3]>0)
    {
        player_situation[5][3]-=1;
    }
    Sleep(slp1);
    system("cls");
    world_print();
    print_situation();
    player_now_print();
    land_set();
}
