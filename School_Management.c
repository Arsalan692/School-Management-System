#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#define MAX_SIZE 1024


//Admin's Panel--
int delete_teacher(){
    system("cls");
    FILE *fp;
    FILE *fp2;
    fp  = fopen("teachers.txt", "r+");
    fp2 = fopen("temp.txt", "w");
    char str[150];
    char loc[20];
    char roll[20];

    printf("Enter the ID of the teacher to delete: ");
    scanf("%s", roll);

    int line_num = 1;
    int total_lines = -1;
    int count = 0;
    while (!feof(fp))   
    {
        fgets(str, 150, fp);
        total_lines++;
    }
    
    rewind(fp);

    while (!feof(fp))
    {
        fgets(str, 150, fp);
        int i = 1;
        for (; i < strlen(str) - 1; i++)
        {
            if (str[i] == ',')
            {
                break;
            }

            loc[i - 1] = str[i];
        }
        loc[i-1] = '\0';
        if (strcmp(roll, loc) == 0)
        {   
            count++;
            break;
        }
        else
        {
            line_num++;
        }
    }
    
    if (count == 0)
    {
        printf("No record found!");
        exit(1);
    }
    
    rewind(fp);
    int line_counter = 1;           
    while (line_counter <= total_lines)
    {   
        fgets(str, 150, fp);
        if (line_counter == line_num)
        {
            line_counter++;
            continue;
        }
        
        fputs(str,fp2);
        line_counter++;
    }
    fclose(fp2);
    fclose(fp);
    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");
    printf("Teacher removed successfully\n");
    int yu;
    printf("Press 0 to return to the menu : ");
    scanf("%d", &yu);
}

int delete_student(){
    system("cls");
    FILE *fp;
    FILE *fp2;
    fp  = fopen("students.txt", "r+");
    fp2 = fopen("temp.txt", "w");
    char str[150];
    char loc[20];
    char roll[20];

    printf("Enter the roll number of the student to delete: ");
    scanf("%s", roll);

    int line_num = 1;
    int total_lines = -1;
    int count = 0;
    while (!feof(fp))   
    {
        fgets(str, 150, fp);
        total_lines++;
    }
    
    rewind(fp);

    while (!feof(fp))
    {
        fgets(str, 150, fp);
        
        for (int i = 1; i < strlen(str) - 1; i++)
        {
            if (str[i] == ',')
            {
                break;
            }

            loc[i - 1] = str[i];
        }
        if (strcmp(roll, loc) == 0)
        {   
            count++;
            break;
        }
        else
        {
            line_num++;
        }
    }
    
    if (count == 0)
    {
        printf("No record found!");
        exit(1);
    }
    
    rewind(fp);
    int line_counter = 1;           
    while (line_counter <= total_lines)
    {   
        fgets(str, 150, fp);
        if (line_counter == line_num)
        {
            line_counter++;
            continue;
        }
        
        fputs(str,fp2);
        line_counter++;
    }
    fclose(fp2);
    fclose(fp);
    remove("students.txt");
    rename("temp.txt", "students.txt");
    printf("Student removed successfully\n");
    int yu;
    printf("Press 0 to return to the menu : ");
    scanf("%d", &yu);

   
}

int edit_student() {
    FILE *fp;
    FILE *fp2;
    fp  = fopen("students.txt", "r+");
    fp2 = fopen("temp.txt", "w");
    if (fp == NULL || fp2 == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char str[150];
    char loc[20];
    char roll[20];
    int comma_num = 0;
    char new[50];

    system("cls");
    printf("Enter the Roll Number of the student you want to edit the credentials of: ");
    scanf("%s", roll);
    

    int line_num = 1;
    int total_lines = -1;
    int count = 0;
    
    while (!feof(fp))   
    {
        fgets(str, 150, fp);
        total_lines++;
    }
   
    rewind(fp);

    while (!feof(fp))
    {
        fgets(str, 150, fp);
        int i = 1;
        for (; i < strlen(str) - 1; i++)
        {
            if (str[i] == ',')
            {
                break;
            }

            loc[i - 1] = str[i];
        }
        loc[i-1] = '\0';
        if (strcmp(roll, loc) == 0)
        {   
            count++;
            break;
        }
        else
        {
            line_num++;
        }
    }
    
    if (count == 0)
    {
        printf("No record found! Exiting...");
        exit(1);
    }
    
     
    system("cls");
    printf("\n----------- EDITING MENU -----------\n");
    printf("(1) Edit Name \n");
    printf("(2) Edit Email \n");
    printf("(3) Edit Password \n");
    printf("(4) Edit Phone Number \n");
    printf("(5) Edit Class \n");
    printf("Enter your choice: ");
    scanf("%d", &comma_num);
    if (comma_num > 5 || comma_num < 1) {
        printf("Invalid choice. Exiting...\n");
        fclose(fp);
        fclose(fp2);
        exit(1);
    }
    system("cls");
    printf("Enter the new value: ");
    scanf("\n");
    scanf("%[^\n]%*c", new);

    rewind(fp);
    int comma_counter = 0;
    int line_counter = 1;           
    while (line_counter <= total_lines)
    {   
        fgets(str, 150, fp);

        if (line_counter == line_num)
        {   

            for (int i = 0; i < strlen(str)-1; i++)
            {   
                if (comma_counter != comma_num)
                {
                    fprintf(fp2,"%c", str[i]);
                }
                else{
                    
                    if (str[i+1] == ',')
                    {
                        
                        fprintf(fp2," %s," ,new);
                    }
                    
                    
                }
                

                if (str[i] == ',')
                {
                    comma_counter++;
                }
                
            }
            fprintf(fp2,"\n");
            line_counter++;
            continue;
        }
        
        fputs(str,fp2);
        line_counter++;
    }
    fclose(fp2);
    fclose(fp);
    remove("students.txt");
    rename("temp.txt", "students.txt");
    printf("\n\nEdited successfully\n");
    int ed;
    printf("Press 0 to return to the menu : ");
    scanf("%d", &ed);

    return 0;
}

void edit_teacher() {
    FILE *fp;
    FILE *fp2;
    fp  = fopen("teachers.txt", "r+");
    fp2 = fopen("temp.txt", "w");
    if (fp == NULL || fp2 == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char str[150];
    char loc[20];
    char roll[20];
    int comma_num = 0;
    char new[50];

    system("cls");
    printf("Enter the ID of the teacher you want to edit the credentials of: ");
    scanf("%s", roll);
    

    int line_num = 1;
    int total_lines = -1;
    int count = 0;
    
    while (!feof(fp))   
    {
        fgets(str, 150, fp);
        total_lines++;
    }
   
    rewind(fp);

    while (!feof(fp))
    {
        fgets(str, 150, fp);
        int i = 1;
        for (; i < strlen(str) - 1; i++)
        {
            if (str[i] == ',')
            {
                break;
            }

            loc[i - 1] = str[i];
        }
        loc[i-1] = '\0';
        if (strcmp(roll, loc) == 0)
        {   
            count++;
            break;
        }
        else
        {
            line_num++;
        }
    }
    
    if (count == 0)
    {
        printf("No record found!");
        exit(1);
    }
    
     
    system("cls");
    printf("\n----------- EDITING MENU -----------\n");
    printf("(1) Edit Name \n");
    printf("(2) Edit Email \n");
    printf("(3) Edit Password \n");
    printf("(4) Edit Phone Number \n");
    printf("Enter your choice: ");
    scanf("%d", &comma_num);
    if (comma_num > 4 || comma_num < 1) {
        printf("Invalid choice. Exiting...\n");
        fclose(fp);
        fclose(fp2);
        exit(1);
    }
    system("cls");
    printf("Enter the new value: ");
    scanf("\n");
    scanf("%[^\n]%*c", new);

    rewind(fp);
    int comma_counter = 0;
    int line_counter = 1;           
    while (line_counter <= total_lines)
    {   
        fgets(str, 150, fp);

        if (line_counter == line_num)
        {   

            for (int i = 0; i < strlen(str)-1; i++)
            {   
                if (comma_counter != comma_num)
                {
                    fprintf(fp2,"%c", str[i]);
                }
                else{
                    
                    if (str[i+1] == ',')
                    {
                        
                        fprintf(fp2," %s," ,new);
                    }
                    
                    
                }
                

                if (str[i] == ',')
                {
                    comma_counter++;
                }
                
            }
            fprintf(fp2,"\n");
            line_counter++;
            continue;
        }
        
        fputs(str,fp2);
        line_counter++;
    }
    fclose(fp2);
    fclose(fp);
    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");
    printf("Edited successfully\n");
    int edt;
    printf("Press 0 to return to the menu : ");
    scanf("%d", &edt);

}

int show_a_teacher(){
    FILE *fp;
    fp = fopen("teachers.txt", "a+");

    // search teacher
    system("cls");
    char str[100];
    char id[50];
    char loc[50];
    printf("Enter ID of the Teacher you want to see credentials of: ");
    scanf("\n");
    scanf("%[^\n]%*c", id);
    show_teacher_label1:
    if (feof(fp))
    {   
        printf("No record found!");
        exit(0);
    }
    
    fgets(str, 100, fp);
    int i;
    for (i = 1; i < strlen(str)-1; i++)
    {   if (str[i] == ',')
        {
            break;
        }
    
        loc[i-1] = str[i];
    }
    loc[i-1] = '\0';
    // printf("%s\n", id);
    // printf("%s\n", loc);
    if (strcmp(id, loc) == 0)
    {   int i = 1;
        printf("\nTeacher's ID: ");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nName:");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nEmail:");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nPassword:");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nPhone:");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nNumber of subjects teaching:");
        while (str[i] != ',')
        {
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nSalary:");
        while (str[i] != ',')
        {
            if (str[i] == '}')
            {
                break;
            }
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        
    }
    else{
        goto show_teacher_label1;
    }
    int c = 1;
    printf("\nPress 0 to return to the menu : ");
    scanf("%d", &c);
    
    


    fclose(fp);


}

int show_a_student(){
    FILE *fp;
    fp = fopen("students.txt", "a+");

    // search student
    system("cls");
    char str[100];
    char roll[50];
    char loc[50];
    printf("Enter Roll Number of the Student you want to see credentials of: ");
    scanf("\n");
    scanf("%[^\n]%*c", roll);
    show_student_label1:
    if (feof(fp))
    {   
        printf("No record found!");
        exit(0);
    }
    
    fgets(str, 100, fp);
    int i;
    for (i = 1; i < strlen(str)-1; i++)
    {   if (str[i] == ',')
        {
            break;
        }
    
        loc[i-1] = str[i];
    }
    loc[i-1] = '\0';
    if (strcmp(roll, loc) == 0)
    {   int i = 1;
        printf("\nRoll Number: ");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nName:");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nEmail:");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nPassword:");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nPhone:");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nClass:");
        while (str[i] != ',')
        {
            if (str[i] == '}')
            {
                break;
            }
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        
    }
    else{
        goto show_student_label1;
    }
    int c = 1;
    printf("\nPress 0 to return to the menu : ");
    scanf("%d", &c);
    
    


    fclose(fp);


}

int add_student(){
    FILE *fp;

    fp = fopen("students.txt", "a+");
    // adding a student
    system("cls");
    char name[50];
    char roll_num[50];
    int class=0;
    char email[50];
    char pass[50];
    char phone[50];
    
    printf("Enter student's roll number : ");
    scanf("\n");
    scanf("%[^\n]%*c",roll_num);
    // checking whether it already exist
    char str[100];
    char loc[50];
    while (!feof(fp))
    {
    
    
    fgets(str, 100, fp);
    if (str[0] == '\0')
    {
        break;
    }
    for (int i = 1; i < strlen(str)-1; i++)
    {   if (str[i] == ',')
        {
            break;
        }
    
        loc[i-1] = str[i];
        
    }
    if (strcmp(roll_num, loc) == 0)
    {   
        
        printf("Error! Roll number already exists \n");
        exit(0);
    }

    }


    // check ends here
    printf("Enter student's name : ");
    scanf("\n");
    scanf("%[^\n]%*c", name);
    printf("Enter student's email : ");
    scanf("\n");
    scanf("%[^\n]%*c", email);
    printf("Enter student's password (8 characters): ");
    scanf("\n");
    scanf("%[^\n]%*c", pass);
    printf("Enter student's guardian's phone number : ");
    scanf("\n");
    scanf("%[^\n]%*c", phone);
    printf("Enter student's class : ");
    scanf("%d", &class);
    fprintf(fp,"{");
    fprintf(fp,"%s, ",roll_num);
    fprintf(fp,"%s, ",name);
    fprintf(fp,"%s, ",email);
    fprintf(fp,"%s, ",pass);
    fprintf(fp,"%s, ",phone);
    fprintf(fp,"%d, ",class);
    fprintf(fp,"00, ");
    fprintf(fp,"00");

    fprintf(fp,"}\n");

    
    fclose(fp);
}

int add_teacher(){
    FILE *fp;

    fp = fopen("teachers.txt", "a+");
    // adding a teacher
    system("cls");
    char teacher_id[50];
    char name[50];
    
    char email[50];
    char pass[50];
    char phone[50];
    int no_of_subjects = 0;
    int salary = 0;
    
    printf("Enter teacher's ID : ");
    scanf("\n");
    scanf("%[^\n]%*c",teacher_id);
    // checking whether it already exist
    char str[100];
    char loc[50];
    while (!feof(fp))
    {
    fgets(str, 100, fp);
    if (str[0] == '\0')
    {
        break;
    }
    for (int i = 1; i < strlen(str)-1; i++)
    {   if (str[i] == ',')
        {
            break;
        }
    
        loc[i-1] = str[i];
        
    }
    if (strcmp(teacher_id, loc) == 0)
    {   
        
        printf("Error! Teacher ID already exists \n");
        exit(0);
    }

    }

    // check ends here
    printf("Enter teacher's name : ");
    scanf("\n");
    scanf("%[^\n]%*c", name);
    printf("Enter teacher's email : ");
    scanf("\n");
    scanf("%[^\n]%*c", email);
    printf("Enter teacher's password (8 characters): ");
    scanf("\n");
    scanf("%[^\n]%*c", pass);
    printf("Enter teacher's phone number : ");
    scanf("\n");
    scanf("%[^\n]%*c", phone);
    printf("Enter total number of subjects (max subjects are 5): ");
    scanf("%d", &no_of_subjects);

    fprintf(fp,"{");
    fprintf(fp,"%s, ",teacher_id);
    fprintf(fp,"%s, ",name);
    fprintf(fp,"%s, ",email);
    fprintf(fp,"%s, ",pass);
    fprintf(fp,"%s, ",phone);
    fprintf(fp,"%d, ",no_of_subjects);
    fprintf(fp,"%d",no_of_subjects*5000);

    fprintf(fp,"}\n");

    
    fclose(fp);
    
}

int see_all_students(){
    system("cls");
    FILE *fp;
    fp = fopen("students.txt", "a+");
    printf("|===================|====================|==============================|======================|====================|================|\n");
    printf("|    Roll Number    |        Name        |            Email             |      Password        |        Phone       |      class     |\n");
    printf("|===================|====================|==============================|======================|====================|================|\n");
    
    char str[100];
    char name[50];
    char roll_num[50];
    char phone[50];
    char class1[50];
    char email[50];
    char pass[50];
    int indexer = 0;
    int counter = 0;

    label1:
    
    str[0]='\0';
    fgets(str, 100, fp);
    
    if(str[0]=='\0'){
        goto label3;
    }

    int i = 1;
        while (str[i] != ',')
        {
            
            roll_num[indexer] = str[i];
            i++;
            indexer++;
        }
        roll_num[indexer]='\0';
        i++;
        indexer = 0;
        while (str[i] != ',')
        {
            
            name[indexer] = str[i];
            i++;
            indexer++;
        }
        name[indexer]='\0';
        i++;
        indexer = 0;
        while (str[i] != ',')
        {
            
            email[indexer] = str[i];
            i++;
            indexer++;
        }
        email[indexer]='\0';
        i++;
        indexer = 0;
        while (str[i] != ',')
        {
            
            pass[indexer] = str[i];
            i++;
            indexer++;
        }
        pass[indexer]='\0';
        i++;
        indexer = 0;
        while (str[i] != ',')
        {
            
            phone[indexer] = str[i];
            i++;
            indexer++;
        }
        phone[indexer]='\0';
        i++;
        indexer = 0;
        while (str[i] != ',')
        {
            if (str[i] == '}')
            {
                break;
            }
            class1[indexer] = str[i];
            i++;
            indexer++;
        }
        class1[indexer]='\0';
        i++;
        indexer = 0;
    

    
    if (counter > 0)
    {
        printf("\n");
    }
    counter++;
    
    printf("|");
    printf(" ");
    
    printf("%s", roll_num);
    for (int l = 1; l < 19-strlen(roll_num); l++)
    {
        printf(" ");
    }
    printf("|");
    printf("%s", name);
    for (int l = 1; l < 21-strlen(name); l++)
    {
        printf(" ");
    }
    printf("|");
    printf("%s", email);
    for (int l = 1; l < 31-strlen(email); l++)
    {
        printf(" ");
    }
    printf("|");
    printf("%s", pass);
    for (int l = 1; l < 23-strlen(pass); l++)
    {
        printf(" ");
    }
    printf("|");
    printf("%s", phone);
    for (int l = 1; l < 21-strlen(phone); l++)
    {
        printf(" ");
    }
    printf("|");
    printf("%s", class1);
    for (int l = 1; l < 17-strlen(class1); l++)
    {
        printf(" ");
    }
    printf("|");

    if (!feof(fp))
    {
        
        goto label1;
    }
    
    
    label3:
    printf("\n|-------------------|--------------------|------------------------------|----------------------|--------------------|----------------|\n");
 
    fclose(fp);
    int c = 1;
    printf("\nPress 0 to return to the menu : ");
    scanf("%d", &c);
    
}

int see_all_teachers(){
    system("cls");
    FILE *fp;
    fp = fopen("teachers.txt", "a+");
    printf("|===================|====================|==============================|======================|====================|==================|\n");
    printf("|    Teacher ID     |        Name        |            Email             |      Password        |        Phone       |  Total Subjects  |\n");
    printf("|===================|====================|==============================|======================|====================|==================|\n");
    
    char str[100];
    char name[50];
    char id[50];
    char phone[50];
    char no_of_sub[50];
    char email[50];
    char pass[50];
    int indexer = 0;
    int counter = 0;
    see_all_label1:
    
    str[0]='\0';
    fgets(str, 100, fp);
    
    if(str[0]=='\0'){
        goto see_all_label3;
    }

    int i = 1;
        while (str[i] != ',')
        {
            
            id[indexer] = str[i];
            i++;
            indexer++;
        }
        id[indexer]='\0';
        i++;
        indexer = 0;
        while (str[i] != ',')
        {
            
            name[indexer] = str[i];
            i++;
            indexer++;
        }
        name[indexer]='\0';
        i++;
        indexer = 0;
        while (str[i] != ',')
        {
            
            email[indexer] = str[i];
            i++;
            indexer++;
        }
        email[indexer]='\0';
        i++;
        indexer = 0;
        while (str[i] != ',')
        {
            
            pass[indexer] = str[i];
            i++;
            indexer++;
        }
        pass[indexer]='\0';
        i++;
        indexer = 0;
        while (str[i] != ',')
        {
            
            phone[indexer] = str[i];
            i++;
            indexer++;
        }
        phone[indexer]='\0';
        i++;
        indexer = 0;
        while (str[i] != ',')
        {
            if (str[i] == '}')
            {
                break;
            }
            no_of_sub[indexer] = str[i];
            i++;
            indexer++;
        }
        no_of_sub[indexer]='\0';
        i++;
        indexer = 0;
    

    // label2:
    if (counter > 0)
    {
        printf("\n");
    }
    counter++;
    
    printf("|");
    printf(" ");
    
    printf("%s", id);
    for (int l = 1; l < 19-strlen(id); l++)
    {
        printf(" ");
    }
    printf("|");
    printf("%s", name);
    for (int l = 1; l < 21-strlen(name); l++)
    {
        printf(" ");
    }
    printf("|");
    printf("%s", email);
    for (int l = 1; l < 31-strlen(email); l++)
    {
        printf(" ");
    }
    printf("|");
    printf("%s", pass);
    for (int l = 1; l < 23-strlen(pass); l++)
    {
        printf(" ");
    }
    printf("|");
    printf("%s", phone);
    for (int l = 1; l < 21-strlen(phone); l++)
    {
        printf(" ");
    }
    printf("|");
    printf("%s", no_of_sub);
    for (int l = 1; l < 19-strlen(no_of_sub); l++)
    {
        printf(" ");
    }
    printf("|");


    if (!feof(fp))
    {
        
        goto see_all_label1;
    }
    
    
    see_all_label3:
    printf("\n|-------------------|--------------------|------------------------------|----------------------|--------------------|------------------|\n");
 
    fclose(fp);
    int c = 1;
    printf("\nPress 0 to return to the menu : ");
    scanf("%d", &c);
}

int admin_menu()
{
    
    int ch1 =1 ;
    while (ch1 != 11)
    {
        system("cls");
        printf("\n/////////////// ADMIN MENU ///////////////\n");
        printf("(1) Add a student \n");
        printf("(2) Add a Teacher \n");
        printf("(3) See all Students \n");
        printf("(4) See all Teachers \n");
        printf("(5) Show credentials of a particular student \n");
        printf("(6) Show credentials of a particular teacher \n");
        printf("(7) Edit credentials of a particular student \n");
        printf("(8) Edit credentials of a particular teacher \n");
        printf("(9) Delete a student \n");
        printf("(10) Delete a teacher \n");
        printf("(11) Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &ch1);
        if (ch1 == 1)
        {
            add_student();
        }
        else if (ch1 == 2){

            add_teacher();   
        }
        else if (ch1 == 3)
        {
            see_all_students();
        }
        else if (ch1 == 4)
        {
            see_all_teachers();
        }
        else if (ch1 == 5)
        {
            show_a_student();
        }
        else if (ch1 == 6)
        {
            show_a_teacher();
        }
        else if (ch1 == 7)
        {
            edit_student();
        }
        else if (ch1 == 8)
        {
            edit_teacher();
        }
        else if (ch1 == 9)
        {
            delete_student();
        }
        else if (ch1 == 10)
        {
            delete_teacher();
        }
        else if (ch1 == 11)
        {
            exit(0);
        }
        else
        {
            printf("ERROR!!! Invalid Entry!");
            exit(1);
        }

    }
 
    
}
//--


//Teacher's Panel--
int show_a_student_for_teacher()
{
    struct data                     //Using Structure
    {
        char roll_no[50];
        char name[50];
        char phone[50];
        char class[50];
        char grade[50];
        char attendance[50];
    }st;
    
    FILE *fp;
    fp = fopen("students.txt", "a+");

    // search student
    system("cls");
    int indexer = 0;
    char str[100];
    char roll[50];
    char loc[50];
    printf("Enter Roll Number of the Student you want to see credentials of: ");
    scanf("\n");
    scanf("%[^\n]%*c", roll);
    show_t_label1:
    if (feof(fp))
    {   
        printf("No record found!");
        exit(0);
    }
    
    fgets(str, 100, fp);
    for (int i = 1; i < strlen(str)-1; i++)
    {   if (str[i] == ',')
        {
            break;
        }
    
        loc[i-1] = str[i];
        
    }
    if (strcmp(roll, loc) == 0)
    {   int i = 1;
        printf("\nRoll Number: ");
        while (str[i] != ',')
        {
            st.roll_no[indexer] = str[i];
            printf("%c", st.roll_no[indexer]);
            i++;
            indexer++;
        }
        
        i++;
        indexer=0;
        printf("\nName:");
        while (str[i] != ',')
        {
            st.name[indexer] = str[i];
            printf("%c", st.name[indexer]);
            i++;
            indexer++;
        }
        
        i++;
        indexer=0;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;
        printf("\nPhone:");
        while (str[i] != ',')
        {
            st.phone[indexer] = str[i];
            printf("%c", st.phone[indexer]);
            i++;
            indexer++;
        }
        
        i++;
        indexer=0;
        printf("\nClass:");
        while (str[i] != ',')
        {
            if (str[i] == '}')
            {
                break;
            }
            st.class[indexer] = str[i];
            printf("%c", st.class[indexer]);
            i++;
            indexer++;
        }
        
        i++;
        indexer=0;
        printf("\nGrade:");
        while (str[i] != ',')
        {
            if (str[i] == '}')
            {
                break;
            }
            st.grade[indexer] = str[i];
            printf("%c", st.grade[indexer]);
            i++;
            indexer++;
        }
        i++;
        printf("\nAttendance Percentage:");
        while (str[i] != ',')
        {   
            if (str[i] == '}')
            {
                break;
            }
            st.attendance[indexer] = str[i];
            printf("%c", st.attendance[indexer]);
            i++;
            indexer++;
        }
        
        i++;
        indexer=0;
        
    }
    else{
        goto show_t_label1;
    }
    int c = 1;
    printf("\nPress 0 to return to the menu : ");
    scanf("%d", &c);
    
    fclose(fp);
}

void assign_grade() {
    FILE *fp;
    FILE *fp2;
    fp  = fopen("students.txt", "r+");
    fp2 = fopen("temp.txt", "w");
    if (fp == NULL || fp2 == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char str[150];
    char loc[20];
    char roll[20];
    int comma_num = 6;
    char new[50];

    system("cls");
    printf("Enter the Roll Number of the student you want to assign grade to: ");
    scanf("%s", roll);
    

    int line_num = 1;
    int total_lines = -1;
    int count = 0;
    
    while (!feof(fp))   
    {
        fgets(str, 150, fp);
        total_lines++;
    }
   
    rewind(fp);

    while (!feof(fp))
    {
        fgets(str, 150, fp);
        int i = 1;
        for (; i < strlen(str) - 1; i++)
        {
            if (str[i] == ',')
            {
                break;
            }

            loc[i - 1] = str[i];
        }
        loc[i-1] = '\0';
        if (strcmp(roll, loc) == 0)
        {   
            count++;
            break;
        }
        else
        {
            line_num++;
        }
    }
    
    if (count == 0)
    {
        printf("No record found! Exiting...");
        exit(1);
    }
    
    system("cls");
    printf("Enter the Grade you want to assign: ");
    scanf("\n");
    scanf("%[^\n]%*c", new);

    rewind(fp);
    int comma_counter = 0;
    int line_counter = 1;           
    while (line_counter <= total_lines)
    {   
        fgets(str, 150, fp);

        if (line_counter == line_num)
        {   

            for (int i = 0; i < strlen(str)-1; i++)
            {   
                if (comma_counter != comma_num)
                {
                    fprintf(fp2,"%c", str[i]);
                }
                else{
                    
                    if (str[i+1] == ',')
                    {
                        
                        fprintf(fp2," %s," ,new);
                    }
                    
                    
                }
                

                if (str[i] == ',')
                {
                    comma_counter++;
                }
                
            }
            fprintf(fp2,"\n");
            line_counter++;
            continue;
        }
        
        fputs(str,fp2);
        line_counter++;
    }
    fclose(fp2);
    fclose(fp);
    remove("students.txt");
    rename("temp.txt", "students.txt");
    printf("\n\nAssigned successfully!\n");
    int ed;
    printf("\nPress 0 to return to the menu : ");
    scanf("%d", &ed);

}

void assign_attendance()
{
    FILE *fp;
    FILE *fp2;
    fp  = fopen("students.txt", "r+");
    fp2 = fopen("temp.txt", "w");
    if (fp == NULL || fp2 == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char str[150];
    char loc[20];
    char roll[20];
    int comma_num = 7;
    char new[50];

    system("cls");
    printf("Enter the Roll Number of the student you want to assign attendance to: ");
    scanf("%s", roll);
    

    int line_num = 1;
    int total_lines = -1;
    int count = 0;
    
    while (!feof(fp))   
    {
        fgets(str, 150, fp);
        total_lines++;
    }
   
    rewind(fp);

    while (!feof(fp))
    {
        fgets(str, 150, fp);
        int i = 1;
        for (; i < strlen(str) - 1; i++)
        {
            if (str[i] == ',')
            {
                break;
            }

            loc[i - 1] = str[i];
        }
        loc[i-1] = '\0';
        if (strcmp(roll, loc) == 0)
        {   
            count++;
            break;
        }
        else
        {
            line_num++;
        }
    }
    
    if (count == 0)
    {
        printf("No record found! Exiting...");
        exit(1);
    }
    
    system("cls");
    printf("Enter the Attendance you want to assign: ");
    scanf("\n");
    scanf("%[^\n]%*c", new);

    rewind(fp);
    int comma_counter = 0;
    int line_counter = 1;           
    while (line_counter <= total_lines)
    {   
        fgets(str, 150, fp);

        if (line_counter == line_num)
        {   

            for (int i = 0; i < strlen(str)-1; i++)
            {   
                if (comma_counter != comma_num)
                {
                    fprintf(fp2,"%c", str[i]);
                }
                else{
                    
                    if (str[i+1] == '}')
                    {
                        
                        fprintf(fp2," %s}" ,new);
                    }
                    
                    
                }
                

                if (str[i] == ',')
                {
                    comma_counter++;
                }
                
            }
            fprintf(fp2,"\n");
            line_counter++;
            continue;
        }
        
        fputs(str,fp2);
        line_counter++;
    }
    fclose(fp2);
    fclose(fp);
    remove("students.txt");
    rename("temp.txt", "students.txt");
    printf("\n\nAssigned successfully!\n");
    int ed;
    printf("\nPress 0 to return to the menu : ");
    scanf("%d", &ed);
}

int calc(int *ptr)
{
    int s;
    s = (*ptr)*5000;
    return s;
}

int show_salary()
{
    int n;
    printf("\nEnter the number of subjects you are teaching (Max. Subjects: 5): ");
    scanf("%d", &n);
    n = calc(&n);
    printf("\nYour Salary is: %d", n);
    int c = 1;
    printf("\nPress 0 to return to the menu : ");
    scanf("%d", &c);
}

void edit_pass_teacher() {
    FILE *fp;
    fp = fopen("teachers.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char str[150];
    char id[10];
    char new[50];
    int slot = 3;  // Assuming the password is in the 3rd slot

    system("cls");
    printf("Enter your ID: ");
    scanf("%s", id);

    int line_num = 1;
    int count = 0;
    while (fgets(str, sizeof(str), fp) != NULL) {
        char loc[10];
        int i;
        for (i = 1; i < strlen(str) - 1 && str[i] != ','; i++) {
            loc[i - 1] = str[i];
        }
        loc[i - 1] = '\0';

        if (strcmp(id, loc) == 0) {
            break;
        } else {
            line_num++;
        }
        count++;
    }

    if (feof(fp)) {
        printf("\nID not found. Exiting...\n");
        fclose(fp);
        exit(1);
    }

    fseek(fp, 0, SEEK_SET);

    int length = strlen(str);
    int arr[7];
    int index = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ',') {
            arr[index] = i;
            index++;
        }
    }

    char first_seg[150];
    char second_seg[150];
    for (int i = 0; i < arr[slot - 1] + 2; i++) {
        first_seg[i] = str[i];
    }
    first_seg[arr[slot - 1] + 2] = '\0';

    printf("\nEnter the new Password(8 characters): ");
    scanf("\n");
    scanf("%[^\n]%*c", new);

    strcat(first_seg, new);
    int p = 0;
    for (int i = arr[slot]; i < length; i++) {
        second_seg[p] = str[i];
        p++;
    }
    second_seg[p] = '\0';
    strcat(first_seg, second_seg);

    char string[2500];
    int u = 0;
    fseek(fp, 0, SEEK_SET);
    while ((string[u] = fgetc(fp)) != EOF) {
        u++;
    }

    fclose(fp);

    fp = fopen("teachers.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        exit(1);
    }

    int line = 0;
    for (int i = 0; i < strlen(string) - 2; i++) {
        if (string[i] == '{') {
            line++;
        }
        if (line == line_num) {
            for (int l = 0; l < strlen(first_seg); l++) {
                fputc(first_seg[l], fp);
            }
            line++;
            i += length - 1;
        } else {
            fputc(string[i], fp);
        }
    }

    if (line_num != count - 1) {
        fprintf(fp, "\n");
    }

    fclose(fp);
    
    printf("\n\nEdited successfully\n");
    int ep;
    printf("Press 0 to return to the menu : ");
    scanf("%d", &ep);

}

int teacher_menu()
{
    int ch1 = 1;
    while (ch1 != 6)
    {
        system("cls");
        printf("\n/////////////// TEACHER MENU ///////////////\n");
        printf("(1) Show credentials of a particular student \n");
        printf("(2) Assign grade \n");
        printf("(3) Assign Attendance \n");
        printf("(4) Show Salary \n");
        printf("(5) Edit your Password \n");
        printf("(6) Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &ch1);
        if (ch1 == 1)
        {
            show_a_student_for_teacher();
        }
        else if (ch1 == 2){

            assign_grade();   
        }
        else if (ch1 == 3)
        {
            assign_attendance();
        }
        else if (ch1 == 4)
        {
            show_salary();
        }
        else if (ch1 == 5)
        {
            edit_pass_teacher();
        }
        else if (ch1 == 6)
        {
            exit(0);
        }
        else
        {
            printf("ERROR!!! Invalid Entry!");
            exit(1);
        }

    }
}
//--


//Student's Panel--
int show_a_student_for_student()
{
    FILE *fp;
    fp = fopen("students.txt", "r+");

    // search student
    system("cls");
    char str[100];
    char roll[50];
    printf("Enter your roll number : ");
    scanf("\n");
    scanf("%[^\n]%*c", roll);
    char *loc;
    loc = (char*) malloc((strlen(roll))*sizeof(char));      //Using DMA

    show_student_label1:
    if (feof(fp))
    {   
        printf("No record found!");
        exit(0);
    }
    
    fgets(str, 100, fp);
    int i = 1;
    for (; i < strlen(str)-1; i++)
    {   if (str[i] == ',')
        {
            break;
        }
    
        *(loc+i-1) = str[i];
        
    }
    *(loc+i-1) = '\0';
    
    if (strcmp(roll, loc) == 0)
    {   int i = 1;
        printf("\nRoll Number: ");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nName:");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nEmail:");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nPassword:");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nPhone:");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("\nClass:");
        while (str[i] != ',')
        {
            if (str[i] == '}')
            {
                break;
            }
            
            printf("%c", str[i]);
            i++;
        }
        i++;
        
    }
    else{
        goto show_student_label1;
    }
    free(loc);
    int c = 1;
    printf("\nPress 0 to return to the menu : ");
    scanf("%d", &c);
    
    


    fclose(fp);
}

int show_grade()
{
    FILE *fp;
    fp = fopen("students.txt", "a+");

    // search student
    system("cls");
    char str[100];
    char roll[50];
    char loc[50];
    printf("Enter your roll number to verify: ");
    scanf("\n");
    scanf("%[^\n]%*c", roll);
    show_student_label1:
    if (feof(fp))
    {   
        printf("No record found!");
        exit(0);
    }
    
    fgets(str, 100, fp);
    int i = 1;
    for (; i < strlen(str)-1; i++)
    {   if (str[i] == ',')
        {
            break;
        }
    
        loc[i-1] = str[i];
        
    }
    loc[i-1] = '\0';
    if (strcmp(roll, loc) == 0)
    {   int i = 1;

        while (str[i] != ',')
        {

            i++;
        }
        i++;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;
        printf("\nYour Grade:\n");
        while (str[i] != ',')
        {
            
            printf("%c", str[i]);
            i++;
        }
        
    }
    else{
        goto show_student_label1;
    }
    int c = 1;
    printf("\nPress 0 to return to the menu : ");
    scanf("%d", &c);
    
    


    fclose(fp);
}

int show_attendance()
{
    FILE *fp;
    fp = fopen("students.txt", "a+");

    // search student
    system("cls");
    char str[100];
    char roll[50];
    char loc[50];
    printf("Enter your roll number to verify: ");
    scanf("\n");
    scanf("%[^\n]%*c", roll);
    show_student_label1:
    if (feof(fp))
    {   
        printf("No record found!");
        exit(0);
    }
    
    fgets(str, 100, fp);
    int i = 1;
    for (; i < strlen(str)-1; i++)
    {   if (str[i] == ',')
        {
            break;
        }
    
        loc[i-1] = str[i];
        
    }
    loc[i-1] = '\0';
    if (strcmp(roll, loc) == 0)
    {   int i = 1;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;

        while (str[i] != ',')
        {
            
            i++;
        }
        i++;

        printf("\nYour Attendance is:\n");
        while (str[i] != ',')
        {
            if (str[i] == '}')
            {
                break;
            }
            printf("%c", str[i]);
            i++;
        }
        i++;
        printf("%%");
        
    }
    else{
        goto show_student_label1;
    }
    int c = 1;
    printf("\nPress 0 to return to the menu : ");
    scanf("%d", &c);
    
    


    fclose(fp);
}

int fee_structure(int cl)
{
    int f;
    int arr[12][2];
    for (int i = 0; i < 12; i++)
    {
        f = (i+1)*1500;
        arr[i][0] = i+1;
        arr[i][1] = f;
    }
    return arr[cl-1][1];
}

int show_fee()
{
    system("cls");
    int cl;
    printf("\nEnter the class you are studying in: ");
    scanf("%d", &cl);
    printf("\nYour Total fee is: %d", fee_structure(cl));

    int c = 1;
    printf("\nPress 0 to return to the menu : ");
    scanf("%d", &c);
}

void edit_pass_student() {
    FILE *fp;
    fp = fopen("students.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char str[150];
    char roll[10];
    char new[50];
    int slot = 3;  // Assuming the password is in the 3rd slot

    system("cls");
    printf("Enter your Roll Number to verify: ");
    scanf("%s", roll);

    int line_num = 1;
    int count = 0;
    while (fgets(str, sizeof(str), fp) != NULL) {
        char loc[10];
        int i;
        for (i = 1; i < strlen(str) - 1 && str[i] != ','; i++) {
            loc[i - 1] = str[i];
        }
        loc[i - 1] = '\0';

        if (strcmp(roll, loc) == 0) {
            break;
        } else {
            line_num++;
        }
        count++;
    }

    if (feof(fp)) {
        printf("\nRoll number not found. Exiting...\n");
        fclose(fp);
        exit(1);
    }

    fseek(fp, 0, SEEK_SET);

    int length = strlen(str);
    int arr[7];
    int index = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ',') {
            arr[index] = i;
            index++;
        }
    }

    char first_seg[150];
    char second_seg[150];
    for (int i = 0; i < arr[slot - 1] + 2; i++) {
        first_seg[i] = str[i];
    }
    first_seg[arr[slot - 1] + 2] = '\0';

    printf("\nEnter the new Password(8 characters): ");
    scanf("\n");
    scanf("%[^\n]%*c", new);

    strcat(first_seg, new);
    int p = 0;
    for (int i = arr[slot]; i < length; i++) {
        second_seg[p] = str[i];
        p++;
    }
    second_seg[p] = '\0';
    strcat(first_seg, second_seg);

    char string[2500];
    int u = 0;
    fseek(fp, 0, SEEK_SET);
    while ((string[u] = fgetc(fp)) != EOF) {
        u++;
    }

    fclose(fp);

    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        exit(1);
    }

    int line = 0;
    for (int i = 0; i < strlen(string) - 2; i++) {
        if (string[i] == '{') {
            line++;
        }
        if (line == line_num) {
            for (int l = 0; l < strlen(first_seg); l++) {
                fputc(first_seg[l], fp);
            }
            line++;
            i += length - 1;
        } else {
            fputc(string[i], fp);
        }
    }

    if (line_num != count - 1) {
        fprintf(fp, "\n");
    }

    fclose(fp);
    
    printf("\n\nEdited successfully\n");
    int ed;
    printf("Press 0 to return to the menu : ");
    scanf("%d", &ed);

}

int student_menu()
{
    int ch1 = 1;
    while (ch1 != 6)
    {
        system("cls");
        printf("\n//////// STUDENT MENU ////////\n");
        printf("(1) See your Credentials \n");
        printf("(2) See your Grade \n");
        printf("(3) See your Attendance \n");
        printf("(4) See your Fee \n");
        printf("(5) Edit your Password \n");
        printf("(6) Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &ch1);
        if (ch1 == 1)
        {
            show_a_student_for_student();
        }
        else if (ch1 == 2){

            show_grade();   
        }
        else if (ch1 == 3)
        {
            show_attendance();
        }
        else if (ch1 == 4)
        {
            show_fee();
        }
        else if (ch1 == 5)
        {
            edit_pass_student();
        }
        else if (ch1 == 6)
        {
            exit(0);
        }
        else
        {
            printf("ERROR!!! Invalid Entry!");
            exit(1);
        }

    }
}
//--


int identifier()
{
    system("cls");
    char admin_id[11] = "admin@fast";
    char admin_pass[6] = "12345";
    int choice = 0;
    char email[25]; 
    char pass[25]; 
    
    system("cls");
    printf("######## MAIN MENU ########\n\n");
    printf("Choose your Occupation : \n");
    printf("(1) Admin\n");
    printf("(2) Teacher \n");
    printf("(3) Student \n");
    printf("Enter (1/2/3) : ");
    scanf("%d", &choice);
    
    int ch = 1;
    if (choice == 1)
    {   
        while (ch)
        {   label2:
            system("cls");
            printf("Enter the Email ID : ");
            scanf("\n");
            scanf("%[^\n]%*c", email);
            printf("Enter the password : ");
            scanf("\n");
            scanf("%[^\n]%*c", pass);
            if (strcmp(email , admin_id) == 0 && strcmp(pass,admin_pass) == 0)
            {   
                ch = 0;
                admin_menu();

            }
            else
            {
                printf("Incorrect email or password\n");
                printf("(press 0 to return to the previous menu) or 1 to try again : ");
                scanf("%d" ,  &ch);
                if (ch == 0)
                {
                    identifier();   //Using Recursion
                }

                else if (ch == 1)
                {
                    goto label2;
                }
                
                
            
            }
        }

    }

    else if (choice == 2)
    {
        labelt:
        system("cls");
        FILE *fp;
        fp = fopen("teachers.txt", "a+");
        int counter = 0;
        // system("cls");
        char str[100];
        char id[50];
        char password[50];
        int loc_indexer = 0;
        int loc2_indexer = 0;
        char loc[100];
        char loc2[100];
        printf("Enter email : ");
        scanf("\n");
        scanf("%[^\n]%*c", id);
        printf("Enter Password : ");
        scanf("\n");
        scanf("%[^\n]%*c", password);
        
        show_teacher_email:
        if (feof(fp))
        {   
            printf("ERROR! Incorrect Email or Password!");
            printf("\n\n(press 0 to return to the previous menu) or 1 to try again: ");
            scanf("%d" ,  &ch);
            if (ch == 0)
            {
                identifier();   //Using Recursion
            }

            else if (ch == 1)
            {
                goto labelt;
            }
                
        }
            loc_indexer = 0;
            loc2_indexer = 0;
            counter = 0;
            
        fgets(str, 100, fp);
        for (int i = 1; i < strlen(str)-1; i++)
        {   
            if (str[i] == ',')
            {
                counter++;
                continue;
            }

            if (counter == 2)
            {   
                if (str[i] == ' ')
                {
                    continue;
                }

                else
                {
                    loc[loc_indexer] = str[i];
                    loc_indexer++;
                }
    
            }
            if (counter == 3)
            {   
                if (str[i] == ' ')
                {
                    continue;
                }

                else
                {
                    loc2[loc2_indexer] = str[i];
                    loc2_indexer++;
                }
    
            }
    
        }
        loc[loc_indexer] = '\0';
        loc2[loc2_indexer] = '\0';
        
        if (strcmp(id, loc) == 0 && strcmp(password, loc2) == 0)
        {
            teacher_menu();
        }
        
        else
        {
            goto show_teacher_email;
        }
    }

    else if(choice == 3)
    {
        labels:
        system("cls");
        FILE *s_fp;
        s_fp = fopen("students.txt", "a+");
        int s_counter = 0;
        // system("cls");
        char s_str[100];
        char s_id[50];
        char s_pass[50];
        int s_loc_indexer = 0;
        int s_loc2_indexer = 0;
        char s_loc[100];
        char s_loc2[100];
        printf("Enter email : ");
        scanf("\n");
        scanf("%[^\n]%*c", s_id);
        printf("Enter Password : ");
        scanf("\n");
        scanf("%[^\n]%*c", s_pass);
        
        show_s_email:
        if (feof(s_fp))
        {   
            printf("ERROR! Incorrect Email or Password!");
            printf("\n\n(press 0 to return to the previous menu) or 1 to try again: ");
            scanf("%d" ,  &ch);
            if (ch == 0)
            {
                identifier();   //Using Recursion
            }

            else if (ch == 1)
            {
                goto labels;
            }
                
        }
            s_loc_indexer = 0;
            s_loc2_indexer = 0;
            s_counter = 0;
            
        fgets(s_str, 100, s_fp);
        for (int i = 1; i < strlen(s_str)-1; i++)
        {   
            if (s_str[i] == ',')
            {
                s_counter++;
                continue;
            }

            if (s_counter == 2)
            {   
                if (s_str[i] == ' ')
                {
                    continue;
                }
                else{
                    s_loc[s_loc_indexer] = s_str[i];
                    s_loc_indexer++;
                }
    
            }

            if (s_counter == 3)
            {   
                if (s_str[i] == ' ')
                {
                    continue;
                }
                else
                {
                    s_loc2[s_loc2_indexer] = s_str[i];
                    s_loc2_indexer++;
                }
    
            }
    
        }
        s_loc[s_loc_indexer] = '\0';
        s_loc2[s_loc2_indexer] = '\0';
        
        if (strcmp(s_id, s_loc) == 0 && strcmp(s_pass, s_loc2) == 0){
            student_menu();
        }
        
        else
        {
            goto show_s_email;
        }

    }
    else
    {
        printf("ERROR!!! Invalid Entry!");
        exit(1);
    }
    
    
    

}

int main()
{   
    char key; 

    
    
    system("cls");
    printf("WELCOME!!!");
    printf("\n\nPress any key to continue...\n");
    scanf("%s", &key);
    identifier();
   

    return 0;
}