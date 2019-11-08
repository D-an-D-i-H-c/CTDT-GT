#include "Bool.h"

Kar::Kar()
{
	// Duyệt qua bảng 4x4 , các phần tử đặt bằng 0
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			this->Matrix[i][j] = 0;
}
void Kar::SetMatrix()
{
	// Khai báo biến
	string temp;
	// Yêu cầu người dùng nhập vào đa thức
	cout << "Cac da thuc gom cac chu cai : x,y,z,t voi ( X la phu dinh cua x ) . Cac da thuc lien ket voi nhau boi dau +" << endl;
	cout << "Moi nhap cac da thuc : ";
	fflush(stdin);
	getline(cin, temp); 
	// Xử lí đa thức đưa vào bảng Kar
	this->Solve(temp);
}
void Kar::drawKar()
{
	// Duyệt qua các phẩn tử trong bảng Kar
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			// In ra giá trị các phần tử
			cout << this->Matrix[i][j] << " ";
		cout << endl;
	}
}
void Kar::Solve(string temp)
{
	int i = 0;
	while (true)
	{
		int j = -1,start=0,end=0;// start , end là 2 biến chỉ điểm đầu và điểm cuối của 1 đa thức
		do
		{
			// Ta tách các đa thức được cách nhau bởi dấu " + " , rồi xử lí từng phần tử đưa vào bảng
			j++;
			// Ta duyệt qua các phần tử
			// Nếu gặp dấu + hoặc cuối phần tử thì xử lí tách chuỗi
			if (temp[j] == '+' || temp[j] == NULL)
			{
				string test;
				// Khi gặp điều kiện dừng thì end bằng vị trí dừng đó
				end = j;
				// với biến test , ta dùng để lưu từng đa thức
				test = temp.substr(start, end-start);
				// sau khi lưu ta đặt lại start bằng vị trí kế 
				start = j + 1;
				// ta xử lí đưa vào bảng Kar bằng hàm SolveString
				this->SolveString(test);
			}
		} while (temp[j] != NULL);
		// Khi mà cuối chuỗi thì sau khi xử lí xong ,ta dừng
		if (temp[j] == NULL) break;
	}
}
void Kar::SolveString(string temp)
{
	// Ta xét độ dài và xét từng trường hợp của nó
	if (temp.length() == 4) // Xét trường hợp đa thức có 4 biến
	{
		// Ta xét tất cả các trường hợp , từ đó chuyển dữ liệu vào bảng Kar
		if (temp == "xyzt")
			this->Matrix[0][0] = 1;
		if (temp == "xYzt")
			this->Matrix[0][1] = 1;
		if (temp == "XYzt")
			this->Matrix[0][2] = 1;
		if (temp == "Xyzt")
			this->Matrix[0][3] = 1;
		if (temp == "xyzT")
			this->Matrix[1][0] = 1;
		if (temp == "xYzT")
			this->Matrix[1][1] = 1;
		if (temp == "XYzT")
			this->Matrix[1][2] = 1;
		if (temp == "XyzT")
			this->Matrix[1][3] = 1;
		if (temp == "xyZT")
			this->Matrix[2][0] = 1;
		if (temp == "xYZT")
			this->Matrix[2][1] = 1;
		if (temp == "XYZT")
			this->Matrix[2][2] = 1;
		if (temp == "XyZT")
			this->Matrix[2][3] = 1;
		if (temp == "xyZt")
			this->Matrix[3][0] = 1;
		if (temp == "xYZt")
			this->Matrix[3][1] = 1;
		if (temp == "XYZt")
			this->Matrix[3][2] = 1;
		if (temp == "XyZt")
			this->Matrix[3][3] = 1;
	}
	if (temp.length() == 3)
	{
		if (temp == "xzt")
		{
			this->Matrix[0][0] = 1;
			this->Matrix[0][1] = 1;
		}
		if (temp == "Xzt")
		{
			this->Matrix[0][2] = 1;
			this->Matrix[0][3] = 1;
		}
		if (temp == "xzT")
		{
			this->Matrix[1][0] = 1;
			this->Matrix[1][1] = 1;
		}
		if (temp == "XzT")
		{
			this->Matrix[1][2] = 1;
			this->Matrix[1][3] = 1;
		}
		if (temp == "xZT")
		{
			this->Matrix[2][0] = 1;
			this->Matrix[2][1] = 1;
		}
		if (temp == "XZT")
		{
			this->Matrix[2][2] = 1;
			this->Matrix[2][3] = 1;
		}
		if (temp == "xZt")
		{
			this->Matrix[3][0] = 1;
			this->Matrix[3][1] = 1;
		}
		if (temp == "XZt")
		{
			this->Matrix[3][2] = 1;
			this->Matrix[3][3] = 1;
		}
		if (temp == "xyt")
		{
			this->Matrix[0][0] = 1;
			this->Matrix[3][0] = 1;
		}
		if (temp == "xyT")
		{
			this->Matrix[1][0] = 1;
			this->Matrix[2][0] = 1;
		}
		if (temp == "xYt")
		{
			this->Matrix[0][1] = 1;
			this->Matrix[3][1] = 1;
		}
		if (temp == "xYT")
		{
			this->Matrix[1][1] = 1;
			this->Matrix[2][1] = 1;
		}
		if (temp == "XYt")
		{
			this->Matrix[0][2] = 1;
			this->Matrix[3][2] = 1;
		}
		if (temp == "XYT")
		{
			this->Matrix[1][2] = 1;
			this->Matrix[2][2] = 1;
		}
		if (temp == "Xyt")
		{
			this->Matrix[0][3] = 1;
			this->Matrix[3][3] = 1;
		}
		if (temp == "XyT")
		{
			this->Matrix[1][3] = 1;
			this->Matrix[2][3] = 1;
		}
		if (temp == "xyz")
		{
			this->Matrix[0][0] = 1;
			this->Matrix[1][0] = 1;
		}
		if (temp == "xyZ")
		{
			this->Matrix[2][0] = 1;
			this->Matrix[3][0] = 1;
		}
		if (temp == "xYz")
		{
			this->Matrix[0][1] = 1;
			this->Matrix[1][1] = 1;
		}
		if (temp == "xYZ")
		{
			this->Matrix[2][1] = 1;
			this->Matrix[3][1] = 1;
		}
		if (temp == "XYz")
		{
			this->Matrix[0][2] = 1;
			this->Matrix[1][2] = 1;
		}
		if (temp == "XYZ")
		{
			this->Matrix[2][2] = 1;
			this->Matrix[3][2] = 1;
		}
		if (temp == "Xyz")
		{
			this->Matrix[0][3] = 1;
			this->Matrix[1][3] = 1;
		}
		if (temp == "XyZ")
		{
			this->Matrix[2][3] = 1;
			this->Matrix[3][3] = 1;
		}
		if (temp == "yzt")
		{
			this->Matrix[0][0] = 1;
			this->Matrix[0][3] = 1;
		}
		if (temp == "Yzt")
		{
			this->Matrix[0][1] = 1;
			this->Matrix[0][2] = 1;
		}
		if (temp == "yzT")
		{
			this->Matrix[1][0] = 1;
			this->Matrix[1][3] = 1;
		}
		if (temp == "YzT")
		{
			this->Matrix[1][1] = 1;
			this->Matrix[1][2] = 1;
		}
		if (temp == "yZT")
		{
			this->Matrix[2][0] = 1;
			this->Matrix[2][3] = 1;
		}
		if (temp == "YZT")
		{
			this->Matrix[2][1] = 1;
			this->Matrix[2][2] = 1;
		}
		if (temp == "yZt")
		{
			this->Matrix[3][0] = 1;
			this->Matrix[3][3] = 1;
		}
		if (temp == "YZt")
		{
			this->Matrix[3][1] = 1;
			this->Matrix[3][2] = 1;
		}
	}
	if (temp.length() == 2)
	{
		if (temp == "xy")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[i][0] = 1;
		}
		if (temp == "xY")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[i][1] = 1;
		}
		if (temp == "XY")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[i][2] = 1;
		}
		if (temp == "Xy")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[i][3] = 1;
		}
		if (temp == "zt")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[0][i] = 1;
		}
		if (temp == "zT")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[1][i] = 1;
		}
		if (temp == "ZT")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[2][i] = 1;
		}
		if (temp == "Zt")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[3][i] = 1;
		}
		if (temp == "xz")
		{
			this->Matrix[0][0] = this->Matrix[0][1] = this->Matrix[1][0] = this->Matrix[1][1] = 1;
		}
		if (temp == "Xz")
		{
			this->Matrix[0][2] = this->Matrix[0][3] = this->Matrix[1][2] = this->Matrix[1][3] = 1;
		}
		if (temp == "xZ")
		{
			this->Matrix[2][0] = this->Matrix[3][0] = this->Matrix[2][1] = this->Matrix[3][1] = 1;
		}
		if (temp == "XZ")
		{
			this->Matrix[2][2] = this->Matrix[2][3] = this->Matrix[3][2] = this->Matrix[3][3] = 1;
		}
		if (temp == "yt")
		{
			this->Matrix[0][0] = this->Matrix[0][3] = this->Matrix[3][0] = this->Matrix[3][3] = 1;
		}
		if (temp == "Yt")
		{
			this->Matrix[0][1] = this->Matrix[0][2] = this->Matrix[3][1] = this->Matrix[3][2] = 1;
		}
		if (temp == "YT")
		{
			this->Matrix[1][1] = this->Matrix[1][2] = this->Matrix[2][1] = this->Matrix[2][2] = 1;
		}
		if (temp == "yT")
		{
			this->Matrix[1][0] = this->Matrix[2][0] = this->Matrix[1][3] = this->Matrix[2][3] = 1;
		}
		if (temp == "xt")
		{
			this->Matrix[0][0] = this->Matrix[0][1] = this->Matrix[3][0] = this->Matrix[3][1] = 1;
		}
		if (temp == "Xt")
		{
			this->Matrix[0][2] = this->Matrix[0][3] = this->Matrix[3][2] = this->Matrix[3][3] = 1;
		}
		if (temp == "XT")
		{
			this->Matrix[1][2] = this->Matrix[1][3] = this->Matrix[2][2] = this->Matrix[2][3] = 1;	
		}
		if (temp == "xT")
		{
			this->Matrix[1][0] = this->Matrix[2][0] = this->Matrix[1][1] = this->Matrix[2][1] = 1;
		}
		if (temp == "yz")
		{

			this->Matrix[0][0] = this->Matrix[1][0] = this->Matrix[0][3] = this->Matrix[1][3] = 1;
		}
		if (temp == "Yz")
		{
			this->Matrix[0][1] = this->Matrix[1][1] = this->Matrix[0][2] = this->Matrix[1][2] = 1;
		}
		if (temp == "YZ")
		{
			this->Matrix[2][1] = this->Matrix[3][1] = this->Matrix[2][2] = this->Matrix[3][2] = 1;
		}
		if (temp == "yZ")
		{
			this->Matrix[2][0] = this->Matrix[2][3] = this->Matrix[3][0] = this->Matrix[3][3] = 1;
		}

	}
	if (temp.length() == 1)
	{
		if (temp == "x")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[i][0] = this->Matrix[i][1] = 1;
		}
		if (temp == "y")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[i][0] = this->Matrix[i][3] = 1;
		}
		if (temp == "z")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[0][i] = this->Matrix[1][i] = 1;
		}
		if (temp == "t")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[0][i] = this->Matrix[3][i] = 1;
		}
		if (temp == "X")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[i][2] = this->Matrix[i][3] = 1;
		}
		if (temp == "Y")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[i][1] = this->Matrix[i][2] = 1;
		}
		if (temp == "Z")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[2][i] = this->Matrix[3][i] = 1;
		}
		if (temp == "T")
		{
			for (int i = 0; i < 4; i++)
				this->Matrix[1][i] = this->Matrix[2][i] = 1;
		}
	}
}
void Kar::GetMatrix(int matrix[4][4])
{
	// Duyệt qua các phẩn tử của bảng Kar
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			// Gán giá trị tham số matrix = Matrix của class
			matrix[i][j] = this->Matrix[i][j];
}
