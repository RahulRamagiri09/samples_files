#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <curl/curl.h>

using namespace std;

// Function to handle API data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* userData) {
    userData->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    // Vector Example
    vector<string> names = {"Alice", "Bob", "Charlie"};
    for (const string& name : names) {
        cout << "Name: " << name << endl;
    }

    // Write to a file
    ofstream outfile("output.txt");
    outfile << "Welcome to Advanced C++ Programming!";
    outfile.close();
    cout << "Data written to file." << endl;

    // API Fetching Example (Using libcurl)
    CURL* curl;
    CURLcode res;
    string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/posts/1");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            cout << "Fetched Data: " << readBuffer << endl;
        } else {
            cerr << "CURL Error: " << curl_easy_strerror(res) << endl;
        }
    }
    return 0;
}
