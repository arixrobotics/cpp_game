#include <iostream>

using namespace std;

class Vec2D
{
    public:
    static const Vec2D Zero;
    
    Vec2D(): Vec2D(0,0){}
    Vec2D(float x, float y): mX(x), mY(y)
    {

    }

    inline void SetX(float x) {mX = x;}
    inline void SetY(float y) {mY = y;}
    inline float GetX() const {return mX;}
    inline float GetY() const {return mY;}
    
    void Display() const
    {
        std::cout<< "X: " << mX << ", Y: " << mY << std::endl;
    }
    
    // let's define an insertion operator using the friend keyword
    //friend void operator<<(std::ostream & consoleOut, const Vec2D& vec);
    friend ostream& operator<<(std::ostream & consoleOut, const Vec2D& vec);
    
    private:
    float mX;
    float mY;
};

// now, outside the class, we can access the private members
//void operator<<(std::ostream & consoleOut, const Vec2D& vec)
//{
//    consoleOut<< "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
//}
ostream& operator<<(std::ostream & consoleOut, const Vec2D& vec)
{
    consoleOut<< "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
    return consoleOut;
}
   
const Vec2D Vec2D::Zero;

int main(int argc, const char * argv[])
{
    Vec2D aVec(10, 5);
    Vec2D bVec(13, 9);
    
    cout << aVec << bVec << endl;
    
    return 0;
}
