#include <iostream>
#define Add(type) (type*)malloc(sizeof(type)) //����꺯��


using namespace std;
struct pcb { //PCB�ṹ�嶨��
	char name[99];
	char state;
	int priority;
	int needtime;
	int passedtime;
	struct pcb* link;
}*ready = NULL, * process;
typedef struct pcb PCB;

