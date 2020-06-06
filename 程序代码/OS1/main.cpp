#include "pcb.h"
void display(PCB* displayProcess) //��ӡ������Ϣ
{
	cout << endl << " -������ " <<"-״̬ " << "  " << "-������" <<" "<<"-������ʱ��"<<"  "<<"-�Ѿ�����ʱ��"<< endl;
	cout << "  " <<displayProcess->name << "\t";
	cout << "  " << displayProcess->state << "\t";
	cout << "  " << displayProcess->priority << "\t";
	cout << "  " << displayProcess->needtime << "\t";
	cout <<"     "<< "  " << displayProcess->passedtime << "\t";
	cout << endl;
}
void classify() //�Խ��̰�����������������
{
	PCB* Head, * second;
	//�������û�н��̣��������ȼ�����Ŀǰ��������
	if ((ready == NULL) || ((process->priority) > (ready->priority)))
	{
		process->link = ready;
		ready = process;
	}
	//�����н��̣������ȼ�С��Ŀǰ��������
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
void insert() //�������
{
	int num;
	cout << "�������������" << endl;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int a = i + 1;
		cout << "����" << a << endl;
		process = Add(PCB);
		cout << "�����������" << endl;
		cin >> process->name;
		cout << "���������������" << endl;
		cin >> process->priority;
		cout << "���������Ҫ������ʱ��" << endl;
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

void print() //��ӡ�������
{
	PCB* temp;
	cout << endl << "�������еĽ���Ϊ��" << process->name << endl;
	cout << "-----------------------------------------------------" << endl;
	display(process);
	cout << "-----------------------------------------------------" << endl;
	temp = ready;
	cout << endl << "���ھ����Ķ���Ϊ��"  << endl;
	while (temp != NULL)
	{
		display(temp);
		temp = temp->link;
	}
	cout << "-----------------------------------------------------" << endl;
}

void finish() //���̽���
{
	cout << "����" << process->name << "�����";
	free(process);
}
void running() //����ʱ�Ӻ����ƽ�
{
	(process->passedtime)++;
	if (process->passedtime == process->needtime)
		finish(); //���̽���
	else
	{
		(process->priority)--;
		process->state = 'R';
		classify(); //��������
	}
}

int main() 
{
	int length= 0;
	insert();
	length = space();
	getchar();
	while ((length != 0) && (ready != NULL))//�ж��������ж����
	{
		int num = 0;
		num++;
		cout << endl << "��"<<num<<"�β���";
		process = ready;
		ready = process->link;
		process->link = NULL;
		process->state = 'R';
		print();
		running();
		cout << endl<<"�����������" ;
		getchar();
	}
	cout << "���̽���" << endl;
	getchar();
}