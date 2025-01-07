#include <cs50.h>
#include <stdio.h>
#include <string.h>


// close to oop, unable to define attributes within this struct (makes it abstract)
typedef struct
{
    string name;
    string number;
    string address;
}
person;

int main(void){

    person people[2];

    people[0].name = "Carter";
    people[0].number = "978-447-3031";

    people[1].name = "Anthony";
    people[1].number = "781-831-1662";

    string name = get_string("Name: ");
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}

