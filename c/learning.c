#include <stdio.h> // Library for input and output functions.
#include <stdbool.h> // Library for booleans
#include <string.h> // Library for string functions
#include <math.h> // Library for math functions
// #include is like import from python
/*
Multi-line comment
*/
int equations();
int constants();
int logicalOps();
int sizeOfVars();
int numbers();
int booleans();
int conditions();
int arrays();
int strings();
int inputs();
int memory();
void parameters(char name[]);
void parametersV2(char name[], int age);
int printName();
 
int main() { // int is like def
    //Do not forget the ; at the end of each line
    // the {} is used to say what is contained by something. the code below is contained by main()
    printf("Hello World\n");
    printf("I am suffering!!!\n");
    numbers(); // same as calling defined functions in python.
    return 0; // return 0 is a stopper
}

int numbers() { // This is for numbers
    int integers = 5; // You can also separate it as int integers; integers = 5;
    float decimals = 5.005; // Same as above.
    char myLetter = "a";
    char myString[] = "Hello!"; // strings are stored as arrays
    printf("%i\n", integers); // %i is to translate integers to strings
    printf("%f\n", decimals); // %f is to translate floats to strings
    printf("%.3f\n", decimals); // only prints 3 digits after the .
    printf("I have %i pencils\n", integers);
    printf("%s\n", myString); // %s is to print a string
    printf("%c\n", myString[5]); // %c is to print a character. it would print "!"
    myString[0] = 'J'; // It is now "Jello!"
    printf("%i %s\n", integers, myString);
    equations();
    return 0;
}

int equations() {
    int x = 5;
    int y = 10;
    int sum = x + y;
    printf("%i\n", sum);
    int a = 10, b = 20, c = 1;
    printf("a = %i. b = %i. c = %i\n", a, b, c);
    printf("The sum of all of them is %i\n", a + b + c);

    /*
    All operators:
    +: adds two values
    -: subtracts two values
    /: divides two values
    %: returns division remainder of two values
    *: multiplies two values
    ++: increments a value up (adds one)
    --: increments a value down (subtracts one)
    +=: add to a variable (ex: int x = 10; x += 5; x is now 15)
    if you do (operator)=, it would take the variable, take the value given, and do whatever the operator says to do
    */
    constants();
    return 0;
}

int constants() {
    const int f = 9; // const turns the variable you make into a constant
    /*
    f = 20
    the above line would return an error
    if a variable is a constant, it can't be changed
    */
    // good idea to have constants be caps lock
    // it would make it easier to tell constants from regular variables
    logicalOps();
    return 0;
}

int logicalOps() {
    /*
    ==
    !=
    >
    <
    >=
    <=

    &&: is like "and" in python (x = 5 && y = 10)
    ||: is like "or" in python (x = 5 || x = 10)
    !: is like "not" in python !(x = 5 $$ y = 10)
    */
    sizeOfVars();
    return 0;
}

int sizeOfVars() {
    int myInt = 5;
    float myFloat = 5.5;
    char myString[] = "Hello :)";
    printf("%lu\n", sizeof(myInt)); // "sizeof" grabs the memory size of the specified variable
    printf("%lu\n", sizeof(myFloat)); // %lu is used to translate it beacuse "sizeof" outputs "long unsinged int"
    printf("%lu\n", sizeof(myString));
    booleans();
    return 0;
}

int booleans() {
    bool iHavePencil = true; // Almost the same as python, but lowercase
    bool iHaveCar = false; // and you say it's a boolean
    printf("%d\n", iHavePencil); // you might be able to use %i, but just use %d for booleans to tell them apart
    printf("%d\n", 10 > 5); // returns 1 (true) because 10 is greater than 5
    printf("%d\n", 10 == 15); // returns 0 (false) because 10 is not equal to 15
    printf("%d\n", iHavePencil == iHaveCar); // returns 0 (false) because both are not the same value (1 or 2, true or false)
    conditions();
    return 0;
}

int conditions() {
    if (5 == 5) {
        printf("5 is equal to 5\n");
    } else if (5 >= 5) { // place them on the previous curly bracket
        printf("5 is greater than or equal to 5\n");
    } else {
        printf("5 is not equal to 5 (?)\n");
    }
    int age = 5;
    (age > 10) ? printf("The age is greater than 10\n") : printf("The age is less than 10\n"); // like a if, else, statement in one line
    // this might be good for things that only use one line of code

    int day = 7;

    switch (day) { // checks if specified variable is equal to each case
        case 1:
            printf("It is Monday\n");
            break;
        case 2:
            printf("It is Tuesday\n");
            break;
        case 3:
            printf("It is Wednesday\n");
            break;
        case 4:
            printf("It is Thursday\n");
            break;
        case 5:
            printf("It is Friday\n");
            break;
        case 6:
            printf("It is Saturday\n");
            break;
        case 7: // day = 7, day is equal to case 7 because 7 == 7, meaning that it would print "It is Sunday"
            printf("It is Sunday\n");
            break;
        default:
            printf("It is none of the days in the week\n");
            break; // like an else, if none of the previous cases were true, it would print the above line
    } // would output "It is Sunday"

    do { // Do this first
        printf("I will count down the day variable til 3\n");
    }
    while (day == 0); // If this is true, repeat above code

    while (day >= 3) { // repeat till condition == false
        printf("The day number is %i\n", day);
        day--;
    }

    int i;
    for (i = 9; i < 50; i++) { // Makes i into 9, and repeats until i is equal to 50, adding 1 to i every loop. you can also make the final one i += (number)
        if (i == 12) {
            continue; // if true, skip the this loop
        }
        printf("'i' is currently %i\n", i); // works the same in nested loops as well
    }
    /*
    Outer Loop: 1
      Inner Loop: 1
      Inner Loop: 2
      Inner Loop: 3
    Outer Loop: 2
      Inner Loop: 1
      Inner Loop: 2
      Inner Loop: 3
    so on and so forth
    */
    arrays();
    return 0;
}

int arrays() {
    int myArray[] = {90, 1, 50, 2};
    printf("%i\n", myArray[2]); // outputs 50
    myArray[2] = 19; // position 2 (50) is now 19. the array is now {90, 1, 19, 2}
    int i;
    for (i = 0; i < 4; i++) {
        printf("%i\n", myArray[i]);
    /*
    would output:
    90
    1
    50
    2
    */
    }
    int myArray2[4]; // limits the amount of values that can be assigned to 4

    int matrix[2][5] = { {1, 2, 3, 4, 5}, {9, 10, 11, 12, 14} }; // each {} is a row, with each value being in a column
    printf("%i\n", matrix[1][3]); // would output 12 because it was in row 1 (starts with 9), column 3 (index 3)
    
    int a, j;
    for (a = 0; a < 2; a++) {
        for (j = 0; j < 5; j++) {
            printf("%i\n", matrix[a][j]); // would go through each column in row one then go through each column in row two
        }
    }
    int d, b;
    for (d = 0; d < 2; d++) {
        for (b = 0; b < 5; b++) {
            printf("%i ", matrix[d][b]);
        }
        printf("\n");
    }
    strings();
    return 0;
}

int strings() {
    char stringArray[] = {'H', 'e', 'l', 'l', 'o', '!', ' ', 'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 's', 't', 'r', 'i', 'n', 'g', '.', '\0'};
    char string[] = "sure... and I have 5 million \"dollars\" in my bank account.";
    char string2[] = "Are you sure it\'s his?";
    char backslash[] = "This is how you print a \\";
    printf("%s\n", stringArray);
    printf("%s\n", string);
    printf("%s\n", string2);
    printf("%s\n", backslash);

    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    printf("%lu\n", strlen(alphabet)); // returns 26 because there are 26 characters
    printf("%lu\n", sizeof(alphabet)); // returns 27 because the "\0" is included
    // if you do
    char newString[100] = "Uuhhh";
    printf("%lu\n", sizeof(newString)); // it would return 100 because that is how much memory it takes (in bytes)

    strcat(string, string2); // Joins the two strings together, and stores the result in the first specified variable
    printf("%s\n", string); // would print:
    // sure... and I have 5 million "dollars" in my bank account. Are you sure it's his?
    strcpy(string2, backslash); // copies the backslash string to string2

    printf("%d\n", strcmp(string, string2)); // Checks if string and string2 are the same
    // it would return false because they aren't
    printf("%d\n", strcmp(string2, backslash)); // checks if string2 and backslash are the same
    // it would return true because they are.
    inputs();
    return 0;
}

int inputs() {
    int myNumber;
    printf("Type any number :)\n");
    scanf("%i", &myNumber); // grabs the number the user typed and stores it in myNumber. stops if there is a space or tab
    printf("You put %i\n", myNumber); // prints it

    getchar(); // removes the \n buffer from "scanf()", allowing the fgets() to work

    char myName[50];
    printf("What is your name?\n");
    fgets(myName, sizeof(myName), stdin); // grabs everything in the line (even if there are spaces)
    myName[strcspn(myName, "\n")] = '\0'; // strcspn finds first instance of a string in another string and returns the index of it. you can use that to replace or remove letters
    printf("Hello %s!\n", myName);
    memory();
    return 0;
}

int memory() {
    char myString[50] = "Hello!!!";
    char* ptr = myString; // make a pointer to myString's memory address
    printf("%p\n", &myString); // prints the memory address of myString
    printf("%p\n", ptr); // prints the memory address of myString
    printf("%i\n", *ptr); // prints the value of myString (72 for some reason)
    /*
    if you want to print the memory addresses of all the values in an array
    just make a for loop and print the memory address as done above
    Using a pointer for the array itself would give you the memory address of the array
    */
    printName();
    return 0;
}

void voidFunctions() {
    // Functions defined with "void" don't require a "return" at the end and work the same as an "int" function
}

void parameters(char name[]) { // takes one value (a string)
    printf("My name is %s\n", name); // and prints it
}

void parametersV2(char name[], int age) { // takes two values (string and integer)
    printf("My name is %s and I'm %i years old.\n", name, age); // then prints them both
}

int printName() {
    parameters("Johnathon");
    parameters("Alexander");
    parameters("Jeremy");
    parametersV2("Alexandra", 43);
    return 0;
}