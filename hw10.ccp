// Red-Black Tree fix deletion function

#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

template <class T>
class RBT;

template <class T>
class RBTNode{
    bool isBlack;
    T data;
    RBTNode<T> *left, *right, *parent;
public:
    RBTNode(const T& newdata = T(), RBTNode<T>* newparent = nullptr, RBTNode<T>* newleft = nullptr, RBTNode<T>* newright = nullptr, bool newIsBlack=false) :
    data(newdata), parent(newparent), left(newleft), right(newright),isBlack(newIsBlack){}
    
    friend class RBT < T >;
};

template <class T>
class RBT{
    RBTNode<T>* root;
    void printPreOrder(RBTNode<T>* start);
    void printInOrder(RBTNode<T>* start);
    void printPostOrder(RBTNode<T>* start);
    void printLevelOrder(RBTNode<T>* start);
    RBTNode<T>* recursiveCopy(RBTNode<T>* rhs);
    void remove(RBTNode<T>* toRemove);
    bool isBlack(RBTNode<T>* item){ return item == nullptr ? true : item->isBlack; }
    void recolor(RBTNode<T>* node);
    void doRotation(RBTNode<T>* node);
    bool isLeftChild(RBTNode<T>* node);
    void singleCCR(RBTNode<T>* start);
    void singleCR(RBTNode<T>* start);
    void doubleCCR(RBTNode<T>* start);
    void doubleCR(RBTNode<T>* start);
    void removeBalance(RBTNode<T>* toRemove);
public:
    RBT(){ root = nullptr; }
    ~RBT(){ clear(); }
    RBT(const RBT& rhs) :root(nullptr){ *this = rhs; }
    bool isEmpty() const{ return root == nullptr; }
    void printPreOrder(){ printPreOrder(root); cout << endl; }
    void printInOrder(){ printInOrder(root); cout << endl; }
    void printPostOrder(){ printPostOrder(root); cout << endl; }
    void printLevelOrder(){ printLevelOrder(root); cout << endl; }
    
    RBT<T>& operator=(const RBT<T>& rhs);
    void clear();
    void insert(const T& data);
    void remove(const T& data){ remove(find(data)); }
    RBTNode<T>* find(const T& data) const;
    
};
template <class T>
void RBT<T>::singleCCR(RBTNode<T>* node){
    RBTNode<T>* start;
    if (node->parent == nullptr || node->parent->parent == nullptr){
        start = node;
    }
    else{
        start = node->parent->parent;
    }
    RBTNode<T>* child = start->right;
    start->right = child->left;
    child->parent = start->parent;
    start->parent = child;
    child->left = start;
    if (start->right != nullptr)
        start->right->parent = start;
    if (child->parent != nullptr){
        if (child->parent->left == start)
            child->parent->left = child;
        else
            child->parent->right = child;
    }
    else
        root = child;
    child->isBlack = true;
    node->isBlack = false;
    start->isBlack = false;
    
}
template <class T>
void RBT<T>::singleCR(RBTNode<T>* node){
    RBTNode<T>* start;
    if (node->parent == nullptr || node->parent->parent == nullptr){
        start = node;
    }
    else{
        start = node->parent->parent;
    }
    RBTNode<T>* child = start->left;
    start->left = child->right;
    child->parent = start->parent;
    start->parent = child;
    child->right = start;
    if (start->left != nullptr)
        start->left->parent = start;
    if (child->parent != nullptr){
        if (child->parent->right == start)
            child->parent->right = child;
        else
            child->parent->left = child;
    }
    else
        root = child;
    child->isBlack = true;
    node->isBlack = false;
    start->isBlack = false;
    
}
template <class T>
void RBT<T>::doubleCCR(RBTNode<T>* node){
    RBTNode<T>* start = node->parent->parent;
    singleCR(start->right);
    singleCCR(start);
    node->isBlack = true;
    if (node->left)
        node->left->isBlack = false;
    if (node->right)
        node->right->isBlack = false;
}
template<class T>
void RBT<T>::doubleCR(RBTNode<T>* node){
    RBTNode<T>* start = node->parent->parent;
    singleCCR(start->left);
    singleCR(start);
    node->isBlack = true;
    if (node->left)
        node->left->isBlack = false;
    if (node->right)
        node->right->isBlack = false;
}

template <class T>
bool RBT<T>::isLeftChild(RBTNode<T>* node){
    return node->parent->left == node;
}
template <class T>
void RBT<T>::doRotation(RBTNode<T>* node){
    bool nodeIsLeft = isLeftChild(node);
    bool parentIsLeft = isLeftChild(node->parent);
    if (nodeIsLeft && parentIsLeft)
        singleCR(node);
    else if (!nodeIsLeft&& parentIsLeft)
        doubleCR(node);
    else if (!nodeIsLeft && !parentIsLeft)
        singleCCR(node);
    else
        doubleCCR(node);
}

template <class T>
void RBT<T>::recolor(RBTNode<T>* node){
    node->isBlack = false;
    if (node->left != nullptr)
        node->left->isBlack = true;
    if (node->right != nullptr)
        node->right->isBlack = true;
    root->isBlack = true;
    if (!isBlack(node->parent))
        doRotation(node);
}
template <class T>
void RBT<T>::remove(RBTNode<T>* toRemove){

    if (toRemove == nullptr)
        return;
    RBTNode<T>* parent = toRemove->parent;
    if (toRemove->left == nullptr && toRemove->right == nullptr){ //leaf node
        if (parent == nullptr){ //last node on the tree
            root = nullptr;
            delete toRemove;
        }
        else{
            if (parent->left == toRemove)
                parent->left = nullptr;
            else
                parent->right = nullptr;
            delete toRemove;
        }
    }
    else if (toRemove->left == nullptr){//has a right child!!!
        RBTNode<T>* removeChild = toRemove->right;
        toRemove->data = toRemove->right->data;
        toRemove->left = toRemove->right->left;
        if (toRemove->left != nullptr)
            toRemove->left->parent = toRemove;
        toRemove->right = toRemove->right->right;
        if (toRemove->right != nullptr)
            toRemove->right->parent = toRemove;
        delete removeChild;
    }
    else if (toRemove->right == nullptr){//has a left child!!!
        RBTNode<T>* removeChild = toRemove->left;
        toRemove->data = toRemove->left->data;
        toRemove->right = toRemove->left->right;
        if (toRemove->right != nullptr)
            toRemove->right->parent = toRemove;
        toRemove->left = toRemove->left->left;
        if (toRemove->left != nullptr)
            toRemove->left->parent = toRemove;
        delete removeChild;
    }
    else{ //ugh... it has two children!!!
        RBTNode<T>* temp = toRemove->right;
        while (temp->left != nullptr)
            temp = temp->left;
        toRemove->data = temp->data;
        remove(temp);
    }
    if ( isBlack(toRemove)){
        removeBalance(toRemove);
    }
}


template <class T>
void RBT<T>::removeBalance(RBTNode<T>* node){

        while (node != root && isBlack(node)) {
          
            if(node == node->parent->left){
                RBTNode<T>* sibling = node->parent->right;
                //case 1
                if (!isBlack(sibling)) {
                    sibling->isBlack = true;
                    node->parent->isBlack = false;
                    singleCCR(node->parent);
                    sibling = node->parent->right;
                }
                //case 2
                if (isBlack(sibling->left) && isBlack(sibling->right)){
                    sibling->isBlack = false;
                    node = node->parent;
                }
                
                else {
                    // case3
                    if (isBlack(sibling->right)){
                        sibling->left->isBlack = true;
                        sibling->isBlack = false;
                        singleCR(sibling);
                        sibling = node->parent->right;
                    }
                    //case 4
                    sibling->isBlack = node->parent->isBlack;
                    node->parent->isBlack = true;
                    sibling->right->isBlack = true;
                    singleCCR(node->parent);
                    node = root;
                }
            }

            else {
                RBTNode<T>* sibling = node->parent->left;
                // case1
                if(!isBlack(sibling)){
                    sibling->isBlack = true;
                    node->parent->isBlack = false;
                    singleCR(node->parent);
                    sibling = node->parent->left;
                }
               //case2
                if (isBlack(sibling->left) && isBlack(sibling->right)){
                    sibling->isBlack = false;
                    node = node->parent;
                }
                
                else {
                    // case3
                    if (isBlack(sibling->left)){
                        sibling->right->isBlack = true;
                        sibling->isBlack = false;
                        singleCCR(sibling);
                        sibling = node->parent->left;
                    }
                    // Case 4
                     sibling->isBlack = node->parent->isBlack;
                    node->parent->isBlack = true;
                    sibling->left->isBlack = true;
                    singleCR(node->parent);
                    node = root;
                }
            }
        }
        node->isBlack = true;
}

template <class T>
RBT<T>& RBT<T>::operator=(const RBT<T>& rhs){
    if (this == &rhs)
        return *this;
    clear();
    root = recursiveCopy(rhs.root);
    return *this;
}
template <class T>
RBTNode<T>* RBT<T>::recursiveCopy(RBTNode<T>* rhs){
    if (rhs == nullptr)
        return nullptr;
    RBTNode<T>* temp = new RBTNode<T>(rhs->data, nullptr,
                                      recursiveCopy(rhs->left), recursiveCopy(rhs->right), rhs->isBlack);
    if (temp->left != nullptr)
        temp->left->parent = temp;
    if (temp->right != nullptr)
        temp->right->parent = temp;
    return temp;
}
template <class T>
void RBT<T>::clear(){
    if (root == nullptr)
        return;
    queue<RBTNode<T>*> q;
    q.push(root);
    root = nullptr;
    while (!q.empty()){
        if (q.front()->left != nullptr)
            q.push(q.front()->left);
        if (q.front()->right != nullptr)
            q.push(q.front()->right);
        delete q.front();
        q.pop();
    }
}
template <class T>
RBTNode<T>* RBT<T>::find(const T& data) const{
    RBTNode<T>* temp = root;
    while (temp != nullptr){
        if (temp->data == data)
            return temp;
        else if (temp->data > data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return temp;
}
template <class T>
void RBT<T>::insert(const T& newdata){
    if (isEmpty()){
        root = new RBTNode<T>(newdata);
        root->isBlack = true;
    }
    else{
        RBTNode<T>* temp = root;
        RBTNode<T>* prev = root;
        while (temp != nullptr){
            bool leftIsBlack = isBlack(temp->left);
            bool rightIsBlack = isBlack(temp->right);
            if (temp->isBlack && !leftIsBlack && !rightIsBlack)
                recolor(temp);
            prev = temp;
            if (temp->data > newdata)
                temp = temp->left;
            else
                temp = temp->right;
        }
        RBTNode<T>* newNode = new RBTNode<T>(newdata, prev);
        if (prev->data > newdata) //left insertion
            prev->left = newNode;
        else
            prev->right = newNode;
        if (!isBlack(prev)){ //rotation will be necessary
            doRotation(newNode);
        }
    }
}
template <class T>
void RBT<T>::printPreOrder(RBTNode<T>* start){
    if (start != nullptr){
        cout << start->data << ", ";
        printPreOrder(start->left);
        printPreOrder(start->right);
    }
}
template <class T>
void RBT<T>::printInOrder(RBTNode<T>* start){
    if (start != nullptr){
        printInOrder(start->left);
        cout << start->data << ", ";
        printInOrder(start->right);
    }
}
template <class T>
void RBT<T>::printPostOrder(RBTNode<T>* start){
    if (start != nullptr){
        printPostOrder(start->left);
        printPostOrder(start->right);
        cout << start->data << ", ";
    }
}
template <class T>
void RBT<T>::printLevelOrder(RBTNode<T>* start){
    if (start == nullptr)
        return;
    queue<RBTNode<T>*> q;
    q.push(start);
    while (!q.empty()){
        cout << q.front()->data << "(";
        if (q.front()->isBlack)
            cout << "B";
        else
            cout << "R";
        cout << "), ";
        if (q.front()->left != nullptr)
            q.push(q.front()->left);
        if (q.front()->right != nullptr)
            q.push(q.front()->right);
        q.pop();
    }
}

int main(){
    RBT<int> t;
    srand(time(NULL));
    for (int i = 0; i < 10; i++){
        //int val = rand() % 100;
        //t.insert(val);
        //cout << val << endl;
        t.insert(i * 10);
    }


    cout << "Preorder: ";
    t.printPreOrder();
    cout << "Postorder: ";
    t.printPostOrder();
    cout << "Inorder: ";
    t.printInOrder();
    cout << "Levelorder: ";
    t.printLevelOrder();
    
    
}
