#include <iostream>
#include <string>
#include <vector>

using namespace std;

int characterElimination( string &s )
{
	string b_str = s;
	while( true )
	{
		if( b_str.size() == 0 )
		{
			return 0;
		}

		vector<char> a_str;
		char pre = b_str[0];
		int count = 1;
		for( int i = 1; i < b_str.size(); i++ )
		{
			if( b_str[i] == pre )
			{
				count++;
			}
			else
			{
				if( count == 1 )
				{
					a_str.push_back(pre);
				}
				pre = b_str[i];
				count = 1;
			}
		}

		if( count == 1 )
		{
			a_str.push_back(pre);
		}

		if(a_str.size() == b_str.size())
		{
			break;
		}

		b_str = string(a_str.begin(), a_str.end());

	}
	return b_str.size();
}

int main()
{
	int Len; 		// define the number of string
	string str;

	cin >> Len; 	

	while( Len-- )
	{
		cin >> str;
		
		int min = str.size();
	
		for( int i = 0; i < str.size(); i++ )
		{
			for( char ch = 'A'; ch <= 'C'; ch++ )
			{
				string newStr = str.substr(0, i) + ch + str.substr(i);
				int len = characterElimination( newStr );
				if( len < min )
				{
					min = len;
				}
			}
		}
		cout << str.size() + 1 - min << endl;
	}

	return 0;
}
