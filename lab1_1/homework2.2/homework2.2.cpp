// ------------------------【NQueen.cpp】----------------------------
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

// ---------------------------------【回溯求解】----------------------------
void CNQueen::TraceBack(int CurRow)
{
    // 这里需要有个 等号操作，我说怎么死活没结果
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
            CurRow--;               // 恢复现场
        }           
    }


}

// ---------------------------------【剪枝函数】----------------------------
bool CNQueen::IsOK(int row, int col)
{
    for (int k = 0; k != row; k++)
    {
        if (col == m_RowSelect[k])    // 列
            return false;

        if (row - k == col - m_RowSelect[k])  // 斜线
            return false;

        if (row - k == m_RowSelect[k] - col)
            return false;
    }

    return true;
}

// ---------------------------------【显示 解的分布 】----------------------------
void CNQueen::output()
{   
    FILE * fd = NULL;

    if (m_solution_num == 1)
    {
        fd = fopen("output.txt", "wt");
        fprintf(fd, "-----------------------------%d皇后问题求解-----------------------------------\n",
            m_num);
    }
    else
        fd = fopen("output.txt", "at+");


    fprintf(fd, "找到第%d组可行解\n", m_solution_num);
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

// ---------------------------------【求解 并显示在屏幕上】----------------------------
void CNQueen::SolveResult()
{
    TraceBack(0);

    if (m_solution_num == 0)
        fprintf(stdout, "无解\n");
    else
        fprintf(stdout, "找到%d组解,放在output.txt文件中\n", m_solution_num);
}

int main(int arg, char ** argv)
{
    CNQueen instance(8);
    instance.SolveResult();
    system("pause");
    return 0;
}