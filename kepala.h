#ifndef KEPALA_H_INCLUDED
#define KEPALA_H_INCLUDED

#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

//struktur data untuk penyimpanan
struct data {
	char ID[15];
	char nama[50];
	char progdi[50];
	char add[50];
	char ortu[50];
	char kelas[10];
	char no_telp[12];
};
struct data mahasiswa;

void gotoxy(int x, int y);
void buat_kotak();
void bersih_tampilan();
void tampilan();
void print_judul(const char judul[]);
void add_mahasiswa();
void cari_mahasiswa();
void ubah_mahasiswa();
void hapus_mahasiswa();
void main_tampilan();


void gotoxy(int x,int y){
	COORD coord;
	coord.X = x; coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void buat_kotak(){
		int i,j;
	gotoxy(0,0);
	printf("%c",201);
	for (i=1; i<78; i++){
		gotoxy(i,0);
		printf("%c",205);
	}
	gotoxy(78,0);
	printf("%c",187);
	for(i=1;i<25;i++){
		gotoxy(78,i);
		if (i == 6){
			printf("%c",185);
		}else{
			printf("%c",186);
		}
	}
	gotoxy(78,25);
	printf("%c",188);
	for(i=1;i<78 ;i++){
		gotoxy (i,25);
		if (i == 35){
			printf("%c",202);
		}else{
			printf("%c",205);
		}
	}
	gotoxy (0,25);
	printf("%c",200);
	for(i=1;i<78;i++){
		gotoxy(i,6);
		if(i==35){
			printf("%c",203);
		}else{
			printf("%c",205);
		}
	}
	gotoxy(0,25);
	for(i=24;i>0;i--){
		gotoxy(0,i);
		if(i==6){
			printf("%c",204);
		}else{
			printf("%c",186);
		}
	}
	for(i=7; i<25; i++){
		gotoxy(35,i);
		printf("%c",186);
    }
}
void bersih_tampilan(){
		int i,j;
	for( i=37;i<78;i++){
		for(j=7;j<25;j++){
			gotoxy(i,j);
			printf(" ");
		}
	}
}
void tampilan(){
	buat_kotak();
	gotoxy(25,2);
	gotoxy(30,2);
    printf("====PROGRAM AHP====");
	gotoxy(28,4);
	printf("UNIVERSITAS SYIAH KUALA");
}
void print_judul(const char judul[]){
	gotoxy(45,8);
	printf("POLKE ->%s",judul);
}
void add_mahasiswa(){
	bersih_tampilan();
	print_judul("Menambah data Mahasiswa");
	int print =37;
	FILE *fp;
	fp = fopen ("Data_Mahasiswa.txt","ab+");
	if (fp == NULL){
		MessageBeep(0);
	}else{
		int a=1,b;
		gotoxy(print,10);printf("Berapa Data yang akan ditambahkan ? = "); scanf("%d",&b);
		while(a<=b){
			fflush(stdin);
			gotoxy(print,12);printf("Nim: ");gets(mahasiswa.ID);
			gotoxy(print,13);printf("Nama: ");gets(mahasiswa.nama);
			gotoxy(print,14);printf("Program Study: ");gets(mahasiswa.progdi);
			gotoxy(print,15);printf("Kelas: ");gets(mahasiswa.kelas);
			gotoxy(print,16);printf("Alamat ");gets(mahasiswa.add);
			gotoxy(print,17);printf("Nama ortu: ");gets(mahasiswa.ortu);
			gotoxy(print,18);printf("no. telepon: ");gets(mahasiswa.no_telp);
			fwrite(&mahasiswa, sizeof(mahasiswa), 1, fp);
			a++;	
		}
			gotoxy(40,20);printf("Data berhasil ditambahkan..");	
	}
	fclose(fp);
	return;
}
void cari_mahasiswa(){
	bersih_tampilan();
	print_judul("Mencari Data Mahasiswa");
	char s_id[15];
	FILE *fp;
	int isFound = 0;
	gotoxy(37,10);printf("inputkan NIM: ");fflush(stdin);
	gets(s_id);
	fp=fopen("Data_Mahasiswa.txt","ab+");
	while(fread(&mahasiswa,sizeof(mahasiswa),1,fp)==1){
		if(strcmp(s_id, mahasiswa.ID)==0)
		isFound = 1;
		break;
	}
	if (isFound ==1){
		gotoxy(37,12);printf("Data ditemukan..");
		gotoxy(37,14);printf("Nim : %s",mahasiswa.ID);
		gotoxy(37,15);printf("Nama : %s",mahasiswa.nama);
		gotoxy(37,16);printf("Program Study : %s",mahasiswa.progdi);
		gotoxy(37,17);printf("Kelas : %s",mahasiswa.kelas);
		gotoxy(37,18);printf("Alamat: %s",mahasiswa.add);
		gotoxy(37,19);printf("Nama orang tua : %s",mahasiswa.ortu);
		gotoxy(37,20);printf("No. telepon : %s",mahasiswa.no_telp);
	} else{
		gotoxy(37,12);printf("Maaf data yang dicari tidak ada !!");
	}
	fclose(fp);
	return;
}
void ubah_mahasiswa(){
	bersih_tampilan();
	print_judul("Mengubah Data Mahasiswa");
	char s_id[15];
	int isFound=0, print=37;
	gotoxy(37,10);printf("Inputkan Nim : ");fflush(stdin);
	gets (s_id);
	FILE *fp;
	fp =fopen("Data_mahasiswa.txt","rb+");
	while(fread(&mahasiswa,sizeof(mahasiswa),1,fp)==1){
		if(strcmp(s_id, mahasiswa.ID)==0){
			fflush(stdin);
			gotoxy(print,12);printf("Nim: ");gets(mahasiswa.ID);
			gotoxy(print,13);printf("Nama: ");gets(mahasiswa.nama);
			gotoxy(print,14);printf("Program Study: ");gets(mahasiswa.progdi);
			gotoxy(print,15);printf("Kelas: ");gets(mahasiswa.kelas);
			gotoxy(print,16);printf("Alamat ");gets(mahasiswa.add);
			gotoxy(print,17);printf("Nama ortu: ");gets(mahasiswa.ortu);
			gotoxy(print,18);printf("no. telepon: ");gets(mahasiswa.no_telp);
			fseek(fp, -sizeof(mahasiswa),SEEK_CUR);
			fwrite(&mahasiswa,sizeof(mahasiswa),1,fp);
			isFound = 1;
			gotoxy(40,20);printf("Data Berhasil diperbarui");
			break;
		}
	}
	if (!isFound){
		gotoxy(print,12);printf("Data tidak ditemukan...");
	}
	fclose(fp);
	return;
}
void hapus_mahasiswa(){
	bersih_tampilan();
	print_judul("Menghapus Data Mahasiswa");
	char s_id[15];
	int isFound =0; int print =37;
	gotoxy(37,10);printf("Inputkan NIM; ");fflush(stdin);
	gets(s_id);
	FILE *fp, *temp;
	fp = fopen ("Data_Mahasiswa.txt","ab+");
	temp =  fopen("temp.txt","wb");
	while (fread(&mahasiswa,sizeof(mahasiswa),1,temp)==1){
		if (strcmp (s_id,mahasiswa.ID)==0){
			fwrite(&mahasiswa,sizeof(mahasiswa),1,temp);
		}
	}
	fclose(fp);
	fclose(temp);
	remove("Data_Mahasiswa.txt");
	rename("temp.txt","Data_Mahasiswa");
	gotoxy(37,12);printf("Data telah sukses dihapus...");
	return;
}

void main_tampilan(){
	int pilih;
	int x=2;
	while(1){
		gotoxy(x,8);printf("1. Menambahkan Data Mahasiswa");
		gotoxy(x,10);printf("2. Mencari Data Mahasiswa");
		gotoxy(x,12);printf("3. Modifikasi Data Mahasiswa");
		gotoxy(x,14);printf("4. Menghapus Data Mahasiswa");
		gotoxy(x,16);printf("5. Keluar");
		gotoxy(x,18);printf(" Masukkan Pilihan Anda: ");scanf("%d",&pilih);
		switch(pilih){
			case 1: printf("sampai disni");add_mahasiswa(); break;
			case 2: cari_mahasiswa();break;
			case 3: ubah_mahasiswa();break;
			case 4: hapus_mahasiswa();break;
			case 5: exit(0); break;
			dafault: break;
		}
	}
}
#endif //KEPALA_H_INCLUDED
