#include<bits/stdc++.h>
#include <windows.h>
#include"space.h"
#include"entity.h"
#include"ecosystem.h"
#include"space.cpp"
#include"entity.cpp"
#include"ecosystem.cpp"
#include "conio.h"//_kbhit()和_getch()的头文件
using namespace std;

/*默认的参数值【可配置】*/
int col;
int row;//初始化生态系统大小<col*row>
int TurnGrass;//空地变为青草地的概率
int Hheal;//食草动物最大健康值
int Cheal;//食肉动物最大健康值
int HreproAge;//食草动物允许繁殖年龄
int CreproAge;//食肉动物允许繁殖年龄

/*函数声明【不可配置】*/
void setsys();//系统配置交互
void start();//系统启动交互
void step1();//创建系统并打印分布
int commander();//命令行
void InFile();//存档操作
void ReadFile();//读档操作
//Eco:
ecosystem me;//EcoName:"me"

int main()
{
    char ch;int flag=0;
    while(cout<<"Type [A] to [recreate the archive] -or- [R] to [read the program]"<<endl&&cin>>ch){//键入[A]来使程序【重新建立存档】\键入[R]来使程序【读档】\n
        if(ch=='A'||ch=='a'){
            flag=1;
            getchar();
            break;
        }
        else if(ch=='R'||ch=='r'){
            flag=2;
            getchar();
            break;
        }
        else{
            system("cls");
            cout << "Illegal input, please re-enter:\n输入不合法，请重新输入:\n" <<endl;
        }
    }//1:为新开模式   2:为读档模式
    if(flag==1){//1:为新开模式
        setsys();//系统配置交互
        start();//系统启动交互
        step1();//创建系统并打印分布
        while(1){//commander()返回值==1表示:存档&结束
            if(commander()==1)break;
        }
        cout<<"BYE BYE!"<<endl;//Save();
    }else{//2:为读档模式
        cout<<"-------读档模式Reading!-------"<<endl;
        ReadFile();
        me.Traverse();
        me.Display();
        cout<<"Read Successfully!\n读取成功!"<<endl;
        while(1){//commander()返回值==1表示:存档&结束
            if(commander()==1)break;
        }
        cout<<"BYE BYE!"<<endl;//Save();
    }

    return 0;
}

void ReadFile(){//读档操作
    ifstream in("EcoSystemSimulatorByQPProgramRecordFile.txt");
    if (! in.is_open())
    { cout << endl << "Error opening file: No Such File Founded!" << endl;; exit (1); }
    if (!in.eof() )
    {
        int tmp;
        string m;
        in >> col; row=col ;
        me.generateEco();
        in >> TurnGrass ;
        in >> Hheal ;
        in >> Cheal ;
        in >> HreproAge ;
        in >> CreproAge ;
        for(int i=0;i<col;i++)
            for(int o=0;o<row;o++)
            {
                in >> m;
                in >> tmp;me.entityLife[i][o].Type = tmp;
                in >> m;
                in >> tmp;me.entityLife[i][o].Gender = tmp;
                in >> m;
                in >> tmp;me.entityLife[i][o].X = tmp;
                in >> m;
                in >> tmp;me.entityLife[i][o].Y = tmp;
                in >> m;
                in >> tmp;me.entityLife[i][o].Age = tmp;
                in >> m;
                in >> tmp;me.entityLife[i][o].Health = tmp;
                in >> m;
            }
    }
    in.close();
}

void InFile(){//存档操作
    char* path = "./EcoSystemSimulatorByQPProgramRecordFile.txt";
    ofstream out(path);
    if (out)
    {
        out << col << endl;
        out << TurnGrass <<endl;
        out << Hheal <<endl;
        out << Cheal <<endl;
        out << HreproAge <<endl;
        out << CreproAge <<endl;
        for(int i=0;i<col;i++)
            for(int o=0;o<row;o++)
                out << me.entityLife[i][o].getstring() << endl;
        out.close();
    }else cout << "Failed to create archive file" << endl;
}

int commander(){//命令行
    char ch;
    while(cout<<"Please enter the command:\n<EcoSystemSimulatorByQP:$Command:/>"&&cin>>ch){//键入[A]来使程序【重新建立存档】\键入[R]来使程序【读档】\n
        if(ch=='A'||ch=='a'){
                int stps;
            while(cout<<"Please enter how many steps you want:"&&cin>>stps){
                if(stps>0){
                    for(int i=0;i<stps;i++){
                        Sleep(1000);
                        me.Develop();
                    }
                    break;
                }else{
                    cout<<"Input Err!Please try AGAIN!"<<endl;
                }
            }
            return 0;
        }
        else if(ch=='B'||ch=='b'){
            while (true)
            {
                Sleep(1000);
                me.Develop();
                if (_kbhit())
                {
                    if (_getch() == 13)//检测到回车符
                    {
                        break;//跳出循环
                    }
                }
            }
            return 0;
        }else if(ch=='R'||ch=='r'){
            me.Show();
            return 0;
        }
        else if(ch=='M'||ch=='m'){
            InFile();
            cout<<"Saved Successfully!"<<endl;//Saved;
            return 1;
        }
        else if(ch=='Q'||ch=='q'){
            cout<<"EcoSystemSimulator Exiting......"<<endl;
            Sleep(1000);
            cout<<"EcoSystemSimulator Quit Completed!\nThanks for Using!"<<endl;
            return 1;
        }
        else{
            system("cls");
            cout << "Illegal input, please re-enter:\n输入不合法，请重新输入:\n" <<endl;
        }
    }
}

void step1(){
    me.generateEco();
    me.Display();
}

void setsys(){
    cout << "\nWelcome to EcoSystemSimulator [made by QP!]\n" << endl;
    cout << "\nPress [Enter] to continue ~\n请敲击回车继续~\n" << endl;
    getchar();
    system("cls");
    cout << "Please Input the [col] wanted:\n请输入你希望的列宽值(生态空间边长):\n[推荐值:20]\n";
    cin >> col; row = col;
    cout << endl;
    cout << "Please Input the [TurnGrass] wanted:\n请输入你希望的概率(空地变为青草地的概率):\n[推荐值:30]\n";
    cin >> TurnGrass;
    cout << "Please Input the [Hheal] wanted:\n请输入你希望的食草动物最大健康值:\n[推荐值:20]\n"<<endl;
    cin >> Hheal;
    cout << "Please Input the [Cheal] wanted:\n请输入你希望的食肉动物最大健康值:\n[推荐值:30]\n"<<endl;
    cin >> Cheal;
    cout << "Please Input the [HreproAge] wanted:\n请输入你希望的食草动物允许繁殖年龄:\n[推荐值:3]\n"<<endl;
    cin >> HreproAge;
    cout << "Please Input the [CreproAge] wanted:\n请输入你希望的食肉动物允许繁殖年龄:\n[推荐值:4]\n"<<endl;
    cin >> CreproAge;
    cout << endl;
}

void start(){
    getchar();
    cout << "Start the Simulator Now?\n现在开启模拟系统?\n[输入y继续][y/n]\n" <<endl;
    char ch = getchar();
    if(ch=='n'||ch=='N'){
        system("cls");
        cout << "System termination!\n系统终止待命!" <<endl;
        start();
    }else if(ch!='y'&&ch!='Y'){
        system("cls");
        cout << "Illegal input, please re-enter:\n输入不合法，请重新输入:\n" <<endl;
        start();
    }else{
        cout << "System Startup!\n系统启动!\n" <<endl;
        int t = 4;
         while(1)
        {
            Sleep(1000);
            t--;
            printf("%d!\n",t);
            if (t==0)
            {
            break;
            }
        }
        printf("Working!\n");
        Sleep(1000);
        system("cls");
    }
}
