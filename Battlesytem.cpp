#include<iostream>
using namespace std;

int health = 100; // global variable! all functions can see and use 
string inventory[5] = { "sword", "shield", "potion", " ", " " };

//funtion declartions
void BattleSytem();

int main() {
	int room = 1;
	char input = 'a';
	//for (int i = 0; i < 10; i++)//puts spaces in inventory
		//inventory[i] = " ";

		while (health > 0) {//game loop

			cout << "your inventiory:";
			for (int i = 0; i < 5; i++)//prints the inventory 
				cout << inventory[i] << " ";
			cout << endl;

			switch (room) {
			case 1:
				cout << "you're in room 1! you can go (s)outh" << endl;
				cin >> input;
				if (input == 's')
					room = 2;
				break;
			case 2:
				BattleSytem(); //functions call 
				cout << "you're in room 2! you can go (n)orth" << endl;
				cin >> input;
				if (input == 'n')
					room = 1;
				break;

			}//end switch 

		}//end of game loop 
}// end of main 

void BattleSytem() {
	cout << "Batlle commencing!" << endl;
	int MonsterHealth = 50;
	char input;

	while (health >= 0 && MonsterHealth > 0) {
		if (inventory[1] == "shield") {
			cout << "the mosnter bites you for 5 hp" << endl;
			health -= 5;
		}
		else {
			cout << "the monster bites you for 10 hp" << endl;
			health -= 10;
		}
		//player attacks!
		if (inventory[0] == "sword") {
			cout << "you hit the Monster with your sword monster for 30 hp" << endl;
			MonsterHealth -= 30;
		}
		else {
			cout << "you punch the monster for 3 damage" << endl;
			MonsterHealth -= 3;
		}
		
		cout << "your health : " << health << ". Monster health:" << MonsterHealth << endl;
		system("pause");

		if (health > 0 && MonsterHealth > 0) {
			cout << "you can (f)ight,  (r)un, or use (p)otion" << endl;
			cin >> input;
			if (input == 'r') {
				int num = rand() % 100;
				if (num < 40) {
					cout << "you escape the battle!" << endl;
					break;
				}
				else
					cout << "chance to run failed :(" << endl;
			}
			if (input == 'p') {
				if (inventory[2] == "potion") {
					cout << "glug glug" << endl;
					health += 35;
					inventory[2] = " ";
				}
				else
					cout << "sorry, you don't have any more potion." << endl;
			}
			if (input == 'f') cout << "the batt;e continues..." << endl;


		}
	}//end of battle loop


}// end of function 
