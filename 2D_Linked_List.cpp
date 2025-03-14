#include <iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=prev;
    }
    Node(int data,Node* prev, Node* next){
        this->data=data;
        this->prev=prev;
        this->next=next;
    }
};
//Doubly Linked List : 
//Application : Browser


//TO PRINT THE DOUBLY LINKED LIST :

void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
    //Just to check its a doubly linked list :
    //cout<<head->next->next->prev->data;
}



//TO CONVERT THE ARRAY IN DLL:

 Node* ConvertArr(vector<int> arr){
     Node* head = new Node(arr[0]);
     Node* prev = head;
     for(int i=1;i<arr.size();i++){
         Node* temp = new Node(arr[i],prev,nullptr);
         prev->next=temp;
         prev=temp;
     }
     return head;
 }


//TO DELETE THE HEAD:
 
 Node* deleteHead(Node* head){
     if(head==nullptr || head->next==NULL) return NULL;
       
     Node* temp = head;
     head=head->next;
         
     head->prev=nullptr;
     temp->next=nullptr; 
         
     delete temp;
     return head;
 }


//DELETE TAIL :

  Node* deleteTail(Node* head){
     if(head==NULL || head->next == NULL){
         return NULL;
     }
     Node* tail = head;
     while(tail->next != NULL){
         tail=tail->next;
     }
     //pointer pointing to same memory location as tail->prev is pointing.
     Node* temp =  tail->prev;
     tail->prev = nullptr;
     temp->next=nullptr;
     delete(tail);
     return head;
 }

//DELETE Kth ELEMENT IN LL:
 Node* deleteKthElement(Node* head,int k){
     if(head==NULL) return head;
     int counter=0;
     bool found=false;
     Node* temp=head;
     while(temp!= NULL){
         counter++;
         if(counter==k){
            found=true;
            break;
         }
         temp=temp->next;
     }
     //If element is not there in LL:
     if(!found) return head;
     
     Node* back= temp->prev;
     Node* front = temp->next;
     if(back == NULL && front==NULL) {
         delete temp;
         return nullptr;
     }
     else if(back==NULL) return deleteHead(head);
     else if(front==NULL) return deleteTail(head);
     else{
         back->next=front;
         front->prev=back;
         delete temp;
     }
     return head;
}



//DELETE NODE HAVING ele ELEMENT:
Node* deleteElement(Node* head,int ele){
    if(!head) return nullptr;
    bool found=false;
    Node* temp = head;
    while(temp){
        if(temp->data == ele){
            found=true;
            break;
        }
        temp=temp->next;
    }
    if(!found) return head;
    Node* back=temp->prev;
    Node* front= temp->next;
    if(!back && !front) {
        delete temp;
        return nullptr;
    }
    else if(back==NULL){
        head=head->next;
        head->prev=nullptr;
        delete temp;
        return head;
    }
    else if(front==NULL){
        back->next = nullptr;
        delete temp;
        return head;
    }else{
        back->next=front;
        front->prev=back;
        delete temp;
    }
    return head;
}


//INSERT NEW HEAD IN LL:
Node* insertHead(Node* head,int val){
    Node* newHead = new Node(val,nullptr,head);
    if(!head) return newHead;
    head->prev=newHead;
    head=newHead;
    return head;
}

//INSERT NEW TAIL IN LL:
Node* insertTail(Node* head , int val){
    Node* newTail = new Node( val,nullptr,nullptr);
    if(!head) return newTail;
    Node* temp = head;
    //Moving temp to tail:
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next= newTail;
    newTail->prev=temp;
    return head;
}


Node* insertBeforeTail(Node* head , int val){
    Node* beforeTail = new Node( val,nullptr,nullptr);
    if(!head) return beforeTail;
    //if there is only one node:
    if(!head->next) return insertHead(head,val);

    //more than 1 node:
    Node* temp = head;
    //Moving temp to tail:
    while(temp->next)   temp=temp->next;
    //Node before tail:
    Node* back = temp->prev;
    //inserting before tail node:
    back->next=beforeTail;
    beforeTail->next=temp;
    beforeTail->prev=back;
    temp->prev=beforeTail;
    return head;
}


// Insert before Kth element in LL: 1 2 3 4 5 and after adding 6 while k=3 : It means 6 will be placed before the 3rd element.

Node* insertBeforeKth(Node* head,int k,int val){
    if(k==1){
        if(head==NULL) return new Node(val,nullptr,nullptr);
        else return insertHead(head,val);
    }else{
        if(!head) return head;
        int count=0;
        bool found=false;
        Node* mover=head;
        while(mover){
            count++;
            if(count==k){
                found=true;
                break;
            }
            mover=mover->next;
        }
        if(!found) return head;
        else{
            Node* temp = new Node(val,nullptr,mover);
            Node* back = mover->prev;
            back->next=temp;
            mover->prev=temp;
            temp->prev=back;
        }
        
    }
    return head;
}


// Insert before "ELE" element in LL:

Node* insertBeforeEle(Node* head,int ele,int val){
    if(head==NULL) return head;
    else if(head->data == ele) head = insertHead(head,val);
    else{
        bool found=false;
        Node* mover=head;
        while(mover){
            if(mover->data == ele){
                found=true;
                break;
            }
            mover=mover->next;
        }
        if(!found) return head;
        else{
            Node* temp = new Node(val,nullptr,mover);
            Node* back = mover->prev;
            back->next=temp;
            mover->prev=temp;
            temp->prev=back;
        }
        
    }
    return head;
}

Node* reverseByPointer(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    Node* last=NULL;
    while(temp){
        last = temp->prev;
        temp->prev=temp->next;
        temp->next=last;
        temp=temp->prev;
    }
    return last->prev ;
}






int main(){
	vector<int> arr = {2,4,6,8,10,12};
    	//Converting array into LL:
    	Node* head = ConvertArr(arr); 
    	//Deleting head of LL:
    	//head = deleteHead(head);
        // head = deleteKthElement(head,3);
        // head = insertHead(head,0);
        // head = insertTail(head,6);
        // head = insertBeforeTail(head,5);
        //head = insertBeforeKth(head,8,4);
        
	//printing the DLL:
	//print(head);
	return 0;
}