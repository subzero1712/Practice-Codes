#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int Rs100, Rs50, Rs20, Rs1;
    switch(1){
        case 1: Rs100=n/100;
                n=n%100;
                cout<<"the number of 100 rupee note is "<< Rs100<<endl;
        case 2: Rs50=n/50;
                n=n%50;
                cout<<"the number of 50 rupee note is "<< Rs50<<endl;
        case 3: Rs20=n/20;
                n=n%20;
                cout<<"the number of 20 rupee note is "<< Rs20<<endl;
        case 4: Rs1=n/1;
                cout<<"the  number of 1 rupee note is "<< Rs1<<endl;
                
    }
    
}
