#include <iostream>
#include <string>
using namespace std;

int main(){
    string heart = "$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$______$$$$$$\n$$$$______$$___________$$$$\n$$$_____________________$$$\n$$______________________$$$\n$$$_____________________$$$\n$$$____________________$$$$\n$$$$$_________________$$$$$\n$$$$$$$______________$$$$$$\n$$$$$$$$____________$$$$$$$\n$$$$$$$$$_________$$$$$$$$$\n$$$$$$$$$_______$$$$$$$$$$$\n$$$$$$$$$____$$$$$$$$$$$$$$\n$$$$$$$$___$$$$$$$$$$$$$$$$\n$$$$$$$_$$$$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$$$$$$$$$$$$";

    cout << heart << endl;

    cout << endl << "I LOVE YOU MOM! YOU ARE THE BEST MOM IN THE" << endl << endl;

    string world = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣾⣿⣿⣿⣿⣿⡿⠒⠚⠒⠛⣲⣶⠆⠀⠠⣶⡦⠀⠀⠿⣷⣦⡀⢠⣤⣼⣦⡤⣄⡀⢀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⢀⣤⡶⠒⢛⡲⠿⣿⣿⢿⡿⢿⣿⣿⣿⣿⣧⣽⣿⠂⣀⣠⣾⣿⡄⠀⢀⣤⣼⣿⣿⣷⣶⡿⠿⠻⣿⡿⠁⠀⠀⠉⠉⠉⠙⠛⠋⠙⠛⠒⢲⠖⠶⣦⣄⠀⠀⠀\n⠀⢏⡭⠶⣴⡏⠀⠀⠙⠚⠉⠀⣶⣿⡿⠻⢿⡏⠘⠷⠾⠟⠉⠙⢿⣿⣿⣾⣿⣷⣿⣿⡉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⠴⣾⢦⣾⠋⠀⠀⠀\n⠁⠀⠀⠀⣿⣧⡤⠤⠤⠄⣦⣀⡀⠛⢁⣠⣤⣿⠆⠀⠀⠀⠀⠀⠘⢿⣯⠿⣟⣯⣉⠀⠑⣤⠀⣤⡤⣆⠈⠉⠓⢦⣤⡤⠔⠯⠠⣔⠀⢌⡉⢷⣞⢳⡇⠀⠀⠀⠀\n⠀⠀⠀⢰⡟⠁⠀⠀⠀⠀⠹⠿⢟⣦⡿⠟⠋⠉⠀⠀⠀⠀⠀⠀⢠⡟⢻⣶⣿⣿⣧⣼⣿⠿⢶⣿⣿⣿⣇⣤⣯⠏⠀⠑⠒⠢⠄⠋⢠⣀⣴⣾⣿⣿⠀⠀⠀⠀⠀\n⠀⠀⠀⠸⣯⡀⣀⠀⠀⠀⠀⣠⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣨⡗⠞⠋⢿⢿⣿⣿⣿⣶⡜⢻⡉⠉⢇⢩⠿⠷⣆⠀⠀⠀⠀⠀⠈⠹⣿⣿⣿⠿⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⣿⣧⠈⢱⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⡿⠡⠀⠀⢸⣄⡀⢁⠈⣻⡄⠈⢻⣶⣼⣯⣤⠀⠈⠻⣷⠸⣄⣀⠀⣠⣿⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠛⢧⣼⣟⡿⣏⠻⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⣯⣡⢰⣈⣷⠋⡐⠈⡉⠀⠀⣿⣄⣄⣾⡿⠉⢿⡄⢠⣾⠿⣷⡟⠻⣿⠉⢿⡆⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⡟⠟⠛⢿⣦⡀⠀⠀⠀⠀⠀⠀⢻⣽⡞⣿⣏⣈⢹⠀⢳⡀⢞⠀⠛⢻⠏⠀⠀⠈⠻⣼⡇⠠⣿⣿⣷⠞⢡⣾⡿⡆⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠣⢀⠒⠉⠛⣽⣶⣄⡀⠀⠀⠀⠀⠉⠛⠉⠻⣿⡶⠏⠉⢹⡟⢁⣴⠛⠀⠀⠀⠀⠀⠈⠃⠀⠙⣿⢿⣾⠋⣿⣤⣷⣦⣤⣤⣀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⡀⣾⣀⠀⠀⠀⠀⠀⢹⠆⠀⠀⠀⠀⠀⠀⠀⢸⡇⠤⣀⣼⣇⢸⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣿⣿⣿⣿⣿⣿⣧⣬⣿⠁⢦\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢳⣬⡏⠱⡄⠀⠀⢀⡿⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⢀⣏⠹⢿⣼⡷⢻⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢁⣤⠟⠋⠙⠿⢿⡀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⡗⠒⣿⡄⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⢰⠤⠓⣾⠗⣧⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠋⠁⠀⠀⠀⠀⠈⢳⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⢸⣴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣦⣤⡼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣀⣤⠤⣤⠀⠀⣠⠞⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⡀⡶⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣷⡾⠃⢀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣟⡇⣠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠋⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣟⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";

    cout << world << endl;
    return 0;
}