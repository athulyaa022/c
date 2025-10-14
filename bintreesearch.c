#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int value) {
	if(root == NULL) {
		return createNode(value);
	}
	
	if(value < root->data)
		root->left = insertNode(root->left, value);
	else if(value > root->data)
		root->right = insertNode(root->right, value);
	return root;		
}

int search(struct Node* root, int data) {
    if (root == NULL) {
        return 0; 
    }
    if (data == root->data) {
        return 1;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorder(struct Node* root) { 
	if(root != NULL) { 
	inorder(root->left); 
	printf("%d ", root->data); 
	inorder(root->right); 
	} 
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
	printf("5. Exit\n");
	
	printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("Value %d found in the BinarySearchTree.\n", value);
                } else {
                    printf("Value %d not found in the BinarySearchTree.\n", value);
                }
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("The value %d is deleted \n", value);
                break;
            case 4:
             	printf("Inorder traversal: "); 
             	inorder(root);
             	printf("\n"); 
             	break;
	    case 5:
	    printf("Exiting Program \n");
            exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
