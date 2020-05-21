#include "user.h"
#include "group.h"
#include <string.h>
#define DEBUG
void load_user();
void create_user();
void read_user();
void delete_user();
void update_user();
void rank_user();
void ranking();
void make_group();
void join_group();
void group_score_calc();
void list_user();
void save_user();

int main(){
	
	int menu;
	while(1){
		printf("\nChoose Menu: 0.load user datas 1.create user 2. read user 3. delete user 4. update user 5. rank user 6.ranking\n");
		printf("7. make group 8. join group 9. save group score 10. show all users 11.save all users 12.Quit >> ");
		scanf("%d",&menu);
		switch(menu){
			case 0:
				load_user();
				break;
			case 1:
				create_user();
				break;
			case 2: 
				read_user();
				break;
			case 3:
				delete_user();
				break;
			case 4:
				update_user();
				break;
			case 5:
				rank_user();
				break;
			case 6:
				ranking();
				break;
			case 7:
				make_group();
				break;
			case 8:
				join_group();
				break;
			case 9:
				group_score_calc();
				break;
			case 10:
				list_user();
				break;
			case 11:
				save_user();
			case 12:
			default:
				return 0;
		}
	}
	return 0;
}
void load_user(){

	FILE* f = fopen("user.txt","r");
	

	char name[20], gender[20], job[20], grade[20], group[20];

	int score;
	while(!feof(f)){
		if(!m_is_available()){
			printf("[Load] There is no space\n");
			break;
		}
		fscanf(f,"%s %s %s %d %s %s", name,gender,job,&score,grade,group);
		m_create(name,gender,job,score);
		User* u = m_search_by_name(name);
		m_rankmaker(u,grade);
		m_groupwriter(u,group);
	}
}

void create_user(){
	
		
	if(!m_is_available()){
		printf("there is no space!");
		return;
	}	
	char name[20], gender[20], job[20];
	int score;

	printf("Enter a new member's info.\n");
	printf("name > ");
	scanf("%s",name);
	if(m_search_by_name(name)){
		printf("duplicated name!\n");
		return;
	}
	printf("gender >");
	scanf("%s",gender);
	printf("job > ");
	scanf("%s",job);
	printf("score > ");
	scanf("%d",&score);
	m_create(name,gender,job,score);

#ifdef DEBUG
	printf("6. '[%s]''s data generated!\n",name);
#endif
}

void read_user(){

	char name[20];
	printf("Enter a name > ");
	scanf("%s",name);
	User* u = m_search_by_name(name);
	if(u){
		printf("[user info]\n");
		printf("Name: %s\n",m_user_getname(u));
		printf("gender: %s\n",m_user_getgender(u));
		printf("job: %s\n",m_user_getjob(u));
		printf("score: %d\n",m_user_getscore(u));
		printf("rank: %s\n",m_user_getrank(u));
		printf("group: %s\n",m_user_getgroup(u));
	}
	else{
		printf("no such user!\n");
	}

}

void delete_user(){
	char name[20];
	printf("Enter a name > ");
	scanf("%s",name);
	
	User * u = m_search_by_name(name);
	if(u){
		m_delete();
		printf("%s's data is deleted!\n",name);
	}
	else{
		printf("%s doesn't exist!\n",name);
	}

#ifdef DEBUG
	printf("2. '[%s]''s data deleted!\n",name);
#endif
}
void update_user(){
	char name[20], gender[20], job[20];
	int score;
	printf("Enter a name > ");
	scanf("%s",name);
	
	User* u = m_search_by_name(name);
	if(u){
		printf("Enter a updated info\n");
		printf("gender > ");
		scanf("%s",gender);
		printf("job > ");
		scanf("%s",job);
		printf("score > ");
		scanf("%d",&score);

		m_update(u, gender,job,score);
		printf("run function 'rank_user' to update your grade!\n");
	
#ifdef DEBUG
	printf("6.%s's data updated!\n",name);
#endif
	}
	else{
		printf("no such member: %s",name);
	}
}
void rank_user(){
	char name[20],rank[20];
	int score=0;
	printf("input name > ");
	scanf("%s",name);
	User* u = m_search_by_name(name);
	score = m_user_getscore(u);
	if(score >= 95){
		strcpy(rank,"grand master");
	}
	else if(score >= 90){
		strcpy(rank,"master");
	}
	else if(score >= 80){
		strcpy(rank,"diamond");
	}
	else if(score >= 70){
		strcpy(rank,"gold");
	}
	else if(score >= 60){
		strcpy(rank,"silver");
	}
	else{
		strcpy(rank,"bronze");
	}
	
	m_rankmaker(u,rank);

#ifdef DEBUG
	printf("3.%s's rank '[%s]' generated!\n",name,rank);
#endif

}
void ranking(){
	int count = m_count();
	User* user[MAX_DATA];
	m_get_all(user);
	User* temp;
	for(int i =0;i<count;i++){
		for(int j=i;j<count;j++){
			if(user[i]->score < user[j]->score)
			{
				temp = user[i];
				user[i]=user[j];
				user[j]=temp;
			}
		}
	}
	for(int i=0;i<count;i++){
		User* u = user[i];
		printf("%d. %s",i+1,m_to_string(u));	
	}
}
void make_group(){
	char name[20];
	 int limit=0;
	if(g_is_available()==0){
		printf("there is no space!\n");
		return;
	}
	printf("Enter a new group's info.\n");
	printf("name > ");
	scanf("%s",name);
	if(g_search_by_name(name)){
		printf("duplicated name!\n");
		return;
	}
	printf("maximum group member number > ");
	scanf("%d",&limit);
	g_create(name, limit);
#ifdef DEBUG
	printf("4.group '[%s]' generated!\n",name);
	printf("group's limit number is %d!\n",limit);
#endif
}
void join_group(){
	char name[20];
	char groupname[20];
	printf("input name > ");
	scanf("%s",name);
	User* u = m_search_by_name(name);
	printf("input group what you want to join > ");
	scanf("%s",groupname);
	m_groupwriter(u,groupname);
		

}

void group_score_calc(){
	char groupname[20];
	printf("Enter a group name: ");
	scanf("%s",groupname);
	group* g = g_search_by_name(groupname);
	if(g){
		

	}
	else{
		
	}
}
void list_user(){
	printf("All Users\n");
	int size = m_count();
	User* player[MAX_DATA];
	m_get_all(player);
	for(int i=0;i<size;i++){
		User* u = player[i];
	 	printf("%d. %s \n",i+1,m_to_string(u));
	}
}
void save_user(){
	FILE* f = fopen("user.txt","w");
	printf("All records\n");
	int size = m_count();
	User* user[MAX_DATA];
	m_get_all(user);
	
	for(int i=0;i<size;i++){
		User* u = user[i];
		fprintf(f,"%s",m_to_string_save(u));
	}
	fclose(f);
	
#ifdef DEBUG
	printf("5.all user records saved!\n");
#endif
}
void save_group(){

	FILE* f = fopen("user.txt","w");
	printf("All records\n");
	int size = m_count();
	User* user[MAX_DATA];
	m_get_all(user);
	
	for(int i=0;i<size;i++){
		User* u = user[i];
		fprintf(f,"%s\n",m_to_string_save(u));
	}
	fclose(f);
	
#ifdef DEBUG
	printf("8.all group records saved!");
#endif
}

