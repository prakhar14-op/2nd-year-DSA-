#include<iostream>
using namespace std;
class Hero{
    private:
    int health;
    char name[100];
    public:
    char level;

    void print(){
        cout<<level<<endl;
    }

    int gethealth(){
        return health;
    }
    void sethealth(int h){
        health=h;
    }
    void setlevel(int l){
        level=l;
    }
};
int main(){

    // stastics allocation
    Hero h1;
    h1.sethealth(70);
    h1.gethealth();
    h1.level='A';
    cout<<"size: "<<sizeof(h1)<<endl;
    cout<<"health is:"<<h1.gethealth()<<endl;
    cout<<"level :"<<h1.level<<endl;

    // dyanmic allocation
    cout<<"using dyanmic allocation"<<endl;
    Hero *b=new Hero;
    (*b).sethealth(70);
    (*b).setlevel('A');
    cout<<"health is:"<<(*b).gethealth()<<endl;
    cout<<"level :"<<(*b).level<<endl;
}
