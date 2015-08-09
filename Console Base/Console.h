#include "Includes.h"
using namespace std;

class Console{
private:
	int Return_Int, Text_Color = 7, Background_Color = 0;
	char Return_Char;
	string Return_String;
	HANDLE hConsole;
	void Set_Color();
public:
	void C(string Line);
	void STCS(string Color);
	void STCI(int Color);
	void SBCS(string Color);
	void SBCI(int Color);
	void SCS(string Text, string Background);
	void SCI(int Text, int Background);
	void L(int Lines);
	void D(int Charictars);
	void R(int Charictars, string Line);
	int GI();
	int CI();
	char GC();
	char CC();
	string GS();
	string CS();
	void GCS(int& lines, int& columns);
};

class Menu{
private:
	vector<string> Items;
	int Menu_Type, Selected = 0;
	Console C_Menu;
	string Tital, A = "w", B = "bl", C = "w", D = "g";
	int Run_Menu();
	void Print_Menu();
public:
	string STR_Menu(string tital, vector<string> Options);
	string STR_Menu_From_File(string File);
	void Set_Colors(string a, string b, string c, string d);
};