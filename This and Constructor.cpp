#include <iostream>

using namespace std;
class hero{
    public:
    int health;
    char level;
    //hero()
    //{
    //    cout<<"constructor called"<<endl;
    //}
    
    hero(int health)  //constructor  
    {
        this->health=health;
        cout<<"constructor called"<<endl;
    }
};
int main()
{
    cout<<"hello"<<endl;
    hero obj1(20);  //constructor called
    cout<<obj1.health<<endl;
    cout<<"world"<<endl;
    
}
