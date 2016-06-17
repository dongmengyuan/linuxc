/*
* File name:  Schedule_Persist.h
* File ID:	  TTMS_SSF_Schedule_Perst_Head
* Author:     Huang Ru
* Version:    V1.0
* Date: 	  2015-04-25
*/

#ifndef SCHEDPERSIST_H_
#define SCHEDPERSIST_H_

	#include "../Service/Schedule.h"



	/*
	 * Function:    Schedule_Perst_Insert
	 * Function ID:	TTMS_SCU_Schedule_Perst_Insert
	 * Description: ���ݳ��ƻ���Ϣ�ļ�ĩβд��һ���ݳ��ƻ���Ϣ
	 * Input:       �������ļ����ݳ��ƻ���Ϣ����
	 * Output:      ���ļ�ʧ�ܵ���Ϣ
	 * Return:      д���ļ��ļ�¼��
	 */
	int Schedule_Perst_Insert(const schedule_t *data);

	/*
	 * Function:    Schedule_Perst_Update
	 * Function ID:	TTMS_SCU_Schedule_Perst_Mod
	 * Description: �����ݳ��ƻ�ID�Ÿ����ļ��е��ݳ��ƻ���Ϣ
	 * Input:       �����ļ��и��µ��ݳ��ƻ���Ϣ����
	 * Output:      ���ļ�ʧ�ܵ���Ϣ
	 * Return:      ���µ��ݳ��ƻ���Ϣ����0��ʾδ�ҵ���1��ʾ�ҵ�������
	 */
	int Schedule_Perst_Update(const schedule_t *data);

	/*
	 * Function:    Schedule_Perst_DeleteByID
	 * Function ID:	TTMS_SCU_Schedule_Perst_DelByID
	 * Description: �����ݳ��ƻ�ID��ɾ���ݳ��ƻ�����Ϣ
	 * Input:       ��ɾ�����ݳ��ƻ�ID��
	 * Output:      ���ļ�ʧ�ܵ���Ϣ
	 * Return:      0��ʾɾ��ʧ�ܣ�1��ʾɾ���ɹ�
	 */
	int Schedule_Perst_DeleteByID(int ID);

	/*
	 * Function:    Schedule_Perst_SelectByID
	 * Function ID:	TTMS_SCU_Schedule_Perst_SelByID
	 * Description: �����ݳ��ƻ�ID��ɾ���ݳ��ƻ�����Ϣ
	 * Input:       �����ҵ��ݳ��ƻ�ID�ţ�������ҽ�����ڴ�ĵ�ַ
	 * Output:      ��
	 * Return:      0��ʾδ�ҵ���1��ʾ�ҵ���
	 */
	int Schedule_Perst_SelectByID(int ID, schedule_t *buf);

	/*
	 * Function:    Schedule_Perst_SelectAll
	 * Function ID:	TTMS_SCU_Schedule_Perst_SelAll
	 * Description: �������ݳ��ƻ���Ϣ������һ������
	 * Input:       listΪ�ݳ��ƻ���Ϣ�����ͷָ��
	 * Output:      ��ʾ��������ʱ������ռ�ʧ��
	 * Return:      ���ز��ҵ��ļ�¼��Ŀ
	 */
	int Schedule_Perst_SelectAll(schedule_list_t list);

	/*
	 * Function:    Schedule_Perst_SelectByPlay
	 * Function ID:	TTMS_SCU_Schedule_Perst_SelByPlay
	 * Description: ��ͬ���Ŀ���ݳ��ƻ���Ϣ��������������һ������
	 * Input:       listΪ�����������ݳ��ƻ���Ϣ�����ͷָ�룬��Ŀ��ID��
	 * Output:      ��ʾ��������ʱ������ռ�ʧ��
	 * Return:      ���ز��ҵ��ļ�¼��Ŀ
	 */
	int Schedule_Perst_SelectByPlay(schedule_list_t list, int play_id);

#endif // SCHEDPERSIST_H_
