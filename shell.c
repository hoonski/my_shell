#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_LEN 100 /* The maximum length command */

int cmd_cd(int argc, char* argv[]);
int my_mkdir(int argc, char* argv[]);

int main(void) {
	char *args[MAX_LEN / 2 + 1]; /* command line arguments */
	char *path[MAX_LEN];
	char *path_cur[MAX_LEN];
	char *tmp[MAX_LEN / 3];
	int path_index = 0;
	int should_run = 1;          /* flag to determine when to exit program */
	int background = 0;

	char *input;
	int status;
  
	while(should_run){
		if(path!=NULL) printf("hoons%s> ",path);
		else printf("hoons> ");
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
			if(cmd_cd(i,args)==1) {
				strcat(path, "/");
				strcat(path, args[1]);
			//	strcmp(path_cur[path_index],args[1]);
			//	path_index++;
		/*	}else if(cmd_cd(i,args)==2) {
				cmd_cd(1,args);
				for(int k=0;k<path_index;k++){
					strcmp(tmp[1],path_cur[path_index]);
					cmd_cd(i,tmp);
				}*/
			}

		}
		else if(!strcmp(args[0],"mkdir")) my_mkdir(i,args);

	}
}

int cmd_cd( int argc, char* argv[]){ //cd : change directory
	if( argc == 1 )
		chdir( getenv( "HOME" ) );
	else if( argc == 2 ){
		if( chdir( argv[1] )==-1)
			printf( "No directory\n" );
		else if(strcmp(argv[1],"..")==0){
			printf("test\n");
			return 2;
		}
		else
			return 1;
	}
	else
		printf( "USAGE: cd [dir]\n" );
	return 0;
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
