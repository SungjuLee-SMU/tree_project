#pragma once

#include <iostream>
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS 
#define MAXNODE 100 

typedef struct Userdata
{
	int key;
	int Data;
}Userdata;

typedef struct node
{
	int key;
	int Data;
	node* LChild;
	node* RChild;
}node;

typedef struct PriorityQueue
{
	int Length;
	node* Root;
}PriorityQueue;


typedef node* Nptr;
typedef PriorityQueue* Qptr;