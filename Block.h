class Block{ 
	public:
		int shape;	//��״ 
		int color;	//��ɫ 
		int speed;	//�ٶ� 
		char locate[10][10];	//λ�� 
		int score;	//�÷� 
		
	public:
		void Creat();	//����
		void Random();	//������� 
		void Down();	//�����ٶ��Զ����� 
		bool IsAgain();	//�߽��ж����غ��ж� 
		void Move();	//�ƶ� 
		void Rotate();	//��ת
		void Accelerate();	//�����ƶ� 
		bool Judge();	//�����ж� 
		void Eliminate();	//����
		void Add();	//���� 
		bool CheckWin//ʤ���ж� 
		
};
