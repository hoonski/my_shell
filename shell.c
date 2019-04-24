#include "cd_pw.c"
#include "ls.c"

#define MAX_LEN 100 /* The maximum length command */

int my_mkdir(int argc, char* argv[]);

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
		if(!strcmp(args[0],"cd")) cmd_cd(i,args);
		else if(!strcmp(args[0],"mkdir")) my_mkdir(i,args);
		else if(!strcmp(args[0],"pwd")) my_pwd();
		else if(!strcmp(args[0],"ls")) ls();
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
