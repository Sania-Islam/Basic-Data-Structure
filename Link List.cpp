
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *root = nullptr;
void add_node(int data)
{
    if(root == nullptr)
    {
        root = new Node();N
        root->data = data;
        root->next = nullptr;
    }
    else
    {
        Node *current_node = root;
        while(current_node->next != nullptr)
        {
            current_node = current_node->next;
        }
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = nullptr;
        current_node->next = new_node;
    }

}

void print_forward()
{
    Node *current = root;
    while(current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void print_backward(Node *node)
{

    if(node != nullptr)
    {
        print_backward(node->next);
     cout << node->data << " ";
    }

}

int main()
{
    int data[5] = {1,2,4,6,8};
    for(int i=0; i<5; i++)
    {
        add_node(data[i]);
    }
    cout<< "Forward traversal ";
    print_forward();
    cout<< "Backward traversal ";
    print_backward(root);
    cout << endl;
}
