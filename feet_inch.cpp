#include<iostream>

using namespace std;

class Distance{
    private:
    int _feet = 0;
    int _inch = 0;

    public:
    void getData(int a, int b);
    void showData();
    void add(Distance a,Distance b);
    Distance* add(Distance a);
};

void Distance :: getData(int a , int b){
    _feet = a;
    _inch = b;
}

void Distance :: showData(){
    cout << "Feet = " << _feet << " & Inch = " <<_inch << endl;
}

void Distance :: add(Distance a, Distance b){
    _feet = a._feet + b._feet;
    _inch = a._inch + b._inch;
    _feet += _inch/12;
    _inch = _inch%12;
}

Distance* Distance :: add(Distance a){
    _feet += a._feet ;
    _inch += a._inch ;
    _feet += _inch/12;
    _inch = _inch%12;

    return this;
}

int main(){
    Distance c1,c2,c3;
    Distance *c4;
    c1.getData(2,3);
    c2.getData(3,10);
    c3.add(c1,c2);
    c4 = c1.add(c2);

    c3.showData();
    c4->showData();

}