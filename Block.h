/*	��������Ҫ����	���á��������ж������Ʒ���	*/

#pragma once

class Unit {
public:
	int state;		//	״̬
					/*	�ո�	0
						�䶨	1
						Ԥ��	2	*/
	int color;		//	��ɫ
};

class Block {
private:
	int view_type;				//	Ԥ����������
	int view_shape[4][4];		//	��״
	int view_color;				//	��ɫ
	int view_x;					//	������
	int view_y;					//	������

	int dynamic_type;			//	��̬��������
	int dynamic_shape[4][4];	//	��״
	int dynamic_color;			//	��ɫ
	int row;					//	������������
	int column;					//	������

	Unit map[26][10];			//	��Ϸ�ص�ͼ
	int map_x;					//	������
	int map_y;					//	������

public:
	Block() {}
	Block(int x1, int y1, int x2, int y2);
	void InitMap();				//	��ʼ����ͼ
	void SetViewBlock();		//	����Ԥ������
	void NewBlock();			//	����
	void DrawBlock();			//	����
	void ClearBlock();			//	����
	int	FixBlock();				//	�̶�
	void Refresh();				//	����

	void MoveDown();			//	����
	void MoveLeft();			//	����
	void MoveRight();			//	����
	void Rotate();				//	��ת
	void Sink();				//	����
	void DeleteLine(int r);		//	����
	void AddLine();				//	���� 

	bool IsBottom();			//	���׼��
	bool IsAgain();				//	��ײ���
	bool IsFullLine(int r);		//	�������
	bool IsGameOver();			//	������� 

};