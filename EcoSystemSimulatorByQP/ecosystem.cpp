#include<bits/stdc++.h>

using namespace std;

void ecosystem::generateEco(){
    //������ά��������
    entityLife = new entity*[col];
    for(int i=0;i<col;i++)entityLife[i] = new entity[row];
    //�����ʼ��EcoSystem����
    cout << "Generate starting!" << endl;
    srand((unsigned)time(NULL));//���������
    for(int i=0;i<col;i++)
        for(int o=0;o<row;o++){
            int flag = rand()%4;
            if(flag==0)entityLife[i][o].copyentity(entity(0,3,i,o));
            else if(flag==1)entityLife[i][o].copyentity(entity(1,3,i,o));
            else if(flag==2)entityLife[i][o].copyentity(entity(2,rand()%2==1?0:1,i,o));
            else if(flag==3)entityLife[i][o].copyentity(entity(3,rand()%2==1?0:1,i,o));
            else{
                entityLife[i][o].copyentity(entity(5,3,i,o));
                cout << "System Err:003(Randomly generated anomalies:rand)" <<endl;
            }
        }
    cout << "Generate over!" << endl;
    Traverse();
}

void ecosystem::Show(){
    for(int i=0;i<col;i++)
        for(int o=0;o<row;o++)
            entityLife[i][o].dp();
}

void ecosystem::Display(){
    cout<<"["<<col<<"*"<<row<<"]"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(int i=0;i<col;i++){
        for(int o=0;o<row;o++)
            cout<<entityLife[i][o];
        cout << endl;
    }
    cout<<"-----------------------------------------"<<endl;
    cout<<"Tips: \n type [A] to make the program [continuous simulation of specified steps]; \n type [B] to make the program [perform continuous simulation] !!Press ENTER to stop loop!!; \n"
        <<" type [M] to make the program [perform archive operation];\n type [R] to make the program [Output all individual attributes];\n"
        <<" type [Q] to make the program [Quiet Out];\n"<<endl;//Tips:\n����[A]��ʹ��������ģ��ָ��������\n����[B]��ʹ���򡾽�������ģ�⡿\n����[M]��ʹ����ִ�д浵������\n����[R]��ʹ����������и������ԡ�\n����[Q]��ʹ�����˳���
}

void ecosystem::Traverse(){
    for(int i=0;i<col;i++)
        for(int o=0;o<row;o++){
            if(entityLife[i][o].Type==0||entityLife[i][o].Type==1||entityLife[i][o].Type==2||entityLife[i][o].Type==3);
            else cout << "System Err:004(Traversal Err)" <<endl;
        }
    cout << "Traversal Successed!" << endl;
}

void ecosystem::Develop(){

    entity **tmp = new entity*[col];
    for(int i=0;i<col;i++)tmp[i] = new entity[row];


        for(int i=0;i<col;i++)
        for(int o=0;o<row;o++){
            if(entityLife[i][o].Type==0){cout<<"0";//�������
                        srand((unsigned)time(NULL));//���������
                        if(rand()%101>=TurnGrass){
                            tmp[i][o].copyentity(entity(1,3,i,o));
                        }else{
                            tmp[i][o].copyentity(entityLife[i][o]);
                        }
                        tmp[i][o].older();

                    }

        }
        for(int i=0;i<col;i++)
        for(int o=0;o<row;o++){
            if(entityLife[i][o].Type==1){cout<<"1";//�������
                        tmp[i][o].copyentity(entityLife[i][o]);//���뵱ǰ������
                        int turned = 0;
                        /*
                        srand((unsigned)time(NULL));//���������
                        int flag = rand()%8;
                        if(i-1>=0&&o-1>=0)
                        if(entityLife[i-1][o-1].Type == 0&&turned == 0&&flag==0)//�ݵط�ֳ
                        {
                            tmp[i-1][o-1].copyentity(entity(1,3,i,o));
                            turned = 1;
                        }
                        if(i-1>=0)
                        if(entityLife[i-1][o].Type == 0&&turned == 0&&flag==1)
                        {
                            tmp[i-1][o].copyentity(entity(1,3,i,o));
                            turned = 1;
                        }
                        if(i-1>=0&&o+1<=row)
                        if(entityLife[i-1][o+1].Type == 0&&turned == 0&&flag==2)
                        {
                            tmp[i-1][o+1].copyentity(entity(1,3,i,o));
                            turned = 1;
                        }
                        if(o-1>=0)
                        if(entityLife[i][o-1].Type == 0&&turned == 0&&flag==3)
                        {
                            tmp[i][o-1].copyentity(entity(1,3,i,o));
                            turned = 1;
                        }
                        if(o+1<=row)
                        if(entityLife[i][o+1].Type == 0&&turned == 0&&flag==4)
                        {
                            tmp[i][o+1].copyentity(entity(1,3,i,o));
                            turned = 1;
                        }
                        if(o-1>=0&&i+1<=col)
                        if(entityLife[i+1][o-1].Type == 0&&turned == 0&&flag==5)
                        {
                            tmp[i+1][o-1].copyentity(entity(1,3,i,o));
                            turned = 1;
                        }
                        if(i+1<=col)
                        if(entityLife[i+1][o].Type == 0&&turned == 0&&flag==6)
                        {
                            tmp[i+1][o].copyentity(entity(1,3,i,o));
                            turned = 1;
                        }
                        if(o+1<=row&&i+1<=col)
                        if(entityLife[i+1][o+1].Type == 0&&turned == 0&&flag==7)
                        {
                            tmp[i+1][o+1].copyentity(entity(1,3,i,o));
                            turned = 1;
                        }
                        */
                        srand((unsigned)time(NULL));//���������
                        if(rand()%101>=TurnGrass){//������Է�ֳ
                        int flag1 = rand()%8;//���ڷ�ֳ��rand
                        for(int m=0;m<8&&turned==0;m++){  //�ݵط�ֳ
                            int fl = (flag1+m)%8;
                            switch(fl){
                                case 0:
                                    if(i-1>=0&&o-1>=0)
                                    if(entityLife[i-1][o-1].Type == 0&&turned == 0){
                                        tmp[i-1][o-1].copyentity(entity(1,3,i,o));
                                        turned = 1;
                                    }
                                    break;
                                case 1:
                                    if(i-1>=0)
                                    if(entityLife[i-1][o].Type == 0&&turned == 0){
                                        tmp[i-1][o].copyentity(entity(1,3,i,o));
                                        turned = 1;
                                    }
                                    break;
                                case 2:
                                    if(i-1>=0&&o+1<=row-1)
                                    if(entityLife[i-1][o+1].Type == 0&&turned == 0){
                                        tmp[i-1][o+1].copyentity(entity(1,3,i,o));
                                        turned = 1;
                                    }
                                    break;
                                case 3:
                                    if(o-1>=0)
                                    if(entityLife[i][o-1].Type == 0&&turned == 0){
                                        tmp[i][o-1].copyentity(entity(1,3,i,o));
                                        turned = 1;
                                    }
                                    break;
                                case 4:
                                    if(o+1<=row-1)
                                    if(entityLife[i][o+1].Type == 0&&turned == 0){
                                        tmp[i][o+1].copyentity(entity(1,3,i,o));
                                        turned = 1;
                                    }
                                    break;
                                case 5:
                                    if(i+1<=col-1&&o-1>=0)
                                    if(entityLife[i+1][o-1].Type == 0&&turned == 0){
                                        tmp[i+1][o-1].copyentity(entity(1,3,i,o));
                                        turned = 1;
                                    }
                                    break;
                                case 6:
                                    if(i+1<=col-1)
                                    if(entityLife[i+1][o].Type == 0&&turned == 0){
                                        tmp[i+1][o].copyentity(entity(1,3,i,o));
                                        turned = 1;
                                    }
                                    break;
                                case 7:
                                    if(o+1<=row-1&&i+1<=col-1)
                                    if(entityLife[i+1][o+1].Type == 0&&turned == 0){
                                        tmp[i+1][o+1].copyentity(entity(1,3,i,o));
                                        turned = 1;
                                    }
                                    break;
                                default:cout << "System Err:009(Grass Reproduction Err:switch)" <<endl;
                                }
                            }
                        }
                        tmp[i][o].older();

                    }
        }
        for(int i=0;i<col;i++)
        for(int o=0;o<row;o++){
            if(entityLife[i][o].Type==2){cout<<"2";//�������
                        srand((unsigned)time(NULL));//���������
                        int flag1 = rand()%8;//���ڽ�ʳ��rand
                        int turned = 0;//��¼�Ƿ��ƶ�λ��
                        int fl;//��¼�ƶ����ĸ�λ��
                        for(int m=0;m<8&&turned==0;m++){  //��ʳ
                            fl = (flag1+m)%8;
                            switch(fl){
                                case 0:
                                    if(i-1>=0&&o-1>=0)
                                    if(entityLife[i-1][o-1].Type==1){
                                        tmp[i-1][o-1].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i-1][o-1].recover();
                                    }
                                    break;
                                case 1:
                                    if(i-1>=0)
                                    if(entityLife[i-1][o].Type==1){
                                        tmp[i-1][o].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i-1][o].recover();
                                    }
                                    break;
                                case 2:
                                    if(i-1>=0&&o+1<=row-1)
                                    if(entityLife[i-1][o+1].Type==1){
                                        tmp[i-1][o+1].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i-1][o+1].recover();
                                    }
                                    break;
                                case 3:
                                    if(o+1<=row-1)
                                    if(entityLife[i][o+1].Type==1){
                                        tmp[i][o+1].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i][o+1].recover();
                                    }
                                    break;
                                case 4:
                                    if(i+1<=col-1&&o+1<=row-1)
                                    if(entityLife[i+1][o+1].Type==1){
                                        tmp[i+1][o+1].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i+1][o+1].recover();
                                    }
                                    break;
                                case 5:
                                    if(i+1<=col-1)
                                    if(entityLife[i+1][o].Type==1){
                                        tmp[i+1][o].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i+1][o].recover();
                                    }
                                    break;
                                case 6:
                                    if(i+1<=col-1&&o-1>=0)
                                    if(entityLife[i+1][o-1].Type==1){
                                        tmp[i+1][o-1].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i+1][o-1].recover();
                                    }
                                    break;
                                case 7:
                                    if(o-1>=0)
                                    if(entityLife[i][o-1].Type==1){
                                        tmp[i][o-1].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i][o-1].recover();
                                    }
                                    break;
                                default:cout << "System Err:006(Ecosystem Switch case 2 Err:rand)" <<endl;
                            }
                        }
                        if(turned==0)tmp[i][o].copyentity(entityLife[i][o]);//��ʳʧ�ܴ���
                        //��ʳ����
                        //׷��λ��:
                        int xx,yy;
                        if(turned==1){
                            switch(fl){
                                case 0:xx=i-1;yy=o-1;break;
                                case 1:xx=i-1;yy=o;break;
                                case 2:xx=i-1;yy=o+1;break;
                                case 3:xx=i;yy=o+1;break;
                                case 4:xx=i+1;yy=o+1;break;
                                case 5:xx=i+1;yy=o;break;
                                case 6:xx=i+1;yy=o-1;break;
                                case 7:xx=i;yy=o-1;break;
                            }
                        }
                        else{
                            xx=i;yy=o;
                        }
                        //��ֳ (��HreproAge�꼰���Ͽ��Է�ֳ)
                        if(xx-1>=0&&yy-1>=0&&xx+1<=col-1&&yy+1<=row-1){
                        if(tmp[xx][yy].Type==2&&tmp[xx][yy].Age>=HreproAge&&
                                                  ((entityLife[xx-1][yy-1].Type==2&&entityLife[xx-1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy-1].Age>=HreproAge)
                                                 ||(entityLife[xx-1][yy].Type==2&&entityLife[xx-1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy].Age>=3)
                                                 ||(entityLife[xx-1][yy+1].Type==2&&entityLife[xx-1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy+1].Age>=HreproAge)
                                                 ||(entityLife[xx][yy+1].Type==2&&entityLife[xx][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy+1].Age>=3)
                                                 ||(entityLife[xx+1][yy+1].Type==2&&entityLife[xx+1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy+1].Age>=HreproAge)
                                                 ||(entityLife[xx+1][yy].Type==2&&entityLife[xx+1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy].Age>=3)
                                                 ||(entityLife[xx+1][yy-1].Type==2&&entityLife[xx+1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy-1].Age>=HreproAge)
                                                 ||(entityLife[xx][yy-1].Type==2&&entityLife[xx][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy-1].Age>=3))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx-1][yy-1].Type==0)tmp[xx-1][yy-1].copyentity(entity(2,rand()%2,xx-1,yy-1));
                            else if(tmp[xx-1][yy].Type==0)tmp[xx-1][yy].copyentity(entity(2,rand()%2,xx-1,yy));
                            else if(tmp[xx-1][yy+1].Type==0)tmp[xx-1][yy+1].copyentity(entity(2,rand()%2,xx-1,yy+1));
                            else if(tmp[xx][yy+1].Type==0)tmp[xx][yy+1].copyentity(entity(2,rand()%2,xx,yy+1));
                            else if(tmp[xx+1][yy+1].Type==0)tmp[xx+1][yy+1].copyentity(entity(2,rand()%2,xx+1,yy+1));
                            else if(tmp[xx+1][yy].Type==0)tmp[xx+1][yy].copyentity(entity(2,rand()%2,xx+1,yy));
                            else if(tmp[xx+1][yy-1].Type==0)tmp[xx+1][yy-1].copyentity(entity(2,rand()%2,xx+1,yy-1));
                            else if(tmp[xx][yy-1].Type==0)tmp[xx][yy-1].copyentity(entity(2,rand()%2,xx,yy-1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(xx-1<0&&yy-1<0){//����
                            if(tmp[xx][yy].Type==2&&tmp[xx][yy].Age>=HreproAge&&
                                                  ((entityLife[xx][yy+1].Type==2&&entityLife[xx][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy+1].Age>=HreproAge)
                                                 ||(entityLife[xx+1][yy+1].Type==2&&entityLife[xx+1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy+1].Age>=HreproAge)
                                                 ||(entityLife[xx+1][yy].Type==2&&entityLife[xx+1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy].Age>=HreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx][yy+1].Type==0)tmp[xx][yy+1].copyentity(entity(2,rand()%2,xx,yy+1));
                            else if(tmp[xx+1][yy+1].Type==0)tmp[xx+1][yy+1].copyentity(entity(2,rand()%2,xx+1,yy+1));
                            else if(tmp[xx+1][yy].Type==0)tmp[xx+1][yy].copyentity(entity(2,rand()%2,xx+1,yy));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(xx-1<0&&yy+1>row-1){//����
                            if(tmp[xx][yy].Type==2&&tmp[xx][yy].Age>=HreproAge&&
                                                  ((entityLife[xx+1][yy].Type==2&&entityLife[xx+1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy].Age>=HreproAge)
                                                 ||(entityLife[xx+1][yy-1].Type==2&&entityLife[xx+1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy-1].Age>=HreproAge)
                                                 ||(entityLife[xx][yy-1].Type==2&&entityLife[xx][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy-1].Age>=HreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx+1][yy].Type==0)tmp[xx+1][yy].copyentity(entity(2,rand()%2,xx+1,yy));
                            else if(tmp[xx+1][yy-1].Type==0)tmp[xx+1][yy-1].copyentity(entity(2,rand()%2,xx+1,yy-1));
                            else if(tmp[xx][yy-1].Type==0)tmp[xx][yy-1].copyentity(entity(2,rand()%2,xx,yy-1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(xx+1>col-1&&yy-1<0){//����
                            if(tmp[xx][yy].Type==2&&tmp[xx][yy].Age>=HreproAge&&
                                                  ((entityLife[xx-1][yy].Type==2&&entityLife[xx-1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy].Age>=HreproAge)
                                                 ||(entityLife[xx-1][yy+1].Type==2&&entityLife[xx-1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy+1].Age>=HreproAge)
                                                 ||(entityLife[xx][yy+1].Type==2&&entityLife[xx][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy+1].Age>=HreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx-1][yy].Type==0)tmp[xx-1][yy].copyentity(entity(2,rand()%2,xx-1,yy));
                            else if(tmp[xx-1][yy+1].Type==0)tmp[xx-1][yy+1].copyentity(entity(2,rand()%2,xx-1,yy+1));
                            else if(tmp[xx][yy+1].Type==0)tmp[xx][yy+1].copyentity(entity(2,rand()%2,xx,yy+1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(xx+1>col-1&&yy+1>row-1){//����
                            if(tmp[xx][yy].Type==2&&tmp[xx][yy].Age>=HreproAge&&
                                                  ((entityLife[xx-1][yy-1].Type==2&&entityLife[xx-1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy-1].Age>=HreproAge)
                                                 ||(entityLife[xx-1][yy].Type==2&&entityLife[xx-1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy].Age>=HreproAge)
                                                 ||(entityLife[xx][yy-1].Type==2&&entityLife[xx][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy-1].Age>=HreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx-1][yy-1].Type==0)tmp[xx-1][yy-1].copyentity(entity(2,rand()%2,xx-1,yy-1));
                            else if(tmp[xx-1][yy].Type==0)tmp[xx-1][yy].copyentity(entity(2,rand()%2,xx-1,yy));
                            else if(tmp[xx][yy-1].Type==0)tmp[xx][yy-1].copyentity(entity(2,rand()%2,xx,yy-1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(xx-1<0){//��
                            if(tmp[xx][yy].Type==2&&tmp[xx][yy].Age>=HreproAge&&
                                                  ((entityLife[xx][yy+1].Type==2&&entityLife[xx][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy+1].Age>=HreproAge)
                                                 ||(entityLife[xx+1][yy+1].Type==2&&entityLife[xx+1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy+1].Age>=HreproAge)
                                                 ||(entityLife[xx+1][yy].Type==2&&entityLife[xx+1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy].Age>=HreproAge)
                                                 ||(entityLife[xx+1][yy-1].Type==2&&entityLife[xx+1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy-1].Age>=HreproAge)
                                                 ||(entityLife[xx][yy-1].Type==2&&entityLife[xx][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy-1].Age>=HreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx][yy+1].Type==0)tmp[xx][yy+1].copyentity(entity(2,rand()%2,xx,yy+1));
                            else if(tmp[xx+1][yy+1].Type==0)tmp[xx+1][yy+1].copyentity(entity(2,rand()%2,xx+1,yy+1));
                            else if(tmp[xx+1][yy].Type==0)tmp[xx+1][yy].copyentity(entity(2,rand()%2,xx+1,yy));
                            else if(tmp[xx+1][yy-1].Type==0)tmp[xx+1][yy-1].copyentity(entity(2,rand()%2,xx+1,yy-1));
                            else if(tmp[xx][yy-1].Type==0)tmp[xx][yy-1].copyentity(entity(2,rand()%2,xx,yy-1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(xx+1>col-1){//��
                            if(tmp[xx][yy].Type==2&&tmp[xx][yy].Age>=HreproAge&&
                                                  ((entityLife[xx-1][yy-1].Type==2&&entityLife[xx-1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy-1].Age>=HreproAge)
                                                 ||(entityLife[xx-1][yy].Type==2&&entityLife[xx-1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy].Age>=HreproAge)
                                                 ||(entityLife[xx-1][yy+1].Type==2&&entityLife[xx-1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy+1].Age>=HreproAge)
                                                 ||(entityLife[xx][yy+1].Type==2&&entityLife[xx][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy+1].Age>=HreproAge)
                                                 ||(entityLife[xx][yy-1].Type==2&&entityLife[xx][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy-1].Age>=HreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx-1][yy-1].Type==0)tmp[xx-1][yy-1].copyentity(entity(2,rand()%2,xx-1,yy-1));
                            else if(tmp[xx-1][yy].Type==0)tmp[xx-1][yy].copyentity(entity(2,rand()%2,xx-1,yy));
                            else if(tmp[xx-1][yy+1].Type==0)tmp[xx-1][yy+1].copyentity(entity(2,rand()%2,xx-1,yy+1));
                            else if(tmp[xx][yy+1].Type==0)tmp[xx][yy+1].copyentity(entity(2,rand()%2,xx,yy+1));
                            else if(tmp[xx][yy-1].Type==0)tmp[xx][yy-1].copyentity(entity(2,rand()%2,xx,yy-1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(yy-1<0){//��
                            if(tmp[xx][yy].Type==2&&tmp[xx][yy].Age>=HreproAge&&
                                                  ((entityLife[xx-1][yy].Type==2&&entityLife[xx-1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy].Age>=HreproAge)
                                                 ||(entityLife[xx-1][yy+1].Type==2&&entityLife[xx-1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy+1].Age>=HreproAge)
                                                 ||(entityLife[xx][yy+1].Type==2&&entityLife[xx][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy+1].Age>=HreproAge)
                                                 ||(entityLife[xx+1][yy+1].Type==2&&entityLife[xx+1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy+1].Age>=HreproAge)
                                                 ||(entityLife[xx+1][yy].Type==2&&entityLife[xx+1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy].Age>=HreproAge))){
                           //Ѱ�Ҳ��пյ�
                           if(tmp[xx-1][yy].Type==0)tmp[xx-1][yy].copyentity(entity(2,rand()%2,xx-1,yy));
                            else if(tmp[xx-1][yy+1].Type==0)tmp[xx-1][yy+1].copyentity(entity(2,rand()%2,xx-1,yy+1));
                            else if(tmp[xx][yy+1].Type==0)tmp[xx][yy+1].copyentity(entity(2,rand()%2,xx,yy+1));
                            else if(tmp[xx+1][yy+1].Type==0)tmp[xx+1][yy+1].copyentity(entity(2,rand()%2,xx+1,yy+1));
                            else if(tmp[xx+1][yy].Type==0)tmp[xx+1][yy].copyentity(entity(2,rand()%2,xx+1,yy));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(yy+1>row-1){//��
                            if(tmp[xx][yy].Type==2&&tmp[xx][yy].Age>=HreproAge&&
                                                  ((entityLife[xx-1][yy-1].Type==2&&entityLife[xx-1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy-1].Age>=HreproAge)
                                                 ||(entityLife[xx-1][yy].Type==2&&entityLife[xx-1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy].Age>=HreproAge)
                                                 ||(entityLife[xx+1][yy].Type==2&&entityLife[xx+1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy].Age>=HreproAge)
                                                 ||(entityLife[xx+1][yy-1].Type==2&&entityLife[xx+1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy-1].Age>=HreproAge)
                                                 ||(entityLife[xx][yy-1].Type==2&&entityLife[xx][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy-1].Age>=HreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx-1][yy-1].Type==0)tmp[xx-1][yy-1].copyentity(entity(2,rand()%2,xx-1,yy-1));
                            else if(tmp[xx-1][yy].Type==0)tmp[xx-1][yy].copyentity(entity(2,rand()%2,xx-1,yy));
                            else if(tmp[xx+1][yy].Type==0)tmp[xx+1][yy].copyentity(entity(2,rand()%2,xx+1,yy));
                            else if(tmp[xx+1][yy-1].Type==0)tmp[xx+1][yy-1].copyentity(entity(2,rand()%2,xx+1,yy-1));
                            else if(tmp[xx][yy-1].Type==0)tmp[xx][yy-1].copyentity(entity(2,rand()%2,xx,yy-1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }

                        //��δ��ʳ,������ƶ���Health-1:
                        if(turned==0){
                            tmp[i][o].hurt();
                            if(tmp[i][o].Type==2){
                            int flag2;
                            loop2:flag2 = rand()%8;
                            switch(flag2){
                                case 0:
                                    if(i-1>=0&&o-1>=0)
                                    tmp[i-1][o-1].copyentity(tmp[i][o]);
                                    else goto loop2;
                                    break;
                                case 1:
                                    if(i-1>=0)
                                    tmp[i-1][o].copyentity(tmp[i][o]);
                                    else goto loop2;
                                    break;
                                case 2:
                                    if(i-1>=0&&o+1<=row-1)
                                    tmp[i-1][o+1].copyentity(tmp[i][o]);
                                    else goto loop2;
                                    break;
                                case 3:
                                    if(o+1<=row-1)
                                    tmp[i][o+1].copyentity(tmp[i][o]);
                                    else goto loop2;
                                    break;
                                case 4:
                                    if(i+1<=col-1&&o+1<=row-1)
                                    tmp[i+1][o+1].copyentity(tmp[i][o]);
                                    else goto loop2;
                                    break;
                                case 5:
                                    if(i+1<=col-1)
                                    tmp[i+1][o].copyentity(tmp[i][o]);
                                    else goto loop2;
                                    break;
                                case 6:
                                    if(i+1<=col-1&&o-1>=0)
                                    tmp[i+1][o-1].copyentity(tmp[i][o]);
                                    else goto loop2;
                                    break;
                                case 7:
                                    if(o-1>=0)
                                    tmp[i][o-1].copyentity(tmp[i][o]);
                                    else goto loop2;
                                    break;
                                default:cout << "System Err:008(2 Move after Eat Failed:switch)" <<endl;
                            }
                            tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                        }}
                        tmp[xx][yy].older();

                    }
        }
        for(int i=0;i<col;i++)
        for(int o=0;o<row;o++){
            if(entityLife[i][o].Type==3){cout<<"3";//�������
                        srand((unsigned)time(NULL));//���������
                        int flag1 = rand()%8;//���ڽ�ʳ��rand
                        int turned = 0;//��¼�Ƿ��ƶ�λ��
                        int fl;//��¼�ƶ����ĸ�λ��
                        for(int m=0;m<8&&turned==0;m++){  //��ʳ
                            fl = (flag1+m)%8;
                            switch(fl){
                                case 0:
                                    if(i-1>=0&&o-1>=0)
                                    if(entityLife[i-1][o-1].Type==2){
                                        tmp[i-1][o-1].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i-1][o-1].recover();
                                    }
                                    break;
                                case 1:
                                    if(i-1>=0)
                                    if(entityLife[i-1][o].Type==2){
                                        tmp[i-1][o].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i-1][o].recover();
                                    }
                                    break;
                                case 2:
                                    if(i-1>=0&&o+1<=row-1)
                                    if(entityLife[i-1][o+1].Type==2){
                                        tmp[i-1][o+1].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i-1][o+1].recover();
                                    }
                                    break;
                                case 3:
                                    if(o+1<=row-1)
                                    if(entityLife[i][o+1].Type==2){
                                        tmp[i][o+1].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i][o+1].recover();
                                    }
                                    break;
                                case 4:
                                    if(i+1<=col-1&&o+1<=row-1)
                                    if(entityLife[i+1][o+1].Type==2){
                                        tmp[i+1][o+1].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i+1][o+1].recover();
                                    }
                                    break;
                                case 5:
                                    if(i+1<=col-1)
                                    if(entityLife[i+1][o].Type==2){
                                        tmp[i+1][o].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i+1][o].recover();
                                    }
                                    break;
                                case 6:
                                    if(i+1<=col-1&&o-1>=0)
                                    if(entityLife[i+1][o-1].Type==2){
                                        tmp[i+1][o-1].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i+1][o-1].recover();
                                    }
                                    break;
                                case 7:
                                    if(o-1>=0)
                                    if(entityLife[i][o-1].Type==2){
                                        tmp[i][o-1].copyentity(entityLife[i][o]);//�ƶ�
                                        tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                                        turned = 1;
                                        tmp[i][o-1].recover();
                                    }
                                    break;
                                default:cout << "System Err:010(3 Eat Err:switch)" <<endl;
                            }
                        }
                        if(turned==0)tmp[i][o].copyentity(entityLife[i][o]);//��ʳʧ�ܴ���
                        //��ʳ����
                        //׷��λ��:
                        int xx,yy;
                        if(turned==1){
                            switch(fl){
                                case 0:xx=i-1;yy=o-1;break;
                                case 1:xx=i-1;yy=o;break;
                                case 2:xx=i-1;yy=o+1;break;
                                case 3:xx=i;yy=o+1;break;
                                case 4:xx=i+1;yy=o+1;break;
                                case 5:xx=i+1;yy=o;break;
                                case 6:xx=i+1;yy=o-1;break;
                                case 7:xx=i;yy=o-1;break;
                            }
                        }
                        else{
                            xx=i;yy=o;
                        }
                        //��ֳ (��CreproAge�꼰���Ͽ��Է�ֳ)
                        if(xx-1>=0&&yy-1>=0&&xx+1<=col-1&&yy+1<=row-1){
                        if(tmp[xx][yy].Type==3&&tmp[xx][yy].Age>=CreproAge&&
                                                  ((entityLife[xx-1][yy-1].Type==3&&entityLife[xx-1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy-1].Age>=CreproAge)
                                                 ||(entityLife[xx-1][yy].Type==3&&entityLife[xx-1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy].Age>=CreproAge)
                                                 ||(entityLife[xx-1][yy+1].Type==3&&entityLife[xx-1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy+1].Age>=CreproAge)
                                                 ||(entityLife[xx][yy+1].Type==3&&entityLife[xx][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy+1].Age>=CreproAge)
                                                 ||(entityLife[xx+1][yy+1].Type==3&&entityLife[xx+1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy+1].Age>=CreproAge)
                                                 ||(entityLife[xx+1][yy].Type==3&&entityLife[xx+1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy].Age>=CreproAge)
                                                 ||(entityLife[xx+1][yy-1].Type==3&&entityLife[xx+1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy-1].Age>=CreproAge)
                                                 ||(entityLife[xx][yy-1].Type==3&&entityLife[xx][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy-1].Age>=CreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx-1][yy-1].Type==0)tmp[xx-1][yy-1].copyentity(entity(3,rand()%2,xx-1,yy-1));
                            else if(tmp[xx-1][yy].Type==0)tmp[xx-1][yy].copyentity(entity(3,rand()%2,xx-1,yy));
                            else if(tmp[xx-1][yy+1].Type==0)tmp[xx-1][yy+1].copyentity(entity(3,rand()%2,xx-1,yy+1));
                            else if(tmp[xx][yy+1].Type==0)tmp[xx][yy+1].copyentity(entity(3,rand()%2,xx,yy+1));
                            else if(tmp[xx+1][yy+1].Type==0)tmp[xx+1][yy+1].copyentity(entity(3,rand()%2,xx+1,yy+1));
                            else if(tmp[xx+1][yy].Type==0)tmp[xx+1][yy].copyentity(entity(3,rand()%2,xx+1,yy));
                            else if(tmp[xx+1][yy-1].Type==0)tmp[xx+1][yy-1].copyentity(entity(3,rand()%2,xx+1,yy-1));
                            else if(tmp[xx][yy-1].Type==0)tmp[xx][yy-1].copyentity(entity(3,rand()%2,xx,yy-1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(xx-1<0&&yy-1<0){//����
                            if(tmp[xx][yy].Type==3&&tmp[xx][yy].Age>=CreproAge&&
                                                  ((entityLife[xx][yy+1].Type==3&&entityLife[xx][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy+1].Age>=CreproAge)
                                                 ||(entityLife[xx+1][yy+1].Type==3&&entityLife[xx+1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy+1].Age>=CreproAge)
                                                 ||(entityLife[xx+1][yy].Type==3&&entityLife[xx+1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy].Age>=CreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx][yy+1].Type==0)tmp[xx][yy+1].copyentity(entity(3,rand()%2,xx,yy+1));
                            else if(tmp[xx+1][yy+1].Type==0)tmp[xx+1][yy+1].copyentity(entity(3,rand()%2,xx+1,yy+1));
                            else if(tmp[xx+1][yy].Type==0)tmp[xx+1][yy].copyentity(entity(3,rand()%2,xx+1,yy));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(xx-1<0&&yy+1>row-1){//����
                            if(tmp[xx][yy].Type==3&&tmp[xx][yy].Age>=CreproAge&&
                                                  ((entityLife[xx+1][yy].Type==3&&entityLife[xx+1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy].Age>=CreproAge)
                                                 ||(entityLife[xx+1][yy-1].Type==3&&entityLife[xx+1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy-1].Age>=CreproAge)
                                                 ||(entityLife[xx][yy-1].Type==3&&entityLife[xx][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy-1].Age>=CreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx+1][yy].Type==0)tmp[xx+1][yy].copyentity(entity(3,rand()%2,xx+1,yy));
                            else if(tmp[xx+1][yy-1].Type==0)tmp[xx+1][yy-1].copyentity(entity(3,rand()%2,xx+1,yy-1));
                            else if(tmp[xx][yy-1].Type==0)tmp[xx][yy-1].copyentity(entity(3,rand()%2,xx,yy-1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(xx+1>col-1&&yy-1<0){//����
                            if(tmp[xx][yy].Type==3&&tmp[xx][yy].Age>=CreproAge&&
                                                  ((entityLife[xx-1][yy].Type==3&&entityLife[xx-1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy].Age>=CreproAge)
                                                 ||(entityLife[xx-1][yy+1].Type==3&&entityLife[xx-1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy+1].Age>=CreproAge)
                                                 ||(entityLife[xx][yy+1].Type==3&&entityLife[xx][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy+1].Age>=CreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx-1][yy].Type==0)tmp[xx-1][yy].copyentity(entity(3,rand()%2,xx-1,yy));
                            else if(tmp[xx-1][yy+1].Type==0)tmp[xx-1][yy+1].copyentity(entity(3,rand()%2,xx-1,yy+1));
                            else if(tmp[xx][yy+1].Type==0)tmp[xx][yy+1].copyentity(entity(3,rand()%2,xx,yy+1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(xx+1>col-1&&yy+1>row-1){//����
                            if(tmp[xx][yy].Type==3&&tmp[xx][yy].Age>=CreproAge&&
                                                  ((entityLife[xx-1][yy-1].Type==3&&entityLife[xx-1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy-1].Age>=CreproAge)
                                                 ||(entityLife[xx-1][yy].Type==3&&entityLife[xx-1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy].Age>=CreproAge)
                                                 ||(entityLife[xx][yy-1].Type==3&&entityLife[xx][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy-1].Age>=CreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx-1][yy-1].Type==0)tmp[xx-1][yy-1].copyentity(entity(3,rand()%2,xx-1,yy-1));
                            else if(tmp[xx-1][yy].Type==0)tmp[xx-1][yy].copyentity(entity(3,rand()%2,xx-1,yy));
                            else if(tmp[xx][yy-1].Type==0)tmp[xx][yy-1].copyentity(entity(3,rand()%2,xx,yy-1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(xx-1<0){//��
                            if(tmp[xx][yy].Type==3&&tmp[xx][yy].Age>=CreproAge&&
                                                  ((entityLife[xx][yy+1].Type==3&&entityLife[xx][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy+1].Age>=CreproAge)
                                                 ||(entityLife[xx+1][yy+1].Type==3&&entityLife[xx+1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy+1].Age>=CreproAge)
                                                 ||(entityLife[xx+1][yy].Type==3&&entityLife[xx+1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy].Age>=CreproAge)
                                                 ||(entityLife[xx+1][yy-1].Type==3&&entityLife[xx+1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy-1].Age>=CreproAge)
                                                 ||(entityLife[xx][yy-1].Type==3&&entityLife[xx][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy-1].Age>=CreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx][yy+1].Type==0)tmp[xx][yy+1].copyentity(entity(3,rand()%2,xx,yy+1));
                            else if(tmp[xx+1][yy+1].Type==0)tmp[xx+1][yy+1].copyentity(entity(3,rand()%2,xx+1,yy+1));
                            else if(tmp[xx+1][yy].Type==0)tmp[xx+1][yy].copyentity(entity(3,rand()%2,xx+1,yy));
                            else if(tmp[xx+1][yy-1].Type==0)tmp[xx+1][yy-1].copyentity(entity(3,rand()%2,xx+1,yy-1));
                            else if(tmp[xx][yy-1].Type==0)tmp[xx][yy-1].copyentity(entity(3,rand()%2,xx,yy-1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(xx+1>col-1){//��
                            if(tmp[xx][yy].Type==3&&tmp[xx][yy].Age>=CreproAge&&
                                                  ((entityLife[xx-1][yy-1].Type==3&&entityLife[xx-1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy-1].Age>=CreproAge)
                                                 ||(entityLife[xx-1][yy].Type==3&&entityLife[xx-1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy].Age>=CreproAge)
                                                 ||(entityLife[xx-1][yy+1].Type==3&&entityLife[xx-1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy+1].Age>=CreproAge)
                                                 ||(entityLife[xx][yy+1].Type==3&&entityLife[xx][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy+1].Age>=CreproAge)
                                                 ||(entityLife[xx][yy-1].Type==3&&entityLife[xx][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy-1].Age>=CreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx-1][yy-1].Type==0)tmp[xx-1][yy-1].copyentity(entity(3,rand()%2,xx-1,yy-1));
                            else if(tmp[xx-1][yy].Type==0)tmp[xx-1][yy].copyentity(entity(3,rand()%2,xx-1,yy));
                            else if(tmp[xx-1][yy+1].Type==0)tmp[xx-1][yy+1].copyentity(entity(3,rand()%2,xx-1,yy+1));
                            else if(tmp[xx][yy+1].Type==0)tmp[xx][yy+1].copyentity(entity(3,rand()%2,xx,yy+1));
                            else if(tmp[xx][yy-1].Type==0)tmp[xx][yy-1].copyentity(entity(3,rand()%2,xx,yy-1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(yy-1<0){//��
                            if(tmp[xx][yy].Type==3&&tmp[xx][yy].Age>=CreproAge&&
                                                  ((entityLife[xx-1][yy].Type==3&&entityLife[xx-1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy].Age>=CreproAge)
                                                 ||(entityLife[xx-1][yy+1].Type==3&&entityLife[xx-1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy+1].Age>=CreproAge)
                                                 ||(entityLife[xx][yy+1].Type==3&&entityLife[xx][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy+1].Age>=CreproAge)
                                                 ||(entityLife[xx+1][yy+1].Type==3&&entityLife[xx+1][yy+1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy+1].Age>=CreproAge)
                                                 ||(entityLife[xx+1][yy].Type==3&&entityLife[xx+1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy].Age>=CreproAge))){
                           //Ѱ�Ҳ��пյ�
                           if(tmp[xx-1][yy].Type==0)tmp[xx-1][yy].copyentity(entity(3,rand()%2,xx-1,yy));
                            else if(tmp[xx-1][yy+1].Type==0)tmp[xx-1][yy+1].copyentity(entity(3,rand()%2,xx-1,yy+1));
                            else if(tmp[xx][yy+1].Type==0)tmp[xx][yy+1].copyentity(entity(3,rand()%2,xx,yy+1));
                            else if(tmp[xx+1][yy+1].Type==0)tmp[xx+1][yy+1].copyentity(entity(3,rand()%2,xx+1,yy+1));
                            else if(tmp[xx+1][yy].Type==0)tmp[xx+1][yy].copyentity(entity(3,rand()%2,xx+1,yy));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }else if(yy+1>row-1){//��
                            if(tmp[xx][yy].Type==3&&tmp[xx][yy].Age>=CreproAge&&
                                                  ((entityLife[xx-1][yy-1].Type==3&&entityLife[xx-1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy-1].Age>=CreproAge)
                                                 ||(entityLife[xx-1][yy].Type==3&&entityLife[xx-1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx-1][yy].Age>=CreproAge)
                                                 ||(entityLife[xx+1][yy].Type==3&&entityLife[xx+1][yy].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy].Age>=CreproAge)
                                                 ||(entityLife[xx+1][yy-1].Type==3&&entityLife[xx+1][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx+1][yy-1].Age>=CreproAge)
                                                 ||(entityLife[xx][yy-1].Type==3&&entityLife[xx][yy-1].Gender==1-tmp[xx][yy].Gender&&entityLife[xx][yy-1].Age>=CreproAge))){
                           //Ѱ�Ҳ��пյ�
                            if(tmp[xx-1][yy-1].Type==0)tmp[xx-1][yy-1].copyentity(entity(3,rand()%2,xx-1,yy-1));
                            else if(tmp[xx-1][yy].Type==0)tmp[xx-1][yy].copyentity(entity(3,rand()%2,xx-1,yy));
                            else if(tmp[xx+1][yy].Type==0)tmp[xx+1][yy].copyentity(entity(3,rand()%2,xx+1,yy));
                            else if(tmp[xx+1][yy-1].Type==0)tmp[xx+1][yy-1].copyentity(entity(3,rand()%2,xx+1,yy-1));
                            else if(tmp[xx][yy-1].Type==0)tmp[xx][yy-1].copyentity(entity(3,rand()%2,xx,yy-1));
                            //else ��Ϊû�пյز��з�ֳʧ��
                            }
                        }

                        //��δ��ʳ,������ƶ���Health-1:
                        if(turned==0){
                            tmp[i][o].hurt();
                            if(tmp[i][o].Type==3){
                            int flag2;
                            loop:flag2 = rand()%8;
                            switch(flag2){
                                case 0:
                                    if(i-1>=0&&o-1>=0)
                                    tmp[i-1][o-1].copyentity(tmp[i][o]);
                                    else goto loop;
                                    break;
                                case 1:
                                    if(i-1>=0)
                                    tmp[i-1][o].copyentity(tmp[i][o]);
                                    else goto loop;
                                    break;
                                case 2:
                                    if(i-1>=0&&o+1<=row-1)
                                    tmp[i-1][o+1].copyentity(tmp[i][o]);
                                    else goto loop;
                                    break;
                                case 3:
                                    if(o+1<=row-1)
                                    tmp[i][o+1].copyentity(tmp[i][o]);
                                    else goto loop;
                                    break;
                                case 4:
                                    if(i+1<=col-1&&o+1<=row-1)
                                    tmp[i+1][o+1].copyentity(tmp[i][o]);
                                    else goto loop;
                                    break;
                                case 5:
                                    if(i+1<=col-1)
                                    tmp[i+1][o].copyentity(tmp[i][o]);
                                    else goto loop;
                                    break;
                                case 6:
                                    if(i+1<=col-1&&o-1>=0)
                                    tmp[i+1][o-1].copyentity(tmp[i][o]);
                                    else goto loop;
                                    break;
                                case 7:
                                    if(o-1>=0)
                                    tmp[i][o-1].copyentity(tmp[i][o]);
                                    else goto loop;
                                    break;
                                default:cout << "System Err:008(2 Move after Eat Failed:switch)" <<endl;
                            }
                            tmp[i][o].copyentity(entity(0,3,i,o));//���ÿյ�
                        }}
                        tmp[xx][yy].older();

                    }
        }
    Traverse();//����ǰ����
    for(int i=0;i<col;i++)//����ת��
        for(int o=0;o<row;o++){
            entityLife[i][o].copyentity(tmp[i][o]);
        }
    Traverse();//���Ǻ����
    system("cls");//����
    Display();//���
}
