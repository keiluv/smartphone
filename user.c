#include "user.h"

User* user[MAX_DATA];
int count =0;

int m_is_available(){
  
    for(int i=0; i<MAX_DATA; i++){
        if(user[i]==NULL) return 1;
    }
    return 0;
}
int m_count(){
	return count;
}

int m_first_available(){
	
	for(int i=0;i<MAX_DATA;i++){
		if(user[i]==NULL)return i;
	}
	return -1;
}

void m_create(char* username, char* usergender, char*userjob, int userscore){
	int index =m_first_available();
	user[index] = (User*)malloc(sizeof(User));
	
	User *u = user[index];
#ifdef DEBUG
	printf("%d 만큼의 유저 할당성공",index);
#endif
	strcpy(u->name,username);
	strcpy(u->sex,usergender);
	strcpy(u->job,userjob);
	u->score = userscore;
	count++;
#ifdef DEBUG
	printf("현재 들어있는 인원 수는 %d명",count);
#endif
}

User* m_search_by_name(char* username){
	
	for(int i=0;i<MAX_DATA;i++){
		if(user[i]!=NULL && strcmp(user[i]->name, username)==0) return user[i];
	}
	return NULL;
}

char* m_user_getname(User* u){
	return u->name;
}
char* m_user_getgender(User* u){
	return u->sex;
}
char* m_user_getjob(User* u){
	return u->job;
}
int m_user_getscore(User* u){
	return u->score;
}
char* m_user_getrank(User* u){
	return u->rank;
}

char* m_to_string(User* u){
	static char str[80];
	sprintf(str, "점수: %d / 이름: %s / 성별: %s / 직업: %s ",u->score,u->name,u->sex,u->job);
	
#ifdef DEBUG
	printf("점수: %d / 이름: %s / 성별: %s / 직업: %s 정보 호출됨\n",u->score,u->name,u->sex,u->job);
#endif
	return str;
}

void m_get_all(User* u[]){
	int i =0;
	for(i=0;i<MAX_DATA;i++){
		u[i]=user[i];
	}
}
void m_rankmaker(User* u, char* userrank){
	strcpy(u->rank,userrank);
}
void m_groupwriter(User* u, char* usergroup){
	strcpy(u->group, usergroup);
}
void m_delete(User* u){
	int i,index;
	for(i=0;i<MAX_DATA;i++)
	{
		if(user[i]==u){
			index=i;
			break;
		}
	}
	free(u);
	user[index]=NULL;
	count--;
#ifdef DEBUG
	printf("해당 정보가 삭제되었습니다.\n");
#endif
}
void m_update(User* u, char* gender, char* job, int score){
	strcpy(u->sex,gender);
	strcpy(u->job,job);
	u->score = score;

}
char* m_to_string_save(User* u){
	static char str[200];
	sprintf(str,"%s %s %s %d %s %s",u->name, u->sex, u->job, u->score, u->rank, u->group);
#ifdef DEBUG
	printf("%s %s %s %d %s %s 저장 성공",u->name, u->sex, u->job, u->score, u->rank, u->group);
#endif
	return str;
}

char* m_user_getgroup(User*u){
	return u->group;
}
