#include <stdio.h>
#include <stdbool.h> 
#include <string.h>


bool isValid(const char *s) {
    char stack[10000];  
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;  
        } else {
            if (top == -1) return false;  
            char topChar = stack[top--];  
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return top == -1; 
}


bool containsOnlyBraces(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c != '(' && c != ')' &&
            c != '{' && c != '}' &&
            c != '[' && c != ']') {
            return false;
        }
    }
    return true;
}

int main() {
    char input[1000];
    char choice;

    do {
        printf("Enter a string of brackets (only (), {}, [] allowed): ");
        scanf("%s", input);

        if (!containsOnlyBraces(input)) {
            printf("Invalid input! Only brackets (), {}, [] are allowed.\n");
        } else {
            if (isValid(input))
                printf("The bracket sequence is VALID ✅\n");
            else
                printf("The bracket sequence is INVALID ❌\n");
        }

        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &choice);  

    } while (choice == 'Y' || choice == 'y');

    printf("Your code has been executed\n");

    return 0;
}
