#ifndef Sorted_LINKED_LIST_H
#define Sorted_LINKED_LIST_H


/**
*   Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
    T data;   // ��忡�� ������ ���ڵ�
    NodeType* next;   // ���� ��带 ����Ű�� ������
};


/**
*   Simple unsorted list class for managing items.
*/
template <typename T>
class SortedLinkedList
{
public:

    SortedLinkedList(); // ������

    ~SortedLinkedList(); // �Ҹ���

    /**
    *   @brief   Initialize list to empty state.
    *   @pre   None
    *   @post   List is empty.
    */
    void MakeEmpty(); //List�� ���

    /**
    *   @brief   Get number of elements in the list.
    *   @pre   None.
    *   @post   Function value = number of elements in list.
    *   @return   Number of elements in this list.
    */
    int GetLength() const; // ����Ʈ�� �����ϰ� �ִ� item ���� ��ȯ

    /**
    *   @brief   Add item into appropriate spot of this list.
    *   @pre   List is not full. item is not in list.
    *   @post   Item is inserted in this list.
    *   @return   1 if this function works well, otherwise 0.
    */
    int Add(T item); // ���ο� ���ڵ带 ����Ʈ�� ����

    /**
    *   @brief   Delete item from this list.
    *   @pre   List is not empty. the item exists in list.
    *   @post   Item is deleted from this list.
    *   @return   1 if this function works well, otherwise 0.
    */
    int Delete(T item);

    /**
    *   @brief   Change value of item which is in this list.
    *   @pre   List is not empty. the item exists in list.
    *   @post   Item's value is changed.
    *   @return   1 if this function works well, otherwise 0.
    */
    int Replace(T item);

    /**
    *   @brief   Retrieve list element whose key matches item's key (if present).
    *   @pre   Key member of item is initialized.
    *   @post   If there is an element whose key matches with item's key then the element's record is copied to the item.
    *   @return   1 if any element's primary key matches with item's, otherwise 0.
    */
    int Get(T& item); // Primary key�� �������� �����͸� �˻��ϰ� �ش� ������ ������

    /**
    *   @brief   Initialize current pointer for an iteration through the list.
    *   @pre   None.
    *   @post   current pointer is prior to list. current pointer has been initialized.
    */
    void ResetList(); // ���ڵ� ������ �ʱ�ȭ

    /**
    *   @brief   Get the next element in list.
    *   @pre   current pointer is defined. Element at current pointer is not last in list.
    *   @post   current pointer is updated to next position. item is a copy of element at current pointer.
    */
    void GetNextItem(T& item);
    // Current Pointer�� ���� node�� ����Ű���� �̵� �� �ش� ���ڵ带 ������.

 // ���ڵ��� data�� ����ϴ� �Լ�
    void DIsplayOnScreen();

    bool operator ==(T& item);

    // ���� �����Ϳ����� data ���
    int GetStudentID();

    //friend ostream& operator << (ostream& os, const SortedLinkedList& item);

private:
    NodeType<T>* m_pList;   // ����Ʈ ������
    NodeType<T>* m_pCurPointer;   // current pointer
    int m_nLength;   // ����Ʈ�� ����� ���ڵ� ��
};

/*ostream& operator << (ostream& os, const SortedLinkedList& item)
{
    os << item. << endl;
    return os;
}*/

// Class constructor
template <typename T>
SortedLinkedList<T>::SortedLinkedList()
{
    m_nLength = 0;
    m_pList = NULL;
    m_pCurPointer = NULL;
}


// Class destructor
template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
    //����Ʈ���� ��� node ����
    MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void SortedLinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    // ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
    /*
    NodeType<T>* tempPtr;
    tempPtr = m_pList;
     while (m_pList != NULL)
     {
         tempPtr = m_pList;
         m_pList = m_pList->next;
       delete tempPtr;
     }
    */
    m_pCurPointer = 0;
    m_pList = 0;

    m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int SortedLinkedList<T>::GetLength() const
{
    return m_nLength;
}


// Add item into this list.
template <typename T>
int SortedLinkedList<T>::Add(T item)
{
    // ����Ʈ �ʱ�ȭ
    ResetList();

    // ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
    NodeType<T>* node = new NodeType<T>;
    NodeType<T>* pre;
    T dummy;
    bool bFound = false;

    // node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
    node->data = item;
    node->next = NULL;

    // list �� node �� �������� �ʴ� ���
    if (!m_nLength)
    {
        m_pList = node;
    }
    // list �� node �� �ϳ� �̻� �����ϴ� ���
    else
    {
        // ���� ������ node �� �̵� �� ����
        while (1)
        {
            // ���� ��带 ����Ű�� ������ ����
            pre = m_pCurPointer;

            // iteration �� �̿��� node ������ ����.
            GetNextItem(dummy);

            if (m_pCurPointer->data > node->data)
            {
                if (pre == NULL)
                {
                    node->next = m_pCurPointer;
                    m_pList = node;
                    break;
                }   //���� �ڸ� �� ���Ұ� �������� ���� �� ù��° ���ҷ� ����.
                node->next = m_pCurPointer;
                pre->next = node;
                break;
            }   //���� ����Ű�� ������ data���� node�� data������ Ŭ ��� pre ���ڸ��� ����.

            // node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
            if (m_pCurPointer->next == NULL)
            {
                // ������ node �� ���ο� node ����
                m_pCurPointer->next = node;
                break;
            }
        }
    }

    m_nLength++;

    return 1;
}

//Delete item from this list.
template <typename T>
int SortedLinkedList<T>::Delete(T item)
{
    bool moreToSearch, found;
    NodeType<T>* pre = NULL;   //���� ����

    m_pCurPointer = m_pList;
    found = false;
    moreToSearch = (m_pCurPointer != NULL);   //���� �ʱ�ȭ

    while (moreToSearch && !found)   //����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
    {
        if (item == m_pCurPointer->data)   //���� ����Ű�� ������ ���� item�� ���� ��ġ�� ��
        {
            found = true;   //ã�����Ƿ� found �� ����
            if (pre == NULL)
                m_pList = m_pCurPointer->next;   //�׸� ������ �ٸ� ���Ұ� ���� �� �׸��� ���� ���Ҹ� ù��° ���ҷ� �Ѵ�.
            else
            {
                pre->next = m_pCurPointer->next;
                delete m_pCurPointer;
            }   //������ ������ ���� ���Ҹ� '����Ű�� �׸��� ���� ����'�� �ٲ۴�.
            m_nLength--;   //����Ʈ�� ���̸� 1 �ٿ��ش�.
        }
        else
        {
            pre = m_pCurPointer;
            m_pCurPointer = m_pCurPointer->next;
            moreToSearch = (m_pCurPointer != NULL);
        }   //��ġ���� ���� �� ���� ���Ҹ� ����Ų��. ��, pre�� ������ ���Ҹ� ����Ų��.
    }

    if (found)
        return 1;
    else
        return 0;   //������ �����ϸ� 1, �ƴϸ� 0�� �����Ѵ�.
}

//Change value of item which is in this list.
template <typename T>
int SortedLinkedList<T>::Replace(T item)
{
    bool moreToSearch, found;
    NodeType<T>* location;   //���� ����

    location = m_pList;
    found = false;
    moreToSearch = (location != NULL);   //���� �ʱ�ȭ

    while (moreToSearch && !found)   //����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
    {
        if (item == location->data)
        {
            found = true;
            location->data = item;
        }   //��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� ����Ʈ�� �׸� item�� �������ش�.
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }   //ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
    }
    if (found)
        return 1;
    else
        return 0;   //������ �����ϸ� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int SortedLinkedList<T>::Get(T& item)
{
    bool moreToSearch, found;
    NodeType<T>* location;   //���� ����

    location = m_pList;
    found = false;
    moreToSearch = (location != NULL);   //���� �ʱ�ȭ

    while (moreToSearch && !found)   //����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
    {
        if (item == location->data)
        {
            found = true;
            item = location->data;
        }   //��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� item�� �ش� �׸��� �������ش�.
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }   //ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
    }

    if (found)
        return 1;
    else
        return 0;   //ã���� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}


// Initializes current pointer for an iteration through the list.
template <typename T>
void SortedLinkedList<T>::ResetList()
{
    // current pointer �ʱ�ȭ
    m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void SortedLinkedList<T>::GetNextItem(T& item)
{
    // current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
    if (m_pCurPointer == NULL)
    {
        m_pCurPointer = m_pList;
    }
    else
        //current position �� ���� ���� �̵�
        m_pCurPointer = m_pCurPointer->next;

    //item �� current position �� info �� ����
    item = m_pCurPointer->data;
}

template <typename T>
bool SortedLinkedList<T>::operator==(T& item)
{
    return (this->Get() == item.Get());
}

// ���ڵ��� data�� ����ϴ� �Լ�
template <typename T>
void SortedLinkedList<T>::DIsplayOnScreen()
{
    int count = 0;

    // ����Ʈ�� ����ִٸ�
    if (m_pList == NULL) {
        cout << "record is empty! " << endl;
    }
    // ����Ʈ�� node�� �ϳ��� �ִٸ�
    else {
        T item;
        m_pCurPointer = m_pList; // ù��° node�� ����Ű����.
        while (count < m_nLength)   //����Ʈ�� ���� �ƴ϶�� �ݺ�.
        {
            item = m_pList->data;
            cout << item << endl; // ����Ʈ�� data�� ���
            m_pList = m_pList->next; // ���� node�� �̵�
            count++;
        }
    }
}

template <typename T>
int SortedLinkedList<T>::GetStudentID() {

    // ����Ʈ�� ����ִٸ� 
    if (m_pList == NULL) {
        cout << "list is empty! " << endl;
        return 0;
    }
    // ����Ʈ�� node�� �ϳ��� �ִٸ�
    else {
        if (m_pCurPointer == NULL) {
            m_pCurPointer = m_pList;
            return m_pList->data;
        }
        else {
            int item = 0;
            item = m_pCurPointer->data;
            m_pCurPointer = m_pCurPointer->next;
            return item;
        }
    }
}

#endif   // Sorted_LINKED_LIST