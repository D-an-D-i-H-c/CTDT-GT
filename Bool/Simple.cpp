#include "Simple.h"

Simple::Simple()
{
}
Simple::Simple(Kar kar)
{
	this->kar = kar; // Gán kar ( tham số ) vào biến của class
	this->kar.GetMatrix(this->Matrix); // Truyền số liệu cho Matrix
}
Simple::~Simple()
{
}
void Simple::AddCellforGroups(vector <vector <Point>> &groupcells, int i, int j)
{
	// Với groupcellscell ta lưu các tế bào tồn tại trong _Kar
	vector <Point> groupcell; // ta dùng vector để lưu các tọa độ điểm chứa tế bào
	Point temp;
	int around[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; // 1 điểm có (x+around[k][0] , y+around[k][1]) là các điểm xung quanh điểm (x,y)
	temp.x = i; // Nếu i,j là điểm = 1 , ta lưu vào groupcell
	temp.y = j;
	int KTTimthay = 0; // 1 biến để kiểm tra xem có tìm thấy tế bào nào không
	groupcell.push_back(temp);
	// Tìm kiếm các tế bào
	for (int k = 0; k < 4; k++)
	{
		// Tìm kiếm tế bào có 2 ô 
		if (Matrix[(i + around[k][0] + 4) % 4][(j + around[k][1] + 4) % 4] == 1)// Ta xét các trường hợp có thể xảy ra xung quanh ô i ,j
		{
			// Nếu điểm xung quanh i,j == 1 , thì gán vào groupcell
			temp.x = (i + around[k][0] + 4) % 4;
			temp.y = (j + around[k][1] + 4) % 4;
			groupcell.push_back(temp);
			// Khi tìm thấy ta tìm tiếp trường hợp i ,j có 4 ô
			// Kiểm tra đường thẳng
			if (Matrix[(i + 2 * around[k][0] + 4) % 4][(j + 2*around[k][1] + 4) % 4] == 1 &&
				Matrix[(i + 3 * around[k][0] + 4) % 4][(j + 3*around[k][1] + 4) % 4] == 1)
			{
				// Nếu các điểm thuộc đường thẳng xung quanh điểm i,j == 1 , thì gán vào groupcell
				temp.x = (i + 2 * around[k][0] + 4); temp.y = (j + 2 * around[k][1] + 4);
				groupcell.push_back(temp);
				temp.x = (i + 3 * around[k][0] + 4); temp.y = (j + 3 * around[k][1] + 4);
				groupcell.push_back(temp);
				// Kiểm tra trường hợp có 8 ô , Ta xét 4 ô liền kề với 4 ô đã tìm thấy trước đó
				if (Matrix[(i + 0 * around[k][0] + around[(k + 1) % 4][0] + 4) % 4][(j + 0 * around[k][1] + around[(k + 1) % 4][1] + 4) % 4] == 1 &&
					Matrix[(i + 1 * around[k][0] + around[(k + 1) % 4][0] + 4) % 4][(j + 1 * around[k][1] + around[(k + 1) % 4][1] + 4) % 4] == 1 &&
					Matrix[(i + 2 * around[k][0] + around[(k + 1) % 4][0] + 4) % 4][(j + 2 * around[k][1] + around[(k + 1) % 4][1] + 4) % 4] == 1 &&
					Matrix[(i + 3 * around[k][0] + around[(k + 1) % 4][0] + 4) % 4][(j + 3 * around[k][1] + around[(k + 1) % 4][1] + 4) % 4] == 1)
				{
					// Nếu đường thẳng xung quanh đường thẳng ( thuộc i,j ) đều == 1 , thì ta gán vào groupcell
					temp.x = (i + 0 * around[k][0] + around[(k + 1) % 4][0] + 4) % 4; temp.y = (j + 0 * around[k][1] + around[(k + 1) % 4][1] + 4) % 4;
					groupcell.push_back(temp);
					temp.x = (i + 1 * around[k][0] + around[(k + 1) % 4][0] + 4) % 4; temp.y = (j + 1 * around[k][1] + around[(k + 1) % 4][1] + 4) % 4;
					groupcell.push_back(temp);
					temp.x = (i + 2 * around[k][0] + around[(k + 1) % 4][0] + 4) % 4; temp.y = (j + 2 * around[k][1] + around[(k + 1) % 4][1] + 4) % 4;
					groupcell.push_back(temp);
					temp.x = (i + 3 * around[k][0] + around[(k + 1) % 4][0] + 4) % 4; temp.y = (j + 3 * around[k][1] + around[(k + 1) % 4][1] + 4) % 4;
					groupcell.push_back(temp);
				}
				groupcells.push_back(groupcell);
				KTTimthay = 1;
				groupcell.clear();
				break;
			}
			// Ta xét trường hợp tế bào hình vuông , ta xét 2 ô xung quanh 2 ô đã tìm thấy
			if (Matrix[(i + 0 * around[k][0] + around[(k + 1) % 4][0] + 4) % 4][(j + 0 * around[k][1] + around[(k + 1) % 4][1] + 4) % 4] == 1 &&
				Matrix[(i + 1 * around[k][0] + around[(k + 1) % 4][0] + 4) % 4][(j + 1 * around[k][1] + around[(k + 1) % 4][1] + 4) % 4] == 1)
			{
			// Với 2 điểm đã tìm thấy , nếu 2 điểm kề nhau xung quanh 2 điểm đã tìm thấy đều == 1 thì ta gán vào groupcell
				temp.x = (i + 0 * around[k][0] + around[(k + 1) % 4][0] + 4) % 4; temp.y = (j + 0 * around[k][1] + around[(k + 1) % 4][1] + 4) % 4;
				groupcell.push_back(temp);
				temp.x = (i + 1 * around[k][0] + around[(k + 1) % 4][0] + 4) % 4; temp.y = (j + 1 * around[k][1] + around[(k + 1) % 4][1] + 4) % 4;
				groupcell.push_back(temp);
			}
			// Sau khi đã tìm xong 1 tế bào ( groupcell ) thì ta gán groupcell vào groupcells
			groupcells.push_back(groupcell);
			groupcell.clear();
			// Sau khi tìm xong 1 tế bào , ta đặt lại temp để tìm các tế bào khác
			temp.x = i;
			temp.y = j;
			groupcell.push_back(temp);
			KTTimthay = 1;
		}
	}
	// Nếu không tìm thấy điểm nào khác , đẩy 1 điểm này vào groupcell
	if (KTTimthay == 0)
	{
		groupcells.push_back(groupcell);
	}
}
void HoanVi(Point &a,Point &b) // Hàm hoán vị 2 điểm
{
	Point temp = a;
	a = b;
	b = temp;
}
void Simple::SortGroups(vector <Point> &groupcell)
{
	// Ta duyệt qua các tế bào , ta so sánh giữa các điểm bằng số của nó trên ma trận ( 4*x + y , từ 0-15 )
	for (int i = 0; i < groupcell.size(); i++)
	{
		for (int j = i+1; j < groupcell.size(); j++)
		{
			if (groupcell[i].x * 4 + groupcell[i].y > groupcell[j].x * 4 + groupcell[j].y)
			{
				// Nếu điểm tại i < j thì hoán vị lại
				HoanVi(groupcell[i], groupcell[j]);
			}
		}
	}
}

void Simple::Delete(vector <vector <Point>> &groupcells)
{
	// Xóa phần tử trùng
	// Xóa các phần tử con 
	for (int i = 0; i < groupcells.size(); i++)
	{
		// Ta duyệt qua các phần tử của groupcells

		// Tạo vector lưu giá trị
		vector <Point> groupcell = groupcells[i];
		for (int j = 0; j < groupcells.size(); j++)
		{
			// Ta không so sánh những phần tử trùng nên dùng continue để bỏ qua
			if (i == j) continue;
			if (KTCon(groupcells[j], groupcell))
			{
				// Nếu tế bào tại j là con của tế bào tại i thì ta xóa tế bào j
				groupcells.erase(groupcells.begin() + j);
				// Giảm j để đảm bảo không chạy thiếu trường hợp khi xóa
				j--;
			}
		}
	}
	
	// Xóa các phần tử thừa
	for (int i = 0; i < groupcells.size(); i++)
	{
		// Duyệt qua các phần tử của groupcells
		vector <Point> groupcell = groupcells[i];
		if (KTDiemChung(groupcell, i, groupcells))
		{
			// Nếu tại vị trí i , tế bào i có điểm thuộc tế bào khác của groupcells thì ta xóa tế bào tại i
			groupcells.erase(groupcells.begin() + i);
			// Giảm i để đảm bảo không chạy thiếu trường hợp khi xóa
			i--;
		}
	}
}
int Simple::KTCon(vector <Point> &temp1, vector <Point> &temp2)
{
	int KT; // KT để đánh dấu xem có sự xuất hiện của temp1 trong temp2 hay không
	for (int i = 0; i < temp1.size(); i++)
	{
		KT = 0;
		// Ta duyệt qua các phần tử của temp1
		for(int j=0;j<temp2.size();j++)
			// Duyệt tiếp các phần tử của temp2
			if (temp1[i].x * 4 + temp1[i].y == temp2[j].x * 4 + temp2[j].y)
			{
				// Nếu có điểm trùng thì ta đánh dấu bằng KT = 1
				KT = 1;
				break;
			}
		// Sau khi duyệt 1 phần tử của temp1 mà đều không giống phần tử nào của temp2 thì ta return 0
		if (KT == 0) return 0;
	}
	// Nếu sau khi chạy hết mà KT = 1 thì temp2 chứa toàn bộ temp1 thì return 1
	if (KT == 1) return 1;
	else return 0;
}
int Simple::KTDiemChung(vector <Point> &groupcell, int position, vector <vector <Point>> &groupcells)
{
	// Duyệt qua các phần tử của groupcells
	for (int k = 0; k < groupcell.size(); k++)
	{
		for (int i = 0; i < groupcells.size(); i++)
		{
			// Ta dùng biến position để thể hiện vị trí của groupcell trong groupcells , để ta không so sánh cùng 1 tế bào
			if (i == position) continue;
			vector <Point> temp = groupcells[i];
			for (int j = 0; j < temp.size(); j++)
			{
				// Nếu có phần tử nào trong groupcell giống với 1 phần tử trong groupcell còn lại thì return 1
				if (groupcell[k].x * 4 + groupcell[k].y == temp[j].x * 4 + temp[j].y)
					return 1;
			}
		}
	}
	// Nếu không có phần tử nào trong groupcell trùng thì return 0
	return 0;
}
string Simple::ChangeString(vector <Point> &groupcell)
{
	string cot[4] = { "xy","xY","XY","Xy" }; // 2 String để chuyển Point -> String bằng cách đặt x,y vào
	string dong[4] = { "zt","zT","ZT","Zt" };
	string KQ = cot[groupcell[0].y] + dong[groupcell[0].x];
	// Với x,y là số cột và dòng , ta có thể dễ dàng chuyển thành dạng string mà không if else
	if (groupcell.size() == 1) // Nếu chỉ có 1 điểm , kết quả string là KQ
	{
		return KQ;
	}
	else // Các tế bào luôn có kí tự chung , ABcd + ABCd -> ABd
	{
		for (int i = 1; i < groupcell.size(); i++)
		{
			string buffer = ""; // Dùng để lưu tạm các kí tự chung trong 1 nhóm
			string factor = cot[groupcell[i].y] + dong[groupcell[i].x];// String để so sánh
			for (int j = 0; j < KQ.size(); j++)
				if (factor.find(KQ[j]) != -1) // Tìm kiếm sự xuất hiện của temp[j] trong factor
				{
					// Nếu có xuất hiện thì thêm vào buffer
					buffer += KQ[j];
				}
			KQ = buffer;
		}
		return KQ;
	}
}
void Simple::Process_Kar()
{
	string result = "";
	vector <vector <Point>> groupcells;

	// Thêm tế bào vào groupcells
	for(int i=0;i<4;i++)
		for (int j = 0; j < 4; j++)
		{
			// Duyệt qua các phần tử của groupcells
			// Nếu có điểm == 1 thì ta thêm vào groupcells
			if(Matrix[i][j]==1)
			this->AddCellforGroups(groupcells, i, j);
		}
	// Duyệt qua các phần tử của groupcells
	for (int i = 0; i < groupcells.size(); i++)
	{
		// Sort các phẩn tử trong groupcells[i]
		this->SortGroups(groupcells[i]);
	}

	// Sắp xếp các group trong groupcells theo kích cỡ giảm dần
	for (int i = 0; i < groupcells.size()-1; i++)
	{
		// Duyệt qua các phần tử của groupcells
		for (int j = i + 1; j < groupcells.size(); j++)
		{
			// Nếu kích cỡ i < j thì hoán vị , 
			if (groupcells[i].size() < groupcells[j].size())
			{
				vector <Point> temp = groupcells[i];
				groupcells[i] = groupcells[j];
				groupcells[j] = temp;
			}
		}
	}
	this->Delete(groupcells);
	// Xử lí phủ tế bào còn thiếu
	for (int i = 0; i < groupcells.size(); i++)
	{
		// Duyệt qua các phần tử của groupcells
		// Chuyển các phần tử thành string và xuất ra kết quả
		string temp = ChangeString(groupcells[i]);
		result += temp;
		if (i != groupcells.size() - 1)
			result += " + ";
	}
	cout << "Da thuc toi tieu : " << result;
}
