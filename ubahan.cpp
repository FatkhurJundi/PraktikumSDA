#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node{
    int info;
    struct node *next;
}*start;
 
class single_llist{
    public:
        node* buat_node(int);
        void tambah_awal();
        void tambah_tengah();
        void tambah_akhir(); 
        void hapus_pos();
        void ganti();
        void tampil();
        single_llist() {
            start = NULL;
        }
};
 

int main(){
    int pilihan, nodes, elemen, posisi, i;
    single_llist sl;
    start = NULL;
    char ulang;
    do{
    	system("cls");
    	cout << " nama kelompok 5\n";
    	cout << " fatkhurrahman Jundi\n";
    	cout << " Muhammad fazri\n\n";
        cout<<"1.Tambah di awal"<<endl;
        cout<<"2.Tambah di akhir"<<endl;
        cout<<"3.Tambah di tengah"<<endl;
        cout<<"4.Hapus node"<<endl;
        cout<<"5.Ganti isi node"<<endl;
        cout<<"6.Tampilkan linked list"<<endl;
        cout<<"7.keluar "<<endl;
        cout<<"Masukkan Pilihan : ";
        cin>>pilihan;
        switch(pilihan){
        	case 1:
            	cout<<"Tambah di awal: "<<endl;
            	sl.tambah_awal();
            	cout<<endl;
            	break;
        	case 2:
            	cout<<"Tambah di akhir: "<<endl;
            	sl.tambah_akhir();
            	cout<<endl;
            	break;
        	case 3:
            	cout<<"Tambah di tengah:"<<endl;
            	sl.tambah_tengah();
            	cout<<endl;
            break;
        	case 4:
            	cout<<"Hapus node: "<<endl;
            	sl.hapus_pos();
            	break;
        	case 5:
            	cout<<"Ganti isi node:"<<endl;  
            	sl.ganti();
            	cout<<endl;
            	break;
        	case 6:
            	cout<<"Tampilkan linked list"<<endl;
            	sl.tampil();
            	cout<<endl;
            	break;
        	case 7:
            	cout<<"Keluar..."<<endl;
            	exit(1);
            	break;
        default:
            cout<<"salah pilihan"<<endl;
        }
        cout << "\nKembali ke menu? (y/n) = ";
        cin >> ulang;
    }
    while(ulang=='y' || ulang=='Y');
}

 
node *single_llist::buat_node(int nilai){
    struct node *temp, *s;
    temp = new(struct node); 
    if (temp == NULL){
        cout<<"salah inputan "<<endl;
        return 0;
    }
    else{
        temp->info = nilai;
        temp->next = NULL;     
        return temp;
    }
}
 

void single_llist::tambah_awal(){
    int nilai;
    cout<<"masukkan nilai yang diinginkan: ";
    cin>>nilai;
    struct node *temp, *p;
    temp = buat_node(nilai);
    if (start == NULL){
        start = temp;
        start->next = NULL;          
    } 
    else{
        p = start;
        start = temp;
        start->next = p;
    }
    cout<<"elemen terisi diawal"<<endl;
}
 
void single_llist::tambah_akhir(){
    int nilai;
    cout<<"masukkan nilai yang diinginkan: ";
    cin>>nilai;
    struct node *temp, *s;
    temp = buat_node(nilai);
    s = start;
    while (s->next != NULL){         
        s = s->next;        
    }
    temp->next = NULL;
    s->next = temp;
    cout<<"Elemen terisi diakhir"<<endl;  
}
 
void single_llist::tambah_tengah(){
    int nilai, pos, counter = 0; 
    cout<<"masukkan nilai yang diinginkan: ";
    cin>>nilai;
    struct node *temp, *s, *ptr;
    temp = buat_node(nilai);
    cout<<"masukkan pada posisi: ";
    cin>>pos;
    int i;
    s = start;
    while (s != NULL){
        s = s->next;
        counter++;
    }
    if (pos == 1){
        if (start == NULL){
            start = temp;
            start->next = NULL;
        }
        else{
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }
    else if (pos > 1  && pos <= counter){
        s = start;
        for (i = 1; i < pos; i++){
            ptr = s;
            s = s->next;
        }
        ptr->next = temp;
        temp->next = s;
    }
    else{
        cout<<"Posisi tidak terjangkau"<<endl;
    }
}
 
void single_llist::hapus_pos(){
    int pos, i, counter = 0;
    if (start == NULL){
        cout<<"list kosong"<<endl;
        return;
    }
    cout<<"masukkan node yang ingin dihapus: ";
    cin>>pos;
    struct node *s, *ptr;
    s = start;
    if (pos == 1){
        start = s->next;
    }
    else{
        while (s != NULL){
            s = s->next;
            counter++;  
        }
        if (pos > 0 && pos <= counter){
            s = start;
            for (i = 1;i < pos;i++){
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }
        else{
            cout<<"Posisi tidak terjangkau"<<endl;
        }
        free(s);
        cout<<"Elemen terhapus"<<endl;
    }
}
 
void single_llist::ganti(){
    int nilai, pos, i;
    if (start == NULL){
        cout<<"List kosong"<<endl;
        return;
    }
    cout<<"masukkan node yang ingin diganti: ";
    cin>>pos;
    cout<<"masukkan nilai baru: ";
    cin>>nilai;
    struct node *s, *ptr;
    s = start;
    if (pos == 1){
        start->info = nilai; 
    }
    else{
        for (i = 0;i < pos - 1;i++){
            if (s == NULL){
                cout<<"data kurang dari "<<pos<<" elemen";
                return;
            }
            s = s->next;
        }
        s->info = nilai;  
    }
    cout<<"Node terganti"<<endl;
} 
 
void single_llist::tampil(){
    struct node *temp;
    if (start == NULL){
        cout<<"List kosong"<<endl;
        return;
    }
    temp = start;
    cout<<"list elemen adalah: "<<endl;
    while (temp != NULL){
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
