#include "Customer1.h"

class MyQueue
{
	public:
		MyQueue(int queueCapacity); //
		~MyQueue();
		void ClearQueue();		//Clear a queue
		bool QueueEmpty() const;
		int QueueLength() const;
		bool QueueFull() const;
		bool EnQueue(Customer element);	//Element in
		bool DeQueue(Customer &element);	//Element out
		void QueueTraverse();
	private:
		Customer *m_pQueue; 	//pointer to a queue
		int m_iQueueLen;	//current number of elements in a queue
		int m_iQueueCapacity;	//size of a queue
		int m_iHead;
		int m_iTail;
};