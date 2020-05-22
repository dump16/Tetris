#pragma once

class Block {
private:
	int type;			//	��ǰ��������
	int shape[4][4];		//	��״
	int color;			//	��ɫ
	int column;
	int row;
	
public:
	void SetShape();				//	������״
	void NewBlock();				//	�����·���
	void DrawBlock();				//	���Ʒ���
	void FixBlock();				//	��������
	void Drop();					//	�Զ����� 
	void Move();					//	�ƶ� 
	void Rotate();					//	��ת
	void Sink();					//	ֱ���³�
	bool IsAgain();					//	��ײ���
	bool Judge();					//	�����ж� 
	void Eliminate();				//	����
	void Add();						//	���� 
	bool IsGameOver();				//	ʤ���ж� 

};