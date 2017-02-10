class Array
{
public:
	Array(int len);
	~Array();	
	//Array& setLen(int len);
	Array* setLen(int len);
  	int getLen();
 	//Array& printInfo();
 	Array* printInfo();

private:
	int len;
};

