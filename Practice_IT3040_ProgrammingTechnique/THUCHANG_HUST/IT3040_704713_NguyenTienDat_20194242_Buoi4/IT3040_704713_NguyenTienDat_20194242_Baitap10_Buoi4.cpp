#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, q;
vector< vector<string> > txt;
vector< vector<string> > query;

map< pair<string, int>, int > f; // so lan xuat hien pair (tu t trong vb thu d) 
vector<int> max_f; // so lan xuat hien nhieu nhau cua tu trong vb thu d
map< string, int > df;// so van ban chua tu t
map< pair<string, int>, double > score; // diem cua tu t trong van ban thu d la kieu double


vector<string> split(const string &p) {
    vector<string> res;
    stringstream ss(p);

    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        res.push_back(substr);
    }
    return res;
}

void in(const vector<string> &p) {
    for (auto &it : p) {
        cout << it << " ";
    }
}

void input() {
    string enter;
    cin >> n;
    getline(cin, enter); // cin.ignore()
    for (int i = 0; i < n; i++) {
        string tmp;
        getline(cin, tmp);
        txt.push_back(split(tmp));
    }
    cin >> q;
    getline(cin, enter); // cin.ignore()
    for (int i = 0; i < q; i++) {
        string tmp;
        getline(cin, tmp);
        query.push_back(split(tmp));
    }
}

// tinh so lan xuat hien cua tu t trong van ban d
int fCal(string t, int d) {
    if (f.find({t, d}) != f.end())  // tuc la {t,d} ton tai trong f 
        return f[{t,d}]; // f.find({t,d})->second;
    
    // else
    int count = 0;
    for (unsigned int i = 0; i < txt[d].size(); i++) {
        if (!t.compare(txt[d][i])) {
            count++;
        }
    }
    f.insert({{t, d}, count});
    return count;
}

// tinh so lan lap lai nhieu nhat trong van ban d
void max_fCal() {
    for (int i = 0; i < n; i++) {
        map<string, int> mini_dict;
        int maxf = 0;
        // cal mini_dict
        for (unsigned int j = 0; j < txt[i].size(); j++) {
            // neu da ton tai trong mini_dict
            auto it = mini_dict.find(txt[i][j]);
            if (it != mini_dict.end()) {
                it->second++;
            }
            else {
                mini_dict.insert({txt[i][j], 1});
            }
        }

        for (auto it : mini_dict) {
            maxf = max(maxf, it.second);
        }
        max_f.push_back(maxf);  
    }
}

// tinh so van ban chua tu t
int dfCal(string t) {
    // neu tu t da co trong df r
    if (df.find(t) != df.end()) {
        return df[t]; // df.find(t)->second;
    }
    // else
    int count = 0;
    for (auto it : txt) {
        vector<string>::iterator it_element = find(it.begin(), it.end(), t);
        if (it_element != it.end()) count++;
    }
    df.insert({t, count});
    return count;
}

bool check(string t, int d) {
    return (txt[d].end() != find(txt[d].begin(), txt[d].end(), t));
}

double scoreCal(string t, int d) {
    if (score.find({t,d}) != score.end()) return score[{t,d}];
    // else
    double score_res = 0;
    if (check(t,d)) {
        int f_cal = fCal(t,d);
        int max = max_f[d];
        int df_cal = dfCal(t);

        double TF = 0.5 + 0.5 * ((double)f_cal / max); //cout << "TF: " << TF << endl;
        double IDF = log2((double)n / df_cal); //cout << "IDF: " << IDF << endl;
        score_res = TF * IDF;
    }
    score.insert({{t,d}, score_res});
    
    return score_res;
}

int searchResult(vector<string> query) {
    int res = 0;
    double max_score = 0;
    for (int i = 0; i < n; i++) {
        double score = 0;
        for (unsigned int j = 0; j < query.size(); j++) {
            score += scoreCal(query[j], i);
        }

        if (max_score < score) {
            max_score = score;
            res = i;
        }
    }
    return res + 1;
}

int main() {
	cout << "Ho ten: Nguyen Tien Dat\n" << "MSSV: 20194242\n";
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    // tinh maxf
    max_fCal();
    for (int i = 0; i < q; i++) 
        cout << searchResult(query[i]) << endl;
    return 0;
}


// c2 toi uu thoi gian hon
// #include<bits/stdc++.h>
// using namespace std;

// int n, q;
// vector< vector<string> > vector_train;
// vector< vector<string> > vector_test;
// vector<int> f_max; // tan suat xuat hien tu xuat hien nhieu nhat trong van ban i
// map<string, int> df; // tinh xem tu word nam trong bao nhieu van ban
// map<pair<string, int>, int> fe; // tinh xem tu word xuat hien bao nhieu lan trong van ban i <word, i> = int

// // split string
// vector<string> split_string(string str){
//     vector<string> vt;

//     while (!str.empty()){
//         string tmp = str.substr(0, str.find(","));
//         int pos = tmp.find(" ");

//         if(pos > tmp.size())
//             vt.push_back(tmp);
//         else {
//             while(pos <= tmp.size()){
//                 tmp.erase(pos,1);
//                 pos = tmp.find(" ");
//             }
//             vt.push_back(tmp);
//         }
//         if (str.find(",") > str.size()){
//             break;
//         } else {
//             str.erase(0, str.find(",") + 1);
//         }
//     }

//     return vt;
// }

// // input
// void input(){
//     vector<string> document_train;
//     vector<string> document_test;

//     cin >> n;
//     string str_tmp;
//     getline(cin, str_tmp);

//     for(int i=0; i<n; i++){
//         string str_tmp;
//         getline(cin, str_tmp);
//         document_train.push_back(str_tmp);
//     }

//     cin >> q;
//     getline(cin, str_tmp);
//     for(int i=0; i<q; i++){
//         string str_tmp;
//         getline(cin, str_tmp);
//         document_test.push_back(str_tmp);
//     }

//     for(string v : document_train){
//         vector<string> element = split_string(v);

//         vector_train.push_back(element);
//     }

//     for(string v : document_test){
//         vector<string> element = split_string(v);

//         vector_test.push_back(element);
//     }
// }

// // preprocessing
// void pre_processing(){
//     // tinh tan suat tu xuat hien nhieu nhat trong van ban i
//     for(vector<string> str_tmp : vector_train){
//         map<string, int> m;

//         // thiet lap tu dien mini m voi chi so : [sotu] [tansuatxuathien]
//         int max_f = 0;
//         for(string word_tmp : str_tmp){
//             map<string, int>::iterator ite = m.find(word_tmp);
//             if(ite == m.end()){ // neu tu nay chua co trong tu dien mini
//                 m.insert({word_tmp, 1});
//             } else {
//                 ite->second += 1;
//             }

//             max_f = max(m[word_tmp], max_f);
//         }
//         f_max.push_back(max_f);
//     }
// }

// // tinh xem word xuat hien bao nhieu lan trong van ban i
// int frequence_word_int_document_i(string word, int i){
//     if(fe.find({word, i}) != fe.end()){ // neu da co trong kho luu tru thi lay ra va tra ve
//         return fe[{word, i}];
//     }

//     int index = 0;
//     vector<string> str_tmp = vector_train[i];

//     for(string v : str_tmp){
//         if(word == v) index++;
//     }

//     fe.insert({{word, i}, index});
//     return index;
// }

// // tinh xem tu word nam trong bao nhieu van ban
// int count_document_contain_word(string word){ // neu da co trong kho luu tru thi lay ket qua va tra ve
//     if(df.find(word) != df.end()){
//         return df[word];
//     }

//     int index = 0;
//     for(vector<string> str_tmp : vector_train){

//         vector<string>::iterator ite = find(str_tmp.begin(), str_tmp.end(), word);
//         if(ite != str_tmp.end()){
//             index++;
//         }
//     }

//     df.insert({word,index});
//     return index;
// }

// // du doan van ban
// int search_engine(vector<string> list_word){
//     double score_max = -1000;
//     int predict_label = -1;
//     for(int i=0; i<n; i++){
//         vector<string> list_word_train_doc = vector_train[i];

//         double score = 0;
//         for(string word : list_word){
//             if(find(list_word_train_doc.begin(), list_word_train_doc.end(), word) == list_word_train_doc.end()){ // tu nay khong xuat hien trong van ban
//                 continue;
//             } else {
//                 int ftd = frequence_word_int_document_i(word, i); 
//                 int dft = count_document_contain_word(word);
//                 int maxfd = f_max[i];

//                 double tf_word = 0.5 + 0.5 * ((double) ftd / maxfd); //cout << "tf: " << tf_word << endl; 
//                 double idf_word = log2((double) n / dft); //cout << "idf:" << idf_word << endl;

//                 score += tf_word * idf_word;
//             }
//         }

//         if(score > score_max) {
//             predict_label = i;
//             score_max = score;
//         }
//     }

//     return predict_label + 1;
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     input();
//     pre_processing();

//     for(int i=0; i<q; i++)
//         cout << search_engine(vector_test[i]) << endl;

//     return 0;
// }
