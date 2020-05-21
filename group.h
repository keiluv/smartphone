#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DATA 100

typedef struct Group{
	char name[20];
	int group_score;
	int group_number;
	int group_limit_number;
	float group_avg;
}group;

int g_is_available();
int g_first_available();
group* g_search_by_name(char* groupname);
void g_create(char* groupname, int limit_number);
