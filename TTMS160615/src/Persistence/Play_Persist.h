/*
* File name:  Play_Persist.h
* File ID:	  TTMS_SSF_Play_Perst_Head
* Author:     Huang Ru
* Version:    V1.0
* Date: 	  2015-04-25
*/

#ifndef PLAYPERSIST_H_
#define PLAYPERSIST_H_

	#include "../Service/Play.h"

	/*
	 * Function:    Play_Perst_Insert
	 * Function ID:	TTMS_SCU_Play_Perst_Insert
	 * Description: �ھ�Ŀ��Ϣ�ļ�ĩβд��һ����Ŀ��Ϣ
	 * Input:       �������ļ��ľ�Ŀ��Ϣ����
	 * Output:      ���ļ�ʧ�ܵ���Ϣ
	 * Return:      д���ļ��ļ�¼��
	 */
	int Play_Perst_Insert(const play_t *data);

	/*
	 * Function:    Play_Perst_Update
	 * Function ID:	TTMS_SCU_Play_Perst_Mod
	 * Description: ���վ�ĿID�Ÿ����ļ��еľ�Ŀ��Ϣ
	 * Input:       �����ļ��и��µľ�Ŀ��Ϣ����
	 * Output:      ���ļ�ʧ�ܵ���Ϣ
	 * Return:      ���µľ�Ŀ��Ϣ����0��ʾδ�ҵ���1��ʾ�ҵ�������
	 */
	int Play_Perst_Update(const play_t *data);

	/*
	 * Function:    Play_Perst_DeleteByID
	 * Function ID:	TTMS_SCU_Play_Perst_DelByID
	 * Description: ���վ�ĿID��ɾ����Ŀ����Ϣ
	 * Input:       ��ɾ���ľ�ĿID��
	 * Output:      ���ļ�ʧ�ܵ���Ϣ
	 * Return:      0��ʾɾ��ʧ�ܣ�1��ʾɾ���ɹ�
	 */
	int Play_Perst_DeleteByID(int ID);

	/*
	 * Function:    Play_Perst_SelectByID
	 * Function ID:	TTMS_SCU_Play_Perst_SelByID
	 * Description: ���վ�ĿID�Ų��Ҿ�Ŀ����Ϣ
	 * Input:       �����ҵľ�ĿID�ţ�������ҽ�����ڴ�ĵ�ַ
	 * Output:      ��
	 * Return:      0��ʾδ�ҵ���1��ʾ�ҵ���
	 */
	int Play_Perst_SelectByID(int ID, play_t *buf);

	/*
	 * Function:    Play_Perst_SelectByName
	 * Function ID:	TTMS_SCU_Play_Perst_SelByName
	 * Description: ���վ�Ŀ���Ʋ��Ҿ�Ŀ����Ϣ
	 * Input:       listΪ���ҵ��ľ�Ŀ��Ϣ�����ͷָ�룬condtΪģ����ѯ�Ĺؼ���
	 * Output:      ��ʾ��������ʱ������ռ�ʧ��
	 * Return:      ���ز��ҵ��ļ�¼��Ŀ
	 */
	int Play_Perst_SelectByName(play_list_t list, char condt[]);

	/*
	 * Function:    Play_Perst_SelectAll
	 * Function ID:	TTMS_SCU_Play_Perst_SelAll
	 * Description: �����о�Ŀ��Ϣ������һ������
	 * Input:       list��Ŀ��Ϣ�����ͷָ��
	 * Output:      ��ʾ��������ʱ������ռ�ʧ��
	 * Return:      ���ز��ҵ��ļ�¼��Ŀ
	 */
	int Play_Perst_SelectAll(play_list_t list);

#endif /* PLAYPERSIST_H_ */
