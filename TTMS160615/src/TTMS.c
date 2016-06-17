/*
 ============================================================================
 Name        : TTMS.c
 Author      : shu xinfeng
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
//#include <io.h>
#include "./View/Main_Menu.h"
#include "./View/Account_UI.h"


//����ȫ�ֱ��������ڴ洢��½�û���Ϣ
account_t gl_CurUser={0, USR_ANOMY, "Anonymous",""};

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

/*
	if(!SysLogin()) {
		printf("\n�Բ�������Ȩ��¼��ϵͳ�밴������˳�......\n");
		getchar();
		exit(0);
	}*/


	Main_Menu();
	return EXIT_SUCCESS;
}
