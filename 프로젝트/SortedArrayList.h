#pragma once
#define ADDSIZE 5
template <typename T>
class SortedArrayList
{
private:
	T * m_Array;		///< list array.
	int m_Length;		///< number of elements in list.
	int m_CurPointer;	///< iterator pointer.
	int m_MaxSize;		///< max size.

public:
	SortedArrayList() {
		m_MaxSize = ADDSIZE;
		m_Length = 0;
		ResetList();
		m_Array = new T[m_MaxSize];
	}
	~SortedArrayList(){ delete[] m_Array; }

	void DisplayOnScreen() {
		for (int i = 0; i < m_Length; i++) {
			cout << m_Array[i].GetId() << endl;
		}
	}

	void MakeEmpty(){ m_Length = 0; }
	int GetLength(){ return m_Length; }
	bool IsFull(){
		if (m_Length > m_MaxSize - 1)
			return true;
		else
			return false;
	}

	void ResetList(){ m_CurPointer = -1; }
	int GetNextItem(T& data){
		m_CurPointer++;
		if (m_CurPointer == m_Length)
			return -1;
		data = m_Array[m_CurPointer];

		return m_CurPointer;
	}

	int Add(const T& inData){
		if (IsFull()) {
			T* tmpList = new T[m_Length];
			for (int i = 0; i < m_Length; ++i) {
				tmpList[i] = m_Array[i];
			}
			delete[] m_Array;
			m_MaxSize += ADDSIZE;
			m_Array = new T[m_MaxSize];
			for (int i = 0; i < m_Length; ++i) {
				m_Array[i] = tmpList[i];
			}
			delete[] tmpList;
		}

		if (m_Length == 0)
		{
			m_Array[m_Length] = inData;
			m_Length++;
			return 1;
		}
		else
		{
			for (int i = 0; i < m_Length; i++)
			{
				if (m_Array[i] < inData) {
					if (i == m_Length - 1)
					{
						m_Array[m_Length] = inData;
						m_Length++;
						return 1;
					}
				}
				else if (m_Array[i] > inData) {
					for (int j = m_Length; j > i; j--)
					{
						m_Array[j] = m_Array[j - 1];
					}
					m_Array[i] = inData;
					m_Length++;
					return 1;
				}
				else {
					return -1;
				}
			}
		}
		return 0;
	}
	int Get(T& data){
		for (int i = 0; i < m_Length; i++)
		{
			if (m_Array[i] == data)
			{
				data = m_Array[i];
				return 1;
			}
		}
		return 0;
	}
	int Delete(T data) {
		for (int i = 0; i < m_Length; i++)
		{
			if (m_Array[i] == data)
			{
				for (int j = i; j < m_Length - 1; j++)
				{
					m_Array[j] = m_Array[j + 1];
				}
				m_Length--;
				return 1;
			}
		}
		return 0;
	}
	int Replace(const T& data) {
		for (int i = 0; i < m_Length; i++)
		{
			if (m_Array[i] == data)
			{
				m_Array[i] = data;
				return 1;
			}
		}
		return 0;
	}

	int GetByBinarySearch(T& data) {
		int first = 0;
		int last = m_Length - 1;
		bool found = false;
		while (first <= last && !found)
		{
			int mid = (first + last) / 2;
			if (data < m_Array[mid]) {
				last = mid - 1;
			}
			else if (data > m_Array[mid]) {
				first = mid + 1;
			}
			else {
				data = m_Array[mid];
				found = true;
				return 1;
			}
		}
		return 0;
	}

	bool operator < (T& item) {
		return (this->Get() < item.Get());
	}
	bool operator > (T& item) {
		return (this->Get() > item.Get());
	}
};
