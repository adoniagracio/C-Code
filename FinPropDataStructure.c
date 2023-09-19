#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
 
void judul(){
printf(" _______  _______  _______                                                                                  \n");
printf("|  _    ||       ||       |                                                                                 \n");
printf("| |_|   ||  _____||_     _|                                                                                 \n");
printf("|       || |_____   |   |                                                                                   \n");
printf("|  _   | |_____  |  |   |                                                                                   \n");
printf("| |_|   | _____| |  |   |                                                                                   \n");
printf("|_______||_______|  |___|                                                                                   \n");
printf(" _______  ___   __    _  _______  ___        _______  ______    _______      ___  _______  _______  _______ \n");
printf("|       ||   | |  |  | ||   _   ||   |      |       ||    _ |  |       |    |   ||       ||       ||       |\n");
printf("|    ___||   | |   |_| ||  |_|  ||   |      |    _  ||   | ||  |   _   |    |   ||    ___||       ||_     _|\n");
printf("|   |___ |   | |       ||       ||   |      |   |_| ||   |_||_ |  | |  |    |   ||   |___ |       |  |   |  \n");
printf("|    ___||   | |  _    ||       ||   |___   |    ___||    __  ||  |_|  | ___|   ||    ___||      _|  |   |  \n");
printf("|   |    |   | | | |   ||   _   ||       |  |   |    |   |  | ||       ||       ||   |___ |     |_   |   |  \n");
printf("|___|    |___| |_|  |__||__| |__||_______|  |___|    |___|  |_||_______||_______||_______||_______|  |___|  \n");
}

struct Node{
    int data;
    char string[111];
    struct Node *left, *right;
};


struct Node* newNode(int data, char string[111]){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    strcpy(node->string, string);
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct Node* addNode(struct Node *root, int data, char string[111]){
    if(root == NULL){
        root = newNode(data, string);
    }else{
        if(data < root->data){
            root->left = addNode(root->left, data, string);
        }else{
            root->right = addNode(root->right, data, string);
        }
    }
    return root;
}


void inOrder(struct Node *node){
    if(node != NULL){
        inOrder(node->left);
        printf("| %-33s       | %-14d	     |\n", node->string, node->data);
        inOrder(node->right);
    }
}


void postOrder(struct Node *node){
    if(node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        printf("| %-33s       | %-14d	     |\n", node->string, node->data);
    } 
}


void preOrder(struct Node *node){
    if(node != NULL){
        printf("| %-33s       | %-14d	     |\n", node->string, node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

void gotoxy(int x,int y){
	COORD coord = {0,0};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int bg, fg, panjang;
int simbol[20] = {2,3,4,5,6,14,16,22,35,36,62,64,158,174,175,176,177,178,219};

void delay(){
	int delay;
	delay = 1;
	while(delay<30000000){
	delay++;
}
}


void loading(int bg, int fg, int panjang, int simbol[20])
{
 int k,l,i=0;
   for (k=0; k<=panjang; k++)
   {
      gotoxy(28,26);
      
	  printf("\n\tPlease Wait..\n\t");
      for (l=0; l<k; l++)
       printf("%c", simbol[fg]);
      for (l=0; l<panjang-1; l++)
       printf("%c", simbol[bg]);
      delay();
   }
   system("cls");
}




struct Node* delNode(struct Node *root, int data){
    if (root == NULL)
    {    	
	    gotoxy(60,13);
        printf("Size tidak ada");
        return root;
    }
    if (data < root->data)
        root->left = delNode(root->left, data);
    else if (data > root->data)
        root->right = delNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            gotoxy(60,13);
            printf("Data berhasil di Hapus");
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            gotoxy(60,13);
            printf("Data berhasil di Hapus");
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delNode(root->right, temp->data);
    }
    return root;
}


void printTree(struct Node *root, int space)
{
    if(root == NULL)
        return;

    space += 5;
    
    printTree(root->right, space);
    printf("\n");
    for(int i = 5; i < space; i++)
        printf("-");
    printf("### %d ###", root->data);

    printTree(root->left, space);
}
int checkSize(struct Node *root, int data){ 
    if(root == NULL){ 
        return 0;
    }else{
        if(data == root->data){ 
            return 1;
        }else{
            if(data < root->data){ 
                return checkSize(root->left, data);
            }else{
                return checkSize(root->right, data); 
            }
        }
    }
}

void loginprint(){                            
printf("\t\t\t _            ___________   ___________   ___________  __        _  \n");
printf("\t\t\t¦¦¦           ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦     ¦¦¦\n");
printf("\t\t\t¦¦¦           ¦¦¦¯¯¯¯¯¯¯¦¦ ¦¦¦¦¯¯¯¯¯¯¯¯¯  ¯¯¯¯¦¦¦¯¯¯¯  ¦¦¦¦¦     ¦¦¦\n");
printf("\t\t\t¦¦¦           ¦¦¦       ¦¦ ¦¦¦¦               ¦¦¦      ¦¦¦¦¦¦    ¦¦¦\n");
printf("\t\t\t¦¦¦           ¦¦¦       ¦¦ ¦¦¦¦ ________      ¦¦¦      ¦¦¦ ¦¦¦   ¦¦¦\n");
printf("\t\t\t¦¦¦           ¦¦¦       ¦¦ ¦¦¦¦¦¦¦¦¦¦¦¦¦¦     ¦¦¦      ¦¦¦  ¦¦¦  ¦¦¦\n");
printf("\t\t\t¦¦¦           ¦¦¦       ¦¦ ¦¦¦¦ ¯¯¯¯¯¯¦¦¦     ¦¦¦      ¦¦¦   ¦¦¦ ¦¦¦\n");
printf("\t\t\t¦¦¦           ¦¦¦       ¦¦ ¦¦¦¦       ¦¦¦     ¦¦¦      ¦¦¦    ¦¦¦¦¦¦\n");
printf("\t\t\t¦¦¦_________  ¦¦¦_______¦¦ ¦¦¦¦_______¦¦¦ ____¦¦¦____  ¦¦¦     ¦¦¦¦¦\n");
printf("\t\t\t¦¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦¦¦¦¦¦ ¦¦¦¦     ¦¦¦¦\n");
printf("\t\t\t ¯¯¯¯¯¯¯¯¯¯¯  ¯¯¯¯¯¯¯¯¯¯¯  ¯¯¯¯¯¯¯¯¯¯¯  ¯ ¯¯¯¯¯¯¯¯¯¯   ¯         ¯¯ \n");   
                                                                                                 
}
void login(){
    	char username[10], password[8];
    	int ulang = 0;
	    for(int j=0; j<3; j++){
        loginprint();
        printf("\nUsername: ");
        scanf ( "%s", &username);
        printf("\n");
        printf("Password: ");
        fflush(stdin);
            char ch;
        int i=0;
        int x=10;
        int y=14;
        while((ch = (char) _getch()) != '\r'){
    	if (ch == 8){
    		password[i] = '\0';
    		gotoxy(x-1,y);	
    		printf(" ");
    		x--;
    		i--;	
    		gotoxy(x,y);
		}
	
		else{
			password[i]=ch;
			gotoxy(x,y);
			printf("*");
			x++;
			i++;
		}
	}
        if ((strcmp(username,"admin")==0)&&(strcmp(password,"admin")==0)) {
        	printf("\n\n\n\n\n\n\t\t\t\t\t   LOGIN SUKSES!!!!");
        	Sleep(1400);
        	break;
        } else {
        	ulang++;
        	if(ulang != 3){
            printf("\n\nPassword atau username yang anda masukan salah.");
            Sleep(500);
             system ("pause>0");
        }
            else if(ulang == 3){
            	printf("\n\nAnda Terlalu Banyak Mencoba,Silahkan Buka Progam Ini Kembali.");
            	Sleep(1400);
            	exit(0);
			}
        }
        system("cls");
    }
}

void byebyeprint(){                                                                                                                                         
gotoxy(0,25);                                                                                                                                       
printf("BBBBBBBBBBBBBBBBB   YYYYYYY       YYYYYYYEEEEEEEEEEEEEEEEEEEEEE     BBBBBBBBBBBBBBBBB   YYYYYYY       YYYYYYYEEEEEEEEEEEEEEEEEEEEEE !!!  !!! \n");
printf("B::::::::::::::::B  Y:::::Y       Y:::::YE::::::::::::::::::::E     B::::::::::::::::B  Y:::::Y       Y:::::YE::::::::::::::::::::E!!:!!!!:!!\n");
printf("B::::::BBBBBB:::::B Y:::::Y       Y:::::YE::::::::::::::::::::E     B::::::BBBBBB:::::B Y:::::Y       Y:::::YE::::::::::::::::::::E!:::!!:::!\n");
printf("BB:::::B     B:::::BY::::::Y     Y::::::YEE::::::EEEEEEEEE::::E     BB:::::B     B:::::BY::::::Y     Y::::::YEE::::::EEEEEEEEE::::E!:::!!:::!\n");
printf("  B::::B     B:::::BYYY:::::Y   Y:::::YYY  E:::::E       EEEEEE       B::::B     B:::::BYYY:::::Y   Y:::::YYY  E:::::E       EEEEEE!:::!!:::!\n");
printf("  B::::B     B:::::B   Y:::::Y Y:::::Y     E:::::E                    B::::B     B:::::B   Y:::::Y Y:::::Y     E:::::E             !:::!!:::!\n");
printf("  B::::BBBBBB:::::B     Y:::::Y:::::Y      E::::::EEEEEEEEEE          B::::BBBBBB:::::B     Y:::::Y:::::Y      E::::::EEEEEEEEEE   !:::!!:::!\n");
printf("  B:::::::::::::BB       Y:::::::::Y       E:::::::::::::::E          B:::::::::::::BB       Y:::::::::Y       E:::::::::::::::E   !:::!!:::!\n");
printf("  B::::BBBBBB:::::B       Y:::::::Y        E:::::::::::::::E          B::::BBBBBB:::::B       Y:::::::Y        E:::::::::::::::E   !:::!!:::!\n");
printf("  B::::B     B:::::B       Y:::::Y         E::::::EEEEEEEEEE          B::::B     B:::::B       Y:::::Y         E::::::EEEEEEEEEE   !:::!!:::!\n");
printf("  B::::B     B:::::B       Y:::::Y         E:::::E                    B::::B     B:::::B       Y:::::Y         E:::::E             !!:!!!!:!!\n");
printf("  B::::B     B:::::B       Y:::::Y         E:::::E       EEEEEE       B::::B     B:::::B       Y:::::Y         E:::::E       EEEEEE !!!  !!! \n");
printf("BB:::::BBBBBB::::::B       Y:::::Y       EE::::::EEEEEEEE:::::E     BB:::::BBBBBB::::::B       Y:::::Y       EE::::::EEEEEEEE:::::E          \n");
printf("B:::::::::::::::::B     YYYY:::::YYYY    E::::::::::::::::::::E     B:::::::::::::::::B     YYYY:::::YYYY    E::::::::::::::::::::E !!!  !!! \n");
printf("B::::::::::::::::B      Y:::::::::::Y    E::::::::::::::::::::E     B::::::::::::::::B      Y:::::::::::Y    E::::::::::::::::::::E!!:!!!!:!!\n");
printf("BBBBBBBBBBBBBBBBB       YYYYYYYYYYYYY    EEEEEEEEEEEEEEEEEEEEEE     BBBBBBBBBBBBBBBBB       YYYYYYYYYYYYY    EEEEEEEEEEEEEEEEEEEEEE !!!  !!! \n");
                                                                                                                                             
}
/* main menu */

int main(){
	system ("color A"); 
    struct Node *root = NULL;
    int data;
    char string[111];
    int pilihan;
    int pilihantampil;
    judul();
    loading(20 - 1, 19 - 1, 102, simbol);
    login();
    system("cls");
    do{
    	system("cls");
	    int i;
	    
    	for(i=1;i<=100;i++){
    		gotoxy(i,1);
    		printf("#");
    		gotoxy(i,4);
    		printf("#");
    		gotoxy(i,20);
    		printf("#");
    		gotoxy(i,24);
    		printf("#");
		}
    	for(i=1;i<=24;i++){
    		gotoxy(1,i);
    		printf("#");
    		gotoxy(100,i);
    		printf("#");
		}
		    for(i=4;i<=20;i++){
    		gotoxy(40,i);
    		printf("#");
    	}
    	gotoxy(41,2);
        printf("PROGRAM PEMASUKAN SEPATU");
        gotoxy(41,21);
        printf("Adonia Gracio - 2502016935");
        gotoxy(41,22);
        printf("Hana Dyah Ayu Pertiwi - 2501974933");
        gotoxy(41,23);
        printf("Marwah Inas Rabbani - 2502001914");
        gotoxy(3,6);
        printf("1. Tambah Data Sepatu\n");
        gotoxy(3,7);
        printf("2. Tampilkan Data Sepatu\n");
        gotoxy(3,8);
        printf("3. Delete Data\n");
        gotoxy(3,9);
        printf("4. Tampilkan Kode \n");
        gotoxy(3,10);
        printf("5. Exit\n");
        gotoxy(3,13);
        printf("Pilihan Anda : ");
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:
                tambah:
                gotoxy(44,7);
                printf("Ukuran Sepatu : ");
                scanf("%d", &data);
                if(checkSize(root, data) == 1){
                    printf("Ukuran Sepatu Tersedia\n");
                    goto tambah;
                }
                gotoxy(44,8);
                printf("Merek Sepatu  : ");
                scanf("%s", string);
                root = addNode(root, data, string);
                gotoxy(60,13);
                printf("Data berhasil di Tambahkan");getch();
                break;
            case 2:
                gotoxy(44,7);
                printf("1. InOrder\n");
                gotoxy(44,8);
                printf("2. PreOrder\n");
                gotoxy(44,9);
                printf("3. PostOrder\n");
                gotoxy(44,11);
                printf("Pilihan : ");
                scanf("%d", &pilihantampil);getchar();
                switch(pilihantampil){
                    case 1:
                    	system("cls");
                         printf("+-+-+-+-+-+-+-+\n");
                         printf("|I|n|O|r|d|e|r|\n");
                         printf("+-+-+-+-+-+-+-+\n");
                        printf("----------------------------------------------------------------------\n");
				        printf("|              Merek Sepatu                |       Ukuran Sepatu     |\n");
			            printf("----------------------------------------------------------------------\n");
                        printf("\n");
                        inOrder(root);
                        system ("pause>0");
                        break;
                    case 2:
                        system("cls");
                         printf("+-+-+-+-+-+-+-+-+\n");
                         printf("|P|r|e|O|r|d|e|r|\n");
                         printf("+-+-+-+-+-+-+-+-+\n");
                        printf("----------------------------------------------------------------------\n");
				        printf("|              Merek Sepatu                |       Ukuran Sepatu     |\n");
			            printf("----------------------------------------------------------------------\n");
                        printf("\n");
                        preOrder(root);
                        system ("pause>0");
                        break;
                    case 3:
                    	system("cls");
                         printf("+-+-+-+-+-+-+-+-+-+\n");
                         printf("|P|o|s|t|O|r|d|e|r|\n");
                         printf("+-+-+-+-+-+-+-+-+-+\n");
                        printf("----------------------------------------------------------------------\n");
				        printf("|              Merek Sepatu                |       Ukuran Sepatu     |\n");
			            printf("----------------------------------------------------------------------\n");
                        printf("\n");
                        postOrder(root);
                        system ("pause>0");
                        break;
                    default:
                    	gotoxy(60,13);
                        printf("Pilihan Tidak Tersedia");
                        system ("pause>0");
                        system("cls");
                        break;
                }
                break;
            case 3:
            	gotoxy(44,7);
                printf("Ukuran Sepatu  : ");
                scanf("%d", &data);
                root = delNode(root, data);
                system ("pause>0");
                break;
            case 4:
                system("cls");
                printTree(root, 0);
				system ("pause>0");
                break;         
            case 5:
            	system("cls");
            	byebyeprint();
                break;
            default:
                printf("Pilihan Tidak Tersedia\n");
        }
    }while(pilihan != 5);
    return 0;
}
