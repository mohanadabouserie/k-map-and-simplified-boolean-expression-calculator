#include<bits/stdc++.h>
using namespace std;

int num_words(string s)
{
int words = 0;
for(int i = 0; i < s.length(); i++)
  {
    if(s[i] == ' ')
    {
      words++;
    }
  }
  return words + 1;
}
//from decimal to binary
void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

string DecimalToBinary_3(int num)
{
    string str;
      while(num){
      if(num & 1) // 1
        str+='1';
      else // 0
        str+='0';
      num>>=1; // Right Shift by 1
    }
    reverseStr(str);
    if(str.length() == 0)
    {
        str = "000";
    }
    else if(str.length() == 1)
    {
        str = "00" + str;
    }
    else if(str.length() == 2)
    {
        str = "0" + str;
    }
    return str;
}

string DecimalToBinary_2(int num)
{
    string str;
      while(num){
      if(num & 1) // 1
        str+='1';
      else // 0
        str+='0';
      num>>=1; // Right Shift by 1
    }
    reverseStr(str);
    if(str.length() == 0)
    {
        str = "00";
    }
    else if(str.length() == 1)
    {
        str = "0" + str;
    }
    return str;
}

bool compare(string a, string b) {
		// checks if two string differ at exactly one location or not
    int count = 0;
    for(int i = 0; i < a.length(); i++) {
        if (a[i]!=b[i])
            count++;
    }

    if(count == 1)
        return true;

    return false;
}

string getDiff(string a, string b) {
		// returns a string that replaces the differ location of two strings with '-'
    for(int i = 0; i < a.length(); i++) {
        if (a[i]!=b[i])
            a[i]='-';
    }

    return a;
}

string binToString(string x){
		// converts binary string to alphabetic variables
    string out = "";
    if(x[0] == '0')
        out = out + "A'";
    if(x[0] == '1')
        out = out + "A";
    if(x[1] == '0')
        out = out + "B'";
    if(x[1] == '1')
        out = out + "B";
    return out;
}

string binToString3(string x){
		// converts binary string to alphabetic variables
    string out = "";
    if(x[0] == '0')
        out = out + "A'";
    if(x[0] == '1')
        out = out + "A";
    if(x[1] == '0')
        out = out + "B'";
    if(x[1] == '1')
        out = out + "B";
    if(x[2] == '0')
        out = out + "C'";
    if(x[2] == '1')
        out = out + "C";
    return out;
}

int main()
{
    //Getting the data of the input file and opening it
    string file;
    cout << "Please enter the file directory: ";
    getline(cin, file);
    int len = file.length();
    for(int i = 0; i < len; i++)
    {
        if(file[i] == '\\')
        {
            file.insert(i + 1, "\\");
            i++;
            len = file.length();
        }
    }
    char file_name[len+1];
    strcpy(file_name, file.c_str());
    if(!freopen(file_name, "r", stdin))
    {
        cout << "Error! The program could not open the input file!";
        exit(1);
    }
    freopen(file_name, "r", stdin);

    //opening the output file in the same directory of the input file
    string path = file.substr(0, file.find_last_of('\\') +1 ) + "out.txt";
    char output[path.length()+1];
    strcpy(output, path.c_str());
    if(!freopen(output, "w", stdout))
    {
        cout << "Error! The program could not open the output file!";
        exit(1);
    }
    freopen(output, "w", stdout);

    //reading the number of test cases
    int test_cases, num_variables;
    cin >> test_cases;

    //checking if the number of test cases is the same as the test cases provided
    int counter = 0;
    string line;
    ifstream check(file_name);
    while(getline(check, line))
        counter++;
    if(test_cases != counter-1)
    {
        cout << "Insufficient data according to the number of test cases provided by the user!";
        exit(1);
    }

    //start looping over the test cases
    freopen(file_name, "r", stdin);
    cin >> test_cases;
    for(int k = 0; k < test_cases; k++)
    {
    //reading the number of variables
    cin >> num_variables;

    //if there are 3 variables
    if(num_variables == 3)
    {
    //reading the minterms
    vector<int> minterms_3;
    int num_min_3;
    int min_3;
    cin >> num_min_3;
    //checking that number of minterms is the same as the minterms provided
    int current_line = 0;
    string line;
    ifstream check(file_name);
    while (!check.eof())
    {
        current_line++;
        getline(check, line);
    if (current_line == k + 2) break;
    }
    if(num_min_3 != num_words(line) - 2)
    {
        cout << "Insufficient data according the number of min-terms specified in trial " + to_string(k+1) + "!";
        exit(1);
    }
    //checking that every minterm is within the right range
    for(int i = 0; i < num_min_3; i++)
    {
        cin >> min_3;
        if(min_3 < 0 || min_3 > 7)
        {
            cout << "There is a min-term out of range in trial " + to_string(k+1) + "!";
            exit(1);
        }
        if(find(minterms_3.begin(),minterms_3.end(), min_3) != minterms_3.end())
        {
            cout << "The min-term " + to_string(min_3) + " is duplicated in trial " + to_string(k+1) +"!";
            exit(1);
        }
        minterms_3.push_back(min_3);
    }

    //printing the 3 variable k-map
    cout << k + 1 << endl;
    cout << "K-map = " << endl;
    int k_map_3[2][4];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {

            k_map_3[i][j] = 0;
        }
    }
    for(int  i = 0; i < minterms_3.size(); i++)
    {
        if(minterms_3[i] == 0)
        {
            k_map_3[0][0] = 1;
        }
        else if(minterms_3[i] == 1)
        {
            k_map_3[0][1] = 1;
        }
        else if(minterms_3[i] == 3)
        {
            k_map_3[0][2] = 1;
        }
        else if(minterms_3[i] == 2)
        {
            k_map_3[0][3] = 1;
        }
        else if(minterms_3[i] == 4)
        {
            k_map_3[1][0] = 1;
        }
        else if(minterms_3[i] == 5)
        {
            k_map_3[1][1] = 1;
        }
        else if(minterms_3[i] == 7)
        {
            k_map_3[1][2] = 1;
        }
        else if(minterms_3[i] == 6)
        {
            k_map_3[1][3] = 1;
        }

    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {

            cout << k_map_3[i][j] << " ";
        }
        cout << endl;
    }

    //getting the simplified expression
    vector<string> minterms_3_b;
    for(int i = 0; i < minterms_3.size(); i++)
    {
        minterms_3_b.push_back(DecimalToBinary_3(minterms_3[i]));
    }

    vector<int> found_terms1;
    vector<int> search_term1;
    vector<int> found_terms2;
    vector<int> search_term2;
    vector<int> found_terms3;
    vector<int> search_term3;
    for(int i = 0; i < minterms_3_b.size(); i++)
    {
        search_term1.push_back(i);
    }
    vector<string> step1;
    for(int i = 0; i < minterms_3_b.size(); i++)
        {
            for(int j = 0; j < minterms_3_b.size(); j++)
            {
                if(compare(minterms_3_b[i], minterms_3_b[j]))
                {
                    string approved  = getDiff(minterms_3_b[i], minterms_3_b[j]);
                    found_terms1.push_back(i);
                    found_terms1.push_back(j);
                    if(find(step1.begin(), step1.end(), approved) == step1.end())
                    {
                       step1.push_back(approved);
                    }
                }
            }
        }
    cout << "F = ";
    if(step1.empty())
    {
    for(int i = 0; i < minterms_3_b.size(); i++)
    {
        cout << binToString3(minterms_3_b[i]);
        if(minterms_3_b.size() - i > 1)
            cout << " + ";
    }
    }
    else if(k_map_3[0][0] && k_map_3[0][1] && k_map_3[0][2] && k_map_3[0][3] && k_map_3[1][0] && k_map_3[1][1] && k_map_3[1][2] && k_map_3[1][3])
    {
        cout << "1";
    }
    else{
    for(int i = 0; i < step1.size(); i++)
    {
        search_term2.push_back(i);
    }
    vector<string> step2;

        for(int i = 0; i < step1.size(); i++)
        {
            for(int j = 0; j < step1.size(); j++)
            {
                if(compare(step1[i], step1[j]))
                {
                    string approved  = getDiff(step1[i], step1[j]);
                    found_terms2.push_back(i);
                    found_terms2.push_back(j);
                    if(find(step2.begin(), step2.end(), approved) == step2.end())
                    {
                        step2.push_back(approved);
                    }
                }
            }
        }

    if(step2.empty())
    {
    for(int i = 0; i < step1.size(); i++)
        {
            cout << binToString3(step1[i]);
            if(step1.size() - i > 1)
                cout << " + ";
        }
    for(int i = 0; i < search_term1.size(); i++)
    {
            if(find(found_terms1.begin(), found_terms1.end(), search_term1[i]) == found_terms1.end())
            {
                cout << " + " << binToString3(minterms_3_b[search_term1[i]]);
            }
    }
    }
    else
    {
        vector<string> step3;

        for(int i = 0; i < step2.size(); i++)
        {
            for(int j = 0; j < step2.size(); j++)
            {
                if(compare(step2[i], step2[j]))
                {
                    string approved  = getDiff(step2[i], step2[j]);
                    found_terms3.push_back(i);
                    found_terms3.push_back(j);
                    if(find(step3.begin(), step3.end(), approved) == step3.end())
                    {
                        step3.push_back(approved);
                    }
                }
            }
        }

    if(step3.empty())
    {
    for(int i = 0; i < step2.size(); i++)
        {
            cout << binToString3(step2[i]);
            if(step2.size() - i > 1)
                cout << " + ";

        }
        for(int i = 0; i < search_term1.size(); i++)
            {
                    if(find(found_terms1.begin(), found_terms1.end(), search_term1[i]) == found_terms1.end())
                    {
                        cout << " + " << binToString3(minterms_3_b[search_term1[i]]);
                    }
            }

        for(int i = 0; i < search_term2.size(); i++)
            {
                    if(find(found_terms2.begin(), found_terms2.end(), search_term2[i]) == found_terms2.end())
                    {
                        cout << " + " << binToString3(step1[search_term2[i]]);
                    }
            }
    }
    else
    {
    for(int i = 0; i < step3.size(); i++)
        {
            cout << binToString3(step3[i]);
            if(step3.size() - i > 1)
                cout << " + ";
        }
        for(int i = 0; i < search_term1.size(); i++)
            {
                    if(find(found_terms1.begin(), found_terms1.end(), search_term1[i]) == found_terms1.end())
                    {
                        cout << " + " << binToString3(minterms_3_b[search_term1[i]]);
                    }
            }

        for(int i = 0; i < search_term2.size(); i++)
            {
                    if(find(found_terms2.begin(), found_terms2.end(), search_term2[i]) == found_terms2.end())
                    {
                        cout << " + " << binToString3(step1[search_term2[i]]);
                    }
            }
        for(int i = 0; i < search_term3.size(); i++)
            {
                    if(find(found_terms3.begin(), found_terms3.end(), search_term3[i]) == found_terms3.end())
                    {
                        cout << " + " << binToString3(step2[search_term3[i]]);
                    }
            }
    }
    }
    }
    }

    //if there are two variables
    if(num_variables == 2)
    {
    //reading the number of minterms
    vector<int> minterms_2;
    int num_min_2;
    int min_2;
    cin >> num_min_2;
    //checking that number of minterms is the same as the minterms provided
    int current_line = 0;
    string line;
    ifstream check(file_name);
    while (!check.eof())
    {
        current_line++;
        getline(check, line);
    if (current_line == k + 2) break;
    }
    if(num_min_2 != num_words(line) - 2)
    {
        cout << "Insufficient data according the number of min-terms specified in trial " + to_string(k+1) + "!";
        exit(1);
    }
    //checking that every minterm is within the right range
    for(int i = 0; i < num_min_2; i++)
    {
        cin >> min_2;
        if(min_2 < 0 || min_2 > 3)
        {
            cout << "There is a min-term out of range in trial " + to_string(k+1) + "!";
            exit(1);
        }
        if(find(minterms_2.begin(),minterms_2.end(), min_2) != minterms_2.end())
        {
            cout << "The min-term " + to_string(min_2) + " is duplicated in trial " + to_string(k+1) +"!";
            exit(1);
        }
        minterms_2.push_back(min_2);
    }

    //printing the 2 variable k-map
    cout << k + 1 << endl;
    cout << "K-map = " << endl;
    int k_map_2[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {

            k_map_2[i][j] = 0;
        }
    }
    for(int  i = 0; i < minterms_2.size(); i++)
    {
        if(minterms_2[i] == 0)
            k_map_2[0][0] = 1;
        else if(minterms_2[i] == 1)
            k_map_2[0][1] = 1;
        else if(minterms_2[i] == 2)
            k_map_2[1][0] = 1;
        else if(minterms_2[i] == 3)
            k_map_2[1][1] = 1;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {

            cout << k_map_2[i][j] << " ";
        }
        cout << endl;
    }

    //getting the simplified expression
    vector<string> minterms_2_b;
    for(int i = 0; i < minterms_2.size(); i++)
    {
        minterms_2_b.push_back(DecimalToBinary_2(minterms_2[i]));
    }


    vector<string> step_1;
    for(int i = 0; i < minterms_2_b.size(); i++)
        {
            for(int j = 0; j < minterms_2_b.size(); j++)
            {
                if(compare(minterms_2_b[i], minterms_2_b[j]))
                {
                    string approved  = getDiff(minterms_2_b[i], minterms_2_b[j]);
                    if(find(step_1.begin(), step_1.end(), approved) == step_1.end())
                    step_1.push_back(approved);

                }
            }
        }
    cout << "F = ";
    if(step_1.empty())
    {
    for(int i = 0; i < minterms_2_b.size(); i++)
    {
        cout << binToString(minterms_2_b[i]);
        if(minterms_2_b.size() - i > 1)
            cout << " + ";
    }
    }

    else if(k_map_2[0][0] && k_map_2[0][1] && k_map_2[1][0] && k_map_2[1][1])
    {
        cout << "1";
    }

    else{
    vector<string> step_2;

        for(int i = 0; i < step_1.size(); i++)
        {
            for(int j = 0; j < step_1.size(); j++)
            {
                if(compare(step_1[i], step_1[j]))
                {
                    string approved  = getDiff(step_1[i], step_1[j]);
                    if(find(step_2.begin(), step_2.end(), approved) == step_2.end())
                    step_2.push_back(approved);
                }
            }
        }
    if(step_2.empty())
    {
    for(int i = 0; i < step_1.size(); i++)
        {
            cout << binToString(step_1[i]);
            if(step_1.size() - i > 1)
                cout << " + ";
        }
    }
    else
    {
    for(int i = 0; i < step_2.size(); i++)
        {
            cout << binToString(step_2[i]);
            if(step_2.size() - i > 1)
                cout << " + ";
        }
    }
    }
    }

    cout << endl << endl;
    }
}
