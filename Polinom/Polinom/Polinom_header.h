#pragma once
#include<iostream>
#include <string>
template <class T>
struct TLink
{
	T val;
	TLink *pNext;
};
template <class T>
class TList
{
protected:
	TLink<T>*pFirst, *pLast, *pCurr, *pPrev, *pStop;
	int size,pos;
public:
	TList()
	{
		pStop = NULL;
		pFirst = pStop;
		pLast = pStop;
		pCurr = pStop;
		pPrev = pStop;
		size = 0;
		pos = 0;
	}
	TList(const TList<T>& m)  //без Т?
	{
		if (m.size == 0)
		{
			pStop = m.pStop;
			pFirst = pStop;
			pLast = pStop;
			pCurr = pStop;
			pPrev = pStop;
			size = 0;
			pos = 0;
		}
		else
		{
			pStop = m.pStop;
			pCurr = pStop;
			pPrev = pStop;
			pos = 0;
			TLink<T>* p = new TLink<T>;
			p->val = m.pFirst->val;
			p->pNext = pStop;
			pFirst = p;
			TLink<T>* curr = m.pFirst;
			while (curr->pNext != pStop)
			{
				curr = curr->pNext;
				TLink<T>* link = new TLink<T>;
				link->val = curr->val;
				link->pNext = pStop;
				p->pNext = link;
				p = link;
			}
			size = m.size;
			pLast = p;
		}
	}
	~TList()
	{
		pCurr = pPrev = pStop;
		pos = 0;
		while (pFirst != pStop)
		{
			TLink<T>* curr = pFirst->pNext;
			delete pFirst;
			pFirst = curr;
			size--;
		}
		pFirst = pLast = pStop;
	}

	void InsFirst(T el)
	{
		TLink<T>* t = new TLink<T>;
		t->val = el;
		if (size == 0)
		{
			t->pNext = pStop;
			pFirst = t;
			pLast = t;
		}
		else
		{
			t->pNext = pFirst;
			pFirst = t;
		}
		size++;
	}
	void InsLast(T el)
	{
		TLink<T>* t = new TLink<T>;
		t->val = el;
		t->pNext = pStop;
		if (size == 0)
		{
			pFirst = t;
			pLast = t;
		}
		else
		{
			pLast->pNext = t;
			pLast = t;
		}
		size++;
	}
	void DelFirst()
	{
		if (size == 0)
		{
			throw 0;
		}
		else
		{
			TLink<T>* t = pFirst->pNext;
			delete pFirst;
			pFirst = t;
			size--;
		}
	}
	void DelCurr()
	{
		if (pCurr == pStop||size==0)
		{
			throw 0;
		}
		if (pCurr == pFirst)
		{
			DelFirst();
			pCurr = pFirst;
		}
		else
		{
			pPrev->pNext = pCurr->pNext;
			delete pCurr;
			pCurr = pPrev->pNext;
			size--;
		}
	}
	void InsCurr(T el)
	{
		if (pCurr == pStop)
		{
			InsLast(el);
		}
		else
		{
			if (pCurr == pFirst)
			{
				InsLast(el);
			}
			else
			{
				TLink<T>* t = new TLink<T>;
				t->val = el;
				t->pNext = pCurr;
				pPrev->pNext = t;
				pPrev = t;
				size++;
			}
		}
	}
	void Reset()
	{
		pCurr = pFirst;
	}
	void GoNext()
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}
	bool IsEnd()const
	{
		return pCurr == pStop;
	}
	int Get_Size()const
	{
		return size;
	}
	friend std::istream& operator >> (std::istream& in, TList<T>& m)
	{
		std::cout << "Ведите размер: ";
		int t;
		in >> t;
		if (t < 0)
			throw 0;
		for (int i = 0; i < t; i++)
		{
			T tmp;
			in >> tmp;
			m.InsLast(tmp);
		}
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const TList<T> m)
	{
		TLink<T>* t = m.pFirst;
		while (t != m.pStop)
		{
			out << t->val << ' ';
			t = t->pNext;
		}
		return out;
	}
};

struct TMonom
{
	double coeff;
	int x, y, z;
	TMonom(int _x = 0, int _y = 0, int _z = 0, double _coeff = 1.0);
	bool operator < (const TMonom& m)const;
	bool operator > (const TMonom& m)const;
	bool operator == (const TMonom& m)const;
	TMonom& operator = (const TMonom& m);
	TMonom operator * (const TMonom& m);
	TMonom operator * (const double qm);
	void input(char p, int m);
	std::string print(char p, int pow)const;
	friend std::istream& operator >>(std::istream& in, TMonom& m)
	{
		std::string res;
		in >> res;
		int flag = 0;
		for (int i = 0; i < res.size(); i++)
		{
			if (res[i] == 'x' || res[i] == 'y' || res[i] == 'z')
			{
				flag = 1;
			}
			if (flag == 1)
			{
				if (i + 1 < res.size())
				{
					if (res[i + 1] == '^')
					{
						m.input(res[i], res[i + 2] - '0');
					}
					else
						m.input(res[i], 1);
				}
				else
					m.input(res[i], 1);
				flag = 0;
			}
			else
			{
				if (i == 0)
				{
					std::string tmp;
					int j;
					for (j = 0; j < res.size(); j++)
					{
						if (res[j] == 'x' || res[j] == 'y' || res[j] == 'z')
						{
							break;
						}
						tmp += res[j];
					}
					i = j - 1;
					if (tmp == "-")
					{
						m.coeff = -1;
					}
					else
					{
						m.coeff = std::stod(tmp);
					}
				}
			}
		}
		return in;
	}
	friend std::ostream& operator <<(std::ostream& out, const TMonom& m)
	{
		if (m.x + m.y + m.z)
		{
			if (m.coeff != 1.0)
			{
				if (m.coeff != -1.0)
				{
					out << m.coeff;
				}
				else
				{
					out << '-';
				}
			}
				if (m.coeff != 1.0 && m.coeff != -1.0 && m.x)
				{
					out << '*';
				}
				out << m.print('x', m.x);
				if (m.x && m.y)
				{
					out << '*';
				}
				out << m.print('y', m.y);
				if (m.x && m.y && m.z)
				{
					out << '*';
				}
				out << m.print('z', m.z);

		}
		else
		{
			out << m.coeff;
		}
		return out;
	}
};
TMonom::TMonom(int _x , int _y , int _z , double _coeff )
{
	x = _x; y = _y; z = _z; coeff = _coeff;
}
bool TMonom:: operator <(const TMonom& m)const
{
	int sum = x + y + z;
	int sum_m = m.x + m.y + m.z;
	return sum < sum_m;
}
bool TMonom:: operator >(const TMonom& m)const
{
	int sum = x + y + z;
	int sum_m = m.x + m.y + m.z;
	return sum > sum_m;
}
bool TMonom:: operator ==(const TMonom& m)const
{
	return x == m.x && y == m.y && z == m.z;
}
TMonom& TMonom:: operator =(const TMonom& m)
{
	x = m.x; y = m.y; z = m.z;
	return *this;
}
TMonom TMonom:: operator *(const TMonom& m)
{
	TMonom res;
	res.x = x + m.x;
	res.y = y + m.y;
	res.z = z + m.z;
	res.coeff = coeff * m.coeff;
	return res;
}
TMonom TMonom:: operator *(const double qm)
{
	TMonom res(this->x, this->y, this->z, this->coeff);
	res.coeff=res.coeff * qm;
	return res;
}
void TMonom::input(char p, int m)
{
	switch (p)
	{
	case'x':x = m;
		break;
	case'y':y = m;
		break;
	case'z':z = m;
		break;
	}
}
std::string TMonom::print(char p, int pow)const
{
	std::string res = "";
	if (pow != 0)
	{
		if (pow > 1)
		{
			res += p;
			res += '^';
			res += std::to_string(pow);
		}
		else
		{
			res += p;
		}
	}
	return res;
}

template <class T>
class THeadList :public TList<T>
{
protected:
	TLink<T>* pHead;
public:
	THeadList();
	THeadList(const THeadList& h);
	~THeadList();
	void InsFirst(T elem);
	void DelFirst();
	void InsLast(T elem);
	void InsCurr(T elem);
	void DelCurr();
};
template<class T>
	THeadList<T>::THeadList():TList<T>()
	{
		/*TLink<T>*t = new TLink<T>;
	pHead = t;
	pStop = pHead;
	pHead->pNext = pHead;*/
		pHead = new TLink<T>;
		TList<T>::pStop = pHead;
		pHead->pNext = TList<T>::pStop;
		TList<T>::pFirst = TList<T>::pLast = TList<T>::pCurr = TList<T>::pPrev = TList<T>::pStop;
	}
	template<class T>
	THeadList<T>::THeadList(const THeadList<T>& h)
	{
		pHead = new TLink<T>;
		TList<T>::pStop = TList<T>::pFirst = TList<T>::pLast = TList<T>::pPrev = TList<T>::pCurr = pHead;
		pHead->pNext = TList<T>::pStop;
		if (h.size)
		{
			TLink<T>* prev = new TLink<T>;
			pHead->pNext = prev;
			TList<T>::pFirst = prev;
			TList<T>::pFirst->val = h.pFirst->val;
			TList<T>::pFirst->pNext = TList<T>::pStop;
			TLink<T>* curr = h.pFirst->pNext;
			while (curr != h.pStop)
			{
				TLink<T>* t = new TLink<T>;
				t->val = curr->val;
				t->pNext = TList<T>::pStop;
				prev->pNext = t;
				prev = t;
				curr = curr->pNext;
			}
			TList<T>::pLast = prev;
		}
		TList<T>::size = h.size;
		TList<T>::pos = 0;
	}
	template<class T>
	void THeadList<T>::InsFirst(T el)
	{
		TList<T>::InsFirst(el);
		pHead->pNext = TList<T>::pFirst;
	}
	template<class T>
	void THeadList<T>::DelFirst()
	{
		TList<T>::DelFirst();
		pHead->pNext = TList<T>::pFirst;
	}
	template<class T>
	void THeadList<T>::InsLast(T el)
	{
		TList<T>::InsLast(el);
		pHead->pNext = TList<T>::pFirst;
	}
	template<class T>
	void THeadList<T>::InsCurr(T el)
	{
		TList<T>::InsCurr(el);
		pHead->pNext = TList<T>::pFirst;
	}
	template<class T>
	void THeadList<T>::DelCurr()
	{
		TList<T>::DelCurr();
		pHead->pNext = TList<T>::pFirst;
	}
	template<class T>
	THeadList<T>::~THeadList()
	{
		TList<T>::~TList();
		delete pHead;
	}

class TPolinom :public THeadList <TMonom>
{
public:
	TPolinom();
	TPolinom(const TPolinom& m);
	void InsMonom(const TMonom& m);
	TPolinom& operator=(const TPolinom& m);
	TPolinom& operator += (const TPolinom& m);
	TPolinom operator + (const TPolinom& m);
	TPolinom operator * (const double qm);
	TPolinom operator * (const TMonom& m);
	TPolinom& operator *=(const TPolinom& m);
	TPolinom operator * (const TPolinom& m);
	friend std::istream& operator >> (std::istream& in, TPolinom& m)
	{
		std::cout << "Введите размер: ";
		int t;
		in >> t;
		if (t < 0)
			throw 0;
		for (int i = 0; i < t; i++)
		{
			TMonom p;
			in >> p;
			m.InsMonom(p);
		}
		return in;
	}
	friend std::ostream& operator << (std::ostream& out, TPolinom& m)
	{
		for (m.Reset(); !m.IsEnd(); m.GoNext())
		{
			out << m.pCurr->val << ' ';
		}
		if (!m.size)
			out << "Polinom empty";
		return out;
	}
};

TPolinom::TPolinom() :THeadList<TMonom>()
{
	TMonom tmp;
	tmp.z = -1;
	tmp.coeff = 0.0;
	pHead->val = tmp;
}

TPolinom::TPolinom(const TPolinom& m) :THeadList<TMonom>(m)
{
	pHead->val = m.pHead->val;
}

void TPolinom::InsMonom(const TMonom& m )
{
	Reset();
	while (true)
	{
		if (pCurr->val < m)
		{
			InsCurr(m);
			break;
		}
		if (pCurr->val == m)
		{
			if (pCurr->val.coeff + m.coeff != 0)
				pCurr->val.coeff += m.coeff;
			else
				DelCurr();
			break;
		}
		GoNext();
	}
}

TPolinom& TPolinom::operator+=(const TPolinom& p)
{
	Reset();
	TLink<TMonom>* curr = p.pFirst;
	while (curr != p.pStop)
	{
		if (pCurr->val < curr->val)
		{
			InsCurr(curr->val);
			curr = curr->pNext;
		}
		else
		{
			if (pCurr->val == curr->val)
			{
				double tmp = pCurr->val.coeff + curr->val.coeff;
				pCurr->val.coeff = tmp;
				if (tmp)
					GoNext();
				else
					DelCurr();
				curr = curr->pNext;
			}
			else
				GoNext();
		}
	}
	return *this;
}

TPolinom TPolinom::operator + (const TPolinom& m)
{
	TPolinom res(*this);
	res.Reset();
	TLink<TMonom>* curr = m.pFirst;
	while (curr != m.pStop)
	{
		if (res.pCurr->val < curr->val)
		{
			res.InsCurr(curr->val);
			curr = curr->pNext;
		}
		else
		{
			if (res.pCurr->val == curr->val)
			{
				double tmp = res.pCurr->val.coeff + curr->val.coeff;
				if (tmp)
				{
					res.pCurr->val.coeff = tmp;
					res.GoNext();
				}
				else
					res.DelCurr();
				curr = curr->pNext;
			}
			else
			{
				res.GoNext();
			}
		}
	}
	return res;
}

TPolinom TPolinom:: operator*(const double qm)
{
	if (qm == 0.0)
	{
		TPolinom res;
		return res;
	}
	else
	{
		TPolinom res(*this);// res3;
		//TMonom res1(0, 0, 0, qm);
		//res3 = res * res1;
		for (res.Reset(); !res.IsEnd(); res.GoNext())
			res.pCurr->val.coeff = res.pCurr->val.coeff * qm;
		return res;
	}
}

TPolinom TPolinom::operator*(const TMonom& m)
{
	if (m.coeff == 0.0)
	{
		TPolinom res;
		return res;
	}
	else
	{
		TPolinom res(*this);
		for (res.Reset(); !res.IsEnd(); res.GoNext())
			res.pCurr->val = res.pCurr->val * m;
		return res;
	}
}

TPolinom& TPolinom:: operator *=(const TPolinom& m)
{
	TPolinom p(*this);
	TList<TMonom>::~TList();
	for (p.Reset(); !p.IsEnd(); p.GoNext())
	{
		TLink<TMonom>* curr = m.pFirst;
		TPolinom tmp;
		while (curr != m.pStop)
		{
			tmp.InsLast(p.pCurr->val * curr->val);
			curr = curr->pNext;
		}
		*this += tmp;
	}
	return *this;
}

TPolinom TPolinom:: operator *(const TPolinom& m)
{
	TPolinom res;
	if (m.size)
	{
		for (Reset(); !IsEnd(); GoNext())
		{
			TLink<TMonom>* curr = m.pFirst;
			TPolinom tmp;
			while (curr != m.pStop)
			{
				tmp.InsLast(pCurr->val * curr->val);
				curr = curr->pNext;
			}
			res += tmp;
		}
	}
	return res;
}

TPolinom& TPolinom:: operator=(const TPolinom& m)
{
	if (this != &m)
	{
		if (!m.size)
		{
			TList<TMonom>::~TList();
		}
		else
		{
			if (size < m.size)
			{
				int tmp = m.size - size;
				TLink<TMonom>* curr = pLast;
				for (int i = 0; i < tmp; i++)
				{
					TLink<TMonom>* new_elem = new TLink<TMonom>;
					curr->pNext = new_elem;
					curr = new_elem;
					curr->pNext = pStop;
				}
				pFirst = pHead->pNext;
				pLast = curr;
				curr = m.pFirst;
				for (Reset(); !IsEnd(); GoNext())
				{
					pCurr->val = curr->val;
					curr = curr->pNext;
				}
			}
			else
			{
				TLink<TMonom>* curr = m.pFirst;
				Reset();
				while (true)
				{
					pCurr->val = curr->val;
					curr = curr->pNext;
					if (curr == m.pStop)
						break;
					GoNext();
				}
				pLast = pCurr;
				GoNext();
				while (!IsEnd())
				{
					TLink<TMonom>* t = pCurr;
					GoNext();
					delete t;
				}
				pLast->pNext = pStop;
				pPrev = pLast;
			}
		}
	}
	size = m.size;
	pos = 0;
	return *this;
}