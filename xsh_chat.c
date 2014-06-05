#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <shell.h>
#include <kernel.h>
#include <tty.h>

#define LENGTH 160

command xsh_chat(ushort stdin, ushort stdout, ushort stderr, ushort nargs, char *args[])
{

/* This portion of code is used for the login of the account
   the user will be asked their user name they sre choosing to use 
   and the password need to gain entry into the system
 */

char admin_Account[] = "Admin Primar";
char user_Account[] = "User1 Second";
char msg1[LENGTH];
char msg2[LENGTH];  
char account_IN1[12];
char account_IN2[12]; 
char exit[] = "exit\n";
int i;
int CHAT = 1; 
int LOGIN = 1; 

while(LOGIN){

        if (stdin == TTY0)
        {
                fprintf(stdout, "Enter Administartion username along with password separated by space: \n");
                read(stdin, account_IN1, 12);

                if((strcmp(admin_Account, account_IN1)) != 0){
                        fprintf(stdout, "You are not the valid user of this device.\n");
                        return(-1);
                }
		else{
			fprintf(stdin, "You have successfully logged in!!!!\n"); 
			LOGIN = 0; 
		}
		break; 				
        }

        else if (stdin == TTY1)
        {
                fprintf(stdout, "Enter username along with password separated by space: \n");
                read(stdin, account_IN2, 12);

                if((strcmp(user_Account, account_IN2)) != 0){
                        fprintf(stdout, "You are not the valid user of this device.\n");
                        return(-1);
                }
		else{
			fprintf(stdin, "You have successfully logged in!!!!\n"); 
			LOGIN = 0; 
		}
		break; 
        }
}

while(CHAT){

        if (stdin == TTY0){
        	for (i=0; i < LENGTH; i++){
                    	 msg1[i] = '\0';
            	}
            	read(TTY0, msg1, LENGTH);
             	if (strcmp(exit, msg1) == 0) {
                      	CHAT = 0; 
             	}
		else{
			fprintf(TTY1, "%s> ", account_IN1);
			write(TTY1, msg1, LENGTH); 
		}
        }

        if (stdin == TTY1){
                for (i=0; i < LENGTH; i++){
                         msg1[i] = '\0';
                }
                read(TTY1, msg2, LENGTH);
                if (strcmp(exit, msg2) == 0) {
                        CHAT = 0;
                }
                else{
                        fprintf(TTY0, "%s> ", account_IN2);
                        write(TTY0, msg2, LENGTH);
                }
        }

}
return 0; 
}
