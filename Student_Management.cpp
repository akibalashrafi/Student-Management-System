#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Teacher Node
struct node {
    long long int id,pass,phone;
    char name[50],des[30],address[100],mail[50];
    struct node *next;
};

struct node *fhead=NULL;


//Student Node
struct nodeS {
    char name[50],address[100],mail[50];
    long long int id, pass,phone;
    float classtest, assignment, mid, fi, cg;
    struct nodeS *next;
};
struct nodeS *headS = NULL;

//Node for routine
struct routine {
    char day[30];
    char time[30];
    char subject[30];
    struct routine *next;
};

struct routine *headR = NULL;


long long int ID,Password;


//Function Declaration
struct node *createnode(long long int id, long long int pass,long long phone,char name[50],char des[30],char address[100],char mail[50]);
struct nodeS *createnodeS(char name[50], long long int ID, long long int pass,long long phone,char address[100],char mail[50]);
void verify();
void notice_update();
void notice_print();
void SearchT();
void AddT();
void AllT();
void EditT();
void DelT();
int verifyT();
void filetonodeT(long long int id, long long int pass,long long phone,char name[50],char des[30],char address[100],char mail[50]);
void SearchS();
void AllS();
void AddS();
void EditS();
void DelS();
void filetonodeS(long long int id, long long int pass,long long phone,char name[50],char address[100],char mail[50],float classtest,float assignment,float mid, float fi,float cg);
void CGPA(struct nodeS **ptrcgpa,float classtest,float assignment,float mid, float fi);
void ViewResult(long long int IDS);
struct routine *createclass(char day[30], char time[30], char subject[30]);
void addR();
void routinesave();
void printroutine();
void freeList();






int main(){

    fhead = (struct node *)malloc(sizeof(struct node));
    fhead-> id=24115463;
    fhead->pass=111111;
    fhead->phone=1910243870;
    strcpy(fhead->name,"Rahmatul Kabir Rasel Sarker");
    strcpy(fhead->des,"Lecturer");
    strcpy(fhead->address,"Dhaka");
    strcpy(fhead->mail,"raselsarker.cse@diu.edu.bd");
    fhead->next = NULL;

    headS = (struct nodeS *)malloc(sizeof(struct nodeS));
    headS-> id=24115463;
    headS->pass=111111;
    headS->phone=1910243870;
    strcpy(headS->name,"Akib Al Ashrafi");
    strcpy(headS->address,"Latifpur Colony Bogura Sadar");
    strcpy(headS->mail,"al241-15-463@diu.edu.bd");
    headS->next = NULL;

    
    long long int adminID=111,adminpassword=222;

    //Extract teacher info from file to node
    long long int id,pass,phone;
    char name[50],des[30],address[100],mail[50];

    FILE *fteacher;
    fteacher=fopen("fteacher.txt","r");
    while(fscanf(fteacher,"%lld\n%lld\n%lld\n%49[^\n]\n%29[^\n]\n%99[^\n]\n%49[^\n]\n",&id,&pass,&phone,name,des,address,mail)!=EOF){
        filetonodeT(id,pass,phone,name,des,address,mail);
        
        
    }
    fclose(fteacher);

    
    //Extract Student Info From File to Node
    long long int idS,passS,phoneS;
    char nameS[50],addressS[100],mailS[50];
    float attendanceS,assignmentS,midS,fiS,cgS;
    FILE *fstudent;
    fstudent=fopen("fstudent.txt","r");
    while(fscanf(fstudent,"%lld\n%lld\n%lld\n%49[^\n]\n%99[^\n]\n%49[^\n]\n%f\n%f\n%f\n%f\n%f\n",&idS,&passS,&phoneS,nameS,addressS,mailS,&attendanceS,&assignmentS,&midS,&fiS,&cgS)!=EOF){
        filetonodeS(idS, passS,phoneS,nameS,addressS,mailS,attendanceS,assignmentS,midS,fiS,cgS);
        
        
    }
    fclose(fstudent);    


    int back,exit=1;
    while(exit!=0){
        //Hoome Page layout
        printf("\n\033[1;36mStudent Management System\033[0m\n\n");
        printf("\033[1;32mNotice Board:\033[0m");
        notice_print();
        printf("Enter your choice (1 to 3).\n");
        printf("1. Admin\n2. Teacher\n3. Student\n\033[1;31mEnter 0 to exit.\033[0m\n");
        printf("Enter your choice: ");
        int choice; scanf("%d",&choice);

        switch(choice){
            case 0: printf("Closing\n");
            exit=0;
            break;

     // Admin Pannel
     // Admin Pannel

            case 1:
        verify();
        if(ID==adminID && Password==adminpassword){

            back=1;
            while(back!=0){
                printf("\n\033[1;36mAdmin Pannel\033[0m\n\n");
                printf("Enter 1 to 11\n");
                printf(" 1. Update Notice\n");
                printf(" 2. All Teachers\n");
                printf(" 3. Search Teacher\n");
                printf(" 4. Add Teacher\n");
                printf(" 5. Edit Teachers data\n");
                printf(" 6. Remove Teacher\n");
                printf(" 7. All Students\n");
                printf(" 8. Search Student\n");
                printf(" 9. Add Student\n");
                printf("10. Edit Students data\n");
                printf("11. Remove Student\n");
                printf("\033[1;31m0.Return To Homepage\033[0m\n");
                printf("Enter your choice: ");

                int choiceA; scanf("%d",&choiceA);
                switch(choiceA){

                    case 0:
                        back=0;
                    break;

                    //Notice Board
                    case 1: 
                        printf("\n\033[1;36mUpdate Notice\033[0m\n\n");
                        printf("Write The Notice: ");
                        notice_update();
                    break;

                    //All Teacher
                    case 2: 
                        printf("\n\033[1;36mAll Teachers\033[0m\n\n");
                        AllT();
                    break;

                    //Search Teacher
                    case 3: 
                        printf("\n\033[1;36mSearch Teacher\033[0m\n\n");
                        SearchT();
                    break;


                    //Add Teacher
                    case 4:
                        printf("\n\033[1;36mAdd Teacher\033[0m\n");
                        AddT();
                    break;

                    //Edit Teachers Data
                    case 5: 
                        printf("\n\033[1;36mEdit Teacher Information\033[0m\n");
                        EditT();
                    break;

                    //Remove Teacher Data
                    case 6: 
                        printf("\n\033[1;36mRemove Teacher\033[0m\n");
                        DelT();
                    break;

                    //All Students
                    case 7: 
                        printf("\n\033[1;36mAll Students\033[0m\n");
                        AllS();
                    break;

                    //Search Student
                    case 8: 
                        printf("\n\033[1;36mSearch Student\033[0m\n");
                        SearchS();
                    break;


                    //Add Student
                    case 9: 
                        printf("\n\033[1;36mAdd Student\033[0m\n");
                        AddS();
                    break;

                    //Edit Students Data
                    case 10: 
                        printf("\n\033[1;36mEdit Student Information\033[0m\n");
                        EditS();
                    break;

                    //Remove Student
                    case 11: 
                        printf("\n\033[1;36mRemove Student\033[0m\n");
                        DelS();
                    break;

                    default:
                    printf("Invalid Choice.\n");
                    break;
                }
               }

        } 
        else {
            printf("\n\033[1;31mInvalid ID or Password\033[0m\n");
        }  
            break;




        //Teachers Pannel
        //Teachers Pannel
        case 2: 
        long long int IDT,passwordT;
        printf("Enter ID: ");
        scanf("%lld",&IDT);
        printf("Enter Password: ");
        scanf("%lld",&passwordT);

        struct node *ptrT;
        ptrT=fhead->next;

        while(ptrT!=NULL && ptrT->id!=IDT){
            ptrT=ptrT->next;
        }

        if(ptrT!=NULL && ptrT->id==IDT && ptrT->pass==passwordT){
            int backT=1;
            while(backT!=0){
                printf("\n\033[1;36mTeachers Pannel\033[0m\n\n");
                printf(" 1. All Students\n");
                printf(" 2. Search Student\n");
                printf(" 3. Marks Update\n");
                printf(" 4. Class Routine Update\n");
                printf("\033[1;31m0.Return To Homepage\033[0m\n");
                printf("Enter your choice: ");
                int choiceT; scanf("%d",&choiceT);

                switch(choiceT){

                    case 0: 
                        backT=0;
                    break;

                    case 1: 
                        printf("\n\033[1;36mAll Students\033[0m\n");
                        AllS();
                    break;

                    case 2: 
                        printf("\n\033[1;36mSearch Student\033[0m\n");
                        SearchS();
                    break;

                    case 3: 
                        printf("\n\033[1;36mMarks Update\033[0m\n");
                        printf("Enter Student's ID: ");
                        long long sID; scanf("%lld",&sID);
                        struct nodeS *ptr3;
                        ptr3=headS;

                        while(ptr3!=NULL && ptr3->id!=sID){
                            ptr3=ptr3->next;
                        }

                        if(ptr3->id==sID){
                            int backM;

                            while(backM!=0){
                            printf("\n\n\033[1;32mMark Update\033[0m\n\n");
                            printf("1. Class Test Mark\n");
                            printf("2. Assignment Mark\n");;
                            printf("3. Mid Term Exam Mark\n");
                            printf("4. Final Exam Mark\n");
                            printf("\033[1;31m0.To Back\033[0m\n");
                            printf("Enter Your Choice: ");
                            int choiceM; scanf("%d",&choiceM);

                            switch(choiceM){
                            
                            case 0: 
                                backM=0;
                            break;

                            case 1: 
                                printf("\n\033[1;36mClass Test Mark\033[0m\n");
                                printf("Class test mark: ");
                                float ctmark; scanf("%f",&ctmark);
                                ptr3->classtest=ctmark;
                            break;

                            case 2: 
                                printf("\n\033[1;36mAssignment Mark\033[0m\n");
                                printf("Assignment mark: ");
                                float assignmark; scanf("%f",&assignmark);
                                ptr3->assignment=assignmark;
                            break;


                            case 3: 
                                printf("\n\033[1;36mMid Term Mark\033[0m\n");
                                printf("Mid Term mark: ");
                                float midmark; scanf("%f",&midmark);
                                ptr3->mid=midmark;
                            break;


                            case 4: 
                                printf("\n\033[1;36mFinal Exam Mark\033[0m\n");
                                printf("Final Exam Test mark: ");
                                float fimark; scanf("%f",&fimark);
                                ptr3->fi=fimark;
                            break;


                            default: 
                                printf("Invalid Choice.\n");
                            break;
                            
                        }
   
                        }

                    }

                    else {
                        printf("\n\033[1;31mStudent of ID:%lld dose not exist\033[0m\n",ID);
                    }
                    break;



                    case 4:
                        printf("\n\033[1;36mClass Routine Update\033[0m\n");
                        addR();
                        routinesave();
                    break;



                    default:
                        printf("Invalid choice.\n");
                    break;

                }

            }
        


        }


        else {
            printf("Invalid ID or Password.\n");
        }
        break;




        //Student Pannel
        //Student Pannel
        case 3: 
        long long int IDS,passwordS;
        printf("Enter ID: ");
        scanf("%lld",&IDS);
        printf("Enter Password: ");
        scanf("%lld",&passwordS);

        struct nodeS *ptrS;
        ptrS=headS->next;

        while(ptrS!=NULL && ptrS->id!=IDS){
            ptrS=ptrS->next;
        }

        if(ptrS!=NULL && ptrS->id==IDS && ptrS->pass==passwordS){
            int BackS=1;
            while(BackS!=0){
                printf("\n\033[1;36mStudent Pannel\033[0m\n\n");
                printf(" 1. View Routine\n");
                printf(" 2. View Result\n");
                printf("\033[1;31m0.Return To Homepage\033[0m\n");
                printf("Enter your choice: ");
                int choiceS; scanf("%d",&choiceS);

                switch(choiceS){
                    
                    case 0: 
                        BackS=0;
                    break;

                    case 1: 
                        printf("\n\033[1;36mClass Routine\033[0m\n\n");
                        printroutine();
                    break;


                    case 2: 
                        printf("\n\033[1;36mResult\033[0m\n\n");
                        ViewResult(IDS);
                    break;
                }

            }

        }

        else {
            printf("\n\033[1;31mInvalid ID or Password.\033[0m\n");
        }

        break;



            default:
                printf("\n\033[1;31mInvalid Choice.\033[0m\n");
            break;


        }
    }



    //Store teacher info in file
    struct node *tem=fhead->next;
    
    fteacher = fopen("fteacher.txt","w");
    while(tem!=NULL){
        fprintf(fteacher,"%lld\n%lld\n%lld\n%s\n%s\n%s\n%s\n",tem->id,tem->pass,tem->phone,tem->name,tem->des,tem->address,tem->mail);
        tem=tem->next;
    }
    fclose(fteacher);



    //Store Student info in file
    struct nodeS *temp=headS->next;
    
    fstudent = fopen("fstudent.txt","w");
    while(temp!=NULL){

        fprintf(fstudent,"%lld\n%lld\n%lld\n%s\n%s\n%s\n%f\n%f\n%f\n%f\n%f\n",temp->id,temp->pass,temp->phone,temp->name,temp->address,temp->mail,temp->classtest,temp->assignment,temp->mid,temp->fi,temp->cg);
        temp=temp->next;
    }
    fclose(fstudent);


    //free stroage
    freeList();




    return 0;
}







//User Verification
void verify(){
    printf("\nEnter ID Number: ");
    scanf("%lld",&ID);
    printf("Enter Password: ");
    scanf("%lld",&Password);
}



//Teacher Node Creation
struct node *createnode(long long int id, long long int pass,long long phone,char name[50],char des[30],char address[100],char mail[50]) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
        printf("Erorr: Memory allocation failed.\n");
        return NULL;
    }

    newnode->id = id;
    newnode->pass = pass;
    newnode->phone=phone;
    strcpy(newnode->name, name);
    strcpy(newnode->des, des);
    strcpy(newnode->address, address);
    strcpy(newnode->mail, mail);
    newnode->next = NULL;
    return newnode;
}



//Update Notice
void notice_update(){
    FILE *notice=fopen("notice.txt","w");
    char note[1000];
    getchar();
    fgets(note,1000,stdin);
    fprintf(notice,"%s",note);
    fclose(notice);
}



//Print Notice
void notice_print(){
    FILE *printnotice = fopen("notice.txt","r");
    char note[1000];
    while(fscanf(printnotice,"%s",&note)!=EOF){
        printf(" %s",note);
    }
    printf("\n\n");
    fclose(printnotice);
}



//Teacher file to node creation
void filetonodeT(long long int id, long long int pass,long long phone,char name[50],char des[30],char address[100],char mail[50]){
    
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->id = id;
    newnode->pass = pass;
    newnode->phone=phone;
    strcpy(newnode->name, name);
    strcpy(newnode->des, des);
    strcpy(newnode->address, address);
    strcpy(newnode->mail, mail);
    newnode->next = NULL;

    struct node *ptr=fhead;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
}



//Add Teacher
void AddT(){
    char ch,name[50],des[30],address[100],mail[50];
    long long int id,pass,phone;
    printf("\nEnter Name: ");
    getchar();
    gets(name);

    printf("Enter Designation: ");
    gets(des);

    printf("Phone Nmber: ");
    scanf("%lld",&phone);
    getchar();

    printf("Email Address: ");
    gets(mail);

    printf("Home Address: ");
    gets(address);


    printf("Enter ID: ");
    scanf("%lld",&id);


    printf("Enter Password(Digit only): ");
    scanf("%lld",&pass);
    getchar();

    struct node *newnode=createnode(id,pass,phone,name,des,address,mail);
    struct node *ptr7=fhead;
    while(ptr7->next!=NULL){
        ptr7=ptr7->next;
    }
    ptr7->next=newnode;
    printf("\n\033[1;32mTeacher added successflly\033[0m\n");
    return;
}



//All teacher details print
void AllT() {
    struct node *ptr = fhead->next;
    if(ptr!=NULL){
    while (ptr != NULL) {
        printf("Name        : %s\n", ptr->name);
        printf("ID          : %lld\n", ptr->id);
        printf("Designation : %s\n", ptr->des);
        printf("Phone Number: 0%lld\n",ptr->phone);
        printf("Email Addess: %s\n",ptr->mail);
        printf("Home Address: %s\n\n",ptr->address);
        ptr = ptr->next;
    }

    }
    
    else{
        printf("\nNo Teacher Information Exist, Please Add First.\n");
    }
}



//Edit Teacher's Information
void EditT(){
    long long int ID; 
    printf("\nEnter the ID Number: ");
    char ch;
    do{
        ch=getchar();
    }
    while(ch!= '\n' && ch !=EOF);
    scanf("%lld",&ID);
    struct node *ptr=fhead->next;

    while(ptr!=NULL && ptr->id!=ID){
        ptr=ptr->next;
    }

    if(ptr!=NULL && ptr->id==ID){
    char ch,name[50],des[30],address[100],mail[50];
    long long int id,pass,phone;
    printf("\nEnter Name: ");
    getchar();
    gets(name);

    printf("Enter Designation: ");
    gets(des);

    printf("Phone Nmber: ");
    scanf("%lld",&phone);
    getchar();

    printf("Email Address: ");
    gets(mail);

    printf("Home Address: ");
    gets(address);


    printf("Enter Password(Digit only): ");
    scanf("%lld",&pass);

    ptr->pass = pass;
    ptr->phone=phone;
    strcpy(ptr->name, name);
    strcpy(ptr->des, des);
    strcpy(ptr->address, address);
    strcpy(ptr->mail, mail);

    printf("\n\033[1;32mTeacher Details Upadated Successfully\033[0m\n");
        printf("Name        : %s\n", ptr->name);
        printf("ID          : %lld\n", ptr->id);
        printf("Designation : %s\n", ptr->des);
        printf("Phone Number: 0%lld\n",ptr->phone);
        printf("Email Addess: %s\n",ptr->mail);
        printf("Home Address: %s\n\n",ptr->address);

    }

    else {
        printf("\n\033[1;31mTeacher details not found\033[0m\n");
    }

}



//Search Teacher
void SearchT(){
        long long int ID; 
    printf("\nEnter the ID Number: ");
    scanf("%lld",&ID);
    struct node *ptr=fhead;

    while(ptr!=NULL && ptr->id!=ID){
        ptr=ptr->next;
    }

    if(ptr->id==ID){
        printf("\n\n\033[1;32mTeacher Details\033[0m\n\n");
        printf("Name        : %s\n", ptr->name);
        printf("ID          : %lld\n", ptr->id);
        printf("Designation : %s\n", ptr->des);
        printf("Phone Number: 0%lld\n",ptr->phone);
        printf("Email Addess: %s\n",ptr->mail);
        printf("Home Address: %s\n\n",ptr->address);

    }

    else {
        printf("\n\033[1;31mTeacher with ID:%lld dose not exist\033[0m\n",ID);
    }

}



//Delete Teacher
void DelT(){
    long long int ID; 
    printf("Enter the ID Number: ");
    char ch;
    do{
        ch=getchar();
    }
    while(ch!= '\n' && ch !=EOF);
    scanf("%lld",&ID);
    struct node *ptr=fhead;
    struct node *ptr1=fhead;

    while(ptr->next!=NULL){
        if(ptr->id==ID){
            break;
        }
        ptr1=ptr;
        ptr=ptr->next;
    }

    if(ptr->id==ID){
        ptr1->next=ptr->next;
        free(ptr);
        printf("\n\033[1;32mDeletion Successful\033[0m\n");
    }

    else {
        printf("\n\033[1;31mNo teacher exist on ID number: %lld\033[0m\n",ID);
    }
}



//extract from file to node
struct nodeS *createnodeS(long long int id, long long int pass,long long phone,char name[50],char address[100],char mail[50],float classtest,float assignment,float mid, float fi,float cg) {
    struct nodeS *newnode = (struct nodeS *)malloc(sizeof(struct nodeS));
        if (newnode == NULL) {
        printf("Erorr: Memory allocation failed.\n");
        return NULL;
    }

    newnode->id = id;
    newnode->pass = pass;
    newnode->phone= phone;
    newnode->classtest = classtest;
    newnode->assignment = assignment;
    newnode->mid = mid;
    newnode->fi = fi;
    newnode->cg = cg;
    strcpy(newnode->name, name);
    strcpy(newnode->address, address);
    strcpy(newnode->mail, mail);
    newnode->next = NULL;
    return newnode;
}



//Extract Student info from file to node
void filetonodeS(long long int id, long long int pass,long long phone,char name[50],char address[100],char mail[50],float classtest,float assignment,float mid, float fi,float cg){
    
    struct nodeS *newnode = (struct nodeS *)malloc(sizeof(struct nodeS));
    newnode->id = id;
    newnode->pass = pass;
    newnode->phone=phone;
    newnode->classtest = classtest;
    newnode->assignment = assignment;
    newnode->mid = mid;
    newnode->fi = fi;
    newnode->cg = cg;
    strcpy(newnode->name, name);
    strcpy(newnode->address, address);
    strcpy(newnode->mail, mail);
    newnode->next = NULL;

    struct nodeS *ptr=headS;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
}



// Add Student data
void AddS() {
    char name[50],address[100],mail[50];
    long long int id, pass,phone;
    float classtest=0,assignment=0,mid=0,fi=0,cg=0;

    getchar();
    printf("\nEnter Student's Name: ");
    gets(name);

    printf("Enter id Number: ");
    scanf("%lld", &id);

    printf("Enter Phone Number: ");
    scanf("%lld",&phone);
    getchar();

    printf("Email Address: ");
    gets(mail);

    printf("Enter Address: ");
    gets(address);

    printf("Enter Password: ");
    scanf("%lld", &pass);

    struct nodeS *newnode = createnodeS(id, pass,phone,name,address,mail,classtest,assignment,mid,fi,cg);
    if (newnode == NULL) {
        return;
    }
    struct nodeS *ptr=headS;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    
    printf("\n\033[1;32mStudent added successflly\033[0m\n");
}



//Edit student info
void EditS(){
        long long int ID; 
    printf("\nEnter the ID Number: ");
    scanf("%lld",&ID);
    struct nodeS *ptr=headS->next;

    while(ptr!=NULL && ptr->id!=ID){
        ptr=ptr->next;
    }

    if(ptr!=NULL && ptr->id==ID){
        char name[50],address[100],mail[50];
    long long int id, pass,phone;


    printf("\nEnter Student's Name: ");
    getchar();
    gets(name);

    printf("Enter id Number: ");
    scanf("%lld", &id);

    printf("Enter Phone Number: ");
    scanf("%lld",&phone);
    getchar();

    printf("Email Address: ");
    gets(mail);

    printf("Enter Address: ");
    gets(address);

    printf("Enter Password: ");
    scanf("%lld", &pass);


    ptr->pass = pass;
    ptr->phone=phone;
    strcpy(ptr->name, name);
    strcpy(ptr->address, address);
    strcpy(ptr->mail, mail);

    printf("\n\033[1;32mStudent Details Upadated Successfully\033[0m\n");
        printf("Name           : %s\n", ptr->name);
        printf("id             : %lld\n", ptr-> id);
        printf("Contact Number : 0%lld\n", ptr->phone);
        printf("Adress         : %s\n", ptr->address);
        printf("Email          : %s\n\n", ptr->mail);

    }

    else {
        printf("\n\033[1;31mStudent details not found\033[0m\n");
    }

}



//Delete Student info
void DelS(){
    long long int ID; 
    printf("Enter the ID Number: ");
    scanf("%lld",&ID);
    struct nodeS *ptr=headS;
    struct nodeS *ptr1=headS;

    while(ptr->next!=NULL){
        if(ptr->id==ID){
            break;
        }
        ptr1=ptr;
        ptr=ptr->next;
    }

    if(ptr->id==ID){
        ptr1->next=ptr->next;
        free(ptr);
        printf("\n\033[1;32mDeletion Successful\033[0m\n\n");
    }

    else {
        printf("\n\033[1;31mNo student exist on ID number: %lld\033[0m\n",ID);
    }

}



//Search Student
void SearchS(){
        long long int ID; 
    printf("\nEnter the ID Number: ");
    scanf("%lld",&ID);
    struct nodeS *ptr=headS;

    while(ptr!=NULL && ptr->id!=ID){
        ptr=ptr->next;
    }

    if(ptr->id==ID){
        printf("\n\n\033[1;32mStudent Details\033[0m\n\n");
        printf("Name           : %s\n", ptr->name);
        printf("id             : %lld\n", ptr-> id);
        printf("Contact Number : 0%lld\n", ptr->phone);
        printf("Email          : %s\n", ptr->mail);
        printf("Address        : %s\n", ptr->address);
        printf("Class Test Mark: %.2f\n", ptr->classtest);
        printf("Assignment Mark: %.2f\n", ptr->assignment);
        printf("Mid Term Mark  : %.2f\n", ptr->mid);
        printf("Final Exam Mark: %.2f\n", ptr->fi);
        CGPA(&ptr,ptr->classtest,ptr->assignment,ptr->mid,ptr->fi);

    }

    else {
        printf("\n\033[1;31mStudent with ID:%lld dose not exist\033[0m\n",ID);
    }

}



//All Students List
void AllS() {
    struct nodeS *ptr = headS->next;
    if(ptr!=NULL){
    while (ptr != NULL) {
        printf("Name           : %s\n", ptr->name);
        printf("id             : %lld\n", ptr-> id);
        printf("Contact Number : 0%lld\n", ptr->phone);
        printf("Email          : %s\n", ptr->mail);
        printf("Address        : %s\n", ptr->address);
        printf("Class Test Mark: %.2f\n", ptr->classtest);
        printf("Assignment Mark: %.2f\n", ptr->assignment);
        printf("Mid Term Mark  : %.2f\n", ptr->mid);
        printf("Final Exam Mark: %.2f\n", ptr->fi);
        printf("CGPA           : %.2f\n\n", ptr->cg);
        ptr = ptr->next;
    }

    }

    else{
        printf("\nNo Student Data Exist, Please Add first.\n");
    }
}



//CGPA calculation
void CGPA(struct nodeS **ptrcgpa,float classtest,float assignment,float mid, float fi){
    float sum=classtest+assignment+mid+fi;
    if(sum>=80){
        printf("\n\033[1;35mCGPA:\033[0m %.2f      \033[1;35mGrade:\033[0m A+\n",4.00);
    }

    else if(sum>=75 && sum<80){
        printf("\n\033[1;35mCGPA:\033[0m %.2f      \033[1;35mGrade:\033[0m A\n",3.75);
    }

        else if(sum>=70 && sum<75){
        printf("\n\033[1;35mCGPA:\033[0m %.2f      \033[1;35mGrade:\033[0m A-\n",3.50);
    }

        else if(sum>=65 && sum<70){
        printf("\n\033[1;35mCGPA:\033[0m %.2f      \033[1;35mGrade:\033[0m B+\n",3.25);
    }

        else if(sum>=60 && sum<65){
        printf("\n\033[1;35mCGPA:\033[0m %.2f      \033[1;35mGrade:\033[0m B\n",3.00);
    }

        else if(sum>=55 && sum<60){
        printf("\n\033[1;35mCGPA:\033[0m %.2f      \033[1;35mGrade:\033[0m B-\n",2.75);
    }

        else if(sum>=50 && sum<55){
        printf("\n\033[1;35mCGPA:\033[0m %.2f      \033[1;35mGrade:\033[0m C+\n",2.50);
    }

        else if(sum>=45 && sum<50){
        printf("\n\033[1;35mCGPA:\033[0m %.2f      \033[1;35mGrade:\033[0m C\n",2.25);
    }

        else if(sum>=40 && sum<45){
        printf("\n\033[1;35mCGPA:\033[0m %.2f      \033[1;35mGrade:\033[0m D\n",2.00);
    }

    else{
        printf("\n\033[1;35mCGPA:\033[0m \033[1;31m%.2f\033[0m      \033[1;35mGrade:\033[0m \033[1;31mF\033[0m\n",0.00);
    }

}



//View Result
void ViewResult(long long int IDS){

    struct nodeS *ptr=headS;

    while(ptr->id!=IDS){
        ptr=ptr->next;
    }

    if(ptr->id==IDS){
        printf("\n\n\033[1;32mView Result\033[0m\n\n");

        printf("Class Test Mark: %.2f\n", ptr->classtest);
        printf("Assignment Mark: %.2f\n", ptr->assignment);
        printf("Mid Term Mark  : %.2f\n", ptr->mid);
        printf("Final Exam Mark: %.2f\n", ptr->fi);
        CGPA(&ptr,ptr->classtest,ptr->assignment,ptr->mid,ptr->fi);

    }



}



//Create routine Node
struct routine *createclass(char day[30], char time[30], char subject[30]) {
    struct routine *newnode = (struct routine *) malloc(sizeof(struct routine));
    strcpy(newnode->day, day);
    strcpy(newnode->time, time);
    strcpy(newnode->subject, subject);
    newnode->next = NULL;

    return newnode;
}



//Update Routine
void addR() {
    char day[30];
    char time[30];
    char subject[30];

    printf("\nEnter class count in a week: ");
    int count;
    scanf("%d", &count);
    getchar();  

    for (int i = 1; i <= count; i++) {
        printf("\nEnter Day %d Class details:\n", i);
        printf("Day: ");
        gets(day);


        printf("Time: ");
        gets(time);


        printf("Course: ");
        gets(subject);

        struct routine *newday = createclass(day, time, subject);

        if (headR == NULL) {
            headR = newday;
        } else {
            struct routine *ptr = headR;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newday;
        }

    }
    printf("\n\033[1;32mRoutine Updated Successfully\033[0m\n");
}



//Save the routine to file
void routinesave(){
    struct routine *ptr=headR;
    FILE *schedule= fopen("schedule.txt","w");
    while(ptr!=NULL){
        fprintf(schedule, "%s\n%s\n%s\n\n",ptr->day,ptr->time,ptr->subject);
        ptr=ptr->next;
    }

    fclose(schedule);
}


//Printing Routine
void printroutine(){
    FILE *schedule= fopen("schedule.txt","r");
    char day[30];
    char time[30];
    char subject[30];

    while(fscanf(schedule,"%s\n%s\n%s\n\n",day,time,subject)!=EOF){
        printf("\nDay: %s\n",day);
        printf("Time: %s\n",time);
        printf("Course: %s\n\n",subject);
    }

    fclose(schedule);
}


// Free the allocated memory
void freeList() {

    struct node *temp1;
    struct nodeS *temp2;
    struct routine *temp3;
    
    
    while (fhead!=NULL || headS != NULL || headR != NULL) {
        temp1 = fhead;
        headR = headR->next;
        free(temp1);

        temp2 = headS;
        headR = headR->next;
        free(temp2);

        temp3 = headR;
        headR = headR->next;
        free(temp3);
    }

}
