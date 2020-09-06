#ifndef ECOSYSTEM_H_INCLUDED
#define ECOSYSTEM_H_INCLUDED

using namespace std;

extern int col;
extern int row;//初始化生态系统大小<col*row>
extern int TurnGrass;//空地变为青草地的概率
extern int HreproAge;//食草动物允许繁殖年龄
extern int CreproAge;//食肉动物允许繁殖年龄

class ecosystem:public space{

public:
    entity **entityLife;

    void generateEco();//初始化->生成
    void Display();//输出
    void Traverse();//遍历
    void Develop();//演化
    void Show();//输出全体个体信息

};

#endif // ECOSYSTEM_H_INCLUDED
