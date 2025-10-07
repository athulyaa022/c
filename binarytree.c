#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

char opStack[MAX];
int top = -1;

Node* nodeStack[MAX];
int nodeTop = -1;

void push(char ch) {
    opStack[++top] = ch;
}

char pop() {
    return opStack[top--];
}

int isEmpty() {
    return top == -1;
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperand(char ch) {
    return isalpha(ch) || isdigit(ch);
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0') {
        ch = infix[i];

        if (isOperand(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (!isEmpty() && opStack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
        else {
            while (!isEmpty() && precedence(opStack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void pushNode(Node* node) {
    nodeStack[++nodeTop] = node;
}

Node* popNode() {
    return nodeStack[nodeTop--];
}

Node* ConstructExpressionTree(char postfix[]) {
    int i = 0;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isOperand(ch)) {
            Node* node = createNode(ch);
            pushNode(node);
        } else {
            Node* node = createNode(ch);
            Node* rightChild = popNode();
            Node* leftChild = popNode();
            node->left = leftChild;
            node->right = rightChild;
            pushNode(node);
        }
    }

    return popNode();
}

void PrintPrefix(Node* root) {
    if (root == NULL) return;
    printf("%c", root->data);
    PrintPrefix(root->left);
    PrintPrefix(root->right);
}

void PrintPostfix(Node* root) {
    if (root == NULL) return;
    PrintPostfix(root->left);
    PrintPostfix(root->right);
    printf("%c", root->data);
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    Node* root = ConstructExpressionTree(postfix);

    printf("PreOrder Traversal: ");
    PrintPrefix(root);
    printf("\n");

    printf("PostOrder Traversal: ");
    PrintPostfix(root);
    printf("\n");

    return 0;
}

