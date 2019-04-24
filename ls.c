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
/*
void ls_mod(int mode){
	if(mode == 1){
		file_mode = file_info.st_mode;
		rwx(file_mode);
		printf("%d ", file_info.st_nlink);

		my_passwd = getpwuid(file_info.st_uid);
		my_group = getgrgid(file_info.st_gid);
		printf("%s ", my_passwd->pw_name);
		printf("%s ", my_group->gr_name);
		printf("%d ", file_info.st_size);
	}
	
}
*/
