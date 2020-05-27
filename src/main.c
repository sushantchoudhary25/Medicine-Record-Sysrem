#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include <conio.h>

void del();
void insert();
void display();
void search();
int n, flag = 0;
int ag, si[15];
int a[15], f[15];
struct student {
    char name[20];
    int rn;
    int mr, at;
}
s;
void del() {
    int r, n = 1;

    FILE * fp, * fp1;
    printf("Enter roll no:");
    scanf("%d", & r);

    fp = fopen("data.txt", "r");
    fp1 = fopen("data1.txt", "a");

    while (!feof(fp)) {
        fscanf(fp, "%s %d %d %d", s.name, & s.rn, & s.mr, & s.at);
        if (s.rn != r) {

            n = 0;
            fprintf(fp1, "%s %d %d %d", s.name, s.rn, s.mr, s.at);
            break;
        } else
            continue;
    }
    if (n == 1)
        printf("\nInvalid roll no");
    fclose(fp);
    fclose(fp1);
    remove("data.txt");
    rename("data1.txt", "data.txt");
    display();
}
void pass() {
    char pasword[10], usrname[10], ch;
    int i;
    printf("Enter User name: ");
    gets(usrname);
    if (strcmp(usrname, "root") == 0 || strcmp(usrname, "user") == 0) {
        printf("Enter the password <any 4 characters>: ");

        for (i = 0; i < 4; i++) {
            ch = getch();
            pasword[i] = ch;
            ch = '@';
            printf("%c", ch);
        }

        pasword[i] = '\0';

        if (strcmp(pasword, "root") == 0) {
            flag = 1;
        } else if (strcmp(pasword, "user") == 0) {
            flag = 2;
        } else {
            printf("Worng Password!!!");
        }
    } else {
        printf("Worng Username!!!");
    }
}

void calc() {
    int w, c, d = 0;
    int e = 0;
    printf("\nEnter the Current Number of week :-");
    scanf("%d", & w);
    for (int i = 0; i < n; i++) {
        printf("Enter the Classes Missed till now in subject %d :-", i + 1);
        scanf("%d", & d);
        c = a[i];
        f[i] = (c * w) - d;
    }
    for (int i = 0; i < n; i++) {
        c = a[i];
        d = f[i];
        si[i] = ((d * 100) / (c * w));
        printf("\nYour Attendence in Subject %d is :-%d %", i + 1, si[i]);
        e += si[i];
    }
    ag = e / n;
    printf("\n\nTotal Attendence is :-%d", ag);
}

void sub() {
    printf("\nEnter the Total no of subject :-");
    scanf("%d", & n);
    for (int i = 0; i < n; i++) {
        printf("\nEnter the Total no of class in a week for Subject %d :-", i + 1);
        scanf("%d", & a[i]);
    }

}

void display() {
    char ch;
    FILE * fp;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("file does not found !");
        exit(1);

    } else {
        printf("\n\n");
        printf("Name |Roll No |Marks |Attendence |\n\n\n");
        while ((ch = fgetc(fp)) != EOF) {
            printf("%c", ch);
        }

    }
    fclose(fp);
}

void find() {
    struct student s;
    FILE * fp;

    int r, a = 0;
    printf("\nEnter Student Roll number :");
    scanf("%d", & r);
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("file does not found !");
        exit(1);

    } else {
        while (getc(fp) != EOF) {
            fscanf(fp, "%s %d %d %d", s.name, & s.rn, & s.mr, & s.at);
            if (s.rn == r) {
                a = 1;
                printf("\n Record Found\n");
                printf("\n\t\tName ::%s", s.name);
                printf("\n\t\tRoll No ::%d", s.rn);
                printf("\n\t\tMarks ::%d", s.mr);
                printf("\n\t\tAgre attendence is ::%d", s.at);
                break;
            }
        }
        if (a == 0)
            printf("\nInvalid roll number");

    }

    fclose(fp);
}

void insert() {

    FILE * fp;
    struct student s;
    printf("Enter Student Name :- ");
    scanf("%s", s.name);
    printf("Enter Roll No :- ");
    scanf("%d", & s.rn);
    printf("Enter Aggr. Marks :- ");
    scanf("%d", & s.mr);
    sub();
    calc();
    s.at = ag;
    fp = fopen("data.txt", "a");

    if (fp == NULL) {
        printf("FIle not Found");
    } else {
        fprintf(fp, "%s %d %d %d\n", s.name, s.rn, s.mr, s.at);
        printf("\n\nRecord insert Sucessfull");
    }
    printf("\n");
    fclose(fp);
}

int main() {
    int y, cpp = 3;
    char pasword[10], usrname[10], ch;
    int i;
    printf("\t\t********* STUDENT ATTENDANCE CALCULATOR *********");
    printf("\n\n\t\tEnter User name: ");
    gets(usrname);
    if (strcmp(usrname, "11605194") == 0) {

        while (cpp > 0) {
            pasword[10] = NULL;
            printf("\n\n\t\tEnter the password: ");

            for (i = 0; i < 7; i++) {
                ch = getch();
                pasword[i] = ch;
                ch = '@';
                printf("%c", ch);
            }

            pasword[i] = '\0';

            if (strcmp(pasword, "sushant") == 0) {
                do {
                    printf("\n\n\nEnter your choice :-\n(1)Insert\n(2)Display\n(3)Search\n(4)Delete\n(5)Exit\n\n");
                    scanf("%d", & y);
                    switch (y) {
                    case 1:
                        insert();
                        break;
                    case 2:
                        display();
                        break;
                    case 3:
                        find();
                        break;
                    case 4:
                        del();
                        break;
                    case 5:
                        printf("\nProgram over");
                        exit(0);
                        break;
                    }
                } while (y != 5);
            } else {

                cpp--;
                printf("\nWrong password");
                printf("\nYou have %d tries left\n", cpp);
            }
        }
    } else
        printf("\nWrong username");
}
