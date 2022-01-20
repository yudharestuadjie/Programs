#include <iostream>

using namespace std;

class hewan
 {
  public:
    void sh() 
    {
    cout<< "Suaranya seperti : \n" ;
  }
};

class Kucing : public hewan 
{
  public:
    void sh() {
    cout<< "Kucing : Meong \n" ;
  }
};

class anjing : public hewan 
{
  public:
    void sh() {
    cout << "Anjing : guk guk \n" ;
  }
};