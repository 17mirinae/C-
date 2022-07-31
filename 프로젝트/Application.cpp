#include "Application.h"

// Program driver.
void Application::Run()
{
    while (1)
    {
        m_nCurCommand = GetCommand();

        switch (m_nCurCommand)
        {
        case 1:      // inset item
            InsertItem();
            break;
        case 2:      // display all items
            DisplayAll();
            break;
        case 3:      // make the list empty
            MakeEmpty();
            break;
        case 4:      // retrieves item
            RetrieveItem();
            break;
        case 5:      // delete item
            DeleteItem();
            break;
        case 6:      // change value of an item
            Update();
            break;
        case 7:      // �������� ���� �ð� ������ �˻� �� ����
            SearchTime();
            break;
        case 8:      // �������� �̺�Ʈ���� �˻�
            SearchEvent();
            break;
        case 9: // �������� ������� �˻�
            SearchPeople();
            break;
        case 10: // �������� ��Һ��� �˻�
            SearchPlace();
        case 0:   // quit
            return;
        default:
            cout << "\tIllegal sellection...\n";
            break;
        }
    }
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
    int command;
    cout << endl << endl;
    cout << "\t---ID -- Command ----- " << endl;
    cout << "\t   1 : Insert Item" << endl;
    cout << "\t   2 : Display all Item" << endl;
    cout << "\t   3 : Make empty list" << endl;
    cout << "\t   4 : Search item by ID" << endl;
    cout << "\t   5 : Delete Item" << endl;
    cout << "\t   6 : Update item" << endl;
    cout << "\t   7 : �����ð����� �˻�" << endl;
    cout << "\t   8 : �̺�Ʈ ���� �˻�" << endl;
    cout << "\t   9 : ��� ���� �˻�" << endl;
    cout << "\t  10 : ��� ���� �˻�" << endl;
    cout << "\t   0 : Quit " << endl;

    cout << endl << "\t Choose a Command--> ";
    cin >> command;
    cout << endl;

    return command;
}


// Add new record into list.
int Application::InsertItem()
{
    ItemType item;
    item.SetRecordFromKB();

    m_Contents.Add(item);
    DisplayAll();

    return 1;
}

//Delete record into list.
int Application::DeleteItem()
{
    ItemType item;

    cout << "Delete item : ";
    item.SetNameFromKB();   //������ �׸��� id�� �Է�

    if (m_Contents.Delete(item))
    {
        cout << "Deleted " << item.GetName() << " Successfully." << endl;
        return 1;
    }   //������ �����ϸ� ���� �޽����� ���
    else
    {
        cout << item.GetName() << " is not found." << endl;
        return 0;
    }   //�ش� �׸��� ã�� �� ������ ã�� ���ߴٴ� �޽����� ���
}


// Display all records in the list on screen.
void Application::DisplayAll()
{
    ItemType data;

    cout << "\n\tCurrent list" << endl;

    m_Contents.MakeEmpty();   // ����Ʈ �ʱ�ȭ
    // list�� ��� �����͸� ȭ�鿡 ���
    for (int i = 0; i < m_Contents.GetLength(); i++)
    {
        m_Contents.GetNextItem(data);
        data.DisplayRecordOnScreen();
        cout << "\n\t\t|\n\n";
    }
}


//Make empty list.
int Application::MakeEmpty()
{
    m_Contents.MakeEmpty();
    cout << "List is now empty.";
    return 0;
}


// Retrieve item in the list.
int Application::RetrieveItem()
{
    ItemType item;
    cout << "Enter a item for search (primary key) : ";
    //cin >> item;
    item.SetNameFromKB();

    if (m_Contents.Get(item))
    {
        cout << "Target item exists in the list." << endl;
        item.DisplayRecordOnScreen();
        return 1;
    }
    else
    {
        cout << "Target item is not in the list." << endl;
        return 0;
    }
}

//Change item's value in the list.
int Application::Update()
{
    ItemType item;
    cout << "Enter a item's ID for search : ";
    item.SetNameFromKB();   //������ ������ �׸��� id�� �Է�

    if (!m_Contents.Get(item))
    {
        cout << "Target item is not in the list." << endl;
        return 0;
    }   //�ش� �׸��� ����Ʈ�� ������ ã�� ���ߴٴ� �޽��� ���
    else
    {
        item.SetRecordFromKB();   //������ ���� �Է�
        if (m_Contents.Replace(item))   //�Է¹��� ������ ����Ʈ�� �ݿ�
            cout << "���� �Ϸ�" << endl;
        else
            cout << "���� ����" << endl;
    }
    return 1;
}

int Application::SearchTime() {

}

// event���� �˻� �� ����
int Application::SearchEvent() {

}

// ������� �˻� �� ����
int Application::SearchPeople() {

}

// ��Һ��� �˻� �� ����
int Application::SearchPlace() {

}

// �ϳ� �̻��� Ű ���� �˻�
int Application::BothType() {

}