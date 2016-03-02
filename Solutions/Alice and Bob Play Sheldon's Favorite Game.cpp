#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int who_wins(string s1,string s2)
{
	if(s1==s2) return 0;
	else if(s1=="Scissors"&&s2=="Paper") return 1;
	else if(s2=="Scissors"&&s1=="Paper") return 2;
	else if(s1=="Paper"&&s2=="Rock") return 1;
	else if(s1=="Rock"&&s2=="Paper") return 2;
	else if(s1=="Rock"&&s2=="Lizard") return 1;
	else if(s1=="Lizard"&&s2=="Rock") return 2;
	else if(s1=="Lizard"&&s2=="Spock") return 1;
	else if(s1=="Spock"&&s2=="Lizard") return 2;
	else if(s1=="Spock"&&s2=="Scissors") return 1;
	else if(s1=="Scissors"&&s2=="Spock") return 2;
	else if(s1=="Scissors"&&s2=="Lizard") return 1;
	else if(s2=="Scissors"&&s1=="Lizard") return 2;
	else if(s1=="Lizard"&&s2=="Paper") return 1;
	else if(s2=="Lizard"&&s1=="Paper") return 2;
	else if(s1=="Paper"&&s2=="Spock") return 1;
	else if(s2=="Paper"&&s1=="Spock") return 2;
	else if(s1=="Spock"&&s2=="Rock") return 1;
	else if(s2=="Spock"&&s1=="Rock") return 2;
	else if(s1=="Rock"&&s2=="Scissors") return 1;
	else return 2;
}

string alice_next_sub(string shape)
{
	if(shape=="Rock") return "Paper";
	else if(shape=="Paper") return "Scissor";
	else if(shape=="Scissor") return "Spock";
	else if(shape=="Lizard") return "Rocks";
	else return "Lizard";
}
string next_move_Alice(int result,string current,string opponent)
{
	if(result==1) return current;
	else if(result==0) return alice_next_sub(current);
	else return alice_next_sub(opponent);
}

string next_move_Bob(string current,int result)
{
	if(current!="Spock") return "Spock";
	else if(result==0) return "Lizard";
	else if(result==2) return "Rock";
	else return "Paper";
}

int main()
{
	int t;		
	cin>>t;
	while(t--)
	{
		int this_turn,n,win_Alice,win_Bob,tie;
		win_Alice=win_Bob=tie=0;
		string s1,s2;
		cin>>s1>>s2>>n;
		while(n--)
		{
			this_turn=who_wins(s1,s2);
			if(this_turn==0) tie++;
			else if(this_turn==1) win_Alice++;
			else if(this_turn==2) win_Bob++;
			s1=next_move_Alice(this_turn,s1,s2);
			s2=next_move_Bob(s2,this_turn);
		}
		if(win_Alice==win_Bob) cout<<"Alice and Bob tie, each winning "<<win_Alice<<" game(s) and tying "<<tie<<" game(s)"<<endl;
		else if(win_Alice>win_Bob) cout<<"Alice  wins, by winning "<<win_Alice<<" game(s) and tying "<<tie<<" game(s)"<<endl;
		else if(win_Bob>win_Alice) cout<<"Bob wins, by winning "<<win_Bob<<" game(s) and tying "<<tie<<" game(s)"<<endl;
	}
	return 0;
}
