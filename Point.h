#ifndef TAST101_POINT_H
#define TAST101_POINT_H
#include <ostream>
#include <iostream>
template <class T>
class Point
{
public:
    Point(T x,T y)
            :x_(x),y_(y)
    {}
    Point()
            :x_(0),y_(0)
    {}

    T x_,y_;
//Overload + operator to add two Points objects.
  Point<T> operator+(Point&p);

  Point<T> operator-(Point&p);

  Point<T> operator*(const int v);
};

template <class T>
Point<T> Point<T>::operator+(Point<T> &B) {
    /*Point<T> A;
    this->x_+=B.x_;
    this->y_+=B.y_;
    return A;*/
    Point<T> newA;
    newA = *this;//this is pointer,*this get the value of the A , and affect to A
    newA.x_ += B.x_;
    newA.y_ += B.y_;
    return newA;
}
template <class T>
Point<T> Point<T>::operator-(Point<T> &B) {
    Point<T> newA;
    newA = *this;//this is pointer,*this get the value of the A , and affect to A
    newA.x_ -= B.x_;
    newA.y_ -= B.y_;
    return newA;
}
template <class T>
Point<T> Point<T>::operator*(const int v) {
    Point<T> A;
    A = *this;
    A.x_*=v;
    A.y_*=v;
    return A;
}

#endif //TAST101_POINT_CLASS_H
/*
std::ostream& operator<<(std::ostream&o, const Point& p);
*/
/*
#ifndef TAST101_POINT_H
#define TAST101_POINT_H

#include <ostream>

class Point
{
public:
    Point(int x,int y)
            :x_(x),y_(y)
    {}
    Point()
            :x_(0),y_(0)
    {}
    //copy constructor
    Point(const Point &p)
            :x_(p.x_),y_(p.y_)
    {}

    //move constructor
    Point(Point &&p)
            :x_(std::move(p.x_)),y_(std::move(p.y_))
    {}

    int x_,y_;

   Point operator+(Point&p);
   Point operator-(Point&p);
   Point operator*(const int v);
};
#endif //TAST101_POINT_CLASS_H
 */