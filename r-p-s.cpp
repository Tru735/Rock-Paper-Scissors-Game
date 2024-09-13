#include <iostream>
#include <ctime>

int w;
int l;
int t;
char playersChoice(){
    char pChoice;
    do{
        std::cout<<"Choose one of the following: \n ";
        std::cout<<"'r' for ROCK \n ";
        std::cout<<"'p' for PAPER \n ";
        std::cout<<"''s' for SCISSORS \n ";
        std::cout<<"''e' to EXIT \n ";
        std::cin>>pChoice;
        return pChoice;
    }while(pChoice!= 'p' && pChoice!= 'r' && pChoice!= 's' && pChoice!='e');
}
char computersChoice(){
    char cChoice;
    srand(time(0));
    int num = rand()%3 +1;
    switch (num)
    {
        case 1:
            cChoice = 'r';
            return cChoice;
        case 2:
            cChoice = 'p';
            return cChoice;
        case 3:
            cChoice = 's';
            return cChoice;    
        default:
            break;
    }
}
void showChoice(char pMove, char cMove){
    std::cout<<"Your move is "<<pMove<<" \n";
    std::cout<<"Computer's move is "<<cMove<<" \n";
}
void compete(char pMove, char cMove ,int &w ,int &l ,int &t){
    switch (pMove){
        case 'r':
            if(cMove=='s'){
                std::cout<<"You WIN!!! \n";
                w+=1;
            }
            else if(cMove=='p'){
                std::cout<<"You LOSE!!! \n";
                l=+1;
            }else if(cMove=='r'){
                std::cout<<"TIE!!! \n";
                t+=1;
            }
            break;
        case 'p':
            if(cMove=='r'){
                std::cout<<"You WIN!!! \n";
                w+=1;
            }
            else if(cMove=='s'){
                std::cout<<"You LOSE!!! \n";
                l+=1;
            }else if(cMove=='p'){
                std::cout<<"TIE!!! \n";
                t+=1;
            }
            break;
        case 's':
            if(cMove=='p'){
                std::cout<<"You WIN!!! \n";
                w+=1;
            }
            else if(cMove=='r'){
                std::cout<<"You LOSE!!! \n";
                l+=1;
            }else if(cMove=='s'){
                std::cout<<"TIE!!! \n";
                t+=1;
            }
            break;
        case 'e':
            std::cout<<"Thank You for playing!! \n";
            break;
    }

}

void score(){
    std::cout<<"WINS: "<<w<<" LOSSES: "<<l<<" TIES: "<<t<<'\n';
}
int main(){
    std::cout<<"******************* \n";
    std::cout<<"ROCK PAPER SCISSORS \n";
    std::cout<<"******************* \n";

    char player;
    char computer;
    do{
    player = playersChoice();
    computer = computersChoice();
        if(player!='e'){
            showChoice(player, computer);
            compete(player, computer,w ,l ,t);
        }else{
            score();
            return 0;
        }
        score();
    }while(player!='e');


}
