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
    hero(int health)
    {
        cout<<"constructor called"<<endl;
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
    
    
}
