
#include <iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
    Node(int data,Node* next){
        this->data=data;
        this->next=next;
    }
};

void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
}
 Node* ConvertArr(vector<int> arr){
     Node* head = new Node(arr[0]);
     Node* mover = head;
     for(int i=1;i<arr.size();i++){
         Node* temp = new Node(arr[i]);
         mover->next=temp;
         mover=temp;
     }
     return head;
 }
 
 Node* deleteHead(Node* head){
     if(head==nullptr) return head;
     Node* temp = head;
     head=head->next;
     delete temp;
     return head;
 }

  Node* deleteTail(Node* head){
     if(head==NULL || head->next == NULL){
         return NULL;
     }
     Node* temp = head;
     while(temp->next->next != NULL){
         temp=temp->next;
     }
     delete(temp->next);
     temp->next = nullptr;
     return head;
 }

  Node* deleteAtK(Node* head,int k){
     if(head==NULL) return head;
     if(k==1){
         Node* temp = head;
         head=head->next;
         delete temp;
         return head;
     }
     int counter=0;
     Node* prev=NULL;
     Node* temp=head;
     while(temp!= NULL){
         counter++;
         if(counter==k){
             prev->next=prev->next->next;
             delete temp;
             break;
         }
         prev=temp;
         temp=temp->next;
     }
     return head;
 }


Node* deleteElement(Node* head,int ele){
     if(head==NULL) return head;
     if(head->data == ele){
         Node* temp = head;
         head=head->next;
         delete temp;
         return head;
     }
     Node* prev=NULL;
     Node* temp=head;
     while(temp){
         if(temp->data == ele){
             prev->next=prev->next->next;
             delete temp;
             break;
         }
         prev=temp;
         temp=temp->next;
     }
     return head;
 }

Node* insertAtHead(Node* head,int val){
    Node* temp = new Node(val,head);
    head=temp;  //instead of this, we can simply return temp as head of Linked List.
    return head;
}

Node* insertAtEnd(Node* head,int val){
    Node* temp = new Node(val);
    if(head==NULL) return temp;
    Node* mover = head;
    while(mover->next!=NULL){
        mover=mover->next;
    }
    mover->next=temp;
    return head;
}


Node* insertAtK(Node* head, int k, int val){
    if(k==1){
        if(head==NULL) return new Node(val);
        else {
            Node* temp = new Node( val);
            temp->next=head;
            return temp;
        }
    }
    Node* mover = head;
    Node* temp = new Node(val);
    int count=0;
    while(mover){
        count++;
        if(count==k - 1){
            temp->next=mover->next;
            mover->next=temp;
            break;
        }
        mover=mover->next;
    }
    
    return head;
}



Node* insertBeforeK(Node* head, int k, int val){
    if(head==NULL) return head;
    if(head->data == k)  return new Node(val,head);
      
    Node* mover = head;
    while(mover->next!=NULL){
        if(mover->next->data == k){
            Node* temp = new Node(val,mover->next);
            mover->next=temp;
            break;
        }
        mover=mover->next;
    }
    
    return head;
}

Node* AddNumbers(Node* head1,Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    int carry = 0;
    while( t1 != NULL || t2 != NULL){
        int sum =0;
        if( t1) {
            sum+=t1->data;
            t1=t1->next;
        }
        if(t2){
            sum+=t2->data;
            t2=t2->next;
        }
        curr->next = new Node((sum+carry)%10 );
        curr=curr->next;
        carry = sum/10;
    }
    if(carry>0) curr->next = new Node(carry);
    return dummyNode->next;
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* front = NULL;

    while( curr){
        front = curr->next;
        curr->next = prev;
        prev=curr;
        curr= front;
    }
    return prev;
}

Node* sortByBruteForce(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* temp =head;
    int count1=0,count2=0,count0=0;
    while(temp){
        if(temp->data == 0) count0++;
        else if(temp->data == 1)    count1++;
        else count2++;
        temp=temp->next;
    }

    temp=head;
    while(temp){
        if(count0){
            temp->data=0;
            count0--;
        }else if(count1){
            temp->data=1;
            count1--;
        }else{
            temp->data=2;
            count2--;
        }
        temp=temp->next;

    }
    return head;
}


Node* sort012(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* zeroHead=new Node(-1);
    Node* oneHead=new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zero=zeroHead;
    Node* one=oneHead;
    Node* two=twoHead;
    Node* temp = head;
    while(temp){
        if(temp->data == 0) {
            zero->next=temp;
            zero=zero->next;
        }else if(temp->data == 1){
            one->next =temp;
            one=one->next;
        }
        else{
            two->next =temp;
            two=two->next;
        } 
        temp=temp->next;
    }
    zero->next= (oneHead->next)? oneHead->next : twoHead->next;  // first we will check whether there is node with value 1 or not, if node we directly link it with node having value 2.
    one->next=twoHead->next;
    two->next=NULL;
    head = zeroHead->next;
    delete oneHead;
    delete twoHead;
    delete zeroHead;
    
    return head;
}
Node* DeleteFromLast(Node* head,int k){
    if(head==NULL || k==0) return head;
    Node* slow = head;
    Node* fast = head;

    while(k--){
        fast = fast->next;
    }
    if( fast == NULL) return head = deleteHead(head);
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    Node* del = slow->next;
    slow->next = del->next;
    delete del;
    return head;
}


Node* reverseByData(Node* head){
    stack<int> st;
    if( head==NULL || head->next == NULL) return head;
    Node* mover = head;
    while(mover){
        st.push(mover->data);
        mover = mover->next;
    }
    mover=head;
    while(mover){
        mover->data = st.top();
        st.pop();
        mover=mover->next;
    }
    return head;
}



Node* reverseByRecursion(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* newHead = reverseByRecursion(head->next);
    Node* front = head->next;
    front->next = head;
    head->next=NULL;
    
    return newHead;
}

Node* MiddleNode(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool palindrome(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead = reverseByRecursion(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second){
        if(first->data != second->data){
            reverseByRecursion(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseByRecursion(newHead);
    return true;

}

Node* rotate(Node* head,int k){
    if (!head || !head->next || k == 0) return head;

    Node* fast = head;
    Node* slow=head;

    for(int i=0;i<k;i++){
        fast=fast->next;
    }

    while(fast->next != NULL){
        slow=slow->next;
        fast=fast->next;
    }

    Node* newHead = slow->next;
    fast->next=head;
    slow->next=NULL;
    return newHead;
}
int main() {
    vector<int> arr = {1,2,3,4,5,6,7};
    //Converting array into LL:
    Node* head = ConvertArr(arr);
    //Deleting head of LL:
    // head = deleteHead(head);
    // //Deleting tail of LL:
    // head = deleteTail(head);
    // //Delete node present at position : K 
    // head = deleteAtK(head,3);
    // //Delete first element(ele) present in LL: { If element's frequency is more than 1, it will delete first one}
    // head = deleteElement(head,3);
    
    // head = insertAtHead(head,0);
    //head = insertAtEnd(head,6);
   // head = sortByBruteForce(head);
    //head = sort012(head);
    //head = DeleteFromLast(head,5);
    //head = reverseByRecursion(head);
    // Node* midNode = MiddleNode(head);
    // cout << "Middle Node: " << midNode->data << endl;
    //cout<<palindrome(head)<<endl;
    head = rotate(head,3);
    print(head);
    return 0;
}
