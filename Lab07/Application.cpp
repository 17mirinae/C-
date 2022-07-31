#include "Application.h"

// Program driver.
void Application::Run()
{
	ItemType* newData;

	while (1)
	{
		newData = NULL;
		m_nCurCommand = GetCommand();

		switch (m_nCurCommand)
		{
		case 1:		
			newData = new Picture();
			//AddContents(*newData);
			break;
		case 2:
			newData = new Video();
		//	AddContents(*newData);
			break;
		case 3:
			newData = new Music();
		//	AddContents(*newData);
			break;
		case 4:
			DisplayAll();
			break;

		case 0:	// quit
			return;

		default:
			cout << "\t��ȿ���� �ʽ��ϴ�.\n";
		}
		
		if (newData != NULL)
		{
			newData->Read();
			m_Contents.Add(newData);
		}
		
		cout << "\n";
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : ���� ������ ����" << endl;
	cout << "\t   2 : ���� ������ ����" << endl;
	cout << "\t   3 : ���� ������ ����" << endl;
	cout << "\t   4 : ��� ������ ���� ���" << endl;
	
	cout << "\t   0 : ���� " << endl;
	cout << "\t------------------------" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Display all records in the list on screen.
void Application::DisplayAll()
{
	ItemType* data;

	cout << "\n\tContents Current list" << endl;

	DoublyIterator<ItemType*> itor(m_Contents);

	data = itor.Next();
	while(itor.NextNotNull())
	{
		data->play();
		data = itor.Next();
	}


}
/*
int Application::AddContents(ItemType item)
{
	item.Read();
	
	m_Contents.Add(item); // ML�� �߰�

	return 1;
}
*/



