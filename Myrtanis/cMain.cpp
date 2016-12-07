//Benötigte Header
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;
#include "variables.h";

void SetColor(int ForgC)//Credits : UC
{
	///Farben
	//14 = Gelb
	//10 = Grün
	//11 = Cyan
	//12 = Rot
	//13 = Magenta
	//15 = Weiß
	//16 = Schwarz
	//17 = Dunkelblau
	//18 = Dunkelgrün
	//20 = Dunkelrot
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}

void Beeper()
{
	Beep(704, 750);
	Beep(792, 250);
	Beep(880, 500);
	Beep(792, 500);
	Beep(940, 500);
	Beep(880, 500);
	Beep(792, 250);
	Beep(660, 250);
	Beep(704, 500);
	Beep(1188, 500);
	Beep(1056, 500);
	Beep(940, 500);
	Beep(880, 500);
	Beep(792, 500);
	Beep(880, 250);
	Beep(704, 250);
	Beep(1056, 1000);
	Beep(704, 750);
	Beep(792, 250);
	Beep(880, 500);
	Beep(792, 500);
	Beep(940, 500);
	Beep(880, 500);
	Beep(792, 250);
	Beep(660, 250);
	Beep(704, 500);
	Beep(1188, 500);
	Beep(1056, 500);
	Beep(940, 500);
	Beep(880, 500);
	Beep(792, 500);
	Beep(880, 250);
	Beep(704, 250);
	Beep(1056, 1000);
	Beep(792, 500);
	Beep(880, 500);
	Beep(792, 250);
	Beep(660, 250);
	Beep(528, 500);
	Beep(940, 500);
	Beep(880, 500);
	Beep(792, 250);
	Beep(660, 250);
	Beep(528, 500);
	Beep(1056, 500);
	Beep(940, 500);
	Beep(880, 750);
	Beep(880, 250);
	Beep(990, 500);
	Beep(940, 250);
	Beep(1056, 250);
	Beep(1056, 1000);
	Beep(1408, 750);
	Beep(1320, 250);
	Beep(1320, 250);
	Beep(1188, 250);
	Beep(1056, 500);
	Beep(1188, 750);
	Beep(1056, 250);
	Beep(1056, 250);
	Beep(940, 250);
	Beep(880, 500);
	Beep(792, 750);
	Beep(880, 125);
	Beep(940, 125);
	Beep(1056, 250);
	Beep(1188, 250);
	Beep(940, 250);
	Beep(792, 250);
	Beep(704, 500);
	Beep(880, 250);
	Beep(792, 250);
	Beep(704, 1000);
	Beep(1408, 750);
	Beep(1320, 250);
	Beep(1320, 250);
	Beep(1188, 250);
	Beep(1056, 500);
	Beep(1188, 750);
	Beep(1056, 250);
	Beep(1056, 250);
	Beep(940, 250);
	Beep(880, 500);
	Beep(792, 750);
	Beep(880, 125);
	Beep(940, 125);
	Beep(1056, 250);
	Beep(1188, 250);
	Beep(940, 250);
	Beep(792, 250);
	Beep(704, 500);
	Beep(880, 250);
	Beep(792, 250);
	Beep(704, 1000);
}

void savegame()
{
	//Datei erstellen
	std::ofstream outfile(savegame_path);
	//
	cout << "Speichere.." << endl;
	//Konvertieren
	LPCSTR player_name_lpcstr = const_cast<char *>(player_name.c_str());
	LPCSTR player_race_lpcstr = const_cast<char *>(player_race.c_str());
	LPCSTR player_position_lpcstr = const_cast<char *>(player_position.c_str());
	LPCSTR player_position_map_lpcstr = const_cast<char *>(player_position_map.c_str());
	LPCSTR savegame_path_lpcstr = const_cast<char *>(savegame_path.c_str());
	//Speichern
	WritePrivateProfileStringA("PlayerVariables", "PlayerName", player_name_lpcstr, savegame_path_lpcstr);
	WritePrivateProfileStringA("PlayerVariables", "PlayerRace", player_race_lpcstr, savegame_path_lpcstr);
	WritePrivateProfileStringA("PlayerVariables", "PlayerPosition", player_position_lpcstr, savegame_path_lpcstr);
	WritePrivateProfileStringA("PlayerVariables", "PlayerPositionMap", player_position_map_lpcstr, savegame_path_lpcstr);
	//Fertig
	cout << "Speichern erfolgreich !" << endl;
}

void loadgame()
{
	//Buffer initialisieren
	char player_name_buffer[100];
	char player_race_buffer[100];
	char player_position_map_buffer[100];
	char player_position_buffer[100];
	//Konvertieren
	LPCSTR savegame_path_lpcstr = const_cast<char *>(savegame_path.c_str());
	//Laden
	GetPrivateProfileStringA("PlayerVariables", "PlayerName", "maurice", player_name_buffer, 100, savegame_path_lpcstr);
	GetPrivateProfileStringA("PlayerVariables", "PlayerRace", "Ork", player_race_buffer, 100, savegame_path_lpcstr);
	GetPrivateProfileStringA("PlayerVariables", "PlayerPosition", "room01", player_position_buffer, 100, savegame_path_lpcstr);
	GetPrivateProfileStringA("PlayerVariables", "PlayerPositionMap", "map01", player_position_map_buffer, 100, savegame_path_lpcstr);
	//Geladenes zuweisen
	player_name = player_name_buffer;
	player_race = player_race_buffer;
	player_position = player_position_buffer;
	player_position_map = player_position_map_buffer;
}

void clearScreen()
{
	system("cls");
}

void logo()
{
	cout << ".##...##..##..##..#####...######...####...##..##..######...####.." << endl;
	cout << ".###.###...####...##..##....##....##..##..###.##....##....##....." << endl;
	cout << ".##.#.##....##....#####.....##....######..##.###....##.....####.." << endl;
	cout << ".##...##....##....##..##....##....##..##..##..##....##........##." << endl;
	cout << ".##...##....##....##..##....##....##..##..##..##..######...####.." << endl;
	cout << "................................................................." << endl;
	cout << "................................................................." << endl;
	cout << "................................................................." << endl;
}

void about()
{
	clearScreen();
	SetColor(15);
	system("TITLE - Myrtanis - C++ Recode - EARLY ALPHA -");
	logo();
	cout << "- Thank you for playing this game. It is my very first C++ game so please dont judge too hard :-)" << endl;
	cout << "- I want to thank Splamy for all of his help with my coding questions, " << endl;
	cout << "SANiK who brought me to coding back in the days," << endl;
	cout << "the stackoverflow people" << endl;
	cout << "XOXO <3" << endl;
	Beeper();
	cin.get();
}

void whoami()
{
	SetColor(12);
	cout << "playername = "  + player_name << endl;
	cout << "Volk = " + player_race << endl;
	cout << "Wo bist du = " + player_position << endl;
	if (player_hasItem_key01)
	{
		cout << "Keys = TRUE" + player_hasItem_key01 << endl;
	}
	else if (!player_hasItem_key01)
	{ 
		cout << "Keys = FALSE" + player_hasItem_key01 << endl;
	}
}

void checkforfreerooms()
{
	if (player_position == "room01")
	{
		north_isfree = true;
		south_isfree = true;
		east_isfree = true;
		west_isfree = false;
	}
	else if (player_position == "room02")
	{
		north_isfree = false;
		south_isfree = false;
		east_isfree = false;
		west_isfree = true;
	}
	else if (player_position == "room03")
	{
		north_isfree = false;
		south_isfree = true;
		east_isfree = false;
		west_isfree = true;
	}
	else if (player_position == "room04")
	{
		north_isfree = false;
		south_isfree = false;
		east_isfree = true;
		west_isfree = false;
	}
	else if (player_position == "room05")
	{
		north_isfree = true;
		south_isfree = true;
		east_isfree = false;
		west_isfree = false;
	}
	else if (player_position == "room06")
	{
		north_isfree = true;
		south_isfree = false;
		east_isfree = true;
		west_isfree = false;
	}
	else if (player_position == "room07")
	{
		north_isfree = false;
		south_isfree = false;
		east_isfree = true;
		west_isfree = true;
	}
}

void go_south()
{
	checkforfreerooms();
	if (south_isfree)
	{
		cout << "Du gehst nach S" << ue << "den .." << endl;
		if (player_position == "room01")
		{
			player_position = "room05";
		}
		else if (player_position == "room05")
		{
			player_position = "room06";
		}
		else if (player_position == "room03")
		{
			player_position = "room01";
		}
	}
	else if (!south_isfree)
	{
		cout << "Dieser Weg ist versperrt!" << endl;
	}
}

void go_west()
{
	checkforfreerooms();
	if (west_isfree)
	{
		cout << "Du gehst nach Westen .." << endl;
		if (player_position == "room03")
		{
			player_position = "room04";
		}
		else if (player_position == "room02")
		{
			player_position = "room01";
		}
		else if (player_position == "room07")
		{
			player_position = "room06";
		}
	}
	else if (!west_isfree)
	{
		cout << "Dieser Weg ist versperrt!" << endl;
	}
}

void go_east()
{
	checkforfreerooms();
	if (east_isfree)
	{
		cout << "Du gehst nach Osten .." << endl;
		if (player_position == "room01")
		{
			player_position = "room02";
		}
		else if (player_position == "room04")
		{
			player_position = "room03";
		}
		else if (player_position == "room06")
		{
			player_position = "room07";
		}
	}
	else if (!east_isfree)
	{
		cout << "Dieser Weg ist versperrt!" << endl;
	}
}

void go_north()
{
	checkforfreerooms();
	if (north_isfree)
	{
		cout << "Du gehst nach Norden .." << endl;
		if (player_position == "room01")
		{
			cout << "Du siehst eine T" << ue << "r. Du ben" << oe << "tigst einen Schl" << ue << "ssel!" << endl;
			player_position = "room03";
		}
		else if (player_position == "room05")
		{
			player_position = "room01";
		}
		else if (player_position == "room06")
		{
			player_position = "room05";
		}
	}
	else if (!north_isfree)
	{
		cout << "Dieser Weg ist versperrt!" << endl;
	}
}

void lookforitem()
{
	SetColor(15);
	cout << "Du durchsucht den Raum nach Items..  " << endl;

	if (player_position == "room02" && !player_hasItem_key01)
	{
		SetColor(13);
		cout << "Du findest einen Schl" << ue << "ssel!  " << endl;
		player_hasItem_key01 = true;
		Beep(704, 250);
		Beep(792, 250);
		Beep(880, 250);
		Beep(792, 250);
	}
	else
	{	
		SetColor(12);
		cout << "Hier ist nichts.. Schade... " << endl;
	}
}

void countgametime()
{
	
}

void helpme()
{
	SetColor(14);
	cout << "Die folgenden Kommandos sind verf"<< ue << "gbar :" << endl;
	cout << "- hilfe (Zeigt dir diesen Text.. Unglaublich oder?)" << endl;
	cout << "- gehe nach x (Der Spieler geht in Richtung X , wobei X norden s"<< ue << "den westen oder osten heissen kann)" << endl;
	cout << "- whoami (Zeigt im Debugmode Spielername und Volk an)" << endl;
	cout << "- save (Speichert das Spiel. Sehr hilfreich.)" << endl;
	cout << "- load (L"<< ae << "dt das letzte gesicherte Spiel. Super oder ?)" << endl;
	cout << "- suche (Sucht den Raum nach items ab, welche zuf" << ae << "lligerweise auf dem Boden liegen.)" << endl;
	cout << "- clear (L"<< oe << "scht das Fenster. Zauberei! )" << endl;
	cout << "- exit (Beendet das Spiel , und wirft den Spieler auf das Hauptmenu zur"<< ue << "ck. Keine Angst, das tut nicht weh!)" << endl;
}

void whereami()
{
	SetColor(12);
	cout << "Du befindest dich hier :  " + player_position << endl;
}

void open_readme()
{
	string line;
	ifstream myfile("ReadMe.txt");
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, line);
			cout << line;
		}
		myfile.close();
	}

	else wcout << "Unable to open file";
}

void useitem()
{
	if (player_hasItem_key01 && player_position == "room02")
	{
		cout << "Du benutzt den Schl" << ue << "ssel.." << endl;
		cout << "Die T" << ue << "r schwenkt quiteschend auf.."  << endl;
	}
}

void engine()
{
	clearScreen();
	while (true)
	{
		if (player_alive)
		{
			SetColor(15);
			cout << "Was willst du tun : " << endl;
		}
		SetColor(13);
		getline(cin, input);
		if (input == "flammkuchen")
		{
			global_debugmode = true;
			SetColor(12);
			cout << "---> DEBUG MODE ENABLED! <---" << endl;
		}
		else if(input == "beep")
		{
			Beeper();
		}
		else if(input == "bye" || "close" || "exit")//If by OR others
		{
			exit(0);
		}
		else if (input == "readme")//Öffne die Readme Datei
		{
			open_readme();
		}
		else if (input == "gehe nach norden")//Norden
		{
			go_north();
		}
		else if (input == "gehe nach osten")//Osten
		{
			go_east();
		}
		else if (input == "gehe nach westen")//Westen
		{
			go_west();
		}
		else if (input == "gehe nach süden")//Süden
		{
			go_south();
		}
		else if (input == "gehe nach oben")//oben
		{
			go_north();
		}
		else if (input == "gehe nach rechts")//rechts
		{
			go_east();
		}
		else if (input == "gehe nach links")//links
		{
			go_west();
		}
		else if (input == "gehe nach unten")//unten
		{
			go_south();
		}
		else if (input == "n")//Norden
		{
			go_north();
		}
		else if (input == "o")//Osten
		{
			go_east();
		}
		else if (input == "w")//Westen
		{
			go_west();
		}
		else if (input == "s")//Süden
		{
			go_south();
		}
		else if (input == "save")//Speichern
		{
			savegame();
		}
		else if (input == "load")//laden
		{
			loadgame();
		}
		else if (input == "?")//Wo befindet sich der Spieler
		{
			whereami();
		}
		else if (input == "wo bin ich")//Wo befindet sich der Spieler
		{
			whereami();
		}
		else if (input == "exit")
		{
			//system("close");
		}
		else if (input == "hilfe")//Zeigt den Hilfetext
		{
			helpme();
		}
		else if (input == "whoami" && global_debugmode)//Info über playername usw
		{
			whoami();
		}
		else if (input == "clear")//Löscht die Konsole
		{
			clearScreen();
		}
		else if (input == "about")//Zeigt das Logo und die credits. Ebenfalls die deutsche nationalhyme.
		{
			about();
		}
		else if (input == "suche")//Suche nach item
		{
			lookforitem();
		}
		else if (input == "benutze")//Benutzen
		{
			useitem();
		}
		else//Wenn das eingegebene Kommando nicht existiert
		{
			SetColor(12);
			cout << "Ehm, was haben Sie gesagt mein Herr? Tippe hilfe ein um eine Liste der m"<< oe << "glichen Kommandos einzusehen! " << endl;
		}
	}
}

void check_player_name()
{
	if (player_name == "")
	{
		
	}
}

void check_player_race()
{
	if (player_race == "Ork")
	{
		event_player_race_valid = true;
	}
	else if (player_race == "Mensch")
	{
		event_player_race_valid = true;
	}
	else if (player_race == "Elf")
	{
		event_player_race_valid = true;
	}
	else
	{
		event_player_race_valid = false;
	}
}

void ask_race()
{
	SetColor(14);
	cout << "Als n"<< ae <<"chstes sage mir bitte welchem Volk du entstammst ?" << endl;
	cout << "Also entweder ""Mensch"" , ""Elf"" oder ""Ork"" " << endl;
	cout << "Und achte auf deine Rechtschreibung!! " << endl;
	SetColor(13);
	getline(cin, player_race);
	check_player_race();
	if (event_player_race_valid)
	{
		SetColor(14);
		cout << "Ein " + player_race + " also .. Soso .. " << endl;
		cout << "Du scheinst sehr entschlossen zu sein, " + player_name + "!" << endl;
		cout << "Ich w" << ue << "nsche dir alles gute auf deiner Reise!" << endl;
		event_finishedCreation = true;
		player_alive = true;
		engine();
	}
	else if (!event_player_race_valid)
	{
		SetColor(12);
		cout << "Ohje , so ein Volk kenne ich garnicht.. Versuchen wir es noch einmal ja ?" << endl;
		//clearScreen();
		ask_race();
	}
}

void ask_name()
{
	SetColor(14);
	cout << "Willkommen in der Welt von Myrtanis." << endl;
	cout << "Bitte verrate mir deinen Namen !" << endl;
	SetColor(13);
	getline(cin, player_name);
	SetColor(14);
	cout << "Ahh , " + player_name + " ist ein wahrlich passender Name!" << endl;
	ask_race();
}

void howtostart()
{
	cout << "Spiel laden oder von vorne?" << endl;
	cout << "F" << ue << "r ein neues Spiel tippe neu ein." << endl;
	cout << "Um deinen Spielstand zu laden, tippe laden ein." << endl;
	while (true)
	{ 
		getline(cin, input);
		if (input == "neu")
		{
			cout << "Neues Spiel!" << endl;
			player_alive = true;
			ask_name();
		}
		else if (input == "laden")
		{
			cout << "Spiel laden..." << endl;
			player_alive = true;
			loadgame();
			engine();
		}
		else
		{
			cout << "ERROR" << endl;
		}
	}
}

void init()//Initialisiere das Spiel
{
	SetColor(15);
	system("TITLE - Myrtanis - C++ Recode - EARLY ALPHA -");
	logo();
	cout << "\n" << endl;
	cout << "ENTER zum starten..." << endl;
	cin.get();
	clearScreen();
	howtostart();
}

void main()//Hauptfunktion
{
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, 600, 500, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	if (!event_finishedCreation)
	{ 
		init();
	}
	else if (event_finishedCreation)
	{
		engine();
	}
}