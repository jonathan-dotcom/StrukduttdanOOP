#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Character {
    string name;
    int level;
    int health;
    int mana;
    int attack;
    int magic;
    int defense;
    int experience;
    int stamina;
    int agility;

    Character(const string& n, int l, int hp, int mp, int atk, int mgi, int def, int exp, int st, int agl)
        : name(n), level(l), health(hp), mana(mp), attack(atk), magic(mgi), defense(def), experience(exp), stamina(st), agility(agl) {
    }
};

void displayCharacter(const Character& character) {
    cout << "Name: " << character.name << "\n";
    cout << "Level: " << character.level << "\n";
    cout << "Health: " << character.health << "\n";
    cout << "Mana: " << character.mana << "\n";
    cout << "Attack: " << character.attack << "\n";
    cout << "Magic: " << character.magic << "\n";
    cout << "Defense: " << character.defense << "\n";
    cout << "Experience: " << character.experience << "\n";
    cout << "Stamina: " << character.stamina << "\n";
    cout << "Agility: " << character.agility << "\n";
    cout << "--------------------------\n";
}

int main() {
    vector<Character> characters;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add a character\n";
        cout << "2. Display all characters\n";
        cout << "3. Erase a character\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: // Menambah data karakter
                {
                    string name;
                    int level, health, mana, attack, magic, defense, experience, stamina, agility;
                    cout << "Enter character name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter character level: ";
                    cin >> level;
                    cout << "Enter character health: ";
                    cin >> health;
                    cout << "Enter character mana: ";
                    cin >> mana;
                    cout << "Enter character attack: ";
                    cin >> attack;
                    cout << "Enter character magic: ";
                    cin >> magic;
                    cout << "Enter character defense: ";
                    cin >> defense;
                    cout << "Enter character experience: ";
                    cin >> experience;
                    cout << "Enter character stamina: ";
                    cin >> stamina;
                    cout << "Enter character agility: ";
                    cin >> agility;
                    characters.emplace_back(name, level, health, mana, attack, magic, defense, experience, stamina, agility);
                    cout << "Character added successfully!\n";
                }
                break;
            case 2: // Memunculkan karakter
                cout << "All Characters:\n";
                for (const Character& character : characters) {
                    displayCharacter(character);
                }
                break;
            case 3: // MEnghapus karakter
                if (!characters.empty()) {
                    int index;
                    cout << "Enter the index of the character to erase: ";
                    cin >> index;
                    if (index >= 0 && index < characters.size()) {
                        characters.erase(characters.begin() + index);
                        cout << "Character erased successfully!\n";
                    } else {
                        cout << "Invalid index!\n";
                    }
                } else {
                    cout << "No characters to erase!\n";
                }
                break;
            case 4: // Exit
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}
