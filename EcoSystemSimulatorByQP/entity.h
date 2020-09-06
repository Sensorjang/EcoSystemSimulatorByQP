#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

using namespace std;

extern int Hheal;//食草动物最大健康值
extern int Cheal;//食肉动物最大健康值

class entity{

public:

    int X;//x坐标
    int Y;//y坐标
    int Age;//年龄
    unsigned int Gender;//意义 : 0:male雄性 1:female雌性  3:Unknowed未知
    int Health;//生命值
    unsigned int Type;//意义:  0:Empty空地 1:Grass草地 2:Herbivores食草动物 3:Carnivores食肉动物 5:Unknowed未知

    entity();
    entity(unsigned int type,unsigned int gender,int x,int y);
    ~entity(){}
    void copyentity(const entity& k);
    void older();
    void hurt();
    void recover();
    void dp();
    string getstring();

    //for输出
    friend ostream& operator<<(ostream &output,const entity &e){//运算符<<
            if(e.Type==0)output<<"   ";
            else if(e.Type==1)output<<" G ";
            else if(e.Type==2)output<<" H ";
            else if(e.Type==3)output<<" C ";
            else output<<"System Err:002(实体输出异常overwrite:<<)";
            return output;
        }

};
#endif // ENTITY_H_INCLUDED
