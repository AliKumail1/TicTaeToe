#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<string>
using namespace std;
void board();
int tossC();
int check_progress(int t,char p1, char p2);

string table[9];

int main(){
	string p1,p2,toss;
	table[0] = "1";
	table[1] = "2";
	table[2] = "3";
	table[3] = "4";
	table[4] = "5";
	table[5] = "6";
	table[6] = "7";
	table[7] = "8";
	table[8] = "9";
	
	srand(time(NULL));
	
	cout << "\t" << "-------TIC TAC TOE - GAME-------" << endl;
	cout << "Enter player 1 name : ";
	getline(cin,p1);
	cout << "Enter player 2 name : ";
	getline(cin,p2);
	cout << "Press T to toss a coin for first turn : ";
	cin >> toss;
	int turn;
	
			if(toss == "t" || toss == "T"){
			turn = tossC();
		}
	
	
	
	if(turn == 1)
		cout << p1 << " won toss and its your turn";
	else
		cout << p2 << " won toss and its your turn";
		
	board();
	int choice = turn,turns=0,checks=0;
	while( checks == 0){
		
		int loc;
		
		if(choice == 1){
			cout << p1 << " Select location number : ";
			cin >> loc;
			while(table[loc-1].at(0) == p2.at(0)){
				cout << "Already chosen! " << endl;
				cout << p1 << " Select again : ";
				cin >> loc;	
			}
			table[loc-1] = p1[0];
			choice++;
			turns++;
		}
		else{
			cout << p2 << " Select location number : ";
			cin >> loc;
			while(table[loc-1].at(0) == p1.at(0)){
				cout << "Already chosen! " << endl;
				cout << p2 << " Select again : ";
				cin >> loc;	
			}
			table[loc-1] = p2[0];
			choice--;
			turns++;
		}
			
		board();
		char pl1 = p1[0];
		char pl2 = p2[0];
		checks = check_progress(turns,pl1,pl2);
	}
	if(checks == 1)
		cout << p1 << " Has Won The Game!!" << endl;
	else if(checks == 2){
		cout << p2 << " Has Won the Game!!";
	}
	else if(checks == 3){
		cout << "DRAW!!!";
	}
}

void board(){
	cout << endl << "     "  << "       " << "|" << "       " << "|" << "       " << endl;
	cout<< "     "    << "       " << "|" << "       " << "|" << "       " << endl;
	cout<< "     "    << "   "<< table[0] <<"   " << "|" << "   "<< table[1] <<"   " << "|" << "   "<< table[2] <<"   " << endl;
	cout<< "     "    << "       " << "|" << "       " << "|" << "       " << endl;
	cout<< "  "    <<"--------------------------------" << endl;
	cout<< "     "    << "       " << "|" << "       " << "|" << "       " << endl;
	cout<< "     "    << "       " << "|" << "       " << "|" << "       " << endl;
	cout<< "     "    << "   "<< table[3] <<"   " << "|" << "   "<< table[4] <<"   " << "|" << "   "<< table[5] <<"   " << endl;
	cout<< "     "    << "       " << "|" << "       " << "|" << "       " << endl;
	cout<< "  "    << "--------------------------------" << endl;
	cout<< "     "    << "       " << "|" << "       " << "|" << "       " << endl;
	cout<< "     "    << "       " << "|" << "       " << "|" << "       " << endl;
	cout<< "     "    << "   "<< table[6] <<"   " << "|" << "   "<< table[7] <<"   " << "|" << "   "<< table[8] <<"   " << endl;
	cout<< "     "    << "       " << "|" << "       " << "|" << "       " << endl;
}
int tossC(){
	int t;
	t = rand() % (2) + 1;
	return t;
}
int check_progress(int t,char p1,char p2){
	if((table[0].at(0) == p1 && table[1].at(0) == p1 && table[2].at(0) == p1) || (table[2].at(0) == p1 && table[5].at(0) == p1 && table[8].at(0) == p1) || (table[8].at(0) == p1 && table[7].at(0) == p1 && table[6].at(0) == p1) || (table[0].at(0) == p1 && table[3].at(0) == p1 && table[6].at(0) == p1 ) || (table[0].at(0) == p1 && table[4].at(0) == p1 && table[8].at(0) == p1) || (table[2].at(0) == p1 && table[4].at(0) == p1 && table[6].at(0) == p1)){
		return 1;		
	}
	else if((table[0].at(0) == p2 && table[1].at(0) == p2 && table[2].at(0) == p2) || (table[2].at(0) == p2 && table[5].at(0) == p2 && table[8].at(0) == p2) || (table[8].at(0) == p2 && table[7].at(0) == p2 && table[6].at(0) == p2) || (table[0].at(0) == p2 && table[3].at(0) == p2 && table[6].at(0) == p2 ) || (table[0].at(0) == p2 && table[4].at(0) == p2 && table[8].at(0) == p2) || (table[2].at(0) == p2 && table[4].at(0) == p2 && table[6].at(0) == p2)){
		return 2;		
	}
	else if(t == 9)
		return 3;	
}






