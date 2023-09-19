#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

FILE* file;
char username[20];
char password[20];

int isValidCredentials(char *username, char *password) {
    char buffer[255];
    char *token;
    file = fopen("database/account.txt", "r");
    if (file == NULL) {
        return 0;
    }
    while (fgets(buffer, 255, file)) {
        token = strtok(buffer, "#");
        if (strcmp(token, username) == 0) {
            token = strtok(NULL, "\n");
            if (strcmp(token, password) == 0) {
                    fclose(file);
                    return 1;
            }
        }
    }
    fclose(file);
    return 0;
}

int isPasswordExist(char *password){
    char buffer[255];
    char *token;
    file = fopen("database/account.txt", "r");
    while (fgets(buffer, 255, file)) {
        token = strtok(buffer, "#");
        if (strcmp(token, username) == 0) {
            token = strtok(NULL, "\n");
            if (strcmp(token, password) == 0) {
                fclose(file);
                return 1;
            }
        }
    }
    fclose(file);
    return 0;
} 
int isUsernameExist(char *username) {
    char buffer[100];
    char *token;
    file = fopen("database/account.txt", "r");
    if (file == NULL) {
        return 0;
    }
    while (fgets(buffer, 100, file) != NULL) {
        token = strtok(buffer, "#");
        if (strcmp(token, username) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}


void miner(){
		printf("Mining\n");
		printf("Press Enter to Start Mining");
	    while (getchar() != '\n'); 

}



int main(){
	int i;
	do{
	    mainmenu:
	    printf("Blue Miner\n\n");
		printf("1. Log in\n");
		printf("2. Exit\n");
		printf(">>");
		scanf("%d",&i);
	}while(i < 1 || i > 2);
	switch(i){
		case 1:{
		printf("Enter Username >> ");getchar();
		scanf("%[^\n]", username);
		printf("Enter Password >> ");getchar();
		scanf("%[^\n]", password);
		if(isValidCredentials(username,password)) {
            printf("Login Successful!\n\n");
 			break;
        } 
    	if (!isUsernameExist(username)) {
        	printf("Username Not Found\n");
        	system("pause");
        		goto mainmenu;
        }
         if(!isPasswordExist(password)){
            printf("Inccorect Password\n");
        	system("pause");
        		goto mainmenu;
		}
			miner();
			break;
		}
		case 2:{
			goto mainmenu;
			break;
		}
	}
}
