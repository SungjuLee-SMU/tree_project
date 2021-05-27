#pragma once

#include <iostream>
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS 
#define MAXNODE 100 

typedef struct node
{
	int Data;
	node* LChild;
	node* RChild;
}node;
typedef node* Nptr;
