#include <iostream>

using namespace std;

const float PI = 3.1416;
void main()
{
	int graphicType;
	float radius, a, b, perimeter;
	cout << "��ѡ��ͼ�ε����� (1-Բ�� 2-������ 3-������) ��";
	cin >> graphicType;            //�ڴ������öϵ�
	switch(graphicType)
	{
	case 1:
		cout << "������Բ�İ뾶Ϊ��";
		cin >> radius;
		perimeter = PI * 2 * radius;
		cout<<"Բ"<< radius <<"���ܳ�Ϊ��"<< perimeter <<endl;
		break;
	case 2:
		cout << "��������εĳ������Կո�ָ�����";
		cin >> a >> b;
		perimeter = 2*(a + b );
	    cout<<"����"<< a <<"��"<<b<<"���ܳ�Ϊ��"<< perimeter <<endl;
		break;
	case 3:
		cout << "�����������εı߳�Ϊ��";
		cin >> a;
		perimeter = a * 4;
		cout<<"������"<< a <<"���ܳ�Ϊ��"<< perimeter <<endl;
		break;
	default:
		cout << "�������!"<<endl;
	}
}

