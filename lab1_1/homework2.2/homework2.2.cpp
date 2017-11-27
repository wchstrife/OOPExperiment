// ------------------------��NQueen.cpp��----------------------------
#include "NQueen.h"
#include <cstdio>
#include <string>


bool CNQueen::init(int num)
{
    m_solution_num = 0;

    m_RowSelect = new int[m_num];
    memset(m_RowSelect, 0, sizeof(m_RowSelect));

    return true;
}

CNQueen::CNQueen(int num) :m_num(num)
{
    init(m_num);
}


CNQueen::~CNQueen()
{
    if (m_RowSelect)
        delete [] m_RowSelect;
}

// ---------------------------------��������⡿----------------------------
void CNQueen::TraceBack(int CurRow)
{
    // ������Ҫ�и� �ȺŲ�������˵��ô����û���
    if (CurRow >= m_num)
    {
        m_solution_num++;
        output();       
        return;
    }

    for (int j = 0; j != m_num; j++)
    {
        m_RowSelect[CurRow] = j;
        if (IsOK(CurRow, j))
        {
            CurRow++;
            TraceBack(CurRow);  
            CurRow--;               // �ָ��ֳ�
        }           
    }


}

// ---------------------------------����֦������----------------------------
bool CNQueen::IsOK(int row, int col)
{
    for (int k = 0; k != row; k++)
    {
        if (col == m_RowSelect[k])    // ��
            return false;

        if (row - k == col - m_RowSelect[k])  // б��
            return false;

        if (row - k == m_RowSelect[k] - col)
            return false;
    }

    return true;
}

// ---------------------------------����ʾ ��ķֲ� ��----------------------------
void CNQueen::output()
{   
    FILE * fd = NULL;

    if (m_solution_num == 1)
    {
        fd = fopen("output.txt", "wt");
        fprintf(fd, "-----------------------------%d�ʺ��������-----------------------------------\n",
            m_num);
    }
    else
        fd = fopen("output.txt", "at+");


    fprintf(fd, "�ҵ���%d����н�\n", m_solution_num);
    for (int i = 0; i != m_num; i++)
    {
        for (int j = 0; j != m_num; j++)
        {
            if (m_RowSelect[i] == j)
                fprintf(fd, "\tQ");
            else
                fprintf(fd, "\t*");
        }
        fprintf(fd, "\n");
    }
    fclose(fd);
    //system("pause");
}

// ---------------------------------����� ����ʾ����Ļ�ϡ�----------------------------
void CNQueen::SolveResult()
{
    TraceBack(0);

    if (m_solution_num == 0)
        fprintf(stdout, "�޽�\n");
    else
        fprintf(stdout, "�ҵ�%d���,����output.txt�ļ���\n", m_solution_num);
}

int main(int arg, char ** argv)
{
    CNQueen instance(8);
    instance.SolveResult();
    system("pause");
    return 0;
}