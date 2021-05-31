#include <iostream>
using namespace std;
unsigned int S;
int M;
#define endl '\n'

void add(int x){
    S |= (1<<x);
}


void remove(int x){
    S &= ~(1<<x);
}

void check(int x){
    if(S & (1 << x))
        cout << '1' << endl;
    else {
        cout << '0' << endl;
    }
}

void toggle(int x){
    S ^= (1 << x);
}

void all(){
    S |= (1 << 21) - 1;
}

void empty(){
    S &= 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M;

    for(int i=0 ; i<M; ++i){
        string command;
        cin >> command;
        if(command == "add"){
            int x;
            cin >> x;
            add(x);
        }
        else if (command == "remove"){
            int x;
            cin >> x;
            remove(x);
        }

        else if (command == "check"){
            int x;
            cin >> x;
            check(x);
        }
        else if (command == "toggle"){
            int x;
            cin >> x;
            toggle(x);
        }

        else if (command == "all"){
            all();
        }
        else{
            empty();
        }
    }

}
