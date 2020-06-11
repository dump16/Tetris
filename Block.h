/*	��������Ҫ����	���÷��顢�Է���Ĳ������ж�������	*/

#pragma once
class Unit
{
public:
	int state;
	int color;
};

class Block {
private:
	int dynamic_type;			//	��̬��������
	int dynamic_shape[4][4];	//	��״
	int dynamic_color;			//	��ɫ

	int view_type;				//	Ԥ����������
	int view_shape[4][4];		//	��״
	int view_color;				//	��ɫ

	int row;					//	������������
	int column;					//	������

	Unit map[26][10];			//	��Ϸ�ص�ͼ
								/*	�ո�	0
									�䶨	1
									Ԥ��	2	*/
	int width;
	int height;
	int view_width;
	int view_height;
public:
	Block(int w1=0,int h1=0,int w2=0,int h2=0);
	void SetShape();
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