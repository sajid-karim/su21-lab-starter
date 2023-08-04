// Copyright sajid karim
#include <stdio.h>
#include <stdlib.h>


struct student {
  char name[20];
  int ID;
  int age;
};

int main() {
  struct student s;

  printf("Enter details of student \n");
  printf("Enter name: ");
  scanf("%20[^\n]%*c", s.name);
  printf("Enter Id: ");
  scanf("%d", &s.ID);
  printf("Enter age: ");
  scanf("%d", &s.age);


  printf("\n\n\tStudent Details: \t%s \t%d \t%d \n\n\n", s.name, s.ID, s.age);
  return 0;
}
