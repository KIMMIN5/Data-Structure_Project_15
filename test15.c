#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {    // 노드 타입
    element data;
    struct ListNode* link;
} ListNode;


void error(char* message) {
    fprintf(stderr, "%s\n\n", message);
}

ListNode* insert_first(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head;
        ListNode* temp = head;
        while (temp->link != head)
            temp = temp->link;
        temp->link = node;
        head = node;
    }
    return head;
}

ListNode* insert_last(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head;
        ListNode* temp = head;
        while (temp->link != head)
            temp = temp->link;
        temp->link = node;
    }
    return head;
}

void print_list(ListNode* head)
{
    ListNode* p;

    if (head == NULL) return;
    p = head;
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head);
    printf("\n\n");
}

ListNode* delete_first(ListNode* head) {
    if (head == NULL) {
        error("List is Empty.");
        return NULL;
    }


    if (head->link == head) {
        free(head);
        return NULL;
    }

    ListNode* temp = head;
    while (temp->link != head) {
        temp = temp->link;
    }

    ListNode* firstNode = head;
    head = head->link;
    temp->link = head;

    free(firstNode);

    return head;
}

ListNode* delete_last(ListNode* head) {
    if (head == NULL) {
        error("List is Empty.");
        return NULL;
    }

    
    if (head->link == head) {
        free(head);
        return NULL;
    }

    ListNode* temp = head;
    while (temp->link->link != head) {
        temp = temp->link;
    }

    ListNode* lastNode = temp->link;
    temp->link = head;

    free(lastNode); 

    return head;
}

int main() {
    int menu_bar, value, pos, i;

    ListNode* head = NULL, * tmp;

    while (1) {
        printf("Menu\n");
        printf("(1) Insert First\n");
        printf("(2) Insert Last\n");
        printf("(3) Delete First\n");
        printf("(4) Delete Last\n");
        printf("(5) Print\n");
        printf("(0) Exit\n\n");
        printf("Enter the Menu : ");
        scanf("%d", &menu_bar);

        if (menu_bar == 1) {
            printf("Enter the number : ");
            scanf("%d", &value);

            head = insert_first(head, value);
        }

        else if (menu_bar == 2) {
            printf("Enter the number : ");
            scanf("%d", &value);

            head = insert_last(head, value);
        }

        else if (menu_bar == 3) {
            head = delete_first(head);
        }

        else if (menu_bar == 4) {
            head = delete_last(head);
        }

        else if (menu_bar == 5) {
            print_list(head);
        }

        else if (menu_bar == 0) {
            error("Exit the program.");
            exit(0);
        }
        else {
            error("Invalid Menu. Please select again..");
        }
    }
}