class Array
{
public:
	Array();
	Array(const Array & arr);
	~Array();
	void setCount(int _count);
	int getCount();

private:
	int m_iCount;
};

