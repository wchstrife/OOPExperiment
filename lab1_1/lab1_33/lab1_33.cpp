#include<iostream> 
#include <stdlib.h> 
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

struct MyNode
{
    MyNode(int a_data):m_data(a_data),m_pNext(NULL){}
    int m_data;
    MyNode *m_pNext;
};
class Josephus
{
    public:
        Josephus(int a_N,int a_K,int a_M):m_N(a_N),m_K(a_K),m_M(a_M){
            createList();
            outputList();
        }
    protected:
        void createList();
        void outputList();
    private:
        MyNode *m_pHead;   //ѭ�������ͷ�ڵ�
        int m_N;  //����ڵ����
        int m_K;  // ��һ�������˵����
        int m_M;  // �������ֵ���
};
void Josephus::createList()
{
    MyNode *pre = NULL;
    MyNode *cur = NULL;
    MyNode *p = new MyNode(1);
    m_pHead = p;
    cur = p;
    for(int i=2; i<=m_N;i++)
    {
        p = new MyNode(i);
        pre = cur;
        cur = p;
        pre->m_pNext = p;
    }
    cur->m_pNext = m_pHead;
    int n = m_N;
    p = m_pHead;
    cout << "��ʼ����Ϊ:" << endl; 
    while(n--){
        cout << p->m_data << ",";
        p = p->m_pNext;
    }
    cout << endl;
}
void Josephus::outputList()
{
	ofstream fout("01.out.txt",ofstream::app);
    // ��pStartָ���һ�������˵����
    MyNode *pStart = m_pHead;  
	MyNode *p = new MyNode(1);
    int count = 1;
    while(count < m_K){
        pStart = pStart->m_pNext;
        count++;
    }
    MyNode *pTemp = pStart;
    MyNode *pPre = NULL;
    MyNode *tobeDeleted = NULL;
    cout << "���γ��ֵ�����Ϊ:" << endl;
	/*������1��ʱ��ֱ�ӱ���һ���Ȧ����*/
	if(m_M == 1){
		int n = m_N;
    p = m_pHead;
    cout << "��ʼ����Ϊ:" << endl; 
    while(n--){
        cout << p->m_data << ",";
		fout << p->m_data << ",";
        p = p->m_pNext;
    }
    cout << endl;
	}else{
		while(pTemp->m_pNext!=pTemp) // when pTemp->m_pNext==pTemp only one node in the list
    {
        int count = 1; 
        while(count < m_M){
            pPre = pTemp;
            pTemp = pTemp->m_pNext;
            count++;
        }
        tobeDeleted = pTemp;
        pTemp = pTemp->m_pNext;
        pPre->m_pNext = pTemp;
        cout << tobeDeleted->m_data << ",";
		fout << tobeDeleted->m_data << ",";
    }
    cout << pTemp->m_data << endl;
	fout << pTemp->m_data << endl;
	} 
}

void PKbyNo(){
	int total_people;
	int start = 1;
	int step;

	ifstream infile;
	ofstream outfile;

	/*���ļ�*/
	infile.open("01.in.txt", ios::in); 

	while (!infile.eof())            // ��δ���ļ�����һֱѭ��
    {
        infile >> total_people >> step;
		cout << total_people << endl;
		cout << step << endl; 

		/*����Լɪ�����*/
		Josephus josephus(total_people,start,step);
    }

    infile.close();   //�ر��ļ�

	
	
}

int main()
{
	PKbyNo();
	/**
    int total_people;
    int start;
    int step;
    cout << "������������:" << endl;
    cin >> total_people;
    cout << "�����뿪ʼ������:" << endl;
    cin >> start;
    cout << "�����������������:" << endl;
    cin >> step;
    Josephus josephus(total_people,start,step);
	**/
	system("pause");
    return 0;
}