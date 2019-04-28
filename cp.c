#include "head.h"
#include <errno.h>
#include <fcntl.h>
void f_err(int erno) {
	switch(erno) {
        	case ENOENT : printf("해당 파일이 존재하지 않습니다.\n"); exit(0);
		case EACCES : printf("접근이 허용된 파일이 아닙니다.\n"); exit(0);
        	case EROFS : printf("읽기전용 파일입니다.\n"); exit(0);
        	default : printf("알수 없는 오류입니다.\n"); break;
    	}
}

void writefile(char *in_f, char *out_f) { //File copy
    	int in_o, out_o;
    	int read_o;

    	char buf[1024];

    	in_o = open(in_f, O_RDONLY);
    	printf("test\n");
	out_o = open(out_f, O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	printf("test2\n");
   	while((read_o = read(in_o,buf,sizeof(buf))) > 0)
        	write(out_o,buf,read_o);
}

void my_cp(char *argv[]){
	char bkname[64];
	char conin = 'h';
	
	writefile(argv[1],argv[2]);
    	return ;
}

