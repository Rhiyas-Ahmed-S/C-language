#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct
{
    int id;
    char name[30];
    int age;
    char gender[10];
    char phone[15];
}patient;
typedef struct
{
    int id;
    char name[30];
    char specialization[30];
}doctor;
typedef struct
{
    int patientId;
    int doctorId;
    char date[30];
    char time[30];
}appointment;
patient patients[MAX];
appointment appointments[MAX];
int patientcount = 0;
int appointmentcount = 0;
int d,m,y;
int amount,change;
float bookingfees=500;

doctor doctors[3]=
{
    {
        1,"Dr.Shaji","Neurologist"
    },
    {
        2,"Dr.kumar","General Medicine"
    },
    {
        3,"Dr.Sam","Dentist"
    },
};

void addpatient();
void viewpatients();
void listdoctors();
void bookappointment();
void viewappointments();
void cancelappointment();

int main()
{
    int choice;
    while(1)
    {
        printf("\n====Hospital Appointment Booking System====\n");
        printf("1. Register patient\n");
        printf("2. View patient\n");
        printf("3. List Doctors\n");
        printf("4. Book Appointments\n");
        printf("5. View Appointments\n");
        printf("6. Cancel Appointments\n");
        printf("7. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            addpatient();
            break;
        case 2:
            viewpatients();
            break;
        case 3:
            listdoctors();
            break;
        case 4:
            bookappointment();
            break;
        case 5:
            viewappointments();
            break;
        case 6:
            cancelappointment();
            break;
        case 7:
            exit(0);
        default :
            printf("Invalid choice\n");
        }
    }
    return 0;
}

void addpatient()
{
    patient p;
    printf("\nEnter Patient ID : ");
    scanf("%d",&p.id);
    printf("Enter Name : ");
    scanf("%s",p.name);
    printf("Enter Age : ");
    scanf("%d",&p.age);
    printf("Enter Gender : ");
    scanf("%s",&p.gender);
    printf("Enter Phone : ");
    scanf("%s",&p.phone);

    patients[patientcount++]=p;
    printf("Patient registered Successfully!\n");
}

void viewpatients()
{
    printf("\n---patient list---\n");
    for(int i=0;i<patientcount;i++)
    {
        printf("ID:%d | Name: %s | Age: %d | Gender: %s | Phone number: %s\n",patients[i].id,patients[i].name,patients[i].age,patients[i].gender,patients[i].phone);
    }
}

void listdoctors()
{
    printf("\n---Doctors Available---\n");
    for(int i=0;i<3;i++)
    {
        printf("ID: %d | %s (%s)\n",doctors[i].id, doctors[i].name, doctors[i].specialization);
    }
}

void bookappointment()
{
    appointment a;
    printf("\nEnter patient ID: ");
    scanf("%d",&a.patientId);
    listdoctors();
    printf("Choose Doctor ID: ");
    scanf("%d",&a.doctorId);
    printf("Enter Date (dd/mm/yyyy): ");
    scanf("%s",a.date);
    printf("Enter Time (hh:mm): ");
    scanf("%s",a.time);

    appointments[appointmentcount++]=a;
    printf("Appointment Successfully Registered \n");

    printf("Your appointment fees is 500 !\n");
    printf("Enter amount to booking: ");
    scanf("%d",&amount);
    if(amount<bookingfees)
    {
        printf("You need to pay correct fees !\n");
    }
    else
    {
        change=amount-bookingfees;
        printf("Paid: Rs.%d | Change Returned: Rs.%d\n",amount,change);
    }
}
void viewappointments()
{
    printf("\n---Appointment List---\n");
    for(int i=0;i<appointmentcount;i++)
    {
        printf("Patient ID: %d |Doctor ID: %d |Date: %s |Time: %s\n",appointments[i].patientId,appointments[i].doctorId,appointments[i].date,appointments[i].time);

    }
}

void cancelappointment()
{
    int id,found=0;
    printf("\nEnter Patient ID to cancel appointment: ");
    scanf("%d",&id);

    for(int i=0;i<appointmentcount;i++)
    {
        if(appointments[i].patientId==id)
        {
            found=1;
            for(int j=i;j<appointmentcount-1;j++)
            {
                appointments[j]=appointments[j+1];
            }
            appointmentcount--;
            printf("Appointment Cancelled for patient ID: %d\n",id);
            break;
        }
    }
    if(!found)

    {
        printf("No appointments found for given Patient ID!\n");
    }
}
