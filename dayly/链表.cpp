#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	node *front;
	node *next;
};
node *head;
node *creat(node *head){
	node *newnode;
	node *q;
	newnode=(node*)malloc(sizeof(node));
	scanf("%d",&newnode->num);
	head=q=newnode;
	q->front=NULL;
	while(newnode->num>0){
		newnode=(node*)malloc(sizeof(node));
		scanf("%d",&newnode->num);
		newnode->front=q;
		q->next=newnode;
		q=q->next;
	}
	q->next=NULL;
	return head;
}
node *add(node* p,int num){
	node *ad=(node*)malloc(sizeof(node));
	ad->num=num;
//	cout<<"2";
	if(p==NULL){
	head=(node*)malloc(sizeof(node));
	head->num=num;
//	cout<<"1";
	head->next=NULL;
	head->front=NULL;
//	cout<<head->next;
	
//	head->next=head->front=NULL;
	//cout<<"z"<<;
//	return ad;
	}
	else{
	ad->next=p->next;
	ad->front=p;
	p->next=ad;
	}//	cout<<"y"<<head->next->num;
}
node *find(node *head,int num){
	if(head==NULL)return NULL;
	return head->num==num?head:find(head->next,num);
}
node *del(node *p){
	if(p->next==NULL&&p->front==NULL)p=NULL;
	else if(p->next!=NULL&&p->front!=NULL)p->next->front=p->front,p->front->next=p->next;
	else if(p->next==NULL&&p->front!=NULL) p->front->next=NULL;
	else p->next->front=NULL;
	if(p==head)head=head->next; //ÐÞ¸Ä1 90+60+60+140=350 
	free(p);
}
node *change(node *p,int num){
	p->num=num;
}
void print(node *head){
	node *p=head;
	cout<<head->num;
	if(head==NULL) 
	{printf("NULL\n");
	return;
	}
	printf("\n");
	while(p->num>0){
		printf("%d\n",p->num);
		if(p->next==0)break;
		else
		p=p->next;
	}
return;
}
int main(){
	node *p;
	head=creat(head);
	int n,x,ch,vi;
	if(head==NULL)
	{
		printf("error");
		exit(0);
	}
	printf("1:add\n2:del\n3:change\n4:find\n");
	while(~scanf("%d",&ch)&&ch){
	system("cls");
	printf("1:add\n2:del\n3:change\n4:find\n");
	//print(head);
	if(ch==1){
		scanf("%d%d",&n,&x);
		if(head==NULL)
		{
		//	cout<<"s";
		add(head,x);
		}
		else{
		node *q=find(head,n); 
		add(q,x);
		}
	}
	else if(ch==2){
		scanf("%d",&n);
		node *q=find(head,n); 
		del(q);
	}
	else if(ch==3){
		scanf("%d%d",&n,&x);
		node *q=find(head,n); 
		change(q,x);
	}
	else{
		scanf("%d",&n);
		node *q=find(head,n);
		printf("\n%d\n",q->num);
		continue;
	}
	print(head);
	}
//	print(head);
	return 0;
}
