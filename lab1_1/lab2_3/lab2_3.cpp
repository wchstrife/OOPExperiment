#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//enum bool { false, true };

template<class T>
struct quenode {                 //定义队列中的各结点类型
    T nodedata;
    quenode *next;
};
template <class T>
class  queue {
     protected:
         int  quesize;                 //定义队列长度
         quenode<T>  *head;            //定义队列列头
         quenode<T>  *tail;            //定义队列列尾
         bool allocateerror;
         queue   &copy (queue  &q);    //队列拷贝函数
     public:
          queue();                     //构造函数 
          queue(queue &q){ head=NULL;tail=NULL; copy(q);}//建q 队列
          ~queue()  { clearque(); }
          bool  getallocateerror()  { return  allocateerror;  }
          void push(T &);                //将结点插入队尾
          bool pop(T &);                 //队头取结点
          bool isempty() { return  (quesize==0)? true: false;}
                                         //判断队列是否为空
          void clearque();               //清空队列
 queue &operator= (queue &q) {  copy(q);  return  *this;  }
                                            //重载赋值运算符
};
template<class T>
queue<T>::queue()                       //定义构造函数 
{  quesize=0;
    allocateerror=false;
    head=NULL;
    tail=NULL;
}
template<class T>
queue<T> &queue<T>::copy(queue<T> &que) 
                                  //将队列que复制给当前队列对象
{ quenode<T>  *p,  *q,  *r;
  if (head)  clearque();
  quesize=que.quesize;                  //传递队列长度
  allocateerror=false;
  head=NULL;
  tail=NULL;
  if (!que.head)  return *this;         //若队列为空，则返回
  head=new quenode<T>;                  //为队列头结点分配存储空间
  if (!head)                            //若分配失败，则返回
   {  allocateerror=true;
       return  *this;
   }
  head->nodedata=que.head->nodedata;
                             //将que队列头结点值赋给当前队列头结点
  head->next=NULL;
  tail=head;                     //将队列尾也指向此结点
  r=NULL;
  p=head;                        //p 指针也指向此结点
  q=que.head->next;              //q 指针指向que队列的第二个结点
  while (q)
  { r=new  quenode<T>;           //为结点r 分配存储空间
    if(! r ) 
    {  allocateerror=true;
      return  *this;
    }
    r->nodedata=q->nodedata;
    r->next=NULL;
    p->next=r ;              //将结点 r 链接到当前队列的链上
    tail=r ;                 //队尾指针指向 r，因为r为最后一个结点
    p=p->next;               //指针后移                                
    q=q->next;
  }
  return  *this;
}

template<class  T>
void  queue<T>::push(T  &x)             //向队尾插入结点
{ quenode<T>   *p;
  p=new  quenode<T>;                    //为 p 结点分配存储空间
  if( !p )                              //若分配失败，则返回
  {  allocateerror=true;
     return;
  }
  p->nodedata=x;
  if (tail)                             //若队列非空
  { p->next=head;                 //将 p 结点链接到头指针head前
    head =p;                            //修改队头指针
  }
 else                                   //若队列为空
  { p->next=NULL;
     head=p;                            //p结点为队列的头，又为尾
     tail=p; 
  } 
  quesize++;                            //长度加1
}  

template<class T>
bool queue<T>::pop(T  &x)               //从队头取一结点
{ quenode<T>   *p;
   if (head)                            //若队列非空
   { x=head->nodedata;                  //将队头的数据内容赋给x 
     p=head;
     head=head->next;                   //修改队头指针
     if (head==NULL)              //若队列已删空，则tail也改为 NULL
        tail=NULL;
     delete p;                     //删除原头结点
     quesize--;                    //长度减1
     return   true;
   }
   return false;
}

template<class T>
void  queue<T>::clearque()             //将队列清空
{ T    p;
  allocateerror=false;
  while (pop(p)) ;                 //循环提取队列中各结点,实现清除
  head=tail=NULL;
}; 

class staff{                           //定义职工类
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

void  viewque(queue<staff>  &que)//显示实例化后的队列que中的各结点
{  int   i=1;
   staff   p;
   queue<staff>  quecopy(que);//定义queue<staff>类的临时对象quecopy
                              //把形参que传给它
   //clrscr();                //DOS的函数windows不能执行
   while(quecopy.pop(p))               //循环提取队列中各结点
   {    // gotoxy(1, i+5);    //DOS的函数windows不能执行
      printf("%2d:", i++);
      p.print();
   }
}

void  main()
{  queue<staff>  que;                  //定义队列类对象que
   staff  p;                           //定义职工类对象p
   p.assign("陈伟林",47,1500,"男");    //给p对象赋值
   que.push(p);                        //将 p 对象压入队列que
   p.assign("王凌",34,850.5,"男");
   que.push(p);
   p.assign("张大霖",27,1200,"男");
   que.push(p);
   p.assign("方丽碧",51,2000,"女");
   que.push(p);
   viewque(que);                       //显示队列中的各结点
   system("pause");
}
