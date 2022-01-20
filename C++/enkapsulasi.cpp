#include <iostream>

using namespace std;

class rumah 
{
    private:
    int kamar;

    public:
    void setkamar(int k)
    {
        kamar = k;
    }
    int getkamar()
    {
        return kamar;
    }
};

int main()
{
    rumah myOBJ;
    myOBJ.setkamar(200000);
    cout<<endl;
    cout<<endl;
    cout<< myOBJ.getkamar();
    return 0;
}

