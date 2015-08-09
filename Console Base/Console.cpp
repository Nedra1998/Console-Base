
#include "Includes.h"
#include "Console.h"
using namespace std;

void Console::Set_Color(){
	int Color = (16 * Background_Color) + Text_Color;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, Color);
}
void Console::C(string Line){
	int spaces = 40, T = Text_Color, B = Background_Color;
	int l, c;
	GCS(l, c);
	spaces = c / 2;
	SCI(0, 0);
	spaces = spaces - (Line.size() / 2);
	for (int a = 0; a < spaces; a++){
		cout << " ";
	}
	SCI(T, B);
	cout << Line << endl;
}
void Console::STCI(int color){
	Text_Color = color;
	Set_Color();
}
void Console::STCS(string color){
	if (color == "db"){
		Text_Color = 1;
	}
	else if (color == "dg"){
		Text_Color = 2;
	}
	else if (color == "dt"){
		Text_Color = 3;
	}
	else if (color == "dr"){
		Text_Color = 4;
	}
	else if (color == "dp"){
		Text_Color = 5;
	}
	else if (color == "dy"){
		Text_Color = 6;
	}
	else if (color == "gr"){
		Text_Color = 7;
	}
	else if (color == "dgr"){
		Text_Color = 8;
	}
	else if (color == "b"){
		Text_Color = 9;
	}
	else if (color == "g"){
		Text_Color = 10;
	}
	else if (color == "t"){
		Text_Color = 11;
	}
	else if (color == "r"){
		Text_Color = 12;
	}
	else if (color == "p"){
		Text_Color = 13;
	}
	else if (color == "y"){
		Text_Color = 14;
	}
	else if (color == "w"){
		Text_Color = 15;
	}
	else if (color == "bl"){
		Text_Color = 0;
	}
	STCI(Text_Color);
}
void Console::SBCI(int color){
	Background_Color = color;
	Set_Color();
}
void Console::SBCS(string color){
	if (color == "db"){
		Background_Color = 1;
	}
	else if (color == "dg"){
		Background_Color = 2;
	}
	else if (color == "dt"){
		Background_Color = 3;
	}
	else if (color == "dr"){
		Background_Color = 4;
	}
	else if (color == "dp"){
		Background_Color = 5;
	}
	else if (color == "dy"){
		Background_Color = 6;
	}
	else if (color == "gr"){
		Background_Color = 7;
	}
	else if (color == "dgr"){
		Background_Color = 8;
	}
	else if (color == "b"){
		Background_Color = 9;
	}
	else if (color == "g"){
		Background_Color = 10;
	}
	else if (color == "t"){
		Background_Color = 11;
	}
	else if (color == "r"){
		Background_Color = 12;
	}
	else if (color == "p"){
		Background_Color = 13;
	}
	else if (color == "y"){
		Background_Color = 14;
	}
	else if (color == "w"){
		Background_Color = 15;
	}
	else if (color == "bl"){
		Background_Color = 0;
	}
	SBCI(Background_Color);
}
void Console::SCI(int Text, int Background){
	STCI(Text);
	SBCI(Background);
}
void Console::SCS(string Text, string Background){
	STCS(Text);
	SBCS(Background);
}
void Console::L(int lines){
	for (int a = 0; a < lines; a++){
		cout << "\n";
	}
}
void Console::D(int Charictars){
	for (int a = 0; a < Charictars; a++){
		cout << "\r";
	}
	for (int a = 0; a < Charictars; a++){
		cout << " ";
	}
	for (int a = 0; a < Charictars; a++){
		cout << "\r";
	}
}
void Console::R(int Charictars, string Line){
	D(Charictars);
	cout << Line;
}
int Console::GI(){
	Return_Int = _getch();
	return(Return_Int);
}
int Console::CI(){
	cin >> Return_Int;
	return(Return_Int);
}
char Console::GC(){
	Return_Char = _getch();
	return(Return_Char);
}
char Console::CC(){
	cin >> Return_Char;
	return(Return_Char);
}
string Console::GS(){
	getline(cin, Return_String);
	return(Return_String);
}
string Console::CS(){
	cin >> Return_String;
	return(Return_String);
}
void Console::GCS(int& lines, int& columns){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
		))
	{
		lines = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
		columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	}
	else lines = columns = 0;
}

void Menu::Print_Menu(){
	int l, c, Lines, Spaces;
	C_Menu.GCS(l, c);
	Lines = l;
	C_Menu.SCS(A, B);
	C_Menu.C(Tital);
	string Line;
	for (int a = 0; a < c - 2; a++){
		Line = Line + "=";
	}
	C_Menu.C(Line);
	Lines = Lines - 3;
	for (unsigned a = 0; a < Items.size(); a++){
		Spaces = c;
		Spaces = Spaces - Items[a].size();
		Spaces = Spaces / 2;
		if (a == Selected){
			Spaces = Spaces - 5;
		}
		for (int b = 0; b < Spaces; b++){
			cout << " ";
		}
		if (a == Selected){
			cout << ">>[";
			C_Menu.SCS(C, D);
			cout << "  ";
		}
		cout << Items[a];
		if (a == Selected){
			cout << "  ";
			C_Menu.SCS(A, B);
			cout << "]<<";
		}
		cout << endl;
		Lines--;
	}
	for (int a = 0; a < Lines; a++){
		cout << endl;
	}
}
int Menu::Run_Menu(){
	bool Open = true, Update = true;
	int Select = 0, Select_Last = 0;
	while (Open == true){
		if (Update == true){
			Print_Menu();
			Update = false;
		}
		Select_Last = Select;
		Select = C_Menu.GI();
		if (Select == 80 && Selected < Items.size() - 1 && Select_Last == 224){
			Update = true;
			Selected++;
		}
		if (Select == 72 && Selected > 0 && Select_Last == 224){
			Update = true;
			Selected--;
		}
		if (Select == 97 && Selected < Items.size() - 1){
			Update = true;
			Selected++;
		}
		if (Select == 113 && Selected > 0){
			Update = true;
			Selected--;
		}
		if (Select == 115 && Selected < Items.size() - 5){
			Update = true;
			Selected = Selected + 5;
		}
		if (Select == 119 && Selected > 0){
			Update = true;
			Selected = Selected - 5;
		}
		if (Select == 100 && Selected < Items.size() - 10){
			Update = true;
			Selected = Selected + 10;
		}
		if (Select == 101 && Selected > 0){
			Update = true;
			Selected = Selected - 10;
		}
		if (Select == 114){
			Update = true;
			Selected = 0;
		}
		if (Select == 102){
			Update = true;
			Selected = Items.size() - 1;
		}
		if (Select == 13){
			return(1);
		}
	}
	return(0);
}
string Menu::STR_Menu(string tital, vector<string> Options){
	Menu_Type = 1;
	Selected = 0;
	Items.clear();
	Tital = tital;
	Items = Options;
	Run_Menu();
	return(Items[Selected]);
}
string Menu::STR_Menu_From_File(string File){
	string Lines;
	Items.clear();
	ifstream Load(File.c_str());
	if (Load.is_open()){
		getline(Load, Tital);
		while (getline(Load, Lines)){
			Items.push_back(Lines);
		}
	}
	Run_Menu();
	return(Items[Selected]);
}
void Menu::Set_Colors(string a, string b, string c, string d){
	A = a;
	B = b;
	C = c;
	D = d;
}