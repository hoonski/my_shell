#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_LEN 100 /* The maximum length command */

int cmd_cd(int argc, char* argv[]);
int my_mkdir(int argc, char* argv[]);
void cmd_cd_back(char* path);
char my_pwd();

int main(void) {
	char *args[MAX_LEN / 2 + 1]; /* command line arguments */
	char *path[MAX_LEN];
	char *path_cur[MAX_LEN];
	int should_run = 1;          /* flag to determine when to exit program */
	int background = 0;

	char *input;
	int status;
  
	while(should_run){
		printf("hoons$ ");
		fflush(stdout);
		
		input = (char *)malloc(MAX_LEN*sizeof(char));
		fgets(input, MAX_LEN, stdin);
		
		int i = 0;
		args[i] = strtok(input, " ");
		while (args[i] != NULL) {
			i++;
			args[i] = strtok(NULL, " ");
		}
		//Removing array '\n' at last index
		for(int j=0; args[i-1][j] != '\0'; j++){
			if(args[i-1][j] == '\n'){
				args[i-1][j] =0;
                		break;
        		}
    		}
		if(!strcmp(args[0],"cd")) {
			//Go to subdirectory
			int tmp;
			tmp = cmd_cd(i,args);
			if(tmp==1) {
				cmd_cd_back(my_pwd());
			}
		}		
		else if(!strcmp(args[0],"mkdir")) my_mkdir(i,args);
		else if(!strcmp(args[0],"pwd")) my_pwd();
	}
}

void go_home(){
	chdir(getenv("HOME"));
	chdir("Desktop");
	chdir("shell");
}

char my_pwd(){
	char buf[255];
	getcwd(buf,255);
	printf("%s\n",buf);
	return buf;
}

int cmd_cd( int argc, char* argv[]){ //cd : change directory
	if( argc == 1 )
		go_home();
	else if( argc == 2 ){
		if( chdir( argv[1] )==-1)
			printf( "No directory\n" );
		else if(strcmp(argv[1],"..")==0){
			return 1;
		}
		else{
			return 0;
		}
	}
	else
		printf( "USAGE: cd [dir]\n" );
	return 0;
}
/*
char* strtok_cur_path(char* path){
	printf("bcd");
	char* tmp[MAX_LEN/2];
	int i = 0;
	tmp[i] = strtok(path,"/");
	printf("abc");
	while(tmp[i] != NULL){
		i++;
	tmp[i] = strtok(NULL, "/");
	}
	return tmp;
}
*/
void cmd_cd_back(char* path){
	char* tmp[MAX_LEN/2];
        int i = 0,tmpint=0;
        tmp[i] = strtok(path,"/");
        while(tmp[i] != NULL){
                i++;
                tmp[i] = strtok(NULL, "/");
	//	printf("%s+",tmp[i]);
        }
	go_home();
	if(i==1){
		return ;
	}
	while(tmpint < i-1){
		chdir(tmp[tmpint]);
		tmpint++;
	}
}

int my_mkdir(int argc, char* argv[]){
	int i;
	mode_t old;
        old = umask(0);
	if(argc<2){
		fprintf(stderr, "%s : no arguments\n", argv[0]);
		return 0;
	}
	for(i=1; i<argc; i++){
		mkdir(argv[i], 0777);
	}
	umask(old);
	return 0;
}
