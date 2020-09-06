#include<bits/stdc++.h>

using namespace std;

entity::entity(){
    Type=5;
    X=-1; Y=-1; Gender=3; Age=-1; Health=-1;
}

entity::entity(unsigned int type,unsigned int gender,int x,int y){
    if(type==0){
        Type=0; Gender=3; X=x; Y=y; Age=0; Health=-1;
    }else if(type==1){
        Type=1; Gender=3; X=x; Y=y; Age=0; Health=-1;
    }else if(type==2){
        Type=2; Gender=gender; X=x; Y=y; Age=0; Health=Hheal;
    }else if(type==3){
        Type=3; Gender=gender; X=x; Y=y; Age=0; Health=Cheal;
    }else{
        Type=5; Gender=3; X=-1; Y=-1; Age=-1; Health=-1;
        cout << "System Err:001(实体创建异常type)" <<endl;
    }
}

void entity::copyentity(const entity& k){
    Type=k.Type;
    Gender=k.Gender;
    X=k.X;
    Y=k.Y;
    Age=k.Age;
    Health=k.Health;
}

void entity::older(){
    Age+=1;
}

void entity::hurt(){
    Health-=1;
    if(Health==0){Type=0; Gender=3; Age=0; Health=-1;}//生命值降空后死亡
}

void entity::recover(){
    if(Type!=2&&Type!=3)cout << "System Err:007(Recover Err)" <<endl;
    else if(Type==2)Health=Hheal;
    else if(Type==3)Health=Cheal;
}

void entity::dp(){
    cout<<"("
        <<"Type="<<Type<<","
        <<"Gender="<<Gender<<","
        <<"X="<<X<<","
        <<"Y="<<Y<<","
        <<"Age="<<Age<<","
        <<"Health=";
        if(Health==-1)cout<<"Null";else cout<<Health;
        cout<<")"<<endl;
}

string entity::getstring(){
    ostringstream ss;
    ss<<"("
        <<"Type= "<<Type<<" ,"
        <<"Gender= "<<Gender<<" ,"
        <<"X= "<<X<<" ,"
        <<"Y= "<<Y<<" ,"
        <<"Age= "<<Age<<" ,"
        <<"Health= "<<Health;
    ss<<" )";
    string os = ss.str();
    return os;
}
