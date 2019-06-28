/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

/*
Hash map based solution.
Store the mapping of address of nodes of original and new list.
And create new list in parallel

in Second run map random pointer as per the original list.


Another way is  -- 
Create the copy of node 1 and insert it between node 1 & node 2 in original Linked List, create the copy of 2 and insert it between 2 & 3.. Continue in this fashion, add the copy of N afte the Nth node

Now copy the random link in this fashion
 original->next->random= original->random->next;  //TRAVERSE TWO NODES
This works because original->next is nothing but copy of original and Original->random->next is nothing but copy of random.

Now restore the original and copy linked lists in this fashion in a single loop.
original->next = original->next->next;
     copy->next = copy->next->next;

Ensure that original->next is NULL and return the cloned list
*/

//hash map based

class Solution {
public:
    Node* copyRandomList(Node* head){
        
        if(head == NULL)
            return NULL;
        
        Node *temp = head;
        Node* temp1 = NULL;
        Node *temp2 = NULL;
        
        map<Node*, Node*> Add;
        
        //Add.insert(pair<Node*, Node*>(1, 40)); 
        
        while(temp)
        {
            if(temp1 == NULL)
            {
                temp2 = new Node ;
                temp1 = temp2;
            }
            else
            {
                temp2->next = new Node;
                temp2 = temp2->next;   
            }
            temp2->next = NULL;
            temp2->random = temp->random;
            temp2->val = temp->val;
            
            Add.insert({temp, temp2}); 
            
            temp = temp->next;
        }
        
        temp = temp1;
        temp2 = NULL;
        
        map<Node*, Node*>::iterator itr; 
        
        while(temp)
        {
            temp2 = temp->random;
            if(temp2){
                itr = Add.find(temp2);
                temp->random = itr->second;
            }
            temp = temp->next;
        }
        
        return temp1;
    }
};


=============================================================
//using constant space

class Solution {
public:
    Node* copyRandomList(Node* head){
        
        if(head == NULL)
            return NULL;
        
        Node *temp = head;
        Node* temp1 = NULL;
        Node *temp2 = NULL;
        
        while(temp)
        {
            //copy new node between 1 and 2 
            //coninue in this fashion   
            temp2 = new Node; 
            temp2->next = temp->next;
            temp2->random = NULL;
            temp2->val = temp->val;
            temp->next = temp2;

            temp = temp->next->next;
        }
        
        temp = head;
        temp2 = NULL;
         
        while(temp)
        {
            if(temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;   
        }
        
        temp = head;
        temp2 = NULL;
        
        while(temp)
        {
            if(!temp1)
            {
                temp1 = temp->next;
                temp2 = temp->next;
            }            
            else
            {
                temp2->next = temp->next;
                temp2 = temp2->next;
            }         
            temp->next = temp->next->next;
            temp2->next = NULL;   
            temp = temp->next;
        }
        
        return temp1;
    }
};
