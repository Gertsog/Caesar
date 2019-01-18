#include <iostream>
#include <string>
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	int key, size;
	string originalText;
	char originalLetters[256], encryptedText[256], decryptedText[256];
	char alphabet[33] = {'�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�'};

  
	cout << "������� �������� �����: ";
	getline(cin, originalText);
	cout << "������� ����: ";
	cin >> key;

	size = originalText.size();

	//�������� �������
	cout << endl;
	for (int i = 0; i < 33; i++)
	{
		cout << alphabet[i];
	}
	cout << "| �������� �������" << endl;

	//������� ��� ����������
	for (int i = 0; i < 33; i++)
	{
		if ((i+key) < 33)
			cout << alphabet[i+key];
		else
			cout << alphabet[(i+key)%33];
	}
	cout << "| �������������� �������" << endl;

	//�������������� ������ � ������
	for (int i = 0; i <= size; i++)
	{
		originalLetters[i] = (char)originalText[i];
		if (originalLetters[i] == -16)//��������� ����� "�"
		{
			originalLetters[i] = '�' - 64;//�������������� ��������� ����� "�"
		}
		if (originalLetters[i] == ' ' || originalLetters[i] == '.' || originalLetters[i] == ',' || originalLetters[i] == '-')
			originalLetters[i] = originalLetters[i] - 64;
		originalLetters[i] = originalLetters[i] + 64;//64 - ����������� ��������������
	}
	
	//����������
	for (int i = 0; i <= size; i++)
	{
		if (originalLetters[i] == ' ' || originalLetters[i] == '.' || originalLetters[i] == ',' || originalLetters[i] == '-')
			encryptedText[i] = originalLetters[i];
		else
		{
			for (int j = 0; j < 33; j++)
			{
				if (originalLetters[i] == alphabet[j])
					encryptedText[i] = alphabet[(j+key)%33];
			}
		}
	}

	//����� ����������
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << encryptedText[i];
	}
	cout << "| ������������� �����" << endl;

	//�����������
	for (int i = 0; i < size; i++)
	{
		if (encryptedText[i] == ' ' || encryptedText[i] == '.' || encryptedText[i] == ',' || encryptedText[i] == '-')
			decryptedText[i] = encryptedText[i];
		else
		{
			for (int j = 0; j < 33; j++)
			{
				if (encryptedText[i] == alphabet[j])
				{
					decryptedText[i] = alphabet[(j - key + 33) % 33];
				}	
			}
		}
	}

	//����� ����������
	for (int i = 0; i < size; i++)
	{
		cout << decryptedText[i];
	}
	cout << "| �������������� �����" << endl;

	system("pause");
}
