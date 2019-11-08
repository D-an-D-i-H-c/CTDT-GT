

#include "Bool.h"

struct Point
{
	int x, y;
};

class Simple
{
private:
	int Matrix[4][4];
	Kar kar;
	
	void AddCellforGroups(vector <vector <Point>> &groupcells, int i, int j); // Hàm tìm và thêm tế bào vào groupcells
	void SortGroups(vector <Point> &groupcell); // Hàm sắp xếp chuỗi các tế bào
	string ChangeString(vector <Point> &groupcell); // Hàm chuyển các tế bào thành chuỗi
	void Delete(vector <vector <Point>> &groupcells); // Hàm xóa các tế bào trùng , các tế bào con 
	int KTCon(vector <Point> &temp1,vector <Point> &temp2); // Hàm kiểm tra tế bào temp1 có phải là con của tế bào temp2
	int KTDiemChung(vector <Point> &groupcell, int position, vector <vector <Point>> &groupcells); // Hàm kiểm tra điểm p có thuộc vào các groupcell khác trong groupcells
public:
	Simple();
	void Process_Kar();
	Simple(Kar kar); // Hàm tạo có đối số , truyền vào Kar 
	~Simple();

};