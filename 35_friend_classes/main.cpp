#include<iostream>

using namespace std;

class A
{
    private:
        float mVal;
        // make a friend
        friend class B;
};

class B
{
    public:
        B(){}
        void DoSomethingWithA(A& a)
        {
            // let's access some private variables
            // since B is friend with A
            a.mVal = 5;
            std::cout << a.mVal << std::endl;
        }
};

int main(int argc, const char * argv[])
{
    A a;
    B b;
    
    b.DoSomethingWithA(a);
    
    return 0;
}
