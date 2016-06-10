
#pragma once

typedef struct
{
    int day,month,year;
}date;
typedef struct
{
	char name[50];
	double quantity;
	char category[50];
	date ExpDate;
} Food;
typedef struct
{
    char categorySol[50];
    double quantitySol;
}sol;
Food createFood(char name[], double quantity,char category[],int day,int month,int year);
sol createCategory(char categorySol[],double quantitySol);
char* getName(Food* f);
double getQuantity(Food* f);
char* getCategory(Food* f);
int getDay(Food* f);
int getMonth(Food* f);
int getYear(Food* f);
void toString(Food f, char str[]);
void toStringCategory(sol s,char str[]);
