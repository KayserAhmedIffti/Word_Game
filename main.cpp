//This program is developed by S M NAHID MAHMUD , NSU, 1835411050 and Kayser Ahmed, NSU, 1620252042



#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <fstream>
#include <algorithm>


using namespace std;
int main()
{   cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << " \t \t \t \t \t WELCOME TO WORD GAME" <<endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "In this game, you can get your word infos whenever, however you want." << endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;



    typedef unordered_map<string,int> occurrences;
    occurrences s1;

//--------------------------------------------------------------------------------------

//Taking user command to open a file.

    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    string s;
    cout << "Which file you are going to open, write it please:  " << endl;
    cin >> s;
    cout <<endl;

    cout << "The file is following here: "<< endl <<endl;

//--------------------------------------------------------------------------------------

//Make sure both the file(we are going to split and the program in the same folder
    ifstream t;
    t.open(s);       //open the input file
    stringstream strStream;
    strStream << t.rdbuf();   //read the file
    string str = strStream.str();//str holds the content of the file //returns a string object with a copy of the current contents of the stream.
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "The raw text: "<<endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout<<endl;
    cout << str << endl;//print out the whole text!!!

    string result1;
    remove_copy_if(str.begin(), str.end(),
                   back_inserter(result1), //Store output
                   ptr_fun<int, int>(&ispunct)
                  );
    string result;
    remove_copy_if(result1.begin(), result1.end(),
                   back_inserter(result), //Store output
                   ptr_fun<int, int>(&isdigit)
                  );

    cout<<endl;
   // cout<<endl;
   // cout << "After removing the punctuation and digits: " <<endl;
   // cout<<endl;
  //  cout<<endl;
  //  cout << result << endl;
    cout<<endl;
//---------------------------------------------------------------------------------------

    istringstream newstream(move(result)); //Empty the current string stored in result, and move it down to a new input stream

//---------------------------------------------------------------------------------------------------------------------------
//creating a vector to store all the substrings.

    vector<string> most; // this will hold all occurrances of the strings with maximum count. each time a new maximum is found we clear the vector and push the new leader in.
    int max_count = 0;
//---------------------------------------------------------------------------------------------------------------
// now simply extract strings until you reach end-of-file.


    while (newstream >> result)
    {
        int tmp = ++s1[result];
        if (tmp == max_count)
        {
            most.push_back(result);
        }
        else if (tmp > max_count)
        {
            max_count = tmp;
           most.clear();
            most.push_back(result);
        }
    }
    cout<<endl;
    // send our map to stdout.
    int a;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "Enter '1' for getting details frequency of every words in your file." <<endl;
    cout << "Enter '2' for getting frequency of your desired word in your file." <<endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "Enter your number: " <<endl;
    cin >> a;
    cout << "-----------------------------------------------------------------------------------" <<endl;
    cout << "-----------------------------------------------------------------------------------" <<endl;


    switch (a)
    {

    case 1 :

        cout<<"The words with the frequency is given below: " <<endl;

        for (occurrences::const_iterator it1 = s1.cbegin(); it1 != s1.cend(); ++it1)
            cout << it1->first << " : " << it1->second << endl;;

        // send the strings with max_count to stdout
        cout << endl << "Maximum Occurrences" << endl;
        for (vector<string>::const_iterator it = most.cbegin(); it != most.cend(); ++it)
            cout << *it << endl;


        break;

    case 2:

        string userinput;
        cout << "Insert your desired word please: " <<endl;
        cin >> userinput;

        unordered_map<string, int>::iterator s2;


// Find the element with key userinput
        s2 = s1.find(userinput);

// Check if element exists in map or not
        if (s2 != s1.end())

        {
            // Element with key userinput found
            cout << userinput << " has been found" << endl;

            // Access the Key from iterator
            string key = s2->first;
            // Access the Value from iterator
            int value = s2->second;

            cout << key << " has been in the file " << value << " times."<< endl;
        }
else {
    cout <<"Your desired word has not found in this file, please try again" <<endl;
}
        break;
    }

    return 0;
}
