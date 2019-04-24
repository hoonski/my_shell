#include "head.h"

void ls() {
	char* cwd = (char*)malloc(sizeof(char)* 1024);
	DIR* dir = NULL;
	struct dirent* entry = NULL;

	char hide_file[3] = ".";

	getcwd(cwd,1024);
	
	if((dir = opendir(cwd)) == NULL) exit(1);

	while((entry = readdir(dir)) != NULL) {
		if(entry->d_name[0] != '.')
			printf("%s\n",entry->d_name);
	}

	free(cwd);
	closedir(dir);
}
