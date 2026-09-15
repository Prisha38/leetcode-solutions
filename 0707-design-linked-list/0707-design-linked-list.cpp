

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

 class MyLinkedList {
public:

    struct node {
        int val;
        node* next;

        node(int x) {
            val = x;
            next = NULL;
        }
    };

    node* head;

    MyLinkedList() {
        head = NULL;
    }

    int get(int index) {

        node* temp = head;

        for (int i = 0; i < index; i++) {
            if (temp == NULL)
                return -1;

            temp = temp->next;
        }

        if (temp == NULL)
            return -1;

        return temp->val;
    }

    void addAtHead(int val) {

        node* temp = new node(val);

        temp->next = head;
        head = temp;
    }

    void addAtTail(int val) {

        node* temp = new node(val);

        if (head == NULL) {
            head = temp;
            return;
        }

        node* curr = head;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = temp;
    }

    void addAtIndex(int index, int val) {

        if (index == 0) {
            addAtHead(val);
            return;
        }

        node* curr = head;

        for (int i = 0; i < index - 1; i++) {

            if (curr == NULL)
                return;

            curr = curr->next;
        }

        if (curr == NULL)
            return;

        node* temp = new node(val);

        temp->next = curr->next;
        curr->next = temp;
    }

    void deleteAtIndex(int index) {

        if (head == NULL)
            return;

        if (index == 0) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* curr = head;

        for (int i = 0; i < index - 1; i++) {

            if (curr == NULL)
                return;

            curr = curr->next;
        }

        if (curr == NULL || curr->next == NULL)
            return;

        node* temp = curr->next;

        curr->next = temp->next;

        delete temp;
    }
};