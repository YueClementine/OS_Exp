#include "storage.h"

bool Task::reclaim(int id) //回收作业
{
	list <Task*>::iterator reclaim_list;
	if (tasklist.empty())
	{
		cout << "内存为空" << endl;
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
	cout << "作业回收失败" << id << endl;
	return false;
}