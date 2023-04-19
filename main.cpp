#include <iostream>
#include <stack>

using namespace std;
int main(){
    string str;

    while (true){

        cout << "Please enter a string expression:(99 to stop): ";
        getline(cin, str);

        if (str == "99")
        {

            break;

        } // if

        bool flag = true;

        stack<char> st;

        for (int i = 0; i < str.size(); i++){
            
            if ((str.at(i) >= '0' && str.at(i) <= '9') || str.at(i) == '+' || str.at(i) == '-' || str.at(i) == '/' || str.at(i) == '*' || str.at(i) == ' ')
            {

                continue;
            }
            if (str.at(i) == '{' || str.at(i) == '(') {
                
                st.push(str.at(i));
            }
            else if (!st.empty() && ((st.top() == '{' && str.at(i) == '}') || (st.top() == '(' && str.at(i) == ')')))
                st.pop();
            else
            {
                flag = false;
                break;
            }
        }

        if (!st.empty()){
            cout << "Does not match"
                 << "\n";
        }//end if
        else{
            if (flag)
                cout << "Match"
                     << "\n";
            else
                cout << "Does not match"
                     << "\n";
        }//end else

    } //end while
}
