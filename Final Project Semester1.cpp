#include<stdio.h>
#include <time.h>
#include<string.h>
#include <windows.h>
#include <conio.h>
#ifndef MAX
#define MAX 10
#endif

struct bangunan{
	char pembeli[255];
	long long harga;
	long long total_harga;
	char barang[255];
	char jenis[255];
	short tanggal;
	int jumlah_barang;
	bool available;
};

bangunan data[500];
int total_data=0;
FILE *sales;

void dataPenjualan();
void cetakLaporan();
void hapuslaporan();
void dapen();
void menu();
void login();
void loading();
void jam();
void readData();

int main(){  
    system ("color A"); 
    loading();
    //login();
    readData();
	menu();
	fclose(sales);
 	return 0;
}

void readData(){
	FILE *sales;
	sales=fopen("sales.txt","r");
	
	if(sales==NULL){
		printf("File cant be opened\n");
	}
	
	while(fscanf(sales,"%u-%[^-]-%[^-]-%[^-]-%d-%d-%d\r\n",&data[total_data].tanggal,data[total_data].pembeli,data[total_data].jenis,
	data[total_data].barang,&data[total_data].jumlah_barang,&data[total_data].harga,&data[total_data].total_harga)!=EOF){
        total_data++;
    }
    
    fclose(sales);
}

void gotoxy(int x,int y){
	COORD coord = {0,0};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void depan(){
	system ("cls");
	puts("\t==============================================================\t");
	puts("\t\tSELAMAT DATANG DI TOKO BANGUNAN ANJAY BANGUN!!!\t\t\t");
	puts("\t\t\t----------------------------");
	jam();
	puts("\t==============================================================\t\n");
	puts("1. Pendataan penjualan bahan bangunan");
	puts("2. Pencetakan laporan penjualan bahan bangunan (sort menurut tanggal transaksi)");
	puts("3. Pencetakan laporan penjualan bahan bangunan (sort menurut jumlah terjual)");
	puts("4. Hapus Laporan Penjualan");
	puts("5. Exit");
	puts("");
}

void swap(bangunan* xp, bangunan* yp)
{
    bangunan temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void cetakLaporanTanggal(){
	puts("\t==============================================================\t");
	puts("\t\t     CETAK LAPORAN PENJUALAN BAHAN BANGUNAN  \t\t\t");
	puts("\t\t\t----------------------------");
	jam();
	puts("\t==============================================================\t\n");
	printf("%d available data\n",total_data);
	if(!total_data){
		printf("belum ada data \n");
		return;
	}
	int i, j;
	char min_idx;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < total_data-1; i++) {
 
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < total_data; j++)
            if (data[j].tanggal < data[min_idx].tanggal)
                min_idx = j; 
        // Swap the found minimum element
        // with the first elemen
        swap(&data[min_idx], &data[i]);
    }
	char *table[] ={" Tanggal  Transaksi ", "    Nama Pembeli    ", "    Jenis Barang    ", "    Nama  Barang    ", "   Jumlah  Barang   ", "    Harga Barang    ", "  Total Pembayaran  "};
	printf("%*s | %*s | %*s | %*s | %*s | %*s | %*s\n",-3, table[0],-3,table[1],-3,table[2],-3,table[3],-3,table[4],-3,table[5],-3,table[6]);

	for(int i = 0; i < total_data; i++){
		bangunan temp = data[i];
			printf("%-20u | %-20s | %-20s | %-20s | %-20d | %-20lld | %-20lld\n",temp.tanggal, temp.pembeli, temp.jenis, temp.barang, temp.jumlah_barang, temp.harga, temp.total_harga);
 	}

}

void cetakLaporanJumlah(){
	puts("\t==============================================================\t");
	puts("\t\t     CETAK LAPORAN PENJUALAN BAHAN BANGUNAN  \t\t\t");
	puts("\t\t\t----------------------------");
	jam();
	puts("\t==============================================================\t\n");
	printf("%d available data\n",total_data);
	if(!total_data){
		printf("belum ada data \n");
		return;
	}
	int i, j, max_idx;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < total_data; i++) {
 
        // Find the minimum element in unsorted array
        max_idx = i;
        for (j = i + 1; j < total_data; j++)
            if (data[j].jumlah_barang > data[max_idx].jumlah_barang)
                max_idx = j; 
        // Swap the found minimum element
        // with the first elemen
        swap(&data[max_idx], &data[i]);
    }
	char *table[] ={" Tanggal  Transaksi ", "    Nama Pembeli    ", "    Jenis Barang    ", "    Nama  Barang    ", "   Jumlah  Barang   ", "    Harga Barang    ", "  Total Pembayaran  "};
	printf("%*s | %*s | %*s | %*s | %*s | %*s | %*s\n",-3, table[0],-3,table[1],-3,table[2],-3,table[3],-3,table[4],-3,table[5],-3,table[6]);

	for(int i = 0; i < total_data; i++){
		bangunan temp = data[i];
			printf("%-20u | %-20s | %-20s | %-20s | %-20d | %-20lld | %-20lld\n",temp.tanggal, temp.pembeli, temp.jenis, temp.barang, temp.jumlah_barang, temp.harga, temp.total_harga);
 	}

}

void loading(){
	printf("\n\n\n\n\n\n\n");
    printf("\n\n\n\t\t\t\t\t Loading...");
    printf("\n\n");
    printf( "\t\t\t\t\t");
    for (int i=0;i<=25;i++)
    printf("-");
    Sleep(20);
    printf("\r");
    printf("\t\t\t\t\t ");
    for (int i=0; i<= 25; i++)
    {
        printf(">");
        Sleep(40);
    }
    printf ("\n\n\t\t\t\t\t 'PRESS ANY BUTTON TO LOGIN'");
    system ("pause>0");
    system ("cls");
}

void login(){
    	char username[10], password[8];
    	int ulang = 0;
	    for(int j=0; j<3; j++){
        printf("Username: ");
        scanf ( "%s", &username);
        printf("Password: ");
        fflush(stdin);
            char ch;
        int i=0;
        int x=10;
        while((ch = (char) _getch()) != '\r'){
    	if (ch == 8){
    		password[i] = '\0';
    		gotoxy(x-1,1);	
    		printf(" ");
    		x--;
    		i--;	
    		gotoxy(x,1);
		}
	
		else{
			password[i]=ch;
			gotoxy(x,1);
			printf("*");
			x++;
			i++;
		}
	}
        if ((strcmp(username,"admin")==0)&&(strcmp(password,"admin")==0)) {
            break;
        } else {
        	ulang++;
        	if(ulang != 3){
            printf("\nPassword atau username yang anda masukan salah.");
            Sleep(500);
             system ("pause>0");
        }
            else if(ulang == 3){
            	printf("\nAnda Terlalu Banyak Mencoba,Silahkan Buka Progam Ini Kembali.");
            	Sleep(1500);
            	exit(0);
			}
        }
    }
}

void jam(){
    struct tm *waktu;
    time_t Timeval;
    Timeval = time(0);
    waktu = localtime(&Timeval); /* Untuk mendapatkan waktu lokal komputer */  
    printf("\t\t\t  %s", asctime(waktu));/* asctime berfungsi untuk mengubah struct tm menjadi string c*/
}


void dataPenjualan(){
	puts("\t==============================================================\t");
	puts("\t\t     PENDATAAN PENJUALAN BAHAN BANGUNAN  \t\t\t");
	puts("\t\t\t----------------------------");
	jam();
	puts("\t==============================================================\t\n");
	printf("Tanggal Transaksi: ");
    scanf("%u",&data[total_data].tanggal); 
    printf("Nama Pembeli : ");getchar();
    scanf("%[^\n]", data[total_data].pembeli); 
    printf("Jenis Barang : ");getchar();
    scanf("%[^\n]", data[total_data].jenis);
    printf("Nama Barang : ");getchar();
    scanf("%[^\n]", data[total_data].barang); 
    printf("Jumlah Barang : ");getchar();
    scanf("%d", &data[total_data].jumlah_barang);
    printf("Harga Barang: ");getchar();
    scanf("%lld", &data[total_data].harga);
    data[total_data].total_harga=data[total_data].jumlah_barang*data[total_data].harga;
    printf("Total Pembayaran: %lld",data[total_data].total_harga);
    data[total_data].available = true; 
    FILE *output = fopen ("sales.txt","a+");
  	if(fprintf(output,"%d-%s-%s-%s-%d-%lld-%lld\n",data[total_data].tanggal, data[total_data].pembeli, data[total_data].jenis, data[total_data].barang, data[total_data].jumlah_barang,data[total_data].harga,data[total_data].total_harga)){
		  printf ("\n\n\t\t\t\t\t 'DATA BERHASIL DI INPUT'");;
		  Sleep(1300);
	  }
	fclose(output);
	total_data++;	
}

void hapuslaporan(){
	puts("\t==============================================================\t");
	puts("\t\t\t     HAPUS HASIL LAPORAN  \t\t\t");
	puts("\t\t\t----------------------------");
	jam();
	puts("\t==============================================================\t\n");
    char hapus[255];
    printf("Masukan Nama Pembeli yang anda ingin hapus dalam huruf kecil!\n");
    printf("Nama : ");
    scanf("%[^\n]", hapus); getchar();
    for(int i = 0; i < total_data; i++) {
        if(strcmp(data[i].pembeli,hapus) == 0) {
            data[i].available = false;
            break;
        }
    }
}

void menu(){
	bool onApp = true;
    while(onApp) {
        depan();
        int choice = -1;
        do {
            printf(">> ");
            scanf("%d", &choice); getchar();
            system("cls");
        } 
		while(choice < 1 || choice > 5);
         	if(choice == 1) {
               dataPenjualan();
    		}else if(choice ==2){
    			cetakLaporanTanggal();
    			system ("pause>0");
    		}else if(choice ==3){
    			cetakLaporanJumlah();
    			system ("pause>0");
    		}else if(choice ==4){
    			hapuslaporan();
			}else if(choice == 5) {
				system ("cls");
                printf("\n\n\n\t\t\t\t\t\t SEE YOU NEXT TIME...");
                printf("\n\n");
                printf( "\t\t\t\t\t");
            	onApp = false;
        }
	}
}