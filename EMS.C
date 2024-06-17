/***********************************************
 *Name: Amit Narayan                           *
 *Batch: 2-1                                   *
 *Roll No.: 20117                              *
 ***********************************************/

/*
Q10. Write a program using File handling to create a payroll system for n no. of employees of an organization with the following information read from keyboard:
    Employee Code
    Employee Name
    Designation
    Account number
    Date of joining
    Basic Pay
    DA
    HRA
    Deduction like EPF, LIC

Your program should create a file to store inputted information and have the facilities as
i. Create a Master File
ii. List employee
iii. Insert a new entry
iv. Search record by employee code.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int e_code;
    char e_name[30];
    char designation[20];
    int ac_no;
    char date[10];
    long int basic_pay;
    int da;
    int hra;
    int ded_like_lic_epf;
} employee;

void setEmpData(employee *);
void getEmpData(employee *);
void createFile();
void listEmp();
void insertEmp();
void searchEmp();

int main()
{
    int opt;
    do
    {
        // system("cls");
        printf("\n----------------Employee DataBase--------------");
        printf("\n1.Create Master File");
        printf("\n2.List Employee");
        printf("\n3.Insert a new entry");
        printf("\n4.Search Record by Employee code");
        printf("\n5.Exit");
        printf("\nEnter your option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            createFile();
            break;
        case 2:
            listEmp();
            break;
        case 3:
            insertEmp();
            break;
        case 4:
            searchEmp();
            break;
        case 5:
            printf("\nBye...");
            exit(0);
        default:
            printf("\nWorng Input");
        }

    } while (1);
    return 0;
}
void setEmpData(employee *a)
{
    printf("\nEmployee Code: ");
    scanf("%d", &a->e_code);
    fflush(stdin);
    printf("\nEmployee Name: ");
    scanf("%[^\n]s", a->e_name);
    fflush(stdin);
    printf("\nDesignation: ");
    scanf("%[^\n]", &a->designation);
    printf("\nAccount no.: ");
    scanf("%d", &a->ac_no);
    fflush(stdin);
    printf("\nDate of joining(DD/MM/YYYY): ");
    scanf("%[^\n]s", &a->date);
    printf("\nBasic Pay: ");
    scanf("%ld", &a->basic_pay);
    printf("\nDA(%%): ");
    scanf("%d", &a->da);
    printf("\nHRA: ");
    scanf("%d", &a->hra);
    printf("\nDeduction like EPF, LIC: ");
    scanf("%d", &a->ded_like_lic_epf);
    return;
}
void getEmpData(employee *a)
{
    printf("\n%-7d", a->e_code);
    printf("%-16s\t", a->e_name);
    printf("%-9s\t", a->designation);
    printf("%-16d", a->ac_no);
    printf("%-5s\t", a->date);
    printf("%-14ld", a->basic_pay);
    printf("%-5d ", a->da);
    printf("%-5d ", a->hra);
    printf("%d", a->ded_like_lic_epf);
    return;
}
void createFile()
{
    FILE *emp = fopen("employee.txt", "w");
    employee e;
    printf("-------- Creating master file --------");
    setEmpData(&e);
    fwrite(&e, sizeof(employee), 1, emp);
    fclose(emp);
}
void listEmp()
{
    employee e;
    FILE *emp = fopen("employee.txt", "r");
    printf("------ List of Employee -------");
    printf("\nE_Code  E_Name\t\t  Designation  Ac.No.\t\tDOJ\t\tBasic Pay\t DA  HRA  Deduction like EPF,LIC");
    printf("\n----------------------------------------------------------------------------------------------------------------------");
    while (fread(&e, sizeof(employee), 1, emp))
        getEmpData(&e);
    fclose(emp);
}
void insertEmp()
{
    FILE *emp = fopen("employee.txt", "a");
    employee e;
    printf("-------- Creating master file --------");
    setEmpData(&e);
    fwrite(&e, sizeof(employee), 1, emp);
    fclose(emp);
}
void searchEmp()
{
    int n;
    employee e;
    FILE *emp = fopen("employee.txt", "r");
    printf("\n------ Seearch Employee -------");
    printf("\nEnter Employee Code: ");
    scanf("%d", &n);
    printf("\nE_Code  E_Name\t\t  Designation  Ac.No.\t\tDOJ\t\tBasic Pay\t DA  HRA  Deduction like EPF,LIC");
    printf("\n----------------------------------------------------------------------------------------------------------------------");
    while (fread(&e, sizeof(employee), 1, emp))
    {
        if (e.e_code == n)
            getEmpData(&e);
    }
    fclose(emp);
}
