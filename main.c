#include <stdio.h>
#include "employee.h"
#include "heap.h"

int main(int argc, char *argv[])
{
	//Initializes the company with a constant max size
	int MAX_COMPANY_SIZE = 5;
	Employee company[MAX_COMPANY_SIZE];

	//Prompts user for input to create a new employee until the company is filled
	for(int i = 0; i < MAX_COMPANY_SIZE; i++){

		Employee emp;

		printf("Name : ");
		scanf("%s", emp.name);

		printf("Salary : ");
		scanf("%d", &emp.salary);

		company[i] = emp;
	}

	//Prints the list of employees out prior to organizing
	printf("Before organization : \n");
	printList(company, (sizeof(company)/sizeof(company[0])));

	//Runs heapsort on the size of the company - 1(for loops)
	heapSort(company, (sizeof(company)/sizeof(company[0])) - 1);

	//Prints the list of employees out after organizing
	printf("After organization : \n");
	printList(company, (sizeof(company)/sizeof(company[0])));

	return 0;
}
