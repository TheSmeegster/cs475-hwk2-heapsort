/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */

//Main sorting method
void heapSort(Employee *A, int n)
{
	//Runs the heapify loop as long as n is not too small(this would indicate the array is properly organized)
	while(n > 0){
		swap(&A[n-1], &A[0]);
		n--;
		heapify(A, 0, n-1);//This may need to be n-1
	}
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */

//Builds the heap
void buildHeap(Employee *A, int n)
{
	// Calls heapify() every element from A[n/2] down-to A[0]
	for(int i = 0; i <= (n/2) + 1; i++){
		heapify(A, i, n);
	}
}


/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */

void heapify(Employee *A, int i, int n)
{
	// Index of left child of element i
	int leftIndex = 2 * (i+1)-1;

	// Index of right child of element i
	int rightIndex = 2 * (i+1);

	//Locations of employees and their information
	Employee leftEmp = A[leftIndex];
	Employee rightEmp = A[rightIndex];
	Employee currEmp = A[i];
	Employee *currEmpLoc = &A[i];

	//Salaries of current employee, as well as left and right employees
	int rightEmpSal = leftEmp.salary;
	int leftEmpSal = rightEmp.salary;
	int currSal = currEmp.salary;

	//Locates the smallest salary between nearby employees, if they are equal it defaults to the left
	int smaller = leftEmpSal;
	Employee *smallerEmpLoc = &leftEmp;

	if(rightEmpSal < leftEmpSal){
		smaller = rightEmpSal;
		smallerEmpLoc = &rightEmp;
	}

	//Swaps the smallest employee if it is smaller than the current one
	if(currSal > smaller){
		swap(currEmpLoc, smallerEmpLoc);
	}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */

//Swaps the locations of 2 given employees
void swap(Employee *e1, Employee *e2)
{
	Employee emp1 = *e1;
	Employee emp2 = *e2;
	*e2 = emp1;
	*e1 = emp2;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */

//Prints out the entire array of employees with their salaries
void printList(Employee *A, int n)
{
	for(int i = 0; i < n; i++){
		printf("Name : %s | Salary : %i\n", A[i].name, A[i].salary);
	}
}
