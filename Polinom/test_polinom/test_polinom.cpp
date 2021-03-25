#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING 
#include "../Polinom/Polinom_header.h"

#include "gtest.h"

#include <iostream>
//ASSERT_NO_THROW(TMatrix<int> m(5));
//ASSERT_ANY_THROW(TMatrix<int> m(-5));
//EXPECT_EQ(m1, m)
//EXPECT_EQ(1, m == m);



TEST(TPolinom, polinom_cozdaetca_bez_oshibok)
{
  ASSERT_NO_THROW(TPolinom p);
}

TEST(TPolinom, monom_cozdaetca_bez_oshibok)
{
	ASSERT_NO_THROW(TMonom p);
}

TEST(TPolinom, monom_cozdaetca_c_ctondartom)
{
	TMonom m;
	TMonom m1(0, 0, 0, 1.0);
	EXPECT_EQ(m, m1);
}

TEST(TPolinom, monom_priravnivaet)
{
	TMonom m,m1(2,2,2,2.0);
	m = m1;
	EXPECT_EQ(m, m1);
}

TEST(TPolinom, cravnenie_monomov)
{
	TMonom m(2, 2, 2, 2.0), m1(2, 2, 2, 2.0),m2(3,3,3,3.0);
	EXPECT_EQ(1, m==m1);
	EXPECT_EQ(1, m < m2);
	EXPECT_EQ(1, m2 > m1);
}

TEST(TPolinom, polinom_priravnivaet)
{
	TMonom m, m1(2, 2, 2, 2.0);
	TPolinom p, p1;
	p.InsMonom(m);
	p1.InsMonom(m1);
	ASSERT_NO_THROW(p = p1);
}

TEST(TPolinom, polinom_skladivaet_odinakovie_coeff)
{
	TMonom m(2,2,2,2.0), m1(2, 2, 2, 2.0);
	TPolinom p, p1,res;
	p.InsMonom(m);
	p1.InsMonom(m1);
	res = p + p1;
	EXPECT_EQ(1, res.Get_Size());
}

TEST(TPolinom, polinom_skladivaet_raznie_coeff)
{
	TMonom m(2, 3, 2, 2.0), m1(2, 2, 2, 2.0);
	TPolinom p, p1, res;
	p.InsMonom(m);
	p1.InsMonom(m1);
	res = p + p1;
	EXPECT_EQ(2, res.Get_Size());
}

TEST(TPolinom, polinom_skladivaet_odinakovie_coeff_c_minusom)
{
	TMonom m(2, 2, 2, 2.0), m1(2, 2, 2, -2.0);
	TPolinom p, p1, res;
	p.InsMonom(m);
	p1.InsMonom(m1);
	res = p + p1;
	EXPECT_EQ(0, res.Get_Size());
} 

TEST(TPolinom, polinom_skladivaet_raznie_coeff_c_minusom)
{
	TMonom m(2, 3, 2, 2.0), m1(2, 2, 2, -2.0);
	TPolinom p, p1, res;
	p.InsMonom(m);
	p1.InsMonom(m1);
	res = p + p1;
	EXPECT_EQ(2, res.Get_Size());
}

TEST(TPolinom, umnojaet_const_na_monom)
{
	TMonom m(2, 2, 2, 2.0);
	m = m * 2;
	EXPECT_EQ(4, m.coeff);
}

TEST(TPolinom, umojaet_monomi)
{
	TMonom m(2, 2, 2, 2.0), m1(2, 2, 2, 2.0),m2(4,4,4,4.0);
	EXPECT_EQ(m*m1, m2);
}

