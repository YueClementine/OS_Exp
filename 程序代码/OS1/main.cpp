#include "pcb.h"
void display(PCB* displayProcess) //打印进程信息
{
	cout << endl << " -进程名 " <<"-状态 " << "  " << "-优先数" <<" "<<"-总运行时间"<<"  "<<"-已经运行时间"<< endl;
	cout << "  " <<displayProcess->name << "\t";
	cout << "  " << displayProcess->state << "\t";
	cout << "  " << displayProcess->priority << "\t";
	cout << "  " << displayProcess->needtime << "\t";
	cout <<"     "<< "  " << displayProcess->passedtime << "\t";
	cout << endl;
}
void classify() //对进程按照优先数进行排序
{
	PCB* Head, * second;
	//如果就绪没有进程，或者优先级大于目前就绪进程
	if ((ready == NULL) || ((process->priority) > (ready->priority)))
	{
		process->link = ready;
		ready = process;
	}
	//就绪有进程，且优先级小于目前就绪进程
	else {
		int i = 0;
		Head = ready;
		second = Head->link;
		while (second != NULL)
		{
			if ((process->priority) > (second->priority))
			{
				process->link = second;
				Head->link = process;
				second = NULL;
				i = 1;
			}
			else
			{

				Head = Head->link;
				second = second->link;
			}
		}
		if (i == 0)
			Head->link = process;
	}
}
void insert() //插入进程
{
	int num;
	cout << "请输入进程数量" << endl;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int a = i + 1;
		cout << "进程" << a << endl;
		process = Add(PCB);
		cout << "请输入进程名" << endl;
		cin >> process->name;
		cout << "请输入进程优先数" << endl;
		cin >> process->priority;
		cout << "请输入进程要求运行时间" << endl;
		cin >> process->needtime;

		process->passedtime = 0; 
		process->state = 'R';
		process->link = NULL;
		classify(); 
	}
}

int space()
{
	int l = 0; PCB* temp = ready;
	while (temp != NULL)
	{
		l++;
		temp = temp->link;
	}
	return(l);
}

void print() //打印输出函数
{
	PCB* temp;
	cout << endl << "正在运行的进程为：" << process->name << endl;
	cout << "-----------------------------------------------------" << endl;
	display(process);
	cout << "-----------------------------------------------------" << endl;
	temp = ready;
	cout << endl << "正在就绪的队列为："  << endl;
	while (temp != NULL)
	{
		display(temp);
		temp = temp->link;
	}
	cout << "-----------------------------------------------------" << endl;
}

void finish() //进程结束
{
	cout << "进程" << process->name << "已完成";
	free(process);
}
void running() //类似时钟函数推进
{
	(process->passedtime)++;
	if (process->passedtime == process->needtime)
		finish(); //进程结束
	else
	{
		(process->priority)--;
		process->state = 'R';
		classify(); //重新排序
	}
}

int main() 
{
	int length= 0;
	insert();
	length = space();
	getchar();
	while ((length != 0) && (ready != NULL))//判断两个队列都完成
	{
		int num = 0;
		num++;
		cout << endl << "第"<<num<<"次操作";
		process = ready;
		ready = process->link;
		process->link = NULL;
		process->state = 'R';
		print();
		running();
		cout << endl<<"按任意键继续" ;
		getchar();
	}
	cout << "进程结束" << endl;
	getchar();
}