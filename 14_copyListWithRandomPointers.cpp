class Solution {
public:
    Node* copyRandomList(Node* head) {
        // brute force 

        // unordered_map<Node*, Node*> mp;
        // Node* temp= head;


        // while(temp){
        //     Node* copy= new Node(temp->val);
        //     mp[temp]= copy;
        //     temp= temp->next;
        // }

        // temp= head;
        // while(temp){
        //     Node* copy= mp[temp];
        //     Node* originalNext= temp->next;
        //     Node* originalRandom= temp->random;
            
        //     Node* copyNext= mp[originalNext];// deep copy ka next 
        //     Node* copyRandom= mp[originalRandom];// deep copy ka random
            
        //     copy->next= copyNext;
        //     copy->random= copyRandom;
            
        //     temp= temp->next;
        // }
        // return mp[head];

        //optimal solution


        Node* iter = head;
        Node* front = head;

        while(iter != NULL){
            front = iter->next;

            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;

            iter = front;
        }

        iter = head;
        while(iter != NULL){
            if(iter->random != NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

        iter = head;
        Node* pseudoHead = new Node(0);
        Node* copy = pseudoHead;

        while(iter != NULL){
            front = iter->next->next;

            copy->next = iter->next;

            iter->next = front;

            copy = copy->next;
            iter = front;
        }

        return pseudoHead->next;
    }
};