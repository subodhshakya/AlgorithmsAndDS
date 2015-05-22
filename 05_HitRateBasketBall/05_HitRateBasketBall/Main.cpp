/*
Q05> 
Basket ball hit rates The hit rate of the basketball game is given by the number of hits divided by the number of chances. 
For example, you have 73 chances but hit 15 times, then your hit rate is 15/73=0.205 (keep the last 3 digits). 
On average, you have 4.5 chances in each basketball game. Assume the total number of games is 162. Write a function for a 
basketball player. He will input the number of hits he has made, the number of chances he had, and the number of remaining 
games. The function should return the number of future hits, so that he can refresh his hit rate to 0.45
*/

#include<iostream>
using namespace std;

int GetFutureHits(int numberOfHitsMade, int numberOfChances, int numberOfRemGames)
{
	float hitRate = 0.45;
	float currentRate = (float)numberOfHitsMade / (float)numberOfChances;
	int totalNumberOfGame = 162;
	int totalRemChances = 4.5 * numberOfRemGames;

	/*
	(HitsMade + HitsInFuture)/(NumberOfChances + RemainingChances) = 0.45;
	HitsInFuture = 0.45*(NumberOfChances + RemainingChances) - HitsMade;
	*/
	int HitsInFuture = 0.45*(numberOfChances + totalRemChances) - numberOfHitsMade;
	return HitsInFuture;
}

int main()
{
	int hitsMade, numberOfChances, numberOfGamesPlayed;
	cout << "Enter Number of hits made:";
	cin >> hitsMade;
	cout << "Enter Number of Chances:";
	cin >> numberOfChances;
	cout << "Enter Number of GamesPlayed:";
	cin >> numberOfGamesPlayed;
	cout << "\nHits remaining:" << GetFutureHits(hitsMade, numberOfChances, 162 - numberOfGamesPlayed)<<endl;
}