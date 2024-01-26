#include <iostream>
#include "field.h"
using namespace std;

int main()
{
	
	field f;
	try {
	f.gen_random_field();
	f.print();
	
		f.update();
		cout << endl;
	

	}
	catch (const out_of_range& e)
	{
		e.what();
	}
	
	
	
}