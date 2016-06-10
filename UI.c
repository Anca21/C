

#include "UI.h"
#include <stdio.h>

UI createUI(Controller* c, Controller2* c2,ControllerUndo* cU,ControllerRedo* cR)
{
	UI ui;
	ui.ctrl = c;
	ui.ctrl2=c2;
	ui.ctrlU=cU;
	ui.ctrlR=cR;
	return ui;
}


void printMenu()
{

	printf("\n ********************************************************** \n");
	printf("1 - Add some food in the refrigerator.\n");
	printf("2 - List all food.\n");
	printf("3 - Delete an aliment by name.\n");
	printf("4 - Update an aliment by name.\n");
	printf("5 - List all the categories in ascending order.\n");
	printf("6 - List all the aliments which will expire.\n");
	printf("7 - Undo the last operation.\n");
	printf("8 - -Redo the last operation.\n");
	printf("0 - to exit.\n");
	printf("\n ********************************************************** \n");
}

int validCommand(int command){
	if (command >= 0 && command <= 8)
		return 1;
	return 0;
}
/*
The function checks if the user reads an integer. If not, it prints a message.
*/
int readIntegerNumber(const char* message){
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0){
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);
		// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}
/*
The function checks if a number is positive or not. If it's not positive, it keeps asking for another input.
*/
int readPositive(const char* message){
    double s=0;
    int flag=0,r=0;

    while(flag==0){
        printf(message);
        scanf("%lf",&s);
        if (s>=0)
        {
            flag=1;
        }
    }
    return s;
}

/*
The function gets the information about an aliment(keyboard imput), and then it add that aliment to the list.
*/
void addFoodUI(UI* ui){

	char name[50];
	double quantity;
	char category[50];
	date ExpDate;
	printf("Please input the name of the food: ");
	scanf("%49s", name);
	quantity=readPositive("Please input the quantity: ");

	printf("Please input the category(dairy,sweets,meat,fruits): ");
	scanf("%49s",category);
	ExpDate.day=readIntegerNumber("Give the expiration day:");
	ExpDate.month=readIntegerNumber("Give the expiration month:");
    ExpDate.year=readIntegerNumber("Give the expiration year:");
	addFood(ui->ctrl,ui->ctrlU,ui->ctrlR, name, quantity,category,ExpDate.day,ExpDate.month,ExpDate.year);
}
/*
The "DeleteF" function read from the keyboard the name of an aliment, ant then deletes its apparition on the list.
*/
void DeleteF(UI* ui){
    char deleteObj[50];
    printf("Give the aliment you want to delete:");
    scanf("%49s",deleteObj);
    DeleteFood(ui->ctrl,ui->ctrlU,ui->ctrlR,deleteObj);
}
/*
The "UpdateUI" function update an aliment from the list, by its name(keyboard input).
*/
void UpdateUI(UI* ui){
    char Name[50],NewName[50],NewCategory[50];
    int newQuantity,newDay,newMonth,newYear;
    printf("Give the name of the aliment you want to update:\n");
    scanf("%49s",Name);
    printf("Give the new name:\n");
    scanf("%49s",NewName);
    printf("Give the new category:\n");
    scanf("%49s",NewCategory);
    printf("Give the new quantity:\n");
    scanf("%lf",&newQuantity);
    printf("Give the new expiration day:\n");
    scanf("%d",&newDay);
    printf("Give the new expiration month:\n");
    scanf("%d",&newMonth);
    printf("Give the new expiration year:\n");
    scanf("%d",&newYear);
    Update(ui->ctrl,ui->ctrlU,ui->ctrlR,Name,NewName,newQuantity,NewCategory,newDay,newMonth,newYear);
}
/*
The function prints the list of food from the fridge
*/
void listAllFood(UI* ui){
	FoodRepoDynamic* repo = getRepo(ui->ctrl);
	int length = getLength(repo);
	int i;

	if (length == 0){
		char* str = "There is no food.";
		printf("%s \n", str);
	}

	for (i = 0; i < getLength(repo); i++){
		char str[200];
		toString(getFoodOnPos(repo, i), str);
		printf("%49s \n", str);
	}
}
/*
The checkSolution frunctin checks if we find a string in the name of an aliment.YES-saves the category in another string

*/

void checkSolution(UI* ui){
    char str[50];
    printf("Give a string(which appears in the name of the aliment you want) for which you want to display all the categories:\n");
    scanf("%49s",str);
    Statistics(ui->ctrl,ui->ctrl2,str);
    listSolution(ui);

}
void checkCat(UI* ui){
    char str2[20];
    int noDays;
    printf("Give the cateogry for which you want to display all the food which has the expiration date in a number of days:");
    scanf("%49s",str2);
    printf("Give the number of days for the expiration date:");
    scanf("%d",&noDays);
    checkC(ui->ctrl,str2,noDays);
}
/*
The function"listSolution" prints the vector of solutions(the vector of 'sol' objects,
which contain the categories, orderd ascending by quantity.
*/
void listSolution(UI* ui){
    solRepoDynamic* repo2=getRepo2(ui->ctrl2);
    int length=getLengthSol(repo2);
    int i;

    if(length==0){
        char* str="There is no solution.";
        printf("%s \n",str);
        }
    for(i=0;i<getLengthSol(repo2);i++){
        char str[200];
        toStringCategory(getCategoryOnPos(repo2,i),str);
        printf("%49s \n",str);
        }
}

void UndoUI(UI* ui){
    UndoController(ui->ctrl,ui->ctrlU,ui->ctrlR);
}

void RedoUI(UI* ui){
    RedoController(ui->ctrl,ui->ctrlR);
}

void startUI(UI* ui){
	while (1){
		printMenu();
		int command = readIntegerNumber("Input command: ");
		while (validCommand(command) == 0){
			printf("Please input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 0)
			break;
		switch (command){
			case 1:{
				addFoodUI(ui);
				break;
			}
			case 2:{
				listAllFood(ui);
				break;
            }
            case 3:{
                DeleteF(ui);
                break;
            case 4:{
                UpdateUI(ui);
                break;
            }
            case 5:{
                checkSolution(ui);
                //listSolution(ui);
                break;
            }
            case 6:{
                checkCat(ui);
                break;
            }
            case 7:{
                UndoUI(ui);
                break;
            }
            case 8:{
                RedoUI(ui);
                break;
            }
			}
		}//switch
	}//while
}
