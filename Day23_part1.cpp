#include <iostream>
#include <string>
#include <array>

using namespace std;
//
// Linked list building block
struct node {
    unsigned int value;
    node * next;
};

node * get_dest_cup(node * cur_cup, node * rem_cups[], int Np1){
    unsigned int dest_label = (cur_cup->value - 1) % Np1;
    /*
    */
    while (true){
        if ( (dest_label != 0) and (dest_label != rem_cups[0]->value) \
                and (dest_label != rem_cups[1]->value) and (dest_label != rem_cups[2]->value) ){
            node * next_cup = cur_cup->next;
            while (true) {
                if (next_cup->value == dest_label){
                    return next_cup;
                }
                next_cup = next_cup->next;
            }
        }
        dest_label = (dest_label - 1 + Np1) % Np1;
    }
}

node * shift_cups(node * cur_cup, int Np1){
    node * rem_cups[3];
    node * prev_pair;

    node * cur_pair = cur_cup->next;
    for(unsigned int ii=0;ii<3;ii++){
        rem_cups[ii] = cur_pair;
        prev_pair = cur_pair;
        cur_pair = cur_pair->next;
    }

    node * rem_first = cur_cup->next;
    node * rem_last = prev_pair;

    // Remove hole
    cur_cup->next = cur_pair;
    node * dest_cup = get_dest_cup(cur_cup, rem_cups, Np1);
    node * dest_pair = dest_cup->next;

    // Add back cups
    dest_cup->next = rem_first;
    rem_last->next = dest_pair;
    return cur_pair;

}

void print_list(node * cur_node){
    node * it_node = cur_node;
    do{
        cout<<it_node->value<<" ";
        it_node = it_node->next;


    }while (it_node->value != cur_node->value);
    cout<<endl;
}

int main(void){
    // Initialise linked list
    string first_nums = "215694783";
    node * head = new node;
    head->value = int(first_nums[0])-48;
    node * prev_node = head;
    int Np1 = 0;
    for (unsigned int ii=1;ii<first_nums.length();ii++){

        node * cur_node = new node;
        char cur_val = first_nums[ii];
        cur_node->value = int(cur_val)-48;
        prev_node->next = cur_node;
        prev_node = cur_node;
        if (int(first_nums[ii]-48) > Np1){
            Np1 = int(first_nums[ii])-48;
        }
    }
    prev_node->next = head;
    Np1++;
    cout<<"Np1: "<<Np1<<endl;

    node * step_cup = head;
    for(unsigned int rr=0; rr<100; rr++){
        node * next_cup = shift_cups(step_cup, Np1);
        step_cup = next_cup;

    }
    cout<<"Part one solution:"<<endl;
    print_list(step_cup);

    return 0;
}
