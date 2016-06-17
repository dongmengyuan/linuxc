/*
* File name:  Schedule.h
* File ID:	  TTMS_SSF_Schedule_Srv_Head
* Author:     Huang Ru
* Version:    V1.0
* Date: 	  2015-04-25
*/


#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "../Common/common.h"

typedef struct {//�ݳ��ƻ����Ͷ���
	int id;            //�ݳ��ƻ�ID��
	int play_id;       //�ݳ��ľ�ĿID��
	int studio_id;     //�ݳ��ķ�ӳ��ID��
	user_date_t date;  //�ݳ�����
	user_time_t time;  //�ݳ�ʱ��
	int seat_count;    //��λ����
}schedule_t;

//�����ݳ��ƻ���Ϣ��˫������ṹ
typedef struct schedule_node {
	schedule_t data;
	struct schedule_node *next, *prev;
} schedule_node_t, *schedule_list_t;

/*
 * Function:    Schedule_Srv_Add
 * Function ID:	TTMS_SCU_Schedule_Srv_Add
 * Description: ���һ���ݳ��ƻ���Ϣ
 * Input:       ����ӵ��ݳ��ƻ���Ϣ����
 * Output:      ��
 * Return:      ��ӵļ�¼��
 */
inline int Schedule_Srv_Add(const schedule_t *data);

/*
 * Function:    Schedule_Srv_Modify
 * Function ID:	TTMS_SCU_Schedule_ Srv _Mod
 * Description: ����һ���ݳ��ƻ���Ϣ
 * Input:       �����µ��ݳ��ƻ���Ϣ����
 * Output:      ��
 * Return:      ���µ��ݳ��ƻ���Ϣ����0��ʾδ�ҵ���1��ʾ�ҵ�������
 */
inline int Schedule_Srv_Modify(const schedule_t *data);

/*
 * Function:    Schedule_Srv_DeleteByID
 * Function ID:	TTMS_SCU_Schedule_Srv_DelByID
 * Description: ����ID��ɾ���ݳ��ƻ���Ϣ
 * Input:       ��ɾ�����ݳ��ƻ�ID��
 * Output:      ��
 * Return:      0��ʾɾ��ʧ�ܣ�1��ʾɾ���ɹ�
 */
inline int Schedule_Srv_DeleteByID(int ID);

/*
 * Function:    Schedule_Srv_FetchByID
 * Function ID:	TTMS_SCU_Schedule_Srv_FetchByID
 * Description: ����ID�Ų���һ���ݳ��ƻ���Ϣ������buf��ָ��Ԫ
 * Input:       �����ҵ��ݳ��ƻ�ID�ţ������ҵ�����Ϣ���浽buf��
 * Output:      ��
 * Return:      0��ʾδ�ҵ���1��ʾ�ҵ���
 */
inline int Schedule_Srv_FetchByID(int ID, schedule_t *buf);

/*
 * Function:    Schedule_Srv_FetchAll
 * Function ID:	TTMS_SCU_Schedule_Srv_FetchAll
 * Description: ȡ�������ݳ��ƻ���Ϣ������һ������
 * Input:       list�ݳ��ƻ���Ϣ�����ͷָ��
 * Output:      ��
 * Return:      ���ز��ҵ��ļ�¼��Ŀ
 */
inline int Schedule_Srv_FetchAll(schedule_list_t list);

/*
 * Function:    Schedule_Srv_FetchByPlay
 * Function ID:	TTMS_SCU_Schedule_Srv_FetchByPlay
 * Description: ���վ�ĿID�ţ�������ݳ��ƻ���Ϣȡ��������һ������
 * Input:       listΪ���ҵ����ݳ��ƻ���Ϣ�����ͷָ�룬play_idΪ��Ŀ��ID��
 * Output:      ��
 * Return:      ���ز��ҵ��ļ�¼��Ŀ
 */
inline int Schedule_Srv_FetchByPlay(schedule_list_t list,int play_id);

/*
 * Function:    Schedule_Srv_StatRevByPlay
 * Function ID:	TTMS_SCU_Schedule_Srv_StatByPlay
 * Description: ���ݾ�ĿID��ͳ�������ʼ�Ʊ��������Ʊ��������
 * Input:       play_idΪ��ͳ�ƾ�Ŀ��ID�ţ�soldCountΪ������Ʊ����totalCountΪ��Ʊ��
 * Output:      ��
 * Return:      ����Ʊ������
 */
int Schedule_Srv_StatRevByPlay(int play_id, int *soldCount, int *totalCount);


#endif //SCHEDULE_H_
