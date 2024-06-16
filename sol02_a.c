#include <stdio.h>
#include <stdbool.h>

// code copied from task1.1 a)
// --------------
#define MAX_STACK_SIZE 1000

char S[MAX_STACK_SIZE];
int top;  // top = index showing the first empty cell in the array

void new() {
    top = 0;
}

bool is_empty() {
    return (top == 0);
}

char pop() {
    if (is_empty() == 1) {
        return -1;
    }
    top -= 1;
    return S[top];
}

// returns 1 if insertion is successful, 0 if it fails
bool push(char x) {
    if (top == MAX_STACK_SIZE) {
        return 0;
    }
    S[top] = x;
    top += 1;
    return 1;
}
// ----------------

bool validate_parenthesis(char *s) {
    int i;
    char last_paren;
    new();
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(')
            push('(');
        else {  // closing parenthesis
            // We have three cases:
            // 1. The stack is empty. Reject the sequence
            // 2. The stack has a closing parenthesis at the top; reject the
            //    sequence
            // 3. The stack has an opening parenthesis at the top; this is OK,
            //    continue
            if (is_empty())
                return 0;
            last_paren = pop();
            if (last_paren == ')')
                return 0;
            // the stack is already popped, nothing more to do
        }
    }
    if (is_empty())
        return 1;
    return 0;
}

int main() {
    char *s1 = "(())()", *s2 = "(()()))", *s3 = "(()()";
    printf("sequence: %s - function return: %d\n", s1, validate_parenthesis(s1));
    printf("sequence: %s - function return: %d\n", s2, validate_parenthesis(s2));
    printf("sequence: %s - function return: %d\n", s3, validate_parenthesis(s3));
    return 0;
}