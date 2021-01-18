#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int n_pinjam, jml_log, pilihan_fitur, n_anggota, jml_anggota, cek_anggota, n_buku, jml_buku, cek_buku, kembali_hari, kembali_bulan, kembali_tahun;
string ulangi, kembali, nim_balik, kode_balik, nama_karyawan;
time_t my_time = time(NULL);

struct Log { // penggunaan struct
    int id;
    char nama_anggota[50];   // array didalam struct
    char nim_anggota[20];
    char judul_buku[50];
    char kode_buku[20];
    string tanggal_pinjam;
    string tanggal_kembali;
    int hari;
    int bulan;
    int tahun;
    string petugas;
    string status;
}s_log[100];

struct Anggota {
    int id;
    char nama_anggota[50];
    char nim_anggota[20];
}s_anggota[100];

struct Buku {
    int id;
    char judul_buku[50];
    char kode_buku[20];
}s_buku[100];


				
                int main(){
                char pass[4], status; //Tipe data char user ditentukan oleh nama_karyawan password 4 karakter, status tidak dibatasi
                int balik; //Tipe data integer
                int c;
               
                cout<<"\t====================================================== \n";
                cout<<" \tSelamatDatang Di Aplikasi Peminjaman Buku Perpustakaan \n";
                cout<<"\t====================================================== \n";
                cout<<endl;
                atas:
                cout<<" Silakan Login terlebih dahulu \n";
                cout<<" Username : "; cin>>nama_karyawan;
                cout<<" Password : "; cin>>pass;
                if(strcmp(pass,"****")==0) {  //Fungsi percabangan default pass 1234
                                cout<<" User Berhasil Login\n";
                                cout<<"\t====================================================== \n";
                                cout<<endl;
                                system("cls"); //clearscreen
                               
                }else{
                                cout<< "Password Salah\n";
                                cout<<endl;
                                goto atas;

                }

    system("cls");

    menu:
    cout<<"Selamat datang "<<nama_karyawan<<endl<<endl;
    cout<<"Fitur aplikasi"<<endl<<endl;
    cout<<"1. Tambah anggota"<<endl;
    cout<<"2. Tambah buku"<<endl;
    cout<<"3. Daftar anggota"<<endl;
    cout<<"4. Daftar buku"<<endl;
    cout<<"5. Peminjaman buku"<<endl;
    cout<<"6. pengembalian buku"<<endl;
    cout<<"7. Log peminjaman buku"<<endl;
    cout<<"8. Log pengembalian buku"<<endl;
    cout<<"9. Keluar"<<endl<<endl;
    cout<<"pilihan anda    : ";
    cin>>pilihan_fitur;
    
    system("cls");
    
    switch(pilihan_fitur){    //penggunaan switch case

        case 1:

            tambah_anggota:
            jml_anggota += 0;
            s_anggota[jml_anggota].id = jml_anggota; //mengambil data dari struct anggota dan array dari jumlah anggota
            cout<<"Tambah Anggota"<<endl<<endl;
            cout<<"Nama anggota    : ";
            cin>>s_anggota[jml_anggota].nama_anggota; //input nama anggota yang akan disimpan didalam log
            //cin.getline(s_anggota[jml_anggota].nama_anggota, 99)

            cout<<"Nim anggota    : ";
            cin>>s_anggota[jml_anggota].nim_anggota; //input nim anggota yang akan disimpan didalam log
            //cin.getline(s_anggota[jml_anggota].nim_anggota, 99);

            jml_anggota++;
            
            cout << "\nData Anda Sukses Ditambahkan" << endl<< endl;
            cout<<"Kembali Y/n ";
                cin>>kembali;
                
            if(kembali == "Y" || kembali == "y"){
                system("cls");
                goto menu;
            }else{
                system("cls");
                goto tambah_anggota;
            }
            
            break;

        case 2:

            tambah_buku:
            jml_buku += 0;
            s_buku[jml_buku].id = jml_buku; //data buku dalam satuan untuk proses penambahan buku
            cout<<"Tambah Buku"<<endl<<endl;
            cout<<"Judul buku    : ";
                cin>>s_buku[jml_buku].judul_buku; //judul buku disimpan dalam log
            cout<<"Kode buku     : ";
                cin>>s_buku[jml_buku].kode_buku; //kode buku disimpan dalam log
            jml_buku++;
            
            cout << "\nData Anda Sukses Ditambahkan" << endl<< endl;
            cout<<"Kembali Y/n";
                cin>>kembali;
                
            if(kembali == "Y" || kembali == "y"){
                system("cls");
                goto menu;
            }else{
                system("cls");
                goto tambah_buku;
            }
            
            break;

        case 3:

            cout << "Mengecek Data Anggota" << endl;
            log_anggota:
            for(n_anggota = 0; n_anggota < jml_anggota; n_anggota++){ //perulangan untuk jumlah anggota hasil dari log tambah anggota
                cout<<"Nama anggota    : "<<s_anggota[n_anggota].nama_anggota<<endl; //mengambil data dari log tambah anggota
                cout<<"NIM anggota     : "<<s_anggota[n_anggota].nim_anggota<<endl<<endl; //mengambil data dari log tambah anggota
            }
            //log anggota adalah data yang diambil dari daftar anggota yang tersimpan disini
            
            cout<<"Kembali Y/n";
                cin>>kembali;
                
            if(kembali == "Y" || kembali == "y"){
                system("cls");
                goto menu;
            }else{
                system("cls");
                goto log_anggota;
            }
            
            break;

        case 4:

            cout << "Mengecek Data Buku" << endl;
            log_buku:
            for(n_buku = 0; n_buku < jml_buku; n_buku++){
                cout<<"Judul buku    : "<<s_buku[n_buku].judul_buku<<endl; //
                cout <<"Kode buku     : "<<s_buku[n_buku].kode_buku<<endl<<endl; //struct buku dari int buku, mengambil data kode dari buku
            }
            
            cout<<"Kembali Y/n";
                cin>>kembali;
                
            if(kembali == "Y" || kembali == "y"){
                system("cls");
                goto menu;
            }else{
                system("cls");
                goto log_buku;
            }
            
            break;
        
        case 5:

            cout << "Daftar Buku Yang Tersedia" << endl;
            for(n_buku = 0; n_buku < jml_buku; n_buku++){
                cout<<"Judul buku    : "<<s_buku[n_buku].judul_buku<<endl;
                cout <<"Kode buku     : "<<s_buku[n_buku].kode_buku<<endl<<endl;
            }
            cout << endl ;

            pinjam_buku:
            n_pinjam += 1;
                s_log[n_pinjam].id = n_pinjam; //untuk menyimpan data peminjaman di log peminjaman
            cout<<"Peminjaman buku"<<endl<<endl;
            cout<<"Nama peminjam   : ";
                cin>>s_log[n_pinjam].nama_anggota; //untuk menyimpan data nama peminjam
            cout<<"Nim peminjam    : ";
                cin>>s_log[n_pinjam].nim_anggota; //untuk menyimpan data nim peminjam
                
                for(n_anggota = 0; n_anggota <= jml_anggota; n_anggota++){ //perulangan anggota ke-0, jumlah daftar anggota yang tersimpan, increment anggota sampai nilai max n_anggota
                    if(strcmp(s_log[n_pinjam].nim_anggota, s_anggota[n_anggota].nim_anggota ) == 0){
                        cek_anggota = 1; //dilakukan pengecekan nilai anggota yang dimasukan sesuai daftar anggota jika nilai sesuai maka akan dilanjutkan ke pengisian judul buku, jika nilai salah maka akan muncul tampilan anggota tidak terdaftar
                    }
                }
                
                if(cek_anggota != 1){
                    cout<<"Nama anggota tidak terdaftar"<<endl<<endl;
                    goto menu;
                }
                
            cout<<"Judul buku    : "; //input judul buku
                cin>>s_log[n_pinjam].judul_buku; //mengambil data dari log daftar buku
            cout<<"Kode buku     : "; //input kode buku
                cin>>s_log[n_pinjam].kode_buku; //mengambil data dari log daftar buku
                
                for(n_buku = 0; n_buku <= jml_buku; n_buku++){ //data buku yang ada didalam log akan terbaca
                    if(strcmp(s_log[n_pinjam].kode_buku, s_buku[n_buku].kode_buku) == 0){
                        cek_buku = 1; //data peminjaman akan masuk ke log peminjaman, yaitu kode buku, jika pengecekan bernilai benar maka akan diteruskan tapi jika kode buku yang dimasukan nilainya salah maka akan muncul output buku tidak terdaftar
                    }
                }
                
                if(cek_buku != 1){
                    cout<<"buku tidak terdaftar"<<endl<<endl;
                    goto menu;
                }
                
            //input tanggal peminjaman
                cout<<"\nTanggal Pinjam: \n"; //input tanggal peminjaman
                while(1){ //operation while
                    cout<<"Tanggal [1 - 30] : "; cin>>s_log[n_pinjam].hari; //input tgl
                    if(s_log[n_pinjam].hari<=0||s_log[n_pinjam].hari>30){
                          cout<<" ERROR...!\n"; //jikai nilai kurang dari 0 dan lebih dari 31 maka error
                    }else{break;}
                  }
                  while(1){
                    cout<<"Bulan [1 - 12]   : "; cin>>s_log[n_pinjam].bulan; // input bulan
                    if(s_log[n_pinjam].bulan<=0||s_log[n_pinjam].bulan>12){
                          cout<<" ERROR...!\n"; // jikai nilai kurang dari 0 dan lebih dari 12 maka error
                    }else{break;}
                  }
                  while(1){
                    cout<<"Tahun [yyyy]     : "; cin>>s_log[n_pinjam].tahun; //input tahun
                    if(s_log[n_pinjam].tahun<=0){
                      cout<<" ERROR...!\n"; // jika nilai kurang dari 0 maka error
                    }else{break;}
                  }
                  
                  s_log[n_pinjam].petugas = nama_karyawan; // nama petugas disimpan pada log peminjaman
                s_log[n_pinjam].tanggal_pinjam = ctime(&my_time); //tgl pinjam disimpan pada log peminjaman
                s_log[n_pinjam].status = "dipinjam"; //status untuk log peminjaman buku
                
            cek_buku = 0; //cek buku
            cek_anggota = 0; //cek anggota
            n_pinjam++; //nilai pinjam sesuai data buku yang dipinjam melakukan perulangan
            
            cout << "Telah Disetujui Meminjam Buku"<<endl<<endl;
            cout<<"Pinjam lagi Y/n "; //jika Y maka go to pinjam buku, jika n goto menu
                cin>>ulangi;
                
            if(ulangi == "Y" || ulangi == "y"){
                system("cls");
                goto pinjam_buku;
            } else {
                system("cls");
                goto menu;
            }
            
            break;
        
        case 6:
            
            pengembalian_buku:
            cout<<"Pengembalian buku"<<endl<<endl;
            cout<<"NIM peminjam    : ";
                cin>>nim_balik; //input nim peminjam, dengan kode nim balik
            cout<<"Kode buku       : ";
                cin>>kode_balik; //input kode buku yang dipinjam dengan variabel kode_balik
                
            //input tanggal pengembalian
                  cout<<"\n\n Tanggal Kembali: \n";
                  while(1){ //kondisi pertama hari
                    cout<<" Tanggal [1 - 30]    : "; cin>>kembali_hari;
                    if(kembali_hari<=0||kembali_hari>30){ //jika hari kurang dari 0 dan lebih dari 30 maka error
                          cout<<" ERROR...!\n";
                    }else{break;}
                  }
                  while(1){ //kondisi pertama untuk bulan
                    cout<<" Bulan [1 - 12]      : "; cin>>kembali_bulan; //jika bulan kurang dari 1 dan lebih dari 12 maka error
                    if(kembali_bulan<=0||kembali_bulan>12){
                          cout<<" ERROR...!\n";
                    }else{break;}
                  }
                  while(1){ //kondisi pertama untuk tahun
                    cout<<" Tahun [yyyy]        : "; cin>>kembali_tahun; //jika tahun kurang dari 0 maka error
                    if(kembali_tahun<=0){
                          cout<<" ERROR...!\n";
                    }else{break;}
                  }
            
            for(jml_log = 0; jml_log < n_pinjam; jml_log++){ //untuk log peminjaman
                if(nim_balik == s_log[jml_log].nim_anggota && kode_balik == s_log[jml_log].kode_buku && s_log[jml_log].status == "dipinjam"){ //nim peminjam yang mengembalikan buku adalah data didalam log peminjaman terdapat nim dan kode balik untuk data kode buku
                    
                    //proses perhitungan denda
                      int lamaPinjam = (kembali_hari-s_log[s_log[jml_log].id].hari)+((kembali_bulan-s_log[s_log[jml_log].id].bulan)*30)+((kembali_tahun-s_log[s_log[jml_log].id].tahun)*360);
                    //lama peminjaman akan dilakukan fungsi penghitungan hari pengembalian - hari peminjaman, kembali bulan dikurangi bulan peminjaman dan tahun pengembalian dikurangi data tahun peminjaman dikali 360
                      int terlambat = lamaPinjam - 7; //variabel keterlambatan pengembalian, max 7 hari
                      int denda=0;
                      if(lamaPinjam>7){ //jika lama peminjaman lebih dari 7 hari, maka denda per hari 100
                        denda = terlambat *100;
                      }
                      
                      cout<<"Total Denda    : Rp."<<denda<<endl; //output denda
                    
                    s_log[s_log[jml_log].id].tanggal_kembali = ctime(&my_time); //data log pengembalian
                    s_log[s_log[jml_log].id].status = "dikembalikan"; //status buku dikembalikan
                    
                }
            }
                
            cout<<"Pinjam buku Y/n";
                cin>>ulangi;
                
            if(ulangi == "Y" || ulangi == "y"){
                system("cls");
                goto pengembalian_buku;
            } else {
                system("cls");
                goto menu;
            }
            
            break;

        case 7:

        log_peminjaman: //log peminjaman atau data peminjaman sebelum dikembalikan
            for(jml_log = 0; jml_log < n_pinjam; jml_log++){ //jumlah data = 0, jumlah data nilainya lebih kecil dari n pinjam, jumlah log peminjaman akan melakukan increment
                if(s_log[jml_log].status == "dipinjam"){ //jika status buku dipinjam
                    cout<<"Nama peminjam    : "<<s_log[jml_log].nama_anggota<<endl; //output nama peminjam
                    cout<<"NIM peminjam     : "<<s_log[jml_log].nim_anggota<<endl; //output nim peminjam
                    cout<<"Judul            : "<<s_log[jml_log].judul_buku<<endl; //output judul
                    cout<<"Kode             : "<<s_log[jml_log].kode_buku<<endl; //output kode
                    cout<<"Petugas          : "<<s_log[jml_log].petugas<<endl; //output petugas
                    cout<<"Tgl pinjam       : "<<s_log[jml_log].tanggal_pinjam<<endl<<endl; //output tgl pinjam
                }
            }
            
            cout<<"Kembali Y/n"; // Y untuk kembali ke menu, jika n akan goto log_peminjaman
                cin>>kembali;
                
            if(kembali == "Y" || kembali == "y"){
                system("cls");
                goto menu;
            }else{
                system("cls");
                goto log_peminjaman;
            }
            
            break;    
        
        case 8:
            
            log_pengembalian:
            for(jml_log = 0; jml_log < n_pinjam; jml_log++){ //data pengembalian buku
                if(s_log[jml_log].status == "dikembalikan"){
                    cout<<"Nama peminjam    : "<<s_log[jml_log].nama_anggota<<endl;
                    cout<<"NIM peminjam     : "<<s_log[jml_log].nim_anggota<<endl;
                    cout<<"Judul            : "<<s_log[jml_log].judul_buku<<endl;
                    cout<<"Kode             : "<<s_log[jml_log].kode_buku<<endl;
                    cout<<"Petugas          : "<<s_log[jml_log].petugas<<endl;
                    cout<<"Tgl kembali      : "<<s_log[jml_log].tanggal_kembali<<endl<<endl;
                    //mengambil dari data anggota,buku, dan petugas yang terdaftar
                }
            }
            
            cout<<"Kembali Y/n";
                cin>>kembali;
                
            if(kembali == "Y" || kembali == "y"){
                system("cls");
                goto menu;
            }else{
                system("cls");
                goto log_pengembalian;
            }
            
            break;

        case 9:

            goto end;

            break;

        default:
            cout<<"Kembali ke "<<endl;
            goto menu;
            break;
    };
    
    end:
    return 0;
}
