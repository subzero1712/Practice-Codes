class BrowserHistory {
public:

    class Node {
    public:
        string url;
        Node* next;
        Node* prev;

        Node(string url) {
            this->url = url;
            next = NULL;
            prev = NULL;
        }
    };

    Node* current;

    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = NULL;

        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }

    string back(int steps) {
        while(steps > 0 && current->prev != NULL) {
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    string forward(int steps) {
        while(steps > 0 && current->next != NULL) {
            current = current->next;
            steps--;
        }
        return current->url;
    }
};
