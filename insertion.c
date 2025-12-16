#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[20];
	struct node *link;
};

struct node *addatbeg(struct node *start, char data[20]);
void display(struct node *start);

int main(){
	struct node *start = NULL;
	int choice;
	char data[20];
	
	while(1)
	{
		printf("Press 1 to Enter your name.\n");
		printf("Press 2 to Display the name.\n");
		printf("Press 3 to Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter a name : ");
				scanf("%s",&data);
				start = addatbeg(start, data);
				break;
			case 2:
				display(start);
				break;
			case 3:
				exit(1);
			default :
				printf("Invalid choice!!\n");
				break;
			
		}
		getch();
		system("cls");
		printf("----Your choice  = '%d'  ----\n",choice);
		printf("---- Your name is %s ----\n\n",data);
	}
}

struct node *addatbeg(struct node *start , char data[20]){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	strcpy(temp->name,data);
	if(start == NULL){
		temp -> link = NULL;
		start = temp;
		return ;
	}
	temp -> link = start;
	start = temp;
	temp=NULL;
	free(temp);
	return start;
}

void display(struct node *start){
	struct node *p;
	if (start == NULL )
	{
		printf("Linked list is empty..\n");
		return;
	}
	p=start;
	while(p!=NULL)
	{
		printf("%s\t",p->name);
		p=p->link;
	}
}
