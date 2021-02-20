#pragma once
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
	int size;
public:
	TList()
	{
		pStop = NULL;
		pFirst = pStop;
		pLast = pStop;
		pCurr = pStop;
		pPrev = pStop;
		size = 0;
	}
	~TList()
	{

	}
};