#include<stdio.h>
#include<string.h>
struct contactList{
	int id;
	char name[50];
	char phone[12];
	char address[50];
	int status;
	
};
typedef struct contactList cl;
void input (cl*temp){
	printf("nhap id\n");
	scanf("%d",&temp->id);
	printf("nhap ten\n");
	getchar();
	gets(temp->name);
	printf("nhap so dien thoai\n");
	gets(temp->phone);
	printf("nhap dia chi\n/");
	gets(temp->address);
	printf("nhap trang thai\n");
	scanf("%d",&temp->status);
}
void output (cl*temp){
	printf("id: %d,ten: %s,so dien thoai: %s,dia chi: %s,trang thai: %d",temp->id,temp->name,temp->phone,temp->address,temp->status);
}
int main(){
	int n,i;
	int choice;
	int index =2;
	int count;
	cl contactList[2]=
	{
		{1,"hung","0335417874","146tranphu",1},
		{2,"dung","0983737489","130tranphu",0}		
	};
	do{
		printf("1.in toan bo danh sach contact co trong mang tren cung 1 hang\n");
		printf("2.nhap them moi vao contact vao vi tri cuoi cung cua contactlist\n");
		printf("3.cap nhat tt contact neu ko tim thay in ra ko tim thay\n");
		printf("4.xoa 1 contact neu ko tim thay in ra ko tim thay\n");
		printf("5.thuc hien sap xep va in ra contact da duoc sap xep\n");
		printf("6.thuc hien tim kiem va in ra tt contact cung 1 hang\n");
		printf("7.thuc hien tim kiem va in ra toan bo thong tin contact");
		printf("moi nhap lua chon\n");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1:
				 for (i=0;i<index;i++) {
                    printf("%d:",i+1);
                    output(&contactList[i]);
                    printf("\n");
                }
                break;
            case 2:
        		int add_Idcontact;
        		printf("nhap so lan them vao :");
        		scanf("%d",&add_Idcontact);
        		for (i=0;i<add_Idcontact;i++){
        		input(&contactList[index]);
        		index++;
			}
            	break;
            case 3:
            	 count=0;
            	int find_id;
                printf("nhap vao contact_id can cap nhat:");
                scanf("%d",&find_id);
                for (i=0;i<index;i++) {
                    if (contactList[i].id == find_id)
                        {input(&contactList[i]);
						count =1;
						}
    			}
    			if(count==0){
    				printf("khong tim thay\n");
				}
                break;
            case 4 :
            	 count=0;
        	int delete_id;
                printf("nhap vao id can xoa:");
                scanf("%d",&delete_id);
                for (i=0;i<index;i++) {
                    if (contactList[i].id == delete_id)
                    for (int j=i;j<index-1;j++){
                      contactList[i] = contactList [i+1];	
                    	count=1;
					}
                }
                if(count==0){
    				printf("khong tim thay\n");
				}
                index--;
                break;
            case 6 :
            	count=0;
        	int find_contactId ;
        	printf("nhap contact_Id can tim :");
        	scanf("%d",&find_contactId);
			for (i=0;i<index;i++){
				if(contactList[i].id == find_contactId){
				output(&contactList[i]);
				count=1;		
				}
			}
			if(count==0){
    				printf("khong tim thay\n");
				}
		}
	}while(choice!=8);
}

