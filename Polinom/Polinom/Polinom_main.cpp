#include"Polinom_header.h"
#include<iostream>
 int main()
{
	 setlocale(LC_ALL, "Russian");
	 TPolinom p1, p2,res,p1_,p2_;
	 TMonom m1(2, 3, 4, 1.0), m2(2, 3, 4, 1.0), m3(2, 2, 2, -1.0), m4(2, 2, 2, 1.0);
	 p1.InsMonom(m1);
	 p2.InsMonom(m2);
	 p1.InsMonom(m3);
	 p2.InsMonom(m4);
	 p1_ = p1; p2_ = p2;
	 std::cout << p1 << std::endl;
	 std::cout << p2 << std::endl;
	 std::cout << "Сложение" << std::endl;
	 res = p1 + p2;
	 std::cout << res << std::endl;
	 std::cout << "Умножение" << std::endl;
	 res = p1_ * p2_;
	 std::cout << res << std::endl;
	 int t;
	 std::cin >> t;
	 /*setlocale(LC_ALL, "Russian");
	 while (true)
	 {
		 std::cout << "Выберите действие: +, +=, *, *= (для выхода нажмите 0):";
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
			 std::cout << "1-умножить на число" << std::endl << "2-умножить на моном" << std::endl << "3-умножить на полином" << std::endl;
			 int tmp;
			 std::cin >> tmp;
			 switch (tmp)
			 {
			 case(1):
			 {
				 TPolinom res;
				 std::cout << "p:";
				 std::cin >> p1;
				 std::cout << std::endl << "Число:";
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
				 std::cout << std::endl << "Моном:";
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
	 return 0;*/
}