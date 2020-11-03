#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
struct person{
char name[16];
int number;
};

void print(struct person *list,int *quantatyPerson);
void add_person(struct person *list , int *quantatyPerson);
void view_person(struct person *list, int  NumberPerson, int *quantatyPerson);
void delete_person(struct person *list, int deleteNumber, int *quantatyPerson);
void view_quantaty(struct person *list, int *quantatyPerson);
#endif
