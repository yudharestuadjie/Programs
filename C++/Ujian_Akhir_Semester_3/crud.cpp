#include <iostream>
#include <mysql/mysql.h>
#include <sstream>

using namespace std;

int pilih;
char kembali;
const char* hostname = "127.0.0.1";
const char* user = "root";
const char* pass = "";
const char* dbname = "uas";
unsigned int port = 3306;
const char* unixsocket = NULL;
unsigned long clientflag = 0;

MYSQL* connectdb(){
    MYSQL * conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, hostname, user, pass, dbname, port, unixsocket, clientflag);
    if (conn) {
        cout<< "berhasil"<<endl;
        return conn;
    } else {
        cout<< "gagal"<<endl;
        return conn;
    }
}

class crud {
    public :
    void createDatabase(MYSQL* conn){
    string db;
    stringstream createdb, dropdb, createulangdb;
    cout<<"input nama databasenya: \n";
    cin >> db;
    createdb << "CREATE DATABASE "+db+" ";
    string query = createdb.str();
    const char* q = query.c_str();
    int qstate = mysql_query(conn, q);
    if(qstate==0){
        cout<<"berhasil create db\n";
    }else if (qstate ==0)
    {
        dropdb << "DROP DATABASE IF EXISTS "+db+" ";
        string query = dropdb.str();
        const char* q = query.c_str();
        int qstate = mysql_query(conn, q);
        cout<<"berhasil drop\n";
    }else{
        createulangdb << "CREATE DATABASE "+db+" ";
        string query = createulangdb.str();
        const char* q = query.c_str();
        int qstate = mysql_query(conn, q);
        cout<<"create ulang database\n";
    }
    
}

void insertDatamahasiswa(MYSQL* conn){
    int qstate =0;
    stringstream inserttodb;
    string nim, nama, id;
    cout << "insert NIM : "<<endl;
    cin>>nim;
    cout << "insert Nama : "<<endl;
    cin>>nama;
    inserttodb << "INSERT INTO mahasiswa (id, nim, nama) VALUES ('"+id+"','"+nim+"','"+nama+"')";
    string query = inserttodb.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    if (qstate == 0){
        cout <<"berhasil insert"<<endl;
    } else {
        cout <<"gagal"<<endl;
    }
}

void insertDatadosen(MYSQL* conn){
    int qstate =0;
    stringstream inserttodb;
    string kd_dosen, nama, id;
    cout << "insert Kode dosen : "<<endl;
    cin>>kd_dosen;
    cout << "insert Nama : "<<endl;
    cin>>nama;
    inserttodb << "INSERT INTO dosen (id, kd_dosen, nama) VALUES ('"+id+"','"+kd_dosen+"','"+nama+"')";
    string query = inserttodb.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    if (qstate == 0){
        cout <<"berhasil insert"<<endl;
    } else {
        cout <<"gagal"<<endl;
    }
}

void displayDatajoin(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;

    if (conn){
        int qstate = mysql_query(conn, "SELECT * FROM mahasiswa join dosen on mahasiswa.id = dosen.id");
        if(!qstate){
            res = mysql_store_result(conn);
            int count = mysql_num_fields(res);
            cout << "==============LIST DATA==============\n";
            cout <<"\tID\tNim\tNama\tcreated_at\t\tupdate_at\t\tID\tKDdosen\tNama_dosen\tcreated_at\tupdate_at\n";
            while(row = mysql_fetch_row(res)){
                for(int i=0; i<count;i++){
                    cout <<"\t"<<row[i];
                }
                cout<<endl;
            }

        }
    } else {
        cout << "Data Kosong" <<endl;
    }
}

void displayDatamahasiswa(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;

    if (conn){
        int qstate = mysql_query(conn, "SELECT * FROM mahasiswa");
        if(!qstate){
            res = mysql_store_result(conn);
            int count = mysql_num_fields(res);
            cout << "==============LIST DATA==============\n";
            cout <<"\tID\tNim\tNama_Mkul\tcreated_at\tupdate_at\n";
            while(row = mysql_fetch_row(res)){
                for(int i=0; i<count;i++){
                    cout <<"\t"<<row[i];
                }
                cout<<endl;
            }

        }
    } else {
        cout << "Data Kosong" <<endl;
    }
}

void displayDatadosen(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;

    if (conn){
        int qstate = mysql_query(conn, "SELECT * FROM dosen");
        if(!qstate){
            res = mysql_store_result(conn);
            int count = mysql_num_fields(res);
            cout << "==============LIST DATA==============\n";
            cout <<"\tID\tKDdosen\tNama_dosen\tcreated_at\tupdtae_at\n";
            while(row = mysql_fetch_row(res)){
                for(int i=0; i<count;i++){
                    cout <<"\t"<<row[i];
                }
                cout<<endl;
            }

        }
    } else {
        cout << "Data Kosong" <<endl;
    }
}

void updateDatamahasiswa(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, updatedb;
    selectdb << "SELECT * FROM mahasiswa WHERE id = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x = mysql_num_rows(res);
    string nim, nama;
    if(x>0){
        cout << "insert NIM : "<<endl;
        cin>>nim;
        cout << "insert Nama : "<<endl;
        cin>>nama;
        updatedb <<"UPDATE mahasiswa SET nim = '"+nim+"', nama= '"+nama+"' WHERE id = '"+id+"' ";
        string query = updatedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}

void updateDatadosen(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, updatedb;
    selectdb << "SELECT * FROM dosen WHERE id = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x = mysql_num_rows(res);
    string kd_dosen, nama;
    if(x>0){
        cout << "insert Kode dosen : "<<endl;
        cin>>kd_dosen;
        cout << "insert Nama dosen : "<<endl;
        cin>>nama;
        updatedb <<"UPDATE dosen SET kd_dosen = '"+kd_dosen+"', nama= '"+nama+"' WHERE id = '"+id+"' ";
        string query = updatedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}

void deleteDatamahasiswa(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, deletedb;
    selectdb << "SELECT * FROM mahasiswa WHERE id = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x = mysql_num_rows(res);

    if(x>0){
        deletedb <<"DELETE FROM mahasiswa WHERE id = '"+id+"' ";
        string query = deletedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}

void deleteDatadosen(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, deletedb;
    selectdb << "SELECT * FROM dosen WHERE id = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x = mysql_num_rows(res);

    if(x>0){
        deletedb <<"DELETE FROM dosen WHERE id = '"+id+"' ";
        string query = deletedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}
};

int main(){
    MYSQL* conn = connectdb();
    crud ab;
    do{
        cout<<"MENU";
        cout<<"\n 0. Exit";
        cout<<"\n 1. Create mahasiswa ";
        cout<<"\n 2. Create  dosen";
        cout<<"\n 3. Read ";
        cout<<"\n 4. Delete Mahasiswa ";
        cout<<"\n 5. Delete dosen ";
        cout<<"\n 6. Update Mahasiswa ";
        cout<<"\n 7. Update dosen ";
        
        cout<<"\nPilih : "; cin>>pilih;

        switch(pilih){
            case 0:
                cout<<"\nThanks"<<endl;
                return 0;
            case 1:
				ab.insertDatamahasiswa(conn);
                ab.displayDatamahasiswa(conn);
                break;
            case 2:
				ab.insertDatadosen(conn);
                ab.displayDatadosen(conn);
                break;
            case 3:
                ab.displayDatajoin(conn);
                break;
            case 4:
                ab.deleteDatamahasiswa(conn);
                ab.displayDatamahasiswa(conn);
                break;
            case 5:
                ab.deleteDatadosen(conn);
                ab.displayDatadosen(conn);
                break;
            case 6:
                ab.updateDatamahasiswa(conn);
                break;
            case 7:
                ab.updateDatadosen(conn);
                break;
            default:
                cout<<"Pilihan Salah"<<endl;
                break;
            }
            cout<<"Ingin memilih menu lain (y/t)? ";
            cin>>kembali;
            cout<<endl;
        }
        while (kembali!= 't');
        cout<<"Thanks"<<endl;
    return 0;

}