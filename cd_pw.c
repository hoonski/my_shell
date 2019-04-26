#include "head.h"

// Home is shell directory
void go_home(){
	chdir(getenv("HOME"));
	chdir("Desktop");
	chdir("shell");
}

void my_pwd(){
	char buf[255];
	getcwd(buf,255);
	printf("%s\n",buf);
}

int cmd_cd( int argc, char* argv[]){ //cd : change directory
	if( argc == 1 )
		go_home();
	else if( argc == 2 ){
		if( chdir( argv[1] )==-1)
			printf( "No directory\n" );
	}
	else if(argc>2){
		int count = 1;
		while(count < argc){
			if(chdir(argv[count])==-1){
				printf("%s in No directory\n",argv[count]);
				return 0;
			}
			count++;
		}
	}
	else
		printf( "USAGE: cd [dir]\n" );
	return 0;
}

void location_cur(){
	char* path[MAX_LEN];
	char input[MAX_LEN];
	int path_len, i=0;
	getcwd(input,255);

	path[i] = strtok(input, "/");
	while (path[i] != NULL) {
		i++;
		path[i] = strtok(NULL, "/");
	}
	
	path_len = i-1;
	if(path_len == 1){
		printf("%s$ ",path[path_len]);
		return ;
	}
	printf("%s/%s$ ",path[path_len-1],path[path_len]);

}
	
