#include <iostream>
#include <string>
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	int key, size;
	string originalText;
	char originalLetters[256], encryptedText[256], decryptedText[256];
	char alphabet[33] = {'А','Б','В','Г','Д','Е','Ё','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ','Ы','Ь','Э','Ю','Я'};

  
	cout << "Введите исходный текст: ";
	getline(cin, originalText);
	cout << "Введите ключ: ";
	cin >> key;

	size = originalText.size();

	//исходный алфавит
	cout << endl;
	for (int i = 0; i < 33; i++)
	{
		cout << alphabet[i];
	}
	cout << "| исходный алфавит" << endl;

	//алфавит для шифрования
	for (int i = 0; i < 33; i++)
	{
		if ((i+key) < 33)
			cout << alphabet[i+key];
		else
			cout << alphabet[(i+key)%33];
	}
	cout << "| подстановочный алфавит" << endl;

	//преобразование строки в массив
	for (int i = 0; i <= size; i++)
	{
		originalLetters[i] = (char)originalText[i];
		if (originalLetters[i] == -16)//получение буквы "Ё"
		{
			originalLetters[i] = 'Ё' - 64;//преобразование кодировки буквы "Ё"
		}
		if (originalLetters[i] == ' ' || originalLetters[i] == '.' || originalLetters[i] == ',' || originalLetters[i] == '-')
			originalLetters[i] = originalLetters[i] - 64;
		originalLetters[i] = originalLetters[i] + 64;//64 - особенности преобразования
	}
	
	//шифрование
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

	//вывод результата
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << encryptedText[i];
	}
	cout << "| зашифрованный текст" << endl;

	//расшифровка
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

	//вывод результата
	for (int i = 0; i < size; i++)
	{
		cout << decryptedText[i];
	}
	cout << "| расшифрованный текст" << endl;

	system("pause");
}
