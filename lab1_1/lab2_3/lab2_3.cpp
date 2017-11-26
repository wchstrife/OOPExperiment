#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//enum bool { false, true };

template<class T>
struct quenode {                 //��������еĸ��������
    T nodedata;
    quenode *next;
};
template <class T>
class  queue {
     protected:
         int  quesize;                 //������г���
         quenode<T>  *head;            //���������ͷ
         quenode<T>  *tail;            //���������β
         bool allocateerror;
         queue   &copy (queue  &q);    //���п�������
     public:
          queue();                     //���캯�� 
          queue(queue &q){ head=NULL;tail=NULL; copy(q);}//��q ����
          ~queue()  { clearque(); }
          bool  getallocateerror()  { return  allocateerror;  }
          void push(T &);                //���������β
          bool pop(T &);                 //��ͷȡ���
          bool isempty() { return  (quesize==0)? true: false;}
                                         //�ж϶����Ƿ�Ϊ��
          void clearque();               //��ն���
 queue &operator= (queue &q) {  copy(q);  return  *this;  }
                                            //���ظ�ֵ�����
};
template<class T>
queue<T>::queue()                       //���幹�캯�� 
{  quesize=0;
    allocateerror=false;
    head=NULL;
    tail=NULL;
}
template<class T>
queue<T> &queue<T>::copy(queue<T> &que) 
                                  //������que���Ƹ���ǰ���ж���
{ quenode<T>  *p,  *q,  *r;
  if (head)  clearque();
  quesize=que.quesize;                  //���ݶ��г���
  allocateerror=false;
  head=NULL;
  tail=NULL;
  if (!que.head)  return *this;         //������Ϊ�գ��򷵻�
  head=new quenode<T>;                  //Ϊ����ͷ������洢�ռ�
  if (!head)                            //������ʧ�ܣ��򷵻�
   {  allocateerror=true;
       return  *this;
   }
  head->nodedata=que.head->nodedata;
                             //��que����ͷ���ֵ������ǰ����ͷ���
  head->next=NULL;
  tail=head;                     //������βҲָ��˽��
  r=NULL;
  p=head;                        //p ָ��Ҳָ��˽��
  q=que.head->next;              //q ָ��ָ��que���еĵڶ������
  while (q)
  { r=new  quenode<T>;           //Ϊ���r ����洢�ռ�
    if(! r ) 
    {  allocateerror=true;
      return  *this;
    }
    r->nodedata=q->nodedata;
    r->next=NULL;
    p->next=r ;              //����� r ���ӵ���ǰ���е�����
    tail=r ;                 //��βָ��ָ�� r����ΪrΪ���һ�����
    p=p->next;               //ָ�����                                
    q=q->next;
  }
  return  *this;
}

template<class  T>
void  queue<T>::push(T  &x)             //���β������
{ quenode<T>   *p;
  p=new  quenode<T>;                    //Ϊ p ������洢�ռ�
  if( !p )                              //������ʧ�ܣ��򷵻�
  {  allocateerror=true;
     return;
  }
  p->nodedata=x;
  if (tail)                             //�����зǿ�
  { p->next=head;                 //�� p ������ӵ�ͷָ��headǰ
    head =p;                            //�޸Ķ�ͷָ��
  }
 else                                   //������Ϊ��
  { p->next=NULL;
     head=p;                            //p���Ϊ���е�ͷ����Ϊβ
     tail=p; 
  } 
  quesize++;                            //���ȼ�1
}  

template<class T>
bool queue<T>::pop(T  &x)               //�Ӷ�ͷȡһ���
{ quenode<T>   *p;
   if (head)                            //�����зǿ�
   { x=head->nodedata;                  //����ͷ���������ݸ���x 
     p=head;
     head=head->next;                   //�޸Ķ�ͷָ��
     if (head==NULL)              //��������ɾ�գ���tailҲ��Ϊ NULL
        tail=NULL;
     delete p;                     //ɾ��ԭͷ���
     quesize--;                    //���ȼ�1
     return   true;
   }
   return false;
}

template<class T>
void  queue<T>::clearque()             //���������
{ T    p;
  allocateerror=false;
  while (pop(p)) ;                 //ѭ����ȡ�����и����,ʵ�����
  head=tail=NULL;
}; 

class staff{                           //����ְ����
    public:
       char  name[80];
       int  age;
       float  salary;
       char  sex[8];
    void  assign(char  *name, int  age,  float  salary,  char  *sex)
       {  strcpy(staff::name,name);
          staff::age=age;
          staff::salary=salary;
          strcpy(staff::sex,sex);
       }
       void  print()
       {  printf("%10s%6d%10.2f%8s\n",name,age,salary,sex);  }
};

void  viewque(queue<staff>  &que)//��ʾʵ������Ķ���que�еĸ����
{  int   i=1;
   staff   p;
   queue<staff>  quecopy(que);//����queue<staff>�����ʱ����quecopy
                              //���β�que������
   //clrscr();                //DOS�ĺ���windows����ִ��
   while(quecopy.pop(p))               //ѭ����ȡ�����и����
   {    // gotoxy(1, i+5);    //DOS�ĺ���windows����ִ��
      printf("%2d:", i++);
      p.print();
   }
}

void  main()
{  queue<staff>  que;                  //������������que
   staff  p;                           //����ְ�������p
   p.assign("��ΰ��",47,1500,"��");    //��p����ֵ
   que.push(p);                        //�� p ����ѹ�����que
   p.assign("����",34,850.5,"��");
   que.push(p);
   p.assign("�Ŵ���",27,1200,"��");
   que.push(p);
   p.assign("������",51,2000,"Ů");
   que.push(p);
   viewque(que);                       //��ʾ�����еĸ����
   system("pause");
}
