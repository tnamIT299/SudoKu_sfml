#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SinhVien
{
private:
    string stuCode,fName,Class;
    int yearOfBirth;
    float avgScore;
public:
    string getStuCode();
    void setStuCode(string code);
    string getFName();
    void setFName(string name);
    int getYearOfBirth();
    void setYearOfBirth(int year);
    string getClass();
    void setClass(string class1);
    float getAvgScore();
    void setAvgScore(float score);

    friend ostream& operator<<(ostream &COUT, SinhVien &s1);
    friend istream& operator>>(istream &CIN, SinhVien &s1);

    bool operator<(SinhVien &s1);
    //void learnAlertList(SinhVien s1);
    SinhVien();
    ~SinhVien();
};
// void SinhVien::learnAlertList(SinhVien s1){
//     if(s1.avgScore<1.0)
//         cout <<s1;
// }


bool SinhVien::operator<(SinhVien &s1){
    return (avgScore<s1.avgScore);
}

void SinhVien::setAvgScore(float score){
    avgScore=score;
}

float SinhVien::getAvgScore(){
    return avgScore;
}

void SinhVien::setClass(string class1){
    Class=class1;
}

string SinhVien::getClass(){
    return Class;
}

void SinhVien::setYearOfBirth(int year){
    yearOfBirth=year;
}

int SinhVien::getYearOfBirth(){
    return yearOfBirth;
}

void SinhVien::setFName(string name){
    fName=name;
}

string SinhVien::getFName(){
    return fName;
}

void SinhVien::setStuCode(string code){
    stuCode=code;
}

string SinhVien::getStuCode(){
    return stuCode;
}

istream& operator>>(istream &CIN, SinhVien &s1){
    cout <<"\nMa sinh vien: ";
    CIN>>s1.stuCode;
    cout <<"\nHo va ten: ";
    CIN>>s1.fName;
    cout <<"\nNam sinh: ";
    CIN>>s1.yearOfBirth;
    cout <<"\nLop: ";
    CIN>>s1.Class;
    cout <<"\nDiem trung binh: ";
    CIN>>s1.avgScore;
    return CIN;
}

ostream& operator<<(ostream &COUT, SinhVien &s1){
    COUT <<"\nMa sinh vien: "<<s1.stuCode;
    COUT <<"\nHo va ten: "<<s1.fName;
    COUT <<"\nNam sinh: "<<s1.yearOfBirth;
    COUT <<"\nLop: "<<s1.Class;
    COUT <<"\nDiem trung binh: "<<s1.avgScore;
    return COUT;
}

SinhVien::SinhVien()
{
}

SinhVien::~SinhVien()
{
}
void sortByAvgScore(int l, int r, vector<SinhVien> &ListSV){
    if (l <= r)
	{
		int key = ListSV[(l+r)/2].getAvgScore();

		int i = l;
		int j = r;

		while (i <= j)
		{
			while (ListSV[i].getAvgScore() > key)
				i++;
			while (ListSV[j].getAvgScore() < key)
				j--;
			if (i <= j)
			{
				swap(ListSV[i], ListSV[j]);
				i++;
				j--;
			}
		}


		if (l < j)
			sortByAvgScore(l, j,ListSV);
		if (r > i)
			sortByAvgScore(i, r,ListSV);
	}
}

void sortByYearOfBirth(vector<SinhVien> &ListSV){
    int temp; 
    for (int i = 0; i < ListSV.size(); i++){
	for (int j = i + 1; j < ListSV.size(); j++){
		if (ListSV[j].getYearOfBirth() > ListSV[j+1].getYearOfBirth()){
                    temp = ListSV[j].getYearOfBirth();
                    ListSV[j].getYearOfBirth() = ListSV[j+1].getYearOfBirth();
                    ListSV[j+1].getYearOfBirth() = temp;
			}
		}
	}

}
void menu(vector<SinhVien>ListSV){
    int choice=0;
    do
    {
        system("cls");
        cout <<"\n===========Menu==========";
        cout <<"\n1.Nhap 1 sinh vien";
        cout <<"\n2.Xuat danh sach sinh vien";
        cout <<"\n3.Sap xep theo diem trung binh";
        cout <<"\n4.Sap xep theo nam sinh";
        cout <<"\n5.Danh sach sinh vien bi canh bao hoc tap";
        cout <<"\n6.Thoat";
        cout <<"\nMoi ban hap lua chon: ";
        cin>>choice;
        if(choice<1&&choice>6)
            continue;
        switch (choice)
        {
        case 1:{
            cout <<"\n\tMoi ban nhap: ";
            SinhVien s1;
            cin>>s1;
            ListSV.push_back(s1);
            break;}
        case 2:{
            cout <<"\n\tDanh sach sinh vien:";
            for(int i=0;i<ListSV.size();i++){
                cout <<"\n\tThong tin sinh vien thu"<<i+1;
                cout <<ListSV[i];
            }    
            break;   
                }
        case 3:{
            sortByAvgScore(0,ListSV.size(),ListSV);
            cout <<"\n\tDanh sach sinh vien:";
            for(int i=0;i<ListSV.size();i++){
                cout <<"\n\tThong tin sinh vien thu"<<i+1;
                cout <<ListSV[i];
            }  
            break;}
        case 4:{
            sortByYearOfBirth(ListSV);
            cout <<"\n\tDanh sach sinh vien:";
            for(int i=0;i<ListSV.size();i++){
                cout <<"\n\tThong tin sinh vien thu"<<i+1;
                cout <<ListSV[i];
            }  
            break;}
        case 5:{
            for (int i = 0; i < ListSV.size(); i++)
            {
                if(ListSV[i].getAvgScore()<1.0)
                cout<<ListSV[i];
            }
            break;
        }
        default:
            break;
        }
        system("pause");
    } while (choice !=6);
    
}
int main(){
    vector<SinhVien> ListSV;
    menu(ListSV);
    return 0;
}