#include <iostream>
#include <list>
using namespace std;
int player1(list<int> p2answers)
{
	return 1;
	//insert player1 code
}
int player2(list<int> p1answers)
{
	return 0;
	//insert player2 code
}
int playrps(list<int> p2answers, list<int> p1answers)	//rock = 0 paper = 1 scissors = 2
{
	int p1answer = player1(p2answers);
	int p2answer = player2(p1answers);
	p2answers.push_back(p2answer);
	p1answers.push_back(p1answer);
	if (p1answer == p2answer)
	{
		return 0;
	}
	else if (p1answer == 0 && p2answer == 2)
	{
		return 1;
	}
	else if (p1answer == 1 && p2answer == 0)
	{
		return 1;
	}
	else if (p1answer == 2 && p2answer == 1)
	{
		return 1;
	}
	else if (p2answer == 0 && p1answer == 2)
	{
		return 2;
	}
	else if (p2answer == 1 && p1answer == 0)
	{
		return 2;
	}
	else if (p2answer == 2 && p1answer == 1)
	{
		return 2;
	}
}

int main()
{
	int times;	//amount of times rps will be played
	int refreshrate;	//how many plays will happen between rps results being displayed
	int p1count = 0;	//player1 win count
	int p2count = 0;	//player2 win count
	int tiecount = 0;	//tie count
	list<int> p1answers;	//answers thrown by player1 so far
	list<int> p2answers;	//answers thrown by player2 so far
	int wdl;	//win draw or loss to tell what to add the counter too
	cout << "Input the amount of times to play" << endl;
	cin >> times;
	cout << "Input refresh rate" << endl;
	cin >> refreshrate;
	//rps loop begin
	for (int i = 0; i < times; ++i)
	{
		wdl = playrps(p1answers, p2answers);//play rps returns 0 for tie, 1 for p1 win, 2 for p2 win
		if (wdl == 0)
		{
			++tiecount;
		}
		else if (wdl == 1)
		{
			++p1count;
		}
		else if (wdl == 2)
		{
			++p2count;
		}
		if (i% refreshrate == 0)
		{
			cout << "Player 1 has won " << p1count << " times" << endl;
			cout << "Player 2 has won " << p2count << " times" << endl;
			cout << "There has been " << tiecount << " ties" << endl;
		}
	}
	cout << "----FINAL RESULTS----" << endl;
	cout << "Player 1 has won " << p1count << " times" << endl;
	cout << "Player 2 has won " << p2count << " times" << endl;
	cout << "There has been " << tiecount << " ties" << endl;
	return 0;
}