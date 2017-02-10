class List
{

public:
	List(int size);
	~List();
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, int *e);
	int LocateElem(int *e);
	bool PriorElem(int *currentElem, int *preElem);
	bool NextElem(int *currentElem, int *nextElem);
	void ListTraverse();
	bool ListInsert(int i, int *e);
	bool ListDelete(int i, int *e);
    

private:
	int * m_pList;
	int m_iSize;
	int m_iLength;


};