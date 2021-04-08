#include <iostream>
#include <ctime>

using namespace std;

unsigned uiACounter = 0;

template <typename T>
class List
{
	class ListElem
	{
	public:
		ListElem(T t) : m_Elem(t) {}
		ListElem(const ListElem &) = delete;
		T m_Elem;
		ListElem *m_pNext = nullptr;
	};

public:
	//**M�glichkeit finden vom Listen-Destruktor auf Destruktor von**//
	//**Klasse A zuzugreifen, damit Counter gesl�scht werden kann!**//

	~List()
	{ //**Destruktor f�r Listenklasse unvollst�ndig**//

		ListElem *temp = m_pHead;
		ListElem *next = nullptr;
		while (temp != nullptr)
		{
			next = temp->m_pNext;
			temp = nullptr;
			temp = next;
		}
		m_pHead = nullptr;
	}

	//**Methode zum L�schen der Listenelemente in removeAll-Methode**//

	void remove(const T &t)
	{
		if (m_pHead->m_pNext)
		{
			ListElem *tmp;
			tmp = m_pHead;
			m_pHead = m_pHead->m_pNext;
			delete tmp;
			tmp = nullptr;
		}
		else
		{
			delete m_pHead;
			m_pHead = nullptr;
		}
	}

	//**F�gt Listenelemente in die Liste ein mit push_back**//

	void insert(const T &t)
	{
		ListElem *temp = new ListElem(t);
		if (!m_pHead)
		{
			m_pHead = temp;
		}
		else
		{
			ListElem *pTmp = m_pHead;
			while (pTmp->m_pNext)
				pTmp = pTmp->m_pNext;
			pTmp->m_pNext = temp;
			pTmp->m_pNext->m_pNext = nullptr;
		}
	}

	void print(std::ostream &os, unsigned uiNums) const
	{
		ListElem *pTmp = m_pHead;
		for (; pTmp && uiNums > 0; pTmp = pTmp->m_pNext, --uiNums)
			os << pTmp->m_Elem << " ";
		if (pTmp)
			os << "...";
	}

	unsigned size() const
	{
		unsigned uiRes = 0;
		for (ListElem *pTmp = m_pHead; pTmp; pTmp = pTmp->m_pNext)
			++uiRes;
		return uiRes;
	}

	List<T>& operator=(const List<T>& rhs)
	{
		ListElem *pTmp = rhs.m_pHead;
		while (pTmp != nullptr)
		{
			insert(T(pTmp->m_Elem));
			--uiACounter;
			pTmp = pTmp->m_pNext;
		}	
		return *this;
	}
private:
	ListElem *m_pHead = nullptr;
};

class A
{

public:
	A(int i) : m_i(i) { ++uiACounter; }

	A(const A &crArg) : m_i(crArg.m_i) { ++uiACounter; }

	~A()
	{
		--uiACounter;
	}

	friend std::ostream &operator<<(std::ostream &os, const A &crArg)
	{
		return os << crArg.m_i;
	}

	friend bool operator==(const A &crArg1, const A &crArg2)
	{
		return crArg1.m_i == crArg2.m_i;
	}

private:
	int m_i;
};

void print(string msg, List<A> x)
{
	cout << msg << " ";
	x.print(cout, 10);
	cout << endl;
}

void removeAll(List<A> &x, int *pNums)
{
	for (unsigned ui = 0; x.size() > 0; ++ui)
		x.remove(A(pNums[ui]));
}

int main()
{
	{
		srand(time(nullptr)); // setzt den Anfangszustand f�r die Zufallswertberechnung
		unsigned uiCnt = 0;
		cout << "Bitte Anzahl der Elemente eingeben: ";
		cin >> uiCnt;
		List<A> l1, l2;
		int *pNums = new int[uiCnt];
		for (unsigned ui = 0; ui < uiCnt; ++ui)
		{
			pNums[ui] = rand();
			l1.insert(A(pNums[ui]));
		}
		print("l1: ", l1);
		print("l2: ", l2);
		l2 = l1;
		removeAll(l1, pNums);
		print("l1: ", l1);
		print("l2: ", l2);
		delete[] pNums;
	}
	cout << "Anzahl der noch bestehenden A Objekte (sollte 0 sein): " << uiACounter << endl;
	return 0;
}
