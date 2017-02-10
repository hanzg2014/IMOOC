class MyQueue
{
	public:
		MyQueue(int queueCapacity); //
		~MyQueue();
		void ClearQueue();		//Clear a queue
		bool QueueEmpty() const;
		int QueueLength() const;
		bool QueueFull() const;
		bool EnQueue(int element);	//Element in
		bool DeQueue(int &element);	//Element out
		void QueueTraverse();
	private:
		int *m_pQueue; 	//pointer to a queue
		int m_iQueueLen;	//current number of elements in a queue
		int m_iQueueCapacity;	//size of a queue
		int m_iHead;
		int m_iTail;
};
