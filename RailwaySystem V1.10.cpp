#include<iostream>
#include<ctime>		//used for functions of time library
#include<string>	
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<windows.h>  //for VK_RETURN
using namespace std;

#ifdef _WIN32
#define cls system("cls");
#define br  system("pause");
#endif

#define pricePerKM 3.5

void writeToFile();
bool readFromFile(int);
void start();
void println();
void login();
void loginDesign();
void bill();
void showLocations();
float TempBill();
void bookWithoutAcc();
void StationDisplay();
void setPassDesign();
void PassGenDesign();
void showDesign();

float billAmount;
int count=0;
float totalAfterDisc;
float total;
int pickup,destination;
string date;

class stations{
	public: 
		float dist;
		string name;
		string code;
};

stations station[8];

class Account{
	private:
		int  accNo;
		char name[30];
		int  age;
		char address[100];
		char password[30];
		char mobileNo[15];
		
		void SetPass(){
			int choice;
			bool flag = false;
			char p1[30],p2[30];
			do{
				cout<<"Do you want to set a password or use suggested password?"<<endl
					<<"Press 1. to set password"<<endl<<"Press 2. to use suggested Password"<<endl
					<<"choice : ";
				cin>>choice;
				fflush(stdin);
				if(choice == 1){
					ReEnter:
						setPassDesign();
					cout<<"Enter your password : ";
					cin.getline(p1,sizeof(p1));
					cout<<"Reenter your password : ";
					cin.getline(p2,sizeof(p2));
				
					if(strcmp(p1,p2) != 0){
						cout<<"Passwords do not match. Try again"<<endl;	
						br;cls;
						goto ReEnter;
					}else{
						strcpy(password,p1);
						cout<<"Password Set Successfully"<<endl;
					//	cout<<"Your Password  : "<<password<<endl;
					//	br;
						flag = true;
					}	
						
				}else if(choice == 2){
					PassGenDesign();
					PassGen();
					cout<<"Password    : "<<password<<endl<<endl;;
					flag = true;
					
				}else{
					cout<<"Wrong choice. Please enter a valid choice."<<endl;
					br;
					cls;
				}	
			
			}while(flag == false);
		
		}
		
		string PassGen(){
			char lower[]   = {"abcdefghijklmnopqrstuvwxyz"};
			char upper[]   = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
			char digit[]   = {"0123456789"};
			char special[] = {"!@#&*~"};
			int size = 0;
			string SizeofPassStr;
			int passSize;			
			bool isLower,isUpper,isDigit,isSpecial;
			int errorControl;	
				cout<<"Enter size of password : ";
				cin>>passSize;
				fflush(stdin);	
				if(passSize <= 0){
					cout<<"Error Incorrect size for password"<<endl<<"proceeding with default password size i.e 8"<<endl<<endl;
					passSize = 8;
				}
				fflush(stdin);
			string GeneratedPass;
				RE:	
				cout<<"Do you want your password to have lower case letters ? "<<endl
					<<"Press 1. for Yes ,Press 0 for No"<<endl<<" Choice : ";
				cin>>errorControl;
				if(errorControl == 0 || errorControl == 1){
					isLower = errorControl;
				}else{
					isLower = 0;
				}
				
				cout<<"Do you want your password to have Upper case letters ? "<<endl
					<<"Press 1. for Yes ,Press 0 for No"<<endl<<" Choice : ";
				cin>>errorControl;
				if(errorControl == 0 || errorControl == 1){
					isUpper = errorControl;
				}else{
					isUpper = 0;
				}
				
				cout<<"Do you want your password to consist of numbers ? "<<endl
					<<"Press 1. for Yes ,Press 0 for No"<<endl<<" Choice : ";
				cin>>errorControl;
				if(errorControl == 0 || errorControl == 1){
					isDigit = errorControl;
				}else{
					isDigit = 0;
				}
				
				cout<<"Do you want your password to consist of special symbols ? "<<endl
					<<"Press 1. for Yes ,Press 0 for No"<<endl<<" Choice : ";
				cin>>errorControl;
				if(errorControl == 0 || errorControl == 1){
					isSpecial = errorControl;
				}else{
					isSpecial = 0;
				}
			 
			 	if(isLower)
			 		size++;		//=sizeof(lower);
			 	if(isUpper)
			 		size++;		//=sizeof(upper);
				if(isDigit)
			 		size++;		//=sizeof(digit);	 	
			 	if(isSpecial)
			 		size++;		//=sizeof(special);
			 	if(size == 0){
			 		cout<<"Password cannot be empty, retry"<<endl;
			 		br;cls;
			 		goto RE;
				 }	
	//			char *passContents = new char[size+1];
	//			if(isLower)
	//		 		strcpy(passContents,lower);
	//		 	if(isUpper)
	//		 		strcat(passContents,upper);
	//			if(isDigit)
	//		 		strcat(passContents,digit);
	//		 	if(isSpecial)
	//		 		strcat(passContents,special);
	//		cout<<endl<<endl<<passContents<<endl<<endl<<"YO";				//Present for testing if strings are getting concated or not
				
					PassGenDesign();
					cout<<"Password specifications : "<<endl<<endl;
				    cout<<"Password size         : "<<passSize<<endl;
					if(isLower)
						cout<<"lower case characters : "<<"true"<<endl;
					else
						cout<<"lower case characters : "<<"false"<<endl;
					if(isUpper)
						cout<<"Upper case characters : "<<"true"<<endl;
					else
						cout<<"Upper case characters : "<<"false"<<endl;
					if(isDigit)
						cout<<"Numeric characters    : "<<"true"<<endl;
					else
						cout<<"Numeric characters    : "<<"false"<<endl;
					if(isSpecial)
						cout<<"Special characters    : "<<"true"<<endl;
					else
						cout<<"Special characters    : "<<"false"<<endl;		
					cout<<endl;
					
				cout<<"Generating Password";
				for(int i=0;i<=passSize;){
					int j = rand();
					srand(j);
				//	GeneratedPass[i] = passContents[rand()%sizeof(passContents)];
				//	cout<<GeneratedPass[i];
					
						if(isLower){
							GeneratedPass.push_back(lower[rand()%(sizeof(lower)-1)]);
							i++; 
							takeTime();
							cout<<".";
						}
						srand(time(NULL));	
					
						if(isUpper){
					 		GeneratedPass.push_back(upper[rand()%(sizeof(upper)-1)]);	
							i++;
							takeTime();
							cout<<".";
						}
						srand(time(NULL));
						
						if(isDigit){
							GeneratedPass.push_back(digit[rand()%(sizeof(digit)-1)]);	
							i++;
							takeTime();
							cout<<".";	
						}
						srand(time(NULL));
				
					 	if(isSpecial){
					 		GeneratedPass.push_back(special[rand()%(sizeof(special)-1)]);	
							i++;
							takeTime();
							cout<<".";
						}
					srand(time(NULL));
					
				}
				cout<<endl;
				GeneratedPass.erase(passSize);
		//	cout<<GeneratedPass<<endl;
			//		string temp;
			//	srand(time(NULL));
 				
			//	GeneratedPass = temp;
			//	GeneratedPass.erase(passSize);
		//	cout<<GeneratedPass<<endl;	
			//	cout<<"yo";
			//	cout<<GeneratedPass<<endl;
			//cout<<GeneratedPass<<endl;
				cout<<"Encrypting password";
				for(int i =0;i<3;i++){
					takeTime();
					GeneratedPass = randomizer(GeneratedPass);	
					
				//	cout<<GeneratedPass<<endl;
					cout<<".";
				}	
				cout<<endl;
	//				GeneratedPass.push_back('\0');
	//			cout<<endl<<"Password : "<<GeneratedPass;
		for(int i=0;i<GeneratedPass.size();i++){
			password[i] = GeneratedPass[i];
		}
		if(GeneratedPass.size() >28)
			password[29] = '\0';
		else
		password[GeneratedPass.size()] = '\0';
	
				return GeneratedPass;	 	
		}
		
		string randomizer(string GeneratedPass){
			srand(time(NULL));											// c bade 5-2= 3  2+2 =4 , 4
			
			string temp;	//[GeneratedPass.size()] ;
				for(int i=0;i<GeneratedPass.size();i++){
					int n = i+ rand()%(GeneratedPass.size()-i);
				//	temp.push_back(GeneratedPass[n]);
					temp.push_back(GeneratedPass[n]);
					char t = GeneratedPass[i];
					GeneratedPass[i] = GeneratedPass[n];
					GeneratedPass[n] = t;
				//	cout<<GeneratedPass<<endl;
 				}
 			//	GeneratedPass = temp;
 			//	for(int i=0;i<GeneratedPass.size();i++)
 			//		GeneratedPass[i] = temp[i];
 			return temp;	
		}	
		
		void takeTime(){
			int t = time(NULL)+1;
			while(t>time(NULL));	
		}
		
		
		
		void show(){
			showDesign();
			cout<<"Account No : "<<accNo<<endl
				<<"Name       : "<<name<<endl
				<<"Age        : "<<age<<endl
				<<"Contect No : "<<mobileNo<<endl
				<<"Address    : "<<address<<endl;
		}
		
		
		
	public:

		void putDataForNonCustomers(){
			fflush(stdin);
			cout<<"Enter name      : ";
			cin.getline(name,30);
			fflush(stdin);
			cout<<"Enter Mobile No : ";			
			cin>>mobileNo;
			fflush(stdin);
			cout<<"Enter Age       : ";
			cin>>age;
			fflush(stdin);
			cout<<"Enter Address   : ";
			cin.getline(address,100);
			accNo = 00000000;
			
			
		}

		int getAge(){
			return age;
		}
		string getName(){
			return name;
		}
		int getAccNo(){
			return accNo;
		}
		string getNo(){
		 	return mobileNo;	
		}
		
		string getAddress(){
			return address;
		}
		
		bool checkPass(){
			RePassVerify:
		//	loginDesign();
			char pass_in[30];
			cout<<"Welcome, "<<name<<endl;
			cout<<"Enter your password : ";
			char c;
			int i=0;
			fflush(stdin);
	//		cin.ignore();
			bool flag=1;

			do{
			c = getch();	
			if(c==VK_RETURN){
				flag = 0;
			}
			else{
			pass_in[i] = c;
			cout<<"*";
			i++;	
			}	
			
			}while(flag == 1);
			pass_in[i] = '\0';
		//	cin>>pass_in;
			cout<<endl;
			if(strcmp(password,pass_in) == 0){
				return true;
			}else{
				char ch;
				cout<<"Incorrect Password"<<endl
					<<"Press 1 to retry, Press any key to exit : ";
				ch = getch();
				cout<<ch<<endl;
				//takeTime();
				if(ch == '1'){
					
					cls;
					loginDesign();
					goto RePassVerify;
					
				}
			}
		return false;		
		}
		
		void getData(){
			
			ifstream fin;
			fin.open("Account No. Counter.txt");
			fin>>count;
			accNo = 20210601 + count;
			fin.close();
			count++;
			ofstream fout;
			fout.open("Account No. Counter.txt");
			fout<<count;
			fout.close();
			
			fflush(stdin);
			cout<<"Enter Your Full Name : ";
			//gets(name);
			cin.getline(name,30);
			cout<<"Enter Your age : ";
			cin>>age;
			cout<<"Enter Your Phone no : ";
			cin>>mobileNo;
			fflush(stdin);
			cout<<"Enter your address : ";
			cin.getline(address,sizeof(address));
			cout<<endl;
			fflush(stdin);
			SetPass();	
			
			writeToFile();		
			
			show();	
			cout<<"Password   : "<<password<<endl;
			br;	
		}
		
		void test(){
		//	PassGen();
			SetPass();
			fflush(stdin);
			test();
		}	
		
		int checkAccNo(){
			return accNo;
		}
};

Account a1;

void login(){
	bool flag;
	fflush(stdin);
	cls
	loginDesign();
	int tempAccNo;
	cout<<"Enter your account no. : ";
	cin>>tempAccNo;
	bool AccExist = readFromFile(tempAccNo);
	if(AccExist == true)
	flag = a1.checkPass();
	else{
		cout<<"Invalid account no."<<endl;
		br;
	return;
	}
	if(flag == false)
		return;
	float disc;
	float amount;
	if(flag == true){
		cout<<"Logged in successfully."<<endl;
		br; cls;
		int age = a1.getAge();
		amount = TempBill();	
		total = amount;
		if(age<=18){
			disc = ((rand()%30)+20)/100.0;
		}else if(age>=60){
			disc = ((rand()%30)+20)/100.0;
		}else{
			disc = ((rand()%15)+10)/100.0;
		}
		
		amount = amount * disc;
	}	
		
	//	cout<<total;
		totalAfterDisc = total - amount;	
		fflush(stdin);
		cout<<"Enter date for booking : (DD-MM-YYYY) : ";
		cin>>date;
		//getline(cin,date);
	bill();
}

float TempBill(){
	StationDisplay();
	cout<<"Locations Available : "<<endl;
		showLocations();
		cout<<"Choose Your Pickup Station : ";
		cin>>pickup;																//declare
		cout<<"Choose Your Destination Station : ";
		cin>>destination;
//		cout<<station[pickup-1].dist <<" "<<station[destination-1].dist<<endl;
//		br;
		float total_dist = station[pickup-1].dist + station[destination-1].dist;
	return total_dist;	
	
}

void bill(){
	int billNo;
	time_t timeNow;
	timeNow = time(NULL);
	struct tm t = *localtime(&timeNow);
	
	fstream f("BillNo.txt",ios::in | ios::out);
	f>>billNo;
//	cout<<billNo;
	++billNo;
	f.close();
	ofstream fout;
	fout.open("BillNo.txt");
	fout<<billNo;
	fout.close();

	fout.open("BillTest.txt");
	fout<<"------------------------------------------------------------------------------"<<endl;
	fout<<"                               IT Railway System                              "<<endl;
	fout<<"                     Breaking the barriers with the speed...                  "<<endl;
	fout<<endl;
	fout<<"                                                                   "<<t.tm_mday<<"-"<<setw(2)<<setfill('0')<<t.tm_mon+1<<"-"<<t.tm_year+1900<<endl;
	fout<<"Bill No. "<<setw(3)<<setfill('0')<<billNo+20210600<<"                                                    "
		<<setw(2)<<setfill('0')<<t.tm_hour<<":"<<setw(2)<<setfill('0')<<t.tm_min<<":"<<setw(2)<<setfill('0')<<t.tm_sec<<endl;
	fout<<"------------------------------------------------------------------------------"<<endl<<endl;	
	fout<<"Pick up      : "<<station[pickup-1].name<<endl;	
	fout<<"Destination  : "<<station[destination-1].name<<endl;
	fout<<"Date         : "<<date/*<<"-"<<date[1]<<"-"<<date[2]*/<<endl;	
	fout<<"Account No.  : "<<setw(8)<<setfill('0')<<a1.getAccNo()<<endl;
	fout<<"Name         : "<<a1.getName()<<endl;
	fout<<"Contact No.  : "<<a1.getNo()<<endl;
	fout<<"Address      : "<<a1.getAddress()<<endl;
	fout<<"Amount       : Rs."<<total*pricePerKM<<"/-"<<endl;
	fout<<"Discount     : Rs."<<(total-totalAfterDisc)*pricePerKM<<"/-"<<endl;
	fout<<"Total Bill   : Rs."<<totalAfterDisc*pricePerKM<<"/-"<<endl;
	fout<<endl<<endl;
	fout<<"                                                                 __________  "<<endl;
	fout<<"                                                                    SIGN     "<<endl;
	fout<<"Route : "<<station[pickup-1].code<<"->"<<"NGP"<<"->"<<station[destination-1].code<<endl;
	fout<<"-----------------------------------------------------------------------------"<<endl;
	fout<<"                        Wishing You A Happy Journey!                         "<<endl;
	fout.close();
	
	cls;
	ifstream fin;
	fin.open("BillTest.txt");
	char c;
	while(fin){
		fin.get(c);
		cout<<c;
	}
	fin.close();
	br;
}

void loginDesign(){
	println();
	cout<<"|             Login             |"<<endl;
	println();
}

void AccDesign(){
	cls;
	println();
	cout<<"|     Account Registeration     |"<<endl;
	println();
}

void StationDisplay(){
	println();
	cout<<"|        Select Station         |"<<endl;
	println();	
}

void PassGenDesign(){
	cls;
	println();
	cout<<"|      Password Generation      |"<<endl;
	println();
}

void setPassDesign(){
	cls;
	println();
	cout<<"|          Set Password         |"<<endl;
	println();
}

void detailsDesign(){
	cls;
	println();
	cout<<"|        Account Details        |"<<endl;
	println();
}
void println(){
	cout<<"---------------------------------"<<endl;
}

void ITrailwayDesign(){
	println();
	cout<<"|       IT railway system       |"<<endl;
	println();
}

void showDesign(){
	println();
	cout<<"|        Account Details        |"<<endl;
	println();
}

void registrationDesign(){
	println();
	cout<<"|         Train Booking         |"<<endl;
	println();
}

void start(){
	int choice;
	srand(time(NULL));
	do{
		ITrailwayDesign();
	cout<<"Press 1. To login"<<endl
		<<"Press 2. To create account"<<endl
		<<"Press 3. To make a reservation without logging in"<<endl
		<<"Press 4. To exit"<<endl
		<<"Choice : ";
	cin>>choice;
		
	switch(choice){
		case 1:
								// suggestion, set choice to 4 if needed so that you can exit if you are going to use recursion
				login();
				break;				
		case 2:
				AccDesign();
				a1.getData();	
				break;
		case 3: 
				cls;
				registrationDesign();
				bookWithoutAcc();
				break;
		case 4:
				break;
		default:
				cout<<"Error, enter a valid choice"<<endl;
				br;
				break;		
	}	
	cls;
	}while(choice!=4);
}

void bookWithoutAcc(){
	a1.putDataForNonCustomers();
	cls;
	totalAfterDisc = TempBill();
	total = totalAfterDisc;
	cout<<"Enter date for booking : (DD-MM-YYYY) : ";
		cin>>date;
	bill();
	
}

void writeToFile(){
			ofstream fout("Data.txt",ios::app);
			fout.write((char*) &a1, sizeof(a1));
			cout<<"Data Written to file successfully"<<endl;
			fout.close();
			br;
			cls;
}

void showLocations(){
	for(int i=0;i<8;i++){
		cout<<i+1<<"."<<station[i].name<<endl;
	}
}

bool readFromFile(int tempAccNo){
	bool flag = false;
	ifstream fin;
	fin.open("Data.txt",ios::ate);
	int n = fin.tellg();
	fin.close();
	fin.open("Data.txt");
	
	while(n - fin.tellg() >= sizeof(a1)){
	fin.read((char*) &a1,sizeof(a1));
		if(tempAccNo == a1.checkAccNo()){
			flag = true;
			break;
		}
			
	}
	fin.close();
	return flag;
}

void setStations(){
station[0].name = "Pune";
station[1].name = "Mumbai";
station[2].name = "Delhi";
station[3].name = "Goa";
station[4].name = "Chennai";
station[5].name = "Bangalore";
station[6].name = "Jaipur";
station[7].name = "Nashik";

station[0].dist =711.3;
station[1].dist =835.1;
station[2].dist =1080.2;
station[3].dist =1055.3;
station[4].dist =1125.5;
station[5].dist =1092.3;
station[6].dist =943.8;
station[7].dist =669.7; 

station[0].code = "PNE";
station[1].code = "MUM";
station[2].code = "DEL";
station[3].code = "GOA";
station[4].code = "CHN";
station[5].code = "BAN";
station[6].code = "JAI";
station[7].code = "NAS"; 

}


int main(){
//	a1.test();
	setStations();
	start();
	getch();
return 0;
}

