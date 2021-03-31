#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[50];
	char surname[50];
	time_t birth;
}person;

void read_person(person* p)
{
	int time;
	printf("Podaj imie: ");
	scanf_s("%s", p->name, (unsigned)sizeof(p->name));
	printf("Podaj nazwisko: ");
	scanf_s("%s", p->surname, (unsigned)sizeof(p->surname));
	printf("Podaj date urodzenia(unix timestamp): ");
	if (scanf_s("%d", &time) == 1)
		p->birth = (time_t)time;

}

void print_person(person* p)
{
	char text[50];
	ctime_s(text, 50, &p->birth);
	printf("%s %s, born %s\n",p->name, p->surname, text);
}

void load_persons()
{
	person arr[5];
	for (int i = 0; i < 5; ++i)
	{
		printf("---insert data for person #%d---", i);
		read_person(&arr[i]);
	}
	FILE* f;
	fopen_s(&f,"output.binary", "w");
	if (f)
	{
		for (int i = 0; i < 5; ++i)
			fwrite(&arr[i], sizeof(person), 1, f);
		fclose(f);
	}
}

void read_persons()
{
	FILE* f;
	person* arr;
	person tmp;
	int n = 0;
	fopen_s(&f, "output.binary", "r");
	if (f)
	{
		while (fread(&tmp, sizeof(person),1, f)) ++n;
		rewind(f);

		arr = malloc((n+2) * sizeof(person));
		int i = 0;
		for (i = 0; i < n; ++i)
		{
			fread(&arr[i], sizeof(person), 1, f);
			print_person(&arr[i]);
		}

		person p = { "Brad", "Pitt", 1632235486 };
		arr[i++] = p;
		person tmp2 = { "Johny", "Deep", 1638546486 };
		arr[i] = tmp2;

		fclose(f);

		fopen_s(&f, "output.binary", "w");
		if (f)
		{
			for (int i = 0; i < n+2; ++i)
				fwrite(&arr[i], sizeof(person), 1, f);
			fclose(f);
		}
	}
}

void read_and_sort()
{
	FILE* f;
	FILE* fout;
	person* arr;
	person* result;
	person tmp;
	int n = 0;
	fopen_s(&f, "output.binary", "r");
	if (f)
	{
		while (fread(&tmp, sizeof(person), 1, f)) ++n;
		rewind(f);
		arr = malloc(n * sizeof(person));

		for (int i = 0; i < n; ++i)
		{
			fread(&arr[i], sizeof(person), 1, f);
		}
		fclose(f);

		for (int i = 0; i < n-1; ++i)
		{
			int index = i+1;
			for (int j = i; j < n; j++)
				if (compare(arr[j].surname, arr[index].surname) == 1)
					index = j;
			person tmp = arr[i];
			arr[i] = arr[index];
			arr[index] = tmp;

		}
		fopen_s(&f, "output.binary", "w");
		if (f)
		{
			for (int i = 0; i < n; ++i)
				fwrite(&arr[i], sizeof(person), 1, f);
			fclose(f);
		}
	}
}

int compare(char* str1, char* str2)
{
	int len = strlen(str1);
	if (strlen(str2) < len)
		len = strlen(str2);

	for(int i=0; i<len; ++i)
		if (str1[i] < str2[i])
			return 1;
		else if (str1[i] > str2[i])
			return 2;
	return 3;
}

void read_and_print()
{
	FILE* f;
	person tmp;
	fopen_s(&f, "output.binary", "r");
	if (f)
	{
		while (fread(&tmp, sizeof(person), 1, f))
			print_person(&tmp);
		fclose(f);
	}
}

void test() {
	/*person p;
	p.birth = time(NULL);
	strcpy_s(p.name,sizeof(p.name),"Jan");
	strcpy_s(p.surname, sizeof(p.surname), "Nowakowski");
	read_person(&p);
	print_person(&p);*/
	//load_persons();
	//read_and_sort();
	//read_and_print();
	read_and_print();
}

