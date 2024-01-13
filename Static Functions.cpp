#include <iostream>
#include<string.h>
using namespace std;
class hero{
    public:
    char *name;
    int health;
    char level;
    static int timetocomplete;
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
  
    
    static int random()
    {
        return timetocomplete;
    }
    
};
int hero::timetocomplete=10;

int main()
{
    cout<<hero::random()<<endl;
    hero obj1;
    hero *obj2 = new hero();
    delete obj2;
   
}
