#include <stdio.h>
#include <time.h>
#include <string.h>

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
	person arr[5];
	fopen_s(&f, "output.binary", "r");
	for (int i = 0; i < 5; ++i)
	{
		fread(&arr[i], sizeof(person), 1, f);
		print_person(&arr[i]);
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
	read_persons();
}

