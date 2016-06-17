/*
 * Common_Persist.c
 *
 *  Created on: 2015��5��4��
 *      Author: Administrator
 */
#include "../Service/EntityKey.h"

#include "EntityKey_Persist.h"


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/io.h>

//�����?����ʵ���������ļ���ΪEntityKey.dat
static const char ENTITY_KEY_FILE[] = "EntityKey.dat";
/*���ݴ����ʵ����?entName��ʵ�����?count��Ϊ���?count����ʵ�����һ�������?count������ֵ���䣬
 * ʹ��ÿ����ʵ���ڸ������ڶ����Է��䵽 Ψһ�� ����������ֵΪ�������������С�?*/
long EntKey_Perst_GetNewKeys(char entName[], int count) {
	entity_key_t ent;
	FILE *fp;
	int found = 0;
	long newEntKey = 1;

	if (count < 1) {
		printf("Entity count must be bigger than 0!\n");
		return 0;
	}

	//�ж��ļ��Ƿ����?
	if (access(ENTITY_KEY_FILE, 0)) {
		//�½��ļ�
		fp = fopen(ENTITY_KEY_FILE, "wb+");

		if (NULL == fp) {
			return 0;
		}
	} else {
		//�Ը���ģʽ��
		fp = fopen(ENTITY_KEY_FILE, "rb+");
		if (NULL == fp) {
			return 0;
		}
	}

	while (!feof(fp)) {
		if (fread(&ent, sizeof(entity_key_t), 1, fp)) {
			if (0 == strcmp(ent.entyName, entName)) {	//�ҵ�������¼
				fseek(fp, -sizeof(entity_key_t), SEEK_CUR);
				newEntKey = ent.key + 1;
				ent.key += count;
				fwrite(&ent, sizeof(entity_key_t), 1, fp);
				found = 1;
				break;
			}
		}
	}

	//δ�ҵ�ʵ���������¼���¼�������¼���ļ�ĩβ��?
	if (!found) {
		strcpy(ent.entyName, entName);
		newEntKey = 1;
		ent.key = count;
		fwrite(&ent, sizeof(entity_key_t), 1, fp);
	}

	fclose(fp);

	return newEntKey;
}

