#include "storage.h"

bool Task::reclaim(int id) //������ҵ
{
	list <Task*>::iterator reclaim_list;
	if (tasklist.empty())
	{
		cout << "�ڴ�Ϊ��" << endl;
		return false;
	}
	for (reclaim_list = tasklist.begin(); reclaim_list != tasklist.end(); reclaim_list++)
	{
		Task* task;
		task = *reclaim_list;
		if (id == task->id)
		{
			tasklist.remove(task);
			return true;
		}
	}
	cout << "��ҵ����ʧ��" << id << endl;
	return false;
}