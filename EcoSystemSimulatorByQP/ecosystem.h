#ifndef ECOSYSTEM_H_INCLUDED
#define ECOSYSTEM_H_INCLUDED

using namespace std;

extern int col;
extern int row;//��ʼ����̬ϵͳ��С<col*row>
extern int TurnGrass;//�յر�Ϊ��ݵصĸ���
extern int HreproAge;//ʳ�ݶ�������ֳ����
extern int CreproAge;//ʳ�⶯������ֳ����

class ecosystem:public space{

public:
    entity **entityLife;

    void generateEco();//��ʼ��->����
    void Display();//���
    void Traverse();//����
    void Develop();//�ݻ�
    void Show();//���ȫ�������Ϣ

};

#endif // ECOSYSTEM_H_INCLUDED
