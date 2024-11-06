#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()
    {
        cout << "Construct\n";
        x = y = 0;
    }
    Point(int x1, int y1)
    {
        cout << "Construct by 2 param\n";
        x = x1;
        y = y1;
    }
    void Init()
    {
        x = rand() % 10;
        y = rand() % 10;
    }
    void Init(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    void Output()
    {
        cout << "X: " << x << "\tY: " << y << endl;
    }

    Point operator+(Point& b)
    {
        Point temp;
        temp.x = this->x + b.x;
        temp.y = this->y + b.y;
        return temp;
    }
    Point operator+(int a)
    {
        Point temp(x + a, y + a);
        return temp;
    }
    int GetX() const
    {
        return x;
    }
    int GetY() const
    {
        return y;
    }
    void SetX(int a)
    {
        x = a;
    }
    void SetY(int a)
    {
        y = a;
    }
    friend ostream& operator<<(ostream& os, const Point& point);
    friend istream& operator>>(istream& is, Point& point);
};
ostream& operator<<(ostream& os, const Point& point)
{
    os << "X: " << point.x << "\tY: " << point.y;
    return os;
}
istream& operator>>(istream& is, Point& point)
{
    cout << "Enter X: ";
    is >> point.x;
    cout << "Enter Y: ";
    is >> point.y;
    return is;
}

int main()
{
    Point a;
    cin >> a;  
    cout << a;   
}
