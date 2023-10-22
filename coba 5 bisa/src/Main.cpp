#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// variable Teacher >> Biodata
const int maxrowTeacherBiodata = 10; 
string EmpIDTeacherBiodata[maxrowTeacherBiodata] = {};
string EmpNIMTeacherBiodata[maxrowTeacherBiodata] = {};
string EmpNamaTeacherBiodata[maxrowTeacherBiodata] = {};
string EmpJurusanTeacherBiodata[maxrowTeacherBiodata] = {};

// variable Teacher >> Akademik >> Jadwal Kuliah
const int maxrowTeacherAkademikJadwal = 10; 
string EmpIDTeacherAkademikJadwal[maxrowTeacherAkademikJadwal] = {};
string EmpMatkulTeacherAkademikJadwal[maxrowTeacherAkademikJadwal] = {};
string EmpPengajarTeacherAkademikJadwal[maxrowTeacherAkademikJadwal] = {};
string EmpHariTeacherAkademikJadwal[maxrowTeacherAkademikJadwal] = {};
string EmpJamTeacherAkademikJadwal[maxrowTeacherAkademikJadwal] = {};

// variable Teacher >> Akademik >> TUgas Kuliah
const int maxrowTeacherAkademikTugas = 10; 
string EmpIDTeacherAkademikTugas[maxrowTeacherAkademikTugas] = {};
string EmpTugasTeacherAkademikTugas[maxrowTeacherAkademikTugas] = {};
string EmpBatasTeacherAkademikTugas[maxrowTeacherAkademikTugas] = {};

//////////////////////////////////////////////////////////////////////

// variable Student >> Perizinan
const int maxrowStudentPerizinan = 10; 
string EmpIDStudentPerizinan[maxrowStudentPerizinan] = {};
string EmpNIMStudentPerizinan[maxrowStudentPerizinan] = {};
string EmpNamaStudentPerizinan[maxrowStudentPerizinan] = {};
string EmpJurusanStudentPerizinan[maxrowStudentPerizinan] = {};
string EmpAlasanStudentPerizinan[maxrowStudentPerizinan] = {};

////////////////////// TEACHER /////////////////////////

// (1) 2.1 funtion Teacher >> Biodata
void OpenFileTeacherBiodata(){
    string line;
    ifstream myFile("dataTeacherBiodata.txt");
    if (myFile.is_open()){
        int x = 0;
        while (getline(myFile, line)){
            int l = line.length();
            EmpIDTeacherBiodata[x] = line.substr(0, 3);
            EmpNIMTeacherBiodata[x] = line.substr(4, l - 4);
            EmpNamaTeacherBiodata[x] = line.substr(5, l - 5);
            EmpJurusanTeacherBiodata[x] = line.substr(6, l - 6);
            x++;
        }
    } else {
        cout << "Enable to open the file" << endl;
    }
}
void AddTeacherBiodata(){
    char IDTeacherBiodata[10];
    char NIMTeacherBiodata[20];  // [5] maksudnya no ID tidak boleh lebih dari 5 indeks
    char namaTeacherBiodata[50];
    char jurusanTeacherBiodata[50];

    cin.ignore();   // supaya bisa enter ke bawah

    cout << "Masukan ID : ";
    cin.getline(IDTeacherBiodata, 10);
    cout << "Masukan NIM : ";
    cin.getline(NIMTeacherBiodata, 20);
    cout << "Masukan Nama : ";
    cin.getline(namaTeacherBiodata, 50);
    cout << "Masukan Jurusan : ";
    cin.getline(jurusanTeacherBiodata, 50);

    for (int x = 0; x < maxrowTeacherBiodata; x++) 
    {
        if (EmpIDTeacherBiodata[x] == "\0")
        {
            EmpIDTeacherBiodata[x] = IDTeacherBiodata;
            EmpNIMTeacherBiodata[x] = NIMTeacherBiodata;
            EmpNamaTeacherBiodata[x] = namaTeacherBiodata;
            EmpJurusanTeacherBiodata[x] = jurusanTeacherBiodata;

            break;
        }
    }
}
void UpdateTeacherBiodata(string search){
    char IDTeacherBiodata[10];
    char NIMTeacherBiodata[20];  // [5] maksudnya no ID tidak boleh lebih dari 5 indeks
    char namaTeacherBiodata[50];
    char jurusanTeacherBiodata[50];

    int counter = 0;

    for (int x = 0; x < maxrowTeacherBiodata; x++){
        if (EmpIDTeacherBiodata[x] == search){
            counter++;

            cout << "Masukan NIM baru : ";
            cin.getline(NIMTeacherBiodata, 20);
            cout << "Masukan Nama baru : ";
            cin.getline(namaTeacherBiodata, 50);
            cout << "Masukan Jurusan baru : ";
            cin.getline(jurusanTeacherBiodata, 50);

            EmpNIMTeacherBiodata[x] = NIMTeacherBiodata;
            EmpNamaTeacherBiodata[x] = namaTeacherBiodata;
            EmpJurusanTeacherBiodata[x] = jurusanTeacherBiodata;

            cout << "Update Seccessfully" << endl;
            break;
        }
    }

    if (counter == 0){
        cout << "ID Doesnt Exist!" << endl;
    }
}
void DeleteTeacherBiodata(string search){
    int counter = 0;
    for (int x = 0; x < maxrowTeacherBiodata; x++){
        if(EmpIDTeacherBiodata[x] == search){
            counter++;

            EmpIDTeacherBiodata[x] = "";
            EmpNIMTeacherBiodata[x] = "";
            EmpNamaTeacherBiodata[x] = "";
            EmpJurusanTeacherBiodata[x] = "";

            cout << "Seccessfully Deleted!" << endl;
            break;
        }
    }

    if (counter == 0){
        cout << "ID number does not exist !"; 
    }
}
void SearchTeacherBiodata(string search){
    system("clear");
    cout << "Current Records(s)" << endl;
    cout << "=============================" << endl;

    int counter = 0;
    for (int x = 0; x < maxrowTeacherBiodata; x++){
     
        if (EmpIDTeacherBiodata[x] == search){
            counter++;
            cout << "  " << counter << "  " << EmpIDTeacherBiodata[x] << "         " << EmpNIMTeacherBiodata[x] << "     " << EmpNamaTeacherBiodata[x] << "            " << EmpJurusanTeacherBiodata[x] <<endl;
            break;
        }
    }
    if (counter == 0){
        cout << "No Record Found" << endl;
    }
    cout << "=============================" << endl;
}
void ListTeacherBiodata(){

    system("clear");
    cout << "=========================" << endl;
    
    int counter = 0;
    cout << "No. |  ID  |       NIM      |          Nama          |        Jurusan      |" << endl << "-------------------------------------\n" << endl;
    for (int x = 0; x < maxrowTeacherBiodata; x++)
    {
        if (EmpIDTeacherBiodata[x] != "\0")
        {
            counter++;
            cout << "   " << counter << "    " << EmpIDTeacherBiodata[x] << "         " << EmpNIMTeacherBiodata[x] << "      " << EmpNamaTeacherBiodata[x] << "           " << EmpJurusanTeacherBiodata[x] <<endl;
        }
    }

    if (counter == 0)
    {
        cout << "Tidak Ada Data" << endl;
    }

    cout << "===================================" << endl;
}
void SaveTeacherBiodata(){
    ofstream myFile;
    myFile.open("dataTeacherBiodata.txt");

    for (int x = 0; x < maxrowTeacherBiodata; x++){
        if (EmpIDTeacherBiodata[x] == "\0"){
            break;
        } else {
            myFile << EmpIDTeacherBiodata[x] + "," + EmpNIMTeacherBiodata[x] + "," + EmpNamaTeacherBiodata[x] + "," + EmpJurusanTeacherBiodata[x] << endl;
        }
    }    
}
void MenuTeacherBiodata(){
    std::cout << "MENU\n";
    int optionTeacherBiodata;
    string NIMBiodata;
    system("clear");

    do {
        cout << "||<<*****************>>||" << endl;
        cout << "||<<==== BIODATA ====>>||" << endl;
        cout << "||<<*****************>>||" << endl;
        cout << "1. Buat Biodata Mahasiswa" << endl;
        cout << "2. Ganti Biodata Mahasiswa" << endl;
        cout << "3. Hapus Biodata Mahasiswa" << endl;
        cout << "4. Cari Biodata Mahasiswa" << endl;
        cout << "5. Tampilkan Seluruh Biodata Mahasiswa" << endl;
        cout << "6. dan keluar Simpan ke File" << endl;
        cout << "=============================" << endl;
        cout << "Pilih Menu 1-6 : ";
        cin >> optionTeacherBiodata;

        switch (optionTeacherBiodata){
            case 1:
                AddTeacherBiodata();
                system("clear");
                break;

            case 2:
                cin.ignore();
                cout << "Cari Dengan ID -> ";
                getline(cin, NIMBiodata);
                UpdateTeacherBiodata(NIMBiodata);
                system("clear");
                break;

            case 3:
                cin.ignore();
                cout << "Hapus Dengan ID -> ";
                getline(cin, NIMBiodata); 
                DeleteTeacherBiodata(NIMBiodata);
                cin.ignore();
                system("clear");
                break;

            case 4:
                cin.ignore();
                cout << "Cari Dengan ID -> ";
                getline(cin, NIMBiodata);
                SearchTeacherBiodata(NIMBiodata); 
                break;

            case 5:
                ListTeacherBiodata();
                break;

        }

    } while (optionTeacherBiodata != 6);
    SaveTeacherBiodata();
    cout << "Sedang menyimpan ke File" << endl;

}

// (1) 3.1 funtion Teacher >> Akademik >> Jadwal
void OpenFileTeacherAkademikJadwal(){
    string line;
    ifstream myFile("dataTeacherAkademikJadwal.txt");
    if (myFile.is_open()){
        int x = 0;
        while (getline(myFile, line)){
            int l = line.length();
            EmpIDTeacherAkademikJadwal[x] = line.substr(0, 3);
            EmpMatkulTeacherAkademikJadwal[x] = line.substr(4, l - 4);
            EmpPengajarTeacherAkademikJadwal[x] = line.substr(5, l - 5);
            EmpHariTeacherAkademikJadwal[x] = line.substr(6, l - 6);
            EmpJamTeacherAkademikJadwal[x] = line.substr(7, l - 7);
            x++;
        }
    } else {
        cout << "Tidak Bisa Menyimpan File" << endl;
    }
}
void AddTeacherAkademikJadwal(){
    char IDTeacherAkademikJadwal[10];
    char matkulTeacherAkademikJadwal[50];
    char pengajarTeacherAkademikJadwal[50];  // [5] maksudnya no ID tidak boleh lebih dari 5 indeks
    char hariTeacherAkademikJadwal[50];
    char jamTeacherAkademikJadwal[10];

    cin.ignore();   // supaya bisa enter ke bawah

    cout << "Masukan ID Matkul : ";
    cin.getline(IDTeacherAkademikJadwal, 10);
    cout << "Masukan Nama Matkul : ";
    cin.getline(matkulTeacherAkademikJadwal, 50);
    cout << "Masukan Nama Pengajar : ";
    cin.getline(pengajarTeacherAkademikJadwal, 50);
    cout << "Masukkan Jadwal Hari Mengajar : ";
    cin.getline(hariTeacherAkademikJadwal, 50);
    cout << "Masukan Jam Pelajaran : ";
    cin.getline(jamTeacherAkademikJadwal, 10);

    for (int x = 0; x < maxrowTeacherAkademikJadwal; x++) 
    {
        if (EmpIDTeacherAkademikJadwal[x] == "\0")
        {
            EmpIDTeacherAkademikJadwal[x] = IDTeacherAkademikJadwal;
            EmpMatkulTeacherAkademikJadwal[x] = matkulTeacherAkademikJadwal;
            EmpPengajarTeacherAkademikJadwal[x] = pengajarTeacherAkademikJadwal;
            EmpHariTeacherAkademikJadwal[x] = hariTeacherAkademikJadwal;
            EmpJamTeacherAkademikJadwal[x] = jamTeacherAkademikJadwal;

            break;
        }
    }
}
void UpdateTeacherAkademikJadwal(string search){
    char IDTeacherAkademikJadwal[10];
    char matkulTeacherAkademikJadwal[50];
    char pengajarTeacherAkademikJadwal[50];  // [5] maksudnya no ID tidak boleh lebih dari 5 indeks
    char hariTeacherAkademikJadwal[50];
    char jamTeacherAkademikJadwal[10];


    int counter = 0;

    for (int x = 0; x < maxrowTeacherAkademikJadwal; x++){
        if (EmpIDTeacherAkademikJadwal[x] == search){
            counter++;

            cout << "Masukan Matkul baru : ";
            cin.getline(matkulTeacherAkademikJadwal, 50);
            cout << "Masukan Pengajar baru :";
            cin.getline(pengajarTeacherAkademikJadwal, 50);
            cout << "Masukan Hari Mengajar Baru : ";
            cin.getline(hariTeacherAkademikJadwal, 50);
            cout << "Masukan jam Pelajaran baru : ";
            cin.getline(jamTeacherAkademikJadwal, 10);

            EmpMatkulTeacherAkademikJadwal[x] = matkulTeacherAkademikJadwal;
            EmpPengajarTeacherAkademikJadwal[x] = pengajarTeacherAkademikJadwal;
            EmpHariTeacherAkademikJadwal[x] = hariTeacherAkademikJadwal;
            EmpJamTeacherAkademikJadwal[x] = jamTeacherAkademikJadwal;

            cout << "Berhasil Mengupdate" << endl;
            break;
        }
    }

    if (counter == 0){
        cout << "ID Tidak di Temukan" << endl;
    }
}
void DeleteTeacherAkademikJadwal(string search){
    int counter = 0;
    for (int x = 0; x < maxrowTeacherAkademikJadwal; x++){
        if(EmpIDTeacherAkademikJadwal[x] == search){
            counter++;

            EmpIDTeacherAkademikJadwal[x] = "";
            EmpMatkulTeacherAkademikJadwal[x] = "";
            EmpPengajarTeacherAkademikJadwal[x] = "";
            EmpHariTeacherAkademikJadwal[x] = "";
            EmpJamTeacherAkademikJadwal[x] = "";

            cout << "Sukses Menghapus" << endl;
            break;
        }
    }

    if (counter == 0){
        cout << "ID Tidak Ada!!!!"; 
    }
}
void SearchTeacherAkademikJadwal(string search){
    system("clear");
    cout << "Current Records(s)" << endl;
    cout << "=============================" << endl;

    int counter = 0;
    for (int x = 0; x < maxrowTeacherAkademikJadwal; x++){
     
        if (EmpIDTeacherAkademikJadwal[x] == search){
            counter++;
            cout << "  " << counter << "  " << EmpIDTeacherAkademikJadwal[x] << "       " << EmpMatkulTeacherAkademikJadwal[x] << "         ";
            cout << EmpPengajarTeacherAkademikJadwal[x] << "         " << EmpHariTeacherAkademikJadwal[x] << "           ";
            cout << EmpJamTeacherAkademikJadwal[x] << endl;
            break;
        }
    }
    if (counter == 0){
        cout << "Data Tidak Di Temukan" << endl;
    }
    cout << "=============================" << endl;
}
void ListTeacherAkademikJadwal(){

    system("clear");
    cout << "Current Records" << endl;
    cout << "=========================" << endl;
    
    int counter = 0;
    cout << "No. |    ID   |            Matkul          |        Pengajar         |      Hari Mengajar   | Jam Pelajaran  |" << endl << "-------------------------------------\n" << endl;
    for (int x = 0; x < maxrowTeacherAkademikJadwal; x++)
    {
        if (EmpIDTeacherAkademikJadwal[x] != "\0")
        {
            counter++;
            cout << "   " << counter << "    " << EmpIDTeacherAkademikJadwal[x] << "         " << EmpMatkulTeacherAkademikJadwal[x] << "         ";
            cout << EmpPengajarTeacherAkademikJadwal[x] << "           " << EmpHariTeacherAkademikJadwal[x] << "            ";
            cout << EmpJamTeacherAkademikJadwal[x] << endl;
        }
    }

    if (counter == 0)
    {
        cout << "Data Tidak Ditemukan" << endl;
    }

    cout << "===================================" << endl;
}
void SaveTeacherAkademikJadwal(){
    ofstream myFile;
    myFile.open("dataTeacherAkademikJadwal.txt");

    for (int x = 0; x < maxrowTeacherAkademikJadwal; x++){
        if (EmpIDTeacherAkademikJadwal[x] == "\0"){
            break;
        } else {
            myFile << EmpIDTeacherAkademikJadwal[x] + "," + EmpMatkulTeacherAkademikJadwal[x] + "," + EmpPengajarTeacherAkademikJadwal[x] + "," + EmpHariTeacherAkademikJadwal[x] + "," + EmpJamTeacherAkademikJadwal[x] << endl;
        }
    }    
}
void MenuTeacherAkademikJadwal(){
    std::cout << "MENU\n";
    int optionMenuTeacherAkademikJadwal;
    string empID;
    system("clear");

    do {
        cout << "||<<==******************==>>||" << endl;
        cout << "||<<== JADWAL PELAJARAN ==>>||" << endl;
        cout << "||<<==******************==>>||" << endl;
        cout << "1. Buat Jadwal Pelajaran" << endl;
        cout << "2. Ganti Jadwal Pelajaran" << endl;
        cout << "3. Hapus Jadwal Pelajaran" << endl;
        cout << "4. Cari Jadwal Pelajaran" << endl;
        cout << "5. Tampilkan Jadwal Pelajaran" << endl;
        cout << "6. Save ke File" << endl;
        cout << "7. Kembali ke Menu Akademik : " << endl;
        cout << "=============================" << endl;
        cout << "Pilih Menu : ";
        cin >> optionMenuTeacherAkademikJadwal;

        switch (optionMenuTeacherAkademikJadwal){
            case 1:
                AddTeacherAkademikJadwal();
                system("clear");
                break;

            case 2:
                cin.ignore();
                cout << "Cari Dengan ID -> ";
                getline(cin, empID);
                UpdateTeacherAkademikJadwal(empID);
                system("clear");
                break;

            case 3:
                cin.ignore();
                cout << "Hapus Dengan ID -> ";
                getline(cin, empID); 
                DeleteTeacherAkademikJadwal(empID);
                cin.ignore();
                system("clear");
                break;

            case 4:
                cin.ignore();
                cout << "Cari Dengan ID -> ";
                getline(cin, empID);
                SearchTeacherAkademikJadwal(empID); 
                break;

            case 5:
                ListTeacherAkademikJadwal();
                break;

            case 6:
                system("clear");
                SaveTeacherAkademikJadwal();
                cout << "Berhasil Menyimpan ke file" << endl;

            case 7:
                break;

        }
    
    } while (optionMenuTeacherAkademikJadwal != 7);
    cout << "Progam Selesai" << endl;
}

// (1) 3.2 function Teacher << Akademik >> Tugas
void OpenFileTeacherAkademikTugas(){
    string line;
    ifstream myFile("dataTeacherAkademikTugas.txt");
    if (myFile.is_open()){
        int x = 0;
        while (getline(myFile, line)){
            int l = line.length();
            EmpIDTeacherAkademikTugas[x] = line.substr(0, 3);
            EmpTugasTeacherAkademikTugas[x] = line.substr(4, l - 4);
            EmpBatasTeacherAkademikTugas[x] = line.substr(5, l - 5);
            x++;
        }
    } else {
        cout << "Tidak Bisa  Membuka File Ini" << endl;
    }
}
void AddTeacherAkademikTugas(){
    char IDTeacherAkademikTugas[10];
    char tugasTeacherAkademikTugas[50];
    char batasTeacherAkademikTugas[50];

    cin.ignore();   // supaya bisa enter ke bawah

    cout << "Masukan ID tugas Mahasiswa : ";
    cin.getline(IDTeacherAkademikTugas, 10);
    cout << "Masukan Nama Tugas Mahasiswa : ";
    cin.getline(tugasTeacherAkademikTugas, 50);
    cout << "Masukan DeadLine Pengumpulan Tugas Mahasiswa : ";
    cin.getline(batasTeacherAkademikTugas, 50);

    for (int x = 0; x < maxrowTeacherAkademikTugas; x++) 
    {
        if (EmpIDTeacherAkademikTugas[x] == "\0")
        {
            EmpIDTeacherAkademikTugas[x] = IDTeacherAkademikTugas;
            EmpTugasTeacherAkademikTugas[x] = tugasTeacherAkademikTugas;
            EmpBatasTeacherAkademikTugas[x] = batasTeacherAkademikTugas;

            break;
        }
    }
}
void UpdateTeacherAkademikTugas(string search){
    char IDTeacherAkademikTugas[10];
    char tugasTeacherAkademikTugas[50];
    char batasTeacherAkademikTugas[50];


    int counter = 0;

    for (int x = 0; x < maxrowTeacherAkademikTugas; x++){
        if (EmpIDTeacherAkademikTugas[x] == search){
            counter++;

            cout << "Masukan Tugas Baru : ";
            cin.getline(tugasTeacherAkademikTugas, 50);
            cout << "Masukan Deadline Pengumpulan Tugas Baru : ";
            cin.getline(batasTeacherAkademikTugas, 50);

            EmpTugasTeacherAkademikTugas[x] = tugasTeacherAkademikTugas;
            EmpTugasTeacherAkademikTugas[x] = batasTeacherAkademikTugas;

            cout << "Berhasil Mengupdate" << endl;
            break;
        }
    }

    if (counter == 0){
        cout << "ID Tidak Ditemukan" << endl;
    }
}
void DeleteTeacherAkademikTugas(string search){
    int counter = 0;
    for (int x = 0; x < maxrowTeacherAkademikTugas; x++){
        if(EmpIDTeacherAkademikTugas[x] == search){
            counter++;

            EmpIDTeacherAkademikTugas[x] = "";
            EmpTugasTeacherAkademikTugas[x] = "";
            EmpBatasTeacherAkademikTugas[x] = "";

            cout << "Sukses Menghapus" << endl;
            break;
        }
    }

    if (counter == 0){
        cout << "ID Tidak Di Temukan!"; 
    }
}
void SearchTeacherAkademikTugas(string search){
    system("clear");
    cout << "Current Records(s)" << endl;
    cout << "=============================" << endl;

    int counter = 0;
    for (int x = 0; x < maxrowTeacherAkademikTugas; x++){
     
        if (EmpIDTeacherAkademikTugas[x] == search){
            counter++;
            cout << "  " << counter << "  " << EmpIDTeacherAkademikTugas[x] << "         " << EmpTugasTeacherAkademikTugas[x];
            cout << "      " << EmpBatasTeacherAkademikTugas[x] << endl; 
            break;
        }
    }
    if (counter == 0){
        cout << "No Data Tidak Ditemukan" << endl;
    }
    cout << "=============================" << endl;
}
void ListTeacherAkademikTugas(){

    system("clear");
    cout << "Current Records" << endl;
    cout << "=========================" << endl;
    
    int counter = 0;
    cout << "No.  |   ID  |    Nama Tugas   |        Batas Pengumpulan      " << endl << "-------------------------------------\n" << endl;
    for (int x = 0; x < maxrowTeacherAkademikTugas; x++)
    {
        if (EmpIDTeacherAkademikTugas[x] != "\0")
        {
            counter++;
            cout << "   " << counter << "    " << EmpIDTeacherAkademikTugas[x] << "         " << EmpTugasTeacherAkademikTugas[x];
            cout << "      " << EmpBatasTeacherAkademikTugas[x] << endl;
        }
    }

    if (counter == 0)
    {
        cout << "No Tidak Di Temukan" << endl;
    }

    cout << "===================================" << endl;
}
void SaveTeacherAkademikTugas(){
    ofstream myFile;
    myFile.open("dataTeacherAkademikTugas.txt");

    for (int x = 0; x < maxrowTeacherAkademikTugas; x++){
        if (EmpIDTeacherAkademikTugas[x] == "\0"){
            break;
        } else {
            myFile << EmpIDTeacherAkademikTugas[x] + "," + EmpTugasTeacherAkademikTugas[x] + "," + EmpBatasTeacherAkademikTugas[x] << endl;
        }
    }    
}
void MenuTeacherAkademikTugas(){
    std::cout << "MENU\n";
    int optionMenuTeacherAkademikTugas;
    string empID;
    system("clear");

    do {
        cout << "||<<===**************===>>||" << endl;
        cout << "||<<=== Tugas Kuliah ===>>||" << endl;
        cout << "||<<===**************===>>||" << endl;
        cout << "1. Buat Tugas Kuliah" << endl;
        cout << "2. Edit Tugas Kuliah" << endl;
        cout << "3. Hapus Tugas Kuliah" << endl;
        cout << "4. Cari Tugas Kuliah" << endl;
        cout << "5. Tampilkan Semua TUgas Kuliah" << endl;
        cout << "6. Save Tugas Kuliah" << endl;
        cout << "7. Kembali ke Menu Akademik" << endl;
        cout << "=============================" << endl;
        cout << "Pilih Menu 1-7 : ";
        cin >> optionMenuTeacherAkademikTugas;

        switch (optionMenuTeacherAkademikTugas){
            case 1:
                AddTeacherAkademikTugas();
                system("clear");
                break;

            case 2:
                cin.ignore();
                cout << "Search by ID -> ";
                getline(cin, empID);
                UpdateTeacherAkademikTugas(empID);
                system("clear");
                break;

            case 3:
                cin.ignore();
                cout << "Deleted by ID -> ";
                getline(cin, empID); 
                DeleteTeacherAkademikTugas(empID);
                cin.ignore();
                system("clear");
                break;

            case 4:
                cin.ignore();
                cout << "Search by ID -> ";
                getline(cin, empID);
                SearchTeacherAkademikTugas(empID); 
                break;

            case 5:
                ListTeacherAkademikTugas();
                break;

            case 6:
                system("clear");
                SaveTeacherAkademikTugas();
                cout << "Berhasil Menyimpan ke File" << endl;
                break;

            case 7:
                break;

        }

    } while (optionMenuTeacherAkademikTugas != 7);
    cout << "Progam Selesai";
    
}

// (1) 2.2 function Teacher >> (menu)Akademik
void MenuTeacherAkademik(){
    std::cout << "MENU\n";
    int optionTeacherAkademik;
    system("clear");

    do {
        cout << "<<====----------====>>" << endl;
        cout << "<<==== AKADEMIK ====>>" << endl;
        cout << "<<====----------====>>" << endl;
        cout << "1. Jadwal Kuliah" << endl;
        cout << "2. Tugas" << endl;
        cout << "3. Kembali ke menu Teacher" << endl;
        cout << "Select Options [1] atau [2] : ";
        cin >> optionTeacherAkademik;

        switch (optionTeacherAkademik){
            case 1:
                MenuTeacherAkademikJadwal();
                system("clear");
                break;
            case 2:
                MenuTeacherAkademikTugas();
                system("clear");
                break;

            case 3:
                break;

            default:
            cout << "Anda Salah!" << endl;
        }
    
    } while (optionTeacherAkademik != 3);
    cout << "Pilihan Anda Salah" << endl;
}

///////////////// STUDENT /////////////////////////

// (2) 2.3 student >> Perizinan
void OpenFileStudentPerizinan(){
    string line;
    ifstream myFile("dataStudentPerizinan.txt");
    if (myFile.is_open()){
        int x = 0;
        while (getline(myFile, line)){
            int l = line.length();
            EmpIDStudentPerizinan[x] = line.substr(0, 3);
            EmpNIMStudentPerizinan[x] = line.substr(4, l - 4);
            EmpNamaStudentPerizinan[x] = line.substr(5, l - 5);
            EmpJurusanStudentPerizinan[x] = line.substr(6, l -6);
            EmpAlasanStudentPerizinan[x] = line.substr(7, l - 7);
            x++;
        }
    } else {
        cout << "Tidak Bisa Membuat File" << endl;
    }
}
void AddStudentPerizinan(){
    char IDStudentPerizinan[10];
    char NIMStudentPerizinan[20];
    char namaStudentPerizinan[50];
    char jurusanStudentPerizinan[50];
    char alasanStudentPerizinan[50];

    cin.ignore();   // supaya bisa enter ke bawah

    cout << "Masukan ID  : ";
    cin.getline(IDStudentPerizinan, 10);
    cout << "Masukan NIM : ";
    cin.getline(NIMStudentPerizinan, 20);
    cout << "Masukan Nama : ";
    cin.getline(namaStudentPerizinan, 50);
    cout << "Masukan Jurusan : ";
    cin.getline(jurusanStudentPerizinan, 50);
    cout << "Masukan Alasan Sakit : ";
    cin.getline(alasanStudentPerizinan, 50);

    for (int x = 0; x < maxrowStudentPerizinan; x++) 
    {
        if (EmpIDStudentPerizinan[x] == "\0")
        {
            EmpIDStudentPerizinan[x] = IDStudentPerizinan;
            EmpNIMStudentPerizinan[x] = NIMStudentPerizinan;
            EmpNamaStudentPerizinan[x] = namaStudentPerizinan;
            EmpJurusanStudentPerizinan[x] = jurusanStudentPerizinan;
            EmpAlasanStudentPerizinan[x] = alasanStudentPerizinan; 

            break;
        }
    }
}
void UpdateStudentPerizinan(string search){
    char IDStudentPerizinan[10];
    char NIMStudentPerizinan[20];
    char namaStudentPerizinan[50];
    char jurusanStudentPerizinan[50];
    char alasanStudentPerizinan[50];

    int counter = 0;

    for (int x = 0; x < maxrowStudentPerizinan; x++){
        if (EmpIDStudentPerizinan[x] == search){
            counter++;

            cout << "Masukan NIM : ";
            cin.getline(NIMStudentPerizinan, 20);
            cout << "Masukan Nama : ";
            cin.getline(namaStudentPerizinan, 50);
            cout << "Masukan Jurusan : ";
            cin.getline(jurusanStudentPerizinan, 50);
            cout << "Masukan Alasan Sakit : ";
            cin.getline(alasanStudentPerizinan, 50);

           EmpNIMStudentPerizinan[x] = NIMStudentPerizinan;
           EmpNamaStudentPerizinan[x] = namaStudentPerizinan;
           EmpJurusanStudentPerizinan[x] = jurusanStudentPerizinan;
           EmpAlasanStudentPerizinan[x] = alasanStudentPerizinan;

            cout << "Sukses Mengganti" << endl;
            break;
        }
    }

    if (counter == 0){
        cout << "File Tidak Di Temukan!!" << endl;
    }
}
void DeleteStudentPerizinan(string search){
    int counter = 0;
    for (int x = 0; x < maxrowStudentPerizinan; x++){
        if(EmpIDStudentPerizinan[x] == search){
            counter++;

            EmpIDStudentPerizinan[x] = "";
            EmpNIMStudentPerizinan[x] = ""; 
            EmpNamaStudentPerizinan[x] = "";
            EmpJurusanStudentPerizinan[x] = "";
            EmpAlasanStudentPerizinan[x] = ""; 

            cout << "Sukses Menghapus" << endl;
            break;
        }
    }

    if (counter == 0){
        cout << "ID Tidak Ditemukan!!"; 
    }
}
void SearchStudentPerizinan(string search){
    system("clear");
    cout << "Current Records(s)" << endl;
    cout << "=============================" << endl;

    int counter = 0;
    for (int x = 0; x < maxrowStudentPerizinan; x++){
     
        if (EmpIDStudentPerizinan[x] == search){
            counter++;
            cout << "  " << counter << "  " << EmpIDStudentPerizinan[x] << "         " << EmpNIMStudentPerizinan[x];
            cout << "      " << EmpNamaStudentPerizinan[x] << "         " << EmpJurusanStudentPerizinan[x] << "         ";
            cout << EmpAlasanStudentPerizinan[x];
            break;
        }
    }
    if (counter == 0){
        cout << "Tidak Ada Data yang Valid" << endl;
    }
    cout << "=============================" << endl;
}
void ListStudentPerizinan(){

    system("clear");
    cout << "Current Records" << endl;
    cout << "=========================" << endl;
    
    int counter = 0;
    cout << "No. |   ID  |     NIM     |          Nama             |           Jurusan         |                                   Alasan                                     |" << endl << "-------------------------------------\n" << endl;
    for (int x = 0; x < maxrowStudentPerizinan; x++)
    {
        if (EmpIDStudentPerizinan[x] != "\0")
        {
            counter++;
            cout << "   " << counter << "    " << EmpIDStudentPerizinan[x] << "         " << EmpNIMStudentPerizinan[x];
            cout << "           " << EmpNamaStudentPerizinan[x] << "        " << EmpJurusanStudentPerizinan[x];
            cout << "           " << EmpAlasanStudentPerizinan[x] << endl;

        }
    }

    if (counter == 0)
    {
        cout << "Tidak Ada Data!!" << endl;
    }

    cout << "===================================" << endl;
}
void SaveStudentPerizinan(){
    ofstream myFile;
    myFile.open("dataStudentPerizinan.txt");

    for (int x = 0; x < maxrowStudentPerizinan; x++){
        if (EmpIDStudentPerizinan[x] == "\0"){
            break;
        } else {
            myFile << EmpIDStudentPerizinan[x] + "," + EmpNIMStudentPerizinan[x] + "," + EmpNamaStudentPerizinan[x] + "," + EmpAlasanStudentPerizinan[x] << endl;
        }
    }    
}
void MenuStudentPerizinan(){
    std::cout << "MENU\n";
    int optionMenuStudentPerizinan;
    string empID;
    system("clear");

    do {
        cout << "||<<====*********************====>>||" << endl;
        cout << "||<<==== Perizinan Mahasiswa ====>>||" << endl;
        cout << "||<<====*********************====>>||" << endl;
        cout << "1. Buat Perizinan" << endl;
        cout << "2. Ganti Data Perizinan" << endl;
        cout << "3. Hapus Data Perizinan" << endl;
        cout << "4. Cari Data Perizinan" << endl;
        cout << "5. Tampilkan Seluruh Data" << endl;
        cout << "6. Simpan File" << endl;
        cout << "7. Kembali ke Menu Student" << endl;
        cout << "=============================" << endl;
        cout << "Pilih Menu Perizinan 1-7 : ";
        cin >> optionMenuStudentPerizinan;

        switch (optionMenuStudentPerizinan){
            case 1:
                AddStudentPerizinan();
                system("clear");
                break;

            case 2:
                cin.ignore();
                cout << "Cari Dengan ID -> ";
                getline(cin, empID);
                UpdateStudentPerizinan(empID);
                system("clear");
                break;

            case 3:
                cin.ignore();
                cout << "Hapus Dengan ID -> ";
                getline(cin, empID); 
                DeleteStudentPerizinan(empID);
                cin.ignore();
                system("clear");
                break;

            case 4:
                cin.ignore();
                cout << "Cari Dengan ID -> ";
                getline(cin, empID);
                SearchStudentPerizinan(empID); 
                break;

            case 5:
                ListStudentPerizinan();
                break;

            case 6:
                system("clear");
                SaveStudentPerizinan();
                cout << "Berhasi Menyimpan File" << endl;
                break;

            case 7:
                break;

        }
    
    } while (optionMenuStudentPerizinan != 7);
    cout << "Progam Selesai" << endl;
}

/////////////////// READ ONLY ///////////////////////////

// (read only) Teacher >> Perizinan 
void TeacherPerizinan(){
    int teacherPerizinan;
    system("clear");
    do {
        cout << "||<<====*****************====>>||" << endl;
        cout << "||<<== Perizinan Mahasiswa ==>>||" << endl;
        cout << "||<<====*****************====>>||" << endl;
        cout << "1. Lihat Perizinan Mahasiswa" << endl;
        cout << "2. Kembali ke Menu Teacher" << endl;
        cout << "Pilih Menu : ";
        cin >> teacherPerizinan;

        switch (teacherPerizinan) {
            case 1:
                ListStudentPerizinan();
                break;
            case 2:
                break;
        }

    } while (teacherPerizinan != 2);

    cout << "Akhir Dari Progam" << endl;
}

// (read only) Student >> Biodata
void StudentBiodata(){
    int pilStudentBiodata;
    system("clear");
    do {
        cout << "||<<====*****************====>>||" << endl;
        cout << "||<<== Biodata Mahasiswa ==>>||" << endl;
        cout << "||<<====*****************====>>||" << endl;
        cout << "1. Lihat Biodata Mahasiswa" << endl;
        cout << "2. Kembali ke Menu Student" << endl;
        cout << "Pilih Menu : ";
        cin >> pilStudentBiodata;

        switch (pilStudentBiodata) {
            case 1:
                ListTeacherBiodata();
                break;
            case 2:
                break;
        }

    } while (pilStudentBiodata != 2);

    cout << "Akhir Dari Progam" << endl;
}

// (read only) Student >> Akademik
void StudentAkademik(){
    int pilStudentAkademik;
    system("clear");
    do {
        cout << "||<<====*****************====>>||" << endl;
        cout << "||<<====*** Akademik ****====>>||" << endl;
        cout << "||<<====*****************====>>||" << endl;
        cout << "1. Lihat Jadwal Kuliah" << endl;
        cout << "2. Lihat Tugas Kuliah" << endl;
        cout << "3. Kembali ke Menu Student" << endl;
        cout << "Pilih Menu : ";
        cin >> pilStudentAkademik;

        switch (pilStudentAkademik) {
            case 1:
                ListTeacherAkademikJadwal();
                break;
            case 2:
                ListTeacherAkademikTugas();
                break;
            case 3:
                break;
        }

    } while (pilStudentAkademik != 3);

    cout << "Akhir Dari Progam" << endl;
}

//////////////////// MENU /////////////////////////

// (1) 1.1 function (menu) Teaacher 
void Teacher(){
    int pilTeacher;

    do {
        std::cout << "MENU\n";
        int option;
        string empID;
        system("clear");

        cout << "||===> **************** <===||" << endl;
        cout << "||===> Enter as teacher <===||" << endl;
        cout << "||===> **************** <===||" << endl;
        cout << "1. biodata: " << endl;
        cout << "2. akademik: " << endl;
        cout << "3. perizinan: " << endl;
        cout << "4. Kembali ke menu Utama" << endl;
        cout << "Pilih Menu 1-4 : ";
        cin >> pilTeacher; 

        switch (pilTeacher){
            case 1:
                MenuTeacherBiodata();
                break;

            case 2:
                MenuTeacherAkademik();
                break;
            
            case 3:
                TeacherPerizinan();
                break;

            case 4:
                break;
            
            default:
            cout << "Anda salah!" << endl; 
        }

    } while (pilTeacher != 4);
    cout << "Anda Salah" << endl;
}
// (2) 1.2 function (menu) Student
void Student(){
    int pilStudent;

    do {
        std::cout << "MENU\n";
        int option;
        string empID;
        system("clear");

        cout << "||===> **************** <===||" << endl;
        cout << "||===> Enter as Student <===||" << endl;
        cout << "||===> **************** <===||" << endl;
        cout << "1. biodata: " << endl;
        cout << "2. akademik: " << endl;
        cout << "3. perizinan: " << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "Pilih Menu 1-4 : ";
        cin >> pilStudent; 

        switch (pilStudent){
            case 1:
                StudentBiodata();
                break;

            case 2:
                StudentAkademik();
                break;
            
            case 3:
                MenuStudentPerizinan();
                break;

            case 4:
                break;
            
            default:
            cout << "Anda salah!" << endl; 
        }
    
    } while (pilStudent != 4);
    cout << "Anda Salah" << endl;
}


// Main method
int main(){
    int pilihan;

    do {
        system("clear");
        cout << "||***************************************||" << endl;
        cout << "||=======================================||" << endl;
        cout << "||============= WELCOME TO ==============||" << endl;
        cout << "||====== Sistem Managemen Sekolah =======||" << endl;
        cout << "||=======================================||" << endl;
        cout << "||_______________________________________||" << endl;
        cout << endl;

        cout << "Masuk sebagai : " << endl;
        cout << "1. teacher" << endl;
        cout << "2. Student" << endl;
        cout << "pilih [1] atau [2] : ";
        cin >> pilihan;

        // CASE utama teacher dan student
        switch (pilihan){
            case 1:
                Teacher();
                break;
            case 2:
                Student();
                break;
            default:
            cout << "anda salah!" << endl;
        }
    
    } while (pilihan != 3);
    cout << "Progam selesai" << endl;


}