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
        case 7:      // 콘텐츠를 생성 시간 순으로 검색 및 저장
            SearchTime();
            break;
        case 8:      // 콘텐츠를 이벤트별로 검색
            SearchEvent();
            break;
        case 9: // 콘텐츠를 사람별로 검색
            SearchPeople();
            break;
        case 10: // 콘텐츠를 장소별로 검색
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
    cout << "\t   7 : 생성시간으로 검색" << endl;
    cout << "\t   8 : 이벤트 별로 검색" << endl;
    cout << "\t   9 : 사람 별로 검색" << endl;
    cout << "\t  10 : 장소 별로 검색" << endl;
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
    item.SetNameFromKB();   //삭제할 항목의 id를 입력

    if (m_Contents.Delete(item))
    {
        cout << "Deleted " << item.GetName() << " Successfully." << endl;
        return 1;
    }   //삭제에 성공하면 성공 메시지를 출력
    else
    {
        cout << item.GetName() << " is not found." << endl;
        return 0;
    }   //해당 항목을 찾을 수 없으면 찾지 못했다는 메시지를 출력
}


// Display all records in the list on screen.
void Application::DisplayAll()
{
    ItemType data;

    cout << "\n\tCurrent list" << endl;

    m_Contents.MakeEmpty();   // 리스트 초기화
    // list의 모든 데이터를 화면에 출력
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
    item.SetNameFromKB();   //정보를 수정할 항목의 id를 입력

    if (!m_Contents.Get(item))
    {
        cout << "Target item is not in the list." << endl;
        return 0;
    }   //해당 항목이 리스트에 없으면 찾지 못했다는 메시지 출력
    else
    {
        item.SetRecordFromKB();   //나머지 정보 입력
        if (m_Contents.Replace(item))   //입력받은 값들을 리스트에 반영
            cout << "수정 완료" << endl;
        else
            cout << "수정 실패" << endl;
    }
    return 1;
}

int Application::SearchTime() {

}

// event별로 검색 및 저장
int Application::SearchEvent() {

}

// 사람별로 검색 및 저장
int Application::SearchPeople() {

}

// 장소별로 검색 및 저장
int Application::SearchPlace() {

}

// 하나 이상의 키 조합 검색
int Application::BothType() {

}