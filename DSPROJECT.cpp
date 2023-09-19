#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

FILE* file;
char username[20];
char password[20];
	
struct funds{
	int money;
	funds *prev,*next;
}*head = NULL,*tail = NULL;

funds* createdNode(int money){
	funds* newNode = (funds*)malloc(sizeof(funds));
	newNode->money = money;
	newNode->next  = newNode->prev = NULL;
	return newNode;
}

void insertmoney(int money){
	funds *newNode = createdNode(money);
	if(!head){
		head = tail = newNode;
		return;
	}else{
		head->prev = newNode;
		newNode->next =head;
		head = newNode;
	}
}
void print(){
	funds *current = head;
	printf("%s - %d",current->money);
	current = current->next;
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

void mainmenu(){
	int n;
	int money = 0;
	do{
	mainmenu:
	printf("1. Funds\n");
	printf("2. Transaction\n");
	printf("3. My Account\n");
	printf("4. Log Out\n");
	printf(">>");
	scanf("%d",&n);
	}while(n < 1 || n > 4);
	switch(n){
	case 1:{
		int a;
		do{
		tokens:
		printf("Blue Token: %d\n",money);
		printf("1. Deposit\n");
		printf("2. With Draw\n");
		printf("3. Back\n");
		printf(">>");
		scanf("%d",&a);
		}while(a < 1 || a > 3);
		switch(a){
			case 1:{
				int depo;
				printf("Enter Deposit Ammount[0 to cancel]: ");
				scanf("%d",&depo);
			    if (depo == 0) {
			        goto tokens;
			        break;
			    }
				money= money + depo;
				printf("Blue Token(s) Added to Transaction\n");
				goto tokens;
				break;
			}
			case 2:{
				int withdraw;
				printf("Enter Witdraw Ammount[0 to cancel]: ");
				scanf("%d",&withdraw);
				if (withdraw == 0) {
			        goto tokens;
			        break;
			    }
			    if(money < withdraw){
			    	printf("You Don't Have Enough Money\n");
				}else{
				money = money - withdraw;
				printf("Blue Token(s) Withdrawak Added to Transaction\n");
				}
				goto tokens;
				break; 
			}
			case 3:{
				goto mainmenu;
				break;
			}

		}
		break;
	}
	case 2:{
		int b;
		do{
		printf("1. View Transactions\n");
		printf("2. Send Money\n");
		printf("3. Back\n");
		scanf("%d",&b);
		}while(b < 1 || b > 3);
		
		switch(b){
			case 1:{
				int c;
				do{
				printf("1. Ogoing Transactions\n");
				printf("2. Finalized Transactions\n");
				printf("3. Back\n");
				scanf("%d",&c);
				}while(c < 1 || c > 3);
				switch(c){
					
				}
				break;
			}
			case 2:{
	
				break;
			}
			case 3:{
				goto mainmenu;
				break;
			}
		}
		break;
	}
	case 3:{
		int a;
		do{
		printf("1. Change My Password\n");
		printf("2. Back\n");
		printf(">>");
		scanf("%d",&a);
		}while(a < 1 || a > 2);
		switch(a){
			case 1:{
				char old_password[50];
				char new_password[50];
				char line[100];
    			int found = 0;
				while(true){
			    printf("Enter Your Old Password [0 to cancel] >> ");
			    getchar();
			    scanf("%[^\n]", old_password);
			    if (strcmp(old_password, "0") == 0) {
			        goto mainmenu;
			        break;
			    }
			    if (!isValidCredentials(username, old_password)) {
			        printf("Invalid current password.\n");
			        continue;
			    }
			    break;
				}
				while(true){
			    printf("Enter New Password[0 to cancel] >> ");getchar();
			    scanf("%[^\n]", new_password);
			    if (strcmp(new_password, "0") == 0) {
		         	goto mainmenu;
		         	break;
				}
			    int alpha = 0, num = 0;
			    if (strlen(new_password) < 10) {
			        printf("Password must be at least 10 characters long.\n");
			        continue; 
			    }
			    for (int i = 0; new_password[i] != '\0'; i++) {
			        if (isalpha(new_password[i])) {
			            alpha = 1;
			        }
			        else if (isdigit(new_password[i])) {
			            num = 1;
			        }
			    }
			    if (!alpha || !num) {
			        printf("Password must contain both letters and numbers.\n");
			        continue;
			    }
			    
			    file = fopen("database/account.txt", "r+");
			    fseek(file, 0, SEEK_SET);
			    while (fgets(line, sizeof(line), file)) {
			        char *token = strtok(line, "#");
			        if (strcmp(token, username) == 0) {
			            fseek(file, -strlen(line), SEEK_CUR);
			            fprintf(file,"%s#%s\n", username, new_password);
			            printf("\nPassword Updated!!.\n\n");
			            break;
			        }
			    }
			    fclose(file);
				break;
			}
			goto mainmenu;
			break;
			}
			case 2:{
				break;
			}

		}
			 goto mainmenu;
		break;
	}
	case 4:{
		return;
		}
	}
}


int main(){
	int n;
	do{
	firstmenu:
	printf("1. Log in\n");
	printf("2. Register\n");
	printf("3. Exit\n");
	printf(">>");
	scanf("%d",&n);
	}while(n < 1 || n > 3);
	switch(n){
		case 1:{
		while(true){
		printf("Enter Username [0 to Cancel] >> ");getchar();
		scanf("%[^\n]", username);
		if (strcmp(username, "0") == 0) {
           goto firstmenu;
		}
		if (isUsernameExist(username)) {
        	break;
    	}else{
    		printf("\n Username not found!");system("pause");
    		continue;
		}
		}
		while(true){
		printf("Enter Password [0 to Cancel] >> ");getchar();
		scanf("%[^\n]", password);
		if (strcmp(username, "0") == 0) {
          goto firstmenu;
		}
		if (isValidCredentials(username,password)) {
            printf("Login Successful!\n\n");
            break;
        } else {
            printf("Invalid Credentials. Please try again.\n");
            continue;
        }
	}   
		mainmenu();
		goto firstmenu;
		break;
	}

		case 2:{
		while(true){
		printf("Enter Username [0 to Cancel] >> ");getchar();
		scanf("%[^\n]", username);
		if (strcmp(username, "0") == 0) {
          break;
		}
		if (isUsernameExist(username)) {
        printf("\nUsername already taken ,please try again.\n\n");
        continue;
    	}else{
		int i;
		for (i = 0; username[i] != '\0'; i++) {
            if (isspace(username[i])) {
                printf("\nUsername Musn't Contain Spaces\n\n");
                break;
            }
        }
        if (username[i] != '\0') {
            continue; 
		}      
		else{
		printf("Enter Password [0 to Cancel] >> ");getchar();
		scanf("%[^\n]", password);
    	if (strcmp(password, "0") == 0) {
        break;
        }
		int alpha = 0, num = 0;
        if (strlen(password) < 10) {
            printf("Password must be at least 10 characters long.\n");
            continue; 
        }
        for (i = 0; password[i] != '\0'; i++) {
            if (isalpha(password[i])) {
                alpha = 1;
            }
            else if (isdigit(password[i])) {
                num = 1;
            }
        }
        if (!alpha || !num) {
            printf("Password must contain both letters and numbers.\n");
            continue; // Try again
        }else{
		file = fopen("database/account.txt", "a");
   	    fprintf(file,"%s#%s\n", username, password);
   	    printf("\nAccount Created!, ");system("pause");
        fclose(file);
        break;
    	}
    }
	}
}
        goto firstmenu;
        break;
		}
		case 3:{
			exit(0);
			break;
		}
	}
}
