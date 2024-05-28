#include<iostream>


using namespace std;

class Tasks
{
    public:
        string Title;
        string date;
        string Output()
        {
            return  Title + " : " + date + " : incomplete";
        }
};

void view()
{
    cout << "............................................................ \n";
    cout << "                         TO DO LIST                          \n";
    cout << "............................................................ \n";
    cout << "\n";
    cout << "::::::::::::::::::::::: PROGRAM MENU ::::::::::::::::::::::: \n";

    cout << "1. Add new task \n";
    cout << "2. Display all tasks \n";
    cout << "3. Mark as complete \n";
    cout << "4. Edit task \n";
    cout << "5. Remove task \n";
    cout << "6. Exit \n";

}


int menu() {
    string choice ;
    
    while (true) {
        
        view();
        cout << "Enter Your Choice: ";
        getline(cin, choice);

        if (choice < "7" && choice > "0") {

            return stoi (choice);
        }
        else {

            system("clear");
            cout << "Enter Valid Number ... \n";  
        }
        
    }
    
}

string New_Task()
{
    Tasks Temp;
    
    cout << "Add your task title: ";
    getline(cin, Temp.Title);

    
    cout << "set time for this task: (example: yyyy/mm/dd) \n";
    getline(cin, Temp.date);

    string final = Temp.Output();
    system("clear");
    return final;
}
void Display_All(string list[], int n) {

    system("clear");
    for(int i=0; i<n; i++) {

        cout<<"[" << i+1 << "] : " << list[i] << "\n";
    }
    
}

void Mark_as_Complete(string list[], int n)
{
    system("clear");
    Display_All(list, n);
    string temp ;
    int Target;
    cout << "Which Task ?(Just Number of Task) : ";
    
    getline(cin, temp);

    while (true) {

        if (temp > "0" && temp < to_string(n+1)) {

            Target = stoi(temp)-1;
            break;
        }
        else {

            system("clear");
            cout << "Enter a Valid Choice ...\n ";
            cout << "Which Task ?(Just Number of Task) : ";
            getline(cin, temp);
        }   
    }
    
    for (int i = size(list[Target]); list[Target][i] != ':'; i--) {

        if (list[Target][i]=='i' || list[Target][i] == 'n') {

            list[Target][i] = '#';
        }
        
    }

    Display_All(list,n);
    
}




void Edit_Task(string list[],int n) 
{
    system("clear");
    Display_All(list, n);
    string temp ;
    int Target;
    cout << "Which Task to Edit ?(Just Number of Task) : ";
    
    getline(cin, temp);

    while (true) {

        if (temp > "0" && temp < to_string(n+1)) {

            Target = stoi(temp)-1;
            break;
        }
        else {

            system("clear");
            cout << "Enter a Valid Choice ...\n ";
            cout << "Which Task ?(Just Number of Task) : ";
            getline(cin, temp);
        }   
    }    
    string  temp2 = New_Task();

    list[Target]=temp2;

}

int  Remove_Task(string list[],int n)
{
    system("clear");
    Display_All(list, n);
    string temp ;
    int Target;
    cout << "Which Task to Remove ?(Just Number of Task) : ";
    
    getline(cin, temp);

    while (true) {

        if (temp > "0" && temp < to_string(n+1)) {

            Target = stoi(temp)-1;
            break;
        }
        else {

            system("clear");
            cout << "Enter a Valid Choice ...\n ";
            cout << "Which Task ?(Just Number of Task) : ";
            getline(cin, temp);
        }   
    } 

    list[Target] = "";
    return Target;


}

int main() {
    int rem ;
    string temp;
    string tasks[100];
    int count = 0;
    int choice;
    while(true)
    {
        choice = menu();

        if (choice == 1) {

            tasks[count] = New_Task();
            count++;
        }
        else if (choice == 2) {

            Display_All(tasks, count);
        
        }
        else if (choice == 3) {

            Mark_as_Complete(tasks, count);
        }
        else if (choice == 4) {

            Edit_Task(tasks,count);
        }
        else if(choice == 5)
        {
            rem = Remove_Task(tasks,count);
            temp = tasks[rem];
            tasks[rem] = tasks[count];
            tasks[count] = temp;
            count--;
            system("clear");
            Display_All(tasks,count);
        }
        else if (choice == 6)
        {
            exit(0);
        }
        
    }

    return 0;
}