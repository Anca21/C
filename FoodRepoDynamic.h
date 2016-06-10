
#pragma once
#include "Food.h"

typedef struct
{
	Food* foodstuff;
	int length;
	int capacity;
} FoodRepoDynamic;
typedef struct
{
    Food* undo;
    int lengthUndo;
    int capacityUndo;
}UndoDynamic;
typedef struct
{
    sol* solstuff;
    int lengthSol;
    int capacitySol;
} solRepoDynamic;
typedef struct
{
    Food* redo;
    int lengthRedo;
    int capacityRedo;
}RedoDynamic;

solRepoDynamic* createRepoSol(int capacitySol);
FoodRepoDynamic* createRepo(int capacity);
UndoDynamic* createRepoUndo(int capacity);
RedoDynamic* createRepoRedo(int capacity);


/*
The function add an element to FoodRepoDynamic.
Input:FoodRepoDynamic-the list
      f-an element of type f
Output:The modified list
*/
void add(FoodRepoDynamic* v,UndoDynamic* u,RedoDynamic* r, Food f);


/*
The function returns the lenght of the aliments list.
Input:The list
Output:v->length-the length of the list
*/
int getLength(FoodRepoDynamic* v);


/*
The function return the lenght of the categories list.
Input:The categories list
Output:s->lenghtSol-the lenght of the list
*/
int getLengthSol(solRepoDynamic* s);


/*
The function return the length of the vector 'u'=undo
*/
int getLengthUndo(UndoDynamic* u);

/*
The function return the length of the vector 'r'-redo
*/
int getLengthRedo(RedoDynamic* r);


/*
The function "getFoodOnPos" return the element in 'v' list, on a given position
Input:'v', the position
Output:the element on that position
*/
Food getFoodOnPos(FoodRepoDynamic* v, int pos);

/*
The function "getCategoryOnPos" return the element in 's' list, on a given position
Input:'s', the position
Output:the element on that position
*/
sol getCategoryOnPos(solRepoDynamic* s,int pos);

/*
The function "getUndoOnPos" return the element in 'u' list, on a given position
Input:'u', the position
Output:the element on that position
*/
Food getUndoOnPos(UndoDynamic* u,int pos);

/*
The function "getRedoOnPos" return the element in 'r' list, on a given position
Input:'r', the position
Output:the element on that position
*/
Food getRedoOnPod(RedoDynamic* r,int pos);


/*
The function deteles an object from the list, by its name.
Input:The list
      The given name(keyboard imput)
Output:The modified list
*/
void deleteFood(FoodRepoDynamic* v,UndoDynamic* c,RedoDynamic* r,char deleteObj[]);


/*
the function"update" updates an element from the vector v, by its name
Input:The name of the element you want to update
      The new element you want to put in the lsit.
Output: the modified list.
*/
void update(FoodRepoDynamic* v,UndoDynamic* u,RedoDynamic*r,char Name[],Food f);


/*
The function checks if the name of an aliment contains the given string. If the name contains it, we go in the list of categories
check if the category of the aliment that contains the string is already in the category list. Yes-We increase the quantity of that
category .No-we add it to the list.
Input:The list of aliments,the list of categories, the given string
Output:The categories list,modified
*/
void checkString(FoodRepoDynamic* v,solRepoDynamic* s, char solution[]);


/*
The function prints the elements which will expire in "noDays" days from now, from a certain category
Input:v-the vector, the category, the number of days.
*/
void checkCategory(FoodRepoDynamic* v ,char categ[],int noDays);


/*
The function sorts the categories list, by its quantity
Input:The categories list
Output: the sorted list
*/
void sortAsc(solRepoDynamic* s);


/*
The function" CopyVector" copy the undo vector in v(when we do undo).
Output:The list(v) modified.
*/
void CopyVector(FoodRepoDynamic* v,UndoDynamic* u,RedoDynamic* r);


/*
The function"CopyVectorRedo" copy the vector r in v(when we do redo).
Ouput:The list(v) modified.
*/
void CopyVectorRedo(FoodRepoDynamic* v,RedoDynamic* r);

void Destroy(FoodRepoDynamic* v);
void DestroySol(solRepoDynamic* s);
void DestroyUndo(UndoDynamic* u);
void DestroyRedo(RedoDynamic* r);

void testsFoodRepoDynamic();
