#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#define MAKANAN 20000
#define BAGASI 30000

//GLOBAL VARIABEL
int saldo, size = 0, id, *jumlahPenumpang[];
bool loop = true;

//array
 char *namaMaskapai[] = {
    "GARUDA INDONESIA",
    "CITILINK AIRLINES",
    "NUSANTARA AIRLINES",
    "MERPATI NUSANTARA",
    "LION AIRLINES",
    "INDONEISA AIR ASIA",
    "SRIWIJAYA AIRLINES"
};

 char *rutePenerbangan[] = {
    "SURABAYA - JAKARTA",
    "SURABAYA - SAMARINDA",
    "SURABAYA - MAKASSAR",
    "SURABAYA - JAKARTA",
    "SURABAYA - ACEH",
    "SURABAYA - MAKASSAR",
    "SURABAYA - SAMARINDA"
};

 char *hargaMaskapai[] = {
    "Rp.650.000",
    "Rp.700.000",
    "Rp.850.000",
    "Rp.650.000",
    "      Rp.1.000.000",
    "Rp.850.000",
    "Rp.700.000"
};

char *WaktuPesawat[] = {
    "08.00 - 09.30",
    "10.00 - 14.00",
    "18.10 - 22.00",
    "07.00 - 09.30",
    "15.00 - 18.20",
    "16.00 - 17.30",
    "16.00 - 17.30"
};

char *months[]=
{
	" ",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

//STRUCT
struct Data{
    char name[100],
        maskapai[100],
        ruteuser[100],
        waktuBerangkat[100],
        bulanBerangkat[100],
        statusBooking[100],
        orderTime[100];
    int totalBayar[100],
        userId[100],
        hargauser[100],
        hotel[100],
        bagasi[100],
        makanan[100],
        tanggalBerangkat[100],
        ppn[100],
        tempatDuduk[100];
}user[100], tempUser[100];

//fungsi utama
int main(){
        printf("\n\n\n\n");
        printf("\t\t\t|===============================================================|\n");
        printf("\t\t\t|                                                               |\n");
        printf("\t\t\t|                                                               |\n");
        printf("\t\t\t|       SELAMAT DATANG DI PROGRAM RESERVASI TIKET PESAWAT       |\n");
        printf("\t\t\t|                       SURABAYA AIRPORT                        |\n");
        printf("\t\t\t|                                                               |\n");
        printf("\t\t\t|                                                               |\n");
        printf("\t\t\t|===============================================================|\n\t\t\t");
        handlePause();;
        menuUtama();
}


void menuUtama(){
    int menuOption;
    while(loop){
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t==================================================================\n");
        printf("\t\t\t||                          MENU UTAMA                          ||\n");
        printf("\t\t\t||==============================================================||\n");
        printf("\t\t\t||\t[1] Pesan Tiket Pesawat\t\t\t\t\t||\n");
        printf("\t\t\t||\t[2] Riwayat Penerbangan\t\t\t\t\t||\n");
        printf("\t\t\t||\t[3] Cari Data Penerbangan\t\t\t\t||\n");
        printf("\t\t\t||\t[4] Exit\t\t\t\t\t\t||\n");
        printf("\t\t\t||==============================================================||\n");
        printf("\t\t\tMasukkan Pilihan Anda : ");scanf("%d", &menuOption);
        if(menuOption == 1){
            flightList(size++);
        }else if(menuOption == 2){
            bookingHistory(size);
        }else if(menuOption == 3){
            searchCentre(size);
        }else if(menuOption == 4){
            handleExit();
            handlePause();
            loop = false;
        }else{
            handleError();
        }
    }
}

//melooping list maskapai yang tersedia
void maskapaiList(){
    for(int i = 0; i <  sizeof(namaMaskapai) / sizeof(namaMaskapai[0]); i++){
        printf("\t\t\t||   [%d]           %s\t\t", i+1, namaMaskapai[i]);
        printf("%s\t\t", rutePenerbangan[i]);
        printf("   %s                 ", hargaMaskapai[i]);
        printf("%s       ||\n", WaktuPesawat[i]);
    }
}

//menampilkan dan memilih list maskapai
void flightList(int size){
    int flightOption;
    while(loop){
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t____________________________________________________________________________________________________________________________________\n");
        printf("\t\t\t||                                                  DAFTAR MASKAPAI                                                               ||\n");
        printf("\t\t\t||________________________________________________________________________________________________________________________________||\n");
        printf("\t\t\t||________________________________________________________________________________________________________________________________||\n");
        printf("\t\t\t||   No  |             Maskapai               |          Rute              |           Harga          |            Waktu          ||\n");
        printf("\t\t\t||________________________________________________________________________________________________________________________________||\n");
        maskapaiList();
        printf("\t\t\t||________________________________________________________________________________________________________________________________||\n\n");
        printf("\t\t\tPilih Maskapai Pesawat : ");scanf("%d", &flightOption);
        if(flightOption <= 7){
            dataPesanan(size, flightOption);
        }else{
            handleError();
        }
    }
}

//untuk memilih dan menampilkan pilihan dari user
void dataPesanan(int size, int option){
    int dewasa, anak;
    fflush(stdin);printf("\t\t\tMasukkan Nama Anda : ");gets(user[size].name);
    switch(option){
    case 1 :
        strcpy(user[size].maskapai, "GARUDA INDONESIA");
        strcpy(user[size].ruteuser, "SURABAYA - JAKARTA");
        strcpy(user[size].waktuBerangkat, "08.00 - 09.30");
        break;
    case 2 :
        strcpy(user[size].maskapai, "CITILINK AIRLINES");
        strcpy(user[size].ruteuser, "SURABAYA - SAMARINDA");
        strcpy(user[size].waktuBerangkat, "10.00 - 14.00");
         break;
    case 3 :
        strcpy(user[size].maskapai, "NUSANTARA AIRLINES");
        strcpy(user[size].ruteuser, "SURABAYA - MAKASSAR");
        strcpy(user[size].waktuBerangkat, "18.10 - 22.00");
         break;
    case 4 :
        strcpy(user[size].maskapai, "MERPATI NUSANTARA");
        strcpy(user[size].ruteuser, "SURABAYA - JAKARTA");
        strcpy(user[size].waktuBerangkat,"07.00 - 09.30");
         break;
    case 5 :
        strcpy(user[size].maskapai, "LION AIRLINES");
        strcpy(user[size].ruteuser, "SURABAYA - ACEH");
        strcpy(user[size].waktuBerangkat, "15.00 - 18.20");
         break;
    case 6 :
        strcpy(user[size].maskapai, "INDONESIA AIR ASIA");
        strcpy(user[size].ruteuser, "SURABAYA - MAKASSAR");
        strcpy(user[size].waktuBerangkat, "16.00 - 17.30");
         break;
    case 7 :
        strcpy(user[size].maskapai, "SRIWIJAYA AIRLINES");
        strcpy(user[size].ruteuser, "SURABAYA - SAMARINDA");
        strcpy(user[size].waktuBerangkat, "16.00 - 17.30");
         break;
    default :
        handleError();
        break;
    }
    printf("\t\t\tMaskapai Penerbangan : %s\n", user[size].maskapai);
    printf("\t\t\tRute Penerbangan     : %s\n", user[size].ruteuser);
    printf("\t\t\tWaktu Penerbangan    : %s\n",user[size].waktuBerangkat);
    printf("\n");
    printf("\t\t\tMasukkan Jumlah Penumpang\n");
    printf("\t\t\tDewasa               : ");scanf("%d", &dewasa);
    printf("\t\t\tAnak-Anak            : ");scanf("%d", &anak);
    printf("\n");
    jumlahPenumpang[size] = dewasa + anak;
    if(dewasa != 0){
        getTempatDuduk(size, dewasa, anak);
        calender(size,dewasa, anak, option);
    }else{
        printf("\t\t\tPENUMPANG DIBAWAH UMUR TIDAK DIPERBOLEHKAN MEMESAN TIKET");
        handlePause();
        system("cls");
        flightList(size);
    }
}

//untuk memilih jadwal penerbangan
void calender(int size,int dewasa, int anak, int option){
    int bulan;
    while(loop){
            system("cls");
            printf("\n\n\n\n");
            printf("\t\t\t|=================================================================|\n");
            printf("\t\t\t|                                                                 |\n");
            printf("\t\t\t|                      PILIH JADWAL PENERBANGAN                   |\n");
            printf("\t\t\t|                                                                 |\n");
            printf("\t\t\t|=================================================================|\n");
            printf("\t\t\tMasukkan Bulan Keberangkatan [1-12]: ");scanf("%d", &bulan);
            user[size].bulanBerangkat[size] = bulan;
            switch(bulan){
            case 1:
            case 3:
            case 5:
            case 8:
            case 10:
            case 12:
                printf("\n");
                printf("\t\t\t\t\t%s\n", months[bulan]);
                strcpy(user[size].bulanBerangkat, months[bulan]);
                printf("\t\t\t\t\tSun  Mon  Tue  Wed  Thu  Fri  Sat\n\t\t\t\t\t" );
                for(int i = 1; i <= 31; i++){
                    printf("%2d", i);
                    if(i % 7 > 0){
                        printf("   " );
                    }else if(i % 7 == 0){
                        printf("\t\t\t\n\n\t\t\t\t\t");
                    }
                }
                break;
            case 2:
                printf("\n");
                printf("\t\t\t\t\t%s\n", months[bulan]);
                strcpy(user[size].bulanBerangkat, months[bulan]);
                printf("\t\t\t\t\tSun  Mon  Tue  Wed  Thu  Fri  Sat\n\t\t\t\t\t" );
                for(int i = 1; i <= 28; i++){
                    printf("%2d", i);
                    if(i % 7 > 0){
                        printf("   " );
                    }else if(i % 7 == 0){
                        printf("\t\t\t\n\n\t\t\t\t\t");
                    }
                }
                break;
            case 4:
            case 6:
            case 7:
            case 9:
            case 11:
                printf("\n");
                printf("\t\t\t\t\t%s\n", months[bulan]);
                strcpy(user[size].bulanBerangkat, months[bulan]);
                printf("\t\t\t\t\tSun  Mon  Tue  Wed  Thu  Fri  Sat\n\t\t\t\t\t" );
                for(int i = 1; i <= 30; i++){
                    printf("%2d", i);
                    if(i % 7 > 0){
                        printf("   " );
                    }else if(i % 7 == 0){
                        printf("\t\t\t\n\n\t\t\t\t\t");
                    }
                }
                break;
             default :
                handleError();
                return calender(size, dewasa, anak, option);
                break;
            }
        printf("\n\n\t\t\tSilahkan pilih tanggal keberangkatan : ");
        scanf("%d", &user[size].tanggalBerangkat[size]);
        if(user[size].tanggalBerangkat[size] <= 31){
            flightFare(size, dewasa, anak, option);
            handlePause();
            menuTambahan(size);
        }else{
            handleError();
        }
    }
}

//opsi tambahan
void menuTambahan(int size){
    int addOption, jmlh;
    while(loop){
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t==================================================================\n");
        printf("\t\t\t||           MENU TAMBAHAN        |           HARGA             ||\n");
        printf("\t\t\t||==============================================================||\n");
        printf("\t\t\t||       [1] Makanan              |         Rp.20.000           ||\n");
        printf("\t\t\t||       [2] Bagasi               |         Rp.30.000           ||\n");
        printf("\t\t\t||       [3] Selesai              |                             ||\n");
        printf("\t\t\t==================================================================\n");
        printf("\t\t\tMasukkan Pilihan : ");scanf("%d", &addOption);
        if(addOption == 1){
            printf("\t\t\tMasukkan Jumlah Pesanan Makanan : ");scanf("%d", &jmlh );
            priceFood(size, jmlh);
            handlePause();
        }else if(addOption == 2){
            printf("\t\t\tMasukkan Kapasitas Bagasi Tambahan (Kg): ");scanf("%d", &jmlh);
            bagasi(size, jmlh);
            handlePause();
        }else if(addOption == 3){
            printf("\t\t\tPESANAN ANDA TELAT DICATAT\n");
            handlePause();
            printNota(size);
        }else{
            handleError();
        }
    }
}

//untuk mencetak nota pembayaran
int printNota(int size){
    char option;
    while(loop){
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t==================================================================\n");
        printf("\t\t\t||                          E-NOTA                              ||\n");
        printf("\t\t\t||==============================================================||\n");
        printf("\t\t\t\tNama                        : %s\n", user[size].name);
        printf("\t\t\t\tTanggal Pemesanan           : %d %s 2023\n", user[size].tanggalBerangkat[size], user[size].bulanBerangkat);
        printf("\t\t\t\tRute Pesawat                : %s\n", user[size].ruteuser);
        printf("\t\t\t\tWaktu Penerbangan           : %s\n",user[size].waktuBerangkat);
        printf("\t\t\t\tNama Maskapai               : %s\n", user[size].maskapai);
        printf("\t\t\t\tTempat Duduk Penumpang      : ");
        for(int i = 0; i < jumlahPenumpang[size]; i++){
          printf("%d-A  ", user[size].tempatDuduk[i]);
        }
        printf("\n\t\t\t\tBiaya Makanan               : Rp.%d\n", user[size].makanan[size]);
        printf("\t\t\t\tBiaya Bagasi Tambahan       : Rp.%d\n", user[size].bagasi[size]);
        printf("\t\t\t\tStatus                      : %s\n", strcpy(user[size].statusBooking, "Belum Bayar"));
        printf("\t\t\t\tBiaya Tiket Pesawat         : Rp.%d\n", user[size].hargauser[size]);
        printf("\t\t\t\tPPN                         : Rp.%d\n", user[size].ppn[size]);
        TotalPembayaran(size);
        printf("\t\t\t\tTotal Pembayaran            : Rp.%d\n", user[size].totalBayar[size]);
        currentTime(size);
        printf("\t\t\t==================================================================\n\n");
        printf("\t\t\tBayar Sekarang ? (y/n) : ");scanf("%s", &option);
        if(option == 'y'){
            paymentAction(size);
        }else if(option == 'n'){
            menuUtama();
        }else{
            handleError();
            return printNota(size);
        }
    }
}

//untuk menghitung tarif pesawat
int flightFare(int size, int dewasa, int anak, int option){
    switch(option){
    case 1 :
    case 4 :
        user[size].ppn[size] = 100000;
        user[size].hargauser[size] = (dewasa * 650000) + (anak * 600000);
        break;
    case 2 :
    case 7 :
        user[size].ppn[size] = 150000;
        user[size].hargauser[size] = (dewasa * 700000) + (anak * 650000);
        break;
    case 3 :
    case 6 :
        user[size].ppn[size] = 160000;
        user[size].hargauser[size] = (dewasa * 850000) + (anak * 700000) ;
        break;
    case 5 :
        user[size].ppn[size] = 170000;
        user[size].hargauser[size] = (dewasa * 1000000) + (anak * 800000);
        break;
    }
    return  user[size].hargauser[size];
}

//untuk menghitung harga makanan
int priceFood(int size, int jumlah){
     user[size].makanan[size] = jumlah * MAKANAN;
     return user[size].makanan[size];
}

//untuk menghitung harga bagasi tambahan
int bagasi(int size, int jumlah){
    user[size].bagasi[size] = jumlah * BAGASI;
    return user[size].bagasi[size];
}

//untuk menghitung total harga
int TotalPembayaran(int size){
    user[size].totalBayar[size] = user[size].makanan[size] + user[size].bagasi[size] + user[size].hargauser[size] + user[size].ppn[size];
    return user[size].totalBayar[size];
}

//untuk membayar tagihan tiket
void paymentAction(int size){
    int hasil, option;
    printf("\t\t\tMasukkan Saldo Anda : ");scanf("%d", &saldo);
    if(saldo >= user[size].totalBayar[size]){
        hasil = saldo - user[size].totalBayar[size];
        strcpy(user[size].statusBooking, "Sudah Bayar");
        id = rand();
        user[size].userId[size] = id;
        printf("\t\t\tSisa saldo anda : Rp.%d\n\t\t\t", hasil);
        handlePause();;
    }else{
        printf("\t\t\tSALDO ANDA TIDAK CUKUP\n\t\t\t");
        handlePause();
        printNota(size);
    }
    menuUtama();
}

//untuk mendapatkan nomor tempat duduk
void getTempatDuduk(int size, int dewasa, int anak){
    printf("\t\t\tTempat Duduk Penumpang\n");
    for(int i = 0; i < jumlahPenumpang[size]; i++){
        user[size].tempatDuduk[i] = rand() % 50 + 1;
        printf("\t\t\tSit penumpang ke-%d    : %d-A\n", i + 1, user[size].tempatDuduk[i]);
    }
    handlePause();
}


//Untuk mendapatkan waktu saat ini
void currentTime(int size){
    time_t localTime;
    time(&localTime);
    strcpy(user[size].orderTime, ctime(&localTime));
    printf("\t\t\t\tWaktu Order                 : %s", user[size].orderTime);
}

//menampilkan dan sorting data yang telah diinputkan
void bookingHistory(int size){
    int bookingOption;
    printf("\t\t\t[1] Tampilkan Data Berdasarkan Harga Tertinggi - Terendah\n");
    printf("\t\t\t[2] Tampilkan Data Berdasarkan Harga Terendah - Tertinggi\n");
    printf("\t\t\t[3] Kembali\n");
    printf("\t\t\tMasukkan Pilihan : ");scanf("%d",&bookingOption);
    if(bookingOption == 1){
       sortTotalHigh(size);
    }else if(bookingOption == 2){
        sortTotalLow(size);
    }else if(bookingOption == 3){
        menuUtama();
    }else{
        handleError();
    }
}

// untuk mengoutputkan data user
void display(int index){
    printf("\t\t\t______________________________________________________________________________\n");
    printf("\n");
    printf("\t\t\tNama                          : %s\n", user[index].name);
    if(user[index].userId[index] != 0){
      printf("\t\t\tId User                       : %d\n", user[index].userId[index]);
    }
    printf("\t\t\tTanggal Penerbangan           : %d %s 2023\n", user[index].tanggalBerangkat[index], user[index].bulanBerangkat);
    printf("\t\t\tRute user                     : %s\n", user[index].ruteuser);
    printf("\t\t\tWaktu Penerbangan             : %s\n",user[index].waktuBerangkat);
    printf("\t\t\tNama Maskapai                 : %s\n", user[index].maskapai);
    printf("\t\t\tStatus                        : %s\n", user[index].statusBooking);
    printf("\t\t\tWaktu Order                   : %s", user[index].orderTime);
    printf("\t\t\tTotal Pembayaran              : Rp.%d\n", user[index].totalBayar[index]);
    printf("\t\t\t______________________________________________________________________________\n");
}

//sorting descending
void sortTotalHigh(int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(user[j].totalBayar[j] < user[j+1].totalBayar[j+1]){
                strcpy(tempUser[j].name, user[j].name);
                strcpy(tempUser[j].ruteuser, user[j].ruteuser);
                strcpy(tempUser[j].maskapai, user[j].maskapai);
                strcpy(tempUser[j].bulanBerangkat, user[j].bulanBerangkat);
                strcpy(tempUser[j].statusBooking, user[j].statusBooking);
                strcpy(tempUser[j].waktuBerangkat, user[j].waktuBerangkat);
                strcpy(tempUser[j].orderTime, user[j].orderTime);
                tempUser[j].userId[j] = user[j].userId[j];
                tempUser[j].tanggalBerangkat[j] = user[j].tanggalBerangkat[j];
                tempUser[j].totalBayar[j] = user[j].totalBayar[j];

                strcpy(user[j].name, user[j+1].name);
                strcpy(user[j].ruteuser, user[j+1].ruteuser);
                strcpy(user[j].maskapai, user[j+1].maskapai);
                strcpy(user[j].bulanBerangkat, user[j+1].bulanBerangkat);
                strcpy(user[j].statusBooking, user[j + 1].statusBooking);
                strcpy(user[j].waktuBerangkat, user[j + 1].waktuBerangkat);
                strcpy(user[j].orderTime, user[j+1].orderTime);
                user[j].userId[j] = user[j+1].userId[j+1];
                user[j].tanggalBerangkat[j] = user[j+1].tanggalBerangkat[j+1];
                user[j].totalBayar[j] = user[j+1].totalBayar[j+1];

                strcpy(user[j+1].name, tempUser[j].name);
                strcpy(user[j+1].statusBooking, tempUser[j].statusBooking);
                strcpy(user[j+1].maskapai, tempUser[j].maskapai);
                strcpy(user[j+1].ruteuser, tempUser[j].ruteuser);
                strcpy(user[j+1].bulanBerangkat, tempUser[j].bulanBerangkat);
                strcpy(user[j+1].waktuBerangkat, tempUser[j].waktuBerangkat);
                strcpy(user[j+1].orderTime, tempUser[j].orderTime);
                user[j+1].userId[j+1] = tempUser[j].userId[j];
                user[j+1].totalBayar[j+1] = tempUser[j].totalBayar[j];
                user[j+1].tanggalBerangkat[j+1] = tempUser[j].tanggalBerangkat[j];
            }
        }
    }
        for(int i = 0; i < size; i++){
            display(i);
        }
        handlePause();
}


//sorting ascending
void sortTotalLow(int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(user[j].totalBayar[j] > user[j+1].totalBayar[j+1]){
                strcpy(tempUser[j].name, user[j].name);
                strcpy(tempUser[j].ruteuser, user[j].ruteuser);
                strcpy(tempUser[j].maskapai, user[j].maskapai);
                strcpy(tempUser[j].bulanBerangkat, user[j].bulanBerangkat);
                strcpy(tempUser[j].statusBooking, user[j].statusBooking);
                strcpy(tempUser[j].waktuBerangkat, user[j].waktuBerangkat);
                strcpy(tempUser[j].orderTime, user[j].orderTime);
                tempUser[j].userId[j] = user[j].userId[j];
                tempUser[j].tanggalBerangkat[j] = user[j].tanggalBerangkat[j];
                tempUser[j].totalBayar[j] = user[j].totalBayar[j];

                strcpy(user[j].name, user[j+1].name);
                strcpy(user[j].ruteuser, user[j+1].ruteuser);
                strcpy(user[j].maskapai, user[j+1].maskapai);
                strcpy(user[j].bulanBerangkat, user[j+1].bulanBerangkat);
                strcpy(user[j].statusBooking, user[j + 1].statusBooking);
                strcpy(user[j].waktuBerangkat, user[j + 1].waktuBerangkat);
                strcpy(user[j].orderTime, user[j+1].orderTime);
                user[j].userId[j] = user[j+1].userId[j+1];
                user[j].tanggalBerangkat[j] = user[j+1].tanggalBerangkat[j+1];
                user[j].totalBayar[j] = user[j+1].totalBayar[j+1];

                strcpy(user[j+1].name, tempUser[j].name);
                strcpy(user[j+1].statusBooking, tempUser[j].statusBooking);
                strcpy(user[j+1].maskapai, tempUser[j].maskapai);
                strcpy(user[j+1].ruteuser, tempUser[j].ruteuser);
                strcpy(user[j+1].bulanBerangkat, tempUser[j].bulanBerangkat);
                strcpy(user[j+1].waktuBerangkat, tempUser[j].waktuBerangkat);
                strcpy(user[j+1].orderTime, tempUser[j].orderTime);
                user[j+1].userId[j+1] = tempUser[j].userId[j];
                user[j+1].totalBayar[j+1] = tempUser[j].totalBayar[j];
                user[j+1].tanggalBerangkat[j+1] = tempUser[j].tanggalBerangkat[j];
            }
        }
    }

    for(int i = 0; i < size; i++){
        display(i);
    }
    handlePause();
}

//Searching data
void searchCentre(int size){
    int searchOption;
    while(loop){
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t==================================================================\n");
        printf("                         CARI DATA PENERBANGAN ANDA                     \n");
        printf("\t\t\t==================================================================\n");
        printf("\t\t\t[1] Berdasarkan Maskapai\n");
        printf("\t\t\t[2] Berdasarkan Username\n");
        printf("\t\t\t[3] Berdasarkan Id User\n");\
        printf("\t\t\t[4] Kembali\n");
        printf("\t\t\tMasukkan Pilihan : ");scanf("%d", &searchOption);
        if(searchOption == 1){
            cariMaskapai(size);
        }else if(searchOption == 2){
            cariUserName(size);
        }else if(searchOption == 3){
            cariId(size);
        }else if(searchOption == 4){
            menuUtama();
        }
        handlePause();
    }
}

//searching data nama maskapai
void cariMaskapai(int size){
    int n;
    char inputUser[100];
    fflush(stdin);printf("\t\t\tCari maskapai (gunakan huruf kapital): ");gets(inputUser);
    for(int i = 0; i < size; i++){
        if(strcmp(user[i].maskapai, inputUser) == 0){
            n++;
            if(n != 0){
                display(i);
            }
        }
    }
    if(n == 0){
        printf("\t\t\tDATA TIDAK DITEMUKAN\n\t\t\t");
    }
}

//searching data username
void cariUserName(int size){
    int n;
    char inputUser[100];
    fflush(stdin);printf("\t\t\tCari Username : ");gets(inputUser);
    for(int i = 0; i < size; i++){
        if(strcmp(user[i].name, inputUser) == 0){
            n++;
            if(n != 0){
                display(i);
            }
        }
    }
    if(n == 0){
                printf("\t\t\tDATA TIDAK DITEMUKAN\n\t\t\t");
    }
}

//searching data id user
void cariId(int size){
    int n;
    int inputUser;
    fflush(stdin);printf("\t\t\tCari Id : ");scanf("%d", &inputUser);
    for(int i = 0; i < size; i++){
        if(user[i].userId[i] == inputUser){
            n++;
            if(n != 0){
                display(i);
            }
        }
    }
    if(n == 0){
        printf("\t\t\tDATA TIDAK DITEMUKAN\n\t\t\t");
    }
}



//keluar program
void handleExit(){
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t|===============================================================|\n");
    printf("\t\t\t|                                                               |\n");
    printf("\t\t\t|                                                               |\n");
    printf("\t\t\t|         TERIMAKASIH TELAH MENGGUNAKAN LAYANAN KAMI            |\n");
    printf("\t\t\t|                                                               |\n");
    printf("\t\t\t|                                                               |\n");
    printf("\t\t\t|===============================================================|\n");
}

//inputan user salah
void handleError(){
    printf("\t\t\t|===============================================================|\n");
    printf("\t\t\t|              INPUTAN YANG ANDA MASUKKAN TIDAK VALID           |\n");
    printf("\t\t\t|===============================================================|\n\t\t\t");
    handlePause();
}

//untuk memberhentikan output sementara
void handlePause(){
    printf("\n\t\t\tPress any key to continue . . .");
    getch();
}




