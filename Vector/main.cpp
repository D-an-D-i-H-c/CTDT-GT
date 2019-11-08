#include "Vector.h"

void main()
{
	while(1)
	{
		Vector v;
		int key;
		cout << "--------------------------" << endl;
		cout << "Menu vector : " << endl;
		cout << "0. Thoat ra " << endl;
		cout << "1. Nhap vector " << endl;
		cout << "Choose :";
		cin >> key;
		cout << "--------------------------" << endl;
		if (key == 0)
			break;
		else if (key == 1)
		{
			int key1;
			v.Nhap();
			while(1)
			{
				cout << "--------------------------" << endl;
				cout << "Menu vector : " << endl;
				cout << "2. Quay lai menu truoc " << endl;
				cout << "3. Xuat vector " << endl;
				cout << "4. Cong 2 vector " << endl;
				cout << "5. Nhan vector voi 1 so " << endl;
				cout << "Choose :";
				cin >> key1;
				cout << "--------------------------" << endl;
				if (key1 == 2)
					break;
				else if (key1 == 3)
				{
					cout << "Vector : ";
					v.Xuat();
					cout << "--------------------------" << endl;
				}
				else if (key1 == 4)
				{
					Vector temp;
					cout << "Nhap vector de cong : " << endl;
					temp.Nhap();
					Vector KQ = v.Add(temp);
					if (KQ.KTRong()) cout << "Khong the cong !!!" << endl;
					else
					{
						cout << "Vector sau khi cong : " << endl;
						KQ.Xuat();
					}
					cout << "--------------------------" << endl;
				}
				else if (key1 == 5)
				{
					int alpha;
					cout << "Nhap 1 so de nhan : ";
					cin >> alpha;
					cout << endl;
					Vector KQ = v.Multiply(alpha);
					cout << "Vector sau khi nhan : " << endl;
					KQ.Xuat();
					cout << "--------------------------" << endl;
				}
			}
		}
	}

	system("pause");
}