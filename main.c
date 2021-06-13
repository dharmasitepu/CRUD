#include<stdio.h>
#include<string.h>

FILE *db_user;
FILE *data_obat;
FILE *v_akun;
void main();
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
void bri();
void mandiri();
int caseuser,caseadmin,total,berat,loginadminmenu,checkout,bankswitch;

struct
{
    //struct (daftar)
    char z[20],db_user[20],username[20],pass[20],nama[20],alamat[20],telp[20];
    int salah, stt;
    //struct (logina)
    char usernamea[20],passa[20];
    //struct (dtobat)
    char data_obat[20],kt_penyakit[20],dt_harga[20],dt_dosis[20];

} daftar,logina,dtobat;

void main()
{
    system("cls");
    puts("################################");
    puts("####       TOKO OBAT        ####");
    puts("################################\n\n");
    puts("1. Login Admin");
    puts("2. Registrasi");
    puts("3. Login User ");
    puts("4. Exit");
    printf("\n\nPilih Menu : ");
    scanf("%d",&caseadmin);
    fflush(stdin);
    switch(caseadmin)
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
    puts("################################");
    puts("####       LOGIN ADMIN      ####");
    puts("################################\n\n");
    printf("username : ");
    fflush(stdin);
    gets(logina.usernamea);
    printf("password : ");
    fflush(stdin);
    gets(logina.passa);
    if(strcmp(logina.usernamea,"123")==0&&strcmp(logina.passa,"123")==0)
    {
        system("cls");
        adminmenu();
    }
    else
    {
        system("cls");
        main();
    }
}

void adminmenu()
{
    puts("################################");
    puts("####       MENU ADMIN       ####");
    puts("################################\n\n");
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
    puts("################################");
    puts("####     INPUT DATA OBAT    ####");
    puts("################################\n\n");
    data_obat=fopen("data_obat.dat","wb");
    printf("Masukan banyak data obat 1-3 : ");
    scanf("%d",&n);
    getchar();
    for(i=0; i<n; i++)
    {
        printf("\n%d.  Nama Obat           : ",i+1);
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
    printf("\n\n\t\tOutput\n");
    data_obat=fopen("data_obat.dat","rb");
    while(fread(&dtobat,sizeof(dtobat),1,data_obat)==1)
    {
        printf("\n\tNama Obat\t\t: %s\n ",dtobat.data_obat);
        printf("\tkategori penyakit\t: %s\n",dtobat.kt_penyakit);
        printf("\tDosis\t\t\t: %s\n ",dtobat.dt_dosis);
        printf("\tHarga\t\t\t\: %s\n ",dtobat.dt_harga);
    }
    fclose(data_obat);
    system("pause");
    system("cls");
    adminmenu();
}

void updateobat()
{
    system ("cls");
    puts("################################");
    puts("####    UPDATE DATA OBAT    ####");
    puts("################################\n\n");
    data_obat=fopen("data_obat.dat","wb");
    fflush(stdin);
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
    printf("\n\n\tOutput\n");
    data_obat=fopen("data_obat.dat","rb");
    printf("Nama Obat\t\t: %s ",dtobat.data_obat);
    printf("\nkategori penyakit\t: %s ",dtobat.kt_penyakit);
    printf("\nDosis\t\t\t: %s ",dtobat.dt_dosis);
    printf("\nHarga\t\t\t: %s ",dtobat.dt_harga);
    fclose(data_obat);
    system("pause");
    system("cls");
    adminmenu();
}

void infoobat()
{
    system ("cls");
    puts("################################");
    puts("####     INFO DATA OBAT    ####");
    puts("################################\n\n");
    data_obat=fopen("data_obat.dat","rb");
    while(fread(&dtobat,sizeof(dtobat),1,data_obat)==1)
    {
        printf("\nNama Obat\t\t: %s\n ",dtobat.data_obat);
        printf("kategori penyakit\t: %s\n ",dtobat.kt_penyakit);
        printf("Dosis\t\t\t: %s\n ",dtobat.dt_dosis);
        printf("Harga\t\t\t: %s\n ",dtobat.dt_harga);
    }
    fclose(data_obat);
    system("pause");
    system("cls");
    adminmenu();
}

void hapuspesanan()
{
    system ("cls");
    puts("################################");
    puts("####     HAPUS DATA OBAT    ####");
    puts("################################\n\n");
    FILE *file_hapus;
    char haps[20];
    data_obat=fopen("data_obat.dat","rb");
    file_hapus = fopen("file_hapus.dat", "wb");
    gets(file_hapus);
    printf("Nama Obat   :");
    gets(haps);
    while(fread(&dtobat,sizeof(dtobat),1,file_hapus)!=1)
    {
        if(strcmp(haps, dtobat.data_obat)==0);
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
    puts("################################");
    puts("####     VIRTUAL ACCOUNT    ####");
    puts("################################\n\n");
    v_akun=fopen("v_akun.dat","wb");
    printf("Masukkan Kode tambahan : "),scanf("%s", &daftar.z);
    fflush(stdin);
    printf("\n   %s + NO HP MEMBER\n\n\n",daftar.z);
    FILE *out=fopen("v_akun.dat","ab");
    fprintf(out,"%s#STOP#\n", daftar.z);
    fclose(out);
    system("pause");
    system("cls");
    adminmenu();
}

void upmemb()
{
    system ("cls");
    puts("################################");
    puts("####      UPDATE MEMBER     ####");
    puts("################################\n\n");
    db_user=fopen("db_user.dat","wb");
    printf("    \nEnter untuk edit data member\n");
    gets(daftar.db_user);
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
    fwrite(&daftar,sizeof(daftar),1,db_user);
    fclose(db_user);
    printf("\n\nOutput\n");
    db_user=fopen("db_user","rb");
    printf("\nUsername  : %s ",daftar.username);
    printf("\nPassword  : %s ",daftar.pass);
    printf("\nNama      : %s ",daftar.nama);
    printf("\nAlamat    : %s ",daftar.alamat);
    printf("\nNO hp     : %s ",daftar.telp);
    fclose(db_user);
    system("pause");
    system("cls");
    adminmenu();
}

void hapusmember()
{
    system("cls");
    puts("################################");
    puts("####       HAPUS MEMBER     ####");
    puts("################################\n\n");
    FILE *db_user2;
    char rere[20];
    db_user = fopen("db_user.dat", "rb");
    db_user2 = fopen("db_user.dat", "wb");
    printf("\nHapus Semua Member (yes) :  ");
    fflush(stdin);
    gets(daftar.username);
    while(fread(&daftar,sizeof(daftar),1,db_user2)==1)
    {
        if(strcmp(db_user, rere)!=0);
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
    db_user=fopen("db_user.dat","ab+");
    puts("#################################");
    puts("####     FORM REGISTRASI     ####");
    puts("#################################\n\n");
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

void loginuser()
{
    system("cls");
    puts("################################");
    puts("####       LOGIN USER      ####");
    puts("################################\n\n");
    char usr[20],pws[20];
    db_user = fopen("db_user.dat","rb+");
    while(daftar.stt <= 3)
    {
        printf("Username : ");
        gets(usr);
        printf("Password : ");
        gets(pws);

        FILE *db_user=fopen("db_user.dat","rb");

        if(strcmp(usr,daftar.username)==0 && strcmp(pws,daftar.pass)==0)
        {
            printf("Selamat Datang\n");
            system("pause");
            system("cls");
            usermenu ();
        }
        else
        {
            printf("Username dan Password tidak match\n");
            daftar.salah++;
            if(daftar.salah == 3)
            {
                printf("Akses ditolak\n");
                daftar.stt++;
                system("pause");
                system("cls");
                main();
            }
        }
        daftar.stt++;
    }
}

void usermenu()
{
    puts("################################");
    puts("####      MENU MEMBER       ####");
    puts("################################\n\n");
    puts("Menu : ");
    puts("1. Buat Pesanan");
    puts("2. Exit ");
    printf("Pilihan : ");
    scanf("%d",&caseuser);
    switch(caseuser)
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
            system("pause");
            system("cls");
            usermenu();
    }
    }
}

void pesanan()
{
    system ("cls");
    FILE *data_obat;
    data_obat=fopen("data_obat.dat","rb");
    fflush(stdin);
    puts("################################");
    puts("####     MENU PEMESANAN     ####");
    puts("################################\n\n");
    while(fread(&dtobat,sizeof(dtobat),1,data_obat)==1)
    {
        printf("\nNama Obat         : %s\n ",dtobat.data_obat);
        printf("kategori penyakit   : %s\n ",dtobat.kt_penyakit);
        printf("Dosis               : %s\n ",dtobat.dt_dosis);
        printf("Harga               : %s\n ",dtobat.dt_harga);
    }
    {
        printf("Ketik Kategori Penyakit untuk membeli obat :");
        scanf("%s", &dtobat.kt_penyakit);
        getchar();
    }
    system("pause");
    system("cls");
    puts("Menu : ");
    puts("1. COD");
    puts("2. BANK ");;
    printf("Pilihan : ");
    scanf("%d", &checkout);
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
{
    FILE *v_akun;
    FILE *db_user;
    v_akun=fopen("v_akun.dat","rb");
    db_user=fopen("db_user.dat","rb");
    printf("NO Rekening Anda Adalah : %s%s\n",daftar.z,daftar.telp);
    fflush(stdin);
    system("pause");
    system("cls");
    puts("################################");
    puts("####       PILIH BANK       ####");
    puts("################################\n\n");
    puts("PILIH JENIS BANK");
    puts("1. MANDIRI");
    puts("2. BRI ");;
    printf("Pilihan : ");
    scanf("%d",&bankswitch);
    switch(bankswitch)
    {
    case 1:
    {
        mandiri();
        break;
    }
    case 2:
    {
        bri();
        break;
        default :
            printf ("Error!");
            system("pause");
            system("cls");
            bank();
        }
    }
}

void mandiri()
{
    printf("Silahkan Transfer ke bank mandiri\n");
    printf("NO REK :12121212121212\n");
    printf("Terima Kasih\n");
    system("pause");
    system("cls");
    usermenu();
}

void bri()
{
    printf("Silahkan Transfer ke bank BRI\n");
    printf("NO REK :1313131313131313\n");
    printf("Terima Kasih\n");
    system("pause");
    system("cls");
    usermenu();
}
