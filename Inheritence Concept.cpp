#include <iostream>

using namespace std;
class human{
    public:
    int health;
    int age;
   
    void setHealth(int h)
    { 
        this->health=h;
    }
    void setAge(int a)
    {
        this->age=a;
    }
     int getHealth()
    {
        return this->health;
    }
    int getAge()
    {
        return this->age;
    }
};

class male: public human{
    public:
    void attack()
    {
        cout<<"he kicks the shit out of you"<<endl;
    }
    
};
class female: public human{
    public:
    void attack()
    {
        cout<<"she is gonna burn your inside out with a death stare"<<endl;
    }
};

int main()
{
    male object1;
    female object2;
    object1.setHealth(100);
    object2.setHealth(200);
    object1.setAge(25);
    object2.setAge(25);
    cout<<"the health of male is "<<object1.getHealth()<<endl;;
    cout<<"the age os male is "<<object1.getAge()<<endl;
    cout<<"male attack perk: ";
    object1.attack();
    cout<<"the health of female is "<<object2.getHealth()<<endl;
    cout<<"the age of female is "<< object2.getAge()<<endl;
    cout<<"female attack perk: ";
    object2.attack();
}
