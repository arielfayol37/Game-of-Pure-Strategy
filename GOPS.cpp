#include<iostream>
#include<string>
#include <stdlib.h>
#include <time.h>
#include <sstream>


using namespace std;


class card{
public:
    string face;
    string symbol;

    void printcard(){
        cout << face << " of " << symbol;
    }

};
card deck[4][13];




void printdeck(){

        for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            deck[i][j].printcard();
            cout<<"\n";
        }
    }
    cout<<"\n";
}
void print_hand(card cards[]){

        for(int j=0;j<13;j++){
            cards[j].printcard();
            cout<<"\n";
    }
}
void shuffle_cards(card cards[]){
    srand(time(0));
    card temp;
    int i;
    for(int j=0;j<13;j++){

        i = rand()%13;
        temp = cards[i];
        cards[i]=cards[j];
        cards[j] = temp;

    }}

card bidding(string* has_bid1, int * has_bid1_counter, card place_holder, card player_1_hand[], int p){
        string bid01;
        int valid_bid1 = 0;
        card bid1 = place_holder;
            cout << "player "<<p<<" should bid" << endl;
            cin >> bid01;

        while(valid_bid1 == 0){
            for(int q=0; q<13;q++){
                if (bid01 == has_bid1[q]){
                    cout<<"player "<< p<< " has already played this card"<<endl;
                    cout << "player "<<p<<" should bid" << endl;
                    cin >> bid01;
                    break;
                }else if(q==12){
                    valid_bid1=1;
                    has_bid1[*has_bid1_counter] = bid01;
                    *has_bid1_counter++;}
            }

            }


            if (bid01 == "A"){bid1 = player_1_hand[0]; player_1_hand[0]=place_holder;}
            if (bid01 == "2"){bid1 = player_1_hand[1]; player_1_hand[1]=place_holder;}
            if (bid01 == "3"){bid1 = player_1_hand[2];player_1_hand[2]=place_holder;}
            if (bid01 == "4"){bid1 = player_1_hand[3];player_1_hand[3]=place_holder;}
            if (bid01 == "5"){bid1 = player_1_hand[4];player_1_hand[4]=place_holder;}
            if (bid01 == "6"){bid1 = player_1_hand[5];player_1_hand[5]=place_holder;}
            if (bid01 == "7"){bid1 = player_1_hand[6];player_1_hand[6]=place_holder;}
            if (bid01 == "8"){bid1 = player_1_hand[7];player_1_hand[7]=place_holder;}
            if (bid01 == "9"){bid1 = player_1_hand[8];player_1_hand[8]=place_holder;}
            if (bid01 == "10"){bid1 = player_1_hand[9];player_1_hand[9]=place_holder;}
            if (bid01 == "J"){bid1 = player_1_hand[10];player_1_hand[10]=place_holder;}
            if (bid01 == "Q"){bid1 = player_1_hand[11];player_1_hand[11]=place_holder;}
            if (bid01 == "K"){bid1 = player_1_hand[12];player_1_hand[12]=place_holder;}
            if(bid1.face != place_holder.face){return bid1;}else{cout<<"Invalid card input.\n";
                     *has_bid1_counter--;has_bid1[*has_bid1_counter] = ")";
            return bidding(has_bid1, has_bid1_counter, place_holder,player_1_hand, p);}

}


void select_from_shuffled(card prizes_covered[], card place_holder, card topmost_card_on_table, card prizes_on_table[]){
    if(prizes_covered[12].face != place_holder.face || prizes_covered[12].symbol != place_holder.symbol){
        for(int o = 0; o < 13; o++){
            if(prizes_covered[o].face != place_holder.face || prizes_covered[o].symbol != place_holder.symbol){
                topmost_card_on_table = prizes_covered[o];
                prizes_covered[o]=place_holder;
                cout << "the card " << topmost_card_on_table.face << " " << topmost_card_on_table.symbol << " is now on the table as topmost prize\n" << endl;
                break;
            }}
            for(int n = 0; n< 13; n++){
                if(prizes_on_table[n].face == place_holder.face && prizes_on_table[n].symbol == place_holder.symbol){
                    prizes_on_table[n] = topmost_card_on_table;
                    break;
                }
            }}
}

int card_to_value(card lol){

            if (lol.face == "A"){ return 1;}
            if (lol.face == "2"){ return 2;}
            if (lol.face == "3"){ return 3;}
            if (lol.face == "4"){ return 4;}
            if (lol.face == "5"){ return 5;}
            if (lol.face == "6"){ return 6;}
            if (lol.face == "7"){ return 7;}
            if (lol.face == "8"){ return 8;}
            if (lol.face == "9"){ return 9;}
            if (lol.face == "10"){ return 10;}
            if (lol.face == "J"){ return 11;}
            if (lol.face == "Q"){ return 12;}
            if (lol.face == "K"){ return 13;}
return 0;



}
class table{
public:
    card player_1_hand[13];
    card player_2_hand[13];
    card player_1_store[13];
    card player_2_store[13];
    card prizes_covered[13];
    card prizes_on_table[13];
    void shuffle_cards(prizes_covered){
    srand(time(0));
    card temp;
    int i;
    for(int j=0;j<13;j++){

        i = rand()%13;
        temp = prizes_covered[i];
        prizes_covered[i]=prizes_covered[j];
        prizes_covered[j] = temp;

    }}

}

int main()
{
    string face[]{"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    string symbol[]{"hearts","diamond","spades","clubs"};
    int i,j,k;
    for(i=0;i<4;i++){
        for(j=0;j<13;j++){
            deck[i][j].face=face[j];
            deck[i][j].symbol=symbol[i];
        }
    }

    srand(time(0));

    int select_prize = rand()%4;
    int discard_suit = rand()%4;
    while(discard_suit == select_prize){
        discard_suit = rand()%4;
    }
    int player_1_cards = rand()%4;
    while(player_1_cards == select_prize || player_1_cards== discard_suit){
        player_1_cards = rand()%4;
    }
    int player_2_cards;
    for(int z=0; z<4; z++){

        if(z!=player_1_cards && z!=discard_suit && z!=select_prize){
            player_2_cards = z;
        }
    }
    card player_1_hand[13];
    card player_2_hand[13];
    card player_1_store[13];
    card player_2_store[13];
    card prizes_covered[13];
    card place_holder;
    place_holder.face = "zero";
    place_holder.symbol="0";
    card bid1;
    card bid2;
    int sum_of_prizes=0;
    string bid01, bid02;
    card prizes_on_table[13];
    for(int l=0; l<13; l++){
        player_1_hand[l] = deck[player_1_cards][l];
        player_2_hand[l] = deck[player_2_cards][l];
        prizes_covered[l] = deck[select_prize][l];
        prizes_on_table[l]=place_holder;
        player_1_store[l]=place_holder;
        player_2_store[l]=place_holder;
        }

        card (*prizesptr)[13] = &prizes_covered;

    //print_hand(prizes_covered);

    //GAME PLAY
    card topmost_card_on_table;


        int draw = 13;
        int counter = 0;
        int selected = 0;
        int bid1_int, bid2_int;
                        select_from_shuffled(prizes_covered, place_holder, topmost_card_on_table, prizes_on_table);
                selected++;
                string has_bid1[13] = {")",")",")",")",")",")",")",")",")",")",")",")",")"};
                string has_bid2[13] = {")",")",")",")",")",")",")",")",")",")",")",")",")"};

                int has_bid1_counter = 0;
                int has_bid2_counter = 0;

        while(selected != 13){

 bid1 = bidding(has_bid1, &has_bid1_counter, place_holder, player_1_hand,1);
 bid2 = bidding(has_bid2, &has_bid2_counter, place_holder, player_2_hand,2);
 bid1_int = card_to_value(bid1);
 bid2_int = card_to_value(bid2);




            cout << " player one has bid " << bid1.face << " " << bid1.symbol << endl;
            cout << " player two has bid " << bid2.face << " " << bid2.symbol << endl;


            while(bid1_int == bid2_int && selected!=13){

                     cout<<"Draw. You will bid again"<<endl;

                     select_from_shuffled(prizes_covered, place_holder, topmost_card_on_table, prizes_on_table);
                     sum_of_prizes = 0;
                              for(int p=0; p<13;p++){
                sum_of_prizes+= card_to_value(prizes_on_table[p]);
       }
                     cout<< "Sum of prizes on table is "<<sum_of_prizes<<endl;
                     selected++;

                             bid1 = bidding(has_bid1, &has_bid1_counter, place_holder, player_1_hand,1);
 bid2 = bidding(has_bid2, &has_bid2_counter, place_holder, player_2_hand,2);
 bid1_int = card_to_value(bid1);
 bid2_int = card_to_value(bid2);

            cout << " Player one has bid " << bid1.face << " " << bid1.symbol << endl;
            cout << " Player two has bid " << bid2.face << " " << bid2.symbol << endl;
            }

            if(bid1_int > bid2_int){
                    sum_of_prizes=0;
                    cout<<"\n Player 1 takes the prizes"<<endl;
                for(int g=0; g<13;g++){
                    if(prizes_on_table[g].face != place_holder.face || prizes_on_table[g].symbol != place_holder.symbol){
                        player_1_store[g] = prizes_on_table[g];

                        }else{for(int h=0;h<13;h++){prizes_on_table[h] = place_holder;} break;}
                }select_from_shuffled(prizes_covered, place_holder, topmost_card_on_table, prizes_on_table);
            selected++;
            }
            if(bid1_int < bid2_int){
                sum_of_prizes=0;
                    cout<<"\n Player 2 takes the prizes"<<endl;
                for(int g=0; g<13;g++){
                    if(prizes_on_table[g].face != place_holder.face || prizes_on_table[g].symbol != place_holder.symbol){
                        player_2_store[g] = prizes_on_table[g];


                    }else{for(int h=0;h<13;h++){prizes_on_table[h] = place_holder;}break;}
                 }select_from_shuffled(prizes_covered, place_holder, topmost_card_on_table, prizes_on_table);selected++;
            }

        }
     int score1=0, score2=0;
    for(int p=0; p<13;p++){
        score1+= card_to_value(player_1_store[p]);
        score2+= card_to_value(player_2_store[p]);}


    if (score1 > score2){
        cout << "Player one wins with a score of " << score1 << endl;
    }else if(score1 < score2){
        cout << "Player two wins with a score of " << score2 << endl;
    }else if(score1 == score2){
        cout << "DRAWWWWWWW" << endl;
    }



    return 0;
}
