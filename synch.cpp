#include<iostream>
#include<thread>
#include<mutex>
#include<fstream>
#include<string>

using namespace std;

//to create and write to file uncomment mtx
//mutex mtx; 

void printChars(string fileName)
{
	//mtx.lock();

	fstream file;
	file.open(fileName, fstream::app);
	for (int line = 0; line < 20; line++)
	{
		for (char ch = 'A'; ch <= 'Z'; ch++)
		{
			file << static_cast<char>(ch) << " ";
		}
		file << endl;
	}
	file.close();
	//mtx.unlock();
}
void printNums(string fileName)
{
	//mtx.lock();

	fstream fs;
	fs.open(fileName, fstream::app);

	for (int line = 0; line < 20; line++)
	{
		for (int n = 1; n <= 26; n++)
		{
			fs << n << " ";
		}
		fs << endl;
	}
	fs.close();
	//mtx.unlock();
}


int main()
{
	ofstream file("synch.txt");

	thread thrA(printChars, "synch.txt");
	thread thrB(printNums, "synch.txt");

	thrA.join();
	thrB.join();

	system("pause");
	return 0;
}
