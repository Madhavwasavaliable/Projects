#include<bits/stdc++.h>
#include<iostream>
#include<unistd.h>
#include <cstdlib>
#include <time.h>

using namespace std;

//character
struct character{

    string name;
    int health;
    int inventory[3];                       
}characterstr;
//weapons
struct axe{
    int damage;
    int weaponHealth;
}vaxe;
struct sword{
    int damage;
    int weaponHealth;
}vsword;
struct bow{
    int damage;
    int weaponHealth;
}vbow;
struct katana{
    int damage;
    int weaponHealth;
}vkatana;
struct shuriken{ 
    int damage;
    int weaponHealth;
}vshuriken;

struct weapon{
     struct axe vaxe;
     struct sword vsword;
     struct bow vbow;
     struct katana vkatana;
     struct shuriken vshuriken;
}weaponstr;


//enemy
struct enemy{
    string enemyName;
    int damage;
    int health;
    int enemyWeaponHealth;
}enemystr;

int  main(){//Variables
    int Level = 0, score = 0, attack[3], enemyAttack[3], finalMoves[6];
    int lower_value = 0, upper_value = 3;
    //stats
    characterstr.health = 25;

    enemystr.enemyName = "Zabuza";
    enemystr.health = 20;
    enemystr.damage = 3;
    enemystr.enemyWeaponHealth = 15;

    weaponstr.vaxe.weaponHealth = 10;
    weaponstr.vaxe.damage = 5;

    weaponstr.vsword.weaponHealth = 10;
    weaponstr.vsword.damage = 5;

    weaponstr.vbow.weaponHealth = 10;
    weaponstr.vbow.damage = 5;

    weaponstr.vkatana.weaponHealth = 10;
    weaponstr.vkatana.damage = 5;

    weaponstr.vshuriken.weaponHealth = 10;
    weaponstr.vshuriken.damage = 5;
    //stats over
    //story
    cout<<"Hello!"<<endl;
    cout<<"Welcome to my game\n";
    sleep(1);

    cout<<"Enter the name of your character : ";
    cin>>characterstr.name;
    cout<<"Hello "<<characterstr.name<<endl;
    sleep(1);

    cout<<characterstr.name<<" you are burdrend with a glorious purpose\n";
    cout<<"You have to defeat as many enemies as possible to win\n";
    cout<<"Difficulty will increase as levels increase"<<"\n\n";
    sleep(3);
    cout<<"Now its time to choose your weapon warrior!\n";
    cout<<"your weapon choices are -- 1-Axe, 2-Sword, 3-Bow, 4-Katana, 5-Shuriken (you can choose 3 weapons) : ";
    for (int i = 0; i < 3; i++)     //making of inventory
    {
        cin>>characterstr.inventory[i];
    }
    cout<<"you have these items in your inventory :\n";
    for (int i = 0; i < 3; i++)
    {
        if (characterstr.inventory[i] == 1)
        {
            cout<<"Axe\n"; 
        }
        if (characterstr.inventory[i] == 2)
        {
            cout<<"Sword\n";
        }
        if (characterstr.inventory[i] == 3)
        {
            cout<<"Bow\n";
        }if (characterstr.inventory[i] == 4)
        {
            cout<<"Katana\n";
        }if (characterstr.inventory[i] == 5)
        {
            cout<<"Shuriken\n";
        }
    }
    //story
    sleep(2);
    cout<<"\nQUICK! QUICK! the enemies are here!! \n";
    cout<<"Let me give you quick overview of combact rules...\n\n"<<"1. You get 3 turns and then enemy get 3 turns\n"<<"2. You can Attack/Doudge/Smash\n";
    cout<<"3. Attack decrease Health by 2 points and decreases your weapons durability by 1\n";
    cout<<"4. Doudge lessens the effect of enemy's attack by 1\n";
    cout<<"5. Smash reduces enemy's health by 50 percentage and also of your weapon\n";
    cout<<"When the enemy dies its weapons durability comes to your weapon\n";
    cout<<"Lastly press 1 for Attack, 2 for Dougde and 3 for Smash\n\n";
    sleep(5);

    cout<<"FIGHT!!!\n\n";       //attacking mechanism starts
    while (enemystr.health > 0 && characterstr.health > 0)
    {   
        cout<<enemystr.health<<"\n";
        cout<<"You are fighting with "<<enemystr.enemyName<<"\n";
        for (int i = 0; i < 3; i++)
        {
            cout<<"Enter your attacks - ";
            cin>>attack[i];
        }
        // This program will create different sequence of random numbers on every program run
        // Use current time as seed for random generator
        srand(time(0));
 
        for (int i = 0; i < 3; i++)
        {                
            enemyAttack[i] = (rand() % (upper_value - lower_value + 1)) + lower_value; //uppervalue = 3 lower value = 0
            cout<<"enemy's attacks - "<<enemyAttack[i]<<"\n";
        }

        for (int k = 0; k < 6; k++)     //storing player's attack in even and enemy's attacks in odd places in an array(finalMoves)
         {
             if (k%2==0){
                 finalMoves[k] = attack[k/2];
                 cout<<"even = "<<finalMoves[k]<<"\n";
             }
             else{
                 finalMoves[k] = enemyAttack[k/2];
                 cout<<"odd = "<<finalMoves[k]<<"\n";
             }
        }
        for (int j = 0; j < 6; j+=2)
        {   //finalmove 1
            if (finalMoves[j] == 1 && finalMoves[j+1] == 0){
                enemystr.health = enemystr.health - 2;
                cout<<characterstr.name<<"'s health is "<<characterstr.health<<"\n"<<enemystr.enemyName<<"'s health is "<<enemystr.health<<"\n";
            }   
            else if (finalMoves[j] == 1 && finalMoves[j+1] == 1){
                enemystr.health = enemystr.health - 2;
                characterstr.health = characterstr.health - 2;
                cout<<characterstr.name<<"'s health is "<<characterstr.health<<"\n"<<enemystr.enemyName<<"'s health is "<<enemystr.health<<"\n";
            }
            else if (finalMoves[j] == 1 && finalMoves[j+1] == 2)
            {
                enemystr.health = enemystr.health - 1;
                cout<<characterstr.name<<"'s health is "<<characterstr.health<<"\n"<<enemystr.enemyName<<"'s health is "<<enemystr.health<<"\n";
            }
            else if (finalMoves[j] == 1 && finalMoves[j+1] == 3)
            {
                enemystr.health = enemystr.health - 2;
                characterstr.health = characterstr.health - characterstr.health / 2;
                cout<<characterstr.name<<"'s health is "<<characterstr.health<<"\n"<<enemystr.enemyName<<"'s health is "<<enemystr.health<<"\n";
            } // finalmove 2 
            else if (finalMoves[j] == 2 && finalMoves[j+1] == 0){
                //nothing will happen
                cout<<characterstr.name<<"'s health is "<<characterstr.health<<"\n"<<enemystr.enemyName<<"'s health is "<<enemystr.health<<"\n";
            }   
            else if (finalMoves[j] == 2 && finalMoves[j+1] == 1){
                characterstr.health = characterstr.health - 1;
                cout<<characterstr.name<<"'s health is "<<characterstr.health<<"\n"<<enemystr.enemyName<<"'s health is "<<enemystr.health<<"\n";
            }
            else if (finalMoves[j] == 2 && finalMoves[j+1] == 2)
            {
                //nothing will happen
                cout<<characterstr.name<<"'s health is "<<characterstr.health<<"\n"<<enemystr.enemyName<<"'s health is "<<enemystr.health<<"\n";
            }
            else if (finalMoves[j] == 2 && finalMoves[j+1] == 3)
            {
                characterstr.health = characterstr.health - (characterstr.health)/2 + 1;
                cout<<characterstr.name<<"'s health is "<<characterstr.health<<"\n"<<enemystr.enemyName<<"'s health is "<<enemystr.health<<"\n";
            } //finalmove 3
            if (finalMoves[j] == 3 && finalMoves[j+1] == 0){
                enemystr.health = enemystr.health - enemystr.health/2;
                cout<<characterstr.name<<"'s health is "<<characterstr.health<<"\n"<<enemystr.enemyName<<"'s health is "<<enemystr.health<<"\n";
            }   
            else if (finalMoves[j] == 3 && finalMoves[j+1] == 1){
                enemystr.health = enemystr.health - enemystr.health/2;
                characterstr.health = characterstr.health - 2;
                cout<<characterstr.name<<"'s health is "<<characterstr.health<<"\n"<<enemystr.enemyName<<"'s health is "<<enemystr.health<<"\n";
            }
            else if (finalMoves[j] == 3 && finalMoves[j+1] == 2)
            {
                enemystr.health = enemystr.health - (enemystr.health)/2 + 1;
                cout<<characterstr.name<<"'s health is "<<characterstr.health<<"\n"<<enemystr.enemyName<<"'s health is "<<enemystr.health<<"\n";
            }
            else if (finalMoves[j] == 3 && finalMoves[j+1] == 3)
            {
                enemystr.health = enemystr.health - enemystr.health/2;;
                characterstr.health = characterstr.health - characterstr.health / 2;
                cout<<characterstr.name<<"'s health is "<<characterstr.health<<"\n"<<enemystr.enemyName<<"'s health is "<<enemystr.health<<"\n";
            }   
        }
    }
}
/*
axe = 1; sword = 2 bow = 3 ..
inventory ={ axe bow sword}
n=0
for(int i=0; i<3; i++){
    if(character.invrntory[i] == 1)
    weaponhealth[n]=weaponhealth.vaxe;
    n++

    else if(character.invrntory[i] == 2)
    weaponhealth[n]=weaponhealth.vsword;
    n++

    else if(character.invrntory[i] == 3)
    weaponhealth[n]=weaponhealth.vbow;
    n++

    else if(character.invrntory[i] == 4)
    weaponhealth[n]=weaponhealth.vkat;
    n++

    else if(character.invrntory[i] == 5)
    weaponhealth[n]=weaponhealth.vshru;
    n++
}
    
*/