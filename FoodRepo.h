
#pragma once
#include "Food.h"

typedef struct
{
	Food foodstuff[100];
	int length;
	int capacity;
} FoodRepoDynamic;

typedef struct
{
    sol solstuff[100];
    int lengthSol;
    int capacitySol;
} solRepoDynamic;

solRepoDynamic* createRepoSol(int capacity);
FoodRepoDynamic* createRepo(int capacitySol);

void add(FoodRepoDynamic* v, Food f);

int getLength(FoodRepoDynamic* v);
int getLengthSol(solRepoDynamic* s);

Food getFoodOnPos(FoodRepoDynamic* v, int pos);
sol getCategoryOnPos(solRepoDynamic* s,int pos);

void deleteFood(FoodRepoDynamic* v,char deleteObj[]);
void update(FoodRepoDynamic* v,char Name[],Food f);
void checkString(FoodRepoDynamic* v,solRepoDynamic* s, char solution[]);
void sortAsc(solRepoDynamic* s);

void Destroy(FoodRepoDynamic* v);
void testsFoodRepoDynamic();
