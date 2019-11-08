#include"Matrix.h"
//HAM NHAP MA TRAN
//INPUT: Nhập kích thước n của ma trận, sau đó nhập lần lượt các giá trị của ma trận vào
void Input(double a[][MAX], int& m, int &n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

//HAM XUAT MA TRAN
//Output: Xuất ra lần lượt các giá trị a[i][j]
void Output(double a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		cout << "\n";
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
	}
}

//HAM TIM DINH THUC MA TRAN
//INPUT:Ma trận đã có sẵn dữ liệu bên trong
//OUTPUT: Trả về giá trị định thức của ma trận(biến det)
double determinant(double matrix[][MAX], int n) {
	double det = 0;//bien luu gia tri dinh thuc
	double submatrix[MAX][MAX];
	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));//neu ma tran bac 2, ta dung cong thuc tinh nhanh tim hang
	else {//nếu là ma trận không phải bậc 2, ta dùng công thức tìm định thức theo dòng
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));//đây là công thức tìm định thức theo dong
		}
	}
	return det;
}

//HAM TIM MA TRAN NGHICH DAO
//INPUT:Ma trận đã có sẵn dữ liệu bên trong(ma tran a)
//OUTPUT: Ma trận nghịch đảo của ma trận được nhập vào(ma tran b)
void inverse(double a[][MAX], int n, double b[][MAX])
{
	int i, j, k;
	double temp;
	for (i = 0; i < n; i++) // Tạo ra b là ma trận đơn vị đó
		for (j = 0; j < n; j++)
			if (i == j) b[i][j] = 1; else b[i][j] = 0;
	for (i = 0; i < n; i++) // Xử lý từ hàng đầu đến hàng cuối
	{
		if (a[i][i] == 0) // Nếu gặp phần tử trên đường chéo chính bằng 0 thì đổi hàng
		{
			k = i + 1;
			while (k < n && a[k][i] == 0) k++;//tìm dòng có chưa phần tử khác 0 cùng cột
			// Hoán vị dòng đang xét với dòng vừa tìm được của cả 2 ma trận a,b
			for (j = 0; j < n; j++) 
			{
				temp = a[i][j];
				a[i][j] = a[k][j];
				a[k][j] = temp;
				temp = b[i][j];
				b[i][j] = b[k][j];
				b[k][j] = temp;
			}
		}

		temp = a[i][i];//biến temp bây giờ sẽ lưu các giá trị trên đường chéo chính
		for (j = i; j < n; j++) a[i][j] /= temp;//ta chia các phần tử của tam giác trên cho temp
		for (j = 0; j < n; j++) b[i][j] /= temp;//chia mọi phần tử trên hàng đó của ma trận b cho temp

		for (j = i + 1; j < n; j++)
		{
			temp = -a[j][i];//bien trung gian luu cac gia tri cua a[j][i]
			for (k = i; k < n; k++) a[j][k] += temp * a[i][k];
			for (k = 0; k < n; k++) b[j][k] += temp * b[i][k];
		}
	}// Kết thúc quá trình Gauss

	// Bắt đầu quá trình Jordan:
	for (i = n - 1; i > 0; i--) //ta xet tu duoi len
		for (j = i - 1; j >= 0; j--)
		{
			temp = -a[j][i];
			for (k = n - 1; k >= i; k--)  a[j][k] += temp * a[i][k];
			for (k = 0; k < n; k++) b[j][k] += temp * b[i][k];
		}
}


//HAM TINH TICH 2 MA TRAN
//INPUT: 2 ma tran a, b. Với m:so dong cua a, n:so cot cua a va cung la so dong cua b, p:so cot cua b
//OUTPUT:trả về ma trận c là  tích của 2 ma tran a, b. Có số dòng là m và số cột là p
void Tich(double a[][MAX], double b[][MAX], double c[][MAX], int m, int n, int p)
{
	for (int i = 0; i < m; i++)//m la so dòng ma tran a
		for (int k = 0; k < p; k++) {// p la so cot ma tran b
			c[i][k] = 0;
			for (int j = 0; j < n; j++)//n là số cột ma trận a, cũng chính là số dòng của b
				c[i][k] = c[i][k] + a[i][j] * b[j][k];//ap dụng công thức tìm tích 2 ma trận
		}
}


//HAM TINH HANG MA TRAN
//INPUT:ma trận a
//OUTPUT: hạng của ma trận a
int Rank(double a[][MAX], int soHang, int soCot) {
	//Dua ma tran ve ma tran tam giac tren
	for (int i = 0; i < soHang - 1; i++) {
		for (int j = i; j < soCot; j++) {
			if (a[i][j] == 0)//neu phan tu dang xet a[i][j] bang =0
				for (int k = i + 1; k < soHang; k++)//xet cac phan tu tiep theo tren cot do de tim phan tu khac 0
					if (a[k][j] != 0) {//neu tìm được phần tử khác 0 trên cột đó
						//hoan vi dong co chua phan khac 0 vua tim duoc voi dong dang xet ban dau(daong chua a[i][j]):
						for (int u = 0; u < soCot; u++) {
							double t = a[i][u];
							a[i][u] = a[k][u];
							a[k][u] = t;
						}
						break;
					}
			if (a[i][j] != 0)//neu phan tu dang xet a[i][j] khac 0
			{
				for (int k = i + 1; k < soHang; k++) {
					double tl = (double)a[k][j] / a[i][j];//bien tl luu các giá trị trên cùng cột với phần tử đang xét chia cho phần tử đó
					for (int u = 0; u < soCot; u++) {
						a[k][u] -= a[i][u] * tl;//các phần tử trên dòng k bằng chính nó trừ cho các phần tử trên dòng đang xét nhân cho biến tl
					}
				}
				break;
			}
		}
	}
	//Tim hang (dem hang chua phan tu != 0 co chi so lon nhat, chi so do chinh la hang cua ma tran
	int r = 0;
	for (int i = soHang - 1; i >= 0; i--) {//đếm từ cuối ma trận ngược trở lên
		for (int j = 0; j < soCot; j++)
			if (abs(a[i][j]) != 0) {// neu xuat hien phan tu khac 0
				r = i + 1;//ta lưu vị trí hàng của giá trị khác 0 lại
				break;
			}
		if (r > 0) break;
	}
	return r;
}

//HAM GIAI HPT TUYEN TINH
//Input: ma trận a chứa hệ số của từng biến(bên vế trái của hệ), ma trận b chứa kết quả từng phương trình(bên phía phải của hệ)
//Output:trả về vô nghiệm hoặc vô số nghiệm hoặc ma trận q chứa bộ giá trị nghiệm duy nhất của hệ
void Solve(double a[][MAX], double b[][MAX], int m, int n)
{
	double c[MAX][MAX], d[MAX][MAX], e[MAX][MAX], f[MAX][MAX], q[MAX][MAX];

	//ta ghép ma trận a,b vào ma trận c:
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = a[i][j];
	for (int i = 0; i < m; i++)
		c[i][n] = b[i][0];

	//tìm hạng của ma trận a và c. Đồng thời biến đổi c về dạng ma trận bậc thang
	int t = Rank(a, m, n);
	int s = Rank(c, m, n + 1);

	//xuất ma trận c sau khi dã đưa về dạng ma trận bậc thang:
	cout << "\nHe phuong trinh sau khi da dua ve dang bac thang: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			if (j != n - 1)  cout << c[i][j] << "\t";
			else cout << c[i][j] << "\t|\t" << c[i][j + 1];
		}
		cout << endl;
	}

	//so sánh hạng a,c đẻ rút ra kết luận về nghiệm:
	if (s > t) cout << "He phuong trinh vo nghiem";//nếu hạng c>a:vo nghiem
	else if (t = s && t < n) cout << "He phuong trinh co vo so nghiem";//nếu hạng c=a nhưng nhỏ hơn số cột ma trận a: vo so ng
	else if (s = t = n)//nếu hạng a=c=n thì phương trình có 1 bộ nghiệm duy nhất
	{
		for (int i = 0; i < s; i++) {//ta tách ma trận c thành 2 ma trận d,e
			e[i][0] = c[i][s];
			for (int j = 0; j < s; j++)
				d[i][j] = c[i][j];
		}
		cout << "He phuong trinh co bo nghiem duy nhat la:";
		inverse(d, s, f);//tìm ma trận hoán vị của d chính là f
		Tich(f, e, q, s, s, 1);// khi đó nghiệm của hệ chính là bằng ma trận f nhân e
		for (int i = 0; i < s; i++)//xuat nghiem
			cout <<"\nX"<<i+1<<" =  "<< q[i][0]<<"\t";
	}
}