//#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <fstream>
#include <string>
//#include <stdio.h>
//#include <stdlib.h>
//#include <crtdbg.h>

using namespace std;

struct Node
{
    char ch;
    Node * next;

    // node()
    // {

    // }
    // node (char c, node * p) : ch(c), next(p) {};
};

// Print node
void print_list(Node * node)
{
    while(node != NULL) // While node is not pointing to NULL
    {
        
        if (node->ch != '\0')
        {
            cout << node->ch;
        }        

        node = node->next; // Set node to the pointer of current node.
    }
    cout << endl;
}
// Strip all whitespaces from insert1/2 commands.
string strip_insert(string main)
{
    string args = "";
    for (int i = 0; i < main.length(); i++)
    {
        if (main[i] != ' ')
        {
            args += main[i];
        }
    }
    return args;
}
// Delete all occurrances of a character from a linked list.
Node* delete_All(Node *head, char x, bool &processDone)
{
    Node* distinct = head;
    processDone = false;     
    bool deletedFirst = false;
    
    while (head != NULL && head->ch == x)
    {
        head = head->next;
    }
    deletedFirst = true;
    // cout << (head->ch == '\0') << 208 <<  endl;
    
    while (distinct->next != NULL)
    {
        if (distinct->next->ch == x)
        {
            distinct->next = distinct->next->next;
            processDone = true;
        }
        else
        {
            distinct = distinct->next;
        }
    }

    return head;
}
// Check if char exists in a linked list.
bool doesExist(Node * a, char ch)
{
    Node * m = a;
    while ( m != NULL)
    {
        if (m->ch == ch)
        {
            return true;
        }
        m = m->next;
    }
    return false;
}
// Insert char after a char in a linked list.
void insert_after(Node *& a, char ch)
{
    Node * s = new Node(); // Create a node to be pointed as next
    s->ch = ch; // Set value for word
    s->next = a->next; // p's memory address is set equal to a linked list's next element
                       // so that linked list's pointer would point to the p's memory address
    a->next=s;         // a's next points to p
}
// Insert chars at the end of a linked list.
void insert_back(Node ** head, char back_char)
{
    // Initialize a distinct node
    Node * new_node = new Node();
    new_node->ch = back_char;
    new_node->next = NULL;
    // Check if list is not empty
    // If it empty, distinct node will be head
    if (*head == NULL)
    {
        *head = new_node;
    }
    // Find the last node
    else
    {
        Node *last = *head;
        
        while (last->next != NULL)
        {
            last = last->next;
        }
        // Insert distinct node to the end
        last->next = new_node;
    }
}
// Insert chars at the front of a linked list/
void insert_front(Node *& head, char front_char) // Node ** head means pointer pointing to a pointer.
{
    bool process_done = false;
    // Create a distinct node
    if (head != NULL)
    {
        Node * temp = new Node();
        // Assign values of node
        temp->ch = front_char;
        // Assign next value of current node to point to head node so that it is linked to the main node.
        temp->next = head; // * *head because we are making a pointer to point to a pointer. 
        // Assign head to the temp because head was the second element and temp was the first element.
        head = temp;
        // First element with values of temp is not set as head.
    }
    else if (head == NULL)
    {
        Node * first = new Node();
        first->ch = front_char;
        first->next = head->next;
        head = first;
    }
    
    head = delete_All(head, '\0', process_done);
}
// Main inserting function, responsible for all insertions after files are read.
void inst (Node * node, char after, char ch)
{
    bool cont = true;
    while (cont)
    {
        if (node->next == NULL)
        {
            // cout << "!!!!" << endl;
            Node * new_node = new Node();
            // cout << "Before insertion: " << endl;
            new_node->ch = ch;
            new_node->next = NULL;
            // cout << endl << "After insertion: " << endl;
            if (node == NULL)
            {
                node = new_node;
            }
           
            else 
            {
                if (after != '\0')
                {
                    insert_back(&node, after);
                    cont = false;
                }
            }

        }
        else
        {
            while (node->next != NULL && cont)
            {
                if (node->ch == ch)
                {
                    // cout << "YYYYY" << endl;
                    insert_after(node, after);
                    node = node->next;
                    cont = false;
                }
                else if (node->next == NULL && cont == true)
                {
                    // cout << "WwWW" << endl;
                    // cout << "Before insertion: " << endl;
                    // print_list(node);
                    insert_front(node, after);
                    // cout << endl << "After insertion: " << endl;
                    // print_list(node);
                }
                else 
                {
                    node = node->next;
                }
            }

        }
    }
}
// Similarity detecting function.
void SIM(Node * branch_name1, Node * branch_name2)
{
    cout << "Displaying the content of the two lists: " << endl << "List1: ";
    print_list(branch_name1);
    cout << "List2: ";
    print_list(branch_name2);
    // cout << "BLANK: " << (branch_name1->ch == ' ') << " | | " << (branch_name2->ch == ' ') << endl;
    bool processDone = false;
    int similarity = 0;

    Node* branch1 = branch_name1;
    Node* branch2 = branch_name2;

    branch1 = delete_All(branch1, '\0', processDone); branch2 =delete_All(branch2, '\0', processDone);
    branch_name1 = delete_All(branch_name1, '\0', processDone); branch_name2 = delete_All(branch_name2, '\0', processDone);

    while (branch_name1 != NULL && branch_name2 != NULL)
    {
        if (branch_name1->ch == branch_name2->ch)
        {
            if (branch_name1->ch != '\0' && branch_name2->ch != '\0')
            {
                similarity++;
            }
        }
    
        branch_name1 = branch_name1->next; 
        branch_name2 = branch_name2->next;
    }
    cout << "There is/are " << similarity << " letter(s) matched in the same positions in both lists." << endl << endl;

    // printList(branch_name2);
}
// Completely deletes a linked list.
void deleteList(Node** head_ref)
{
 
    /* deref head_ref to get the real head */
    Node* current = *head_ref;
    Node* next = NULL;
    
    while (current != NULL)
    {
        next = current->next;
        delete current; current = NULL;
        current = next;
    }
 
    /* deref head_ref to affect the real head back
        in the caller. */
    *head_ref = NULL;
}
// Main program, commands are checked and related functions are called here.
bool command_valid(string command, Node *& first_node, Node *& second_node, bool argumentValid)
{
    string main_command = command.substr(0, command.find(" "));
    // cout << "command is 132: " << command << endl;
    argumentValid = false;
    
    if (main_command == "exit")
    {
        // deleteList(&first_node); deleteList(&second_node);
        return true;
    }
    
    else if (main_command == "sim")
    {
        SIM(first_node, second_node);
        return true;
    }

    else if (main_command == "insert1")
    {
        
        command = command.substr(main_command.length());
        string args = strip_insert(command);

        // cout << "insert1 detected" << endl;
        
        char insert1_first  = args[0];
        char insert1_second = args[1];        

        // cout << insert1_first << endl << insert1_second << endl;

        if (insert1_first == toupper(insert1_first) || insert1_second == toupper(insert1_second))
        {
            argumentValid = false;
            
            if (argumentValid == false)
            {
                cout << "Invalid arguments." << endl << endl;
            }
        }
        
        else
        {
            argumentValid = true;
            // cout << "The node with value " << insert1_second << " exists? " << doesExist(first_node, insert1_second); cout << endl;
            if (doesExist(first_node, insert1_second))
            {
                cout << "Inserting " << insert1_first << " after " << insert1_second << " in List1." << endl;
                cout << "The node with " << insert1_first << " has been inserted after the first occurrence of a node with " << insert1_second <<" value."; cout << endl;
                inst(first_node, insert1_first, insert1_second);
                cout << "The current content of List1 is: "; print_list(first_node); cout << endl; 
            }
            else
            {
                insert_front(first_node, insert1_first);
                cout << "The node with " << insert1_second << " value does not exist. Therefore, Inserting " << insert1_first << " at the beginning of the list." << endl;
                cout << "The current content of List1 is: "; print_list(first_node); cout << endl;
            }


        }
    }
        

    else if (main_command == "insert2")
    {
        // cout << "insert1 detected" << endl;
        command = command.substr(main_command.length());
        string args = strip_insert(command);

        // cout << "insert1 detected" << endl;
        
        char insert2_first  = args[0];
        char insert2_second = args[1];  
        // cout << insert1_first << endl << insert1_second << endl;

        if (insert2_first == toupper(insert2_first) || insert2_second == toupper(insert2_second))
        {
            argumentValid = false;
            
            if (argumentValid == false)
            {
                cout << "Invalid arguments." << endl << endl;
            }
        }

        else
        {
            argumentValid = true;
            // cout << "The node with value " << insert1_second << " exists? " << doesExist(second_node, insert1_second); cout << endl;
            if (doesExist(second_node, insert2_second))
            {
                cout << "Inserting " << insert2_first << " after " << insert2_second << " in List1." << endl;
                cout << "The node with " << insert2_first << " has been inserted after the first occurrence of a node with " << insert2_second <<" value." << endl;
                inst(second_node, insert2_first, insert2_second);
                cout << "The current content of List2 is: "; print_list(second_node); cout << endl;
            }
            else
            {
                insert_front(second_node, insert2_first);
                cout << "The node with " << insert2_second << " value does not exist. Therefore, Inserting " << insert2_first << " at the beginning of the list." << endl;
                cout << "The current content of List2 is: "; print_list(second_node); cout << endl;

            }
        }
    }

    else if (main_command == "del1")
    {
        command = command.substr(main_command.length());
        string args = strip_insert(command);

        // cout << "insert1 detected" << endl;
        
        char del1_char  = args[0];

        // char del1_char  = command.substr(command.find(" ") + 1, 1)[0];

        if (del1_char == toupper(del1_char))
        {
            argumentValid = false;
            
            if (argumentValid == false)
            {
                cout << "Invalid arguments." << endl << endl;
            }
        }

        else
        {
            argumentValid = true;
            
            bool processDone = false;

            if (doesExist(first_node, del1_char))
            {
                first_node = delete_All(first_node, del1_char, processDone);
                cout << "Deleting all occurrences of " << del1_char << " in List1." << endl;
                cout << "The current content of List1 is: "; print_list(first_node); cout << endl;              
            }

            else
            {
                cout << "No deletion as the value " << del1_char  << " was not found in the list." << endl << endl;
            }

        }
    }

    else if (main_command == "del2")
    {
        command = command.substr(main_command.length());
        string args = strip_insert(command);

        // cout << "insert1 detected" << endl;
        
        char del2_char  = args[0];
        
        if (del2_char == toupper(del2_char))
        {
            argumentValid = false;
            
            if (argumentValid == false)
            {
                cout << "Invalid arguments." << endl << endl;
            }
        }

        else
        {
            argumentValid = true;
            
            bool processDone = false;
            

            if (doesExist(second_node, del2_char))
            {
                second_node = delete_All(second_node, del2_char, processDone);
                cout << "Deleting all occurrences of " << del2_char << " in List1." << endl;
                cout << "The current content of List2 is: "; print_list(second_node); cout << endl;              
            }

            else
            {
                cout << "No deletion as the value " << del2_char  << " was not found in the list." << endl << endl;
            }
            
        }
    }
    else 
    {
        return false;
    }
    return true;
}


int main()
{
    // Reads files, creates linked lists.
    ifstream file_Name_1, file_Name_2;
    string input1_Name = "", input2_Name = "", err = "";
    char ch_From_File_1, ch_From_File_2;

    Node* p = new Node();
    Node*q = new Node();

    // Input check for file 1 begins
    cout << "Please enter a file 1 name: "; cin >>  input1_Name;

    file_Name_1.open(input1_Name.c_str());

    while (file_Name_1.fail())
    {
        cout << "Please enter a file 1 name: "; cin >> input1_Name;
        file_Name_1.clear(); 
        file_Name_1 >> err;
        file_Name_1.open(input1_Name.c_str());
    }
    // Input check for file 1 ends
    // ---------------------------
    // Input check for file 2 begins
    cout << "Please enter a file 2 name: "; cin >> input2_Name;

    file_Name_2.open(input2_Name.c_str());

    while (file_Name_2.fail())
    {
        cout << "Please enter a file 2 name: "; cin >> input2_Name;
        file_Name_2.clear();
        file_Name_2 >> err;
        file_Name_2.open(input2_Name.c_str());
    }
    // Input check for file 2 ends

    

    while (file_Name_1 >> ch_From_File_1)
    { 
        // cout << 87 << " " << ( ch_From_File_1 == 'h' )<< endl;
        if (ch_From_File_1 != '\0')
        {
            insert_back(&p, ch_From_File_1);
        }
        // cout << p->ch;
    }


    while(file_Name_2 >> ch_From_File_2)
    {
        if (ch_From_File_1 != '\0')
        {
            insert_back(&q, ch_From_File_2);
        }
    }
    cout << "List1: ";  
    print_list(p); 
    
    cout << "List2: ";
    print_list(q);
    cout << endl;

    
    file_Name_1.close();
    file_Name_2.close();

    
    string command;
    bool program_continue = true, argument_valid = true, processDone = false;
    cout << "Enter a command and its corresponding argument(s), if any: ";

    getline(cin >> ws, command);
    // cout << "Command is: " << command << endl;
    // Part of main program that user interacts with.
    while (program_continue)
    {
        // delete_All(p , '\0', processDone); delete_All(q, '\0', processDone);
        if (command_valid(command, p, q, argument_valid))
        {
            // cout << "Command is valid. Doing something bla bla bla... " << endl;
            
            if (command == "exit")
            {
                // cout << endl << "exit detected." << endl;
                deleteList(&p); deleteList(&q);
                cout << "Clearing the two lists and saying Goodbye!" << endl;
                program_continue = false;
            }
            else
            {
                cout << "Enter a command and its corresponding argument(s), if any: "; getline(cin >> ws, command);
            }
            
        }

        else
        {            
            if (argument_valid != true)
            {
                cout << "Invalid arguments." << endl << endl;
            }
            else
            {
                cout << "Invalid command." << endl << endl << "Enter a command and its corresponding argument(s), if any: "; getline(cin >> ws, command);
            }
        }
    }
	delete p; p = NULL; delete q; q = NULL;
	// _CrtDumpMemoryLeaks();
	// system("pause");
  
	return 0;
}