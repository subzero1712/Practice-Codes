#include <iostream>
#include<string.h>
using namespace std;
class hero{
    public:
    char *name;
    int health;
    char level;
    void print()
    {
        cout<<"the name is: "<<this->name<<endl;
        cout<<"the health is "<<this->health<<endl;
        cout<<"the level is "<<this->level<<endl;
    }
    hero()
    {
        cout<<"simple constructor called"<<endl;
        name = new char[10];
    }

    int getHealth()
    {
        return health;
    }
    int getLevel()
    {
        return level;
    }
    void setHealth(int h)
    {
        health=h;
    }
    void setLevel(int l)
    {
        level=l;
    }
    void setName(char name[])
    {
        strcpy(this->name,name);
    }
  
    hero(hero& temp)
    {
        char *ch= new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;
        
    }
};
int main()
{
    hero obj1;
    obj1.setHealth(10);   //constructor called
    obj1.setLevel('A');
    char name[10]="palak";
    obj1.setName(name);
    hero obj2(obj1);
    obj1.print();
    obj2.print();
    obj1.name[0]='j';
    obj1.print();
    obj2.print();
    
    
}
