#include "head.h"
char *getperm(char *perm_c, const mode_t mode);

void ls(char *args[]) {
	char* cwd = (char*)malloc(sizeof(char)* 1024);
	char perm_c[10] = {0};
	DIR* dir = NULL;
	struct dirent* entry = NULL;
	struct stat buf;
	
	char hide_file[3] = ".";

	getcwd(cwd,1024);

        if((dir = opendir(cwd)) == NULL) exit(1);

	if(args[1]==NULL){
		while((entry = readdir(dir)) != NULL) {
                        if(entry->d_name[0] == '.') continue;
			printf("%s\n",entry->d_name);
                }
	}
	if(strcmp(args[1],"-mod")==0) {
		while((entry = readdir(dir)) != NULL) {
			if(entry->d_name[0] != '.'){
				lstat(entry->d_name,&buf);
	                	if(S_ISREG(buf.st_mode))
        	                	printf("FILE\t");
                		else if(S_ISDIR(buf.st_mode))
                        		printf("DIR \t");
				printf("%s\n",entry->d_name);
			}
		}
	}
	else if(strcmp(args[1],"-aut")==0) {
		while((entry = readdir(dir)) != NULL) {
                        if(entry->d_name[0] == '.') continue;
                        lstat(entry->d_name,&buf);
                        printf("%s\t%s\n", getperm(perm_c, buf.st_mode),entry->d_name);
                }
	}
	else if(strcmp(args[1],"-all")==0) {
		while((entry = readdir(dir)) != NULL) {
                        if(entry->d_name[0] == '.') continue;
                        lstat(entry->d_name,&buf);
			printf("%s\t", getperm(perm_c, buf.st_mode));
			if(S_ISREG(buf.st_mode)) printf("FILE\t");
			else if(S_ISDIR(buf.st_mode)) printf("DIR \t");
			printf("%s\n", entry->d_name);
		}
	}
				
	free(cwd);
	closedir(dir);
}

char * getperm(char *perm_c, const mode_t mode)
{
	char *ref = "xwr";
	memset(perm_c,'-',10);

	if((mode & S_IFMT) == S_IFDIR)
		perm_c[0] = 'd';

	for(int i=0; i<9; i++){
		if(mode & (1<<i))
			perm_c[10-i-1] = ref[i%3];
	}

	return perm_c;
}
