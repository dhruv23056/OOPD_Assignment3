#include <iostream>
#include <bits/stdc++.h>
using namespace std;


template <class T>
class Node {
public:
    T data;
    Node* leftmost;
    Node* second;
    Node* third;
    Node* rightmost;

    Node() : data(T()), leftmost(nullptr), second(nullptr), third(nullptr), rightmost(nullptr) {}
    Node(T val) : data(val), leftmost(nullptr), second(nullptr), third(nullptr), rightmost(nullptr) {}
};

template <class T>
class Quaternary_Search_Tree {
    Node<T>* root;
    vector<T> v;
public:
    Quaternary_Search_Tree() : root(nullptr) {}

    Quaternary_Search_Tree(const vector<Node<T>>& v) : root(nullptr) {
        for (const auto& node : v) {
            insert(node.data);
        }
    }

    void insert(T data) {
        insert(&root, data);
    }

    void insert(Node<T>** current_node, T data) {
        if (*current_node == nullptr) {
            *current_node = new Node<T>(data);
            return;
        }

        T k = (*current_node)->data;
        T key = data;

        if (key >= 0 && key < k / 2)
            insert(&(*current_node)->leftmost, data);
        else if (key >= k / 2 && key < k)
            insert(&(*current_node)->second, data);
        else if (key >= k && key < 2 * k)
            insert(&(*current_node)->third, data);
        else
            insert(&(*current_node)->rightmost, data);
    }

    
    void inorder() {
        inorder(root); 
    }

    void inorder(Node<T>* current_node) {
        if (current_node == nullptr)
            return;

        inorder(current_node->leftmost);
        inorder(current_node->second);
        cout << current_node->data << " ";
        inorder(current_node->third);
        inorder(current_node->rightmost);
        
    }

    void preorder() {
        preorder(root);
    }

    void preorder(Node<T>* current_node) {
        if (current_node == nullptr)
            return;

        cout << current_node->data << " ";
        preorder(current_node->leftmost);
        preorder(current_node->second);
        preorder(current_node->third);
        preorder(current_node->rightmost);
    }

    void postorder() {
        postorder(root);
    }

    void postorder(Node<T>* current_node) {
        if (current_node == nullptr)
            return;

        postorder(current_node->leftmost);
        postorder(current_node->second);
        postorder(current_node->third);
        postorder(current_node->rightmost);
        cout << current_node->data << " ";
    }
    void deletenode(T key)
    {
        bool flag = checknodeexists(root,key);
        if(!flag)
        {
            cout<<"There is no node with key value "<<key<<"\n";
            return ;
        }

        deletenode(&root,key);
    }
    void checknodeexists(T key)
    {
        bool f = checknodeexists(root,key);
        if(f)
        cout<<"node exists\n";
        else
        cout<<"no node exists\n";

    }

    void tad(T key)
    {
        tad(&root,key);
    }

    void travel(Node<T>* currentnode)
    {
        if (currentnode==nullptr)
        return;
        v.push_back(currentnode->data);
        travel(currentnode->leftmost);
        travel(currentnode->second);
        travel(currentnode->third);
        travel(currentnode->rightmost);
        return ;
    }

    void tad(Node<T>** current_node,T key)
    {
        if(*current_node == nullptr)
        return;

        T k = (*(current_node))->data;
        if(k==key)
        {
            //debug();
            if((*(current_node))->leftmost!=nullptr || (*(current_node))->second!=nullptr || (*(current_node))->third!=nullptr || (*(current_node))->rightmost!=nullptr )
            deletenode(current_node,(*(current_node))->data);
            else
            *(current_node) = nullptr;

            //delete parent pointer
            //deleteparentpointer(&root);
            return ;
        }
        tad(&(*(current_node))->leftmost, key);
        tad(&(*(current_node))->second,key);
        tad(&(*(current_node))->third,key);
        tad(&(*(current_node))->rightmost,key);
        return ;

    }

    bool checknodeexists(Node<T>* current_node,T key)
    {
        if(current_node==NULL)
        return false;

        if (current_node->data == key)
        return true;

        bool flag = false;

        flag = flag | checknodeexists(current_node->leftmost,key);
        flag = flag | checknodeexists(current_node->second,key);
        //cout<<current_node->data<<" ";
        flag = flag | checknodeexists(current_node->third,key);
        flag = flag | checknodeexists(current_node->rightmost,key);

        return flag;
    }


// Node<T>* deletenode(Node<T>* current_node, T key) 
// {
//     // if (current_node == nullptr) {
//     //     return current_node;
//     // }

//     // if (key >= 0 && key < k / 2)
//     // {
//     //     current_node->leftmost = deletenode(current_node->leftmost, key);
//     // }
//     // else if (key >= k / 2 && key < k)
//     // {
//     //     current_node->second = deletenode(current_node->second, key);
//     // }
//     // else if (key >= k && key < 2 * k)
//     //     insert(&(*current_node)->third, data);
//     // else
//     //     insert(&(*current_node)->rightmost, data);


//     // // if (key < current_node->data) 
//     // // {
//     // //     current_node->leftmost = deletenode(current_node->leftmost, key);
//     // // } 
//     // // else if (key > current_node->data) 
//     // // {
//     // //     current_node->rightmost = deletenode(current_node->rightmost, key);
//     // // } 
//     // // else 
//     // // {
//     // //     // Node with only one child or no child
//     // //     if (current_node->leftmost == nullptr) {
//     // //         Node<T>* temp = current_node->rightmost;
//     // //         delete current_node;
//     // //         return temp;
//     // //     } else if (current_node->rightmost == nullptr) {
//     // //         Node<T>* temp = current_node->leftmost;
//     // //         delete current_node;
//     // //         return temp;
//     // //     }

//     // //     // Node with two children: Get the inorder successor (smallest in the right subtree)
//     // //     Node<T>* temp = findmin(current_node->rightmost);

//     // //     // Copy the inorder successor's content to this node
//     // //     current_node->data = temp->data;

//     // //     // Delete the inorder successor
//     // //     current_node->rightmost = deletenode(current_node->rightmost, temp->data);
//     // // }
    
//     // return current_node;
// }


void deletenode(Node<T>** current_node,T key)
    {
        if(*current_node == nullptr)
        return;

        T k = (*(current_node))->data;

        if(k==key)
        {
            // find predecessor/succesor of the element to be deleted
            v.clear();
            travel(*current_node);
            sort(v.begin(),v.end());
            int x=-1;
            auto f = find(v.begin(),v.end(),k);
            v.erase(f);
            auto p = lower_bound(v.begin(),v.end(),key);
            // make the succesor/predecessor to be null
            
            // if no predecessor/successor found 
            // that means the tree below the current node is null
            if(v.size()==0)
            {
                tad(current_node,k);
                return;
            }

            if(p==v.end())
            x = v[v.size()-1];
            else
            x = *p;

            //cout<<x<<"\n";
            tad(current_node,x);
            (*(current_node))->data = x;

            return;

        }



        if (key >= 0 && key < k / 2)
            deletenode(&(*(current_node))->leftmost, key);
        else if (key >= k / 2 && key < k)
            deletenode(&(*(current_node))->second, key);
        else if (key >= k && key < 2 * k)
            deletenode(&(*(current_node))->third, key);
        else
            deletenode(&(*(current_node))->rightmost, key);

        return ;
        

    }

    

Node<T>* findmin(Node<T>* node) 
{
    while (node->leftmost != nullptr) 
    {
        node = node->leftmost;
    }
    return node;
}

};

int main() {
    vector<Node<int>> v;
    
    Quaternary_Search_Tree<int> Q(v);
    cout << "\n";

    while (true) {
        char choice;
        cout << "1 for Inserting node in tree.\n";
        cout << "2 for Deleting node in tree.\n";
        cout << "3 for Pre-order traversal of tree.\n";
        cout << "4 for Post-Order traversal of tree.\n";
        cin >> choice ;
        // cout << endl;

        assert(choice<0 || choice>5);

        int node_data;
        switch (choice) {
            // case '1':
            //     cout << "enter node data to be inserted in the tree.\n";
            //     cin >> node_data;
            //     Q.insert(node_data);
            //     Q.inorder();
            //     break;

            case '1':
                cout << "Enter node data to be inserted in the tree:\n";
                try 
                {
                    cin >> node_data;
                    if (cin.fail()) {
                        throw std::runtime_error("Invalid input. Please enter an integer.");
                    }

                    Q.insert(node_data);
                    Q.inorder();
                }
                catch (const std::exception& e) 
                {
                    cout << "Error: " << e.what() << endl;
                    cin.clear();  // Clear the error flag
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
                }
                break;

            case '2':
                try
                {
                    cout << "enter the key to be deleted from the tree.\n";
                    cin >> node_data;

                    if(cin.fail())
                    {
                        throw runtime_error("Invalid input");
                    }    
                }
                catch(const exception& e)
                {
                    cerr << "Error:" << e.what() << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
                Q.deletenode(node_data);
                break;
            case '3':
                Q.preorder();
                break;
            case '4':
                Q.postorder();
                break;
            default:
                cout << "invalid choice entered\n";
        }
    }
}
