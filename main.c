#include<stdio.h>
#include<string.h>
#include<stdbool.h>

FILE *db_user;
FILE *isi_data;
void usermenu();
void pesanan();
void cekstatus();
void adminmenu();
void registrasi();
void daftarpesanan();
void loginuser();
void loginadmin();
void dataobat();
void updateobat();
void hapuspesanan();
void hapusmember();
void infoobat();
void vakun();
int p,luser,ladmin,total,berat,loginadminmenu;
bool ceknampes(char nampes[100]);
bool caripesan(char nampes[100]);
struct
{
    char nama[100],username[100],pass[100],cari1[100],cari2[100],status[100];
    char user[100],nam[100],alamat[100],telp[100],tgl[100],usernamea[100],passa[50];
    char data_obat[100],kt_penyakit[100],dt_harga[100],dt_dosis[100],z[100];
    int biaya, salah, stt ;
} daftar,logina,dtobat;

void main()
{
ulang:
    system("cls");
    puts("\t\t\t================================");
    puts("\t\t\t SELAMAT DATANG DI TOKO OBAT");
    puts("\t\t\t================================");
    puts("1. Login Admin");
    puts("2. Registrasi");
    puts("3. Login User ");
    puts("4. Exit");
    printf("\n\nPilih Menu : ");
    scanf("%d",&p);
    fflush(stdin);
    switch(p)
    {
    case 1:
        loginadmin();
        break;
    case 2:
        registrasi();
        break;
    case 3:
        loginuser();
        break;
    case 4:
        printf("Terima kasih, Selamat Datang Kembali\n");
        break;
    }
}

void loginadmin()
{
    system("cls");
    puts("\t\t\t================================");
    puts("\t\t\t SELAMAT DATANG DI MEDICINE ");
    puts("\t\t\t================================");
    puts("\t\t\t\t Login Admin\n");
    printf("username : ");
    fflush(stdin);
    gets(logina.usernamea);
    printf("password : ");
    fflush(stdin);
    gets(logina.passa);
    if(strcmp(logina.usernamea,"admin")==0&&strcmp(logina.passa,"admin")==0)
    {
        system("cls");
        adminmenu();
    }
    else
    {
        system("cls");
    }
}

void adminmenu()
{
    puts("\t\t\t===============================");
    puts("\t\t\t SELAMAT DATANG DI MEDICINE");
    puts("\t\t\t===============================");
    puts("\t\t\t Selamat Datang Admin\n");
    puts("1. Input data obat");
    puts("2. update informasi obat ");
    puts("3. Lihat informasi obat");
    puts("4. Hapus informasi obat");
    puts("5. Update Virtual Account");
    puts("6. Update Member ");
    puts("7. Hapus Member ");
    puts("8. Exit ");
    printf("Pilihan : ");
    scanf("%d",&loginadminmenu);
    switch(loginadminmenu)
    {
    case 1:
    {
        dataobat();
        break;
    }
    case 2:
    {
        updateobat();
        break;
    }
    case 3:
    {
        infoobat();
        break;
    }
    case 4:
    {
        hapuspesanan();
        break;
    }
    case 5:
    {
        vakun();
        break;
    }
    case 6:
    {
        upmemb();
        break;
    }
    case 7:
    {
        hapusmember();
        break;
    }
    case 8:
    {
        main();
        break;
    }
    default :
        printf ("Error!");
    }
}

void dataobat(int n, int i)
{
    system ("cls");
    FILE *data_obat;
    data_obat=fopen("data_obat.dat","wb");
    printf("Masukan banyak data yang ingin di input : ");
    scanf("%d",&n);
    getchar();
    for(i=0; i<n; i++)
    {
        printf("%d. Nama Obat           : ",i+1);
        gets(dtobat.data_obat);
        printf("    kategori penyakit   : ");
        gets(dtobat.kt_penyakit);
        printf("    Dosis               : ");
        gets(dtobat.dt_dosis);
        printf("    Harga               : ");
        gets(dtobat.dt_harga);
        fwrite(&dtobat,sizeof(dtobat),1,data_obat);
    }
    fclose(data_obat);
    printf("\nOutput");
    data_obat=fopen("data_obat.dat","rb");
    while(fread(&dtobat,sizeof(dtobat),1,data_obat)==1)
    {
        printf("Nama Obat           : %s ",dtobat.data_obat);
        printf("kategori penyakit   : %s ",dtobat.kt_penyakit);
        printf("Dosis               : %s ",dtobat.dt_dosis);
        printf("Harga               : %s ",dtobat.dt_harga);
    }
    fclose(data_obat);
}


void updateobat()
{
    system ("cls");
    FILE *data_obat;
    data_obat=fopen("data_obat.dat","wb");
    printf("    \nEnter untuk edit data obat\n");
    gets(dtobat.data_obat);
    printf("    Nama Obat           : ");
    gets(dtobat.data_obat);
    printf("    kategori penyakit   : ");
    gets(dtobat.kt_penyakit);
    printf("    Dosis               : ");
    gets(dtobat.dt_dosis);
    printf("    Harga               : ");
    gets(dtobat.dt_harga);
    fwrite(&dtobat,sizeof(dtobat),1,data_obat);


    fclose(data_obat);
    printf("\n\nOutput\n");
    data_obat=fopen("data_obat.dat","rb");

    printf("Nama Obat             : %s ",dtobat.data_obat);
    printf("\nkategori penyakit   : %s ",dtobat.kt_penyakit);
    printf("\nDosis               : %s ",dtobat.dt_dosis);
    printf("\nHarga               : %s ",dtobat.dt_harga);
    fclose(data_obat);
}



void infoobat()
{
    system ("cls");
    FILE *data_obat;
    data_obat=fopen("data_obat.dat","rb");
    while(fread(&dtobat,sizeof(dtobat),1,data_obat)==1)
    {
        printf("    Nama Obat           : %s\n ",dtobat.data_obat);
        printf("    kategori penyakit   : %s\n ",dtobat.kt_penyakit);
        printf("    Dosis               : %s\n ",dtobat.dt_dosis);
        printf("    Harga               : %s\n ",dtobat.dt_harga);

    }
    fclose(data_obat);
}



void hapuspesanan()
{
    system ("cls");
    FILE *data_obat;
    FILE *file_hapus;
    data_obat=fopen("data_obat.dat","rb");
    file_hapus = fopen("file_hapus.dat", "wb");
    printf("    \nEnter untuk edit data obat\n");
    gets(dtobat.data_obat);
    printf("    Nama Obat           : ");
    gets(dtobat.data_obat);
    while(fread(&dtobat,sizeof(dtobat),1,file_hapus)==1)
    {
        if(strcmp(file_hapus, dtobat.data_obat)!=0);
        fwrite(&dtobat,sizeof(dtobat),1,file_hapus);
    }

    fclose(data_obat);
    fclose(file_hapus);
    remove("data_obat.dat");
    rename("file_hapus.dat","data_obat.dat");
    printf("Data telah terhapus\n");
    system("pause");
    system("cls");
    adminmenu();
}

void vakun()
{
    system("cls");
    FILE *v_akun;
    v_akun=fopen("v_akun.dat","ab+");
    printf("Masukkan Kode tambahan : "),scanf("%s", &daftar.z);
    fflush(stdin);
    printf("%s",daftar.z);

    FILE *out=fopen("v_akun.dat","a");
    fprintf(out,"%s#STOP#\n", daftar.z);
    fclose(out);
    system("pause");
    system("cls");
    adminmenu();
}

void upmemb()
{
   system("cls");



}
void hapusmember()
{
    system("cls");
    FILE *db_user;
    FILE *db_user2;
    db_user = fopen("db_user.dat", "rb");
    db_user2 = fopen("db_user.dat", "wb");

    printf("\nHapus Semua Member :  ");
    fflush(stdin);
    gets(daftar.user);

    while(fread(&daftar,sizeof(daftar),1,db_user2)==1)
    {
        if(strcmp(db_user2,"yes")!=0);
        fwrite(&daftar,sizeof(daftar),1,db_user2);
    }
    fclose(db_user);
    fclose(db_user2);
    remove("db_user2.dat");
    rename("db_user2.dat","db_user.dat");
    printf("Member telah Dihapus\n");
    system("pause");
    system("cls");
    adminmenu();
}

void registrasi()
{
    system("cls");
    db_user=fopen("save.dat","ab+");
    puts("################################");
    puts("#       FORM REGISTRASI        #");
    puts("################################\n\n");
    printf("Username : "),scanf("%s", &daftar.username);
    fflush(stdin);
    printf("Password : "),scanf("%s", &daftar.pass);
    fflush(stdin);
    printf("Nama     : "),scanf("%s", &daftar.nama);
    fflush(stdin);
    printf("Alamat	 : "),scanf("%s", &daftar.alamat);
    fflush(stdin);
    printf("No HP	 : "),scanf("%s", &daftar.telp);
    fflush(stdin);
    printf("Regist Berhasil , Silahkan Login");
    getchar();

    FILE *out=fopen("db_user.dat","a");
    fprintf(out,"%s#%s#%s#%s#%s#STOP#\n", daftar.username, daftar.pass, daftar.nama, daftar.alamat, daftar.telp);
    fclose(out);
    main();
}

void login(FILE *in, char username[100], char password[100])
{
    if(!feof(in))
    {
        fscanf(in,"%[^#]#", &daftar.username);
        fflush(stdin);
        fscanf(in,"%[^#]#", &daftar.pass);
        fflush(stdin);
        if(strcmp(daftar.username,username)==0 && strcmp(daftar.pass,password)==0)
        {
            fscanf(in,"%[^#]#", &logina.nama);
            fflush(stdin);
            strcpy(logina.status, "Berhasil");
        }
        else
        {
            fscanf(in,"\n");
            fflush(stdin);
            login(in, username, password);
        }
    }
}

void loginuser()
{
    db_user = fopen("save.dat","rb+");
    system("cls");
    puts("\t\t\t================================");
    puts("\t\t\t SELAMAT DATANG DI TOKO OBAT    ");
    puts("\t\t\t================================");
    puts("\t\t\t\t Login User\n");
    while(logina.stt <= 3)
    {
        printf("Username : ");
        fflush(stdin);
        gets(daftar.cari1);
        printf("Password : ");
        gets(daftar.cari2);

        FILE *in=fopen("db_user.dat","r");

        if(strcmp(daftar.cari1, daftar.cari2)==0)
        {
            printf("Selamat Datang, %s\n", logina.nama);
            system("pause");
            system("cls");
            usermenu ();
        }
        else
        {
            printf("Username dan Password tidak match\n");
            logina.salah++;
            if(logina.salah == 3)
            {
                printf("Akses ditolak\n");
                logina.stt++;
            }
        }
        logina.stt++;
    }
}



void usermenu()
{
    puts("\t\t\t================================");
    puts("\t\t\t SELAMAT DATANG DI MEDICINE");
    puts("\t\t\t================================");
    printf("\t\t\t\t SELAMAT DATANG %s \n",logina.nama);
    puts("Menu : ");
    puts("1. Buat Pesanan");
    puts("2. Cek Status");
    puts("3. Exit ");;
    printf("Pilihan : ");
    scanf("%d",&luser);
    switch(luser)
    {
    case 1:
    {
        pesanan();
        break;
    }
    case 2:
    {
        cekstatus();
        break;
    }
    case 3:
    {
        main();
        break;
        default :
            printf ("Error!");
        }
    }
}

bool caripesan(char nampes[100])
{
    FILE *in = fopen("barang.dat","r");

    bool ketemu = false;
    char nam[100], alamat[100], telp[100], tgl[100], user[100], nama[100];

    if(!in)
    {
        return ketemu;
    }
    else
    {
        while(!feof(in) && !ketemu)
        {
            fscanf(in,"%[^#]#", &nam);
            fflush(stdin);
            fscanf(in,"%[^#]#", &alamat);
            fflush(stdin);
            fscanf(in,"%[^#]#", &telp);
            fflush(stdin);
            fscanf(in,"%[^#]#", &tgl);
            fflush(stdin);
            fscanf(in,"%[^#]#", &user);
            fflush(stdin);
            fscanf(in,"%[^#]#", &nama);
            fflush(stdin);

            if(strcmp(nam,nampes)==0)
            {
                ketemu = true;
            }
            fscanf(in,"\n");
            fflush(stdin);
        }
    }
    fclose(in);

    return ketemu;
}

void pesanan()
{
    system ("cls");
    FILE *isi_data;
    isi_data=fopen("barang.dat","a");
    fflush(stdin);
    puts("\t\t\t================================");
    puts("\t\t\t SELAMAT DATANG DI MEDICINE");
    puts("\t\t\t================================");
    printf("\t\t\t\t SELAMAT DATANG %s \n",logina.nama);
    printf("Masukkan User\t: ");
    gets(daftar.user);
    printf("Nama pesanan\t: ");
    gets(daftar.nam);
    printf("Alamat\t\t: ");
    gets(daftar.alamat);
    printf("No Telp\t\t: ");
    gets(daftar.telp);
    printf("Tanggal Pemesanan: \n");
    printf("Tanggal\t\t: ");
    gets(daftar.tgl);

    if(!caripesan(daftar.nam))
    {
        fprintf(isi_data,"%s#%s#%s#%s#%s#%s#\n", daftar.nam, daftar.alamat, daftar.telp, daftar.tgl, daftar.user, logina.nama);
        printf("Berhasil Menambahkan Pesanan\n\n");
    }
    else
    {
        printf("Gagal Menambahkan Karena Nama Pesan sudah ada\n\n");
    }

    fclose(isi_data);

    system("pause");
    system("cls");
    usermenu();
}


int caristatus(char nam[100])
{
    FILE *in = fopen("status.dat","r");

    char nampes[100];
    bool ketemu = false;

    if(!in)
    {
        return 0;
    }
    else
    {
        while(!feof(in) && !ketemu)
        {
            fscanf(in,"%[^#]#", &nampes);
            fflush(stdin);
            fscanf(in,"%[^#]#", &daftar.status);
            fflush(stdin);

            if(strcmp(nam,nampes)==0)
            {
                ketemu = true;
            }
            fscanf(in,"\n");
            fflush(stdin);
        }
    }
    fclose(in);

    if(ketemu)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void cekstatus()
{
    system("cls");
    FILE *db_user;
    int i = 0;
    db_user = fopen("barang.dat","r");
    if(!db_user)
    {
        //Tidak ada db_user status
    }
    else
    {
        while(!feof(db_user))
        {
            fscanf(db_user,"%[^#]#", &daftar.nam);
            fflush(stdin);
            fscanf(db_user,"%[^#]#", &daftar.alamat);
            fflush(stdin);
            fscanf(db_user,"%[^#]#", &daftar.telp);
            fflush(stdin);
            fscanf(db_user,"%[^#]#", &daftar.tgl);
            fflush(stdin);
            fscanf(db_user,"%[^#]#", &daftar.user);
            fflush(stdin);
            fscanf(db_user,"%[^#]#", &daftar.nama);
            fflush(stdin);

            if(strcmp(daftar.cari1,daftar.user)==0)
            {
                i += 1;
                printf("Pesanan ke-%d\n",i);
                printf("Nama pesana	: %s\n", daftar.nam);
                printf("Alamat		: %s\n", daftar.alamat);
                printf("No Telp		: %s\n", daftar.telp);
                printf("Tanggal		: %s\n", daftar.tgl);

                if(caristatus(daftar.nam)==1)
                {
                    printf("Status		: Pesanan Selesai dengan Biaya Rp %d\n\n", daftar.biaya);
                }
                else
                {
                    printf("Status		: Pesanan dalam Proses\n\n");
                }
            }

            fscanf(db_user,"\n");
            fflush(stdin);
        }
    }

    fclose(db_user);
    system("pause");
    system("cls");
    usermenu();
}
