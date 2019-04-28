#include "head.h"

void help(char *args[]){
	if(args[1] == NULL) read_file("./help/help.txt");
	else if(!strcmp(args[1],"-cd")) read_file("./help/cd_help.txt");
	else if(!strcmp(args[1],"-mkdir")) read_file("./help/mkdir_help.txt");
	else if(!strcmp(args[1],"-pwd")) read_file("./help/pwd_help.txt");
	else if(!strcmp(args[1],"-txt")) read_file("./help/read_help.txt");
	else if(!strcmp(args[1],"-ls")) read_file("./help/ls_help.txt");
	else if(!strcmp(args[1],"-edit")) read_file("./help/edit_help.txt");
	else if(!strcmp(args[1],"-rm")) read_file("./help/remove_help.txt");
	else if(!strcmp(args[1],"-cp")) read_file("./help/cp_help.txt");
}

