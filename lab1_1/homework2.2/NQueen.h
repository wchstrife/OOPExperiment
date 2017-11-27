// ----------------------¡¾NQueen.h¡¿-------------------
#pragma once
class CNQueen
{
public:
    CNQueen();
    CNQueen(int num);
    ~CNQueen();

public:
    void SolveResult();

private:
    bool IsOK(int row, int col);
    void output();
    bool init(int num);
    void TraceBack(int CurRow);

private:
    int m_num;
    int * m_RowSelect;

    int m_solution_num;
};