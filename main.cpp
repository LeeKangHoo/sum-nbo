#include <iostream>
#include <cstdio>
#include <arpa/inet.h>

#include "sum.h"


int main(int argc, char* argv[])
{
	//타입 선언
	int f1,f2;
	int cnt[2];
	FILE* ftmp1 = fopen(argv[1], "rb");
	FILE* ftmp2 = fopen(argv[2],"rb");
	//파일 크기 측정
	fseek(ftmp1,0,SEEK_END);
	cnt[0] = ftell(ftmp1);

	fseek(ftmp2,0,SEEK_END);
	cnt[1] = ftell(ftmp2);

	if(cnt[0] < 4 ||cnt[1] < 4)
	{
		printf("file is too small!");
		return 0;
	}
	//파일이 문제가 있거나 없을 시
	if (ftmp1 == NULL || ftmp2 == NULL)
	{
		printf("File error");
		return 0;
	}
	//파일 크기를 측정하느라 밀어놨던 포인터 다시 돌려놓기
	rewind(ftmp1);
	rewind(ftmp2);


	fread (&f1,sizeof(int),100,ftmp1);
	f1 = ntohl(f1);
	

	fread (&f2,sizeof(int),100,ftmp2);
	f2 = ntohl(f2);

	

	printf("%d,%d\n",f1,f2);
	//sum함수 호출
	printf("%d\n",sum(f1,f2));

	fclose(ftmp2);
	fclose(ftmp1);
}
