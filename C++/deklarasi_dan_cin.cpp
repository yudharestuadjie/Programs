#include <iostream>

using namespace std;

int main()
{/*|-------------------|
   | int a;            |
   | a=23;             | Deklarasi interger biasa dimana nilai interger sudah ditentukan
   | cout<<a<<endl;    |
   |-------------------|*/

//Deklarasi interger yang ditentukan berdasarkan nilai yang diinput oleh user

    int b; //di baris ini integer b (masih dalam kondisi kosong, karena tidak ada pernyataan "b=2" dll)
    cout<<"Masukan angka : "<<endl; //baris cout ini berguna sebagai header tidak dipakaipun tidak apa apa
    cin>>b;//cin ini menyuruh kita untuk memasukan nilai untuk interger b
    cout<<"Ok, "<< b << "angka ini sekarang jadi milikmu"<<endl; /*baris ini bertujuan untuk menampilkan nilai dari si interger b 
                                                                   setelah sebelumnya nilai interger b diinput berdasarkan keinginan si user*/

    return 0;
}