#include "head.h" 
void my_remove(char* path)
{
	struct stat buf;
	lstat(path, &buf);
	if(S_ISREG(buf.st_mode)){
		remove(path);
	}
	else if(S_ISDIR(buf.st_mode)){
		rmdir(path);
	}
}

