#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <sys/wait.h>
#include<unistd.h>
using namespace std;
int main()
{
    pid_t pid_B, pid_C;
    if ((pid_B = fork()) < 0)
    {
        cout<<"���̴���ʧ��"<<endl;
        return -1;
    }
    else if (pid_B == 0) 
    {
        cout<<"��ǰ���ӽ���B"<<endl;  
        return 0;
    }
    if ((pid_C = fork()) < 0)
    {
        cout<<"���̴���ʧ��"<<endl;
        return -1;
    }
    else if (pid_C == 0)
    {
        cout<<"��ǰ���ӽ���C"<<endl;
        return 0;
    }
    waitpid(pid_B, NULL, 0);
    waitpid(pid_B, NULL, 0); 
    cout << "��ǰ�Ǹ�����A" << endl;
    return 0;
}