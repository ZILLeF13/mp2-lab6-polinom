#include"Polinom_header.h"
#include<iostream>
 int main()
{
	 setlocale(LC_ALL, "Russian");
	 while (true)
	 {
		 std::cout << "�������� ��������: +, +=, *, *= (��� ������ ������� 0):";
		 TPolinom p1, p2;
		 int flag = 0;
		 std::string p;
		 std::cin >> p;
		 if (p == "+")
		 {
			 TPolinom res;
			 std::cout << "p1: ";
			 std::cin >> p1;
			 std::cout << std::endl << "p2: ";
			 std::cin >> p2;
			 res = p1 + p2;
			 std::cout << std::endl << p1 << " + " << p2 << " = " << res << std::endl;
			 flag = 1;
		 }
		 if (p == "+=")
		 {
			 TPolinom res;
			 std::cout << "p1: ";
			 std::cin >> p1;
			 std::cout << std::endl << "p2: ";
			 std::cin >> p2;
			 std::cout << std::endl << p1 << "+= " << p2 << " = ";
			 p1 += p2;
			 std::cout << p1 << std::endl;
			 flag = 1;
		 }
		 if (p == "*")
		 {
			 std::cout << "1-�������� �� �����" << std::endl << "2-�������� �� �����" << std::endl << "3-�������� �� �������" << std::endl;
			 int tmp;
			 std::cin >> tmp;
			 switch (tmp)
			 {
			 case(1):
			 {
				 TPolinom res;
				 std::cout << "p:";
				 std::cin >> p1;
				 std::cout << std::endl << "�����:";
				 double val;
				 std::cin >> val;
				 res = p1 * val;
				 std::cout << std::endl << p1 << " * " << val << " = " << res << std::endl;
				 break;
			 }
			 case(2):
			 {
				 TPolinom res;
				 std::cout << "p:";
				 std::cin >> p1;
				 std::cout << std::endl << "�����:";
				 TMonom m;
				 std::cin >> m;
				 res = p1 * m;
				 std::cout << std::endl << p1 << " * " << m << " = " << res << std::endl;
				 break;
			 }
			 case(3):
			 {
				 TPolinom res;
				 std::cout << "p1:";
				 std::cin >> p1;
				 std::cout << std::endl << "p2:";
				 std::cin >> p2;
				 res = p1 * p2;
				 std::cout << std::endl << p1 << " * " << p2 << " = " << res << std::endl;
				 break;
			 }
			 default:
				 break;
			 }
			 flag = 1;
		 }
		 if (p == "*=")
		 {
			 TPolinom res;
			 std::cout << "p1:";
			 std::cin >> p1;
			 std::cout << std::endl << "p2:";
			 std::cin >> p2;
			 std::cout << std::endl << p1 << " *= " << p2 << " = ";
			 p1 *= p2;
			 std::cout << p1 << std::endl;
			 flag = 1;
		 }
		 if (flag==0)
			 break;
		 std::cout << std::endl;
	 }
	 return 0;
}