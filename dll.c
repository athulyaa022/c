#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

struct node {
    char url[512];          
    struct node *next;      
    struct node *prev;      
};

struct node *current = NULL, *head = NULL, *newnode = NULL;

void visit_new_page() {
    newnode = (struct node*) malloc(sizeof(struct node));  
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    printf("Enter the URL to visit: ");
    scanf("%s", newnode->url);  
    
    newnode->prev = current;  
    newnode->next = NULL;     
    
    if (current != NULL) {
        current->next = newnode;  
    }
    
    current = newnode;  
    if (head == NULL) {
        head = newnode;  
    }
    
    printf("The visited URL is: %s\n", newnode->url);
}

void go_back() {
    if (current == NULL || current->prev == NULL) {
        printf("Cannot go back\n");
    } else {
        current = current->prev;  
        printf("Moved back to URL: %s\n", current->url);  
    }
}

void go_forward() {
    if (current == NULL || current->next == NULL) {
        printf("Cannot go forward\n");
    } else {
        current = current->next;  
        printf("Moved forward to URL: %s\n", current->url);  
    }
}

void display_current_page() {
    if (current == NULL) {
        printf("No page visited yet\n");
    } else {
        printf("Current page is: %s\n", current->url);  
    }
}


void free_list() {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);  
    }
}

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Visit a new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Display the current page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch(choice) {  
            case 1:
                visit_new_page();  
                break;
            case 2:
                go_back();  
                break;
            case 3:
                go_forward();  
                break;
            case 4:
                display_current_page();  
                break;
            case 5:
                printf("Exiting the navigation\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    free_list();  
    return 0;
}

