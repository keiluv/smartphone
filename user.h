#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 100

typedef struct member{
	char name[20];
	char sex[20];
	char job[20];
	int score;
	char rank[20];
	char group[20];
}User;

int m_is_available();
User* m_search_by_name(char* username);
char* m_user_getname(User* u);
char* m_user_getgender(User* u);
char* m_user_getjob(User* u);
int m_user_getscore(User* u);
char* m_user_getrank(User* u);
void m_create(char* username, char* usergender, char* userjob, int score);
void m_get_all(User* u[]);
char* m_to_string(User* u);
int m_count();
void m_delete();
void m_rankmaker(User* u,char* userrank);
void m_groupwriter(User* u,char* usergroup);
void m_update(User* u,char* gender, char*job, int score);
char* m_to_string_save(User* u);
char* m_user_getgroup(User*u);
