#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Patient structure
struct patient
{
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[100];
    int doctor_id;
    int emergency;
    float bill;
};
//Doctor structure
struct doctor
{
    int id;
    char name[50];
    char specialization[50];
};

struct patient patients[100];
struct doctor doctors[50];

int pcount=0;
int dcount=0;

//Add Doctor
void addDoctor()
{
    printf("Enter the Doctor id: ");
    scanf("%d",&doctors[dcount].id);
    getchar();

    printf("Enter Doctor  Name: ");
    gets(doctors[dcount].name);

    printf("Enter Specialization: ");
    gets(doctors[dcount].specialization);

    dcount++;
    printf("Doctor added successfully.\n");
}
//show Doctors
void showDoctors()
{
    printf("\n----Doctor List----\n");
    for(int i=0; i<dcount; i++)
    {
        printf("Id:%d | Name:%s | Specialization:%s\n",
               doctors[i].id,doctors[i].name,doctors[i].specialization);
    }
}

//Add Patient
void addPatient()
{
    printf("Enter patient ID: ");
    scanf("%d",&patients[pcount].id);
    getchar();

    printf("Enter name: ");
    gets(patients[pcount].name);

    printf("Enter age: ");
    scanf("%d",&patients[pcount].age);
    getchar();

    printf("Enter gender: ");
    gets(patients[pcount].gender);

    printf("Enter disease: ");
    gets(patients[pcount].disease);

    printf("Enter Doctor ID: ");
    scanf("%d",&patients[pcount].doctor_id);

    printf("Emergency?(1=yes,0=No): ");
    scanf("%d",&patients[pcount].emergency);

    printf("Enter Bill Amount: ");
    scanf("%f",&patients[pcount].bill);

    pcount++;
    printf("Patient Added Successfully.\n");
}

//Show patients
void showPatients()
{
    printf("\n----patient list----\n");
    for(int i=0; i<pcount; i++)
    {
        printf("\nID:%d\nName:%s\nAge:%d\nGender:%S\nDisease:%s\nDoctor Id:%d\nEmergency:%s\nBill:%.2f\n",
               patients[i].id,
               patients[i].name,
               patients[i].gender,
               patients[i].disease,
               patients[i].doctor_id,
               patients[i].emergency?"YES":"NO",
               patients[i].bill);

    }
}

//Search Patient
void searchPatient()
{
    int id,found=0;
    printf("Enter ID to search: ");
    scanf("%d",&id);
    for(int i=0; i<pcount; i++)
    {
        if(patients[i].id==id)
        {
            printf("\nPatient Found:\nName:%s\nDisease:%s\nBill:%.2f\n",
                   patients[i].name,
                   patients[i].disease,
                   patients[i].bill);
            found=1;
        }
    }

    if(!found)printf("Patient Not Found\n");

}

//Delete Patient
void deletePatient()
{
    int id;
    printf("Enter Id to Delete: ");
    scanf("%d",&id);

    for(int i=0; i<pcount; i++)
    {
        if(patients[i].id==id)
        {
            for(int j=i; j<pcount-1; j++)
            {
                patients[j]=patients[j+1];
            }
            pcount--;
            printf("Patient Deleted.\n");
            return;
        }
    }
    printf("Patient Not Found\n");
}

//Update Patient
void updatePatient()
{
    int id;
    printf("Enter ID to Update: ");
    scanf("%d",&id);

    for(int i=0; i<pcount; i++)
    {
        if(patients[i].id==id)
        {
            getchar();
            printf("Enter New Name: ");
            gets(patients[i].name);

            printf("Enter New Disease: ");
            gets(patients[i].disease);

            printf("Enter New Bill: ");
            scanf("%f",&patients[i].bill);

            printf("Update Successfully.\n");
            return;
        }
    }
    printf("Patient Not Found\n");
}

//Emergency Patients
void showEmergency()
{
    printf("\n---Emergency---\n");
    for(int i=0; i<pcount; i++)
    {
        if(patients[i].emergency==1)
        {
            printf("ID:%d |Name:%s |Disease:%s\n",
                   patients[i].id,
                   patients[i].name,
                   patients[i].disease);
        }
    }
}

//Menu

void menu()
{
    printf("\n*****HOSPITAL MANAGEMENT SYSTEM*****\n");
    printf("1.Add Doctor\n");
    printf("2.Show Doctor\n");
    printf("3.Add Patient\n");
    printf("4.Show Patients\n");
    printf("5.Search Patient\n");
    printf("6.Update Patient\n");
    printf("7.Delete Patient\n");
    printf("8.Emergency patients\n");
    printf("9.Exit\n");
    printf("Enter Choice: ");
}

int main()
{
    int choice;

    while(1)
    {
        menu();
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            addDoctor();
            break;
        case 2:
            showDoctors();
            break;
        case 3:
            addPatient();
            break;
        case 4:
            showPatients();
            break;
        case 5:
            searchPatient();
            break;
        case 6:
            updatePatient();
            break;
        case 7:
            deletePatient();
            break;
        case 8:
            showEmergency();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid Choice.\n");
        }
    }
    return 0;
}





