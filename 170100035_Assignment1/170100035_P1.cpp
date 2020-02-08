#include<bits/stdc++.h>

using namespace std;

struct StudMarks{
    string rno;
    float marks;
};

// Custom comparison function for StudMarks struct
bool compareMarks(StudMarks stu1, StudMarks stu2){
    return (stu1.marks < stu2.marks);
}
// Sorts students in ascending order of marks
void sortStudents(vector<StudMarks>& students){
    sort(students.begin(), students.end(), compareMarks);
}

// To search for index of last student with marks <= queried marks
int binarySearchMarksEnd(vector<StudMarks>& students, int l, int r, float x){
    int req_index = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(students[mid].marks <= x){
            req_index = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return req_index;
}
// To search for index of first student with marks >= queried marks
int binarySearchMarksStart(vector<StudMarks>& students, int l, int r, float x){
    int req_index = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(students[mid].marks >= x){
            req_index = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return req_index;
}

// To return start & end indices of query results
pair<int, int> fetchMarksQuery(vector<StudMarks>& students, float min, float max){
    int min_index = binarySearchMarksStart(students, 0, students.size()-1, min);
    int max_index = binarySearchMarksEnd(students, 0, students.size()-1, max);

    pair<int, int> q_limits = {min_index, max_index};
    return q_limits;
}

int main(int argc, char* argv[]){
    
    int n, q;
    cin>>n;
    vector<StudMarks> students(n);
    for(int i = 0; i < n; i++){
        cin>>students[i].rno>>students[i].marks;
    }
    
    // Sort the students according to marks in ascending order in-place
    sortStudents(students);

    cin>>q;
    float x, y;
    for(int i = 0; i < q; i++){
        cin>>x>>y;
        cout<<x<<" "<<y<<"\n";
        pair<int, int> q_lims = fetchMarksQuery(students, x, y);;

        for (int j = q_lims.second; j >= q_lims.first; j--){
            cout<<students[j].rno<<"\n";
        }
    }
}