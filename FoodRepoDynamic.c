
#include "FoodRepoDynamic.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <time.h>

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
UndoDynamic* createRepoUndo(int capacity)
{
    UndoDynamic* u=(UndoDynamic*)malloc(sizeof(UndoDynamic));
    if(u==NULL)
        return NULL;

    u->capacityUndo=capacity;
    u->lengthUndo=0;

    u->undo=(Food*)malloc(capacity * sizeof(Food));
    if(u->undo==NULL)
        return NULL;
    return u;
}
RedoDynamic* createRepoRedo(int capacity)
{
    RedoDynamic* r=(RedoDynamic*)malloc(sizeof(RedoDynamic));
    if(r==NULL)
        return NULL;

    r->capacityRedo=capacity;
    r->lengthRedo=0;

    r->redo=(Food*)malloc(capacity * sizeof(Food));
    if(r->redo==NULL)
        return NULL;
    return r;
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
void DestroyRedo(RedoDynamic* r)
{
    free(r->redo);
    free(r);
}
void DestroyUndo(UndoDynamic* u)
{
    free(u->undo);
    free(u);
}
void resize(FoodRepoDynamic* v)
{
    printf("....Resize....\n");
    v->capacity*=2;
    v->foodstuff=(Food*)realloc(v->foodstuff,v->capacity * sizeof(Food));

}
void resizeSol(solRepoDynamic* s)
{
    printf("......Resize.....\n");
    s->capacitySol*=2;
    s->solstuff=(sol*)realloc(s->solstuff,s->capacitySol * sizeof(sol));
}
void resizeUndo(UndoDynamic* u)
{
    printf(".....Resize....\n");
    u->capacityUndo*=2;
    u->undo=(Food*)realloc(u->undo,u->capacityUndo * sizeof(Food));
}
void resizeRedo(RedoDynamic* r)
{
    printf(".....Resize.....\n");
    r->capacityRedo*=2;
    r->redo=(Food*)realloc(r->redo,r->capacityRedo * sizeof(Food));
}
/*
The function add an element to FoodRepoDynamic.
Input:FoodRepoDynamic-the list
      f-an element of type f
Output:The modified list
*/
void add(FoodRepoDynamic* v,UndoDynamic*u,RedoDynamic* r, Food f){
    int i,ok=0;

    CopyUndo(v,u,r);
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
/*
The function add an element to solRepoDynamic.
Input:soolRepoDynamic-the list
      g-an element of type sol
Output:The modified list
*/
void addS(solRepoDynamic* s,sol g){
    int i=0,ok=0;

    if(s->lengthSol==s->capacitySol)
        resizeSol(s);
    for(i=0;i<s->lengthSol;i++)

        if(strcasecmp(s->solstuff[i].categorySol,g.categorySol)==0){
        s->solstuff[i].quantitySol=s->solstuff[i].quantitySol+g.quantitySol;
        ok=1;

        }
    if(ok==0){
        s->solstuff[s->lengthSol] =g;
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
/*
The function return the length of the vector 'u'=undo
*/
int getLengthUndo(UndoDynamic* u){
    return u->lengthUndo;
}
/*
The function return the length of the vector 'r'-redo
*/
int getLengthRedo(RedoDynamic* r){
    return r->lengthRedo;
}
/*
The function "getFoodOnPos" return the element in 'v' list, on a given position
Input:'v', the position
Output:the element on that position
*/
Food getFoodOnPos(FoodRepoDynamic* v, int pos){
	if (pos < 0 || pos >= v->length)
		return createFood("", -1,"",0,0,0);
	return v->foodstuff[pos];
}
/*
The function "getCategoryOnPos" return the element in 's' list, on a given position
Input:'s', the position
Output:the element on that position
*/
sol getCategoryOnPos(solRepoDynamic* s,int pos){
    if (pos<0 || pos>=s->lengthSol)
        return createCategory("",-1);
    return s->solstuff[pos];
}
/*
The function "getUndoOnPos" return the element in 'u' list, on a given position
Input:'u', the position
Output:the element on that position
*/
Food getUndoOnPos(UndoDynamic* u,int pos){
    if(pos<0 || pos>=u->lengthUndo)
        return createFood("",-1,"",0,0,0);
    return u->undo[pos];
}
/*
The function "getRedoOnPos" return the element in 'r' list, on a given position
Input:'r', the position
Output:the element on that position
*/
Food getRedoOnPod(RedoDynamic* r,int pos){
    if(pos<0 ||  pos>=r->lengthRedo)
        return createFood("",-1,"",0,0,0);
    return r->redo[pos];
}
/*
The function copies in 'r' the information from 'v', before 'v' is modified again by copying undo in it.
Input:v,r-redo
Output:u is modified
*/
void CopyRedo(FoodRepoDynamic* v,RedoDynamic* r){
    int i;
    for(i=0;i<v->length;i++){
        r->redo[i]=v->foodstuff[i];
       // printf("%49s",r->redo[i].name);
    }
    r->lengthRedo=v->length;
}
/*
The function copies in 'u' the information from 'v', before 'v' is modified
Input:v,u,r-redo
Output:u is modified
*/
void CopyUndo(FoodRepoDynamic* v,UndoDynamic* u,RedoDynamic* r){
    int i;
    if(u->lengthUndo==u->capacityUndo)
        resizeUndo(u);
    for (i=0;i<v->length;i++){
        u->undo[i]=v->foodstuff[i];

    }
    u->lengthUndo=v->length;
    CopyRedo(v,r);
}
/*
The function deteles an object from the list, by its name.
Input:The list
      The given name(keyboard imput)
Output:The modified list
*/
void deleteFood(FoodRepoDynamic* v,UndoDynamic* u,RedoDynamic* r,char deleteObj[]){
    int i,j;
    CopyUndo(v,u,r);
    for (i=0;i<v->length;i++)
        if (strcasecmp(v->foodstuff[i].name,deleteObj)!=0){
            printf("You don't have this aliment in the fridge!");
            break;
        }
        else{

            for (j=i+1;j<v->length ;j++)
                v->foodstuff[j]=v->foodstuff[j+1];
            v->length--;
        }
}
/*
the function"update" updates an element from the vector v, by its name
Input:The name of the element you want to update
      The new element you want to put in the lsit.
Output: the modified list.
*/
void update(FoodRepoDynamic* v,UndoDynamic*u, RedoDynamic*r,char Name[],Food f){
    int i=0,pos=-1;
    CopyUndo(v,u,r);
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
        if (strstr(v->foodstuff[i].category,solution)!=0){
            addS(s,createCategory(v->foodstuff[i].category,v->foodstuff[i].quantity));
            k++;
        }
    }
    sortAsc(s);
}
/*
The function prints the elements which will expire in "noDays" days from now, from a certain category
Input:v-the vector, the category, the number of days.
*/
void checkCategory(FoodRepoDynamic* v,char categ[],int noDays){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int i=0,ok=0;
    //printf(ctime(&t));
    while(i<v->length){
        if(strcmp(v->foodstuff[i].category,categ)==0)
            if(v->foodstuff[i].ExpDate.year<=tm.tm_year+1900)
                if(v->foodstuff[i].ExpDate.month<=tm.tm_mon+1)
                    if(v->foodstuff[i].ExpDate.day<=tm.tm_mday+noDays){
                        printf("%49s",v->foodstuff[i].name);
                        printf("\n");
                        ok=1;
                        i=v->length+1;}
        else{
            printf("This category does not exist!");
        }
        i++;
    }
    if(ok==0){
        printf("There is no such an aliment!");
    }
}
/*
The function" CopyVector" copy the undo vector in v(when we do undo).
Output:The list(v) modified.
*/
void CopyVector(FoodRepoDynamic*v,UndoDynamic* u,RedoDynamic* r){
    //v->redo=v->undo
    CopyRedo(v,r);
    int i;
    for(i=0;i<u->lengthUndo;i++){
        v->foodstuff[i]=u->undo[i];
        }
    v->length=u->lengthUndo;
}
/*
The function"CopyVectorRedo" copy the vector r in v(when we do redo).
Ouput:The list(v) modified.
*/
void CopyVectorRedo(FoodRepoDynamic* v,RedoDynamic* r){
    int i;
    v->length=r->lengthRedo;
    for(i=0;i<r->lengthRedo;i++){
        v->foodstuff[i]=r->redo[i];
        }

}

// Test
void testsFoodRepoDynamic(){
	FoodRepoDynamic* v= createRepoDynamic(2);
	UndoDynamic* u=createRepoUndo(2);
	RedoDynamic* r=createRepoRedo(2);
	if (v == NULL)
		assert(0);

	assert(v->capacity == 2);
	assert(v->length == 0);

	Food f1 = createFood("Smantana",2,"dairy",12,3,2016);
	add(v,u,r, f1);
	assert(v->length == 1);


	Food f2 = createFood("Carne",3,"meat",3,4,2016);
	add(v,u,r,f2);
	assert(v->length == 2);

    Food f3 = createFood("Mere",5,"fruits",15,4,2016);
	add(v,u,r, f3);
	deleteFood(v,u,r,"Mere");
    update(v,u,r,"Carne",f3);
	Destroy(v);
	DestroyRedo(r);
	DestroyUndo(u);
}
void testsSolRepoDynamic(){
    solRepoDynamic* s=createRepoSol(2);
    if(s==NULL)
        assert(0);

    assert(s->capacitySol==2);
    assert(s->lengthSol==0);

    sol s1=createCategory("dairy",2);
    addSol(s,s1);
    assert(s->lengthSol==1);
    DestroySol(s);
}

