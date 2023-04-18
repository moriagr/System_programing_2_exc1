
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "AdptArray.h"

// I used part of the code from the previous semester- part 1 of the course, from the answers that were on the model to the test moed A question 4.
typedef struct AdptArray_
{
	int ArrSize;
	PElement *pElemArr;
	DEL_FUNC delFunc;
	COPY_FUNC copyFunc;
	PRINT_FUNC printFunc;
} AdptArray;

PAdptArray CreateAdptArray(COPY_FUNC _copyFunc, DEL_FUNC _delFunc, PRINT_FUNC _printFunc)
{
	PAdptArray pArr = (PAdptArray)malloc(sizeof(AdptArray));
	if (pArr == NULL)
	{
		return NULL;
	}
	pArr->ArrSize = 0;
	pArr->pElemArr = NULL;
	pArr->copyFunc = _copyFunc;
	pArr->delFunc = _delFunc;
	pArr->printFunc = _printFunc;
	return pArr;
}
void DeleteAdptArray(PAdptArray pArr)
{
	int i;
	if (pArr == NULL)
		return;
	for (i = 0; i < pArr->ArrSize; i++)
	{
		if ((pArr->pElemArr)[i] != NULL)
			pArr->delFunc((pArr->pElemArr)[i]);
	}
	free(pArr->pElemArr);
	free(pArr);
}

Result SetAdptArrayAt(PAdptArray pArr, int index, PElement pNewElem)
{
	PElement *newpElemArr;
	if (pArr == NULL)
		return FAIL;

	if (index >= pArr->ArrSize)
	{
		// Extend Array
		if ((newpElemArr = (PElement *)calloc((index + 1), sizeof(PElement))) == NULL)
			return FAIL;
		memcpy(newpElemArr, pArr->pElemArr, (pArr->ArrSize) * sizeof(PElement));
		free(pArr->pElemArr);
		pArr->pElemArr = newpElemArr;
		pArr->ArrSize = index + 1;
		(pArr->pElemArr)[index] = pArr->copyFunc(pNewElem);

		return SUCCESS;
	}

	// Delete Previous Elem
	PElement *temp = (pArr->pElemArr)[index];
	if (temp != NULL)
	{
		pArr->delFunc(temp);
	}
	(pArr->pElemArr)[index] = pArr->copyFunc(pNewElem);

	// Update Array Size
	pArr->ArrSize = (index >= pArr->ArrSize) ? (index + 1) : pArr->ArrSize;
	return SUCCESS;
}

PElement GetAdptArrayAt(PAdptArray pArr, int index)
{

	PElement newpElemArr;
	if (pArr == NULL || pArr->ArrSize <= index)
		return FAIL;

	if ((pArr->pElemArr)[index] == NULL)
		return NULL;

	newpElemArr = pArr->copyFunc((pArr->pElemArr)[index]);
	return newpElemArr;
}

int GetAdptArraySize(PAdptArray pArr)
{
	if (pArr->ArrSize < 0 || pArr->copyFunc == NULL || pArr->delFunc == NULL || pArr->printFunc == NULL)
		return -1;
	return pArr->ArrSize;
}

void PrintDB(PAdptArray pArr)
{
	for (int i = 0; i < pArr->ArrSize; i++)
	{
		if ((pArr->pElemArr)[i] != NULL)
			pArr->printFunc((pArr->pElemArr)[i]);
	}
}