
#include "Food.h"
#include <string.h>
#include <stdio.h>

Food createFood(char name[], double quantity,char category[],int day,int month,int year){
	Food f;
	strcpy(f.name, name);
	f.quantity=quantity;
	strcpy(f.category,category);
	f.ExpDate.day=day;
	f.ExpDate.month=month;
	f.ExpDate.year=year;
	return f;
}
sol createCategory(char categorySol[],double quantitySol){
    sol s;
    strcpy(s.categorySol,categorySol);
    s.quantitySol=quantitySol;
    return s;
}
/*
The function "getName" return the name of an aliment which has the type Food*
*/
char* getName(Food* f){
	return f->name;
}
/*
The function "getQuatity" return the quantity of an aliment which has the type Food*
*/
double getQuantity(Food* f){
	return f->quantity;
}
/*
The function getCategory return the category of an aliment which has the type food*
*/
char* getCategory(Food* f){
    return f->category;
}
/*
The function getDay return the expiration day of an aliment which has the type Food*
*/
int getDay(Food* f){
    return f->ExpDate.day;
}
/*
The function getDay return the expiration month of an aliment which has the type Food*
*/
int getMonth(Food* f){
    return f->ExpDate.month;
}
/*
The function getDay return the expiration year of an aliment which has the type Food*
*/
int getYear(Food* f){
    return f->ExpDate.year;
}
/*
The function getDay return the quantity of an aliment which has the type sol*
*/
int getQuantitySol(sol* s){
    return s->quantitySol;
}
/*
The function is used for updateing an aliment. It sets the name of it.
*/
void setName(Food* f,char newName[])
{
    strcpy(f->name,newName);
}
/*
The function is used for updateing an aliment. It sets its quantity.
*/
void setQuantity(Food* f,double newQuantity)
{
    f->quantity=newQuantity;
}
/*
The function is used for updateing an aliment. It sets its category.
*/
void setCategory(Food* f,char newCategory[]){

    strcpy(f->category,newCategory);
}
/*
The function is used for updateing an aliment. It sets its expiration date
*/
void setExpDate(Food f,int newDay,int newMonth,int newYear){
    date newd;
    //newd=(date*)malloc(sizeof(date));
    newd.day=newDay;
    newd.month=newMonth;
    newd.year=newYear;
    f.ExpDate=newd;

}
void SetNewAliment(Food* f,Food newF){

    f->ExpDate=newF.ExpDate;
    strcpy(f->name,newF.name);
    strcpy(f->category,newF.category);
    f->quantity=newF.quantity;
}
void toString(Food f, char str[]){
	sprintf(str, "The aliment %s , with quantity of %lf , from the category %49s, has the expiration date %d/%d/%d", f.name,f.quantity,f.category,f.ExpDate.day,f.ExpDate.month,f.ExpDate.year);
}
void toStringCategory(sol s,char str[]){
    sprintf(str,"The category %s has the quantity %lf",s.categorySol,s.quantitySol);
}


