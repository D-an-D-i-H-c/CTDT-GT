#include "Bool.h"
#include "Simple.h"

void main()
{
	Kar temp;
	temp.SetMatrix();
	temp.drawKar();
	cout << endl;
	Simple SimpleKar(temp);
	SimpleKar.Process_Kar();
	cout << endl;
	system("pause");
}