#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

void readFile(FILE *pF)
{
	char str[256];
	while (!feof(pF))   
	{
		fgets(str, 256, pF);  
		cout <<"	"<< str;
	}

}

void PovtorStroki(FILE *pF, FILE *pG)
{
	char str[256], str1[256];
	bool s;
	while (!feof(pF))
	{
		s = true;
		fgets(str, 256, pF);
		while (!feof(pG))
		{

			fgets(str1, 256, pG);
			if (strcmp(str, str1) == 0)
				s = false;
			}
		if (s == true)
			cout <<"	"<< str;
	}
}


int main()
{
	FILE *pF, *pG;
	char name1[50] = "File1.txt";
	char name2[50] = "File2.txt";
	char s1[256], s2[256];
	
	fopen_s(&pF,name1, "rt");
	if (pF == NULL)  // Открываем файл для чтения в текстовом режиме
	{
		printf("Error open file");
		return 1;
	}
	else
	{
		cout << name1<<endl;
		readFile(pF);
	}

	fopen_s(&pG, name2, "rt");
	if (pG == NULL)  // Открываем файл для чтения в текстовом режиме
	{
		printf("Error open file");
		return 1;
	}
	else
	{
		cout << endl<< name2<<endl;
		readFile(pG);
	}

	rewind(pF);
	rewind(pG);
	cout <<endl<< "file1:" << endl;
	PovtorStroki(pF, pG);

	rewind(pF);
	rewind(pG);
	cout << endl<< "file2:" << endl;
	PovtorStroki(pG, pF);
	
	fclose(pF);
	fclose(pG);
	cout << endl;
	system("pause");
	return 0;
}