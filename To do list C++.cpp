#include <iostream>
using namespace std;

struct todo {
    string task;
    string statuts;
    todo *link;
};

class list {
    todo *start, *cur, *temp;

public:
    list() {
        start = NULL;
        cur = NULL;
        temp = NULL;
    }

    void opend(string t, string s) {
        if (start == NULL) {
            start = new todo;
            start->task = t;
            start->statuts = s;   
            start->link = NULL;
        } 
        else {
            cur = start;
            while (cur->link != NULL)
                cur = cur->link;

            temp = new todo;
            temp->task = t;
            temp->statuts = s;
            temp->link = NULL;
            cur->link = temp;
        }
    }
    void display() {
        cur = start;
        while (cur != NULL) {
            cout <<"#"<< cur->task << "   " << cur->statuts << endl;
            cur = cur->link;
        }
    }
    void updateTask(){
    	if(start == NULL){
    		cout<<"List is empty\n";
    		return;
		}
			bool found = false;
			string task,ntask,nstatus;
		cout<<"\n====== current tasks========\n";
		display();
		cout<<"Enter The task's Name: ";
		cin>>task;
		cur = start;
		while(cur != NULL){
			if(cur->task == task){
				cout<<"Enter New task name: ";
                cin>>ntask;
                cout<<"Enter New status: ";
                cin>>nstatus;

				cur->statuts = nstatus;
				cur->task = ntask;
				found = true;
				cout<<"updation Successful!!\n";
				return;
				
			}
			cur = cur->link;
		}
		if (!found){
			cout<<"Invalid entry\n";
			return;
		}
			
	}
    void updatestatus(){
    	
    	if(start == NULL){
    		cout<<"List is empty\n";
    		return;
		}
		bool found = false;
		cout<<"\n====== current tasks========\n";
		display();
		string task,nstatus;
		cout<<"Enter The task's Name: ";
		cin>>task;
		cur = start;
		while(cur != NULL){
			if(cur->task == task){
				cout<<"Enter New status: ";
				cin>>nstatus;
				cur->statuts = nstatus;
				found = true;
				cout<<"updation Successful!!\n";
				return;
				
			}
			cur = cur->link;
		}
		if (!found){
			cout<<"Invalid entry\n";
			return;
		}
		
	}
    void deleteTask(){
    	cur = start;
    	int pos;
    	if(start == NULL){
    		cout<<"List is empty\n";
    		return;
		}
		cout<<"\n====== current tasks========\n";
		display();
		cout<<"Enter pos of task: ";
		cin>>pos;
		if (pos == 1){
			
			start = start->link;
			delete cur;
			cout<<"Deletion Successful!!\n";
			return;
		
		}
    	for (int i = 1; i < pos && cur != NULL; i++){
    		temp = cur;
    		cur = cur->link;
    		
		}
		if (cur == NULL){
			cout<<"INvalid case\n";
			return;
		}
		temp->link = cur->link;
		delete cur;
		cout<<"Deletion Successful!!\n";
	}
};

int main() {
    list l;
    int choice;
    cout<<"\n======== Main Menu ==========\n";
    do{
    	cout<<"\n1. To insert task\n2. To Diplay\n3. To Update status\n4. To update Task\n5. Delete task\n6. exist\n";    	
		cout<<"Enter your choice: ";
    	cin>>choice;
    	switch(choice){
    		case 1:
    			{
				
    			string task,status;
    			cout<<"Enter task and its status: ";
    			cin>>task>>status;
    			l.opend(task,status);
    			break;
    			}
    		case 2:
    			l.display();
    			break;
    		case 3: 
    		   l.updatestatus();
    		   break;
    		case 4:
    			l.updateTask();
    			break;
    		case 5:
    			l.deleteTask();
    			break;
    		default:
			       cout<<"Invaid case\n";	
		}
	} while(choice != 6);
    return 0;
}

