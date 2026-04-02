#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

using std::fstream;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

string filename = "C:/Users/hendr/c projects/cpp_projects/Interactive diary thing/book_";
string book = filename + "/book.txt";

void to_add(vector<string> &v,string a){
    v.push_back(a);
    cout << "Done adding '" << a << "' !" << endl;
}

int main(){
    vector<string> diary;
    string input;
    if(std::filesystem::exists(filename)){
        cout << "Found!" << endl;
    }
    else{
        if (std::filesystem::create_directory(filename)){
            cout << "Created folder successfully!: " << filename << endl;
        }
        else{
            cout << "Folder creation error try again" << endl;
            getline(cin, input);
            return 1;
        }
    }
    cout << "Type done or exit to exit..." << endl;
    while (true){
        getline(cin, input);
        if (input == "done" || input == "exit"){
            break;
        }
        else if (input == "check"){
            for (const auto &entry : diary){
                cout << entry << endl;
            }
        }
        else{
            to_add(diary, input);
        }
    }
    cout << "what to name file?" << endl;
    getline(cin, input);
    book = filename + "/" + input + ".txt";
    std::ofstream file(book);
    if (file.is_open()){
        cout << "File opened...";
        for (const auto &e : diary){
            file << e << "\n";
        }
        file.close();
    }
    else{
        cout << "uh oh file not found...";
        getline(cin, input);
        return 1;
    }
    getline(cin, input);
    return 0;
}