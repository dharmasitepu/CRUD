#include<stdio.h>
#include<string.h>

FILE *db_user;
FILE *isi_data;
FILE *up_member;
FILE *v_akun;
void usermenu();
void pesanan();
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
void cod();
void bank();

int p,luser,ladmin,total,berat,loginadminmenu,checkout;
struct
{
    char nama[100],username[100],pass[100],cari1[100],cari2[100],status[100];
    char user[100],nam[100],alamat[100],telp[100],tgl[100],usernamea[100],passa[50];
    char data_obat[100],kt_penyakit[100],dt_harga[100],dt_dosis[100],z[100],penyakit[100],up_member[100];
    int biaya, salah, stt ;
} daftar,logina,dtobat,pesan;

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
        printf("\nNama Obat           : %s\n ",dtobat.data_obat);
        printf("kategori penyakit   : %s\n",dtobat.kt_penyakit);
        printf("Dosis               : %s\n ",dtobat.dt_dosis);
        printf("Harga               : %s\n ",dtobat.dt_harga);
    }
    fclose(data_obat);
    system("pause");
    system("cls");
    adminmenu();
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
    system("pause");
    system("cls");
    adminmenu();
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
    system("pause");
    system("cls");
    adminmenu();
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
    system ("cls");
    FILE *up_member;
    up_member=fopen("db_user","wb");
    printf("    \nEnter untuk edit data member\n");
    gets(daftar.up_member);
    printf("    Username           : ");
    gets(daftar.username);
    printf("    Password           : ");
    gets(daftar.pass);
    printf("    Nama               : ");
    gets(daftar.nama);
    printf("    Alamat             : ");
    gets(daftar.alamat);
    printf("    NO hp              : ");
    gets(daftar.telp);
    fwrite(&daftar,sizeof(daftar),1,up_member);

    fclose(up_member);
    printf("\n\nOutput\n");
    up_member=fopen("db_user","rb");

    printf("Username    : %s ",daftar.username);
    printf("\nPassword  : %s ",daftar.pass);
    printf("\nNama     : %s ",daftar.nama);
    printf("\nAlamat     : %s ",daftar.alamat);
    printf("\nNO hp     : %s ",daftar.telp);
    fclose(up_member);
    system("pause");
    system("cls");
    adminmenu();
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

    FILE *out=fopen("db_user.dat","ab");
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
    db_user = fopen("db_user.dat","rb+");
    system("cls");

    puts("\t\t\t================================");
    puts("\t\t\t SELAMAT DATANG DI TOKO OBAT    ");
    puts("\t\t\t================================");
    puts("\t\t\t\t Login User\n");
    while(logina.stt <= 3)
    {
        printf("Username : ");
        fflush(stdin);
        gets(daftar.username);
        printf("Password : ");
        gets(daftar.pass);

        FILE *in=fopen("db_user.dat","r");

        if(strcmp(daftar.username, daftar.pass) && strcmp(daftar.username, daftar.pass)!=0)
        {
            printf("Selamat Datang\n");
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
    puts("2. Exit ");;
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
        main();
        break;
        default :
            printf ("Error!");
        }
    }
}

void pesanan()
{
    system ("cls");
    FILE *data_obat;
    FILE *penyakit;
    char sakit;
    int n;
    data_obat=fopen("data_obat.dat","rb");
    //penyakit=fopen("penyakit.dat","wb");
    fflush(stdin);
    puts("\t\t\t================================");
    puts("\t\t\t SELAMAT DATANG DI MEDICINE");
    puts("\t\t\t================================");
    printf("\t\t\t\t SELAMAT DATANG\n");
    while(fread(&dtobat,sizeof(dtobat),1,data_obat)==1)
    {
        printf("\nNama Obat         : %s\n ",dtobat.data_obat);
        printf("kategori penyakit   : %s\n ",dtobat.kt_penyakit);
        printf("Dosis               : %s\n ",dtobat.dt_dosis);
        printf("Harga               : %s\n ",dtobat.dt_harga);
    }
    {
        printf("Ketik Kategori penyakit untuk membeli obat 1-3 :");
        scanf("%d", &n);
        getchar();
    }
    //fclose(penyakit);
    system("pause");
    system("cls");




    puts("Menu : ");
    puts("1. COD");
    puts("2. BANK ");;
    printf("Pilihan : ");scanf("%d", &checkout);
    switch(checkout)
    {
    case 1:
    {
        cod();
        break;
    }
    case 2:
    {
        bank();
        break;
        default :
            printf ("Error!");
            system("pause");
            system("cls");
            pesanan();
        }
    }
}

void cod()
{
    printf("Cash On Delivery\n");
    printf("Obat akan segera dikirim\n");
    printf("Terima Kasih\n");
    system("pause");
    system("cls");
    usermenu();
}

void bank()
{   FILE *v_akun;
    char v_hasil;
    v_akun=fopen("v_akun.dat","a=rb");
    v_hasil=v_akun+v_hasil;
    printf("NO Rekening Anda Adalah : %d\n",v_hasil);fflush(stdin);
    system("pause");
    system("cls");
    usermenu();
}
