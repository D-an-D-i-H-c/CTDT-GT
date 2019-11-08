#include"Matrix.h"
int main()
{
	cout << "\n+ DANH SACH THAO TAC:\n";
	cout << "0|Ket thuc phien lam viec:\n1| Dinh thuc:\n2| Nghich dao\n3| Tich 2 ma tran\n4| Hang cua ma tran\n5| Tim nghiem he phuong trinh\n";
	cout << "-----------------------------------------------------------";
	while (1)
	{
		int choose = 0;
		cout << "\n+ Chon thao tac ma ban muon thuc hien (0->5): ";
		cin >> choose;
		cout << endl;
		if (choose == 0) break;
		if (choose == 1)
		{
			int n;
			double a[MAX][MAX];
			cout << "NHAP MA TRAN BAN MUON TIM DINH THUC:\n";
			do{
				cout << "Nhap kich thuoc ma tran n= ";
				cin >> n;
				if (n < 0) cout<<"Nhap sai, vui long nhap lai(n>=0)!!!\n ";
			} while (n < 0);
			Input(a, n, n);
			cout << "Dinh thuc cua ma tran= " << determinant(a, n);
		}
		if (choose == 2)
		{
			int n;
			double a[MAX][MAX], b[MAX][MAX];
			cout << "NHAP MA TRAN BAN MUON TIM NGHICH DAO:\n";
			do {
				cout << "Nhap kich thuoc ma tran n= ";
				cin >> n;
				if (n < 0) cout << "Nhap sai, vui long nhap lai(n>=0)!!!\n ";
			} while (n < 0);
			Input(a, n, n);
			if (determinant(a, n) != 0)
			{
				inverse(a, n, b);
				cout << "\nMa tran nghich dao cua ma tran da nhap:";
				Output(b, n, n);
			}
			else cout << "Khong ton tai ma tran nghich dao cua a";
		}
		if (choose == 3)
		{
			int m, n, p;
			double a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
			do {
				cout << "Nhap so dong ma tran a : ";
				cin >> m;
				cout << "Nhap so cot ma tran a(cung la so dong ma tran b) : ";
				cin >> n;
				cout << "Nhap so cot ma tran b : ";
				cin >> p;
				if (m < 0||n<0||p<0) cout << "\nNhap sai, vui long nhap lai(so dong, so cot>=0)!!!\n ";
			} while (m < 0||n<0||p<0);
			cout << "\nNhap cac gia tri ma tran a:\n";
			Input(a, m, n);
			cout << "\nNhap cac gia tri ma tran b: \n";
			Input(b, n, p);
			Tich(a, b, c, m, n, p);
			cout << "Tich cua 2 ma tran a, b la: ";
			Output(c, m, p);
		}
		if (choose == 4)
		{
			int m, n;
			double a[MAX][MAX];
			cout << "NHAP MA TRAN DE TIM HANG: ";
			do {
				cout << "Nhap so dong ma tran: ";
				cin >> m;
				cout << "Nhap so cot ma tran: ";
				cin >> n;
				if (m < 0 || n < 0 ) cout << "\nNhap sai, vui long nhap lai(so dong, so cot>=0)!!!\n ";
			} while (m < 0 || n < 0 );
			Input(a, m, n);
			cout << "\n\nHang cua ma tran la: "<< Rank(a, m, n);
		}
		if (choose == 5)
		{
			int m, n, t = 1;
			double a[MAX][MAX], b[MAX][MAX];
			cout << "NHAP HE PHUONG TRINH DE TIM NGHIEM: ";
			do {
				cout << "\nNhap so luong phuong trinh: ";
				cin >> m;
				cout << "Nhap so luong bien: ";
				cin >> n;
				if (m < 0 || n < 0) cout << "\nNhap sai, vui long nhap lai(so dong, so cot>=0)!!!\n ";
			} while (m < 0 || n < 0);
			cout << "Nhap he so cho tung bien:\n";
			Input(a, m, n);
			cout << "Nhap lan luot ket qua tung phuong trinh:\n";
			Input(b, m, t);
			cout << "\nHe phuong trinh co dang:\n";
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (j != n - 1) cout << a[i][j] << "*X" << j + 1 << "\t+\t";
					else cout << a[i][j] << "*X" << j + 1 << "    =    " << b[i][0];
				}
				cout << endl;
			}
			Solve(a, b, m, n);
		}
		cout << "\n------------------------------------------------";
	}

	system("pause");
	return 0;
}