#include <test.hpp>

int main(){
    int n=10;
    cout<<"Variable is:"<<n<<"\n";
    int a,b,c;
    a=get_square(n);
    b=get_cube(n);
    c=get_square(b);
    cout<<"Square of variable: "<<a<<"\n";
    cout<<"Cube of variable: "<<b<<"\n";
    cout<<"Square of cube of variable: "<<c<<"\n";
    return 0;
}