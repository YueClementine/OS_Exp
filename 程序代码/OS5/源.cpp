#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int avail[3] = {1,1,2};
int maxim[4][3] = { {3,2,2},{6,1,3},{3,1,4},{4,2,2} };
int allo[4][3] = { {1,0,0},{5,1,1},{2,1,1},{0,0,2} };
int resourcesNumber = 3, processesNumber = 4;
int need[4][3];

void print() {
    int i, j;
    cout << "���м��㷨";
    cout << "����������MAX��" << endl;
    cout << "PROCESS";
    for (i = 0;i < resourcesNumber;i++)
    {
        cout<<"\tR"<<i<<"\t";
    }
    cout<<endl<<endl;
    for (i = 0;i < processesNumber;i++)
    {
        cout << "P" << i << "\t";
        for (j = 0;j < resourcesNumber;j++)
        {
            cout << maxim[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << "/////////////////////"<<endl;
    for (i = 0;i < processesNumber;i++)
    {
        for (j = 0;j < resourcesNumber;j++)
        {
            need[i][j] = maxim[i][j] - allo[i][j];
        }
    }
    cout << "�������" << endl;
    cout << "PROCESS";
    for (i = 0;i < resourcesNumber;i++)
    {
        cout << "\tR" << i << "\t";
    }
    cout << endl;
    for (i = 0;i < processesNumber;i++)
    {
        cout << "P" << i << "\t";
        for (j = 0;j < resourcesNumber;j++)
        {
            cout << allo[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << "///////////////////"<<endl;
    cout << "�������NEED��" << endl;
    cout << "PROCESS";
    for (i = 0;i < resourcesNumber;i++)
    {
        cout << "\tR" << i << "\t";
    }
    cout << endl;
    for (i = 0;i < processesNumber;i++)
    {
        cout << "P" << i << "\t";
        for (j = 0;j < resourcesNumber;j++)
        {
            cout << need[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << "///////////////////" << endl;
    cout << "������Դ����" << endl;
    cout << "������Դ";
    for (i = 0;i < resourcesNumber;i++)
    {
        cout << "\tR" << i << "\t";
    }
    cout << endl;
    cout << "\t\t";
    for (j = 0;j < resourcesNumber;j++)
        {
            cout << avail[j] << "\t\t";
        }

    cout << "///////////////////" << endl;
}
void rollback(int roll[], int pro)
{
    int k;
    for (k = 0;k < resourcesNumber;k++)
    {
        avail[k] = avail[k] + roll[k]; 
        allo[pro][k] = allo[pro][k] - roll[k];
        need[pro][k] = allo[pro][k] + roll[k];
    }
    cout << endl << "�����뵽����Դ����ȥ"<<endl;

}
int safety()
{
    int i, j, work[10], finish[10], flag = 0, k, cnt = 0, cn, flag1 = 0, ans;
    cout << "������ķ������Ϊ��" << endl;
    cout << "PROCESS";
    for (i = 0;i < resourcesNumber;i++)
    {
        cout << "\tR" << i << "\t";

    }
    cout << endl;
    for (i = 0;i < processesNumber;i++)
    {
        cout << endl << "P" << i << "\t";
        for (j = 0;j < resourcesNumber;j++)
        {
            cout << allo[i][j] << "\t\t";
        }
    }
    j = 0;
    for (i = 0;i < resourcesNumber;i++)
    {
        work[j] = avail[i];
        j++;
    }

    for (i = 0;i < processesNumber;i++)
    {
        finish[i] = 0;
    }

    while (cnt <= 10)
    {
        for (i = 0;i < processesNumber;i++)
        {
            if (finish[i] == 0)
            {
                for (j = 0;j < resourcesNumber;j++)
                {
                    if (need[i][j] <= work[j])
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }

                }
                if (flag == 1)//���������д��ԭ����
                {
                    cout << endl;
                    cout << "����" << i << "��������"<<endl;
                    finish[i] = 1;
                    for (k = 0;k < resourcesNumber;k++)
                    {
                        work[k] = work[k] + allo[i][k];

                    }

                }
            }
        }
        for (cn = 0;cn < processesNumber;cn++)
        {
            if (finish[cn] == 1)
            {
                flag1 = 1;
            }
            else
            {
                flag1 = 0;
                break;
            }
        }

        cnt++;
        if (flag1 == 1)
        {
            cout << "��ȫ����" << endl;
            ans = 0;
            break;
        }
    }
    if (flag1 == 0)
    {
        cout << endl << "���棡����������ȫ��";
        ans = 1;
    }
    return ans;
}
void request()
{
    print();
    int pro, val, i, safeOrNot, k, roll[4];
    char answer;
    while (1)
    {
        cout << "�Ƿ����������Դ��y/n��"<<endl;
        cin >> answer;
        k = 0;
        if (answer == 'y')
        {
            cout << "������Ҫ������Դ�Ľ���" << endl;
            cin >> pro;
            for (i = 0;i < resourcesNumber;i++)
            {
                cout << "������Ҫ���������" << pro << "��ԴR" << i << "����Ŀ��";
                do
                {
                    cin >> val;
                    if (val>avail[i])
                    {
                        cout << "�������Դ��������Ŀǰ������Դ,���������룺" << endl;
                    }
                    else if (val <= need[pro][i]) {
                        break;
                    }
                    else
                    {
                        cout<<"�������Դ�������˽�����Ҫ����Դ������������"<<endl;
                    }
                } while (val>need[pro][i]);
                    allo[pro][i] = allo[pro][i] + val;
                    avail[i] = avail[i] - val;
                    need[pro][i] = need[pro][i] - val;
                    roll[k] = val;
                    k++;
                
            }
            safeOrNot = safety();
            if (safeOrNot == 1)
            {
                rollback(roll, pro);
            }
        }
        else if(answer=='n')
        {
            exit(0);
        }
    }

}

int main()
{
    while (true) {
        request();
    }

    return 0;

}