
#include "FoodRepo.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>

FoodRepoDynamic* createRepoDynamic(int capacity)
{
	FoodRepoDynamic* v=(FoodRepoDynamic*)malloc(sizeof (FoodRepoDynamic));
	if(v==NULL)
        return NULL;

    v->capacity=capacity;
    v->length=0;

    v->foodstuff=(Food*)malloc(capacity * sizeof(Food));
    if(v->foodstuff==NULL)
        return NULL;
	return v;
}
solRepoDynamic* createRepoSol(int capacitySol)
{
    solRepoDynamic* s=(solRepoDynamic*)malloc(sizeof (solRepoDynamic));
    if(s==NULL)
        return NULL;

    s->capacitySol=capacitySol;
    s->lengthSol=0;
    s->solstuff=(sol*)malloc(capacitySol * sizeof(sol));
    if(s->solstuff==NULL)
        return NULL;
    return s;
}
void Destroy(FoodRepoDynamic* v)
{
    free(v->foodstuff);
    free(v);
}
void DestroySol(solRepoDynamic* s)
{
    free(s->solstuff);
    free(s);
}
void resize(FoodRepoDynamic* v)
{
    printf("....Resize....\n");
    v->capacity*=2;
    v->foodstuff=(Food*)realloc(v->foodstuff,v->capacity * sizeof(Food));

}
/*
The function add an element to FoodRepoDynamic.
Input:FoodRepoDynamic-the list
      f-an element of type f
Output:The modified list
*/
void add(FoodRepoDynamic* v, Food f){
    int i,ok=0;
    if(v->length==v->capacity)
        resize(v);
    for (i=0;i<v->length;i++)
        if(strcasecmp(v->foodstuff[i].name,f.name)==0){
        v->foodstuff[i].quantity=v->foodstuff[i].quantity+f.quantity;
        ok=1;
        }
    if(ok==0){
        v->foodstuff[v->length] = f;
        v->length++;
        }

    }
void addSol(solRepoDynamic *s,sol g){
    int i,ok=0;
    if(s->lengthSol==s->capacitySol)
        resize(s);
    for(i=0;i<s->lengthSol;i++)
        if(strcasecmp(s->solstuff[i].categorySol,g.categorySol)==0){
        s->solstuff[i].quantitySol=s->solstuff[i].quantitySol+g.quantitySol;
        ok=1;
        }
    if(ok==0){
        s->solstuff[s->lengthSol]=g;
        s->lengthSol++;
    }
}
/*
The function returns the lenght of the aliments list.
Input:The list
Output:v->length-the length of the list
*/
int getLength(FoodRepoDynamic* v){
	return v->length;
}
/*
The function return the lenght of the categories list.
Input:The categories list
Output:s->lenghtSol-the lenght of the list
*/
int getLengthSol(solRepoDynamic* s){
    return s->lengthSol;
}
Food getFoodOnPos(FoodRepoDynamic* v, int pos){
	if (pos < 0 || pos >= v->length)
		return createFood("", -1,"",0,0,0);
	return v->foodstuff[pos];
}
sol getCategoryOnPos(solRepoDynamic* s,int pos){
    if (pos<0 || pos>=s->lengthSol)
        return createCategory("",-1);
    return s->solstuff[pos];
}
/*
The function deteles an object from the list, by its name.
Input:The list
      The given name(keyboard imput)
Output:The modified list
*/
void deleteFood(FoodRepoDynamic* v,char deleteObj[]){
    int i,j;
    for (i=0;i<v->length;i++)
        if (strcasecmp(v->foodstuff[i].name,deleteObj)!=0){
            printf("You don't have this aliment in the fridge!");
        }
        else{

            for (j=i+1;j<v->length ;j++)
                v->foodstuff[j]=v->foodstuff[j+1];
            v->length--;
        }
}

void update(FoodRepoDynamic* v,char Name[],Food f){
    int i=0,pos=-1;
    while(i<v->length && pos==-1){
        if(strcasecmp(v->foodstuff[i].name,Name)==0){
            pos=i;
        }
        i++;
    }
    setName(v->foodstuff[pos].name,f.name);
    setQuantity(v->foodstuff[pos].quantity,f.quantity);
    setCategory(v->foodstuff[pos].category,f.category);
    setExpDate(v->foodstuff[pos].ExpDate,f.ExpDate.day,f.ExpDate.month,f.ExpDate.year);
}
/*
The function sorts the categories list, by its quantity
Input:The categories list
Output: the sorted list
*/
void sortAsc(solRepoDynamic* s){
    int i,j;
    float auxq;
    char auxc[50];
    for (i=0;i<getLengthSol(s)-1;i++)
        for(j=i+1;j<getLengthSol(s);j++)
            if(s->solstuff[i].quantitySol>s->solstuff[j].quantitySol)
            {

                auxq=s->solstuff[i].quantitySol;
                strcpy(auxc,s->solstuff[i].categorySol);
                s->solstuff[i]=s->solstuff[j];
                s->solstuff[j].quantitySol=auxq;
                strcpy(s->solstuff[j].categorySol,auxc);
            }
}


/*
The function checks if the name of an aliment contains the given string. If the name contains it, we go in the list of categories
check if the category of the aliment that contains the string is already in the category list. Yes-We increase the quantity of that
category .No-we add it to the list.
Input:The list of aliments,the list of categories, the given string
Output:The categories list,modified
*/
void checkString(FoodRepoDynamic* v,solRepoDynamic* s,char solution[]){
    int i=0,k=0,ok;
    for (i=0;i<v->length;i++){
        k=0,ok=0;
        if (strstr(v->foodstuff[i].category,solution)>0){
            addSol(s,createCategory(v->foodstuff[i].category,v->foodstuff[i].quantity));
            //printf("%49s",s->solstuff[k].categorySol);
           // printf("%lf",s->solstuff[k].quantitySol);
            k++;
        }
    }
    sortAsc(s);
}
