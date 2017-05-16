#include <iostream>
#include "Point.h"
using namespace std;
int main(int argc, char** argv) {

    Point<int> A(25,30);
    Point<int> B(20,40);
    Point<int> C=A+B;
    Point<int> D=A-B;
               A=A*2;
    //typedef Point<int> IntPoint;
    cout<<"A+B value is:="<< C.x_ <<endl;
    cout<<"A-B value is:="<< D.y_ <<endl;
    cout<<"2A:="<< A.x_ <<endl;
    return 0;
}


/*

#include <iostream>
# include "Point.h"
using namespace std;

int main(int argc, char** argv) {

Point A(25,30);
Point B(50,20);
Point C = A + B;
Point D = A - B;
Point E = A * 2;
//copy E to F;
Point F(E);
// move A to G;
Point G(std::move(A));
cout<<"A+B value is:="<< C.x_ <<endl;
cout<<"A-B value is:="<< D.x_ <<endl;
cout<<"A*3 value is:="<< E.x_ <<endl;
cout<<"copy F to E :="<< F.x_ <<";"<<F.y_<<endl;
cout<<"move A to G :="<< G.x_<<endl;
    return 0;
}

 */