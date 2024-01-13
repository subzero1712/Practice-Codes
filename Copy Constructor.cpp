#include <iostream>

using namespace std;
class hero{
    public:
    int health;
    char level;
    void print()
    {
        cout<<"the health is "<<this->health<<endl;
        cout<<"the level is "<<this->level<<endl;
    }
    hero(hero& temp){                            //this is how copy constructor are made in the class
        cout<<"copy constructor callec"<<endl;
    }
    hero(int health)
    {
        cout<<"constructor called"<<endl;
    }
    
    hero(int health, char level)  //constructor  
    {
        this->health=health;
        this->level=level;
        cout<<"constructor called"<<endl;
    }
};
int main()
{
  
    hero obj1(20,'B');   //constructor called
    hero obj2(obj1);
    obj1.print();
    obj2.print();
    
    
}
