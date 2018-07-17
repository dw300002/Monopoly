#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#define red SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED); //�N�r��]������
#define wht SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)//�N�r��]���զ�
#define pur SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE) //�N�r��]������
#define grn SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE) //�N�r��]���C��
#define yew SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN)  //�N�r��]������
#define bgblue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_GREEN);  //�N�r��]���ź��
#define slp0 500
#define slp1 1000
#define slp2 1500
#define slp3 2000
#define slp4 4000
#define n 13
void world(int s); //���a�̪��^�X                                                  (�S���~)
void world_set(); //�N�g�a�]�w��0.1.2���Φ�                                        (�S���~)
void world_print(); //�ھ�world_set��0.1.2�L�X�۹������Ÿ��ή榡                   (�S���~)
void move_player(int s); //�ھڻ�l�Ƨ⪱�a����                                    (�S���~)
int dice(); //��l�I�Ƴ]�w                                                         (�S���~)
void start();  //�}�l�e��                                                          (�S���~)
void rules();  //�W�h                                                              (�d�ɸ�)
void player_choose(); //��ܨ���e��                                               (���ե�)
void print_detail(int a); //�L�X��ܨ���᪺�ݩ�                                   (���ե�)
void player1();//���a1��main                                                       (���ե�)
void player2();//���a2��AI                                                         (���ե�)
void player3();//���a3��AI                                                         (���ե�)
void player4();//���a4��AI                                                         (���ե�)
void print_situation();//�L�X����ثe�L�O����CD����T                              (���ե�)
void player_rule(int pr); //��b���a�̪���T��̭��A����F�ѥثe�O����}��         (���ե�)
void gotoxy(int xpos, int ypos);//���ʴ�Юy��                                     (�S���~)
void player_xy_switch(int a); //����a��b���椺�A���|���W�X���                 (�S���~)
void player_set();//�]�w��l����1.5.9.13                                           (�S���~)
void player_print(int p);//�L�X����                                                (�S���~)
void land_set();//��1~16����Ӫ��a�������                                         (���ե�)
void land_xy_switch(int ls); //�����l�����a�O�֨è̾ڪ��a�L�X�g�a�۹�����        (���ե�)
void chance_or_destiny(int cod,int man);//���|�R�B                                 (�@�P�@�_)
void player_now_print();//��1~16����Ӫ��a�������                                 (�S���~)
void superpower(int people,int people2, int ch_i);//�ϥε���                       (�@�P�@�_)
void attack_land(int al,int alp); //��                                           (�S���~)
void attack_door(int ad); //����                                                   (�S���~)
void you_win(); //��Ӯɵe��                                                       (�d�ɸ�)
void you_lose(); //�}���ɵe��                                                      (�d�ɸ�)
void you_win1(); //��Ӥ���                                                        (�d�ɸ�)
void you_win2(); //��Ӥ���                                                        (�d�ɸ�)
void you_lose1(); // �}������                                                      (�d�ɸ�)
void you_lose2(); // �}������                                                      (�d�ɸ�)
void pk(int pk1,int pk2);//pk                                                      (���ե�)
void pk_view();//pk����                                                            (�d�ɸ�)
void p();//pk����                                                                  (�d�ɸ�)
void p_k();//pk����                                                                (�d�ɸ�)
void fight1();//pk����                                                             (�d�ɸ�)
void fight2();//pk����                                                             (�d�ɸ�)
void fight3();//pk����                                                             (�d�ɸ�)
int i,j,x,y,z,w,a,cod;
int withdraw1=0,savemoney1=0; //�s�ڴ��ڪ��B
int lightning=0;//�֥d�C�·����˼�
char y_n; //yes no
int world1[n][n]= {0}; //�g�a�x�}
int player_situation[6][4]= {0}; //���a���s���B��m�B���B�B�s�ڡB�L�O�BCD
int land_situationl[4][16]= {0};//�g�a���s���B�Ҧ��̡B�L���O�B�����L�O
int force_quanity;//�L�O(���μW)
int player[4];//player[0]�N���a�Aplayer[1]�N��q��1�A�H��������q��3
int money_cosume=0;//��ܦ��⤧�᪺��O
int army_lose1=0,army_lose2=0,money_lose=0,money_gap=0; //pk�ɷl���L�O
int CD[10]= {0,8,10,8,10,9,5,4,7,6}; //���۪�CD
int main()                                                                       //(���ե�)
{
    start();
    rules();
    int l,u;
    int pl2l=0,pl3l=0,pl4l=0;

    char yn;//�����a���(Y/N)
    player_choose();
    do
    {
f1:
        printf("\n�п�ܨ���:");
        scanf("%d",&player[0]);
        if(player[0]>9 || player[0]<1)
        {
            printf("�п�J1~9!!\n");
        }
        else
        {
            printf("�T�{��ܨ��� %d? (Y/N):",player[i]);
            scanf(" %c",&yn);
            yn=toupper(yn);       //���J�ഫ���j�g
            if(yn=='Y')
            {
                printf("\n�A������:");
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
    printf("����q���﨤��F!\n");
    system("PAUSE");
    srand((unsigned)time(NULL));
    for(j=1; j<=3; j++) //��3��q��
    {
        int x;
f2:
        i++;
        player[i]=rand()%8+1;

        for(x=0; x<i; x++) //�ˬdplayer[i]���S���M�e���ҿ諸���⭫��
        {
            if(player[i]==player[x])
            {
                i--;
                goto f2;
            }
        }
        printf("\n�q��%d������:",j);
        print_detail(player[i]);
    }
    red;
    printf("\n�ǳƶ}�l�C��!!\n\n");
    wht;
    system("PAUSE");
    system("cls");
    /***************************�H�U�������i�J�C���ƭȪ�l��****************************/
    for(l=0; l<=3; l++) //CD�ȳ]�w
    {
        player_situation[5][l]=CD[player[l]];
    }
    for(l=0; l<=3; l++) //���a�����L�O��l��
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
    for(i=0; i<16; i++) //�����n�x
    {
        land_situationl[3][i]=1000;
    }
    /**************�}�l�C��***************/
g1:
    world_set();
    world_print();
    print_situation();
    player_set();
    do
    {

        if(player_situation[2][0]<=0 && player_situation[3][0]<=0)  //���a1�}��
        {

            printf("�z�w�g�S�������F...\n");
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
        else if((player_situation[2][1]<=0 && player_situation[3][1]<=0) && (player_situation[2][2]<=0 && player_situation[3][2]<=0) && (player_situation[2][3]<=0 && player_situation[3][3]<=0)) //��L���a�ү}���A���a1���
        {
            printf("��L���a�ү}���F!!!!!!\n");
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
        else if((player_situation[2][1]<=0 && player_situation[3][1]<=0) && (player_situation[2][2]<=0 && player_situation[3][2]<=0)) //���a2.3�}��
        {
            if(pl2l==0)
            {
                grn;
                printf("���a2�w�g�}��...\n���a2�g�a�N�Q�M��\n");
                player_situation[1][1]=-102;
                Sleep(slp3);
                wht;
                pl2l++;
            }
            if(pl3l==0)
            {
                pur;
                printf("���a3�w�g�}��...\n���a3�g�a�N�Q�M��\n");
                player_situation[1][2]=-103;
                Sleep(slp3);
                wht;
                pl3l++;
            }
            for(u=0; u<=15; u++) //�N���a2.3���g�a�M��
            {
                if(land_situationl[1][u]==102 ||land_situationl[1][u]==103)
                {
                    land_situationl[1][u]=0;
                }
            }
            for(u=0; u<=15; u++) //�N�g�a�L�O+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==104)
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("�z���^�X�����A���쪱�a4\n");
            player4();
            printf("���a4���^�X�����A���쪱�a1\n");
        }
        else if((player_situation[2][2]<=0 && player_situation[3][2]<=0) && (player_situation[2][3]<=0 && player_situation[3][3]<=0)) //���a3.4�}��
        {
            if(pl3l==0)
            {
                pur;
                printf("���a3�w�g�}��...\n���a3�g�a�N�Q�M��\n");
                player_situation[1][2]=-103;
                Sleep(slp3);
                wht;
                pl3l++;
            }
            if(pl4l==0)
            {
                yew;
                printf("���a4�w�g�}��...\n���a4�g�a�N�Q�M��\n");
                player_situation[1][3]=-104;
                Sleep(slp3);
                wht;
                pl4l++;
            }
            for(u=0; u<=15; u++) //�N���a4.3���g�a�M��
            {
                if(land_situationl[1][u]==103 ||land_situationl[1][u]==104)
                {
                    land_situationl[1][u]=0;
                }
            }
            for(u=0; u<=15; u++) //�N�g�a�L�O+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==102)
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("�z���^�X�����A���쪱�a2\n");
            player2();
            printf("���a2���^�X�����A���쪱�a1\n");
        }
        else if((player_situation[2][1]<=0 && player_situation[3][1]<=0) && (player_situation[2][3]<=0 && player_situation[3][3]<=0))//���a2.4�}��
        {
            if(pl2l==0)
            {
                grn;
                printf("���a2�w�g�}��...\n���a�g�a�N�Q�M��\n");
                player_situation[1][1]=-102;
                Sleep(slp3);
                wht;
                pl2l++;
            }
            if(pl4l==0)
            {
                yew;
                printf("���a4�w�g�}��...\n���a4�g�a�N�Q�M��\n");
                player_situation[1][3]=-104;
                Sleep(slp3);
                wht;
                pl4l++;
            }
            for(u=0; u<=15; u++) //�N���a2.4���g�a�M��
            {
                if(land_situationl[1][u]==102 ||land_situationl[1][u]==104)
                {
                    land_situationl[1][u]=0;
                }
            }
            for(u=0; u<=15; u++) //�N�g�a�L�O+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==103)
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("�z���^�X�����A���쪱�a3\n");
            player3();
            printf("���a3���^�X�����A���쪱�a1\n");
        }
        else if(player_situation[2][1]<=0 && player_situation[3][1]<=0) //���a2�}��
        {
            if(pl2l==0)
            {
                grn;
                printf("���a2�w�g�}��...\n���a2�g�a�N�Q�M��\n");
                player_situation[1][1]=-102;
                Sleep(slp3);
                wht;
                pl2l++;
            }
            for(u=0; u<=15; u++) //�N���a2���g�a�M��
            {
                if(land_situationl[1][u]==102)
                {
                    land_situationl[1][u]=0;
                }
            }
            for(u=0; u<=15; u++) //�N�g�a�L�O+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==103 || land_situationl[1][u]==104 )
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("�z���^�X�����A���쪱�a3\n");
            player3();
            printf("���a3���^�X�����A���쪱�a4\n");
            player4();
            printf("���a4���^�X�����A���쪱�a1\n");
        }
        else if(player_situation[2][2]<=0 && player_situation[3][2]<=0) //���a3�}��
        {
            if(pl3l==0)
            {
                pur;
                printf("���a3�w�g�}��...\n���a3�g�a�N�Q�M��\n");
                player_situation[1][2]=-103;
                Sleep(slp3);
                wht;
                pl3l++;
            }
            for(u=0; u<=15; u++) //�N���a3���g�a�M��
            {
                if(land_situationl[1][u]==103)
                {
                    land_situationl[1][u]=0;
                }
            }
            for(u=0; u<=15; u++) //�N�g�a�L�O+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==102 || land_situationl[1][u]==104 )
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("�z���^�X�����A���쪱�a2\n");
            player2();
            printf("���a2���^�X�����A���쪱�a4\n");
            player4();
            printf("���a4���^�X�����A���쪱�a1\n");
        }
        else if(player_situation[2][3]<=0 && player_situation[3][3]<=0) //���a4�}��
        {
            if(pl4l==0)
            {
                yew;
                printf("���a4�w�g�}��...\n���a4�g�a�N�Q�M��\n");
                player_situation[1][3]=-104;
                Sleep(slp3);
                wht;
                pl4l++;
            }
            for(u=0; u<=15; u++) //�N���a4���g�a�M��
            {
                if(land_situationl[1][u]==104)
                {
                    land_situationl[1][u]=0;
                }
            }
            for(u=0; u<=15; u++) //�N�g�a�L�O+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==102 || land_situationl[1][u]==103 )
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("�z���^�X�����A���쪱�a2\n");
            player2();
            printf("���a2���^�X�����A���쪱�a3\n");
            player3();
            printf("���a3���^�X�����A���쪱�a1\n");
        }
        else
        {
            for(u=0; u<=15; u++) //�N�g�a�L�O+100
            {
                if(land_situationl[1][u]==101 ||land_situationl[1][u]==103 || land_situationl[1][u]==104 || land_situationl[1][u]==102 )
                {
                    land_situationl[3][u]+=100;
                }
            }
            player1();
            printf("�z���^�X�����A���쪱�a2\n");
            player2();
            printf("���a2���^�X�����A���쪱�a3\n");
            player3();
            printf("���a3���^�X�����A���쪱�a4\n");
            player4();
            printf("���a4���^�X�����A���쪱�a1\n");
        }
    }
    while(1);
    return 0;
}
void player_choose()
{
    wht;
    printf("\t\t\t     ======������=====\t\t\t\n\n");
    printf(" �ССССССССССССССССССССССССССССССССССССС�\n�x");
    red;
    printf("1.�t���i���U\t\t");
    wht;
    printf(" �U");
    pur;
    printf("2.���^�Y\t\t");
    wht;
    printf("  �U");
    grn;
    printf("3.�Өӭ�\t\t ");
    wht;
    printf("   �U\n�x");
    red;
    printf("-�t���i�@�ڶȦs���̫�@");
    wht;
    printf("�U");
    pur;
    printf("-���ػʰꬰ�H��f���`��");
    wht;
    printf("�U");
    grn;
    printf("-����|�B�ʻᬰ�������k ");
    wht;
    printf("�U\n�U");
    red;
    printf(" �H�A�T�Ū��~��U���ñj");
    wht;
    printf("�U");
    pur;
    printf(",�k�����õ۷��j����q  ");
    wht;
    printf("�U");
    grn;
    printf(" �l,��f�Y�I���g����@��");
    wht;
    printf("�U\n�U");
    bgblue;
    printf("����:�U�ᵩ�g����");
    wht;
    printf("      �U");
    bgblue;
    printf("����:���`����");
    wht;
    printf("          �U");
    bgblue;
    printf("����:��������!");
    wht;
    printf("          �U\n�U");
    bgblue;
    printf("�����ɤ��ӷl�L�O,�B�i�H");
    wht;
    printf("�U");
    bgblue;
    printf("pk�ɵo�ʡA���L�O��b");
    wht;
    printf(" �U");
    bgblue;
    printf("�j��N�b�ۤv�᭱5�椺��");
    wht;
    printf(" �U\n�U");
    bgblue;
    printf("�ۭ�10�H�Ĥ諰���h�L");
    wht;
    printf("\t �U\t\t\t  �U");
    bgblue;
    printf("��Ⲿ�ʨ�ۤv�����");
    wht;
    printf("    �U\n�U");
    bgblue;
    printf("CD:8");
    wht;
    printf("\t\t\t �U");
    bgblue;
    printf("CD:10");
    wht;
    printf("\t\t  �U");
    bgblue;
    printf("CD:8");
    wht;
    printf("\t\t    �U\n�U\t\t\t �U\t\t\t  �U\t\t\t    �U\n �ССССССССССССССССССССССССССССССССССССС�\n�U");
    grn;
    printf("4.�B���k�����\t");
    wht;
    printf(" �U");
    red;
    printf("5.�ɦ���\t\t");
    wht;
    printf("  �U");
    yew;
    printf("6.�|��\t\t");
    wht;
    printf("    �U\n�U");
    grn;
    printf("-�Ӯa�I��,�ۥ��K�֦��B");
    wht;
    printf(" �U");
    red;
    printf("-�ɳ������ƪ�,\"�ݿ��p�R");
    wht;
    printf("�U");
    yew;
    printf("-�߻}������������k�H,�~");
    wht;
    printf("�U\n�U");
    grn;
    printf(" ���]�k�A�P�ɾ֦��@�Ʀn");
    wht;
    printf("�U");
    red;
    printf("�A���^�Ҥu\"�����N�O�L");
    wht;
    printf("  �U");
    yew;
    printf(" ���󽦪G�����䨭��I�� ");
    wht;
    printf("�U\n�U");
    grn;
    printf(" �q��\t\t\t ");
    wht;
    printf("�U\t\t\t  �U");
    yew;
    printf(" �u��\t\t    ");
    wht;
    printf("�U\n�U");
    bgblue;
    printf("����:LET IT GO");
    wht;
    printf("\t �U");
    bgblue;
    printf("����:�����ɳ�");
    wht;
    printf("\t  �U");
    bgblue;
    printf("����:���Y�ۦp���󽦤�j");
    wht;
    printf(" �U\n�U");
    bgblue;
    printf("�i��U�@���O�H���g�a");
    wht;
    printf("   �U");
    bgblue;
    printf("��@����l�A�N�{�����W");
    wht;
    printf(" �U");
    bgblue;
    printf("�Y�ۤv��a�b�e�Ϋ�@��,");
    wht;
    printf(" �U\n�U\t\t\t �U");
    bgblue;
    printf("\"1+(0.1*���I��)\"");
    wht;
    printf("\t  �U");
    bgblue;
    printf("�i�ɥR�L�O");
    wht;
    printf("\t\t    �U\n�U");
    bgblue;
    printf("CD:10");
    wht;
    printf("\t\t\t �U");
    bgblue;
    printf("CD:9");
    wht;
    printf("\t\t\t  �U");
    bgblue;
    printf("CD:5");
    wht;
    printf("\t\t    �U\n�U\t\t\t �U\t\t\t  �U\t\t\t    �U\n �ССССССССССССССССССССССССССССССССССССС�\n�U");
    pur;
    printf("7.����\t\t");
    wht;
    printf(" �U");
    yew;
    printf("8.�֥d�C\t\t");
    wht;
    printf("  �U");
    red;
    printf("9.�]����\t\t");
    wht;
    printf("    �U\n�U");
    pur;
    printf("-�p���������̧̡A�ܤ� ");
    wht;
    printf(" �U");
    yew;
    printf("-���S�b���O���q��ѹ�, ");
    wht;
    printf("�U");
    red;
    printf("-�ɨȤH��ź��,�`�b�@�ɦM");
    wht;
    printf("�U\n�U");
    pur;
    printf(" �L�a�A�i�ƨ�������H");
    wht;
    printf("  �U");
    yew;
    printf(" ���U���|���i���Ͱ����q");
    wht;
    printf("�U");
    red;
    printf(" ���ɸѱϦa�y\t");
    wht;
    printf("    �U\n�U");
    bgblue;
    printf("����:�ۼv");
    wht;
    printf("\t\t �U");
    bgblue;
    printf("����:�Q�U��S");
    wht;
    printf("\t  �U");
    bgblue;
    printf("����:����u");
    wht;
    printf("\t\t    �U\n�U");
    bgblue;
    printf("�i���w���ʨ�Y�@��,�d��");
    wht;
    printf("�U");
    bgblue;
    printf("�����·��@�^�X");
    wht;
    printf("\t  �U");
    bgblue;
    printf("�i�H�F���@���g�a");
    wht;
    printf("\t    �U\n�U");
    bgblue;
    printf("���ۨ���m�e��T��");
    wht;
    printf("\t �U\t\t\t  �U\t\t\t    �U\n�U");
    bgblue;
    printf("CD:4");
    wht;
    printf("\t\t\t �U");
    bgblue;
    printf("CD:7");
    wht;
    printf("\t\t\t  �U");
    bgblue;
    printf("CD:6");
    wht;
    printf("\t\t    �U\n�U\t\t\t �U\t\t\t  �U\t\t\t    �U\n �ССССССССССССССССССССССССССССССССССССС�");
}
void print_detail(int a)
{
    switch(a)
    {
    case 1:
        printf("�t���i���U\n");
        printf("���ۡG�U�ᵩ�g����(�����ɤ��ӷl�L�O�A�B�i�H�ۭ�10�H�Ĥ諰���h�L)\n");
        printf("CD�ȡG8\n");
        break;
    case 2:
        printf("���^�Y\n");
        printf("���ۡG���`����(pk�ɵo�ʡA���L�O��b)\n");
        printf("CD�ȡG10\n");
        break;
    case 3:
        printf("�Өӭ�\n");
        printf("���ۡG��������!(�j��N�b�ۤv�᭱5�椺����Ⲿ�ʨ�ۤv�����)\n");
        printf("CD�ȡG8\n");
        break;
    case 4:
        printf("�B���k�����\n");
        printf("���ۡGLET IT GO(�i��U�@���O�H���g�a)\n");
        printf("CD�ȡG10\n");
        break;
    case 5:
        printf("�ɦ���\n");
        printf("���ۡG�����ɳ�(���W���{�����H(1+0.1*��l�I��))\n");
        printf("CD�ȡG9\n");
        break;
    case 6:
        printf("�|��\n");
        printf("���ۡG���Y�ۦp���󽦤�j(�Y�ۤv��a�b�e�Ϋ�@��A�i�ɥR�L�O)\n");
        printf("CD�ȡG5\n");
        break;
    case 7:
        printf("����\n");
        printf("���ۡG�ۼv(�i���w���ʨ�Y�@��A�d�򬰦ۨ���m�e��T��)\n");
        printf("CD�ȡG4\n");
        break;
    case 8:
        printf("�֥d�C\n");
        printf("���ۡG�Q�U��S(�����·��@�^�X)\n");
        printf("CD�ȡG7\n");
        break;
    case 9:
        printf("�]����\n");
        printf("���ۡG����u(�i�H�F���@���g�a)\n");
        printf("CD�ȡG6\n");
        break;
    }
}
void start()
{
    printf("                               \n");
    printf("                   �w��Ө�ð��j�I��                    \n");
    printf("    \n");
    printf("    �b�o�̧A�ݭn                  --------------------        \n");
    printf("                                /                    / |      \n");
    printf("                              /     ability        /   |      \n");
    printf("                            /                    /     |      \n");
    printf("                          /       ��O         /       |      \n");
    printf("                        /                    /         |      \n");
    printf("                        --------------------    force  |      \n");
    printf("                       |                    |          |      \n");
    printf("                       |                    |    �ɤO  |      \n");
    printf("                       |                    |          |      \n");
    printf("                       |       fortune      |          |      \n");
    printf("                       |                    |         /       \n");
    printf("                       |                    |       /         \n");
    printf("                       |        �]�O        |     /           \n");
    printf("                       |                    |   /             \n");
    printf("                       |                    | /               \n");
    printf("                        --------------------                  \n");
    printf("\n");
    printf("\n");
    printf("                                          �d�ɸ��B���ե��B�S���v�p�X�s�@\n");
    printf("\n");
    system("pause");
    system("cls");
}
void rules()
{
    printf("###################�C���W�h###################\n\n");
    printf("1. �C�Ӫ��a���_�l�{���B�L�O�ҬۦP�C\n\n");
    printf("2. ����Ȧ�i�s�ڡC\n\n");
    printf("3. ����Ťg�a�i�β{���ΧL�O�C\n\n");
    printf("4. ����O�H�g�a���I�L���O�A\n");
    printf("   �ΥH�L�O�j��q�L�C\n\n");
    printf("5. ��Ӫ��a�P�ɦb�P�@�g�a�|�i��PK�A\n");
    printf("   ��a�|�Q�m�T�{���C\n\n");
    printf("6. ����ۤv��a�i�H����L�O�C\n\n");
    printf("7. ��l�W�h�p�@��j�I�ιC���C\n");
    system("PAUSE");
    system("cls");
}
void world(int s)
{
    srand((unsigned) time(NULL));

    a=dice();
    printf("��l�I��:%d\n",a);
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
    player_situation[1][s]++;//����+1
    if(player_situation[1][s]>16)//�p�G����W�L16�^��@���s�p��
    {
        player_situation[1][s]=1;
    }
    player_xy_switch(player_situation[1][0]);//��ɪ�����
    player_print(1);
    player_xy_switch(player_situation[1][1]);//�O������
    player_print(2);
    player_xy_switch(player_situation[1][2]);//�O������
    player_print(3);
    player_xy_switch(player_situation[1][3]);//�O������
    player_print(4);
}
void player_xy_switch(int s)//�����ഫ�A�o�Ӥ�k���֤�
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
        printf("��");
        wht;
        break;
    case 2:
        grn;
        printf("��");
        wht;
        break;
    case 3:
        pur;
        printf("��");
        wht;
        break;
    case 4:
        yew;
        printf("��");
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
            printf("��");
            wht;
        }
        else if(land_situationl[1][0]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][0]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][0]==104)
        {
            yew;
            printf("��");
            wht;
        }
        else printf("��");
    }
    else if(ls==2)
    {
        gotoxy(8,0);
        if(land_situationl[1][1]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][1]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][1]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][1]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==3)
    {
        gotoxy(12,0);
        if(land_situationl[1][2]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][2]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][2]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][2]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==4)
    {
        gotoxy(16,0);
        if(land_situationl[1][3]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][3]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][3]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][3]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==5)
    {
        gotoxy(24,2);
        if(land_situationl[1][4]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][4]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][4]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][4]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==6)
    {
        gotoxy(24,4);
        if(land_situationl[1][5]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][5]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][5]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][5]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==7)
    {
        gotoxy(24,6);
        if(land_situationl[1][6]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][6]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][6]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][6]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==8)
    {
        gotoxy(24,8);
        if(land_situationl[1][7]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][7]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][7]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][7]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==9)
    {
        gotoxy(20,12);
        if(land_situationl[1][8]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][8]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][8]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][8]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==10)
    {
        gotoxy(16,12);
        if(land_situationl[1][9]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][9]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][9]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][9]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==11)
    {
        gotoxy(12,12);
        if(land_situationl[1][10]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][10]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][10]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][10]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==12)
    {
        gotoxy(8,12);
        if(land_situationl[1][11]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][11]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][11]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][11]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==13)
    {
        gotoxy(0,10);
        if(land_situationl[1][12]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][12]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][12]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][12]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==14)
    {
        gotoxy(0,8);
        if(land_situationl[1][13]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][13]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][13]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][13]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==15)
    {
        gotoxy(0,6);
        if(land_situationl[1][14]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][14]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][14]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][14]==104)
        {
            yew;
            printf("��");
            wht;
        }
    }
    else if(ls==16)
    {
        gotoxy(0,4);
        if(land_situationl[1][15]==101)
        {
            red;
            printf("��");
            wht;
        }
        else if(land_situationl[1][15]==102)
        {
            grn;
            printf("��");
            wht;
        }
        else if(land_situationl[1][15]==103)
        {
            pur;
            printf("��");
            wht;
        }
        else if(land_situationl[1][15]==104)
        {
            yew;
            printf("��");
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
            world1[i][j]=1;//�N����d��ƭ��ܬ�1
        }

    }
    for(j=1; j<n-3; j++)
    {
        if(j%2==0)//���Ʈ�̭������ܦ�0  �~���[�W2
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
            x=world1[i-1][j];//�w��W�U���k
            y=world1[i+1][j];
            z=world1[i][j-1];
            w=world1[i][j+1];
            if(world1[i][j]==0)//���Ь�0�L�X�Ů�
            {
                printf("  ");
            }
            else if(world1[i][j]==1)//���Ь��@�P�_�W�U���k
            {
                if(x==1&&y==1&&z==1&&w==1)
                {
                    printf("�q");
                }
                else if(x!=1&&y!=1&&z==1&&w==1)
                {
                    printf("�w");
                }
                else if(x==1&&y==1&&z!=1&&w!=1)
                {
                    printf("�x");
                }
                else if(x!=1&&y==1&&z==1&&w==1)
                {
                    printf("�s");
                }
                else if(x==1&&y!=1&&z==1&&w==1)
                {
                    printf("�r");
                }
                else if(x==1&&y==1&&z!=1&&w==1)
                {
                    printf("�u");
                }
                else if(x==1&&y==1&&z==1&&w!=1)
                {
                    printf("�t");
                }
                else if(x==1&&y==1&&z!=1&&w!=1)
                {
                    printf("�x");
                }
                else if(x==1&&y!=1&&z==1&&w!=1)
                {
                    printf("�}");
                }
                else if(x==1&&y!=1&&z!=1&&w==1)
                {
                    printf("�|");
                }
                else if(x!=1&&y==1&&z==1&&w!=1)
                {
                    printf("�{");
                }
                else
                {
                    printf("�z");
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
                printf("�H");
                wht;
            }
            else//���O�s�άO�@�Y���g�a
            {
                printf("��");
            }
        }
        printf("\n");
    }
}
void print_situation()
{

    printf("-------------------------------------------------------------------------------\n");
    red;
    printf("���a1 ");
    player_rule(player[0]);
    wht;
    printf("|");
    grn;
    printf("���a2 ");
    player_rule(player[1]);
    wht;
    printf("|");
    pur;
    printf("���a3 ");
    player_rule(player[2]);
    wht;
    printf("|");
    yew;
    printf("���a4 ");
    player_rule(player[3]);
    wht;
    printf("                    |                   |                   |                   \n");
    printf("    �{��:%5d     |    �{��:%5d     |    �{��:%5d     |    �{��:%5d\n",player_situation[2][0],player_situation[2][1],player_situation[2][2],player_situation[2][3]);
    printf("    �s��:%5d     |    �s��:%5d     |    �s��:%5d     |    �s��:%5d\n",player_situation[3][0],player_situation[3][1],player_situation[3][2],player_situation[3][3]);
    printf("    �L�O:%5d     |    �L�O:%5d     |    �L�O:%5d     |    �L�O:%5d\n",player_situation[4][0],player_situation[4][1],player_situation[4][2],player_situation[4][3]);
    printf("      CD:%5d     |      CD:%5d     |      CD:%5d     |      CD:%5d\n",player_situation[5][0],player_situation[5][1],player_situation[5][2],player_situation[5][3]);
}
void player_rule(int pr)
{
    switch(pr)
    {
    case 1:
        printf("�t���i���U   ");
        break;
    case 2:
        printf("���^�Y       ");
        break;
    case 3:
        printf("�Өӭ�       ");
        break;
    case 4:
        printf("�B���k����� ");
        break;
    case 5:
        printf("�ɦ���       ");
        break;
    case 6:
        printf("�|��         ");
        break;
    case 7:
        printf("����         ");
        break;
    case 8:
        printf("�֥d�C       ");
        break;
    case 9:
        printf("�]����       ");
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
    case 1: //�e���O
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
        printf("���߱z���F�ֳz�j��!\n");
        int lottery=rand()%10+1;
        if(lottery>=1 && lottery<=4)
        {
            printf("�������{��100��\n");
            player_situation[2][man]+=100;
        }
        else if(lottery>=5 && lottery<=7)
        {
            printf("�������{��500��\n");
            player_situation[2][man]+=500;
        }
        else if(lottery>=8 && lottery<=9)
        {
            printf("�������{��1000��\n");
            player_situation[2][man]+=1000;
        }
        else if(lottery==10)
        {
            printf("�������{��5000��\n");
            player_situation[2][man]+=5000;
        }
    }

    else if(cod>=6 && cod<=20)
    {
        printf("��´�󥭤ơA����&�]��A___A(�L�O���2���A�����W�[5�w)\n");
        player_situation[4][man]*=0.8;
        player_situation[2][man]*=1.05;

    }
    else if(cod>=21&&cod<=25)
    {
        printf("���ĭ��ɡA�p�ҥS�̭˳��A�Ȧ�j���v�T(�Ҧ��H�s�ڴ�b)\n");
        for(i=0; i<4; i++)
        {
            player_situation[3][i]=player_situation[3][i]/2;
        }
    }
    else if(cod>=26&&cod<=40)
    {
        printf("�A�֤F��?���Ҩq�p���p�@�h�Ӯ����z���h��!(�L�O�W�[)\n");
        int med=rand()%10+1;
        if(med>=1 && med<=4)
        {
            printf("�L�O�W�[100\n");
            player_situation[4][man]+=100;
        }
        else if(med>=5 && med<=7)
        {
            printf("�L�O�W�[500\n");
            player_situation[4][man]+=500;
        }
        else if(med>=8 && med<=9)
        {
            printf("�L�O�W�[1000\n");
            player_situation[4][man]+=1000;
        }
        else if(med==10)
        {
            printf("�L�O�W�[5000\n");
            player_situation[4][man]+=5000;
        }
    }

    else if(cod>=41&&cod<=45)
    {
        printf("���ũжU�A�л��j�^(�Ҧ��g�a�L���O��b)\n");
        for(i=0; i<16; i++)
        {
            land_situationl[2][i]=land_situationl[2][i]/2;
        }
    }
    else if(cod>=46 && cod<=50)
    {
        printf("�̮𾮯��A���餦�СA�o�ۥs���A�ڶ}�j��(����CD�k0�A�i�ϥε��ۤF!)\n");
        player_situation[5][man]=0;
    }
    else if(cod>=51 && cod<=60)
    {
        printf("��ʰ�j�A���߱z��o�Q�K�Ծ��|�@��!(�i�A�Y�@����l)\n");
        world(man);
    }

    else if(cod>=61&&cod<=65)
    {
        printf("�L�A�X���A�`�Ϊ�Z���P������Ĳ�A�j�a���`�δ��Ӥ�(�����H�L�O��b)\n");
        for(i=0; i<4; i++)
        {
            player_situation[4][i]=player_situation[4][i]/2;
        }
    }
}
void attack_land(int al,int alp)//��
{
    int force_prob=(player_situation[4][al]-land_situationl[3][player_situation[1][al]-1])/200+50;//�o�����\���v�A�p�G�۵����ܾ��v�O50%�A�t�Z�C�j200�[1%
    int force_decrease = (rand()%5+4)*land_situationl[3][player_situation[1][al]-1]/10;//�H���ӷl30%~70%�������L�O

    if(force_prob>rand()%100+1)
    {
        printf("����o~\n");
        if(player_situation[4][al]<force_decrease)
        {
            player_situation[4][al]=0;
        }
        else
        {
            player_situation[4][al]-=force_decrease;
        }
        land_situationl[3][player_situation[1][al]-1]=500;//��e����_�l�L�O��500
        land_situationl[1][player_situation[1][al]-1]=alp;
    }
    else
    {
        printf("��e���ѡA�ФWú�L���O\n");
        if(player_situation[4][al]<force_decrease)
        {
            player_situation[4][al]=0;
        }
        else
        {
            player_situation[4][al]-=force_decrease;
        }
        if(land_situationl[1][player_situation[1][al]-1] == 101 || land_situationl[1][player_situation[1][al]-1] == 102 || land_situationl[1][player_situation[1][al]-1] == 103 || land_situationl[1][player_situation[1][al]-1] == 104)//���H���g�a
        {
            if(land_situationl[2][player_situation[1][al]-1]>player_situation[2][al]) //��W�{�������A�q�Ȧ榩
            {
                int gap1=land_situationl[2][player_situation[1][al]-1]-player_situation[2][al];
                player_situation[2][al]=0;
                player_situation[3][al]-=gap1;
                player_situation[3][land_situationl[1][player_situation[1][al]-1]-101]+=land_situationl[2][player_situation[1][al]-1];//���L�ᵹ�a�D�s��
            }
            else //�q�⤤�{������
            {
                player_situation[2][al]-=land_situationl[2][player_situation[1][al]-1];
                player_situation[3][land_situationl[1][player_situation[1][al]-1]-101]+=land_situationl[2][player_situation[1][al]-1];//���L�ᵹ�a�D�s��
            }
        }
        else if(land_situationl[1][player_situation[1][al]-1] == 0) //�Ťg�a
        {
            if(land_situationl[2][player_situation[1][al]-1]>player_situation[2][al]) //��W�{�������A�q�Ȧ榩
            {
                int gap2=land_situationl[2][player_situation[1][al]-1]-player_situation[2][al];
                player_situation[2][al]=0;
                player_situation[3][al]-=gap2;
            }
            else //�q�⤤�{������
            {
                player_situation[2][al]-=land_situationl[2][player_situation[1][al]-1];//���L�ᵹ�a�D�s��
            }
        }
        Sleep(slp2);
    }
}
void attack_door(int ad)//����
{
    int force_prob=(player_situation[4][ad]-land_situationl[3][player_situation[1][ad]-1])/600+50;// 1/3�������L�O
    int force_decrease = (rand()%5+4)*land_situationl[3][player_situation[1][ad]-1]/30;// �ӷl�]�ܬ�1/3
    if(force_prob>rand()%100+1)
    {
        printf("�����F���A�K���L���O\n");
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
        printf("�������ѡA�[���L���O\n");
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
            int gap3=land_situationl[2][player_situation[1][ad]-1]-player_situation[2][ad]+300;//�������ѥ[��300��
            player_situation[2][ad]=0;
            player_situation[3][ad]-=gap3;
            player_situation[3][land_situationl[1][player_situation[1][ad]-1]-101]+=(land_situationl[2][player_situation[1][ad]-1]+300);//���L�ᵹ�a�D�s��
        }
        else
        {
            player_situation[2][ad]-=(land_situationl[2][player_situation[1][ad]-1]+300);//�������ѥ[��300��
            player_situation[3][land_situationl[1][player_situation[1][ad]-1]-101]+=(land_situationl[2][player_situation[1][ad]-1]+300);//���L�ᵹ�a�D�s��
        }
    }
    Sleep(slp2);
}
void pk(pk1,pk2)
{
    if((player_situation[4][pk2]*0.15)>player_situation[4][pk1]) //player[pk]�l���j��ۨ��L�O�A�h�l���ܬ��ۨ��L�O
    {
        army_lose1=player_situation[4][pk1];
    }
    else if((player_situation[4][pk2]*0.15)<=player_situation[4][pk1])//player[pk]�l���p�󵥩�ۨ��L�O�A�h�l�����`
    {
        army_lose1=(player_situation[4][pk2]*0.15);
    }
    if((player_situation[4][pk1]*0.15)>player_situation[4][pk2]) //player[pk]�l���j��ۨ��L�O�A�h�l���ܬ��ۨ��L�O
    {
        army_lose2=player_situation[4][pk2];
    }
    else if((player_situation[4][pk1]*0.15)<=player_situation[4][pk2])//player[pk]�l���p�󵥩�ۨ��L�O�A�h�l�����`
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
    case 1: //�t���i���U����
        printf("���a%d�o�ʵ���\n",people+1);
        Sleep(slp3);
        printf("�U�ᵩ�g����!���Q�����éۭ������h�L1��\n");
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
        printf("���^�Y�ϥΦ��`�����A���L�O��b...\n");
        player_situation[4][people2]/=2;
        Sleep(slp4);
        gotoxy(0,21);
        player_situation[5][people]=CD[player[people]];
        break;
    case 3:
        if(people==0)//���a�O�Өӭ�
        {you_come_count=0;
f11:
        if(you_come_count<=3)
        {
            printf("�n�N���Ӫ��a�ԹL��?(�ۤv�e�����椺�����a):");
            scanf("%d", &you_come);
            if(you_come<=0 || you_come>4)
            {
                printf("�п�J���a2~4\n");
                goto f11;
            }
            else
            {
                distance = player_situation[1][people]-player_situation[1][(you_come)-1];
                if((distance<=-1 && distance>=-5) || (distance>=11 && distance <=15))
                {
                    red;
                    printf("��");
                    Sleep(slp1);
                    printf("��");
                    Sleep(slp1);
                    printf("��");
                    Sleep(slp1);
                    printf("��\n");
                    Sleep(slp1);
                    wht;
                    player_situation[1][(you_come)-1]=player_situation[1][people];
                    system("cls");
                    world_print();
                    print_situation();
                    player_now_print();
                    land_set();
                    Sleep(slp1);
                    printf("���a%d�Q�A�l�޹L�ӡA�ǳ�pk!",you_come);
                    Sleep(slp4);
                    system("cls");
                pk_view();
                pk(0,(you_come-1));
                printf("�z�l��%d�L�O�A",army_lose1);
                if(you_come==2)
                {
                    grn;
                    printf("���a2");
                }
                else if(you_come==3)
                {
                    pur;
                    printf("���a3");
                }
                else if(you_come==4)
                {
                    yew;
                    printf("���a4");
                }
                wht;
                printf("�l��%d�L�O\n",army_lose2);
                Sleep(slp2);
                money_lose=rand()%501+500;
                if(army_lose1>army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("�z�l�����G���A�Q���a%d�T��%d��\n",you_come,player_situation[2][0]);
                        player_situation[2][0]=0;
                        player_situation[2][(you_come)-1]+=player_situation[2][0];
                    }
                    else
                    {
                        printf("�z�l�����G���A�Q���a%d�T��%d��\n",you_come,money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][(you_come)-1]+=money_lose;
                    }
                }
                else if(army_lose1<army_lose2)
                {
                    if(player_situation[2][(you_come)-1]<money_lose)
                    {
                        printf("���a%d�l�����G���A�z���W�[�o���T��%d��\n",you_come,player_situation[2][(you_come)-1]);
                        player_situation[2][(you_come)-1]=0;
                        player_situation[2][0]+=player_situation[2][(you_come)-1];
                    }
                    else
                    {
                        printf("���a%d�l�����G���A�z���W�[�o���T��%d��\n",you_come,money_lose);
                        player_situation[2][(you_come)-1]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }
                }
                else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
                Sleep(slp4);
                gotoxy(0,13);
                print_situation();
                Sleep(slp3);
                }
                else
                {
                    printf("�z���w�����a���b����d�򤺳�!\n");
                    you_come_count++;
                    goto f11;
                }
            }
        }
        else
        {
            printf("�Өӭ���J���~3���F�A�n�R�O��...!\n");
            Sleep(slp3);
        }
        }
        else //�q���O�Өӭ� �A�P�_�bplayer�U�۪�function��
        {
            printf("���a%d�o�ʵ���\n",people+1);
            Sleep(slp3);
            player_situation[1][people2]=player_situation[1][people];
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
            Sleep(slp1);
            printf("���a%d�Q���a%d�l�ި�ۤv��m�i�Jpk!\n",people2+1,people+1);
            Sleep(slp4);
            system("cls");
            pk_view();
            pk(people,people2);
            printf("���a%d�l��%d�L�O�A",people+1,army_lose1);
            printf("���a%d�l��%d�L�O\n",people2+1,army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1>army_lose2)
            {

                if(player_situation[2][people]<money_lose)
                {
                    printf("���a%d�l�����G���A�Q���a%�T��%d��\n",people,people2, player_situation[2][people]);
                    player_situation[2][people2]+=player_situation[2][people];
                    player_situation[2][people]=0;
                }
                else
                {
                    printf("���a%d�l�����G���A�Q���a%�T��%d��\n",people,people2,money_lose);
                    player_situation[2][people]-=money_lose;
                    player_situation[2][people2]+=money_lose;
                }
            }
            else if(army_lose1<army_lose2)
            {

                if(player_situation[2][people2]<money_lose)
                {
                    printf("���a%d�l�����G���A�Q���a%d�T��%d��\n",people2,people,player_situation[2][people2]);
                    player_situation[2][people]+=player_situation[2][people2];
                    player_situation[2][people2]=0;
                }
                else
                {
                    printf("���a%d�l�����G���A�Q���a%d�T��%d��\n",people2,people,money_lose);
                    player_situation[2][people2]-=money_lose;
                    player_situation[2][people]+=money_lose;
                }
            }
            else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
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
    case 4: //�P�_�bmain
        printf("\n���a%d�o�ʵ���\n",people+1);
        Sleep(slp3);
        printf("���W������A����let it go~~");
        Sleep(slp2);
        printf("let it go�A���g�a�k���a%d�Ҧ�\n",people+1);
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
        printf("���a%d�o�ʵ���\n",people+1);
        Sleep(slp3);
        gotoxy(0,21);
        printf("�ɦ������������۶W�G�Q��...\n�ϥά����ɳ��A��@����l�ñN���W�{�����W(1+0.1*��l�I��)!\n");
        super_dice=dice();
        Sleep(slp3);
        printf("��l�I��:%d\n",super_dice);
        Sleep(slp3);
        player_situation[2][people]*=(1+(0.1*super_dice));
        printf("���a%d�����ܦ�%d",people+1,player_situation[2][people]);
        Sleep(slp3);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        Sleep(slp2);
        player_situation[5][people]=CD[player[people]];
        break;
    case 6: //�P�_�e����O�_���ۤv�����O�bmain
        if(people==0)//���a
        {
f12:
            printf("�n��e���٬O�᭱�������L?  1.�e�� 2.�᭱: ");
            scanf("%d",&army_6);
            if(army_6!=1 && army_6!=2)
            {
                printf("�п�J1.�e�� �άO 2.�᭱\n");
                goto f12;
            }
            else if(army_6==1)
            {
                if(player_situation[1][people]==16 && land_situationl[1][0]==101)
                {
                    printf("�����h�L�ثe��%d�A�n��h��? :",land_situationl[3][0]);
                    scanf("%d",&force_quanity);
                    if(force_quanity>land_situationl[3][0] || force_quanity<=0)
                    {
                        printf("��J�Ʀr���~!\n");
                        goto f12;
                    }
                    else
                    {
                        printf("�|�Ҧ�������A��ۤv��a���L��L�ӸɥR�F!\n");
                        player_situation[4][people]+=force_quanity;
                        land_situationl[3][0]-=force_quanity;
                    }
                }
                else if(land_situationl[1][player_situation[1][people]]==101)
                {
                    printf("�����h�L�ثe��%d�A�n��h��? :",land_situationl[3][player_situation[1][people]]);
                    scanf("%d",&force_quanity);
                    if(force_quanity>land_situationl[3][player_situation[1][people]] || force_quanity<=0)
                    {
                        printf("��J�Ʀr���~!\n");
                        goto f12;
                    }
                    else
                    {
                        printf("�|�Ҧ�������A��ۤv��a���L��L�ӸɥR�F!\n");
                        player_situation[4][people]+=force_quanity;
                        land_situationl[3][player_situation[1][people]]-=force_quanity;
                    }
                }
            else
            {
                printf("�e�����g�a���O�z��!\n");
                goto f12;
            }
            }
            else if(army_6==2)
            {
                if(player_situation[1][people]==1 && land_situationl[1][15]==101)
                {
                    printf("�����h�L�ثe��%d�A�n��h��? :",land_situationl[3][15]);
                    scanf("%d",&force_quanity);
                    if(force_quanity>land_situationl[3][15] || force_quanity<=0)
                    {
                        printf("��J�Ʀr���~!\n");
                        goto f12;
                    }
                    else
                    {
                        printf("�|�Ҧ�������A��ۤv��a���L��L�ӸɥR�F!\n");
                        player_situation[4][people]+=force_quanity;
                        land_situationl[3][15]-=force_quanity;
                    }
                }
                else if(land_situationl[1][player_situation[1][people]-2]==101)
                {
                    printf("�����h�L�ثe��%d�A�n��h��? :",land_situationl[3][player_situation[1][people]-2]);
                    scanf("%d",&force_quanity);
                    if(force_quanity>land_situationl[3][player_situation[1][people]-2] || force_quanity<=0)
                    {
                        printf("��J�Ʀr���~!\n");
                        goto f12;
                    }
                    else
                    {
                        printf("�|�Ҧ�������A��ۤv��a���L��L�ӸɥR�F!\n");
                        player_situation[4][people]+=force_quanity;
                        land_situationl[3][player_situation[1][people]-2]-=force_quanity;
                    }
                }
                else
                {
                    printf("�᭱���g�a���O�z��!\n");
                    goto f12;
                }
            }
        }
        else //�q��
        {
            if(player_situation[1][people]==16)//�q����16
            {
                army_6=rand()%1+1;
                if(army_6==1 && (land_situationl[1][0]-101)==people)
                    {
                        printf("�|�Ҧ�������A��ۤv��a���L��L�ӸɥR�F!\n");
                        force_quanity=land_situationl[3][0]*0.5;
                        player_situation[4][people]+=force_quanity;
                        land_situationl[3][0]-=force_quanity;
                    }
                else if((land_situationl[1][player_situation[1][people]]-101)==people)
                {
                     force_quanity=land_situationl[3][player_situation[1][people]]*0.5;
                     printf("�|�Ҧ�������A��ۤv��a���L��L�ӸɥR�F!\n");
                     player_situation[4][people]+=force_quanity;
                     land_situationl[3][player_situation[1][people]]-=force_quanity;
                }
            }
            else if(player_situation[1][people]==1)//�q����1
            {
                army_6=rand()%1+1;
                if(army_6==2 && (land_situationl[1][15]-101)==people)
                 {
                        force_quanity=land_situationl[3][15]*0.5;
                        printf("�|�Ҧ�������A��ۤv��a���L��L�ӸɥR�F!\n");
                        player_situation[4][people]+=force_quanity;
                        land_situationl[3][15]-=force_quanity;
                }
                else if((land_situationl[1][player_situation[1][people]-2]-101)==people)
                {
                    force_quanity=land_situationl[3][player_situation[1][people]-2]*0.5;
                     printf("�|�Ҧ�������A��ۤv��a���L��L�ӸɥR�F!\n");
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
                     printf("�|�Ҧ�������A��ۤv��a���L��L�ӸɥR�F!\n");
                     player_situation[4][people]+=force_quanity;
                     land_situationl[3][player_situation[1][people]]-=force_quanity;
                }
                else if((land_situationl[1][player_situation[1][people]-2]-101)==people)
                {
                    force_quanity=land_situationl[3][player_situation[1][people]-2]*0.5;
                     printf("�|�Ҧ�������A��ۤv��a���L��L�ӸɥR�F!\n");
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
        if(people==0)//���a
        {
            printf("�п�J�Q���ʪ��Z��(-3~+3):");
            scanf("%d",&Loki);
            if(Loki>3 || Loki<-3)
            {
                printf("��J���~!\n");
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
        else//�q��
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
         printf("\n���a%d�o�ʵ���\n",people+1);
        Sleep(slp3);
       printf("����N�ۤv�ĤJ������A�åB�X�{�b�t�@�Ӱϰ�");
       Sleep(slp3);
       system("cls");
       world_print();
        print_situation();
        player_now_print();
        land_set();
        Sleep(slp2);
        printf("���򲾰�%d��\n",Loki);
        Sleep(slp4);
        system("cls");
       world_print();
        print_situation();
        player_now_print();
        land_set();
        player_situation[5][people]=CD[player[people]];
        break;
    case 8:
        printf("\n���a%d�o�ʵ���\n",people+1);
        Sleep(slp3);
        printf("��~");
        Sleep(slp1);
        printf("�d~");
        Sleep(slp1);
        printf("��~~~~~~~~~~~~~~~~\n");
        Sleep(slp1);
        printf("��L���a����j�P���q���ӵL�k�ʼu�A�·��@�^�X\n");
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
        printf("���a%d�o�ʵ���\n",people+1);
        Sleep(slp3);
        printf("�׶��F�������O�q�A���Ŵ¥L���Ҧb�a�ϥX����u�A�N�Ӧa�Ϧi�����a");
        land_situationl[1][player_situation[1][people]-1]=0;
        Sleep(slp4);
        system("cls");
        world_print();
        print_situation();
        player_now_print();
        land_set();
        printf("�g�a�w�g�ܦ��Ŧa\n");
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
    printf("��    ��    ��\n");
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
    printf("��    ��    ��\n");
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
    printf("                          |   ��    ��   |\n");
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
    printf("                          |   ��    ��   |\n");
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
    printf("            |  �� ___ ��  |   |         |   |  >  ___  <  |       \n");
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
    printf("            |  >       <  |     /     \\     |  �� ___ ��  |      \n");
    printf("        0---|   �z�s�s�{  |---0         0---|   �z�s�s�{  |---0         \n");
    printf("            |   �|�r�r�}  | /             \\ |   �|�r�r�}  |            \n");
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
        printf("�Q�֥d�C�q���A�����·��L�k�ʼu\n");
        lightning--;
        goto p1;
    }
    else if(lightning==0||lightning==4)
    {
        if(lightning==4)//4�N��O�񵴩۪��H
        {
            lightning--;
        }
    }
    printf("player1���: 1.���l 2.���� :");
    scanf("%d",&choose);
    if(choose==1)
    {
        world(0);
f21:
        if(player_situation[1][0]==player_situation[1][1] || player_situation[1][0]==player_situation[1][2] || player_situation[1][0]==player_situation[1][3])//pk
        {
            printf("�J����F�A�i��pk�@�M�ӭt!\n");
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
                    printf("�O�_�ϥ�\"���`����\"?(Y/N) :");
                    scanf(" %c",&y_n);
                    y_n=toupper(y_n);
                    if(y_n=='Y')
                    {
                        superpower(0,1,2);
                    }
                    else if(y_n=='N')
                    {
                        printf("���ϥ�...!\n");
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
                printf("�z�l��%d�L�O�A",army_lose1);
                grn;
                printf("���a2");
                wht;
                printf("�l��%d�L�O\n",army_lose2);
                money_lose=rand()%501+500;
                if(army_lose1>army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("�z�l�����G���A�Q���a2�T��%d��\n",player_situation[2][0]);
                        player_situation[2][1]+=player_situation[2][0];
                        player_situation[2][0]=0;

                    }
                    else
                    {
                        printf("�z�l�����G���A�Q���a2�T��%d��\n",money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][1]+=money_lose;
                    }

                }
                else if(army_lose1<army_lose2)
                {

                    if(player_situation[2][1]<money_lose)
                    {
                        printf("���a2�l�����G���A�z���W�[�o���T��%d��\n",player_situation[2][1]);
                        player_situation[2][0]+=player_situation[2][1];
                        player_situation[2][1]=0;
                    }
                    else
                    {
                        printf("���a2�l�����G���A�z���W�[�o���T��%d��\n",money_lose);
                        player_situation[2][1]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }

                }
                else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
                Sleep(slp4);
                gotoxy(0,13);
                print_situation();
                Sleep(slp3);
            }
            else if(player_situation[1][0]==player_situation[1][2])
            {
                if(player[0]==2 && player_situation[5][0]==0)
                {
                    printf("�O�_�ϥ�\"���`����\"?(Y/N) :");
                    scanf(" %c",&y_n);
                    y_n=toupper(y_n);
                    if(y_n=='Y')
                    {
                        superpower(0,2,2);
                    }
                    else if(y_n=='N')
                    {
                        printf("�����i�J�԰�!\n");
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
                printf("�z�l��%d�L�O�A",army_lose1);
                pur;
                printf("���a3");
                wht;
                printf("�l��%d�L�O\n",army_lose2);
                money_lose=rand()%501+500;
               if(army_lose1>army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("�z�l�����G���A�Q���a3�T��%d��\n",player_situation[2][0]);
                        player_situation[2][2]+=player_situation[2][0];
                        player_situation[2][0]=0;

                    }
                    else
                    {
                        printf("�z�l�����G���A�Q���a3�T��%d��\n",money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][2]+=money_lose;
                    }

                }
                else if(army_lose1<army_lose2)
                {

                    if(player_situation[2][2]<money_lose)
                    {
                        printf("���a3�l�����G���A�z���W�[�o���T��%d��\n",player_situation[2][2]);
                        player_situation[2][0]+=player_situation[2][2];
                        player_situation[2][2]=0;
                    }
                    else
                    {
                        printf("���a3�l�����G���A�z���W�[�o���T��%d��\n",money_lose);
                        player_situation[2][2]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }

                }
                else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
                Sleep(slp4);
                gotoxy(0,13);
                print_situation();
                Sleep(slp3);
            }
            else if(player_situation[1][0]==player_situation[1][3])
            {
                if(player[0]==2 && player_situation[5][0]==0)
                {
                    printf("�O�_�ϥ�\"���`����\"?(Y/N) :");
                    scanf(" %c",&y_n);
                    y_n=toupper(y_n);
                    if(y_n=='Y')
                    {
                        superpower(0,3,2);
                    }
                    else if(y_n=='N')
                    {
                        printf("�����i�J�԰�!\n");
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
                printf("�z�l��%d�L�O�A",army_lose1);
                yew;
                printf("���a4");
                wht;
                printf("�l��%d�L�O\n",army_lose2);
                money_lose=rand()%501+500;
                if(army_lose1>army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("�z�l�����G���A�Q���a4�T��%d��\n",player_situation[2][0]);
                        player_situation[2][3]+=player_situation[2][0];
                        player_situation[2][0]=0;

                    }
                    else
                    {
                        printf("�z�l�����G���A�Q���a4�T��%d��\n",money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][3]+=money_lose;
                    }

                }
                else if(army_lose1<army_lose2)
                {

                    if(player_situation[2][3]<money_lose)
                    {
                        printf("���a4�l�����G���A�z���W�[�o���T��%d��\n",player_situation[2][3]);
                        player_situation[2][0]+=player_situation[2][3];
                        player_situation[2][3]=0;
                    }
                    else
                    {
                        printf("���a4�l�����G���A�z���W�[�o���T��%d��\n",money_lose);
                        player_situation[2][3]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }

                }
                else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
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
            printf("�z�n�ϥΨӨӭ����۶�? (Y/N):");
            scanf(" %c",&y_n);
            y_n=toupper(y_n);
            if(y_n=='Y')
            {
                superpower(0,1000,3);
            }
        }
        if (land_situationl[1][player_situation[1][0]-1]==0 && player_situation[1][0]!=3 && player_situation[1][0]!=7 && player_situation[1][0]!=15) //���D�ū�
        {
            money_cosume=money_change(1);
f3:
            printf("���g�a�a����%d���A�����n�x%d�H�A�A�n1.�ʶR? 2.��e? 3.���} :",money_cosume,land_situationl[3][player_situation[1][0]-1]);
            scanf("%d",&land_choose);
            switch(land_choose)
            {
            case 1:
                if(player_situation[2][0]<money_cosume)
                {
                    printf("�z���Y�{��������...\n");
                    goto f3;
                }
                else
                {
                    land_situationl[1][player_situation[1][0]-1]=101;
                    player_situation[2][0]-=money_cosume;
                    printf("��O%d���e��g�a...\n",money_cosume);
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
                printf("��J���~\n");
                goto f3;
            }
        }
        else if(player_situation[1][0]==3) //����Ȧ�
        {
f4:
            printf("�аݧA�n1.���? 2.�s��? 3.���}\n");
            int while_bank_choose;
            scanf("%d",&while_bank_choose);
            switch(while_bank_choose)
            {
            case 1:
            {
                printf("�п�J���ڪ��B:");
                scanf("%d",&withdraw1);
                if(withdraw1>player_situation[3][0] || withdraw1<=0)
                {
                    printf("���ڪ��B���~!\n");
                    goto f4;
                }
                else
                {
                    player_situation[2][0]+=withdraw1;//�{���W�[
                    player_situation[3][0]-=withdraw1;//�s�ڴ��
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
                printf("�п�J�s�ڪ��B:");
                scanf("%d",&savemoney1);
                if(savemoney1>player_situation[2][0] || savemoney1<=0)
                {
                    printf("�s�ڪ��B���~!\n");
                    goto f4;
                }
                else
                {
                    player_situation[2][0]-=savemoney1;//�{�����
                    player_situation[3][0]+=savemoney1;//�s�ڼW�[
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
                printf("���´f�U�w��U���A��~\n");
                break;
            }
            default:
            {
                printf("�п�J���T�ﶵ!\n");
                goto f4;
                break;
            }
            }
        }
        else if(player_situation[1][0]==7 || player_situation[1][0]==15) //������|�R�B
        {
            int cod;
            printf("���|�R�B��!\n");
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
        else if(land_situationl[1][player_situation[1][0]-1]!=101 && player_situation[1][0]!=3 && player_situation[1][0]!=7 && player_situation[1][0]!=15) //�L���O
        {
f5:
            if(player_situation[5][0]==0 && player[0]==4)
            {
                printf("�O�_�ϥΦB���k����ﵴ��? (Y/N) :");
                scanf(" %c",&y_n);
                y_n=toupper(y_n);
                if(y_n=='Y')
                {
                    superpower(0,1000,4);
                }
            }
            else if(player_situation[5][0]==0 && player[0]==9)
            {
                printf("�O�_�ϥή]���ŵ���? (Y/N) :");
                scanf(" %c",&y_n);
                y_n=toupper(y_n);
                if(y_n=='Y')
                {
                    superpower(0,1000,9);
                }
            }
            else
            {
                printf("���g�a�L���O��%d�A�����n�x��%d�A�A�n1.�I�L���O? 2.����? 3.��?\n",land_situationl[2][player_situation[1][0]-1],land_situationl[3][player_situation[1][0]-1]);
            scanf("%d",&land_choose2);
            switch(land_choose2)
            {
            case 1:
                if(land_situationl[2][player_situation[1][0]-1]>player_situation[2][0])
                {
                    int gap=land_situationl[2][player_situation[1][0]-1]-player_situation[2][0];
                    player_situation[2][0]=0;
                    player_situation[3][0]-=gap;
                    player_situation[3][land_situationl[1][player_situation[1][0]-1]-101]+=land_situationl[2][player_situation[1][0]-1];//�a�D����L���O�A�s�ڼW�[
                }
                else
                {
                    player_situation[2][0]-=land_situationl[2][player_situation[1][0]-1];
                    player_situation[3][land_situationl[1][player_situation[1][0]-1]-101]+=land_situationl[2][player_situation[1][0]-1];//�a�D����L���O�A�s�ڼW�[
                }
                break;
            case 2:
                if(player[0]==1 && player_situation[5][0]==0)
                {
                    printf("�O�_�ϥΦt���i����--�U�ᵩ�g����?:\n");
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
                printf("��J���~");
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
        else if(land_situationl[1][player_situation[1][0]-1]==101 && player_situation[1][0]!=3 && player_situation[1][0]!=7 && player_situation[1][0]!=15) //����ۤv�g�a
        {
f6:
            printf("�ثe�����n�x%d�H�A1.����L�O 2.�s��L�O 3.���} :\n",land_situationl[3][player_situation[1][0]-1]);
            scanf("%d",&land_choose3);
            if(land_choose3==1)
            {
                printf("�п�J����L�O�ƶq�G");
                scanf("%d",&force_quanity);
                if(force_quanity>0 && force_quanity <= land_situationl[3][player_situation[1][0]-1])
                {
                    player_situation[4][0]+=force_quanity;
                    land_situationl[3][player_situation[1][0]-1]-=force_quanity;
                }
                else
                {
                    printf("��J�L�O�Ʀr���~\n");
                    goto f6;
                }
            }
            else if(land_choose3==2)
            {
                printf("�п�J�s��L�O�ƶq�G");
                scanf("%d",&force_quanity);
                if(force_quanity<=player_situation[4][0] && force_quanity>0)
                {
                    player_situation[4][0]-=force_quanity;
                    land_situationl[3][player_situation[1][0]-1]+=force_quanity;
                }
                else
                {
                    printf("��J�L�O�Ʀr���~\n");
                    goto f6;
                }
            }
            else if(land_choose3!=1 && land_choose3 !=2 && land_choose3 !=3)
            {
                printf("��J���~!");
                goto f6;
            }
        }
    }
    else if(choose==2)
       {
            if(player_situation[5][0]==0) //���ۤw�g�ǳƦn
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
                    if(player_situation[1][0]==1) //���b�Ĥ@��
                    {
                        if(land_situationl[1][15]==101 || land_situationl[1][1]==101)
                        {
                            superpower(0,1000,6);
                        }
                        else printf("�e����S���z����a\n");
                        Sleep(slp2);
                        system("cls");
                        world_print();
                        print_situation();
                        player_now_print();
                        land_set();
                        player1();
                    }
                    else if(player_situation[1][0]==16) //���b��16��
                    {
                        if(land_situationl[1][0]==101 || land_situationl[1][14]==101)
                        {
                            superpower(0,1000,6);
                        }
                        else printf("�e����S���z����a\n");
                        Sleep(slp2);
                        system("cls");
                        world_print();
                        print_situation();
                        player_now_print();
                        land_set();
                        player1();
                    }
                    else if(land_situationl[1][player_situation[1][0]]==101 || land_situationl[1][player_situation[1][0]-2]==101) //���b2~15��
                    {
                        superpower(0,1000,6);
                    }
                    else if(land_situationl[1][player_situation[1][0]]!=101 || land_situationl[1][player_situation[1][0]-2]!=101)
                    {
                        printf("�e����S���z����a\n");
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
            else if(player_situation[5][0]>0) //���۩|���ǳƦn��
            {
                printf("�����٨S�ǳƦn");
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
    printf("���a2");
l2:
    if(lightning>0&&lightning<4)
        {
            printf("�Q�֥d�C�q���A�����·��L�k�ʼu\n");
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
                if(player_situation[1][1]==1) //���b�Ĥ@��
                    {
                        if(land_situationl[1][15]==102 || land_situationl[1][1]==102)
                        {
                            superpower(1,1000,6);
                        }
                        else world(1);
                    }
                    else if(player_situation[1][1]==16) //���b��16��
                    {
                        if(land_situationl[1][0]==102 || land_situationl[1][14]==102)
                        {
                            superpower(1,1000,6);
                        }
                        else world(1);
                    }
                    else if(land_situationl[1][player_situation[1][1]]==102 || land_situationl[1][player_situation[1][1]-2]==102) //���b2~15��
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
        printf("���a2�J����F�A�i��pk\n");
        Sleep(slp3);
        if(player_situation[1][1]==player_situation[1][0])
        {
f8:
            if(player[0]==2 && player_situation[5][0]==0)
            {
                printf("�O�_�ϥ�\"���`����\"?(Y/N) :");
                scanf(" %c",&y_n);
                y_n=toupper(y_n);
                if(y_n=='Y')
                {
                    superpower(0,1,2);
                }
                else if(y_n=='N')
                {
                    printf("�����i�J�԰�!\n");
                }
                else goto f8;
            }
            gotoxy(0,0);
            pk_view();
            pk(1,0);
            printf("�z�l��%d�L�O�A",army_lose1);
            grn;
            printf("���a2");
            wht;
            printf("�l��%d�L�O\n",army_lose2);
            money_lose=rand()%501+500;
           if(army_lose1<army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("�z�l�����G���A�Q���a2�T��%d��\n",player_situation[2][0]);
                        player_situation[2][1]+=player_situation[2][0];
                        player_situation[2][0]=0;

                    }
                    else
                    {
                        printf("�z�l�����G���A�Q���a2�T��%d��\n",money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][1]+=money_lose;
                    }

                }
                else if(army_lose1>army_lose2)
                {

                    if(player_situation[2][1]<money_lose)
                    {
                        printf("���a2�l�����G���A�z���W�[�o���T��%d��\n",player_situation[2][1]);
                        player_situation[2][0]+=player_situation[2][1];
                        player_situation[2][1]=0;
                    }
                    else
                    {
                        printf("���a2�l�����G���A�z���W�[�o���T��%d��\n",money_lose);
                        player_situation[2][1]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }
                }
            else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        else if(player_situation[1][1]==player_situation[1][2])
        {
            if(player[1]==2 && player_situation[5][1]==0)
            {
                printf("���a2�ϥΦ��`����\n");
                superpower(1,2,2);

            }
            else if(player[2]==2 && player_situation[5][2]==0)
            {
                printf("���a3�ϥΦ��`����\n");
                superpower(2,1,2);
            }
            gotoxy(0,0);
            pk_view();
            pk(1,2);
            grn;
            printf("���a2");
            wht;
            printf("�l��%d�L�O�A",army_lose1);
            pur;
            printf("���a3");
            wht;
            printf("�l��%d�L�O\n",army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1>army_lose2)
                {
                    if(player_situation[2][1]<money_lose)
                    {
                        printf("���a2�l�����G���A�Q���a3�T��%d��\n",player_situation[2][0]);
                        player_situation[2][2]+=player_situation[2][1];
                        player_situation[2][1]=0;

                    }
                    else
                    {
                        printf("���a2�l�����G���A�Q���a3�T��%d��\n",money_lose);
                        player_situation[2][1]-=money_lose;
                        player_situation[2][2]+=money_lose;
                    }

                }
                else if(army_lose1<army_lose2)
                {

                    if(player_situation[2][2]<money_lose)
                    {
                        printf("���a3�l�����G���A�Q���a2�T��%d��\n",player_situation[2][2]);
                        player_situation[2][1]+=player_situation[2][2];
                        player_situation[2][2]=0;
                    }
                    else
                    {
                        printf("���a3�l�����G���A�Q���a2�T��%d��\n",money_lose);
                        player_situation[2][2]-=money_lose;
                        player_situation[2][1]+=money_lose;
                    }
                }
            else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        else if(player_situation[1][1]==player_situation[1][3])
        {
            if(player[1]==2 && player_situation[5][1]==0)
            {
                printf("���a2�ϥΦ��`����\n");
                superpower(1,3,2);

            }
            else if(player[2]==2 && player_situation[5][2]==0)
            {
                printf("���a4�ϥΦ��`����\n");
                superpower(3,1,2);
            }
            gotoxy(0,0);
            pk_view();
            pk(1,3);
            grn;
            printf("���a2");
            wht;
            printf("�l��%d�L�O�A",army_lose1);
            yew;
            printf("���a4");
            wht;
            printf("�l��%d�L�O\n",army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1>army_lose2)
                {
                    if(player_situation[2][1]<money_lose)
                    {
                        printf("���a2�l�����G���A�Q���a4�T��%d��\n",player_situation[2][1]);
                        player_situation[2][3]+=player_situation[2][1];
                        player_situation[2][1]=0;

                    }
                    else
                    {
                        printf("���a2�l�����G���A�Q���a4�T��%d��\n",money_lose);
                        player_situation[2][1]-=money_lose;
                        player_situation[2][3]+=money_lose;
                    }
                }
                else if(army_lose1<army_lose2)
                {
                    if(player_situation[2][3]<money_lose)
                    {
                        printf("���a4�l�����G���A�Q���a2�T��%d��\n",player_situation[2][3]);
                        player_situation[2][1]+=player_situation[2][3];
                        player_situation[2][3]=0;
                    }
                    else
                    {
                        printf("���a4�l�����G���A�Q���a2�T��%d��\n",money_lose);
                        player_situation[2][3]-=money_lose;
                        player_situation[2][1]+=money_lose;
                    }
                }
            else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
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
                (player_situation[1][1]==2 && player_situation[2][1]<1500 && player_situation[2][1]>500) ) //�q���p�G�����j��1500�����M�p��1500���w���N��b�U�Ӧ^�X����Ȧ�A�K�|��ܦ���
        {
            printf("���a2����ʶR�g�a\n");
            Sleep(slp1);
            money_cosume=money_change(1);
            if(money_cosume>player_situation[2][1])
            {
                printf("�����a2�o�{���Y�S�����������]���@�}...\n");
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
                printf("���a2��O%d������g�a...",money_cosume);
                land_situationl[1][player_situation[1][1]-1]=102;
                Sleep(slp3);
                system("cls");
                world_print();
                print_situation();
                player_now_print();
                land_set();
            }
        }
        else if(player_situation[4][1]>1000 && player_situation[4][1]>=player_situation[4][0]*0.6 && player_situation[4][1]>=player_situation[4][2]*0.6 && player_situation[4][1]>=player_situation[4][3]*0.6) //�p�G�L�O�R���B�۫H���L���apk���P�l���Ӧh�A�N�|���
        {
            printf("���a2��ܧ���g�a...\n");
            Sleep(slp2);
            attack_land(1,102);
        }
        else
        {
            printf("���a2�S������ʧ@...\n");
        }
    }
    else if(player_situation[1][1]==3) //����Ȧ�
    {
        if(player_situation[2][1]>2000)
        {
            printf("���a2��ܦs��\n");
            int save_prob=rand()%401+300;
            savemoney1=(player_situation[2][1]-2000)*save_prob/1000;
            Sleep(slp2);
            printf("���a2�s�F%d��...\n",savemoney1);
            player_situation[2][1]-=savemoney1;//�{�����
            player_situation[3][1]+=savemoney1;//�s�ڼW�[
            Sleep(slp1);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
        }
        else if(player_situation[2][1]<1000 && player_situation[4][1]<=player_situation[4][0]*0.3 && player_situation[4][1]<=player_situation[4][2]*0.3 && player_situation[4][1]<=player_situation[4][3]*0.3 && player_situation[3][1] >0)
        {
            printf("���a2��ܴ���\n");
            withdraw1=rand()%(player_situation[3][1]);
            Sleep(slp2);
            printf("���a2��F%d��...\n",withdraw1);
            player_situation[2][1]+=withdraw1;//�{���W�[
            player_situation[3][1]-=withdraw1;//�s�ڴ��
            Sleep(slp1);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
        }
        else
        {
            printf("���a2��Ȧ���Ӥ���...\n");
        }
    }
    else if(player_situation[1][1]==7 || player_situation[1][1]==15) //������|�R�B
    {
        printf("���a2������|�R�B��\n");
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
    else if(land_situationl[1][player_situation[1][1]-1]!=102 && player_situation[1][1]!=3 && player_situation[1][1]!=7 && player_situation[1][1]!=15) //�L���O
    {
        printf("���a2�����L�H�g�a\n");
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
            printf("���a2ú��L���O%d��\n",land_situationl[2][player_situation[1][1]-1]);
            if(land_situationl[2][player_situation[1][1]-1]>player_situation[2][1])
            {
                int gap=land_situationl[2][player_situation[1][1]-1]-player_situation[2][1];
                player_situation[2][1]=0;
                player_situation[3][1]-=gap;
                player_situation[3][land_situationl[1][player_situation[1][1]-1]-101]+=land_situationl[2][player_situation[1][1]-1];//�a�D����L���O�A�s�ڼW�[
            }
            else
            {
                player_situation[2][1]-=land_situationl[2][player_situation[1][1]-1];
                player_situation[3][land_situationl[1][player_situation[1][1]-1]-101]+=land_situationl[2][player_situation[1][1]-1];//�a�D����L���O�A�s�ڼW�[
            }
        }
        else if(player_situation[2][1]<=2500 && player_situation[4][1]>=player_situation[4][0]*0.6 && player_situation[4][1]>=player_situation[4][2]*0.6 && player_situation[4][1]>=player_situation[4][3]*0.6 )
        {
            printf("���a2�������...");
            if(player[1]==1 && player_situation[5][1]==0)
            {
                printf("���a2�ϥθU�ᵩ�g����!\n");
                superpower(1,1000,1);
            }
            attack_door(1);
        }
        else if(player_situation[2][1]<=2500 && player_situation[4][1]>=player_situation[4][0]*0.8 && player_situation[4][1]>=player_situation[4][2]*0.8 && player_situation[4][1]>=player_situation[4][3]*0.8 )
        {
            printf("���a2��ܧ�...");
            attack_land(1,102);
        }
        else
        {
            printf("���a2ú��L���O%d��\n",land_situationl[2][player_situation[1][1]-1]);
            if(land_situationl[2][player_situation[1][1]-1]>player_situation[2][1])
            {
                int gap=land_situationl[2][player_situation[1][1]-1]-player_situation[2][1];
                player_situation[2][1]=0;
                player_situation[3][1]-=gap;
                player_situation[3][land_situationl[1][player_situation[1][1]-1]-101]+=land_situationl[2][player_situation[1][1]-1];//�a�D����L���O�A�s�ڼW�[
            }
            else
            {
                player_situation[2][1]-=land_situationl[2][player_situation[1][1]-1];
                player_situation[3][land_situationl[1][player_situation[1][1]-1]-101]+=land_situationl[2][player_situation[1][1]-1];//�a�D����L���O�A�s�ڼW�[
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
    else if(land_situationl[1][player_situation[1][1]-1]==102 && player_situation[1][1]!=3 && player_situation[1][1]!=7 && player_situation[1][1]!=15) //����ۤv�g�a
    {
        if(player_situation[4][1]<= player_situation[4][0]*0.8 && player_situation[4][1]<= player_situation[4][2]*0.8 && player_situation[4][1]<= player_situation[4][3]*0.8) //�q������L�O
        {
            force_quanity=land_situationl[3][player_situation[1][1]-1]-500;
            if(force_quanity>0)
            {
                printf("���a2��ܻ�� %d �L�O\n",force_quanity);
                player_situation[4][1]+=force_quanity;
                land_situationl[3][player_situation[1][1]-1]-=force_quanity;
            }
        }
        else if(player_situation[4][1]>= player_situation[4][0]*1.2 && player_situation[4][1]>= player_situation[4][2]*1.2 && player_situation[4][1]>= player_situation[4][3]*1.2) //�q���s��L�O
        {
            int p1s=player_situation[4][0],p2s=player_situation[4][2],p3s=player_situation[4][3],maxs;
            maxs=p1s;
            if(p2s>maxs)        //�����L�T�Ӫ��a���L�O�A���̤j���X�ӡA�M��q���s��P[�̤j���L�O]���t�Z��0.8
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
            printf("���a2��ܦs�� %d �L�O\n",force_quanity);
            player_situation[4][1]-=force_quanity;
            land_situationl[3][player_situation[1][1]-1]+=force_quanity;
        }
        else
        {
            printf("���a2���L����...\n");
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
    printf("���a3");
l3:
    if(lightning>0&&lightning<4)
    {
        printf("�Q�֥d�C�q���A�����·��L�k�ʼu\n");
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
                if(player_situation[1][2]==1) //���b�Ĥ@��
                    {
                        if(land_situationl[1][15]==103 || land_situationl[1][1]==103)
                        {
                            superpower(2,1000,6);
                        }
                        else world(2);
                    }
                    else if(player_situation[1][2]==16) //���b��16��
                    {
                        if(land_situationl[1][0]==103 || land_situationl[1][14]==103)
                        {
                            superpower(2,1000,6);
                        }
                        else world(2);
                    }
                    else if(land_situationl[1][player_situation[1][2]]==103 || land_situationl[1][player_situation[1][2]-2]==103) //���b2~15��
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
        printf("���a3�J����F�A�i��pk\n");
        Sleep(slp3);
        if(player_situation[1][2]==player_situation[1][0])
        {
f9:
            if(player[0]==2 && player_situation[5][0]==0)
            {
                printf("�O�_�ϥ�\"���`����\"?(Y/N) :");
                scanf(" %c",&y_n);
                y_n=toupper(y_n);
                if(y_n=='Y')
                {
                    superpower(0,2,2);
                }
                else if(y_n=='N')
                {
                    printf("�����i�J�԰�!\n");
                }
                else goto f9;
            }
            gotoxy(0,0);
            pk_view();
            pk(2,0);
            printf("�z�l��%d�L�O�A",army_lose1);
            grn;
            printf("���a3");
            wht;
            printf("�l��%d�L�O\n",army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1<army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("�z�l�����G���A�Q���a3�T��%d��\n",player_situation[2][0]);
                        player_situation[2][2]+=player_situation[2][0];
                        player_situation[2][0]=0;
                    }
                    else
                    {
                        printf("�z�l�����G���A�Q���a3�T��%d��\n",money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][2]+=money_lose;
                    }
                }
                else if(army_lose1>army_lose2)
                {
                    if(player_situation[2][2]<money_lose)
                    {
                        printf("���a3�l�����G���A�z���W�[�o���T��%d��\n",player_situation[2][2]);
                        player_situation[2][0]+=player_situation[2][2];
                        player_situation[2][2]=0;
                    }
                    else
                    {
                        printf("���a3�l�����G���A�z���W�[�o���T��%d��\n",money_lose);
                        player_situation[2][2]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }
                }
            else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        else if(player_situation[1][2]==player_situation[1][1])
        {
            if(player[2]==2 && player_situation[5][2]==0)
            {
                printf("���a3�ϥΦ��`����\n");
                superpower(2,1,2);

            }
            else if(player[1]==2 && player_situation[5][1]==0)
            {
                printf("���a2�ϥΦ��`����\n");
                superpower(1,2,2);
            }
            gotoxy(0,0);
            pk_view();
            pk(2,1);
            pur;
            printf("���a3");
            wht;
            printf("�l��%d�L�O�A",army_lose1);
            grn;
            printf("���a2");
            wht;
            printf("�l��%d�L�O\n",army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1>army_lose2)
                {
                    if(player_situation[2][2]<money_lose)
                    {
                        printf("���a3�l�����G���A�Q���a2�T��%d��\n",player_situation[2][2]);
                        player_situation[2][1]+=player_situation[2][2];
                        player_situation[2][2]=0;
                    }
                    else
                    {
                        printf("���a3�l�����G���A�Q���a2�T��%d��\n",money_lose);
                        player_situation[2][2]-=money_lose;
                        player_situation[2][1]+=money_lose;
                    }
                }
                else if(army_lose1<army_lose2)
                {
                    if(player_situation[2][1]<money_lose)
                    {
                        printf("���a2�l�����G���A�Q���a3�T��%d��\n",player_situation[2][1]);
                        player_situation[2][2]+=player_situation[2][1];
                        player_situation[2][1]=0;
                    }
                    else
                    {
                        printf("���a2�l�����G���A�Q���a3�T��%d��\n",money_lose);
                        player_situation[2][1]-=money_lose;
                        player_situation[2][2]+=money_lose;
                    }
                }
            else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        else if(player_situation[1][2]==player_situation[1][3])
        {
            if(player[2]==2 && player_situation[5][2]==0)
            {
                printf("���a3�ϥΦ��`����\n");
                superpower(2,3,2);

            }
            else if(player[3]==2 && player_situation[5][3]==0)
            {
                printf("���a4�ϥΦ��`����\n");
                superpower(3,2,2);
            }
            gotoxy(0,0);
            pk_view();
            pk(2,3);
            pur;
            printf("���a3");
            wht;
            printf("�l��%d�L�O�A",army_lose1);
            yew;
            printf("���a4");
            wht;
            printf("�l��%d�L�O\n",army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1>army_lose2)
                {
                    if(player_situation[2][2]<money_lose)
                    {
                        printf("���a3�l�����G���A�Q���a4�T��%d��\n",player_situation[2][2]);
                        player_situation[2][3]+=player_situation[2][2];
                        player_situation[2][2]=0;
                    }
                    else
                    {
                        printf("���a3�l�����G���A�Q���a4�T��%d��\n",money_lose);
                        player_situation[2][2]-=money_lose;
                        player_situation[2][3]+=money_lose;
                    }
                }
                else if(army_lose1<army_lose2)
                {
                    if(player_situation[2][3]<money_lose)
                    {
                        printf("���a4�l�����G���A�Q���a3�T��%d��\n",player_situation[2][3]);
                        player_situation[2][2]+=player_situation[2][3];
                        player_situation[2][3]=0;
                    }
                    else
                    {
                        printf("���a4�l�����G���A�Q���a3�T��%d��\n",money_lose);
                        player_situation[2][3]-=money_lose;
                        player_situation[2][2]+=money_lose;
                    }
                }
            else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
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
                (player_situation[1][2]==2 && player_situation[2][2]<1500 && player_situation[2][2]>500) ) //�q���p�G�����j��1500�����M�p��1500���w���N��b�U�Ӧ^�X����Ȧ�A�K�|��ܦ���
        {
            printf("���a3����ʶR�g�a\n");
            Sleep(slp1);
            money_cosume=money_change(1);
            if(money_cosume>player_situation[2][2])
            {
                printf("�����a2�o�{���Y�S�����������]���@�}...\n");
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
                printf("���a3��O%d������g�a...",money_cosume);
                land_situationl[1][player_situation[1][2]-1]=103;
                Sleep(slp3);
                system("cls");
                world_print();
                print_situation();
                player_now_print();
                land_set();
            }
        }
        else if(player_situation[4][2]>1000 && player_situation[4][2]>=player_situation[4][0]*0.6 && player_situation[4][2]>=player_situation[4][1]*0.6 && player_situation[4][2]>=player_situation[4][3]*0.6) //�p�G�L�O�R���B�۫H���L���apk���P�l���Ӧh�A�N�|���
        {
            printf("���a3��ܧ���g�a...\n");
            Sleep(slp2);
            attack_land(2,103);
        }
        else
        {
            printf("���a3�S������ʧ@...\n");
        }
    }
    else if(player_situation[1][2]==3) //����Ȧ�
    {
        if(player_situation[2][2]>2000)
        {
            printf("���a3��ܦs��\n");
            int save_prob=rand()%401+300;
            savemoney1=(player_situation[2][2]-2000)*save_prob/1000;
            Sleep(slp2);
            printf("���a2�s�F%d��...\n",savemoney1);
            player_situation[2][2]-=savemoney1;//�{�����
            player_situation[3][2]+=savemoney1;//�s�ڼW�[
            Sleep(slp1);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
        }
        else if(player_situation[2][2]<1000 && player_situation[4][2]<=player_situation[4][0]*0.3 && player_situation[4][2]<=player_situation[4][1]*0.3 && player_situation[4][2]<=player_situation[4][2]*0.3 && player_situation[3][1] >0)
        {
            printf("���a3��ܴ���\n");
            withdraw1=rand()%(player_situation[3][2]);
            Sleep(slp2);
            printf("���a3��F%d��...\n",withdraw1);
            player_situation[2][2]+=withdraw1;//�{���W�[
            player_situation[3][2]-=withdraw1;//�s�ڴ��
            Sleep(slp1);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
        }
        else
        {
            printf("���a3��Ȧ���Ӥ���...\n");
        }
    }
    else if(player_situation[1][2]==7 || player_situation[1][2]==15) //������|�R�B
    {
        printf("���a3������|�R�B��\n");
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
    else if(land_situationl[1][player_situation[1][2]-1]!=103 && player_situation[1][2]!=3 && player_situation[1][2]!=7 && player_situation[1][2]!=15) //�L���O
    {
        printf("���a3�����L�H�g�a\n");
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
            printf("���a3ú��L���O%d��\n",land_situationl[2][player_situation[1][2]-1]);
            if(land_situationl[2][player_situation[1][2]-1]>player_situation[2][2])
            {
                int gap=land_situationl[2][player_situation[1][2]-1]-player_situation[2][2];
                player_situation[2][2]=0;
                player_situation[3][2]-=gap;
                player_situation[3][land_situationl[1][player_situation[1][2]-1]-101]+=land_situationl[2][player_situation[1][2]-1];//�a�D����L���O�A�s�ڼW�[
            }
            else
            {
                player_situation[2][2]-=land_situationl[2][player_situation[1][2]-1];
                player_situation[3][land_situationl[1][player_situation[1][2]-1]-101]+=land_situationl[2][player_situation[1][2]-1];//�a�D����L���O�A�s�ڼW�[
            }
        }
        else if(player_situation[2][2]<=2500 && player_situation[4][2]>=player_situation[4][0]*0.6 && player_situation[4][2]>=player_situation[4][1]*0.6 && player_situation[4][2]>=player_situation[4][3]*0.6 )
        {
            printf("���a3�������...");
            if(player[2]==1 && player_situation[5][2]==0)
            {
                printf("���a3�ϥθU�ᵩ�g����!\n");
                superpower(2,1000,1);
            }
            attack_door(2);
        }
        else if(player_situation[2][2]<=2500 && player_situation[4][2]>=player_situation[4][0]*0.8 && player_situation[4][2]>=player_situation[4][1]*0.8 && player_situation[4][2]>=player_situation[4][3]*0.8 )
        {
            printf("���a3��ܧ�...");
            attack_land(2,103);
        }
        else
        {
            printf("���a3ú��L���O%d��\n",land_situationl[2][player_situation[1][2]-1]);
            if(land_situationl[2][player_situation[1][2]-1]>player_situation[2][2])
            {
                int gap=land_situationl[2][player_situation[1][2]-1]-player_situation[2][2];
                player_situation[2][2]=0;
                player_situation[3][2]-=gap;
                player_situation[3][land_situationl[1][player_situation[1][2]-1]-101]+=land_situationl[2][player_situation[1][2]-1];//�a�D����L���O�A�s�ڼW�[
            }
            else
            {
                player_situation[2][2]-=land_situationl[2][player_situation[1][2]-1];
                player_situation[3][land_situationl[1][player_situation[1][2]-1]-101]+=land_situationl[2][player_situation[1][2]-1];//�a�D����L���O�A�s�ڼW�[
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
    else if(land_situationl[1][player_situation[1][2]-1]==103 && player_situation[1][2]!=3 && player_situation[1][2]!=7 && player_situation[1][2]!=15) //����ۤv�g�a
    {
        if(player_situation[4][2]<= player_situation[4][0]*0.8 && player_situation[4][2]<= player_situation[4][1]*0.8 && player_situation[4][2]<= player_situation[4][3]*0.8) //�q������L�O
        {
            force_quanity=land_situationl[3][player_situation[1][2]-1]-500;
            if(force_quanity>0)
            {
                printf("���a3��ܻ�� %d �L�O\n",force_quanity);
                player_situation[4][2]+=force_quanity;
                land_situationl[3][player_situation[1][2]-1]-=force_quanity;
            }
        }
        else if(player_situation[4][2]>= player_situation[4][0]*1.2 && player_situation[4][2]>= player_situation[4][1]*1.2 && player_situation[4][2]>= player_situation[4][3]*1.2) //�q���s��L�O
        {
            int p1s=player_situation[4][0],p2s=player_situation[4][1],p3s=player_situation[4][3],maxs;
            maxs=p1s;
            if(p2s>maxs)        //�����L�T�Ӫ��a���L�O�A���̤j���X�ӡA�M��q���s��P[�̤j���L�O]���t�Z��0.8
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
            printf("���a3��ܦs�� %d �L�O\n",force_quanity);
            player_situation[4][2]-=force_quanity;
            land_situationl[3][player_situation[1][2]-1]+=force_quanity;
        }
        else
        {
            printf("���a3���L����...\n");
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
    printf("���a4");
l4:
    if(lightning>0&&lightning<4)
    {
        printf("�Q�֥d�C�q���A�����·��L�k�ʼu\n");
        lightning--;
        goto p4;
    }
    else if(lightning==0||lightning==4)
        {
            if(lightning==4)
            {
                lightning--;
            }
            if(player[3]==3 && player_situation[5][3]==0)//�Өӭ�
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
                if(player_situation[1][3]==1) //���b�Ĥ@��
                    {
                        if(land_situationl[1][15]==104 || land_situationl[1][1]==104)
                        {
                            superpower(3,1000,6);
                        }
                        else world(3);
                    }
                    else if(player_situation[1][3]==16) //���b��16��
                    {
                        if(land_situationl[1][0]==103 || land_situationl[1][14]==104)
                        {
                            superpower(3,1000,6);
                        }
                        else world(3);
                    }
                    else if(land_situationl[1][player_situation[1][3]]==104 || land_situationl[1][player_situation[1][3]-2]==104) //���b2~15��
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
        printf("���a4�J����F�A�i��pk\n");
        Sleep(slp3);
        if(player_situation[1][3]==player_situation[1][0])
        {
f10:
            if(player[0]==2 && player_situation[5][0]==0)
            {
                printf("�O�_�ϥ�\"���`����\"?(Y/N) :");
                scanf(" %c",&y_n);
                y_n=toupper(y_n);
                if(y_n=='Y')
                {
                    superpower(0,3,2);
                }
                else if(y_n=='N')
                {
                    printf("�����i�J�԰�!\n");
                }
                else goto f10;
            }
            gotoxy(0,0);
            pk_view();
            pk(3,0);
            printf("�z�l��%d�L�O�A",army_lose1);
            yew;
            printf("���a4");
            wht;
            printf("�l��%d�L�O\n",army_lose2);
            money_lose=rand()%501+500;
            if(army_lose1<army_lose2)
                {
                    if(player_situation[2][0]<money_lose)
                    {
                        printf("�z�l�����G���A�Q���a4�T��%d��\n",player_situation[2][0]);
                        player_situation[2][3]+=player_situation[2][0];
                        player_situation[2][0]=0;
                    }
                    else
                    {
                        printf("�z�l�����G���A�Q���a4�T��%d��\n",money_lose);
                        player_situation[2][0]-=money_lose;
                        player_situation[2][3]+=money_lose;
                    }
                }
                else if(army_lose1>army_lose2)
                {
                    if(player_situation[2][3]<money_lose)
                    {
                        printf("���a4�l�����G���A�z���W�[�o���T��%d��\n",player_situation[2][3]);
                        player_situation[2][0]+=player_situation[2][3];
                        player_situation[2][3]=0;
                    }
                    else
                    {
                        printf("���a3�l�����G���A�z���W�[�o���T��%d��\n",money_lose);
                        player_situation[2][3]-=money_lose;
                        player_situation[2][0]+=money_lose;
                    }
                }
            else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        else if(player_situation[1][3]==player_situation[1][1])
        {
            if(player[3]==2 && player_situation[5][3]==0)
            {
                printf("���a4�ϥΦ��`����\n");
                superpower(3,1,2);

            }
            else if(player[1]==2 && player_situation[5][1]==0)
            {
                printf("���a2�ϥΦ��`����\n");
                superpower(1,3,2);
            }
            gotoxy(0,0);
            pk_view();
            pk(3,1);
            yew;
            printf("���a4");
            wht;
            printf("�l��%d�L�O�A",army_lose1);
            grn;
            printf("���a2");
            wht;
            printf("�l��%d�L�O\n",army_lose2);
            money_lose=rand()%501+500;
              if(army_lose1>army_lose2)
                {
                    if(player_situation[2][3]<money_lose)
                    {
                        printf("���a4�l�����G���A�Q���a2�T��%d��\n",player_situation[2][3]);
                        player_situation[2][1]+=player_situation[2][3];
                        player_situation[2][3]=0;
                    }
                    else
                    {
                        printf("���a4�l�����G���A�Q���a2�T��%d��\n",money_lose);
                        player_situation[2][3]-=money_lose;
                        player_situation[2][1]+=money_lose;
                    }
                }
                else if(army_lose1<army_lose2)
                {
                    if(player_situation[2][1]<money_lose)
                    {
                        printf("���a2�l�����G���A�Q���a4�T��%d��\n",player_situation[2][1]);
                        player_situation[2][3]+=player_situation[2][1];
                        player_situation[2][1]=0;
                    }
                    else
                    {
                        printf("���a2�l�����G���A�Q���a4�T��%d��\n",money_lose);
                        player_situation[2][1]-=money_lose;
                        player_situation[2][3]+=money_lose;
                    }
                }
            else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
            Sleep(slp4);
            gotoxy(0,13);
            print_situation();
            Sleep(slp3);
        }
        else if(player_situation[1][2]==player_situation[1][3])
        {
            if(player[2]==2 && player_situation[5][2]==0)
            {
                printf("���a3�ϥΦ��`����\n");
                superpower(2,3,2);

            }
            else if(player[3]==2 && player_situation[5][3]==0)
            {
                printf("���a4�ϥΦ��`����\n");
                superpower(3,2,2);
            }
            gotoxy(0,0);
            pk_view();
            pk(3,2);
            yew;
            printf("���a4");
            wht;
            printf("�l��%d�L�O�A",army_lose1);
            pur;
            printf("���a3");
            wht;
            printf("�l��%d�L�O\n",army_lose2);
            money_lose=rand()%501+500;
              if(army_lose1>army_lose2)
                {
                    if(player_situation[2][3]<money_lose)
                    {
                        printf("���a4�l�����G���A�Q���a3�T��%d��\n",player_situation[2][3]);
                        player_situation[2][2]+=player_situation[2][3];
                        player_situation[2][3]=0;
                    }
                    else
                    {
                        printf("���a4�l�����G���A�Q���a3�T��%d��\n",money_lose);
                        player_situation[2][3]-=money_lose;
                        player_situation[2][2]+=money_lose;
                    }
                }
                else if(army_lose1<army_lose2)
                {
                    if(player_situation[2][2]<money_lose)
                    {
                        printf("���a3�l�����G���A�Q���a4�T��%d��\n",player_situation[2][2]);
                        player_situation[2][3]+=player_situation[2][2];
                        player_situation[2][2]=0;
                    }
                    else
                    {
                        printf("���a3�l�����G���A�Q���a4�T��%d��\n",money_lose);
                        player_situation[2][2]-=money_lose;
                        player_situation[2][3]+=money_lose;
                    }
                }
            else printf("�l���L�O�@�ˡA�S��O�h���T�t�~�@�H...\n");
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
                (player_situation[1][3]==2 && player_situation[2][3]<1500 && player_situation[2][3]>500) ) //�q���p�G�����j��1500�����M�p��1500���w���N��b�U�Ӧ^�X����Ȧ�A�K�|��ܦ���
        {
            printf("���a4����ʶR�g�a\n");
            Sleep(slp1);
            money_cosume=money_change(1);
            if(money_cosume>player_situation[2][3])
            {
                printf("�����a4�o�{���Y�S�����������]���@�}...\n");
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
                printf("���a4��O%d������g�a...",money_cosume);
                land_situationl[1][player_situation[1][3]-1]=104;
                Sleep(slp3);
                system("cls");
                world_print();
                print_situation();
                player_now_print();
                land_set();
            }
        }
        else if(player_situation[4][3]>1000 && player_situation[4][3]>=player_situation[4][0]*0.6 && player_situation[4][3]>=player_situation[4][1]*0.6 && player_situation[4][3]>=player_situation[4][2]*0.6) //�p�G�L�O�R���B�۫H���L���apk���P�l���Ӧh�A�N�|���
        {
            printf("���a4��ܧ���g�a...\n");
            Sleep(slp2);
            attack_land(3,104);
        }
        else
        {
            printf("���a4�S������ʧ@...\n");
        }
    }
    else if(player_situation[1][3]==3) //����Ȧ�
    {
        if(player_situation[2][3]>2000)
        {
            printf("���a4��ܦs��\n");
            int save_prob=rand()%401+300;
            savemoney1=(player_situation[2][3]-2000)*save_prob/1000;
            Sleep(slp2);
            printf("���a4�s�F%d��...\n",savemoney1);
            player_situation[2][3]-=savemoney1;//�{�����
            player_situation[3][3]+=savemoney1;//�s�ڼW�[
            Sleep(slp1);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
        }
        else if(player_situation[2][3]<1000 && player_situation[4][3]<=player_situation[4][0]*0.3 && player_situation[4][3]<=player_situation[4][1]*0.3 && player_situation[4][3]<=player_situation[4][2]*0.3 && player_situation[3][1] >0)
        {
            printf("���a4��ܴ���\n");
            withdraw1=rand()%(player_situation[3][3]);
            Sleep(slp2);
            printf("���a4��F%d��...\n",withdraw1);
            player_situation[2][3]+=withdraw1;//�{���W�[
            player_situation[3][3]-=withdraw1;//�s�ڴ��
            Sleep(slp1);
            system("cls");
            world_print();
            print_situation();
            player_now_print();
            land_set();
        }
        else
        {
            printf("���a4��Ȧ���Ӥ���...\n");
        }
    }
    else if(player_situation[1][3]==7 || player_situation[1][3]==15) //������|�R�B
    {
        printf("���a4������|�R�B��\n");
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
    else if(land_situationl[1][player_situation[1][3]-1]!=104 && player_situation[1][3]!=3 && player_situation[1][3]!=7 && player_situation[1][3]!=15) //�L���O
    {
        printf("���a4�����L�H�g�a\n");
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
            printf("���a4ú��L���O%d��\n",land_situationl[2][player_situation[1][3]-1]);
            if(land_situationl[2][player_situation[1][3]-1]>player_situation[2][3])
            {
                int gap=land_situationl[2][player_situation[1][3]-1]-player_situation[2][3];
                player_situation[2][3]=0;
                player_situation[3][3]-=gap;
                player_situation[3][land_situationl[1][player_situation[1][3]-1]-101]+=land_situationl[2][player_situation[1][3]-1];//�a�D����L���O�A�s�ڼW�[
            }
            else
            {
                player_situation[2][3]-=land_situationl[2][player_situation[1][3]-1];
                player_situation[3][land_situationl[1][player_situation[1][3]-1]-101]+=land_situationl[2][player_situation[1][3]-1];//�a�D����L���O�A�s�ڼW�[
            }
        }
        else if(player_situation[2][3]<=2500 && player_situation[4][3]>=player_situation[4][0]*0.6 && player_situation[4][3]>=player_situation[4][1]*0.6 && player_situation[4][3]>=player_situation[4][2]*0.6 )
        {
            printf("���a4�������...");
            if(player[3]==1 && player_situation[5][3]==0)
            {
                printf("���a4�ϥθU�ᵩ�g����!\n");
                superpower(3,1000,1);
            }
            attack_door(3);
        }
        else if(player_situation[2][3]<=2500 && player_situation[4][3]>=player_situation[4][0]*0.8 && player_situation[4][3]>=player_situation[4][2]*0.8 && player_situation[4][3]>=player_situation[4][1]*0.8 )
        {
            printf("���a4��ܧ�...");
            attack_land(3,104);
        }
        else
        {
            printf("���a4ú��L���O%d��\n",land_situationl[2][player_situation[1][3]-1]);
            if(land_situationl[2][player_situation[1][3]-1]>player_situation[2][3])
            {
                int gap=land_situationl[2][player_situation[1][3]-1]-player_situation[2][3];
                player_situation[2][3]=0;
                player_situation[3][3]-=gap;
                player_situation[3][land_situationl[1][player_situation[1][3]-1]-101]+=land_situationl[2][player_situation[1][3]-1];//�a�D����L���O�A�s�ڼW�[
            }
            else
            {
                player_situation[2][3]-=land_situationl[2][player_situation[1][3]-1];
                player_situation[3][land_situationl[1][player_situation[1][3]-1]-101]+=land_situationl[2][player_situation[1][3]-1];//�a�D����L���O�A�s�ڼW�[
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
    else if(land_situationl[1][player_situation[1][3]-1]==104 && player_situation[1][3]!=3 && player_situation[1][3]!=7 && player_situation[1][3]!=15) //����ۤv�g�a
    {
        if(player_situation[4][3]<= player_situation[4][0]*0.8 && player_situation[4][3]<= player_situation[4][2]*0.8 && player_situation[4][3]<= player_situation[4][1]*0.8) //�q������L�O
        {
            force_quanity=land_situationl[3][player_situation[1][3]-1]-500;
            if(force_quanity>0)
            {
                printf("���a4��ܻ�� %d �L�O\n",force_quanity);
                player_situation[4][3]+=force_quanity;
                land_situationl[3][player_situation[1][3]-1]-=force_quanity;
            }
        }
        else if(player_situation[4][3]>= player_situation[4][0]*1.2 && player_situation[4][3]>= player_situation[4][2]*1.2 && player_situation[4][3]>= player_situation[4][1]*1.2) //�q���s��L�O
        {
            int p1s=player_situation[4][0],p2s=player_situation[4][1],p3s=player_situation[4][2],maxs;
            maxs=p1s;
            if(p2s>maxs)        //�����L�T�Ӫ��a���L�O�A���̤j���X�ӡA�M��q���s��P[�̤j���L�O]���t�Z��0.8
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
            printf("���a4��ܦs�� %d �L�O\n",force_quanity);
            player_situation[4][3]-=force_quanity;
            land_situationl[3][player_situation[1][3]-1]+=force_quanity;
        }
        else
        {
            printf("���a4���L����...\n");
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
