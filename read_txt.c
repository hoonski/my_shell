#include "head.h"

void read_file(char* pathfile){
	FILE *fp;
	char *str;
	int buf_size = 1024;

	if(fp = fopen(pathfile, "r")){
		str = malloc(buf_size+5);

		while(fgets(str,buf_size,fp))
			printf("%s", str);
		
		printf("\n");
		fclose(fp);
		free(fp);
	}
}
void edit(char* pathname){
	char tmp[20]="vi ";
	int i = 0;
	while(pathname[i]!='\0'){
		tmp[i+3] = pathname[i];
		i++;
	}
	system(tmp);
}
