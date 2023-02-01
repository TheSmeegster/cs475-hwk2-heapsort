#include <stdio.h>
#include "employee.h"
#include "heap.h"

int main(int argc, char *argv[])
{
	Employee emp1;
	emp1 = (Employee){.name = "Dan", .salary = 5};

	Employee emp2;
	emp2 = (Employee){.name = "Mark", .salary = 6};

	Employee emp3;
	emp3 = (Employee){.name = "Human", .salary = 2};

	Employee company[] = {emp1, emp2, emp3};

	heapSort(company, 3);

	return 0;
}
