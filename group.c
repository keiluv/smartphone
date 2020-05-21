#include "group.h"

group* clan[MAX_DATA];
int gcount =0;

int g_is_available(){
	
	for(int i=0;i<MAX_DATA;i++)
	{
		if(clan[i]==NULL)return 1;
	}
	return 0;
}

int g_first_available(){
	
	for(int i=0;i<MAX_DATA;i++){
		if(clan[i]==NULL)return 1;
	}
	return -1;
}

void g_create(char* groupname, int limit_number){
	int index = g_first_available();
	clan[index]=(group*)malloc(sizeof(group));
	group *g = clan[index];
	strcpy(g->name,groupname);
	g->group_limit_number = limit_number;
	gcount++;
#ifdef DEBUG
	printf("[%s] 그룹이 생성되었습니다.\n",groupname);
#endif
}

group* g_search_by_name(char* groupname){
	
	for(int i=0;i<MAX_DATA;i++){
		if(clan[i]!=NULL && strcmp(clan[i]->name, groupname)==0)return clan[i];
	}
	return NULL;


}
