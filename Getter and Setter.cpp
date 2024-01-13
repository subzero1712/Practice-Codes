#include <iostream>

using namespace std;

class hero{
    private:
    int health;
    public:
    char level;
    int getHealth()
    {
        return health;
    }
    void setHealth(int h)
    {
        health = h;
    }
    
    
};
int main()
{
    hero obj1;
    //obj1.health=150;
    obj1.level='B';
    obj1.setHealth(100);
    cout<<"the health is: "<<obj1.getHealth()<<endl;
    cout<<"the level is: "<<obj1.level<<endl;
}
