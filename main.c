#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<windows.h>

struct kamus{

        char bahasa [30], language[30],bjowo[30];
        int jumlahData;
        struct kamus *next;

} *head, *tail, *current;


void Lihat()
{
    system("cls");
    system("color 1F");
    if (head == NULL)
    {
        printf("Belum ada data, plis input your data! \n");

    }
    else
    {
        current = head;

        int i = 0;
        while (current != NULL)
            {
                printf("\n\n\n\n\t\t\t\t\tData ke - %i\n", i+1);
                printf("\t\t\t\t========================================================\n\n");
                printf("\t\t\t\t\tBahasa    : %s \n\n", current->bahasa);
                printf("\t\t\t\t+------------------------------------------------------+\n\n");
                printf("\t\t\t\t\tLanguage  : %s \n\n", current->language);
                printf("\t\t\t\t+------------------------------------------------------+\n\n");
                printf("\t\t\t\t\tJowo      : %s \n\n", current->bjowo);
                printf("\t\t\t\t========================================================\n\n");
                current = current->next;
                printf("\n");

                i++;
            }
            printf("\t\t\t\t\tTekan apa saja untuk kembali ke menu!!!");
    }
    printf("\n");
}

void tambahData()
{
    system("cls");
    system("color 1F");
    char bahasa [15], language[15], bjowo[15];

    current = (struct kamus*)malloc(sizeof(struct kamus));

    printf("\n\n\n\n\n\n\n\n\t\t\t\tTambahkan Data Kamus ");
    printf("\n\n\t\t\t========================================================\n\n");
    printf("\t\t\t\tBahasa : ");
    scanf("%s",&bahasa);
    fflush(stdin);
    printf("\t\t\t+------------------------------------------------------+\n\n");
    printf("\t\t\t\tLanguage : ");
    scanf("%s",&language);
    fflush(stdin);
    printf("\t\t\t+------------------------------------------------------+\n\n");
    printf("\t\t\t\tJowo : ");
    scanf("%s",&bjowo);
    fflush(stdin);
    printf("\t\t\t========================================================\n\n");

    fflush(stdin);

    strcpy(current->bahasa, bahasa);
    strcpy(current->language, language);
    strcpy(current->bjowo, bjowo);

    if (head == NULL)
    {
        head = tail = current;
    }
    else
    {
        tail->next = current;
        tail = current;
    }
    tail->next = NULL;
    printf("\n\t\t\t Data berhasil ");
}

void editData()
{
    system("cls");
    char bahasa[15], language[15], bjowo[15];
    int pilihan;

    if (head == NULL)
    {
        printf("belum ada data");

    }
    else
    {
        current = head;

        printf("\n\n\n\n\t\t\t\tCari data yang mau diedit berdasarkan B.Indonesia : ");
        scanf("%s", &bahasa);
        printf("\n\t\t\t=====================================================================\n\n");
        while(current != NULL)
        {
            if (strcasecmp(current->bahasa,bahasa)==0)
            {
                    printf("\n\t\t\t\t\t\t1. B indonesia : %s\n", current->bahasa);
                    printf("\n\t\t\t\t\t\t2. B inggris : %s\n", current->language);
                    printf("\n\t\t\t\t\t\t3. B jawa : %s\n", current->bjowo);
                    printf("\n\t\t\t=====================================================================\n\n");

                    printf("\n\t\t\t\t\t\tMasukan nomer yang mau di edit : ");scanf("%i",&pilihan);



                switch(pilihan)
                {
                    case 1:
                    printf("\n\t\t\t\t\t\tEDIT DATA\n");
                    char dataBaru[30];
                    printf("\n\t\t\t\t\t\tdata lama : %s",current->bahasa);
                    printf("\n\t\t\t\t\t\tdata baru : ");fflush(stdin);gets(dataBaru);
                    strcpy(current->bahasa, dataBaru);

                    break;

                    case 2:
                    printf("\n\t\t\t\t\t\tEDIT DATA\n");
                    char dataBaru2[30];
                    printf("\n\t\t\t\t\t\tdata lama : %s",current->language);
                    printf("\n\t\t\t\t\t\tdata baru : ");fflush(stdin);gets(dataBaru);
                    strcpy(current->language, dataBaru);

                    break;

                    case 3:
                    printf("\n\t\t\t\t\t\tEDIT DATA\n");
                    char dataBaru3[30];
                    printf("\n\t\t\t\t\t\tdata lama : %s",current->bjowo);
                    printf("\n\t\t\t\t\t\tdata baru : ");fflush(stdin);gets(dataBaru);
                    strcpy(current->bjowo, dataBaru);

                    break;

                    default:
                        printf("default");
                }

                    printf("\n\t\t\t\t\t\tData berhasil diedit");
                    printf("\n\n\t\t\t=====================================================================\n\n");
                break;
            }
         else if (current == NULL || current->next==NULL)
            {
                printf("\n\t\t\t\t\t\tdata tidak ada");
            }
        current = current->next;
    }
  }
}


void deletData()
{
    system("cls");
    if (head == NULL)
    {
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\tBelum ada data");
        printf("\n\t\t\t=====================================================================\n\n");

    }
    else
    {
        struct kamus *temp = head;
        current = head;
        char bahasa[15];
        printf("\n\n\n\n\n\n\t\t\t\t\Cari KATA YANG INGIN DIHAPUS BERDASARKAN B.INDONESIA : ");
        scanf("%s",&bahasa);
        printf("\n\t\t\t=====================================================================\n\n");
        int index = 0;
        while (current != NULL)
        {
            if (strcasecmp(current->bahasa, bahasa)==0)
            {
                break;
            }
            index++;
            current = current->next;
        }
        if (index == 0)
        {
            head = temp->next;
            free(temp);
            printf("\n\t\t\t\t\t\tData berhasil dihapus");
            printf("\n\n\n\t\t\t=====================================================================\n\n");

        }
        else
        {
            for (int i=1; temp != NULL && i<index; i++)
            {
                temp = temp->next;
            }
            if (temp == NULL || temp->next == NULL)
            {
                printf("\n Data tidak ada");
            }
            else
            {
                struct kamus *next = temp->next->next;
                free(temp->next);
                temp->next = next;
                printf("\n Data berhasil dihapus");
            }
        }
    }
}

void searching()
{
    if (head == NULL){
        printf("\n\t\t\t\tbelum ada data");

    }else{
int cari;
system("cls");
        printf("\n\n\n\n\t\t\t\t  =================================================\n");
        printf("\t\t\t\t  ===================  SORTING   ==================\n");
        printf("\t\t\t\t  =================================================\n");
        printf("\t\t\t\t1. cari berdasarkan B. indonesia\t\t\t\t\n");
        printf("\t\t\t\t2. cari berdasarkan B. inggris\t\t\t\t\n");
        printf("\t\t\t\t3. cari berdasarkan B. jawa\t\t\t\t\n");
        printf("\t\t\t\tTekan 4 untuk kembali\t\t\t\t\n");
        printf("\t\t\t\tPilihan : ");
        scanf("%d",&cari);


        switch(cari){
            case 1: searchindonesia();break;
            case 2: searchinggris();break;
            case 3: searchjawa();break;
            case 4: break;
            default : printf("masukan angka yang benar");
            break;

        }



}
}

       /////           ////            ///////




void searchindonesia()
{
    char bahasa[20];
    int i=0;
    printf("\n\t\t\t\tmasukan kata yang ingin dicari (B.indonesia): ");
    scanf("%s",&bahasa);
    current = head;

    while (current!=NULL)
    {
        if(strcasecmp(current->bahasa,bahasa)==0){
            i=1;
            printf("\n\t\t\t\tData ditemukan\n");break;
        }
        current=current->next;
    }

    if(i==1){

     printf("\n\n\t\t\t\t\t\t  KATA YANG DICARI");
        printf("\n\t\t =====================================================================================\n");
        printf("\t\t |  INDONESIA|                INGGRIS|              JAWA|\n");
        printf("\t\t =====================================================================================\n");
        printf("\t\t |%4s|%20s|%18s|\n", current->bahasa,current->language,current->bjowo);
        printf("\t\t =====================================================================================\n");
        //getch();

    }else if (i!=1) {
        printf("Data tidak ditemukan");
    }
}

//////////// ////////////////
void searchinggris()
{
    char language[30];
    int i=0;
    printf("\n\t\t\t\tmasukan kata yang ingin dicari (B.inggris):");
    scanf(" %s",&language);
    current = head;
    while (current!=NULL)
    {
        if(strcmp(current->language,language)==0){
            i=1;
            printf("data ditemukan\n");break;
        }
        current=current->next;
    }
    if(i==1){

     printf("\n\n\t\t\t\t\t\t  KATA YANG DICARI");
        printf("\n\t\t =====================================================================================\n");
        printf("\t\t |  INDONESIA|                INGGRIS|              JAWA|\n");
        printf("\t\t =====================================================================================\n");
        printf("\t\t |%4s|%20s|%18s|\n", current->bahasa,current->language,current->bjowo);
        printf("\t\t =====================================================================================\n");
        getch();
    }else if (i!=0){
        printf("Data tidak ditemukan");
    }


}

///////////


void searchjawa()
{

char bjowo[30];
    int i=0;
    printf("\n\t\t\t\tmasukan kata yang ingin dicari (B.jawa):");
    scanf(" %s",&bjowo);
    current = head;
    while (current!=NULL)
    {
        if(strcmp(current->bjowo,bjowo)==0){
            i=1;
            printf("data ditemukan\n");break;
        }
        current=current->next;
    }
    if(i==1){

     printf("\n\n\t\t\t\t\t\t  KATA YANG DICARI");
        printf("\n\t\t =====================================================================================\n");
        printf("\t\t |  INDONESIA|                INGGRIS|              JAWA|\n");
        printf("\t\t =====================================================================================\n");
        printf("\t\t |%4s|%20s|%18s|\n", current->bahasa,current->language,current->bjowo);
        printf("\t\t =====================================================================================\n");
        getch();
    }else if (i!=0){
        printf("Data tidak ditemukan");
    }
}

void keluar ()
{
    system("cls");
            printf("			 \n\n\n\n\n\n\n					Pembuat: \n\n 					Samuel Galuh Dias Pramudya(672021023)\n\n					Muhammad Jafar.(672021150)\n\n					Danie Abdillah Iskandar(672021267)\n\n");
            printf("\n\n\n\t\tKarena untuk setiap ucapan Selamat Datang akan selalu diakhiri dengan ucapan Selamat Tinggal");
}

int main()
{
    char username[8], pass[12];
    int repeat = 0, gagal = 0;

    while(repeat < 3)
    {
      system("color 1F");
      printf("\n\n\n\n\n\n\t\t\t\t\tMasukkan Username (admin): ");
      scanf("%s", &username);
      printf("\n\t\t\t\t\tMasukkan Password (123): ");
      scanf("%s", &pass);

      if(strcmp(username,"admin")==0 && strcmp (pass,"123")== 0)
      {
         printf("\t\t\t\t\tSelamat, kamu berhasil login\n");
         system("cls");
         break;
      }
      else
        {
            printf("Input Salah!\n");
            gagal++;
            if(gagal == 3)
            {
                printf("Sayang sekali, kamu tidak bisa login lagi\n");
            }
        }
      repeat++;
    }


    system("color 1F");
    int home;
    do {
            printf("\n\n\n\n\n\n\n\t\t\t==========================================================================\n");
            printf("\n\t\t\t\t\t\tSELAMAT DATANG DIPROGRAM KAMUS ");
            printf("\n\n\t\t\t=============================   MENU KAMUS   =============================\n\n");
            printf("\t\t\t\t1. Menampilkan isi data kamus\n");
            printf("\t\t\t\t2. Membuat data baru kamus \n");
            printf("\t\t\t\t3. Mengedit data ke kamus\n");
            printf("\t\t\t\t4. Menghapus data dari kamus\n");
            printf("\t\t\t\t5. Mencari data dari kamus\n");
            printf("\t\t\t\t6. Keluar\n");
            printf("\n\t\t\t==========================================================================\n");
            printf("\n\t\t\t\tMasukan pilihan: ");
            scanf("%i", &home);

            switch(home)
            {
                case 1 : Lihat(); break;
                case 2 : tambahData(); break;
                case 3 : editData(); break;
                case 4 : deletData(); break;
                case 5 : searching();break;
                case 6 : keluar(); break;
                default :
                    printf("\n\t\t\t\tPilihanmu salah!!!\n");break;
            }
            getch();
            system("cls");
        }while(home != 6);
    return 0;
}
