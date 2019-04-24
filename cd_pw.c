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
		else{
			return 0;
		}
	}
	else
		printf( "USAGE: cd [dir]\n" );
	return 0;
}
	
